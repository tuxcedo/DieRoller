// DieRoller.cpp : main project file.

#include "stdafx.h"
#include "iostream"
#include "cstdlib"
#include "ctime"
#include "vector"


using namespace System;
using std::cout;
using std::cin;
using std::endl;
using std::string;

void RandomNumber();
void PickANumber();

int main(array<System::String ^> ^args)
{
	int choice;

	cout << "Choose game mode 1 or 2 ";
		cin >> choice;

		if (choice == 1) { RandomNumber(); }
		else if (choice == 2) { PickANumber(); }
	


    return 0;
}

void RandomNumber() 
{
	const int ArrayLenght = 5;
	srand(static_cast<unsigned int>(time(0))); //seed random number generator
											   //int randomNumber = rand(); //generate random number
	int RandomArray[ArrayLenght];


	bool check = false;
	int randomNumber = rand() % ArrayLenght; //generate random number
	for (int i = 0; i < ArrayLenght; i++)
	{

		check = true;
		do
		{
			for (int j = 0; (check) && j < i; j++) {
				check = (RandomArray[i] != RandomArray[j]);
			}
		} while (check == false);
		cout << RandomArray[i] << endl;
	}

	

}


void PickANumber()
{
	srand(static_cast<unsigned int>(time(0)));
	int randomNumber = rand();
	double die = (randomNumber % 10) + 1;
	double DieNumber = 0;
	double PlayerGuesses = 0;
	double Winnings = 0;
	

	cout << "Guess the random number: ";
	cin >> DieNumber;
	do
	{
		if (die > DieNumber)
		cout << "The number is too low try again ";
		else if(die < DieNumber)
		cout << "the number is to high try again ";

		cin >> DieNumber;
		PlayerGuesses++;

		if (PlayerGuesses > 5)
		{
			cout << "You failed you Loser!\n";
			break;
		}


	} while (die != DieNumber);

	

	if (PlayerGuesses == 1)
	Winnings = die * 5.5;
	else if (PlayerGuesses == 2)
	Winnings = die *4.4;
	else if (PlayerGuesses == 3)
	Winnings = die * 3.3;
	else if (PlayerGuesses == 4)
	Winnings = die * 2.2;
	else if (PlayerGuesses == 5)
	Winnings = die * 1.1;

	if (die == DieNumber)
	{
		cout << "You guessed correctly! The number is " << die << " congradulations!\n";
		cout << "It took you " << PlayerGuesses << " tries to get the right answer!\n";
		cout << "You Won: " << Winnings << " YAY!\n";
	}

	//return die, PlayerGuesses, Winnings;
}