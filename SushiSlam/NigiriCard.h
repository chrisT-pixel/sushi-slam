

#pragma once
#ifndef _NIGIRICARD_H
#define _NIGIRICARD_H

#include "Card.h"

const enum class NigiriType {
	Egg,
	Squid,
	Salmon
};


class NigiriCard: public Card {

public: 
   
	CardType cardType;
	NigiriCard(NigiriType nigiriType_);
	
	virtual const CardType& type() const override;
	virtual std::string str() const override;

	NigiriType getNigiriType() const { return nigiriType_;};
	std::string nigiriTypeToString(NigiriType nt);

	


private:
	
	NigiriType nigiriType_;


};

#endif //_NIGIRICARD_H