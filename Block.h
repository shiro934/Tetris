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

	virtual void rotateRight() = 0;	//ブロックを時計回りに回転
	virtual void rotateLeft() = 0;	//ブロックを反時計回りに回転
	virtual void move(const Direction dire, const CellType box[BOX_HEIGHT_CELL][BOX_WIDTH_CELL]);
	bool isDownFinish() const { return downFinishFlag; }	//もうこれ以上落ちないならtrue
	bool canRotate(const CellType box[BOX_HEIGHT_CELL][BOX_WIDTH_CELL]);
	void render();

	void blockCellPos(int rowPos[BLOCK_CELL_NUM], int linePos[BLOCK_CELL_NUM]) const;	//ボックスに対するブロックの位置を返す
protected : 
	void blockInit();
	virtual void setBlock() = 0;
	virtual void rotateBlock() = 0;
	bool canMove(const Direction dir, const CellType box[BOX_HEIGHT_CELL][BOX_WIDTH_CELL]);

	unsigned int blockPos;		//現在のブロックの位置
	unsigned int rotateType;	//ブロックの回転量

	BlockCategory block_type;
	bool block[BLOCK_HEIGHT][BLOCK_WIDTH];

	const unsigned int BLOCK_COLOR;
	bool downFinishFlag;
};

#endif // !INCLUDED_BLOCK_H_
