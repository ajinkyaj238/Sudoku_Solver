//
// Created by Ajinkya Joshi on 3/15/23.
//

#ifndef SUDOKUBOARD_H
#define SUDOKUBOARD_H
#include <iostream>
#include <vector>
using namespace std;

class SudokuBoard
{
private:
    int boardSize;              // Size of the sudoku board
    int matrix<int> sdkMatrix;  // Sudoku matrix

public:
    SudokuBoard(int N = 9);     // Constructor
    void clearBoard();
    void initializeBoard(ifstream& fin);
    bool solveSudoku();
    void printSudoku();
};

#endif
