#include "Block.h"



Block::Block()
{
	//ブロック保持領域の初期化
	for (int height = 0; height < BLOCK_HEIGHT; height++) {
		for (int width = 0; width < BLOCK_WIDTH; width++) {
			block[height][width] = false;
		}
	}
}


Block::~Block()
{
}
