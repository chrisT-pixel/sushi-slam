/**
 * Project Sushi Slam
 */

#pragma once
#ifndef _MAKIROLLCARD_H
#define _MAKIROLLCARD_H

#include "Card.h"

const enum class MakiAmount {
	one,
	two,
	three
};

class MakiRollCard: public Card {

public: 
   
	CardType cardType;
	MakiRollCard(MakiAmount makiAmount_);
	
	virtual const CardType& type() const override;
	virtual std::string str() const override;

	MakiAmount getMakiAmount() const { return makiAmount_; };
	std::string makiAmountToString(MakiAmount ma);


private:
	MakiAmount makiAmount_;
};

#endif //_MAKIROLLCARD_H