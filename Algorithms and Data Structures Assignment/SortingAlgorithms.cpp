#include "SortingAlgorithms.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include <cstdlib>

SortState::SortState(int arraySize, int minValue, int maxValue)
{
	reset(arraySize, minValue, maxValue);
}

void SortState::update()
{
	
	if (!sorting || sorted)
		return;

	switch (currentSort)
	{
		case SortType::Bubble:
		{
			BubbleSort bubbleSort;
			bubbleSort.step(*this);
			break;
		}


		case SortType::Selection:
		{
			SelectionSort selectionSort;
			selectionSort.step(*this);
			break;
		}


		case SortType::Insertion:
		{
			InsertionSort insertionSort;
			insertionSort.step(*this);
			break;
		};

	}
}
	
	

void SortState::reset(int arraySize, int minValue, int maxValue)
{
	values.clear();

	this->minValue = minValue;
	this->maxValue = maxValue;

	for (int i = 0; i < arraySize; i++)
	{
		int value = minValue + rand() % (maxValue - minValue + 1);
		values.push_back(value);
	}
	
	sorting = false;
	sorted = false;
	comparisons = 0;
	swaps = 0;

	bubbleI = 0;
	bubbleJ = 0;

	selectionI = 0;
	selectionJ = 1;
	minIndex = 0;

	insertionI = 1;
	insertionJ = 1;

}

void SortState::start()
{
	if (!sorted)
	{
		sorting = true;
	}
}

void SortState::stop()
{
	sorting = false;
}

bool SortState::isSorting() const
{
	return sorting;
}

bool SortState::isSorted() const
{
	return sorted;
}

const std::vector<int>& SortState::getValues() const
{
	return values;
}

int SortState::getComparisons() const
{
	return comparisons;
}

int SortState::getSwaps() const
{
	return swaps;
}

SortType SortState::getSortType() const
{
	return currentSort;
}

void SortState::setSortType(SortType type)
{
	currentSort = type;
}

std::string SortState::getSortName() const
{
	switch (currentSort)
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