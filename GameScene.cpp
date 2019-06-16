#include "GameScene.h"

#include "Block_I.h"

#include "DxLib.h"

GameScene::GameScene()
{
	block = new Block_I();

	boxInit();
}


GameScene::~GameScene()
{
	delete block;
}

//ボックスを詰む箱の初期化
void GameScene::boxInit() {
	for (int height = 0; height < BOX_HEIGHT_CELL; height++) {
		for (int width = 0; width < BOX_WIDTH_CELL; width++) {
			if (width == 0 || width == BOX_WIDTH_CELL - 1) {
				box[height][width] = WALL;
			}
			else {
				box[height][width] = EMPTY;
			}
		}
	}

	for (int width = 0; width < BOX_WIDTH_CELL; width++) {
		box[BOX_HEIGHT_CELL - 1][width] = WALL;
	}
}

void GameScene::input() const {

}

void GameScene::update() const {
}

void GameScene::render() const {
	unsigned int cellColor;
	for (int i = 0; i < BOX_HEIGHT_CELL; i++) {
		for (int j = 0; j < BOX_WIDTH_CELL; j++) {
			cellColor = getCellColor(box[i][j]);
			DrawBox(BOX_POS_X + (BLOCK_SIZE * j), BOX_POS_Y + (BLOCK_SIZE * i)
				, BOX_POS_X + (BLOCK_SIZE * (j + 1)), BOX_POS_Y + (BLOCK_SIZE * (i + 1)),
				cellColor, TRUE);
		}
	}
}

bool GameScene::isCellEmpty(const CellType type) const {
	return (type == EMPTY) ? true : false;
}

unsigned int GameScene::getCellColor(const CellType type) const {
	unsigned color;
	switch (type) {
	case WALL : 
		color = 0x00ffffff;
		break;
	case EMPTY : 
		color = 0x00000000;
		break;
	case CELL_L : 
		color = 0x0000ff00;		//緑
		break;
	case CELL_L_REVERSE : 
		color = 0x00ffff00;
		break;
	case CELL_T : 
		color = 0x00ff8800;
		break;
	case CELL_S : 
		color = 0x00ff0000;
		break;
	case CELL_S_REVERSE : 
		color = 0x000000ff;
		break;
	case CELL_O : 
		color = 0x00ff00ff;
		break;
	case CELL_I : 
		color = 0x0000ffff;
		break;
	default : 
		color = 0x0088ff00;
	}
	return color;
}
