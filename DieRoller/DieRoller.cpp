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
	int guessDie = 0;
	int guesses = 0;

	cout << "Guess the random number: ";
	cin >> guessDie;
		do
		{
				if (die > guessDie)
					cout << "The number is too low try again ";
				else if(die < guessDie)
					cout << "the number is to high try again ";
			
				cin >> guessDie;
				guesses++;

				if (guesses == 5) 
				{
					cout << "You failed you Loser!\n";
						break;
				}
					

		} while (die != guessDie);
		
		if (die == guessDie)
		{
			cout << "You guessed correctly! The number is " << die << " congradulations!\n";
			cout << "It took you " << guesses << " tries to find the right answer!\n";

		}
			


    return 0;
}
