/*	Project:    Rock Paper Scissors Tourny
	Name:       Adam Davis
    Class:      CSC 1810
*/

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	int num_peps;
	cout << "How many Players?: ";
	cin >> num_peps;
	cout << endl;

	int index;
	string UserName;
	vector<string> playersNames(num_peps);
	vector<int> playersNumbers(num_peps, 1);
	int Randomplayer1;
	int Randomplayer2;
	vector<int> Randomizer(num_peps);
	string Player1;
	string Player2;
	int Tie = 0;
	int Score1 = 0;
	int Score2 = 0;
	int Rounds = 0;
	int Randomthrow = 0;

	int roundOn = 1;
	string Winner;
	int Throw_1 = 0;
	int Throw_2 = 0;
	string roundWinner;
	int TournyRounds;
	int tempplayer = 0;
	int tempplayer1 = 0;
	int tempplayer2 = 0;
	int countercurrentround;
	int counternextround;

	int tempgameWinner = -1;
	int gameWinner = -1;

	for (index = 0; index < num_peps; index++)
	{

		cout << "Input Player " << index + 1 << " Name: ";
		cin >> UserName;
		cout << endl;
		playersNames.at(index) = UserName;
	}

	TournyRounds = 1;
	while (gameWinner == -1)
	{
		countercurrentround = 0;
		for (tempplayer = 0; tempplayer < num_peps; tempplayer++)
		{

			if (playersNumbers.at(tempplayer) == TournyRounds)
			{
				countercurrentround = countercurrentround + 1;
			}
		}

		if (countercurrentround < 2)
		{
			TournyRounds = TournyRounds + 1;
			counternextround = 0;
			for (tempplayer = 0; tempplayer < num_peps; tempplayer++)
			{
				if (playersNumbers.at(tempplayer) == TournyRounds)
				{
					counternextround = counternextround + 1;
					tempgameWinner = tempplayer;
				}
			}
			if (countercurrentround == 1 && counternextround > 0)
			{
				countercurrentround = 0;
				for (tempplayer = 0; tempplayer < num_peps; tempplayer++)
				{

					if (playersNumbers.at(tempplayer) == TournyRounds - 1)
					{
						playersNumbers.at(tempplayer) = playersNumbers.at(tempplayer) + 1;
						counternextround = counternextround + 1;
					}
				}
			}

			if (counternextround < 2)
			{
				gameWinner = tempgameWinner;
				cout << "You win. " << playersNames.at(gameWinner) << endl;
			}
		}
		cout << "Tournament Round " << TournyRounds << endl;
		if (gameWinner == -1)
		{
			Randomplayer1 = -1;
			Randomplayer2 = -1;

			while (Randomplayer1 == -1)
			{

				tempplayer1 = (rand() % (num_peps));
				if (playersNumbers.at(tempplayer1) == (TournyRounds))
				{
					Randomplayer1 = tempplayer1;
				}
			}
			while (Randomplayer2 == -1)
			{

				tempplayer2 = (rand() % (num_peps));
				if (playersNumbers.at(tempplayer2) == TournyRounds && tempplayer2 != (Randomplayer1))
				{
					Randomplayer2 = tempplayer2;
				}
			}
			Score1 = 0;
			Score2 = 0;
			Tie = 0;
			for (Rounds = 3; Rounds > 0; Rounds--)
			{
				Player1 = playersNames.at(Randomplayer1);
				Player2 = playersNames.at(Randomplayer2);
				roundOn = roundOn + 1;

				Randomthrow = (rand() % 3) + 1;

				if (Randomthrow == 1)
				{
					cout << Player1 << " - "
						 << "Rock" << endl;
					Throw_1 = 1;
				}
				else if (Randomthrow == 2)
				{
					cout << Player1 << " - "
						 << "Paper" << endl;
					Throw_1 = 2;
				}
				else
				{
					cout << Player1 << " - "
						 << "Scissors" << endl;
					Throw_1 = 3;
				}

				Randomthrow = (rand() % 3) + 1;

				if (Randomthrow == 1)
				{
					cout << Player2 << " - "
						 << "Rock" << endl;
					Throw_2 = 1;
				}
				else if (Randomthrow == 2)
				{
					cout << Player2 << " - "
						 << "Paper" << endl;
					Throw_2 = 2;
				}
				else
				{
					cout << Player2 << " - "
						 << "Scissors" << endl;
					Throw_2 = 3;
				}

				if ((Throw_1 == 1) && (Throw_2 == 3))
				{
					roundWinner = Player1;
					Score1 = Score1 + 1;
				}
				else if ((Throw_1 == 2 && Throw_2 == 3))
				{
					roundWinner = Player2;
					Score2 = Score2 + 1;
				}
				else if ((Throw_1 == 3) && (Throw_2 == 3))
				{
					roundWinner = Tie;
					Tie = Tie + 1;
				}
				else if ((Throw_1 == 1) && (Throw_2 == 2))
				{
					roundWinner = Player1;
					Score1 = Score1 + 1;
				}
				else if ((Throw_1 == 2) && (Throw_2 == 2))
				{
					roundWinner = Tie;
					Tie = Tie + 1;
				}
				else if ((Throw_1 == 3) && (Throw_2 == 2))
				{
					roundWinner = Player2;
					Score2 = Score2 + 1;
				}
				else if ((Throw_1 == 1) && (Throw_2 == 1))
				{
					roundWinner = Tie;
					Tie = Tie + 1;
				}
				else if ((Throw_1 == 2) && (Throw_2 == 1))
				{
					roundWinner = Player1;
					Score1 = Score1 + 1;
				}
				else if ((Throw_1 == 3) && (Throw_2 == 1))
				{
					roundWinner = Player2;
					Score2 = Score2 + 1;
				}
				cout << "Round Winner: " << roundWinner << endl;
			}
			cout << "Player one Score: " << Score1 << endl;
			cout << "Player two Score: " << Score2 << endl;
			cout << "Number of Ties: " << Tie << endl;
			if (Score1 > Score2)
			{
				playersNumbers.at(Randomplayer1) = playersNumbers.at(Randomplayer1) + 1;
				playersNumbers.at(Randomplayer2) = playersNumbers.at(Randomplayer2) - 1;
			}
			else if (Score2 > Score1)
			{

				playersNumbers.at(Randomplayer2) = playersNumbers.at(Randomplayer2) + 1;
				playersNumbers.at(Randomplayer1) = playersNumbers.at(Randomplayer1) - 1;
			}
		}
	}

	{

		cin.clear();
		cin.ignore(1000, '\n');
		char c;
		cout << "Hit enter to exit:";
		cin.get(c);
	}
	return 0;
}
