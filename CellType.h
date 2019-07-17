#pragma once
#ifndef INCLUDED_CELL_TYPE_H_
#define INCLUDED_CELL_TYPE_H_

#define TETRIMINO_NUM 7

enum CellType {
	CELL_L,
	CELL_L_REVERSE,
	CELL_T,
	CELL_S,
	CELL_S_REVERSE,
	CELL_O,
	CELL_I, 
	EMPTY,
	WALL,
	MAX
};

//CellTypeÇ…ëŒâûÇµÇΩêFÇÃîzóÒ
static const unsigned int CELL_COLOR[CellType::MAX] = {
	0x00ff00, 
	0xffff00, 
	0xff8800, 
	0xff0000, 
	0x0000ff, 
	0xff00ff, 
	0x00ffff, 
	0x000000,
	0xffffff,
};

#endif // !INCLUDED_CELL_TYPE_H_
