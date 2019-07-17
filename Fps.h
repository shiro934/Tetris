#pragma once
#ifndef INCLUDED_FPS_H_
#define INCLUDED_FPS_H_

class Fps
{
public:
	Fps();
	~Fps();

	void update();
	void drawFPS() const;
	void wait() const ;

	int getFrameCount() const { return frameCount; }	//���t���[���ڂ���Ԃ�
private : 
	unsigned int startTime;		//����J�n����
	int frameCount;
	float fps;			//�v�Z�����t���[����
};

#endif // !INCLUDED_FPS_H_
