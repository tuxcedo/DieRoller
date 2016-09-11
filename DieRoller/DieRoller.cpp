// DieRoller.cpp : main project file.

#include "stdafx.h"
#include "iostream"
#include "cstdlib"
#include "ctime"
#include "vector"
#include "string"

using namespace System;
using std::cout;
using std::cin;
using std::endl;
using std::string;

void RandomNumber();
void PickANumber();

int main(array<System::String ^> ^args)
{
	bool ExitBool = false;


	cout << "Pick '1' for Random number or pick '2' for guess the number\n";
	cout << "Or press 3 to quite\n";
	do
	{
		int ChooseGameType;
		string YesNO;

		cout << "Choose game mode 1 or 2\n";
		cin >> ChooseGameType;

		if (ChooseGameType == 1) { RandomNumber(); }
		else if (ChooseGameType == 2) { PickANumber(); }
		else if (ChooseGameType == 3) 
		{
			cout << "Are you sure you want to exit Y/N?\n";
			cin >> YesNO;
			if (YesNO == "Y" || YesNO == "y")
				ExitBool = true;
		}
		
	} while (ExitBool != true);
	
	cout << "Now Exiting\n";
	
    return 0;
}

int randrange(int low, int high)   /* generates a random number within given range*/
{
	return rand() % (low + high) + low + 1;
}

void RandomNumber() 
{
	bool CheckBool = false;
	string YesNO;
	const int ArrayLenght = 5;
	do
	{

		srand(static_cast<unsigned int>(time(0))); //seed random number generator
		int RandomArray[ArrayLenght];
		//int randomNumber = rand() % (1 + 10); //generate random number

		for (int i = 0; i < ArrayLenght; i++)
		{

			CheckBool = true;
			do
			{
				RandomArray[i] = randrange(1, 10);

				for (int j = 0; (CheckBool) && j < i; j++) {
					CheckBool = (RandomArray[i] != RandomArray[j] && RandomArray[i] != 0);
				}
			} while (CheckBool == false);
			cout << RandomArray[i] << endl;
			
		}

		cout << "Run Again Y/N?\n";
		cin >> YesNO;
		if (YesNO == "Y" || YesNO == "y")
			continue;
		else
			return;
	} while (CheckBool == false);

}


void PickANumber()
{
	
	string YesNO;
	do
	{
		srand(static_cast<unsigned int>(time(0)));
		int randomNumber = rand();
		double RandomDice = (randomNumber % 10) + 1;
		double DieNumber = 0;
		double PlayerGuesses = 0;
		double Winnings = 0;
		double Total = 0;
		

		cout << "Guess the random number:\n";
		cin >> DieNumber;
		do
		{
			if (RandomDice > DieNumber)
				cout << DieNumber <<" is too low try again ";
			else if (RandomDice < DieNumber)
				cout << DieNumber <<" is to high try again ";

			cin >> DieNumber;
			PlayerGuesses++;

			if (PlayerGuesses > 5)
			{
				cout << "You failed you Loser!\n";
				break;
			}


		} while (RandomDice != DieNumber);



		if (PlayerGuesses == 1)
			Winnings = RandomDice * 5.5;
		else if (PlayerGuesses == 2)
			Winnings = RandomDice *4.4;
		else if (PlayerGuesses == 3)
			Winnings = RandomDice * 3.3;
		else if (PlayerGuesses == 4)
			Winnings = RandomDice * 2.2;
		else if (PlayerGuesses == 5)
			Winnings = RandomDice * 1.1;

		if (RandomDice == DieNumber)
		{
			cout << "You guessed correctly! The number is " << RandomDice << " congradulations!\n";
			cout << "It took you " << PlayerGuesses << " tries to get the right answer!\n";
			cout << "You Won: " << Winnings << " points YAY!\n";
		}

	
		cout << "Play Again?\n";
		cin >> YesNO;
		if (YesNO == "Y" || YesNO == "y")
			continue;
		else
			return;

	} while (YesNO != "N" || YesNO != "n");
	

}