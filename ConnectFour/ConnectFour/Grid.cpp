#include "Grid.h"


Grid::Grid()
{
	
}

int Grid::playerTurn(char counter) // Allowing a player to cast their turn, including validation on user input
{
	int playerColumn;
	int playerCheck = 0;
	
	int player;

	if (counter == 'X') // Converting the player token to a player number
	{
		player = 1;
	}
	else
	{
		 player = 2;
	}
	
	
	do // Reiterating until the player enters a valid input.
	{
		cout << endl;
		cout << "Player "<< player << " select a column: ";
		
		try 
		{
			if (!(cin >> playerColumn))
			{
				//cin.clear();
				//cin.ignore();
				//cout << "ERROR: Enter an integer " << endl;
				throw 10;
			}
		}
		catch (int excpt)
		{
			cout << "ERROR: Only integers may be entered for columns." << endl;   
			// Will end the program if an incorect input is entered. *** Might be worth changing to a char and checking that to account for letters****
		}

		cout << endl;

		if (makeMove(playerColumn, counter)) // If the make move does not return TRUE, then the move was not valid and prompts the player to go again
		{
			playerCheck = 1;
			printGrid(); // If the move was valid, the grid is printed and 1 returned to signify a completed turn.
			return 1;
		}

		cout << "MOVE INVALID: Enter a valid column" << endl;
	} while (playerCheck == 0);

	

}

void Grid::clearGrid()
{
	for (int row = 0; row < 6; row++)
	{
		for (int column = 0; column < 7; column++)         //Iterating through each place on the grid and setting it to the default symbol.
		{
			gridCounters[row][column] = '*';
		}
	}
}

bool Grid::makeMove(int column, char counter)
{
	
	
	column = column - 1; // Changing the inputted column number to be interpretted correctly by the array

	for (int row = 5; row != -1; row--)
	{
		if (gridCounters[row][column] == '*')
		{
			gridCounters[row][column] = counter;
			return true;
		}
	}
	return false;
	/*
	if (gridCounters[5][column] == '*') // Checking the counter positions from the bottom first 
	{									// to see if the counter can be placed there.
		gridCounters[5][column] = counter;
		return true;
	}
	else if (gridCounters[4][column] == '*') //Moving from bottom to top to make sure the counter is at the lowest posible position.
	{
		gridCounters[4][column] = counter;
		return true;
	}
	else if (gridCounters[3][column] == '*')
	{
		gridCounters[3][column] = counter;
		return true;
	}
	else if (gridCounters[2][column] == '*')
	{
		gridCounters[2][column] = counter;
		return true;
	}
	else if (gridCounters[1][column] == '*')
	{
		gridCounters[1][column] = counter;
		return true;
	}
	else if (gridCounters[0][column] == '*')
	{
		gridCounters[0][column] = counter;
		return true;
	}
	else
	{
		// This will only be reached if the column in the grid is completely full, meaning no counters can be placed there.
		return false;
	} */
}

