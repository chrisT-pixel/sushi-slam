#pragma once
#ifndef _SASHIMICARD_H
#define _SASHIMICARD_H
#include "Card.h"
#include "Player.h"

class SashimiCard: public Card {

public:
	
	SashimiCard();
	
	virtual const CardType& type() const override;
	virtual std::string str() const override;
	virtual int score(CardCollection tableau, CardCollection otherPlayerTableau) const override;

private:
	CardType _cardType;
};

#endif //_SASHIMICARD_H