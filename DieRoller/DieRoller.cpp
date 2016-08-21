// DieRoller.cpp : main project file.

#include "stdafx.h"
#include "iostream"
#include "cstdlib"
#include "ctime"

using namespace System;
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(array<System::String ^> ^args)
{
	srand(static_cast<unsigned int>(time(0))); //seed random number generator
	int randomNumber = rand(); //generate random number
	int die = (randomNumber % 10) + 1;
	int DieNumber = 0;
	int PlayerGuesses = 0;

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

		int Winnings = 0;
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
			


    return 0;
}
