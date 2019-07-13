#include "TitleScene.h"

#include "WindowInfo.h"
#include "DxLib.h"


#define STRING_COLOR 0x00ffff	//�����̐F
#define MAX_FRAME_COUNT 110
#define FLASH_TIMING 70		//�_�ł���^�C�~���O

TitleScene::TitleScene()
{
	frameCount = 0;
}


TitleScene::~TitleScene()
{
}

void TitleScene::input(const InputKey& input) {
	//���̃V�[���֑J�ڂ���t���O�𗧂Ă�
	if (input.checkKeyState(KEY_INPUT_RETURN) == KEY_DOWN) {
		nextSceneFlag = true;
	}
}

void TitleScene::update() {
	frameCount++;

	//frameCount��int�͈͓̔��Ɏ��܂�悤��
	if (frameCount == INT_MAX - 1) {
		frameCount = 0;
	}
}

void TitleScene::render() const {
	DrawString(WND_WIDTH / 2, WND_HEIGHT / 3, "TETRIS", STRING_COLOR);

	if (frameCount % MAX_FRAME_COUNT < FLASH_TIMING) {
		DrawString(WND_WIDTH / 3 + 90, WND_HEIGHT * 2 / 3, "PUSH ENTER TO START", STRING_COLOR);
	}
}

SceneType TitleScene::nextSceneType() const {
	return GAME;
}