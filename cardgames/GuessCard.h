#pragma once
#include <string>

class GuessCard
{
private:
	std::string face;
	std::string suit;

public:
	GuessCard();
	GuessCard(std::string, std::string);
	std::string getFace();
	std::string getSuit();
	void setFace(std::string);
	void setSuit(std::string);
	void displayCard();
};

