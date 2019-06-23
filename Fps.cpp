#include "Fps.h"

#include "DxLib.h"

Fps::Fps()
{
	startTime = 0;
	frameCount = 0;
	fps = 0;
}


Fps::~Fps()
{
}

bool Fps::update() {
	if (frameCount == 0) {
		startTime = GetNowCount();
	}
	if (frameCount == FPS) {	//FPSで設定した値なら平均を計算
		int t = GetNowCount();
		fps = 1000.0f / (static_cast<float>(t - startTime) / FPS);
		frameCount = 0;
		startTime = t;
	}
	frameCount++;
	return true;
}

void Fps::drawFPS() const {
	DrawFormatString(0, 0, 0xffffff, "%.1f", fps);
}

void Fps::wait() const {
	int elapsedTime = GetNowCount() - startTime;	//経過時間
	int waitTime = frameCount * 1000 / FPS - elapsedTime;	//待機時間
	if (waitTime > 0) {
		Sleep(waitTime);
	}
}