// C++ program to play Tic-Tac-Toe
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void displayBoard(const vector<vector<char>> &board)
{
	for (const auto &row : board)
	{
		for (char cell : row)
		{
			cout << cell << ' ';
		}
		cout << endl;
	}
} // end of displayBoard.

//code for checking games result.
bool checkWin(const vector<vector<char>> &board, char player)
{
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
		{
			return true;
		}
		if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
		{
			return true;
		}
	}
	if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
	{
		return true;
	}
	if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
	{
		return true;
	}
	return false;
} // end of checkWin.
int main()
{
	vector<vector<char>> board(3, vector<char>(3, ' '));
	char currentPlayer = 'X';
	int moves = 0;
	cout << "Welcome to Tic-Tac-Toe!\n";
	do
	{    
		//code for display the output.

		displayBoard(board);
		int row, col;   //enter row column array format.
		cout << "player" << currentPlayer << ",enter your move (row and column): ";
		cin >> row >> col;
		if (board[row][col] == ' ')
		{
			board[row][col] = currentPlayer;
			moves++;
			if (checkWin(board, currentPlayer))
			{
				displayBoard(board);
				cout << "player" << currentPlayer << " won!\n";
				break;
			}
			if (moves == 9)
			{
				displayBoard(board);
				cout << "It's a draw!\n";
				break;
			}
			currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
		}
		else
		{     //if a cell alredy occupied and user enter same cell input then error occured.
			cout << "That cell is already occupied. Try again.\n";
		}
	} while (1);
	{
		cout << "Would you want to play another game?\n";
		return 0;
	}
} // end of main.
