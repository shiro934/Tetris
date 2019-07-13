#include "DxLib.h"

#include "Resident.h"
#include "WindowInfo.h"

int WINAPI WinMain(HINSTANCE hInstacem, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow) {

	Resident resident;

	ChangeWindowMode(TRUE);
	SetGraphMode(WND_WIDTH, WND_HEIGHT, 32);	//画面サイズセット

	if (DxLib_Init() == -1) {
		return -1;
	}

	while (1) {
		//ウインドウメッセージを処理
		if (ProcessMessage() != 0) {
			break;
		}
		resident.input.setKey();	//現在の入力状態をセット
		ClearDrawScreen();	//画面の絵を削除

		resident.sceneManag.sceneChange();
		resident.sceneManag.input(resident.input);
		resident.sceneManag.update();
		resident.sceneManag.render();

		//fps処理
		resident.fpsCalc.update();
		resident.fpsCalc.drawFPS();
		resident.fpsCalc.wait();
	}
	DxLib_End();

	return 0;
}