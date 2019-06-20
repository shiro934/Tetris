#pragma once
#ifndef INCLUDED_BLOCK_H_
#define INCLUDED_BLOCK_H_

#include "BlockCategory.h"

#include "Direction.h"

//�u���b�N�p�^�[����ێ����邽�߂̔z��T�C�Y
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

	unsigned int blockPos;		//���݂̃u���b�N�̈ʒu
	BlockCategory block_type;
	bool block[BLOCK_HEIGHT][BLOCK_WIDTH];

	const unsigned int BLOCK_COLOR;
};

#endif // !INCLUDED_BLOCK_H_
