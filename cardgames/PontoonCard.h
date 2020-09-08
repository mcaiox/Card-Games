#pragma once
#include <string>
#include "GuessCard.h"

class PontoonCard : public GuessCard
{
public:
	PontoonCard(std::string, std::string);
	int getValue();
	void setValue(int);
private:
	int value;

};

