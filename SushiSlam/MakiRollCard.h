/**
 * Project Sushi Slam
 */

#pragma once
#ifndef _MAKIROLLCARD_H
#define _MAKIROLLCARD_H

#include "Card.h"


class MakiRollCard: public Card {
public: 
    int numMakis;
	CardType cardType;
	MakiRollCard();
	virtual const CardType& type() const override;
	virtual std::string str() const override;
};

#endif //_MAKIROLLCARD_H