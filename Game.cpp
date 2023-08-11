#include "Game.h"
Game::Game(vector<Player*> Arr_player, int Size,string Champion)
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
	// Display table header
	cout << "----------------------------------------" << endl;
	cout << "Rank | Player Name     | Points | Bets  | Accurate | Wrong" << endl;
	cout << "----------------------------------------" << endl;

	for (int i = 0; i < size; i++)
	{
		cout << setw(4) << i + 1 << " | "
			<< setw(15) << left << players[i]->GetName() << " | "
			<< setw(6) << right << players[i]->getNumberOfPoints() << " | "
			<< setw(5) << right << players[i]->GetbetsOnWinningTeam() << " | "
			<< setw(8) << right << players[i]->GetaccurateResults() << " | "
			<< setw(5) << right << players[i]->GetwrongBets()
			<< endl;
	}

	cout << "----------------------------------------" << endl;
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
void Game::SortPlayers() {
	sort(players.begin(), players.end(), [](const Player* p1, const Player* p2) {
		return p1->getNumberOfPoints() > p2->getNumberOfPoints();
		});
}
