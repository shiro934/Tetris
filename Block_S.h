#pragma once
#ifndef INCLUDED_BLOCK_S_H_
#define INCLUDED_BLOCK_S_H_

#include "Block.h"
class Block_S :
	public Block
{
public:
	Block_S();
	~Block_S();

	void rotateRight();
	void rotateLeft();

private : 
	void setBlock();
	void rotateBlock();
};

#endif // !INCLUDED_BLOCK_S_H_
