#pragma once
#include "raylib.h"


const int cellSize = 25;
const int gridWidth = 25;
const int gridHeight = 25;

struct Cell
{
	bool visited;
	bool topWall, bottomWall, leftWall, rightWall;
};

extern Cell maze[gridWidth][gridHeight];
extern Vector2 startCell;
extern Vector2 endCell;

void InitializeMaze();
void GenerateMaze(int x, int y);
void DrawMaze();
