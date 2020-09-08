#include "GuessingGame.h"
#include <string>
#include <iostream>
#include <bits/stdc++.h>
//#include "stdc++.h"

GuessingGame::GuessingGame()
{
}

void GuessingGame::loadGame()
{

	while (true) {
		int guesses = 0;
		deck.shuffle();
		computer = deck.dealCard();
		computer.displayCard();
		computer.getFace();
		while (true) {
			//Validate Suit Input
			while (true) {
				std::cout << std::endl;
				std::cout << "Guess the suit, [ hearts | clubs | diamonds | spades ] or [ quit ] to quit " << std::endl;
				std::cin >> suitInput;
				std::cout << std::endl;
				transform(suitInput.begin(), suitInput.end(), suitInput.begin(), ::tolower);
				if (validateSuitInput(suitInput)) {
					break;

				}
				else if (suitInput == "quit") {
					return;
				}
				else {
					std::cout << std::endl;
					std::cout << "Wrong input, please try again from the following list: " << std::endl;
					continue;

				}
			}
			//Validate Face Input
			while (true) {
				std::cout << std::endl;
				std::cout << "Guess the face, [ ace | two | three | four | five | six | seven | eight | nine | ten | jack | queen | king ] or [ quit ] to quit " << std::endl;
				std::cin >> faceInput;
				std::cout << std::endl;
				transform(faceInput.begin(), faceInput.end(), faceInput.begin(), ::tolower);
				if (validateFaceInput(faceInput)) {
					std::cout << std::endl;
					guesses++;
					std::cout << "----------YOU HAVE CHOSEN [" << faceInput << " of " << suitInput <<"]----------"<< std::endl;
				}
				else if (faceInput == "quit") {
					return;
				}
				else {
					std::cout << "Wrong input, please try again from the following list: " << std::endl;
					continue;

				}
				break;
			}
			//std::cout << "cleared validation" << std::endl;
			//Check Matches
			guess.setFace(faceInput);
			guess.setSuit(suitInput);
			std::cout << std::endl;
			if (suitsMatch() && facesMatch()) {
				std::cout << "well done!! you won with a guesscount of: " << guesses << std::endl;
				std::cout << "Do you want to play again (y/n)" << std::endl;
				std::string h;
				std::cin >> h;
				transform(h.begin(), h.end(), h.begin(), ::tolower);
				if (h == "y") {
					std::cout << std::string(10, '\n');
					break;
				}
				else {
					return;
				}
			}
			else if (suitsMatch() && !facesMatch()) {
				std::cout << "The suit is right and ";
				if (computer.getFace() > guess.getFace()) {
					std::cout << "the face is wrong and it is too low!" << std::endl;

				}
				else {
					std::cout << "The face is wrong and it is too high!" << std::endl;
				}
			}
			else if (!suitsMatch() && facesMatch()) {
				std::cout << "The face is right and ";
				std::cout << "the suit is wrong" << std::endl;
			}
			else if (!suitsMatch() && !facesMatch()) {
				std::cout << "The suit is wrong and ";
				if (computer.getFace() > guess.getFace()) {
					std::cout << "the face is wrong and it is too low!" << std::endl;

				}
				else {
					std::cout << "The face is wrong and it is too high!" << std::endl;
				}


			}
		}
	}
}


bool GuessingGame::validateFaceInput(std::string input)
{
	if (input == "ace" || input == "two" || input == "three" || input == "four"
		|| input == "five" || input == "six" || input == "seven" || input == "eight"
		|| input == "nine" || input == "ten" || input == "jack" || input == "queen" || input == "king") {
		return true;

	}
	else {
		return false;
	}
}

bool GuessingGame::suitsMatch()
{
	return computer.getSuit() == guess.getSuit();
}

bool GuessingGame::facesMatch()
{
	return computer.getFace() == guess.getFace();
}

bool GuessingGame::validateSuitInput(std::string input)
{
	if (input == "hearts" || input == "clubs" || input == "diamonds" || input == "spades") {
		return true;
	}
	else {
		return false;
	}
}
