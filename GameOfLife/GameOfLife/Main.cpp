#include <iostream>

#include "GameOfLife.h"
#include "Rule.h"


void Test_1(Coordinate*& coordinates, unsigned int& activeCells)
{
    activeCells = 4;

    coordinates = new Coordinate[activeCells];

    coordinates[0].rowNum = 1;
    coordinates[0].colNum = 1;

    coordinates[1].rowNum = 1;
    coordinates[1].colNum = 2;

    coordinates[2].rowNum = 2;
    coordinates[2].colNum = 1;

    coordinates[3].rowNum = 2;
    coordinates[3].colNum = 2;
}

void Test_2(Coordinate*& coordinates, unsigned int& activeCells)
{
    activeCells = 5;

    coordinates = new Coordinate[activeCells];

    coordinates[0].rowNum = 0;
    coordinates[0].colNum = 1;

    coordinates[1].rowNum = 1;
    coordinates[1].colNum = 0;

    coordinates[2].rowNum = 2;
    coordinates[2].colNum = 1;

    coordinates[3].rowNum = 0;
    coordinates[3].colNum = 2;

    coordinates[4].rowNum = 1;
    coordinates[4].colNum = 2;
}

void Test_3(Coordinate*& coordinates, unsigned int& activeCells)
{
    activeCells = 3;

    coordinates = new Coordinate[activeCells];

    coordinates[0].rowNum = 1;
    coordinates[0].colNum = 1;

    coordinates[1].rowNum = 1;
    coordinates[1].colNum = 0;

    coordinates[2].rowNum = 1;
    coordinates[2].colNum = 2;
}

void Test_4(Coordinate * & coordinates, unsigned int & activeCells)
{
    activeCells = 6;

    coordinates = new Coordinate[activeCells];

    coordinates[0].rowNum = 1;
    coordinates[0].colNum = 1;

    coordinates[1].rowNum = 1;
    coordinates[1].colNum = 2;

    coordinates[2].rowNum = 1;
    coordinates[2].colNum = 3;

    coordinates[3].rowNum = 2;
    coordinates[3].colNum = 2;

    coordinates[4].rowNum = 2;
    coordinates[4].colNum = 3;

    coordinates[5].rowNum = 2;
    coordinates[5].colNum = 4;
}

/*This function is used to play/test the game
Unit test cases can also be added if CPPUnit/GoogleTest is availble*/
void BuildNPlayGame()
{
    GameRule        rule;
    GameOfLife *    game = GameOfLife::GetInstance(5, 5, &rule);
    Coordinate*     coordinates{ nullptr };
    unsigned int    activeCells{ 0 };
    
    Test_4(coordinates, activeCells);

    game->Initialize(coordinates, activeCells);

    std::cout << "Older Grid: \n";
    game->Print();

    game->Generate();

    std::cout << "Generated Grid: \n";
    game->Print();

    //cleanup
    delete []coordinates;
    delete game;
}


int main()
{
    BuildNPlayGame();
    return 0;
}