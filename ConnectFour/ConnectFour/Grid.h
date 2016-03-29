#pragma once
#include <iostream>
#include <ctime>

using namespace std;

class Grid
{
public:
	Grid(); // Constructor
	int playerTurn(char counter); // Allows players to cast their moves, prompts for a column number and checks the input
	bool winCheck(int moves, char counter); // Checks diagonally, horizontally and vertically for any winning chains
	void printGrid(); // Prints the grid in full form the array
	int computerOpponent(); // Returns a generated column for the token to be placed in

protected:
	char gridCounters[6][7]; // Only needs to be accessed by objects within the class
	void clearGrid(); // Shouldn't be accessed outside the class to prevent accidentally clearing the grid mid-game
	bool makeMove(int column, char counter);
};