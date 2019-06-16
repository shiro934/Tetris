#include "Block_L_Reverse.h"



Block_L_Reverse::Block_L_Reverse()
{
	setBlock();
}


Block_L_Reverse::~Block_L_Reverse()
{
}

void Block_L_Reverse::setBlock() {
	block[0][1] = true;
	block[1][1] = true;
	block[2][1] = true;
	block[3][1] = true;
}