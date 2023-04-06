/**
 * Project Sushi Slam
 */

#pragma once
#ifndef _SASHIMICARD_H
#define _SASHIMICARD_H

#include "Card.h"
#include "Player.h"
#include <iostream>


class SashimiCard: public Card {

public:

	CardType cardType;
	SashimiCard();
	virtual const CardType& type() const override;
	virtual std::string str() const override;

	/*int countSashimis() {
		int sashimiCount = 0;

		for (Card* ptr : tableau) {

			std::cout << ptr->str() << "\n";

		}

	}*/

	virtual int score(CardCollection tableau, CardCollection otherPlayerTableau) const override{

		int sashimiCount = 0;

		for (Card* ptr : tableau) {

			if (ptr->type() == Sashimi) {
				++sashimiCount;
			}

		}

		return (sashimiCount / 3) * 10;
	
	}


};

#endif //_SASHIMICARD_H