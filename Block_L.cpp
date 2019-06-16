#include "Block_L.h"



Block_L::Block_L()
{
	setBlock();

}


Block_L::~Block_L()
{
}

void Block_L::setBlock() {
	block[0][0] = true;
	block[1][0] = true;
	block[2][0] = true;
	block[2][1] = true;
}