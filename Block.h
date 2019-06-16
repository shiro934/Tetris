#pragma once
#ifndef INCLUDED_BLOCK_H_
#define INCLUDED_BLOCK_H_

#include "BlockCategory.h"

//ブロックパターンを保持するための配列サイズ
#define BLOCK_WIDTH 4
#define BLOCK_HEIGHT 4

class Block
{
public:
	Block();
	~Block();

protected : 
	virtual void setBlock() = 0;

	BlockCategory block_type;
	bool block[BLOCK_HEIGHT][BLOCK_WIDTH];
};

#endif // !INCLUDED_BLOCK_H_
