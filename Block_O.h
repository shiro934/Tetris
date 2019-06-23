#pragma once
#ifndef INCLUDED_BLOCK_O_H_
#define INCLUDED_BLOCK_O_H_

#include "Block.h"
class Block_O :
	public Block
{
public:
	Block_O();
	~Block_O();

	void rotateRight();
	void rotateLeft();

private : 
	void setBlock();
	void rotateBlock();
};

#endif // !INCLUDED_BLOCK_O_H_
