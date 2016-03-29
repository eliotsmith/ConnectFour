#include "Menu.h"

Menu::Menu()
{

}

void Menu::start() // Main menu of the game which allows different modes to be used.
{
	bool exit = false;
	do {
		cout << "**** CONNECT FOUR GAME **** " << endl; //Listing the menu options for the user to select
		cout << endl;
		cout << "1. Singleplayer" << endl;
		cout << "2. Multiplayer (2 players)" << endl;
		cout << "3. View Leaderboard" << endl;
		cout << "4. Help" << endl;
		cout << endl;
		cout << "5. Exit" << endl;
		cout << endl;
		cout << "Enter an option number: ";

		int optionNumber;
		cin >> optionNumber; //Recieving the input from the user
		cout << endl;

		switch (optionNumber) {
		case 1:  // Singleplayer game
			singleplayer();
			break;
		case 2: // Multiplayer game
			multiplayer();
			break;
		//case 3: // View Leaderboard list
				//Commands to open leaderboard file and print
		//	break;
		//case 4: // List help and rules information
				//Information about the game, help and rules to be printed
		//	break;
		case 5: // Exit game
			exit = true;
			break;

		default: //If no valid option has been entered
			break;
		}
	} while (exit == false);
}

void Menu::singleplayer()
{
	clearGrid(); // Initalising the grid to ensure it is blank.
	printGrid(); // Printing the first grid to give the user an idea of the board.
	int moves = 0;

	bool gameFinished = false;
	string winner;

	do //Looping through player 1 and the computer casting their goes
	{
		playerTurn('X');
		moves++;

		if (winCheck(moves, 'X'))
		{
			gameFinished = true;
			winner = "Player 1";  //If the win check results in a positive, the loop is broken
			break;
		}

		makeMove(computerOpponent(), 'O'); // The computer opponent function returns a generated column to place a token
		moves++;
		printGrid();


		if (winCheck(moves, 'O'))
		{
			gameFinished = true;
			winner = "Computer";  //If the win check results in a positive, the loop is broken
			break;
		}


	} while (gameFinished == false);

	cout << endl;
	if (moves < 42) // Less than 42 moves means that the game did not end with a draw.
	{
		cout << "**************" << endl;
		cout << winner << " has WON the game!" << endl; 
		cout << "**************" << endl;
	}
	else // The game ended with a draw as it was not less than 42 moves.
	{
		cout << "**************" << endl;
		cout << "The grid is full. DRAW!" << endl;
		cout << "**************" << endl;
	}
	cout << endl;
}

void Menu::multiplayer()
{
	clearGrid(); // Initalising the grid
	printGrid(); // Printing the first grid to give the players a visual of the grid
	int moves = 0;

	bool gameFinished = false;
	string winner;

	do // Iterating thorugh player 1 and player 2 casting their goes.
	{
		playerTurn('X');
		moves++;
		
		if (winCheck(moves, 'X'))
		{
			gameFinished = true;
			winner = "Player 1";
			break;
		}
		
		playerTurn('O');
		moves++;


		if (winCheck(moves, 'O'))
		{
			gameFinished = true;
			winner = "Player 2";
			break;
		}
		

	} while (gameFinished == false);

	cout << endl;
	if (moves < 42) // Checking if the win was a draw or not
	{
		cout << "**************" << endl;
		cout << winner << " has WON the game!" << endl; // Print the correct player win message
		cout << "**************" << endl;
	}
	else
	{
		cout << "**************" << endl;
		cout << "The grid is full. DRAW!" << endl;
		cout << "**************" << endl;
	}
	cout << endl;

}

/*void Menu::leaderboard()
{
	string line;

	ifstream leaderFile("leaderboard.txt");
	if (leaderFile.is_open())
	{
		while (leaderFile.good())
		{
			leaderFile >> line;
			cout << line << endl;
		}
		leaderFile.close();
	}
	else
	{
		cout << "ERROR OPENING FILE" << endl;
	}

}*/

void Menu::help()
{
}
