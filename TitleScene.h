#pragma once
#ifndef INCLUDED_TITLE_SCENE_H_
#define INCLUDED_TITLE_SCENE_H_

#include "Scene.h"
class TitleScene :
	public Scene
{
public:
	TitleScene();
	~TitleScene();

	void input(const InputKey& input);
	void update();
	void render() const;

	SceneType nextSceneType() const;

private : 
	int frameCount;
	const int MAX_FRAME_COUNT = 120;
	const int FLASH_TIMING = 100;
};

#endif // !INCLUDED_TITLE_SCENE_H_
