#pragma once
#ifndef INCLUDED_BLOCK_H_
#define INCLUDED_BLOCK_H_

#include "BlockCategory.h"

#include "Direction.h"
#include "TetrisInfo.h"
#include "CellType.h"

class Block
{
public:
	Block(const unsigned int color);
	~Block();

	virtual void rotateRight() = 0;	//�u���b�N�����v���ɉ�]
	virtual void rotateLeft() = 0;	//�u���b�N�𔽎��v���ɉ�]
	virtual void move(const Direction dire, const CellType box[BOX_HEIGHT_CELL][BOX_WIDTH_CELL]);
	bool isDownFinish() const { return downFinishFlag; }	//��������ȏ㗎���Ȃ��Ȃ�true
	bool canRotate(const CellType box[BOX_HEIGHT_CELL][BOX_WIDTH_CELL]);
	void render();

	void blockCellPos(int rowPos[BLOCK_CELL_NUM], int linePos[BLOCK_CELL_NUM]) const;	//�{�b�N�X�ɑ΂���u���b�N�̈ʒu��Ԃ�
protected : 
	void blockInit();
	virtual void setBlock() = 0;
	virtual void rotateBlock() = 0;
	bool canMove(const Direction dir, const CellType box[BOX_HEIGHT_CELL][BOX_WIDTH_CELL]);

	unsigned int blockPos;		//���݂̃u���b�N�̈ʒu
	unsigned int rotateType;	//�u���b�N�̉�]��

	BlockCategory block_type;
	bool block[BLOCK_HEIGHT][BLOCK_WIDTH];

	const unsigned int BLOCK_COLOR;
	bool downFinishFlag;
};

#endif // !INCLUDED_BLOCK_H_
