//-----ReSpace-Engine-----
//	
//	Здесь должно быть что-то важное... :)
//	
//------------------------
#pragma once
#include <map>
#include "Scene.h"

class SceneManager
{
private:
	static int numberOfScenes;
	static std::map<int, Scene> scenes;
	static Scene* curScene;

public:
	static int addScene(Scene&& _scene);
	static void changeScene(int sceneId);
	static Scene& getScene();
};

