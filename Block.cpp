#include "Block.h"



Block::Block()
{
	//ƒuƒƒbƒN•Û—Ìˆæ‚Ì‰Šú‰»
	for (int height = 0; height < BLOCK_HEIGHT; height++) {
		for (int width = 0; width < BLOCK_WIDTH; width++) {
			block[height][width] = false;
		}
	}
}


Block::~Block()
{
}
