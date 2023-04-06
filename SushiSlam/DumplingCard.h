
#pragma once
#ifndef _DUMPLINGCARD_H
#define _DUMPLINGCARD_H
#include <iostream>
#include "Card.h"
#include "Player.h"


class DumplingCard: public Card {

public:
	
	CardType cardType;
	DumplingCard();
	virtual const CardType& type() const override;
	virtual std::string str() const override;

	virtual int score(CardCollection tableau, CardCollection otherPlayerTableau) const override {
		
		int dumplingCount = 0;

		for (Card* ptr : tableau) {

			if (ptr->type() == Dumpling) {
				++dumplingCount;
			}

		}

		if (dumplingCount == 1) {
			return 1;
		}

		else if (dumplingCount == 2) {
			return 3;
		}

		else if (dumplingCount == 3) {
			return 6;
		}

		else if (dumplingCount == 4) {
			return 10;
		}

		else if (dumplingCount > 4) {
			return 15;
		}

		else {
			return 0;
		}

	};
};





#endif //_DUMPLINGCARD_H