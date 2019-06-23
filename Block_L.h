#pragma once
#ifndef INCLUDED_BLOCK_L_H_
#define INCLUDED_BLOCK_L_H_


#include "Block.h"
class Block_L :
	public Block
{
public:
	Block_L();
	~Block_L();

	void rotateRight();
	void rotateLeft();

private : 
	void setBlock();
	void rotateBlock();
};

#endif // !INCLUDED_BLOCK_L_H_
