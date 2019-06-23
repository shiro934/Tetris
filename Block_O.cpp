#include "Block_O.h"

#include "BlockColor.h"


Block_O::Block_O() : Block(O_COLOR)
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

void Block_O::rotateRight() {
	rotateBlock();
}

void Block_O::rotateLeft() {
	rotateBlock();
}