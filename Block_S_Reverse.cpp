#include "Block_S_Reverse.h"



Block_S_Reverse::Block_S_Reverse()
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