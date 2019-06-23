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
};

#endif // !INCLUDED_TITLE_SCENE_H_
