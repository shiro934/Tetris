#include "Block_O.h"



Block_O::Block_O()
{
	setBlock();

}


Block_O::~Block_O()
{
}

void Block_O::setBlock() {
	block[0][0] = true;
	block[0][1] = true;
	block[1][0] = true;
	block[1][1] = true;
}

void Block_O::rotateBlock() {

}