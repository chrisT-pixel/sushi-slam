#pragma once
#ifndef _NIGIRICARD_H
#define _NIGIRICARD_H
#include "Card.h"
#include "Player.h"

const enum class NigiriType {
	Egg,
	Squid,
	Salmon
};


class NigiriCard: public Card {
public: 
   
	NigiriCard(NigiriType nigiriType_);
	
	virtual const CardType& type() const override;
	virtual std::string str() const override;
	virtual int score(CardCollection tableau, CardCollection otherPlayerTableau) const override;
	NigiriType getNigiriType() const { return _nigiriType;};
	std::string nigiriTypeToString(NigiriType nt);

private:
	
	CardType _cardType;
	NigiriType _nigiriType;

};

#endif 