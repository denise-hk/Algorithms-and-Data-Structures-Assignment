#include "SelectionSort.h"
#include <algorithm>

void SelectionStep(SortState& state)
{
    int n = (int)state.values.size();

    if (state.selectionI >= n - 1)
    {
        state.sorting = false;
        state.sorted = true;
        return;
    }

    if (state.selectionJ < n)
    {
        state.comparisons++;

        if (state.values[state.selectionJ] < state.values[state.minIndex])
        {
            state.minIndex = state.selectionJ;
        }

        state.selectionJ++;
    }
    else
    {
        if (state.minIndex != state.selectionI)
        {
            std::swap(state.values[state.selectionI], state.values[state.minIndex]);
            state.swaps++;
        }

        state.selectionI++;
        state.minIndex = state.selectionI;
        state.selectionJ = state.selectionI + 1;
    }
}