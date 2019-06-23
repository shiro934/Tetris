#pragma once
#ifndef BLOCK_L_REVERSE_H_
#define BLOCK_L_REVERSE_H_

#include "Block.h"
class Block_L_Reverse :
	public Block
{
public:
	Block_L_Reverse();
	~Block_L_Reverse();

	void rotateRight();
	void rotateLeft();

private : 
	void setBlock();
	void rotateBlock();
};

#endif // !BLOCK_L_REVERSE_H_
