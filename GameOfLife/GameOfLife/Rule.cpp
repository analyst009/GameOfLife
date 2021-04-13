#include "Rule.h"


void GameRule::Run(const Grid * pSourceGrid, Grid * pTargetGrid)
{
	constexpr int numberOfNeighbours{ 8 };
	constexpr int neighbour_row[numberOfNeighbours] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	constexpr int neighbour_col[numberOfNeighbours] = { -1, 0, 1, -1, 1, -1, 0, 1 };
	int numberofLiveCell{ 0 };
	
	for (int i = 0; i < pSourceGrid->GetHeight(); ++i)
	{
		for (int j = 0; j < pSourceGrid->GetWidth(); ++j)
		{
			numberofLiveCell = 0;
			for (int k = 0; k < numberOfNeighbours; ++k)
			{
				//check the state of all neighbours and count if it is ALIVE
				//for non existing neighbour, grid will return a DEAD cell
				numberofLiveCell += static_cast<int>((*pSourceGrid)(i + neighbour_row[k], j + neighbour_col[k]).GetState());
			}
			if ((*pSourceGrid)(i, j).GetState() == CellState::ALIVE)
			{
				//if cell is ALIVE and has neighbourhood ALIVE cell between 2 and 3
				if (numberofLiveCell >= 2 && numberofLiveCell <= 3)
				{
					(*pTargetGrid)(i, j).SetState(CellState::ALIVE);
				}
			}
			else {
				//if cell us a DEAD cell, check whehter it has exactly 3 ALIVE neighbourhood cells
				if (numberofLiveCell == 3)
				{
					(*pTargetGrid)(i, j).SetState(CellState::ALIVE);
				}
			}
		}
	}
}