#include "Block_I.h"

#include "BlockColor.h"

Block_I::Block_I() : Block(I_COLOR)
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
	blockInit();
	switch (rotateType) {
	case 0 :
		block[0][0] = true;
		block[1][0] = true;
		block[2][0] = true;
		block[3][0] = true;
		break;
	case 1 : 
		block[0][0] = true;
		block[0][1] = true;
		block[0][2] = true;
		block[0][3] = true;
		break;
	}
}

void Block_I::rotateRight() {
	rotateType++;
	if (rotateType == 2) {
		rotateType = 0;
	}
	rotateBlock();
}

void Block_I::rotateLeft() {
	rotateType--;
	if (rotateType == -1) {
		rotateType = 1;
	}
	rotateBlock();
}