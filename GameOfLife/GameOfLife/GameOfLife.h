#pragma once

#include <iostream>

class GameRule;

enum class CellState 
{
	DEAD = 0,
	ALIVE
};


/* this class represents a Cell in the game*/
class Cell
{
public:
	Cell ()
	{
		state = CellState::DEAD;
	}
	void SetState (CellState pState)
	{
		state = pState;
	}
	CellState GetState () const
	{
		return state;
	}
	~Cell()
	{
	}

private:
	CellState state;
};

/* This class represents board of the game in 2D array view*/
class Grid
{
public:
	Grid(unsigned int pWidth, unsigned int pHeight);

	Cell		operator ()(int pRowNum, int ColumnNum) const;
	Cell&		operator ()(int pRowNum, int ColumnNum);
	void		Print();
	
	int GetWidth() const
	{
		return width;
	}

	int GetHeight() const
	{
		return height;
	}

	~Grid();


private:
	int			width;		//width of the board	
	int			height;		//height of the board
	Cell *		grid;       //array of cells
};

struct Coordinate
{
	unsigned int rowNum;
	unsigned int colNum;
};

class GameOfLife
{
public:
			
	void				Initialize(Coordinate* pCoordinate, int pNumber);

	void				Generate();

	void				Print();

	static GameOfLife*	GetInstance(unsigned int pWidth, unsigned int pHight, GameRule* pGameRule);

	~GameOfLife();

private:

	GameOfLife(unsigned int pWidth, unsigned int pHight, GameRule* pGameRule);


	Grid	 *				grid;
	GameRule *				gameRule;
	static GameOfLife*		instance;
};
