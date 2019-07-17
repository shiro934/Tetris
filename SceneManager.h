#pragma once
#ifndef INCLUDED_SCENE_MANAGER_H_
#define INCLUDED_SCENE_MANAGER_H_

#include "Scene.h"
#include "InputKey.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void input(const InputKey& input) const;
	void update() const;
	void render() const;

	void sceneChange();	//ƒV[ƒ“Ø‚è‘Ö‚¦
private : 
	Scene* currentScene;
};

#endif // !INCLUDED_SCENE_MANAGER_H_
