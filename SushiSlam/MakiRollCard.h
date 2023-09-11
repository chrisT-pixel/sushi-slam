#pragma once
#ifndef _MAKIROLLCARD_H
#define _MAKIROLLCARD_H
#include "Card.h"
#include "Player.h"

const enum class MakiAmount {
	one,
	two,
	three
};

class MakiRollCard: public Card {

public: 
   
	MakiRollCard(MakiAmount makiAmount_);
	
	virtual const CardType& type() const override;
	virtual std::string str() const override;
	virtual int score(CardCollection tableau, CardCollection otherPlayerTableau) const override;
	MakiAmount getMakiAmount() const { return _makiAmount; };
	std::string makiAmountToString(MakiAmount ma) const;

	
private:
	
	CardType _cardType;
	MakiAmount _makiAmount;
};

#endif //_MAKIROLLCARD_H