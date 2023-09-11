#pragma once
#ifndef _DUMPLINGCARD_H
#define _DUMPLINGCARD_H
#include "Card.h"
#include "Player.h"


class DumplingCard: public Card {

public:
	
	DumplingCard();
	
	virtual const CardType& type() const override;
	virtual std::string str() const override;
	virtual int score(CardCollection tableau, CardCollection otherPlayerTableau) const override;

private:
	
	CardType _cardType;

};


#endif //_DUMPLINGCARD_H