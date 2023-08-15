#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include "player.h"
#include <fstream>
#include <iomanip>
using namespace std;
class Game
{
private:

	vector<Player*> players;
	int size;
	string champion;


public:
	Game(vector<Player*>& Arr_player, int& Size, string &Champion);
	Game(ifstream& in);
	void displayLeaderboard();
	void writeLeaderboardToFile();
	void InsertScore();
	void Insertchampion(string& champion1);
	void Save_Game(string& file);
	void SortPlayers();
	~Game();
	
};

