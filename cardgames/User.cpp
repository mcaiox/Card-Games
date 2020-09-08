#include "User.h"
#include <iostream>

User::User()
{
}

void User::showCardsInHand()
{
	for (PontoonCard p : hand) {
		std::cout<< " | ";
		p.displayCard();
		//std::cout<< " | ";
	}
	std::cout << " | ";
	std::cout << std::endl;
}

void User::takeCards(PontoonCard card, PontoonCard card2)
{
	hand.push_back(card);
	hand.push_back(card2);
}

void User::takeCard(PontoonCard card)
{
	hand.push_back(card);
}

void User::clearHand()
{
	hand.clear();
}

int User::calculateHand() { 
	int j = 0;
	for (auto i : hand) {
		j += i.getValue();
	}
	return j;

}

int User::calculateHandSize() {
	return hand.size();
}

