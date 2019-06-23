#pragma once
#ifndef INCLUDED_BLOCK_I_H_
#define INCLUDED_BLOCK_I_H_

#include "Block.h"
class Block_I :
	public Block
{
public:
	Block_I();
	~Block_I();

	void rotateRight();
	void rotateLeft();

private : 
	void setBlock();
	void rotateBlock();
};

#endif // !INCLUDED_BLOCK_I_H_
