#include "BubbleSort.h"
#include <algorithm>

void BubbleStep(SortState& state)
{
	
	int n = (int)state.values.size();

	if (state.bubbleI >= n - 1)
	{
		state.sorting = false;
		state.sorted = true;

		return;
	}

	if (state.bubbleJ >= n - state.bubbleI - 1)
	{
		state.bubbleJ = 0;
		state.bubbleI++;
		
		return;
	}

	state.comparisons++;
	if (state.values[state.bubbleJ] > state.values[state.bubbleJ + 1])
	{
		std::swap(state.values[state.bubbleJ], state.values[state.bubbleJ + 1]);
		state.swaps++;
	}

	state.bubbleJ++;
}