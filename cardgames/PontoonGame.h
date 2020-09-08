#pragma once
#include "CardGame.h"
#include "PontoonCard.h"
#include "Deck.h"
#include "User.h"
#include <vector>
#include <iostream>
class PontoonGame : public CardGame
{
public:
	PontoonGame();
	void loadGame();
private:
	Deck<PontoonCard> deck;
	std::vector <int> stats;
	User computer;
	User human;



};

