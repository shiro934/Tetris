#include "Block_I.h"



Block_I::Block_I()
{
	setBlock();

}


Block_I::~Block_I()
{
}

void Block_I::setBlock() {
	block[0][0] = true;
	block[1][0] = true;
	block[2][0] = true;
	block[3][0] = true;
}

void Block_I::rotateBlock() {

}