#include "InsertionSort.h"
#include<algorithm>

void InsertionStep(SortState& state)
{
	int n = (int)state.values.size();
	if (state.insertionI >= n)
	{
		state.sorting = false;
		state.sorted = true;

		return;

	}

	if (state.insertionJ > 0)
	{
		state.comparisons++;

		if (state.values[state.insertionJ - 1] > state.values[state.insertionJ])
		{
			std::swap(state.values[state.insertionJ - 1], state.values[state.insertionJ]);
			state.swaps++;
			state.insertionJ--;

			return;
		}
	}

	state.insertionI++;
	state.insertionJ = state.insertionI;
	
}