#include "Dijkstras.h"
#include "Maze.h"

#include <vector>
#include <algorithm>
#include <climits>



void Dijkstras::Step(PathState& state)
{
    int startX = static_cast<int>(startCell.x);
    int startY = static_cast<int>(startCell.y);

    int endX = static_cast<int>(endCell.x);
    int endY = static_cast<int>(endCell.y);

    if (!state.initialized)
    {
        state.distance.assign(
            gridWidth,
            std::vector<int>(gridHeight, INT_MAX)
        );

        state.previous.assign(
            gridWidth,
            std::vector<PathNode>(gridHeight, { -1, -1 })
        );

        while (!state.openSet.empty())
            state.openSet.pop();

        state.visitedNodes.clear();
        state.path.clear();

        state.distance[startX][startY] = 0;
        state.previous[startX][startY] = { startX, startY };
        state.openSet.push({ 0, { startX, startY } });

        state.initialized = true;
    }

    if (state.openSet.empty())
    {
        state.searching = false;
        state.found = false;
        return;
    }

    QueueNode currentQueueNode = state.openSet.top();
    state.openSet.pop();

    PathNode current = currentQueueNode.node;

    int x = current.x;
    int y = current.y;

    if (currentQueueNode.distance > state.distance[x][y])
        return;

    state.visitedNodes.push_back(current);

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

    for (const PathNode neighbor : neighbors)
    {
        int newDistance = state.distance[x][y] + 1;

        if (newDistance < state.distance[neighbor.x][neighbor.y])
        {
            state.distance[neighbor.x][neighbor.y] = newDistance;
            state.previous[neighbor.x][neighbor.y] = current;
            state.openSet.push({ newDistance, neighbor });
        }
    }
}