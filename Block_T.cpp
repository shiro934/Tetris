#include "Block_T.h"



Block_T::Block_T()
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