#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "GuessCard.h"
#include "PontoonCard.h"



template<typename T>
class Deck
{
private:
	std::vector<T> mainDeck;

public:
	Deck();
	void shuffle();
	T dealCard();
	void reset();
};

template<typename T>
inline Deck<T>::Deck()
{
	//std::cout << "Deck Constructor" << std::endl;

	std::vector<std::string> faces = { "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king", "ace" };
	std::vector<std::string> suits = { "hearts", "clubs", "diamonds", "spades" };

	for (auto suit : suits) {
		for (auto face : faces) {
			T c(face, suit);
			mainDeck.push_back(c);
			//int counter;
			//counter++;
			//std::cout << face << " of " << suit <<" "<<counter<< std::endl;
		}
	}

}

template<typename T>
inline void Deck<T>::shuffle()
{
	std::srand(unsigned(std::time(0)));

	std::random_shuffle(mainDeck.begin(), mainDeck.end());
	//std::cout << "Shuffled  "<<mainDeck[0].getFace()<<"of"<<mainDeck[0].getSuit()   << std::endl;



}

template<typename T>
inline T Deck<T>::dealCard()
{
	T firstCard = mainDeck.front();
	mainDeck.erase(mainDeck.begin(), mainDeck.begin() + 1);
	return firstCard;
}

template<typename T>
inline void Deck<T>::reset()
{
	mainDeck.clear();
	std::vector<std::string> faces = { "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king", "ace" };
	std::vector<std::string> suits = { "hearts", "clubs", "diamonds", "spades" };

	for (auto suit : suits) {
		for (auto face : faces) {
			T c(face, suit);
			mainDeck.push_back(c);
			//int counter;
			//counter++;
			//std::cout << face << " of " << suit <<" "<<counter<< std::endl;
		}
	}

}
