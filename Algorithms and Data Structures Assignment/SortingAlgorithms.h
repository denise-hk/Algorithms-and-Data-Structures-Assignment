#pragma once
#include <vector>
#include <string>

enum class SortType
{
	Bubble,
	Selection,
	Insertion
};

class SortState
{
public:

	// Constructor
	SortState(int arraySize, int minValue, int maxValue);

	// Main logic
	void update();
	void reset(int arraySize, int minValue, int maxValue);

	// Control
	void start();
	void stop();

	// Getters
	bool isSorting() const;
	bool isSorted() const;

	const std::vector<int>& getValues() const;

	int getComparisons() const;
	int getSwaps() const;

	SortType getSortType() const;
	void setSortType(SortType type);

	std::string getSortName() const;



	std::vector<int> values;

	bool sorting = false;
	bool sorted = false;

	SortType currentSort = SortType::Bubble;

	int comparisons = 0;
	int swaps = 0;

	int minValue = 0;
	int maxValue = 0;

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

