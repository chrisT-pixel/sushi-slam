/**
 * Project Sushi Slam
 */

#pragma once
#ifndef _MAKIROLLCARD_H
#define _MAKIROLLCARD_H
#include <iostream>
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

	virtual int score(std::vector<Card*> firstTableau, std::vector<Card*> secondTableau) const override {
		std::cout << "scoring a maki card \n";
		return 0;
	};


private:
	MakiAmount makiAmount_;
};

#endif //_MAKIROLLCARD_H