/**
 * Project Sushi Slam
 */

#pragma once
#ifndef _TEMPURACARD_H
#define _TEMPURACARD_H

#include "Card.h"


class TempuraCard: public Card {

public:

	CardType cardType;
	TempuraCard();
	virtual const CardType& type() const override;
	virtual std::string str() const override;

};

#endif //_TEMPURACARD_H