#pragma once
#ifndef INCLUDED_SCENE_H_
#define INCLUDED_SCENE_H_

#include "InputKey.h"

class Scene
{
public:
	Scene();
	~Scene();

	virtual void input(const InputKey& input) const = 0;
	virtual void update() = 0;
	virtual void render() const = 0;

};


#endif // !INCLUDED_SCENE_H_
