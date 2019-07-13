#include "SceneManager.h"

#include "TitleScene.h"
#include "GameScene.h"

#include <windows.h>

#include <cassert>

SceneManager::SceneManager()
{
	currentScene = new TitleScene();
}


SceneManager::~SceneManager()
{
	delete currentScene;
}

void SceneManager::input(const InputKey& input) const {
	assert(currentScene != nullptr);
	currentScene->input(input);
}

void SceneManager::update() const {
	assert(currentScene != nullptr);
	currentScene->update();
}

void SceneManager::render() const {
	assert(currentScene != nullptr);
	currentScene->render();
}

void SceneManager::sceneChange() {
	assert(currentScene != nullptr);

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
		MessageBox(nullptr, TEXT("nextSceneÇ™ê≥ÇµÇ≠Ç†ÇËÇ‹ÇπÇÒ")
			, TEXT("ÉGÉâÅ["), MB_OK);
		break;
	}

}