#include "player.h"
//constructor
Player::Player(string& playerName, string& Champ) :playerName(playerName), Champ(Champ)
{
	
	Number_of_points = 0;
	betsOnWinningTeam = 0;
	accurateResults = 0;
	wrongBets = 0;
}
Player::Player(string& playerName, int& Number_of_points, string& Champ, int& betsOnWinningTeam, int& accurateResults, int& wrongBets) :playerName(playerName),
Number_of_points(Number_of_points), Champ(Champ), betsOnWinningTeam(betsOnWinningTeam), accurateResults(accurateResults), wrongBets(wrongBets) {
}

void Player::placeBets(vector<int>& home, vector<int>& away)
{
	int size = home.size();
	int H, A,Undo=0;
	bool undo = true; 

	//bet =0 its home win , bet =1 its duce , bet =2 it away win
	int bet,real;
	for (int i = 0; i < size; i++)
	{
		while (undo)
		{
			cout << "Bet for game " << i + 1 << ": "<<endl;
			cin >> H >> A;

			cout << "You bet: Home " << H << " - Away " << A << endl;

			cout << "Enter 'U' to undo or 'C' to continue: ";
			char command;
			cin >> command;

			// Convert the character to uppercase to ensure case-insensitivity
			command = toupper(command);

			switch (command)
			{
			case 'U':
				undo = true;
				cout << "Undoing your bet. Please enter again." << endl;
				break;
			case 'C':
				undo = false;
				break;
			default:
				cout << "Invalid command! Please enter again." << endl;
				undo = true;
				break;
			}
		}
		undo = true;

		


		if (H > A)
			bet = 0;
		else
			if (H < A)
				bet = 2;
			else
				bet = 1;

		

		if (home[i] > away[i])
			real = 0;
		else
			if (home[i] < away[i])
				real = 2;
			else
				real = 1;
		

		if (real == bet)
		{
			if (home[i] == H && away[i] == A)
			{
				accurateResults++;
				Number_of_points += 3;
			}
			else
			{
				betsOnWinningTeam++;
				Number_of_points += 1;
			}

		}
		else
			wrongBets++;


	}

}
void Player::CheckChamp(string& real)
{
	if (real == this->Champ)
		Number_of_points += 10;
}

//print
void Player::print()
{
	cout << this->playerName << " bets On Winning Team : " << this->GetbetsOnWinningTeam() << " accurate Results" << this->GetaccurateResults() << " wrong Bets" << this->GetwrongBets() << " Total : " <<this->getNumberOfPoints() << endl;

}

// gets
const string Player::GetName() const
{
	return playerName;
}
const int Player::getNumberOfPoints() const
{
	return Number_of_points;
}
const int Player::GetbetsOnWinningTeam() const
{
	return this-> betsOnWinningTeam;
}
const int Player::GetaccurateResults() const
{
	return accurateResults;
}
const int Player::GetwrongBets() const
{
	return wrongBets;
}
const string Player::GetChamp() const
{
	return this->Champ;
}

//operators
ostream& operator<<(ostream& os, const Player& p)
{
	os << p.GetName() << " "
		<< p.getNumberOfPoints() << " "
		<< p.GetChamp() << " "
		<< p.GetaccurateResults() << " "
		<< p.GetbetsOnWinningTeam() << " "
		<< p.GetwrongBets();
	return os;
}
istream& operator>>(istream& is, Player& p)
{
	string name, champ;
	int total, betsonwinning, accurate, wrong;

	is >> name >> total >> champ >> betsonwinning >> accurate >> wrong;

	p = Player(name, total, champ, betsonwinning, accurate, wrong);
	return is;
}

