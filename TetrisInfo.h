#pragma once
#ifndef INCLUDED_TETRIS_INFO_H_
#define INCLUDED_TETRIS_INFO_H_

#include "WindowInfo.h"

//ブロックの情報
const int BLOCK_SIZE = 30;		//ブロックの一辺のサイズ

//壁1マスを含めた箱の横・縦マス数
const int BOX_WIDTH_CELL = 12;
const int BOX_HEIGHT_CELL = 21;

//ブロックが落ちる箱の情報
const int BOX_POS_X = WND_WIDTH / 3;
const int BOX_POS_Y = WND_HEIGHT / 3;

const int BOX_WIDTH = BLOCK_SIZE * BOX_WIDTH_CELL;
const int BOX_HEIGHT = BLOCK_SIZE * BOX_HEIGHT_CELL;

const unsigned int WALL_COLOR = 0xffffff;


#endif // !INCLUDED_TETRIS_INFO_H_
