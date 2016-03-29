#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Grid.h"

using namespace std;

class Menu : public Grid
{
public:
	Menu();  // Constructor
	void start(); // Opens the starting menu and allows users to select a gameplay mode
private:
	void singleplayer(); // Starts the routine to play against the computer
	void multiplayer(); // Starts the routine for two players to play against eachother
	//void leaderboard();
	void help();
	int score;
};
