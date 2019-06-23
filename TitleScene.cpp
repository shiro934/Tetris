#include "TitleScene.h"

#include "WindowInfo.h"
#include "DxLib.h"

TitleScene::TitleScene()
{
	frameCount = 0;
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
	frameCount++;
}

void TitleScene::render() const {
	DrawString(WND_WIDTH / 2, WND_HEIGHT / 3, "TETRIS", 0x00ffff);

	if (frameCount % MAX_FRAME_COUNT < FLASH_TIMING) {
		DrawString(WND_WIDTH / 3 + 90, WND_HEIGHT * 2 / 3, "PUSH ENTER TO START", 0x00ffff);
	}

}

SceneType TitleScene::nextSceneType() const {
	return GAME;
}