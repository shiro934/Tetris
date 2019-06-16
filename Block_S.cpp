#include "Block_S.h"



Block_S::Block_S()
{
	setBlock();

}


Block_S::~Block_S()
{
}

void Block_S::setBlock() {
	block[0][0] = true;
	block[1][0] = true;
	block[1][1] = true;
	block[2][1] = true;
}