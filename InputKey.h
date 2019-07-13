#pragma once
#ifndef INCLUDED_INPUT_KEY_H_
#define INCLUDED_INPUT_KEY_H_

#include "InputKeyState.h"

#define SET_KEY_NUM 256

class InputKey
{
public:
	InputKey();
	~InputKey();

	void setKey();
	KeyState checkKeyState(const unsigned int key) const { return keyState[key]; }
private : 
	char preKey[SET_KEY_NUM];		//�O�t���[���̃L�[���
	KeyState keyState[SET_KEY_NUM]; //���̃t���[���̃L�[�̉������
};

#endif // !INCLUDED_INPUT_KEY_H_
