#include "TitleScene.h"

#include "WindowInfo.h"
#include "DxLib.h"

TitleScene::TitleScene()
{
}


TitleScene::~TitleScene()
{
}

void TitleScene::input(const InputKey& input) {
	if (input.checkKeyState(KEY_INPUT_RETURN) == KEY_DOWN) {
		nextSceneFlag = true;
	}
}

void TitleScene::update() {

}

void TitleScene::render() const {
	DrawString(WND_WIDTH / 2, WND_HEIGHT / 2, "TETRIS", 0x00ffff);

}

SceneType TitleScene::nextSceneType() const {
	return GAME;
}