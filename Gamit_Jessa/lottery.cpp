#include <iostream>	
#include <cstdlib>	
#include <ctime>

const int lotteryDigits = 70;
const int SIZE = 6;

int generateLottery(int[], int, int);
int userInput(int[], int);
int matchCounter(int[], int[], int);
void displayNumbers(int[], int[]);
void winnerOrLoser(int);

using namespace std;

int main()
{
	
	int lottery[6] = {0, 0, 0, 0, 0, 0};
	int user[6] = {0, 0, 0, 0, 0, 0};
	int matches = 0;

	
	generateLottery(lottery, SIZE, lotteryDigits);

	userInput(user, SIZE);

	matchCounter(lottery, user, matches);

	displayNumbers(lottery, user);

	winnerOrLoser(matches);

	system("pause");
	return 0;
}

int generateLottery(int lottery[], int, int)
{
	unsigned seed = time(0);
	srand(seed);

	for (int y=0; y<SIZE; y++)
	{
		lottery[y] = rand() % lotteryDigits;
	}
	
	return lottery[0], lottery[1], lottery[2], lottery[3], lottery[4], lottery[5];
}

int userInput(int user[], int)
{	

	for (int y=0; y<SIZE; y++)
	{
		cout << "Enter your number between 0 and 70: ";
		cin >> user[y];

		while (user[y]<0 || user[y]>70)
		{
		cout << "Error! Entry must be between 0 and 70:";
		cin >> user[y];
		}
	}

	return user[0], user[1], user[2], user[3], user[4], user[5];
}

int matchCounter(int lotto[], int input[], int)
{
	int match = 0;

	for (int x = 0; x < SIZE; ++x)
	{
		if (lotto[x] == input[x])
			match = match + 1;
	}

	return match;
}

void displayNumbers(int lottery[], int user[])
{
	cout << "\nThe winning lottery numbers are: " << lottery[0] << " " << lottery[1] << " " << lottery[2] << " " << lottery[3] << " " << lottery[4] << " " << lottery[5] << endl;
	cout << "Your lottery numbers are: " << user[0] << " " << user[1] << " " << user[2] << " " << user[3] << " " << user[4] << " " << user[5] << endl;
}

void winnerOrLoser(int matches)
{
	cout << "You matched " << matches << " numbers";

	if (matches != SIZE)
		cout << "\nSorry--YOU LOSE! BETTER LUCK NEXT TIME!.\n";
	else
		cout << "\nCongratulations--you WIN!!!!\n";
		
}

