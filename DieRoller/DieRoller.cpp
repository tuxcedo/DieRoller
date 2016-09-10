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
	int ChooseGameType;
	bool ExitBool = false;
	string YesNO;

	cout << "Pick '1' for Random number or pick '2' for guess the number\n";
	cout << "Or press 3 to quite\n";
	do
	{
		cout << "Choose game mode 1 or 2 ";
		cin >> ChooseGameType;

		if (ChooseGameType == 1) { RandomNumber(); }
		else if (ChooseGameType == 2) { PickANumber(); }
		else if (ChooseGameType == 3) 
		{
			cout << "Are you sure you want to exit Y/N?  ";
			cin >> YesNO;
			if (YesNO == "Y" || YesNO == "y")
				ExitBool = true;
		}

	} while (ExitBool != true);
	
	cout << "Now Exiting\n";
	
    return 0;
}

void RandomNumber() 
{
	const int ArrayLenght = 5;
	srand(static_cast<unsigned int>(time(0))); //seed random number generator
											   //int randomNumber = rand(); //generate random number
	int RandomArray[ArrayLenght];


	bool CheckBool = false;
	int randomNumber = rand() % ArrayLenght; //generate random number
	for (int i = 0; i < ArrayLenght; i++)
	{

		CheckBool = true;
		do
		{
			for (int j = 0; (CheckBool) && j < i; j++) {
				CheckBool = (RandomArray[i] != RandomArray[j]);
			}
		} while (CheckBool == false);
		cout << RandomArray[i] << endl;
	}

	

}


void PickANumber()
{
	srand(static_cast<unsigned int>(time(0)));
	int randomNumber = rand();
	double RandomDice = (randomNumber % 10) + 1;
	double DieNumber = 0;
	double PlayerGuesses = 0;
	double Winnings = 0;
	double Total = 0;

	cout << "Guess the random number: ";
	cin >> DieNumber;
	do
	{
		if (RandomDice > DieNumber)
		cout << "The number is too low try again ";
		else if(RandomDice < DieNumber)
		cout << "the number is to high try again ";

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

	
}