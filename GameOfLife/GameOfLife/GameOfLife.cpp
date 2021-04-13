#include "GameOfLife.h"
#include "Rule.h"


GameOfLife* GameOfLife::instance = nullptr;

Grid::Grid(unsigned int pWidth, unsigned int pHeight)
{
	width = pWidth;
	height = pHeight;
	grid = new Cell[width * height];
	memset(grid, 0, width * height);
}

Cell Grid::operator ()(int pRowNum, int ColumnNum) const
{
	if ((pRowNum < 0 || pRowNum > height - 1) || ((ColumnNum < 0 || ColumnNum > width - 1)))
	{
		//retrun an DEAD cell
		return Cell();
	}
	return *(grid + pRowNum * width + ColumnNum);
}

Cell& Grid::operator ()(int pRowNum, int ColumnNum)
{
	if ((pRowNum < 0 || pRowNum > height - 1) || ((ColumnNum < 0 || ColumnNum > width - 1)))
	{
		//TODO: throw exception
	}
	return *(grid + pRowNum * width + ColumnNum);
}

void Grid::Print()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if ((*(grid + i * width + j)).GetState() == CellState::ALIVE)
			{
				std::cout << 'X' << '\t';
			}
			else
			{
				std::cout << '-' << '\t';
			}
		}
		std::cout << "\n";
	}
}

Grid::~Grid()
{
	delete []grid;
	grid = nullptr;
}

GameOfLife::GameOfLife(unsigned int pWidth, unsigned int pHight, GameRule* pGameRule)
{
	grid = new Grid(pWidth, pHight);
	gameRule = pGameRule;
}
	
void GameOfLife::Initialize(Coordinate* pCoordinates, int pNumber)
{
	for (int i = 0; i < pNumber; i++)
	{
		(*grid)(pCoordinates[i].rowNum, pCoordinates[i].colNum).SetState(CellState::ALIVE);
	}
}

void GameOfLife::Generate()
{
	Grid* targetGrid = new Grid(grid->GetWidth(), grid->GetHeight());
	Grid* temp = nullptr;

	gameRule->Run(grid, targetGrid);

	temp = grid;
	grid = targetGrid;
	delete temp;
}

void GameOfLife::Print()
{
	grid->Print();
}

GameOfLife* GameOfLife::GetInstance(unsigned int pWidth, unsigned int pHight, GameRule* pGameRule)
{
	if (instance == nullptr)
	{
		instance = new GameOfLife(pWidth, pHight, pGameRule);
	}
	return instance;
}

GameOfLife::~GameOfLife()
{
	delete grid;
	grid = nullptr;
}