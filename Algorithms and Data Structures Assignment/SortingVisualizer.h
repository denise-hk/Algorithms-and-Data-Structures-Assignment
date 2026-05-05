#pragma once
#include "SortingAlgorithms.h"

class SortVisualizer
{
public:

	
	SortVisualizer();

	void HandleInput();
	void Update();
	void Draw() const;



private:

	
	int _arraySize;

	SortState sortState;

	void DrawBars() const;
	void ResetCurrentArray();

};
