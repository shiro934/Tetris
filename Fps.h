#pragma once
#ifndef INCLUDED_FPS_H_
#define INCLUDED_FPS_H_

class Fps
{
public:
	Fps();
	~Fps();

	bool update();
	void drawFPS() const;
	void wait() const ;

	int getFrameCount() const { return frameCount; }	//���t���[�����J��Ԃ�
private : 
	unsigned int startTime;		//����J�n����
	int frameCount;
	float fps;			//�v�Z�����t���[����
	const int FPS = 60;	//�ݒ�t���[����
};

#endif // !INCLUDED_FPS_H_
