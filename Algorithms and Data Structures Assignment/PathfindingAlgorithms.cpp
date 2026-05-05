#include "PathfindingAlgorithms.h"
#include "Dijkstras.h"
#include "BFS.h"
#include "DFS.h"


void PathState::update()
{
	if (!searching || found)
		return;

	switch (currentPath)
	{
		case PathfinderType::Dijkstras:
		{
			Dijkstras dijkstra;
			dijkstra.Step(*this);
			break;
		}
			

		case PathfinderType::BFS:
		{
			BFS bfs;
			bfs.Step(*this);
			break;
		}

		case PathfinderType::DFS:
		{
			DFS dfs;
			dfs.Step(*this);
			break;
		}
	}
}

void PathState::reset()
{
	searching = false;
	found = false;
	initialized = false;

	visitedNodes.clear();
	path.clear();

	distance.clear();
	previous.clear();

	while (!openSet.empty())
		openSet.pop();

	while (!bfsQueue.empty())
		bfsQueue.pop();

	while (!dfsStack.empty())
		dfsStack.pop();
}