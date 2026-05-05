#include "PathVisualizer.h"
#include "raylib.h"
#include "Maze.h"



PathVisualizer::PathVisualizer()
{
	pathState.reset();
}

void PathVisualizer::HandleInput()
{
	if (IsKeyPressed(KEY_ONE))
	{
		pathState.reset();
		pathState.currentPath = PathfinderType::Dijkstras;
	}

	if (IsKeyPressed(KEY_TWO))
	{
		pathState.reset();
		pathState.currentPath = PathfinderType::BFS;
	}

	if (IsKeyPressed(KEY_THREE))
	{
		pathState.reset();
		pathState.currentPath = PathfinderType::DFS;
	}

	if (IsKeyPressed(KEY_ENTER))
	{
		pathState.reset();
		pathState.searching = true;
		frameCounter = 0;
	}
}

void PathVisualizer::Update()
{

	if (!pathState.searching)
		return;

	frameCounter++;

	if (frameCounter >= 5)
	{
		pathState.update();
		frameCounter = 0;
	}
}

void PathVisualizer::DrawPath() const
{
	int offsetX = (GetScreenWidth() - gridWidth * cellSize) / 2;
	int offsetY = (GetScreenHeight() - gridHeight * cellSize) / 2;

	for (const PathNode& node : pathState.visitedNodes)
	{
		DrawRectangle(offsetX + node.x * cellSize + 7, offsetY + node.y * cellSize + 7, cellSize - 12, cellSize - 12, SKYBLUE);
	}
	for (const PathNode& node : pathState.path)
	{
		DrawRectangle(offsetX + node.x * cellSize + 5, offsetY + node.y * cellSize + 5, cellSize - 10, cellSize - 10, GREEN);
	}
}


void PathVisualizer::Draw()const
{
	DrawPath();

	if (pathState.currentPath == PathfinderType::Dijkstras)
		DrawText("Pathfinder : Dijkstra", 20, 30, 24, BLACK);
	else if (pathState.currentPath == PathfinderType::BFS)
		DrawText("Pathfinder : BFS", 20, 30, 24, BLACK);
	else if (pathState.currentPath == PathfinderType::DFS)
		DrawText("Pathfinder : DFS", 20, 30, 24, BLACK);
	
		DrawText("1 Dijkstra | 2 BFS | 3 DFS | ENTER Start", 20, 65, 20, DARKGRAY);
}