#include "Block.h"

#include "TetrisInfo.h"

#include "DxLib.h"

Block::Block(const unsigned int color) : BLOCK_COLOR(color)
{
	blockInit();
	blockPos = BOX_WIDTH_CELL / 2;	//真ん中から落ち始めるように初期化
	rotateType = 0;
	downFinishFlag = false;
}


Block::~Block()
{
}

void Block::blockInit() {
	//ブロック保持領域の初期化
	for (int height = 0; height < BLOCK_HEIGHT; height++) {
		for (int width = 0; width < BLOCK_WIDTH; width++) {
			block[height][width] = false;
		}
	}
}


CellType box[BOX_HEIGHT_CELL][BOX_WIDTH_CELL];	//そのインデックスが示すマスが埋まっていればtrue
void Block::move(const Direction dir, const CellType box[BOX_HEIGHT_CELL][BOX_WIDTH_CELL]) {
	switch (dir) {
	case LEFT : 
		if (canMove(LEFT, box)) {
			blockPos--;
		}
		break;
	case RIGHT : 
		if (canMove(RIGHT, box)) {
			blockPos++;
		}
		break;
	case UP : 
		if (canMove(UP, box)) {
			blockPos -= BOX_WIDTH_CELL;
		}
		break;
	case DOWN : 
		if (canMove(DOWN, box)) {
			blockPos += BOX_WIDTH_CELL;
		}
		else {
			downFinishFlag = true;
		}
		break;
	}
}

void Block::render() {
	unsigned int blockPosX = blockPos % BOX_WIDTH_CELL;
	unsigned int blockPosY = blockPos / BOX_WIDTH_CELL;

	for (int i = 0; i < BLOCK_HEIGHT; i++) {
		for (int j = 0; j < BLOCK_WIDTH; j++) {
			if (block[i][j]) {
				DrawBox(BOX_POS_X + (BLOCK_SIZE * (blockPosX + j)), BOX_POS_Y + (BLOCK_SIZE * (blockPosY + i))
					, BOX_POS_X + (BLOCK_SIZE * (blockPosX + j + 1)), BOX_POS_Y + (BLOCK_SIZE * (blockPosY + i + 1)),
					BLOCK_COLOR, TRUE);
			}
		}
	}
}

void Block::blockCellPos(int rowPos[BLOCK_CELL_NUM], int linePos[BLOCK_CELL_NUM]) const {
	unsigned int blockPosX = blockPos % BOX_WIDTH_CELL;
	unsigned int blockPosY = blockPos / BOX_WIDTH_CELL;
	int posCount = 0;

	/* ボックスでのブロックの位置を渡す */
	for (int i = 0; i < BLOCK_HEIGHT; i++) {
		for (int j = 0; j < BLOCK_WIDTH; j++) {
			if (block[i][j]) {
				rowPos[posCount] = blockPosX + j;
				linePos[posCount] = blockPosY + i;
				posCount++;
			}
		}
	}
}

bool Block::canMove(const Direction dir, const CellType box[BOX_HEIGHT_CELL][BOX_WIDTH_CELL]) {
	int rowPos[BLOCK_CELL_NUM];
	int linePos[BLOCK_CELL_NUM];
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

	for (int i = 0; i < BLOCK_CELL_NUM; i++) {
		rowPos[i] += move_quantity_x;
		linePos[i] += move_quantity_y;
	}

	//壁にぶつかるかをチェック
	for (int i = 0; i < BLOCK_CELL_NUM; i++) {
		if (box[linePos[i]][rowPos[i]] != EMPTY) {
			return false;
		}
	}
	return true;
}

bool Block::canRotate(const CellType box[BOX_HEIGHT_CELL][BOX_WIDTH_CELL]) {
	int rowPos[BLOCK_CELL_NUM];
	int linePos[BLOCK_CELL_NUM];
	blockCellPos(rowPos, linePos);

	for (int i = 0; i < BLOCK_CELL_NUM; i++) {
		if (box[linePos[i]][rowPos[i]] != EMPTY) {
			return false;
		}
	}
	return true;
}
