#pragma once
#include <vector>
#include <string>

enum class SortType
{
	Bubble,
	Selection,
	Insertion
};

struct SortState
{
	std::vector<int> values;

	bool sorting = false;
	bool sorted = false;

	SortType currentSort = SortType::Bubble;

	int comparisons = 0;
	int swaps = 0;

	// Bubble
	int bubbleI = 0;
	int bubbleJ = 0;

	// Selection
	int selectionI = 0;
	int selectionJ = 1;
	int minIndex = 0;

	// Insertion
	int insertionI = 1;
	int insertionJ = 1;

};

void UpdateSort(SortState& state);
void ResetSortState(SortState& state, int arraySize, int minValue, int maxValue);
std::string GetSortName(SortType type);