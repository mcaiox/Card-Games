#pragma once
#include<vector>
#include "PontoonCard.h"

class User
{
private:
	std::vector<PontoonCard> hand;
public:
	User();
	void showCardsInHand();
	void takeCards(PontoonCard, PontoonCard);
	void takeCard(PontoonCard);
	void clearHand();
	int calculateHand();
	int calculateHandSize();


};

