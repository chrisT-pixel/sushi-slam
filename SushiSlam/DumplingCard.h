/**
 * Project Sushi Slam
 */

#pragma once
#ifndef _DUMPLINGCARD_H
#define _DUMPLINGCARD_H

#include "Card.h"


class DumplingCard: public Card {

public:
	
	CardType cardType;
	DumplingCard();
	virtual const CardType& type() const override;
	virtual std::string str() const override;


};


#endif //_DUMPLINGCARD_H