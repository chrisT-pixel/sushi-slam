/**
 * Project Sushi Slam
 */

#pragma once
#ifndef _SASHIMICARD_H
#define _SASHIMICARD_H

#include "Card.h"


class SashimiCard: public Card {

public:

	CardType cardType;
	SashimiCard();
	virtual const CardType& type() const override;
	virtual std::string str() const override;

};

#endif //_SASHIMICARD_H