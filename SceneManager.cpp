#include "SceneManager.h"

#include "TitleScene.h"
#include "GameScene.h"

SceneManager::SceneManager()
{
	currentScene = new TitleScene();
}


SceneManager::~SceneManager()
{
	delete currentScene;
}

void SceneManager::input(const InputKey& input) const {
	currentScene->input(input);
}

void SceneManager::update() const {
	currentScene->update();
}

void SceneManager::render() const {
	currentScene->render();
}

void SceneManager::sceneChange() {
	if (currentScene->isNextScene() == false) {
		return;
	}

	SceneType nextScene = currentScene->nextSceneType();

	if (currentScene) {
		delete currentScene;
	}

	switch (nextScene)
	{
	case TITLE:
		currentScene = new TitleScene();
		break;
	case GAME:
		currentScene = new GameScene();
		break;
	default:
		break;
	}

}