#pragma once
#include "SortingVisualizer.h"
#include "PathVisualizer.h"


enum class Scene
{
	Menu,
	Sorting,
	Maze
};

struct _Scene
{
public:

	void HandleInput();
	void Draw();

private:
	Scene currentScene = Scene::Menu;
	SortVisualizer sortVisualizer;
	PathVisualizer pathVisualizer;
};
