#include "Tetrimino.h"

#include "TetrisInfo.h"

#include "DxLib.h"

Tetrimino::Tetrimino(const unsigned int x[], const unsigned int y[], const CellType cellType) : myCellType(cellType)
{
	tetriminoInit(x, y);
	downFinishFlag = false;
}


Tetrimino::~Tetrimino()
{
}

//テトリミノの位置を初期化
void Tetrimino::tetriminoPosInit() {
	tetriminoPos = FIELD_WIDTH_CELL / 2;	//真ん中から落ち始めるように初期化
}

//配列にテトリミノをセット
void Tetrimino::tetriminoInit(const unsigned int initX[], const unsigned int initY[]) {
	tetriminoPosInit();

	//テトリミノの保持領域の初期化
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
			tetriminoPos--;
		}
		break;
	case RIGHT : 
		if (canMove(RIGHT, field)) {
			tetriminoPos++;
		}
		break;
	case UP : 
		if (canMove(UP, field)) {
			tetriminoPos -= FIELD_WIDTH_CELL;
		}
		break;
	case DOWN : 
		if (canMove(DOWN, field)) {
			tetriminoPos += FIELD_WIDTH_CELL;
		}
		else {
			downFinishFlag = true;
		}
		break;
	}
}

void Tetrimino::render() {
	unsigned int blockPosX = tetriminoPos % FIELD_WIDTH_CELL;
	unsigned int blockPosY = tetriminoPos / FIELD_WIDTH_CELL;

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
}

void Tetrimino::holdRender() const {
	//次のテトリミノを描画
	for (int i = 0; i < TETRIMINO_HEIGHT; i++) {
		for (int j = 0; j < TETRIMINO_WIDTH; j++) {
			if (tetrimino[i][j]) {
				DrawBox(HOLD_TETRIMINO_POS_X + (TETRIMINO_CELL_SIZE * j), HOLD_TETRIMINO_POS_Y + (TETRIMINO_CELL_SIZE * i)
					, HOLD_TETRIMINO_POS_X + (TETRIMINO_CELL_SIZE * (j + 1)), HOLD_TETRIMINO_POS_Y + (TETRIMINO_CELL_SIZE * (i + 1)),
					CELL_COLOR[myCellType], TRUE);
			}
		}
	}
}

void Tetrimino::tetriminoCellPos(int rowPos[TETRIMINO_CELL_NUM], int linePos[TETRIMINO_CELL_NUM]) const {
	unsigned int blockPosX = tetriminoPos % FIELD_WIDTH_CELL;
	unsigned int blockPosY = tetriminoPos / FIELD_WIDTH_CELL;
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
	tetriminoCellPos(rowPos, linePos);

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
	tetriminoCellPos(rowPos, linePos);

	for (int i = 0; i < TETRIMINO_CELL_NUM; i++) {
		if (box[linePos[i]][rowPos[i]] != EMPTY) {
			return false;
		}
	}
	return true;
}
