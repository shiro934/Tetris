#pragma once
#ifndef INCLUDED_BLOCK_T_H_
#define INCLUDED_BLOCK_T_H_


#include "Block.h"
class Block_T :
	public Block
{
public:
	Block_T();
	~Block_T();

private : 
	void setBlock();
};

#endif // !INCLUDED_BLOCK_T_H_
