#include "Block_L_Reverse.h"

#include "BlockColor.h"


Block_L_Reverse::Block_L_Reverse() : Block(L_REVERSE_COLOR)
{
	setBlock();
}


Block_L_Reverse::~Block_L_Reverse()
{
}

void Block_L_Reverse::setBlock() {
	block[0][1] = true;
	block[1][1] = true;
	block[2][0] = true;
	block[2][1] = true;
}

void Block_L_Reverse::rotateBlock() {
	blockInit();
	switch (rotateType)
	{
	case 0 : 
		block[0][1] = true;
		block[1][1] = true;
		block[2][0] = true;
		block[2][1] = true;
		break;
	case 1 : 
		block[0][0] = true;
		block[1][0] = true;
		block[1][1] = true;
		block[1][2] = true;
		break;
	case 2 : 
		block[0][0] = true;
		block[0][1] = true;
		block[1][0] = true;
		block[2][0] = true;
		break;
	case 3 : 
		block[0][0] = true;
		block[0][1] = true;
		block[0][2] = true;
		block[1][2] = true;
		break;
	default:
		break;
	}
}

void Block_L_Reverse::rotateRight() {
	rotateType++;
	if (rotateType == 4) {
		rotateType = 0;
	}
	rotateBlock();
}

void Block_L_Reverse::rotateLeft() {
	rotateType--;
	if (rotateType == -1) {
		rotateType = 3;
	}
	rotateBlock();
}