bool Grid::winCheck(int moves, char counter)
{
	const int maxMoves = 42; // Maximum moves possible is always 42 and cannot change.
	
	if (moves <= 3)
	{
		// Winning is not possible without 4 moves having been played. Automatic loss.

		return false;
	}

	for (int count = 0; count <= 3; count++) // There are three possible ways a chain with a length of four could fit into the column. 
	{
		for (int column = 0; column < 7; column++) // Iterating through each column to check it
		{
			if ((gridCounters[count+3][column] == counter) && (gridCounters[count+2][column] == counter) && (gridCounters[count+1][column] == counter) && (gridCounters[count][column] == counter))
			{
				return true;
			}
		}
	}

	/*
	for (int column = 0; column < 7; column++)
	{
		// Column checks for wins
		if ((gridCounters[5][column] == counter) && (gridCounters[4][column] == counter) && (gridCounters[3][column] == counter) && (gridCounters[2][column] == counter))
		{
			return true;
		}
		else if ((gridCounters[4][column] == counter) && (gridCounters[3][column] == counter) && (gridCounters[2][column] == counter) && (gridCounters[1][column] == counter)) // Iterating through columns to check for wins
		{
			return true;
		}
		else if ((gridCounters[3][column] == counter) && (gridCounters[2][column] == counter) && (gridCounters[1][column] == counter) && (gridCounters[0][column] == counter))
		{
			return true; // Only returning true if a winning chain has been found.
		}
	} */


	for (int count = 0; count <= 4; count++) // There are four possible ways a chain with a length of four could fit into the row. 
	{
		for (int row = 0; row < 6; row++) // Iterating through each row to check it
		{
			if ((gridCounters[row][count] == counter) && (gridCounters[row][count+1] == counter) && (gridCounters[row][count+2] == counter) && (gridCounters[row][count+3] == counter))
			{
				return true;
			}
		}
	}


	/*for (int row = 0; row < 6; row++)
	{
		// Row checks for wins
		if ((gridCounters[row][0] == counter) && (gridCounters[row][1] == counter) && (gridCounters[row][2] == counter) && (gridCounters[row][3] == counter))
		{
			return true;
		}
		else if ((gridCounters[row][1] == counter) && (gridCounters[row][2] == counter) && (gridCounters[row][3] == counter) && (gridCounters[row][4] == counter))
		{
			return true;
		}
		else if ((gridCounters[row][2] == counter) && (gridCounters[row][3] == counter) && (gridCounters[row][4] == counter) && (gridCounters[row][5] == counter))  //Iterating through rows to check for wins
		{
			return true;
		}
		else if ((gridCounters[row][3] == counter) && (gridCounters[row][4] == counter) && (gridCounters[row][5] == counter) && (gridCounters[row][6] == counter))
		{
			return true;
		}
	}*/

	// Check diagonals left-to-right and right-to-left


	//Right-to-left Diagonal Check (\)

	for (int row = 0; row <= 2; row++)
	{
		for (int column = 0; column <= 3; column++)
		{
			if ((gridCounters[row][column] == counter) && (gridCounters[row + 1][column + 1] == counter) && (gridCounters[row + 2][column + 2] == counter) && (gridCounters[row + 3][column + 3] == counter))
			{
				return true;
			}
		}
	}

	//Left-to-right Diagonal Check (/)

	for (int row = 0; row <= 2; row++)
	{
		for (int column = 3; column <= 6; column++)
		{
			if ((gridCounters[row][column] == counter) && (gridCounters[row + 1][column - 1] == counter) && (gridCounters[row + 2][column - 2] == counter) && (gridCounters[row + 3][column - 3] == counter))
			{
				return true;
			}
		}
	}



	if (moves == maxMoves) // This is the maximum number if permitted moves. If this is reached there is a draw.
	{
		return 1; 
	}

	return false; // If there are no matches to a winning chain, false will be returned.

}

void Grid::printGrid() // Looping through the grid and printing it
{
	cout << "  1 2 3 4 5 6 7" << endl; // Decorative features
	cout << "|---------------|" << endl;
	for (int row = 0; row <= 5; row++)
	{
		cout << "| ";
		for (int column = 0; column <= 6; column++)  // Printing the grid directly from the storage array. Will include any pieces played in the game.
		{
			cout << gridCounters[row][column] << " ";
		}
		cout << "|" << endl;
	}
	cout << "|---------------|" << endl;
}

int Grid::computerOpponent()
{
	//Checking for any horizontal chains of 3 to block

	const char oppCounter = 'X'; // Player 1 (human player) is always 'X' in single player mode.

	/*for (int count = 0; count <= 5; count++) 
	{
		for (int row = 0; row < 6; row++) // Iterating through each row to check it
		{
			if ((gridCounters[row][count] == oppCounter) && (gridCounters[row][count + 1] == oppCounter) && (gridCounters[row][count + 2] == oppCounter))
			{
				if (count + 2 != 6)
				{
					return count + 3; // Providing that the far right chain block isn't on the edge of the board, return the column next to it, to attempt a block.
				}
				else
				{
					return count - 1; // If the far-right block is on the edge, then the chain will be blocked from the left.
				}
			}
		}
	}

	//Checking for any vertical chains of 3 to block

	for (int count = 0; count <= 5; count++)
	{
		for (int column = 0; column < 7; column++) // Iterating through each row to check it
		{
			if ((gridCounters[count][column] == oppCounter) && (gridCounters[count + 1][column] == oppCounter) && (gridCounters[count + 2][column] == oppCounter))
			{
				if (count != 0)
				{
					return count+1; // Return the column to block the chain from the top. Increments it so that it is compatible with human counting.
				}
				// If the chain is at the top of the board, it cannot be blocked so nothing is returned.
			}
		}
	}
	*/
	// [row][column]

	for (int column = 0; column < 7; column++)
	{
		for (int row = 0; row < 5; row++)
		{
			if ((gridCounters[row][column] == oppCounter) && (gridCounters[row + 1][column] == oppCounter) && (gridCounters[row + 2][column] == oppCounter) && (gridCounters[row + 3][column] != 'O'))
			{
				return column + 1;
			}
		}
	}

	// Geneating a random column to place in if there is no chains to block
	/*srand((unsigned)time(0));
	int random_integer;
	for (int index = 0; index<20; index++) 
	{
		random_integer = (rand() % 7) + 1;
		return random_integer + 1;
	}*/
	
	
	return 7;
}
