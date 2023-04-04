

#pragma once
#ifndef _NIGIRICARD_H
#define _NIGIRICARD_H
#include <iostream>
#include "Card.h"
#include "Player.h"

const enum class NigiriType {
	Egg,
	Squid,
	Salmon
};


class NigiriCard: public Card {

public: 
   
	CardType cardType;
	NigiriCard(NigiriType nigiriType_);
	
	virtual const CardType& type() const override;
	virtual std::string str() const override;

	NigiriType getNigiriType() const { return nigiriType_;};
	std::string nigiriTypeToString(NigiriType nt);

	virtual int score(CardCollection tableau, CardCollection otherPlayerTableau) const override {
		
		int nigiriScore = 0;

		for (Card* ptr : tableau) {

			if (ptr->type() == Nigiri) {
				NigiriCard* nPtr = static_cast<NigiriCard*>(ptr);
				//once I know the nigiri type I can score each type appropriatley 
				nPtr->getNigiriType();
			}

		}

		return nigiriScore;

	};


private:
	
	NigiriType nigiriType_;


};

#endif //_NIGIRICARD_H