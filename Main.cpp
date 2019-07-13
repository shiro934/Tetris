#include "DxLib.h"

#include "Resident.h"
#include "WindowInfo.h"

int WINAPI WinMain(HINSTANCE hInstacem, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {

	Resident resident;

	ChangeWindowMode(TRUE);
	SetGraphMode(WND_WIDTH, WND_HEIGHT, 32);	//��ʃT�C�Y�Z�b�g

	if (DxLib_Init() == -1) {
		return -1;
	}

	while (1) {
		//�E�C���h�E���b�Z�[�W������
		if (ProcessMessage() != 0) {
			break;
		}
		resident.input.setKey();	//���݂̓��͏�Ԃ��Z�b�g
		ClearDrawScreen();	//��ʂ̊G���폜

		resident.sceneManag.sceneChange();
		resident.sceneManag.input(resident.input);
		resident.sceneManag.update();
		resident.sceneManag.render();

		//fps����
		resident.fpsCalc.update();
		resident.fpsCalc.drawFPS();
		resident.fpsCalc.wait();
	}
	DxLib_End();

	return 0;
}