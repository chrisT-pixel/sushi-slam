/**
 * Project Sushi Slam
 */

#pragma once
#ifndef _TEMPURACARD_H
#define _TEMPURACARD_H
#include <iostream>
#include "Card.h"
#include "Player.h"


class TempuraCard: public Card {

public:

	CardType cardType;
	TempuraCard();
	virtual const CardType& type() const override;
	virtual std::string str() const override;

	virtual int score(CardCollection tableau, CardCollection otherPlayerTableau) const override {
		
		int tempuraCount = 0;

		for (Card* ptr : tableau) {

			if (ptr->type() == Tempura) {
				++tempuraCount;
			}

		}

		return (tempuraCount / 2) * 5;
	};

};

#endif //_TEMPURACARD_H