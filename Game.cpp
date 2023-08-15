#include "Game.h"
//constructor
Game::Game(vector<Player*>& Arr_player, int& Size,string &Champion)
{
	this->champion = Champion;
	this->players =Arr_player ;
	this->size = Size;
}
Game::Game(ifstream& in)
{
	string name;
	string champ;
	int betsonwinnig;
	int accurate;
	int wrong;
	int total;

	in >> size;
	this->players.resize(size);

	for (int i = 0; i < size; i++)
	{
		in >> name
			>> total
			>> champ
			>> betsonwinnig
			>> accurate
			>> wrong;

		players[i] = new Player(name, total, champ, betsonwinnig, accurate, wrong);
	}
}
//distructor
Game::~Game()
{
	for (int i = 0; i < size; i++)
	{
		delete players[i];
	}
	

	
}


void Game::InsertScore()
{
	int games;
	vector <int> h, a;
	cout << "Enter the number of games " << endl;
	cin >> games;
	h.resize(games);
	a.resize(games);

	for (int i = 0; i < games; i++)
	{
		cout << "Enter score for " << i + 1 << " Game " <<"Home - Away "<< endl;
		cin >> h[i] >> a[i];
	}
	cout << " Now , Place your bets " << endl;

	for (int i = 0; i < size; i++)
	{
		cout << "***********" << endl;
		cout << players[i]->GetName()<<"'s ";
		players[i]->placeBets(h, a);
	}

	SortPlayers();
}

void Game::displayLeaderboard()
{
	cout << "-------------------------------------------------------" << endl;
	cout << "| Rank |      Name      |  Points |  Wins  | BullEye's | Wrongs |" << endl;
	cout << "-------------------------------------------------------" << endl;

	for (int i = 0; i < size; i++)
	{
		cout << "| " << setw(4) << i + 1 << " |";
		cout << setw(15) << players[i]->GetName() << " |";
		cout << setw(7) << players[i]->getNumberOfPoints() << " |";
		cout << setw(6) << players[i]->GetbetsOnWinningTeam() << " |";  // Assuming GetbetsOnWinningTeam now returns Wins
		cout << setw(10) << players[i]->GetaccurateResults() << " |";  // Assuming GetaccurateResults now returns BullEye's
		cout << setw(7) << players[i]->GetwrongBets() << " |";  // Assuming GetwrongBets now returns Wrongs
		cout << endl;
	}
	cout << "-------------------------------------------------------" << endl;
}


void Game::writeLeaderboardToFile()
{
	ofstream outFile("Res.txt");  // Open a file named "Res.txt" for writing.

	if (!outFile)  // Check if the file opened successfully.
	{
		cerr << "Failed to open file for writing." << endl;
		return;
	}

	outFile << "-------------------------------------------------------\n";
	outFile << "| Rank |      Name      |  Points |  Wins  | BullEye's | Wrongs |\n";
	outFile << "-------------------------------------------------------\n";

	for (int i = 0; i < size; i++)
	{
		outFile << "| " << setw(4) << i + 1 << " |";
		outFile << setw(15) << players[i]->GetName() << " |";
		outFile << setw(7) << players[i]->getNumberOfPoints() << " |";
		outFile << setw(6) << players[i]->GetbetsOnWinningTeam() << " |";
		outFile << setw(10) << players[i]->GetaccurateResults() << " |";  // Assuming GetaccurateResults now returns BullEye's
		outFile << setw(7) << players[i]->GetwrongBets() << " |";  // Assuming GetwrongBets now returns Wrongs
		outFile << endl;
	}
	outFile << "-------------------------------------------------------\n";

	outFile.close();  // Close the file after writing.
}



void Game::Insertchampion(string& champion1)
{
	this->champion = champion1;
	for (int i = 0; i < size; i++)
	{
		players[i]->CheckChamp(champion1);
	}
	SortPlayers();
}
void Game::SortPlayers() {
	sort(players.begin(), players.end(), [](const Player* p1, const Player* p2) {
		return p1->getNumberOfPoints() > p2->getNumberOfPoints();
		});
}

//Save game to file
void Game::Save_Game(string& file)
{
	ofstream outfile(file, ios::trunc);
	outfile << this->size << endl;
	for (int i = 0; i < size; i++)
	{
		outfile << *(players[i])<<endl;

	}
	outfile.close();
}

