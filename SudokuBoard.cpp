/**************************************************************************
* Project 1 TEAM 2
* author          :Ajinkya Joshi, Anthony Chamoun
* Date : March 15, 2023
* File name : SodukoBoard.cpp - Solve Sudoku Puzzles using
* : recursive algorithms
* Purpose : Reads in a puzzle of more from a files and solves them
* Usage : g++ SudokuBoard.cpp -o output
* : ./output (No Makefile required)
****************************************************************************/

#include "SudokuBoard.h"
#include <fstream>

using namespace std;

SudokuBoard::SudokuBoard(int N) : boardSize(N)
{
	// Resize conflict matricies
	sdkMatrix.resize(N, N);
	c_rows.resize(N, N);
	c_cols.resize(N, N);
	c_sqs.resize(N, N);
	clearBoard();

}


void SudokuBoard::clearBoard()
{
	// clears conflict matricies
	count = 0;
	for (int row = 0; row < boardSize; row++)
		for (int col = 0; col < boardSize; col++) {
			sdkMatrix[row][col] = Blank;
			c_rows[row][col] = Blank;
			c_cols[row][col] = Blank;
			c_sqs[row][col] = Blank;
		}
}


void SudokuBoard::initializeBoard(ifstream& fin)
{
	int digit;
	char ch; // holds each value read from file
	clearBoard(); // clear the board first
	for (int i = 0; i < boardSize; i++)
	{
		for (int j = 0; j < boardSize; j++)
		{
			fin >> ch;
			// If the read char is not Blank
			if (ch != '.') {
				digit = ch - '0';// Convert char to int
				sdkMatrix[i][j] = digit;
			}
		}
	}
}

void SudokuBoard::file(const string& filename) {
	ofstream ofs(filename);
	streambuf* coutbuf = cout.rdbuf();
	cout.rdbuf(ofs.rdbuf());
}

bool SudokuBoard::solveSudoku()
{
	// need to figure out how backtracking works
	count += 1;
	int row = 0, col = 0;
	findEmpty(row, col);
	if (row == boardSize + 1 || col == boardSize + 1) {
		return true;
	}
	else {
		int l = findLocation(row, col);
		for (int i = 0; i < boardSize; i++) {
			if (c_rows[row][i] == 0 && c_cols[col][i] == 0 && c_sqs[l][i] == 0) {
				sdkMatrix[row][col] = i + 1;
				c_rows[row][i] = 1;
				c_cols[col][i] = 1;
				c_sqs[l][i] = 1;
				break;
			}
			else if (c_rows[row][i] == 1 || c_cols[col][i] == 1 || c_sqs[l][i] == 1) {

			}
		}
	}
	if (count == 40) {
		return false;
	}
	solveSudoku();
}


void SudokuBoard::printSudoku()
{
	for (int i = 1; i <= boardSize; i++)
	{
		if ((i - 1) % SquareSize == 0)
		{
			for (int j = 1; j <= boardSize + 1; j++)
				cout << "---";
			cout << endl;
		}
		for (int j = 1; j < boardSize + 1; j++)
		{
			if ((j - 1) % SquareSize == 0)
				cout << "|";
			if (sdkMatrix[i - 1][j - 1] != Blank)
				cout << " " << sdkMatrix[i - 1][j - 1] << " ";
			else
				cout << " - ";
		}
		cout << "|";
		cout << endl;
	}
	cout << " -";
	for (int j = 1; j <= boardSize - 1; j++)
		cout << "---";
	cout << "-";
	cout << endl;
}

void SudokuBoard::findEmpty(int& row, int& col) {
	// need to pass by reference ,, hoping this works ,, it does
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			if (sdkMatrix[i][j] == Blank) {
				row = i;
				col = j;
				i = j = boardSize;
				break;
			}
		}

	}
}



void SudokuBoard::setConflict() {
	// does exactly that
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			if (sdkMatrix[i][j] != 0) {
				int k = sdkMatrix[i][j];
				int a = findLocation(j, i);
				c_rows[j][k - 1] = 1;
				c_cols[i][k - 1] = 1;
				c_sqs[a][k - 1] = 1;
			}
		}
	}
}

void SudokuBoard::printConflict() {
	cout << "square conflicts" << endl;
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			cout << c_sqs[i][j];
		}
		cout << endl;
	}
	cout << "col conflicts" << endl;
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			cout << c_cols[i][j];
		}
		cout << endl;
	}
	cout << "row conflicts" << endl;
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			cout << c_rows[i][j];
		}
		cout << endl;
	}
}

// determines which square
int SudokuBoard::findLocation(int row, int col) {
	if (row + 1 <= boardSize / 3) {
		if (col + 1 <= boardSize / 3) {
			return 0;
		}
		else if (col + 1 <= 2 * (boardSize / 3)) {
			return 3;
		}
		else if (col + 1 <= boardSize) {
			return 6;
		}
	}
	if (row + 1 <= 2 * (boardSize / 3)) {
		if (col + 1 <= boardSize / 3) {
			return 1;
		}
		else if (col + 1 <= 2 * (boardSize / 3)) {
			return 4;
		}
		else if (col + 1 <= boardSize) {
			return 7;
		}
	}
	if (row + 1 <= boardSize) {
		if (col + 1 <= boardSize / 3) {
			return 2;
		}
		else if (col + 1 <= 2 * (boardSize / 3)) {
			return 5;
		}
		else if (col + 1 <= boardSize) {
			return 8;
		}
	}
}
