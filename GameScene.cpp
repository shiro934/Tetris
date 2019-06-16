#include "GameScene.h"

#include "Block_I.h"

#include "DxLib.h"

GameScene::GameScene()
{
	block = new Block_I();
}


GameScene::~GameScene()
{
	delete block;
}

//ボックスを詰む箱の初期化
void GameScene::boxInit() {
	for (int height = 0; height < BOX_HEIGHT_CELL - 1; height++) {
		for (int width = 0; width < BOX_WIDTH_CELL; width++) {
			if (width == 0 || width == BOX_WIDTH_CELL - 1) {
				box[height][width] = true;
			}
			box[height][width] = false;
		}
	}

	for (int width = 0; width < BOX_WIDTH_CELL; width++) {
		box[BOX_HEIGHT_CELL - 1][width] = true;
	}
}

void GameScene::input() const {

}

void GameScene::update() const {
}

void GameScene::render() const {
	wallRender();
}

void GameScene::wallRender() const {
	for (int i = 0; i < BOX_HEIGHT_CELL; i++) {
		DrawBox(BOX_POS_X, BOX_POS_Y + (BLOCK_SIZE * i)
			, BOX_POS_X + BLOCK_SIZE, BOX_POS_Y + (BLOCK_SIZE * (i + 1)), 
			WALL_COLOR, TRUE);
		DrawBox(BOX_POS_X + (BLOCK_SIZE * (BOX_WIDTH_CELL - 1)), BOX_POS_Y + (BLOCK_SIZE * i)
			, BOX_POS_X + (BLOCK_SIZE * BOX_WIDTH_CELL), BOX_POS_Y + (BLOCK_SIZE * (i + 1)),
			WALL_COLOR, TRUE);
	}

	for (int i = 1; i < BOX_WIDTH_CELL - 1; i++) {
		DrawBox(BOX_POS_X + (BLOCK_SIZE * i), BOX_POS_Y + (BLOCK_SIZE * (BOX_HEIGHT_CELL - 1))
			, BOX_POS_X + (BLOCK_SIZE * (i + 1)), BOX_POS_Y + (BLOCK_SIZE * BOX_HEIGHT_CELL),
			WALL_COLOR, TRUE);
	}
}