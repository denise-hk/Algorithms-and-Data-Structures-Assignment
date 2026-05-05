#include "SortingAlgorithms.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include <cstdlib>

void UpdateSort(SortState& state)
{
	
	if (!state.sorting || state.sorted)
		return;

	switch (state.currentSort)
	{
	   case SortType::Bubble:
		   BubbleStep(state);
		   break;

	   case SortType::Selection:
		   SelectionStep(state);
		   break;

	   case SortType::Insertion:
		   InsertionStep(state);
		   break;

	}
}
	
	

void ResetSortState(SortState& state, int arraySize, int minValue, int maxValue)
{
	state.values.clear();

	for (int i = 0; i < arraySize; i++)
	{
		int value = minValue + rand() % (maxValue - minValue + 1);
		state.values.push_back(value);
	}
	
	state.sorting = false;
	state.sorted = false;
	state.comparisons = 0;
	state.swaps = 0;

	state.bubbleI = 0;
	state.bubbleJ = 0;

	state.selectionI = 0;
	state.selectionJ = 1;
	state.minIndex = 0;

	state.insertionI = 1;
	state.insertionJ = 1;

}
std::string GetSortName(SortType type)
{
	switch (type)
	{
	case SortType::Bubble:
		return "Bubble Sort";
	case SortType::Selection:
		return "Selection Sort";
	case SortType::Insertion:
		return "Insertion Sort";
	default:
		return "Unkown";
	}
}