#include "Block_S.h"

#include "BlockColor.h"


Block_S::Block_S() : Block(S_COLOR)
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

void Block_S::rotateBlock() {
	blockInit();
	switch (rotateType) {
	case 0 : 
		block[0][0] = true;
		block[1][0] = true;
		block[1][1] = true;
		block[2][1] = true;
		break;
	case 1 : 
		block[0][1] = true;
		block[0][2] = true;
		block[1][0] = true;
		block[1][1] = true;
		break;
	}
}

void Block_S::rotateRight() {
	rotateType++;
	if (rotateType == 2) {
		rotateType = 0;
	}
	rotateBlock();
}

void Block_S::rotateLeft() {
	rotateType--;
	if (rotateType == -1) {
		rotateType = 1;
	}
	rotateBlock();
}