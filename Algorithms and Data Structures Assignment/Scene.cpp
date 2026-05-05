#include "Scene.h"
#include "raylib.h"
#include "SortingVisualizer.h"
#include "Maze.h"
#include "PathVisualizer.h"


void _Scene::HandleInput()
{
	if (IsKeyPressed(KEY_M))
	{
		currentScene = Scene::Menu;
	}

	if (IsKeyPressed(KEY_S))
	{
		currentScene = Scene::Sorting;
	}

	if (currentScene == Scene::Sorting)
	{
		sortVisualizer.HandleInput();
		sortVisualizer.Update();
	}

	if (IsKeyPressed(KEY_Z))
	{
		currentScene = Scene::Maze;
		InitializeMaze();
		GenerateMaze((int)startCell.x, (int)startCell.y);
	}
	if (currentScene == Scene::Maze)
	{
		pathVisualizer.HandleInput();
		pathVisualizer.Update();
	}
}


void _Scene::Draw()
{
	if (currentScene == Scene::Menu)
	{
		DrawText("SORTING VISUALIZER", 380, 180, 40, BLACK);
		DrawText("Press S to go to the sorting scene", 390, 250, 24, DARKGRAY);
		DrawText("Press M to return to menu", 420, 290, 24, DARKGRAY);
		DrawText("Press Z to go to the maze", 420, 330, 24, DARKGRAY);

		DrawText("Inside sorting scene:", 450, 390, 24, BLACK);
		DrawText("1 = Bubble Sort", 500, 430, 20, DARKGRAY);
		DrawText("2 = Selection Sort", 500, 460, 20, DARKGRAY);
		DrawText("3 = Insertion Sort", 500, 490, 20, DARKGRAY);
		DrawText("SPACE = Start/Pause", 500, 520, 20, DARKGRAY);
		DrawText("R = Reset array", 500, 550, 20, DARKGRAY);
		
	}
	
	else if (currentScene == Scene::Sorting)
	{
		DrawText("SORTING SCENE", 400, 300, 40, BLACK);
		sortVisualizer.Draw();
		
	}

	else if (currentScene == Scene::Maze)
	{
		DrawText("Maze", 550, 10, 40, BLACK);
		DrawMaze();
		pathVisualizer.Draw();
	}
}