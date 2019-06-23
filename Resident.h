#pragma once
#ifndef INCLUDED_RESIDENT_H_
#define INCLUDED_RESIDENT_H_

#include "SceneManager.h"
#include "InputKey.h"
#include "Fps.h"

class Resident
{
public:
	Resident();
	~Resident();

	SceneManager* sceneManag;
	InputKey input;
	Fps fpsCalc;
};

#endif // !INCLUDED_RESIDENT_H_
