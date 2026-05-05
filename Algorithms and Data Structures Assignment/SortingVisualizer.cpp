#include "SortingVisualizer.h"
#include "raylib.h"


static const int _screenWidth = 1200;
static const int _screenHeight = 800;
static const int ARRAY_SIZE = 30;
static const int minValue = 10;
static const int maxValue = 200;


SortVisualizer::SortVisualizer()
{
	ResetSortState(sortState, ARRAY_SIZE, minValue, maxValue);
	ResetCurrentArray();
}

void SortVisualizer::ResetCurrentArray()
{
	ResetSortState(sortState, ARRAY_SIZE, minValue, maxValue);
	
}



void SortVisualizer::HandleInput()
{
	if (IsKeyPressed(KEY_ONE))
	{
		sortState.currentSort = SortType::Bubble;
		ResetCurrentArray();

	}

	if (IsKeyPressed(KEY_TWO))
	{
		sortState.currentSort = SortType::Selection;
		ResetCurrentArray();
	}

	if (IsKeyPressed(KEY_THREE))
	{
		sortState.currentSort = SortType::Insertion;
		ResetCurrentArray();
	}

	if (IsKeyPressed(KEY_R))
	{
		ResetCurrentArray();
	}

	if (IsKeyPressed(KEY_SPACE) && !sortState.sorted)
	{
		sortState.sorting = !sortState.sorting;
	}
}

void SortVisualizer::Update()
{
	UpdateSort(sortState);
}

void SortVisualizer::DrawBars() const
{
	int bottomY = 700;

	int barWidth = 20;
	int spacing = 10;   

	int count = (int)sortState.values.size();

	int totalWidth = count * barWidth + (count - 1) * spacing;

	int startX = (_screenWidth - totalWidth) / 2;

	for (int i = 0; i < count; i++)
	{
		int value = sortState.values[i];

		int x = startX + i * (barWidth + spacing);

		Color color = BLUE;
		if (sortState.sorting)
			color = ORANGE;
		else if (sortState.sorted)
			color = GREEN;
		
		DrawRectangle(
			x,
			bottomY - value,
			barWidth,
			value,
			color
		);
		
		DrawText(
			TextFormat("%d", value),
			x,
			bottomY - value - 15,
			10,
			BLACK
		);
	}
	
}

void SortVisualizer::Draw() const
{
	DrawBars();
	DrawText(TextFormat("Array size: %d", (int)sortState.values.size()), 20, 230, 20, BLACK);

	DrawText(TextFormat("Algorithm: %s", GetSortName(sortState.currentSort).c_str()), 20, 20, 24, BLACK);
	DrawText(TextFormat("Comparison: %d", sortState.comparisons), 20, 55, 24, BLACK);
	DrawText(TextFormat("Swaps: %d", sortState.swaps), 20, 90, 24, BLACK);

	if (sortState.sorted)
		DrawText("DONE!", 20, 125, 28, GREEN);
	else if (sortState.sorting)
		DrawText("Sorting", 20, 125, 28, ORANGE);
	else 
		DrawText("Paused", 20, 125, 28, RED);
	
	DrawText("1 Bubble | 2 Selection | 3 Insertion | SPACE Start/Pause | R Reset", 20, 160, 20, DARKGRAY);


}