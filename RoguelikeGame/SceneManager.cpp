#include "SceneManager.h"

int SceneManager::numberOfScenes = 0;
std::map<int, Scene> SceneManager::scenes;
Scene* SceneManager::curScene = nullptr;


int SceneManager::addScene(Scene&& _scene)
{
	scenes.emplace(numberOfScenes, std::forward<Scene>(_scene));
	numberOfScenes++;
	return numberOfScenes;
}

void SceneManager::changeScene(int sceneId)
{
	curScene = &scenes.at(sceneId);
}

Scene& SceneManager::getScene()
{
	return *curScene;
}