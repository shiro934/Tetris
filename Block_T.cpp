#include "Block_T.h"

#include "BlockColor.h"


Block_T::Block_T() : Block(T_COLOR)
{
	setBlock();

}


Block_T::~Block_T()
{
}

void Block_T::setBlock() {
	block[0][0] = true;
	block[0][1] = true;
	block[0][2] = true;
	block[1][1] = true;
}

void Block_T::rotateBlock() {
	blockInit();
	switch (rotateType) {
	case 0:
		block[0][0] = true;
		block[0][1] = true;
		block[0][2] = true;
		block[1][1] = true;
		break;
	case 1 : 
		block[0][1] = true;
		block[1][0] = true;
		block[1][1] = true;
		block[2][1] = true;
		break;
	case 2 : 
		block[0][1] = true;
		block[1][0] = true;
		block[1][1] = true;
		block[1][2] = true;
		break;
	case 3 : 
		block[0][0] = true;
		block[1][0] = true;
		block[1][1] = true;
		block[2][0] = true;
		break;
	}
}

void Block_T::rotateRight() {
	rotateType++;
	if (rotateType == 4) {
		rotateType = 0;
	}
	rotateBlock();
}

void Block_T::rotateLeft() {
	rotateType--;
	if (rotateType == -1) {
		rotateType = 3;
	}
	rotateBlock();
}