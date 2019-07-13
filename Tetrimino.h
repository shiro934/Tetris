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

	void rotateRight();	//�u���b�N�����v���ɉ�]
	void rotateLeft();	//�u���b�N�𔽎��v���ɉ�]
	void move(const Direction dire, const CellType box[FIELD_HEIGHT_CELL][FIELD_WIDTH_CELL]);
	bool isDownFinish() const { return downFinishFlag; }	//��������ȏ㗎���Ȃ��Ȃ�true
	bool canRotate(const CellType box[FIELD_HEIGHT_CELL][FIELD_WIDTH_CELL]);
	void render();
	void nextRender() const;

	CellType getCellType() const { return myCellType; }
	void blockCellPos(int rowPos[TETRIMINO_CELL_NUM], int linePos[TETRIMINO_CELL_NUM]) const;	//�{�b�N�X�ɑ΂���u���b�N�̈ʒu��Ԃ�
protected : 
	void tetriminoInit(const unsigned int initX[], const unsigned int initY[]);
	bool canMove(const Direction dir, const CellType box[FIELD_HEIGHT_CELL][FIELD_WIDTH_CELL]);

	unsigned int blockPos;		//���݂̃u���b�N�̈ʒu
	unsigned int rotateType;	//�u���b�N�̉�]��

	CellType myCellType;
	bool tetrimino[TETRIMINO_HEIGHT][TETRIMINO_WIDTH];

	bool downFinishFlag;
};

#endif // !INCLUDED_BLOCK_H_
