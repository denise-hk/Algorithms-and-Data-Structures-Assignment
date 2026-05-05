#include "PathfindingAlgorithms.h"
#include "Dijkstras.h"
#include "BFS.h"
#include "DFS.h"


void UpdatePath(PathState& state)
{
	if (!state.searching || state.found)
		return;

	switch (state.currentPath)
	{
		case PathfinderType::Dijkstras:
		{
			Dijkstras dijkstra;
			dijkstra.Step(state);
			break;
		}
			

		case PathfinderType::BFS:
		{
			BFS bfs;
			bfs.Step(state);
			break;
		}

		case PathfinderType::DFS:
		{
			DFS dfs;
			dfs.Step(state);
			break;
		}
	}
}

void ResetPathState(PathState& state)
{
	state.searching = false;
	state.found = false;
	state.initialized = false;

	state.visitedNodes.clear();
	state.path.clear();

	state.distance.clear();
	state.previous.clear();

	while (!state.openSet.empty())
		state.openSet.pop();

	while (!state.bfsQueue.empty())
		state.bfsQueue.pop();

	while (!state.dfsStack.empty())
		state.dfsStack.pop();
}