#pragma once
#ifndef INCLUDED_SCENE_H_
#define INCLUDED_SCENE_H_

#include "InputKey.h"
#include "SceneType.h"

class Scene
{
public:
	Scene();
	~Scene();

	virtual void input(const InputKey& input) = 0;
	virtual void update() = 0;
	virtual void render() const = 0;

	virtual SceneType nextSceneType() const = 0;	//���̃V�[���^�C�v��Ԃ�

	bool isNextScene() const { return nextSceneFlag; }	//�V�[���J�ڂ����邩�Ԃ�
protected : 
	bool nextSceneFlag;
};


#endif // !INCLUDED_SCENE_H_
