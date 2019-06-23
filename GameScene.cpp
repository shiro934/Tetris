#include "GameScene.h"

#include "Block_L.h"
#include "Block_L_Reverse.h"
#include "BLOCK_T.h"
#include "Block_S.h"
#include"Block_S_Reverse.h"
#include "Block_O.h"
#include "Block_I.h"

#include "BlockColor.h"

#include "DxLib.h"

#include <random>

GameScene::GameScene()
{
	createBlock();
	boxInit();
	frameCount = 0;
	downPace = 60;
	gameOverFlag = false;
}


GameScene::~GameScene()
{
	delete block;
}

bool GameScene::isGameOver() {
	for (int i = 0; i < 4; i++) {
		if (box[0][BOX_WIDTH_CELL / 2 + i] != EMPTY) {
			gameOverFlag = true;
			return true;
		}
	}
	return false;
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

void GameScene::input(const InputKey& input) {
	if (gameOverFlag) {
		return;
	}

	if (input.checkKeyState(KEY_INPUT_LEFT) == KEY_DOWN) {
		block->move(LEFT, box);
	}
	if (input.checkKeyState(KEY_INPUT_RIGHT) == KEY_DOWN) {
		block->move(RIGHT, box);
	}
	if (input.checkKeyState(KEY_INPUT_UP) == KEY_DOWN) {
		while (block->isDownFinish() == false) {
			block->move(DOWN, box);
		}
	}
	if (input.checkKeyState(KEY_INPUT_DOWN) == KEY_DOWN) {
		block->move(DOWN, box);
	}
	if (input.checkKeyState(KEY_INPUT_S) == KEY_DOWN) {
		block->rotateRight();
		if (block->canRotate(box) == false) {
			block->rotateLeft();
		}
	}
	if (input.checkKeyState(KEY_INPUT_A) == KEY_DOWN) {
		block->rotateLeft();
		if (block->canRotate(box) == false) {
			block->rotateRight();
		}
	}
}

void GameScene::update() {
	if (gameOverFlag) {
		return;
	}

	if (block->isDownFinish()) {
		if (isGameOver()) {
//			gameOverFlag = true;
			return;
		}
		setBlock();
		while (lineDelete()) {

		}
		createBlock();
	}
	if (frameCount % downPace == 0) {
		block->move(DOWN, box);
	}
	frameCount++;
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

	block->render();

	if (gameOverFlag) {
		DrawString(WND_WIDTH / 2, WND_HEIGHT / 2, "GAME OVER", 0xff0000);
	}

}

SceneType GameScene::nextSceneType() const {
	return TITLE;
}

bool GameScene::isCellEmpty(const CellType type) const {
	return (type == EMPTY) ? true : false;
}

unsigned int GameScene::getCellColor(const CellType type) const {
	switch (type) {
	case WALL : 
		return BOX_WALL_COLOR;
	case EMPTY : 
		return EMPTY_COLOR;
	case CELL_L : 
		return L_COLOR;
	case CELL_L_REVERSE : 
		return L_REVERSE_COLOR;
	case CELL_T : 
		return T_COLOR;
	case CELL_S : 
		return S_COLOR;
	case CELL_S_REVERSE : 
		return S_REVERSE_COLOR;
	case CELL_O : 
		return O_COLOR;
	case CELL_I : 
		return I_COLOR;
	default : 
		return UNKNOWN_COLOR;
	}
}

void GameScene::createBlock() {

	if (block) {
		delete block;
		block = nullptr;
	}

	//生成するブロックをランダムに決定
	std::random_device rand;
	currentBlockType = static_cast<BlockCategory>(rand() % BLOCK_CATEGORY_NUM);

	switch (currentBlockType) {
	case TYPE_L : 
		block = new Block_L();
		break;
	case TYPE_L_REVERSE : 
		block = new Block_L_Reverse();
		break;
	case TYPE_T : 
		block = new Block_T();
		break;
	case TYPE_S : 
		block = new Block_S();
		break;
	case TYPE_S_REVERSE : 
		block = new Block_S_Reverse();
		break;
	case TYPE_O : 
		block = new Block_O();
		break;
	case TYPE_I : 
		block = new Block_I();
		break;
	default : 
		break;
	}
}

void GameScene::setBlock() {
	CellType type;

	switch (currentBlockType) {
	case TYPE_L:
		type = CELL_L;
		break;
	case TYPE_L_REVERSE:
		type = CELL_L_REVERSE;
		break;
	case TYPE_T:
		type = CELL_T;
		break;
	case TYPE_S:
		type = CELL_S;
		break;
	case TYPE_S_REVERSE:
		type = CELL_S_REVERSE;
		break;
	case TYPE_O:
		type = CELL_O;
		break;
	case TYPE_I:
		type = CELL_I;
		break;
	}

	int rowPos[4];
	int linePos[4];
	block->blockCellPos(rowPos, linePos);

	for (int i = 0; i < 4; i++) {
		box[linePos[i]][rowPos[i]] = type;
	}
}

bool GameScene::lineDelete() {
	int row;
	int line;
	//消せる列を探す
	for (line = 0; line < BOX_HEIGHT_CELL - 1; line++) {
		for (row = 1; row < BOX_WIDTH_CELL - 1; row++) {
			if (box[line][row] == EMPTY) {
				break;
			}
		}
		if (row == BOX_WIDTH_CELL - 1) {
			break;
		}
	}

	if (line == BOX_HEIGHT_CELL - 1) {
		return false;
	}

	/* 消せる列が存在した */
	for (; line != 0; line--) {
		for (row = 1; row < BOX_WIDTH_CELL - 1; row++) {
			box[line][row] = box[line - 1][row];
		}
	}
	for (row = 1; row < BOX_WIDTH_CELL - 1; row++) {
		box[0][row] = EMPTY;
	}

	return true;
}