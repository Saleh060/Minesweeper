#include "raylib.h"
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include "raymath.h"

#define COLS 10
#define ROWS 10

const int screenWidth = 400;
const int screenHeight = 400;

const int cellwidth = screenWidth / COLS;
const int cellHeight = screenHeight / ROWS;

typedef struct Cell
{
	int i;
	int j;
	bool containMine;
	bool revealed;
} Cell;

Cell grid[ROWS][COLS];

void CellDraw(Cell);
bool IndexIsValid(int, int);
void CellReveal(int, int);



int main()
{
	srand(time(0));

	InitWindow(screenHeight, screenHeight, "Minesweeper");

	for (int i = 0; i < COLS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{			
			grid[i][j] = 
			{ i, j, false, false};
		}


	}

	int mineToPlace = (int)(ROWS * COLS * 0.1f);

	while (mineToPlace > 0)
	{
		int i = rand() % COLS;
		int j = rand() % ROWS;

		if (!grid[i][j].containMine)
		{
			grid[i][j].containMine = true;
			mineToPlace--;
		}
	}

	while (!WindowShouldClose())
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			Vector2 mpos = GetMousePosition();
			int indexI = mpos.x / cellwidth;
			int indexJ = mpos.y / cellHeight;

			if (IndexIsValid(indexI, indexJ))
			{
				CellReveal(indexI, indexJ);
			}
		}

		BeginDrawing();

		ClearBackground(WHITE);

		for (int i = 0; i < COLS; i++)
		{
			for (int j = 0; j < ROWS; j++)
			{
				CellDraw(grid[i][j]);
			}
		}

		EndDrawing();

	}
		
	CloseWindow();
	return 0;

}

void CellDraw(Cell cell)
{
	if (cell.revealed)
	{
		if (cell.containMine)
		{
			DrawRectangle(cell.i * cellwidth, cell.j * cellHeight, cellwidth, cellHeight, RED);
		}
		else
		{
		   DrawRectangle(cell.i * cellwidth, cell.j * cellHeight, cellwidth, cellHeight, LIGHTGRAY);
		}
	}


	DrawRectangleLines(cell.i * cellwidth, cell.j * cellHeight, cellwidth, cellHeight, BLACK);
}

bool IndexIsValid(int i, int j)
{
	return i >= 0 && i < COLS && j >= 0 && j < ROWS;
}

void CellReveal(int i, int j)
{
	grid[i][j].revealed = true;

	if (grid[i][j].containMine)
	{

	}
	else
	{

	}
}

