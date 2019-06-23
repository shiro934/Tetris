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
	if (frameCount == FPS) {	//FPS�Őݒ肵���l�Ȃ畽�ς��v�Z
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
	int elapsedTime = GetNowCount() - startTime;	//�o�ߎ���
	int waitTime = frameCount * 1000 / FPS - elapsedTime;	//�ҋ@����
	if (waitTime > 0) {
		Sleep(waitTime);
	}
}