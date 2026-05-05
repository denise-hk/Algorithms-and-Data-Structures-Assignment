#include "raylib.h"
#include "Scene.h"
#include <ctime>
#include <cstdlib>


int main()
{
	static const int screenWidth = 1200;
	static const int screenHeight = 800;

	srand((unsigned)time(nullptr));

	InitWindow(screenWidth, screenHeight, "Algorithms and Data Structures Assignment");
	SetTargetFPS(60);

	_Scene sceneManager;
	SortVisualizer sortVisualizer;

	while (!WindowShouldClose())
	{
		sceneManager.HandleInput();
		
		// Draw
		BeginDrawing();
		ClearBackground(RAYWHITE);
		sceneManager.Draw();
		
		




		EndDrawing();
	}

	// CleanUp
	CloseWindow();

	return 0;
		
}