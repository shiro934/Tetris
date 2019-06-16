#pragma once
#ifndef INCLUDED_SCENE_MANAGER_H_
#define INCLUDED_SCENE_MANAGER_H_

#include "Scene.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void input() const;
	void update() const;
	void render() const;

private : 
	Scene* currentScene;
};

#endif // !INCLUDED_SCENE_MANAGER_H_
