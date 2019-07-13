#pragma once
#ifndef INCLUDED_TETRIS_INFO_H_
#define INCLUDED_TETRIS_INFO_H_

#include "WindowInfo.h"

//�e�g���~�m�̏��
const int TETRIMINO_CELL_SIZE = 30;		//�e�g���~�m�̃}�X��ӂ̃s�N�Z����

//�e�g���~�m��ێ����邽�߂̔z��T�C�Y
const int TETRIMINO_WIDTH = 4;
const int TETRIMINO_HEIGHT = 4;

const int TETRIMINO_CELL_NUM = 4;	//�e�g���~�m�̃}�X��


////////////////�t�B�[���h���/////////////////////
//��1�}�X���܂߂����̉��E�c�}�X��
const int FIELD_WIDTH_CELL = 12;
const int FIELD_HEIGHT_CELL = 21;

//�e�g���~�m�������锠�̏��
const int FIELD_POS_X = WND_WIDTH / 4;
const int FIELD_POS_Y = WND_HEIGHT / 5;

const int FIELD_WIDTH = TETRIMINO_CELL_SIZE * FIELD_WIDTH_CELL;
const int FIELD_HEIGHT = TETRIMINO_CELL_SIZE * FIELD_HEIGHT_CELL;

#endif // !INCLUDED_TETRIS_INFO_H_
