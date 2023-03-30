/**
 * Project Sushi Slam
 */

#pragma once
#ifndef _NIGIRICARD_H
#define _NIGIRICARD_H

#include "Card.h"


class NigiriCard: public Card {
public: 
    //enum nigiriType;
	CardType cardType;
	NigiriCard();
	virtual const CardType& type() const override;
	virtual std::string str() const override;
};

#endif //_NIGIRICARD_H