#pragma once
#ifndef INCLUDED_TETRIS_INFO_H_
#define INCLUDED_TETRIS_INFO_H_

#include "WindowInfo.h"

//テトリミノの情報
const int TETRIMINO_CELL_SIZE = 30;		//テトリミノのマス一辺のピクセル数

//テトリミノを保持するための配列サイズ
const int TETRIMINO_WIDTH = 4;
const int TETRIMINO_HEIGHT = 4;

const int TETRIMINO_CELL_NUM = 4;	//テトリミノのマス数


////////////////フィールド情報/////////////////////
//壁1マスを含めた箱の横・縦マス数
const int FIELD_WIDTH_CELL = 12;
const int FIELD_HEIGHT_CELL = 21;

//テトリミノが落ちる箱の情報
const int FIELD_POS_X = WND_WIDTH / 4;
const int FIELD_POS_Y = WND_HEIGHT / 5;

const int FIELD_WIDTH = TETRIMINO_CELL_SIZE * FIELD_WIDTH_CELL;
const int FIELD_HEIGHT = TETRIMINO_CELL_SIZE * FIELD_HEIGHT_CELL;

#endif // !INCLUDED_TETRIS_INFO_H_
