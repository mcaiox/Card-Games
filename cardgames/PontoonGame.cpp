#include "PontoonGame.h"
#include <string>
#include <bits/stdc++.h>
//#include "stdc++.h"

PontoonGame::PontoonGame()
{
}

void PontoonGame::loadGame()
{

	std::string in;
	while (true) {
		//std::cout << "1st while loop" << std::endl;
		deck.reset();
		deck.shuffle();
		computer.clearHand();
		human.clearHand();

		auto i = deck.dealCard();
		auto j = deck.dealCard();
		human.takeCards(i, j);
		auto k = deck.dealCard();
		auto l = deck.dealCard();
		computer.takeCards(k, l);
		std::cout << "Welcome!" << std::endl;
		while (true) {
			//std::cout << "2nd while loop" << std::endl;
			//computer.showCardsInHand();
			std::cout << std::endl;
			std::cout << "The cards you hold are: ";
			human.showCardsInHand();
			std::cout << std::endl;
			std::cout << "They total to a value =  ";
			std::cout << human.calculateHand() << "\n" << std::endl;
			std::cout << "[s]tick or [t]wist ?" << std::endl;
			std::cin >> in;
			transform(in.begin(), in.end(), in.begin(), ::tolower);
			//std::cout << in << std::endl;
			//std::cout << human.calculateHandSize() << std::endl;
			if (in == "t") {
				auto m = deck.dealCard();
				human.takeCard(m);
				if (human.calculateHand() >= 21) {
					break;
				}
				else {
					continue;
				}
			}
			else if (in == "s" || human.calculateHandSize() >=5 || human.calculateHand()>=21) {
				break;
			}
			else {
				std::cout << "Invalid input, please try again from the options listed" << std::endl;
				continue;
			}


		}
		if (human.calculateHand() == 21) {
			std::cout << std::endl;
			std::cout << "The cards you hold are: ";
			human.showCardsInHand();
			std::cout << std::endl;
			std::cout << "They total to a value =  ";
			std::cout << human.calculateHand() << "\n" << std::endl;
			std::cout << "Well done, you won!!!"<< std::endl;
			stats.push_back(1);
		}
		else if (human.calculateHand() > 21) {
			std::cout << std::endl;
			std::cout << "The cards you hold are: ";
			human.showCardsInHand();
			std::cout << std::endl;
			std::cout << "They total to a value =  ";
			std::cout << human.calculateHand() << "\n" << std::endl;
			std::cout << "BUST!!!"<<std::endl;
			std::cout<<"Bad luck, the bank won"<<std::endl;
			stats.push_back(0);
		}
		else {
			std::cout << std::endl;
			std::cout << "The cards the bank hold are: ";
			computer.showCardsInHand();
			std::cout << std::endl;
			std::cout << "They total to a value =  ";
			std::cout << computer.calculateHand() << "\n" << std::endl;
			while (computer.calculateHand() <= 21 && computer.calculateHandSize() < 5 && human.calculateHand() >= computer.calculateHand()) {
				auto n = deck.dealCard();
				computer.takeCard(n);
				std::cout << "Total value = " << computer.calculateHand() << std::endl;
			}



			if (computer.calculateHand() > 21) {
				std::cout << std::endl;
				std::cout << "BUST!!!" << std::endl;
				std::cout << "Well done, you won!!!" << std::endl;
				stats.push_back(1);
			}
			else if (human.calculateHand() > computer.calculateHand()) {
				std::cout << std::endl;
				std::cout << "BUST!!!" << std::endl;
				std::cout << "Well done, you won!!!" << std::endl;
				stats.push_back(1);

			}
			else if (human.calculateHandSize() >= computer.calculateHandSize() && human.calculateHand() == computer.calculateHand()) {
				std::cout << std::endl;
				std::cout << "TIEBREAKER!..." << std::endl;
				std::cout << "Well done, you won!!!" << std::endl;
				stats.push_back(1);
			}
			else {
				std::cout << "TIEBREAKER!..." << std::endl;
				std::cout << "BANK WINS!"<<std::endl;
				stats.push_back(0);
			}
		}
		std::cout << std::endl;
		std::cout << "Would you like to play another round? (y/n)" << std::endl;
		std::string po;
		std::cin >> po;
		transform(po.begin(), po.end(), po.begin(), ::tolower);
		std::cout << std::endl;
		if (po == "n")
		{
			break;
		}
		else if (po == "y"){
			continue;
		}
	}

	int countj = 1;
	int won = 0;
	int lost = 0;
	for (auto i : stats) {
		std::cout << "Round " << countj<<": ";
		if (i == 1) {
			std::cout << " Won"<<std::endl;
			won++;
		}
		else {
			std::cout << " Lost" << ::std::endl;
			lost++;
		}
		countj++;

	}
	std::cout << std::endl;
	std::cout << "Rounds played: " << stats.size() << std::endl;
	std::cout << "Won: " << won << std::endl;
	std::cout << "Lost: " << lost << std::endl;

}
