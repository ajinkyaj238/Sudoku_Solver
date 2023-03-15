/**************************************************************************
* Project 1 TEAM 2
* author          :Ajinkya Joshi, Anthony Chamoun
* Date            :March 15th, 2023
* File name       :SudokuBoard.cpp
* Purpose         :
 **************************************************************************/

#include "SudokuBoard.h"
#include <fstream>

SudokuBoard::SudokuBoard(int N): boardSize(N)
{

    boardSize = N;

    for(int row = 0; row< boardSize; row++)
        for(int col =0; col < boardSize; col++)
        {

        }

}


void SudokuBoard::clearBoard()
{
    for(int row = 0; row< boardSize; row++)
        for(int col =0; col < boardSize; col++)
            sdkMatrix[row][col] = Blank;
}


void SudokuBoard::initializeBoard(ifstream& fin)
{
    clearBoard();

}

bool SudokuBoard::solveSudoku()
{}

void SudokuBoard::printSudoku()
{}
