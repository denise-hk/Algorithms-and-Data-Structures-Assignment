#include "DFS.h"
#include "Maze.h"
#include <algorithm>

void DFS::Step(PathState& state)
{
	int startX = static_cast<int>(startCell.x);
	int startY = static_cast<int>(startCell.y);

	int endX = static_cast<int>(endCell.x);
	int endY = static_cast<int>(endCell.y);

	// first time setup

	if (!state.initialized)
	{
		state.previous.assign(gridWidth, std::vector<PathNode>(gridHeight, { -1, -1 }));

		while (!state.dfsStack.empty())
			state.dfsStack.pop();

		state.visitedNodes.clear();
		state.path.clear();

		state.dfsStack.push({ startX, startY });

		state.initialized = true;
	}

	if (state.dfsStack.empty())
	{
		state.searching = false;
		state.found = false;
		return;
	}

	PathNode current = state.dfsStack.top();
	state.dfsStack.pop();

	int x = current.x;
	int y = current.y;

	state.visitedNodes.push_back(current);

	// goal found
	if (x == endX && y == endY)
	{
		PathNode pathNode = { endX, endY };

		while (!(pathNode.x == startX && pathNode.y == startY))
		{
			state.path.push_back(pathNode);
			pathNode = state.previous[pathNode.x][pathNode.y];
		}

		state.path.push_back({ startX, startY });

		std::reverse(state.path.begin(), state.path.end());

		state.searching = false;
		state.found = true;
		return;
	}

	std::vector<PathNode> neighbors;

	if (!maze[x][y].topWall && y > 0)
		neighbors.push_back({ x, y - 1 });

	if (!maze[x][y].rightWall && x < gridWidth - 1)
		neighbors.push_back({ x + 1, y });

	if (!maze[x][y].bottomWall && y < gridHeight - 1)
		neighbors.push_back({ x, y + 1 });

	if (!maze[x][y].leftWall && x > 0)
		neighbors.push_back({ x - 1, y });

	for (PathNode neighbor : neighbors)
	{
		if (state.previous[neighbor.x][neighbor.y].x == -1)
		{
			state.previous[neighbor.x][neighbor.y] = { x, y };
			state.dfsStack.push(neighbor);
		}
	}
}