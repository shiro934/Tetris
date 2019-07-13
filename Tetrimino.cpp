#include "Tetrimino.h"

#include "TetrisInfo.h"

#include "DxLib.h"

#define NEXT_TETRIMINO_POS_X	(WND_WIDTH * 4 / 5)
#define NEXT_TETRIMINO_POS_Y	(WND_HEIGHT / 10)

Tetrimino::Tetrimino(const unsigned int x[], const unsigned int y[], const CellType cellType) : myCellType(cellType)
{
	tetriminoInit(x, y);
	blockPos = FIELD_WIDTH_CELL / 2;	//真ん中から落ち始めるように初期化
	downFinishFlag = false;
}


Tetrimino::~Tetrimino()
{
}

void Tetrimino::tetriminoInit(const unsigned int initX[], const unsigned int initY[]) {
	//ブロック保持領域の初期化
	for (int height = 0; height < TETRIMINO_HEIGHT; height++) {
		for (int width = 0; width < TETRIMINO_WIDTH; width++) {
			tetrimino[height][width] = false;
		}
	}
	for (int i = 0; i < TETRIMINO_CELL_NUM; i++) {
		tetrimino[initY[i]][initX[i]] = true;
	}
}

void Tetrimino::rotateRight() {	//時計回りに回転
	bool rotatedTetrimino[TETRIMINO_HEIGHT][TETRIMINO_WIDTH];

	for (int height = 0; height < TETRIMINO_HEIGHT; height++) {
		for (int width = 0; width < TETRIMINO_WIDTH; width++) {
			rotatedTetrimino[height][width] = tetrimino[TETRIMINO_WIDTH - width - 1][height];
		}
	}
	for (int height = 0; height < TETRIMINO_HEIGHT; height++) {
		for (int width = 0; width < TETRIMINO_WIDTH; width++) {
			tetrimino[height][width] = rotatedTetrimino[height][width];
		}
	}
}

void Tetrimino::rotateLeft() {	//反時計回りに回転
	bool rotatedTetrimino[TETRIMINO_HEIGHT][TETRIMINO_WIDTH];

	for (int height = 0; height < TETRIMINO_HEIGHT; height++) {
		for (int width = 0; width < TETRIMINO_WIDTH; width++) {
			rotatedTetrimino[height][width] = tetrimino[width][TETRIMINO_HEIGHT - height - 1];
		}
	}
	for (int height = 0; height < TETRIMINO_HEIGHT; height++) {
		for (int width = 0; width < TETRIMINO_WIDTH; width++) {
			tetrimino[height][width] = rotatedTetrimino[height][width];
		}
	}
}


void Tetrimino::move(const Direction dir, const CellType field[FIELD_HEIGHT_CELL][FIELD_WIDTH_CELL]) {
	switch (dir) {
	case LEFT : 
		if (canMove(LEFT, field)) {
			blockPos--;
		}
		break;
	case RIGHT : 
		if (canMove(RIGHT, field)) {
			blockPos++;
		}
		break;
	case UP : 
		if (canMove(UP, field)) {
			blockPos -= FIELD_WIDTH_CELL;
		}
		break;
	case DOWN : 
		if (canMove(DOWN, field)) {
			blockPos += FIELD_WIDTH_CELL;
		}
		else {
			downFinishFlag = true;
		}
		break;
	}
}

void Tetrimino::render() {
	unsigned int blockPosX = blockPos % FIELD_WIDTH_CELL;
	unsigned int blockPosY = blockPos / FIELD_WIDTH_CELL;

	for (int i = 0; i < TETRIMINO_HEIGHT; i++) {
		for (int j = 0; j < TETRIMINO_WIDTH; j++) {
			if (tetrimino[i][j]) {
				DrawBox(FIELD_POS_X + (TETRIMINO_CELL_SIZE * (blockPosX + j)), FIELD_POS_Y + (TETRIMINO_CELL_SIZE * (blockPosY + i))
					, FIELD_POS_X + (TETRIMINO_CELL_SIZE * (blockPosX + j + 1)), FIELD_POS_Y + (TETRIMINO_CELL_SIZE * (blockPosY + i + 1)),
					CELL_COLOR[myCellType], TRUE);
			}
		}
	}
}

void Tetrimino::nextRender() const {
	//次のテトリミノを描画
	for (int i = 0; i < TETRIMINO_HEIGHT; i++) {
		for (int j = 0; j < TETRIMINO_WIDTH; j++) {
			if (tetrimino[i][j]) {
				DrawBox(NEXT_TETRIMINO_POS_X + (TETRIMINO_CELL_SIZE * j), NEXT_TETRIMINO_POS_Y + (TETRIMINO_CELL_SIZE * i)
					, NEXT_TETRIMINO_POS_X + (TETRIMINO_CELL_SIZE * (j + 1)), NEXT_TETRIMINO_POS_Y + (TETRIMINO_CELL_SIZE * (i + 1)),
					CELL_COLOR[myCellType], TRUE);
			}
		}
	}

	DrawBox(NEXT_TETRIMINO_POS_X - 20, NEXT_TETRIMINO_POS_Y - 20
		, NEXT_TETRIMINO_POS_X + TETRIMINO_CELL_SIZE * 5, NEXT_TETRIMINO_POS_Y + TETRIMINO_CELL_SIZE * 4, 0xffffff, FALSE);
}

void Tetrimino::blockCellPos(int rowPos[TETRIMINO_CELL_NUM], int linePos[TETRIMINO_CELL_NUM]) const {
	unsigned int blockPosX = blockPos % FIELD_WIDTH_CELL;
	unsigned int blockPosY = blockPos / FIELD_WIDTH_CELL;
	int posCount = 0;

	/* ボックスでのブロックの位置を渡す */
	for (int i = 0; i < TETRIMINO_HEIGHT; i++) {
		for (int j = 0; j < TETRIMINO_WIDTH; j++) {
			if (tetrimino[i][j]) {
				rowPos[posCount] = blockPosX + j;
				linePos[posCount] = blockPosY + i;
				posCount++;
			}
		}
	}
}

bool Tetrimino::canMove(const Direction dir, const CellType box[FIELD_HEIGHT_CELL][FIELD_WIDTH_CELL]) {
	int rowPos[TETRIMINO_CELL_NUM];
	int linePos[TETRIMINO_CELL_NUM];
	blockCellPos(rowPos, linePos);

	int move_quantity_x = 0;	//移動量x
	int move_quantity_y = 0;	//移動量y
	switch (dir) {
	case LEFT : 
		move_quantity_x = -1;
		break;
	case RIGHT : 
		move_quantity_x = 1;
		break;
	case UP  : 
		move_quantity_y = -1;
		break;
	case DOWN : 
		move_quantity_y = 1;
		break;
	}

	for (int i = 0; i < TETRIMINO_CELL_NUM; i++) {
		rowPos[i] += move_quantity_x;
		linePos[i] += move_quantity_y;
	}

	//壁にぶつかるかをチェック
	for (int i = 0; i < TETRIMINO_CELL_NUM; i++) {
		if (box[linePos[i]][rowPos[i]] != EMPTY) {
			return false;
		}
	}
	return true;
}

bool Tetrimino::canRotate(const CellType box[FIELD_HEIGHT_CELL][FIELD_WIDTH_CELL]) {
	int rowPos[TETRIMINO_CELL_NUM];
	int linePos[TETRIMINO_CELL_NUM];
	blockCellPos(rowPos, linePos);

	for (int i = 0; i < TETRIMINO_CELL_NUM; i++) {
		if (box[linePos[i]][rowPos[i]] != EMPTY) {
			return false;
		}
	}
	return true;
}
