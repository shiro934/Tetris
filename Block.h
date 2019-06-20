#pragma once
#ifndef INCLUDED_BLOCK_H_
#define INCLUDED_BLOCK_H_

#include "BlockCategory.h"

#include "Direction.h"

//ブロックパターンを保持するための配列サイズ
#define BLOCK_WIDTH 4
#define BLOCK_HEIGHT 4

class Block
{
public:
	Block();
	~Block();

	virtual void rotateBlock() = 0;
	virtual void move(const Direction dire);

	void render();


protected : 
	virtual void setBlock() = 0;

	unsigned int blockPos;		//現在のブロックの位置
	BlockCategory block_type;
	bool block[BLOCK_HEIGHT][BLOCK_WIDTH];

	const unsigned int BLOCK_COLOR;
};

#endif // !INCLUDED_BLOCK_H_
