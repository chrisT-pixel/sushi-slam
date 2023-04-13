
#pragma once
#ifndef _TEMPURACARD_H
#define _TEMPURACARD_H
#include "Card.h"
#include "Player.h"


class TempuraCard: public Card {

public:

	TempuraCard();
	
	virtual const CardType& type() const override;
	virtual std::string str() const override;
	virtual int score(CardCollection tableau, CardCollection otherPlayerTableau) const override;

private:
	
	CardType _cardType;

};

#endif //_TEMPURACARD_H