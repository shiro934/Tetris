#include "Tetrimino.h"

#include "TetrisInfo.h"

#include "DxLib.h"

#define NEXT_TETRIMINO_POS_X	(WND_WIDTH * 4 / 5)
#define NEXT_TETRIMINO_POS_Y	(WND_HEIGHT / 10)

Tetrimino::Tetrimino(const unsigned int x[], const unsigned int y[], const CellType cellType) : myCellType(cellType)
{
	tetriminoInit(x, y);
	blockPos = FIELD_WIDTH_CELL / 2;	//�^�񒆂��痎���n�߂�悤�ɏ�����
	downFinishFlag = false;
}


Tetrimino::~Tetrimino()
{
}

void Tetrimino::tetriminoInit(const unsigned int initX[], const unsigned int initY[]) {
	//�u���b�N�ێ��̈�̏�����
	for (int height = 0; height < TETRIMINO_HEIGHT; height++) {
		for (int width = 0; width < TETRIMINO_WIDTH; width++) {
			tetrimino[height][width] = false;
		}
	}
	for (int i = 0; i < TETRIMINO_CELL_NUM; i++) {
		tetrimino[initY[i]][initX[i]] = true;
	}
}

void Tetrimino::rotateRight() {	//���v���ɉ�]
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

void Tetrimino::rotateLeft() {	//�����v���ɉ�]
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
	//���̃e�g���~�m��`��
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

	/* �{�b�N�X�ł̃u���b�N�̈ʒu��n�� */
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

	int move_quantity_x = 0;	//�ړ���x
	int move_quantity_y = 0;	//�ړ���y
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

	//�ǂɂԂ��邩���`�F�b�N
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
