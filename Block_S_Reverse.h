#pragma once
#ifndef INCLUDED_BLOCK_S_REVERSE_H_
#define INCLUDED_BLOCK_S_REVERSE_H_

#include "Block.h"
class Block_S_Reverse :
	public Block
{
public:
	Block_S_Reverse();
	~Block_S_Reverse();

	void rotateBlock();
	void rotateRight();
	void rotateLeft();

private : 
	void setBlock();
};

#endif // !INCLUDED_BLOCK_S_REVERSE_H_
