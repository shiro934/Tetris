#include "SceneManager.h"

#include "GameScene.h"

SceneManager::SceneManager()
{
	currentScene = new GameScene();
}


SceneManager::~SceneManager()
{
	delete currentScene;
}

void SceneManager::input() const {
	currentScene->input();
}

void SceneManager::update() const {
	currentScene->update();
}

void SceneManager::render() const {
	currentScene->render();
}