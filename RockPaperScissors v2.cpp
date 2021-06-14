// RockPaperScissors.cpp
// v.2

#include <iostream>
#include <Windows.h>
#include <string>
#include <random>

enum RPS
{
	ROCK = 0,
	PAPER,
	SCISSORS
};

class Player
{
public:

	void ScoreUp() { this->score += 1; }

	std::string& SetName() { return name; }
	std::string GetName() { return name; }
	int GetScore() { return score; }

	~Player() {}

private:
	std::string name;
	int score = 0;
};

void GamePVP()
{
	Player a, b;
	bool game = true; std::string gs1, gs2, g; char sp1, sp2;
	std::cout << "Enter player1 name:\n> ";
	std::cin >> a.SetName();
	std::cout << "Enter player2 name:\n> ";
	std::cin >> b.SetName();
	system("cls");

	do
	{
		std::cout << "Game account: "
			<< a.GetName() << " - " << a.GetScore() << " : "
			<< b.GetName() << " - " << b.GetScore() << std::endl;

		std::cout << "Enter " << a.GetName() <<  ", step:\n> ";
		std::cin >> gs1; sp1 = std::tolower(gs1[0]);
		std::cout << "Enter " << b.GetName() << ", step:\n> ";
		std::cin >> gs2; sp2 = std::tolower(gs2[0]);

		if (sp1 == sp2)
		{
			std::cout << "Draw =(\n";
			std::cout << "Do you want to go out?\n> ";
			std::cin >> g;
			if (std::tolower(g[0]) == 'y') game = false;
		}
		else if (sp1 == 'r' && sp2 == 's' || sp1 == 'p' && sp2 == 'r' || sp1 == 's' && sp2 == 'p')
		{
			std::cout << a.GetName() << " won =)\n"; a.ScoreUp();
			std::cout << "Do you want to go out?\n> ";
			std::cin >> g;
			if (std::tolower(g[0]) == 'y') game = false;
		}
		else if (sp2 == 'r' && sp1 == 's' || sp2 == 'p' && sp1 == 'r' || sp2 == 's' && sp1 == 'p')
		{
			std::cout << b.GetName() << " won =)\n"; b.ScoreUp();
			std::cout << "Do you want to go out?\n> ";
			std::cin >> g;
			if (std::tolower(g[0]) == 'y') game = false;
		}
		else
		{
			std::cout << "\nWhat???\n";
			Sleep(1000);
			std::cout << "Do you want to go out?\n> ";
			std::cin >> g;
			if (std::tolower(g[0]) == 'y') game = false;
		}
			
		system("cls");
	} while (game != false);
}

void GamePVE()
{
	bool game = true; std::string gs, g; char sp, bs; int pscr = 0, bscr = 0;
	do
	{
		srand(time(NULL));
		int bot_step = 0 + rand() % 2;
		if (bot_step == RPS::PAPER) bs = 'p';
		else if (bot_step == RPS::SCISSORS) bs = 's';
		else if (bot_step == RPS::ROCK) bs = 'r';

		std::cout << "Game account: "
			<< "Player" << " - " << pscr << " : "
			<< "Bot" << " - " << bscr << std::endl;

		std::cout << "Enter, step:\n> ";
		std::cin >> gs; sp = std::tolower(gs[0]);

		if (sp == bs)
		{
			std::cout << "Draw =(\n";
			std::cout << "Do you want to go out?\n> ";
			std::cin >> g;
			if (std::tolower(g[0]) == 'y') game = false;
		}
		else if (sp == 'r' && bs == 's' || sp == 'p' && bs == 'r' || sp == 's' && bs == 'p')
		{
			std::cout << "You won =)\n"; pscr++;
			std::cout << "Do you want to go out?\n> ";
			std::cin >> g;
			if (std::tolower(g[0]) == 'y') game = false;
		}
		else if (bs == 'r' && sp == 's' || bs == 'p' && sp == 'r' || bs == 's' && sp == 'p')
		{
			std::cout << "Bot won =)\n"; bscr++;
			std::cout << "Do you want to go out?\n> ";
			std::cin >> g;
			if (std::tolower(g[0]) == 'y') game = false;
		}
		else
		{
			std::cout << "\nWhat???\n";
			Sleep(1000);
			std::cout << "Do you want to go out?\n> ";
			std::cin >> g;
			if (std::tolower(g[0]) == 'y') game = false;
		}

		system("cls");
	} while (game != false);
}

char SetMode()
{
	char mode;
	std::cout << "Hello!\n\n"
		<< "Select a game mode:\n\n"
		<< "1)Game 1 vs 1\n"
		<< "2)Playing against a bot\n"
		<< "3)Instructions\n"
		<< "4)Exit\n"
		<< "\n> ";
	std::cin >> mode;
	system("cls");
	return mode;
}

void Inst()
{
	system("cls");
	std::cout << "Rule game:\n\n"
		<< "> Paper beats stone (\"paper wraps around stone\").\n"
		<< "> The stone beats the scissors(\"the stone blunts or breaks the scissors\")\n"
		<< "> Scissors beat paper(\"scissors cut paper\").\n";
	std::cout << "\nHow to play:\n\n"
		<< "> Enter your choice during your turn\n ( Paper(P/p), Rock(R/r), Scissors(S/s) )\n";
	std::cout << "\nDo something to get out!\n";
	system("pause>nul");
	system("cls");
}

int main()
{
	bool gameset = true;

	while (gameset)
	{
		char m = SetMode();
		switch (m)
		{
		case '1':
			GamePVP();
			break;
		case '2':
			GamePVE();
			break;
		case '3':
			Inst();
			break;
		case '4':
			std::cout << "\nGoodbye\n";
			Sleep(1000);
			std::cout << "\nDo something to get out!\n";
			system("pause>nul");
			gameset = false;
			break;
		default:
			std::cout << "\nWhat??\n";
			Sleep(1000);
			system("cls");
			break;
		}
	}
	system("pause>nul");
}

