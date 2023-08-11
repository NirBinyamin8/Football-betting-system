
#include "player.h"
#include "Game.h"
string file = "Ligat hal";
void FreeMem(Game* game)
{
	delete game;
}
Game* Create_A_New_Game()
{
	string name;
	string champ;
	string champion;
	int size;
	cout << "Enter number of players" << endl;
	cin >> size;
	vector<Player*> arr;
	arr.resize(size);

	for (int i = 0; i < size; i++)
	{
		cin.ignore();
		cout << "Enter Name" << endl;
		getline(cin,name);
		cout << "Enter Champion Team" << endl;
		getline(cin, champ);
		arr[i] = new Player(name, champ);

	}
	Game* game = new Game(arr,size, champion);
	return game;
}
void Print_Menu(Game* game)
{
	int chose;
	bool exit = false;
	string champion;

	while (!exit)
	{
		cout << "*************************" << endl;
		cout << "Press 1 for insert the results and bets" << endl;
		cout << "Press 2 display the table" << endl;
		cout << "Press 3 for insert the true champion team" << endl;
		cout << "Press 4 for exit" << endl;
		cin >> chose;

		switch (chose)
		{
		case 1:
			game->InsertScore();
			break;
		case 2:
			game->displayLeaderboard();
			break;
		case 3:
			cout << "Insert champion" << endl;
			cin >> champion;
			game->Insertchampion(champion);
			break;
		case 4:
			game->Save_Game(file);
			exit = true;
			break;
		default:
			cout << "Invalid choise ! Try again" << endl;
			break;
		}

	}
	



}
Game* Reload_Game()
{
	ifstream infile("Ligat hal");
	Game* loadedGame=new Game(infile);
	infile.close();

	return loadedGame;

}
void Save(Game* game)
{
	game->Save_Game(file);
}

void main()
{
	int chose;
	Game* game;

	cout << "Press 1 for new game" << endl << "Press 2 for reload game" << endl;
	cin >> chose;
	if (chose == 1)
		game=Create_A_New_Game();
	else
		game=Reload_Game();

	Print_Menu(game);
	Save(game);
	FreeMem(game);
}