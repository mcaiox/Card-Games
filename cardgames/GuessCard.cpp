#include <iostream>
#include "GuessCard.h"

GuessCard::GuessCard()
{
}

GuessCard::GuessCard(std::string f, std::string s):face(f), suit(s)
{
}

std::string GuessCard::getFace()
{
	return face;
}

std::string GuessCard::getSuit()
{
	return suit;
}

void GuessCard::setFace(std::string f)
{
	face = f;
}

void GuessCard::setSuit(std::string s)
{
	suit = s;
}

void GuessCard::displayCard()
{
	std::cout << face << " of " << suit;
}
