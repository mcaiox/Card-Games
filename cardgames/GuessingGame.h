#pragma once
#include "CardGame.h"
#include "Deck.h"
#include "GuessCard.h"
class GuessingGame : public CardGame
{
public:
	GuessingGame();
	void loadGame();
	bool validateSuitInput(std::string);
	bool validateFaceInput(std::string);
	bool suitsMatch();
	bool facesMatch();

private:
	Deck<GuessCard> deck;
	GuessCard guess;
	GuessCard computer;
	std::string suitInput;
	std::string faceInput;



};

