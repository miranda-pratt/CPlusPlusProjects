/*
 * Game.cpp
 *
 *  Created on: 2 Oct 2022
 *      Author: Student
 */

#include "Game.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main () {

	// Main game loop
	while (true) {

		// See if the user wants to play or exit
		int user_input;
		cout << "Press 1 to play or 2 to exit: ";
		cin >> user_input;
		cout << "\n";

		// If the user presses 2 (exit) break out of the while loop
		if (user_input == 2) {
			break;
		}

		// Generate a random number between 1 and 10
		srand(time(0));
		int random_number = rand() % 10;

		// Create a variable to store the user guess for each round
		int user_guess;

		// For loop to give 5 guesses
		// Decrement instead of increment to make displaying the guesses remaining
		for (int guesses = 5; guesses >= 1; guesses--) {

		  // Let the user enter a guess
		  cout << "Enter a guess [1-10]: ";
		  cin >> user_guess;
		  cout << "\n";

		  // If the user guesses the number, display a message and break the for loop
		  if (user_guess == random_number) {
			  cout << "Congratulations, you guessed the number\n";
			  break;

		  // If guess is higher than number, display message
		  } else if (user_guess > random_number) {
			  cout << "Too high, try again\n";

		  // If guess is lower than number, display message
		  } else if (user_guess < random_number) {
			  cout << "Too low, try again\n";
		  }

		  // When guesses is 1 remaining, display you have 1 guess remaining
		  if (guesses - 1 == 1) {
			  cout << "You have 1 guess remaining\n";

		  // If the user has no more guesses, display game over message
		  } else if (guesses - 1 == 0) {
			  cout << "Game over, the number was " << random_number << "\n";
		  }

		  // Else display general guesses remaining message
		  else {
			  cout << "You have " << (guesses - 1) << " guesses remaining\n";
		  }
		}

	}

	// When user has finished playing, display message and exit main by returning 0
	cout << "Thanks for playing\n";
	return 0;
}

