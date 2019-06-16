#pragma once
#ifndef INCLUDED_BLOCK_H_
#define INCLUDED_BLOCK_H_

#include "BlockCategory.h"

//�u���b�N�p�^�[����ێ����邽�߂̔z��T�C�Y
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
