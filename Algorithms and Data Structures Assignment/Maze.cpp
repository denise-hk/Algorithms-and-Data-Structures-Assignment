#include "Maze.h"
#include "raylib.h"


Cell maze[gridWidth][gridHeight];
Vector2 startCell = { 0,0 };
Vector2 endCell = { gridWidth - 1, gridHeight - 1 };


void InitializeMaze()
{
	for (int x = 0; x < gridWidth; x++)
	{
		for (int y = 0; y < gridHeight; y++)
		{

			maze[x][y].visited = false;
			maze[x][y].topWall = true;
			maze[x][y].bottomWall = true;
			maze[x][y].leftWall = true;
			maze[x][y].rightWall = true;
		}
	}
}

void GenerateMaze(int x, int y)
{
	maze[x][y].visited = true;
	while (true)
	{
		int directions[] = { 0, 1, 2, 3 }; // up, right, down, left
		for (int i = 0; i < 4; i++)
		{
			int j = GetRandomValue(i, 3);
			int temp = directions[i];
			directions[i] = directions[j];
			directions[j] = temp;
		}

		bool moved = false;
		for (int i = 0; i < 4; i++)
		{
			int nx = x, ny = y;
			if (directions[i] == 0) ny -= 1;		// UP
			else if (directions[i] == 1) nx += 1;	// Right
			else if (directions[i] == 2) ny += 1;	// Down
			else if (directions[i] == 3) nx -= 1;	// Left

			if (nx >= 0 && nx < gridWidth && ny >= 0 && ny < gridHeight && !maze[nx][ny].visited)
			{
				if (directions[i] == 0)
				{
					maze[x][y].topWall = false;
					maze[nx][ny].bottomWall = false;
				}
				else if (directions[i] == 1)
				{
					maze[x][y].rightWall = false;
					maze[nx][ny].leftWall = false;
				}
				else if (directions[i] == 2)
				{
					maze[x][y].bottomWall = false;
					maze[nx][ny].topWall = false;
				}
				else if (directions[i] == 3)
				{
					maze[x][y].leftWall = false;
					maze[nx][ny].rightWall = false;
				}
				
				GenerateMaze(nx, ny); // generating it recursively
				moved = true;
				break;
			}
		}
		if (!moved) break;
	}
}
void DrawMaze()
{
	int offsetX = (GetScreenWidth() - gridWidth * cellSize) / 2;
	int offsetY = (GetScreenHeight() - gridHeight * cellSize) / 2;

	for (int x = 0; x < gridWidth; x++)
	{
		for (int y = 0; y < gridHeight; y++)
		{
			int posX = offsetX + x * cellSize;
			int posY = offsetY + y * cellSize;
			if (maze[x][y].topWall)
				DrawLine(posX, posY, posX + cellSize, posY, BLACK);
			if (maze[x][y].rightWall)
				DrawLine(posX + cellSize, posY, posX + cellSize, posY + cellSize, BLACK);
			if (maze[x][y].bottomWall)
				DrawLine(posX, posY + cellSize, posX + cellSize, posY + cellSize, BLACK);
			if (maze[x][y].leftWall)
				DrawLine(posX, posY, posX, posY + cellSize, BLACK);

		}
	}

	DrawRectangle(
		offsetX + (int)startCell.x * cellSize + 5,
		offsetY + (int)startCell.y * cellSize + 5,
		cellSize - 10,
		cellSize - 10,
		GREEN
	);

	DrawRectangle(
		offsetX + (int)endCell.x * cellSize + 5,
		offsetY + (int)endCell.y * cellSize + 5,
		cellSize - 10,
		cellSize - 10,
		RED
	);
}
