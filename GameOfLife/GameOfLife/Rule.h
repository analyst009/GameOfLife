#pragma once

#include "GameOfLife.h"


/* This class encapsulate rules of the Game */
class GameRule
{
	
public:	
	void Run(const Grid * pSourceGrid, Grid * pTargetGrid);
};
