#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
class Player {
private:
	string playerName;
	int Number_of_points=0;
	string Champ;
	int betsOnWinningTeam =0;
	int accurateResults =0;
	int wrongBets =0;
public:
	Player(string playerName, string Champ);
	Player(string playerName, int Number_of_points, string Champ, int betsOnWinningTeam , int accurateResults, int wrongBets);
	void placeBets(vector<int>& home, vector<int>& away);
	void CheckChamp(string& real);
	void print();
	//gets
	const string GetName() const;
	const int getNumberOfPoints() const;
	const int GetbetsOnWinningTeam() const;
	const int GetaccurateResults() const;
	const int GetwrongBets() const;
	const string GetChamp()const;
	

	friend ostream& operator<<(ostream& os, const Player& p);




};


