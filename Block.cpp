#include "Block.h"

#include "TetrisInfo.h"

#include "DxLib.h"

Block::Block() : BLOCK_COLOR(0x00ffff)
{
	//�u���b�N�ێ��̈�̏�����
	for (int height = 0; height < BLOCK_HEIGHT; height++) {
		for (int width = 0; width < BLOCK_WIDTH; width++) {
			block[height][width] = false;
		}
	}

	blockPos = BOX_WIDTH_CELL / 2;	//�^�񒆂��痎���n�߂�悤�ɏ�����
}


Block::~Block()
{
}

void Block::move(const Direction dir) {
	switch (dir) {
	case LEFT : 
		if (blockPos % BOX_WIDTH_CELL != 1) {
			blockPos--;
		}
		break;
	case RIGHT : 
		if (blockPos % BOX_WIDTH_CELL != (BOX_WIDTH - 2)) {
			blockPos++;
		}
		break;
	case UP : 
		if (blockPos > BOX_WIDTH_CELL) {
			blockPos -= BOX_WIDTH_CELL;
		}
		break;
	case DOWN : 
		if (blockPos < BOX_HEIGHT_CELL * (BOX_WIDTH_CELL - 1)) {
			blockPos += BOX_WIDTH_CELL;
		}
		break;
	}
}

void Block::render() {
	unsigned int cellColor;
	for (int i = 0; i < BOX_HEIGHT_CELL; i++) {
		for (int j = 0; j < BOX_WIDTH_CELL; j++) {
			cellColor = getCellColor(box[i][j]);
			DrawBox(BOX_POS_X + (BLOCK_SIZE * j), BOX_POS_Y + (BLOCK_SIZE * i)
				, BOX_POS_X + (BLOCK_SIZE * (j + 1)), BOX_POS_Y + (BLOCK_SIZE * (i + 1)),
				cellColor, TRUE);
		}
	}
}