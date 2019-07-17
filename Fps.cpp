#include "Fps.h"

#include "DxLib.h"

#define FPS 60	//�ݒ�t���[����
#define STRING_COLOR 0xffffff	//�����̐F

Fps::Fps()
{
	startTime = 0;
	frameCount = 0;
	fps = 0;
}


Fps::~Fps()
{
}

void Fps::update() {
	if (frameCount == 0) {
		startTime = GetNowCount();
	}
	if (frameCount == FPS) {	//FPS�Őݒ肵���l�Ȃ畽�ς��v�Z
		int time = GetNowCount();
		fps = 1000.0f / (static_cast<float>(time - startTime) / FPS);
		frameCount = 0;
		startTime = time;
	}
	frameCount++;
}

void Fps::drawFPS() const {
	DrawFormatString(0, 0, STRING_COLOR, "%.1f", fps);
}

void Fps::wait() const {
	int elapsedTime = GetNowCount() - startTime;	//�o�ߎ���
	int waitTime = frameCount * 1000 / FPS - elapsedTime;	//�ҋ@����
	if (waitTime > 0) {
		Sleep(waitTime);
	}
}