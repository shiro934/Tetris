#include "Block_S_Reverse.h"

#include "BlockColor.h"


Block_S_Reverse::Block_S_Reverse() : Block(S_REVERSE_COLOR)
{
	setBlock();

}


Block_S_Reverse::~Block_S_Reverse()
{
}

void Block_S_Reverse::setBlock() {
	block[0][1] = true;
	block[1][0] = true;
	block[1][1] = true;
	block[2][0] = true;
}

void Block_S_Reverse::rotateBlock() {
	blockInit();
	switch (rotateType) {
	case 0 : 
		block[0][1] = true;
		block[1][0] = true;
		block[1][1] = true;
		block[2][0] = true;
		break;
	case 1 : 
		block[0][0] = true;
		block[0][1] = true;
		block[1][1] = true;
		block[1][2] = true;
		break;
	}
}

void Block_S_Reverse::rotateRight() {
	rotateType++;
	if (rotateType == 2) {
		rotateType = 0;
	}
	rotateBlock();
}

void Block_S_Reverse::rotateLeft() {
	rotateType--;
	if (rotateType == -1) {
		rotateType = 1;
	}
	rotateBlock();
}