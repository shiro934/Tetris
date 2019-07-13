#pragma once
#ifndef INCLUDED_BLOCK_H_
#define INCLUDED_BLOCK_H_

#include "BlockCategory.h"

#include "Direction.h"
#include "TetrisInfo.h"
#include "CellType.h"

class Tetrimino
{
public:
	Tetrimino(const unsigned int x[], const unsigned int y[], const CellType cellType);
	~Tetrimino();

	void rotateRight();	//ブロックを時計回りに回転
	void rotateLeft();	//ブロックを反時計回りに回転
	void move(const Direction dire, const CellType box[FIELD_HEIGHT_CELL][FIELD_WIDTH_CELL]);
	bool isDownFinish() const { return downFinishFlag; }	//もうこれ以上落ちないならtrue
	bool canRotate(const CellType box[FIELD_HEIGHT_CELL][FIELD_WIDTH_CELL]);
	void render();
	void nextRender() const;

	CellType getCellType() const { return myCellType; }
	void blockCellPos(int rowPos[TETRIMINO_CELL_NUM], int linePos[TETRIMINO_CELL_NUM]) const;	//ボックスに対するブロックの位置を返す
protected : 
	void tetriminoInit(const unsigned int initX[], const unsigned int initY[]);
	bool canMove(const Direction dir, const CellType box[FIELD_HEIGHT_CELL][FIELD_WIDTH_CELL]);

	unsigned int blockPos;		//現在のブロックの位置
	unsigned int rotateType;	//ブロックの回転量

	CellType myCellType;
	bool tetrimino[TETRIMINO_HEIGHT][TETRIMINO_WIDTH];

	bool downFinishFlag;
};

#endif // !INCLUDED_BLOCK_H_
