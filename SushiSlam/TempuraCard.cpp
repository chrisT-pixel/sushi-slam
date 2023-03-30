/**
 * Project Sushi Slam
 */


#include "TempuraCard.h"


TempuraCard::TempuraCard() {
	this->cardType = Tempura;
}
const TempuraCard::CardType& TempuraCard::type() const {
	return Card::CardType::Tempura;
}

std::string TempuraCard::str() const {
	return "Tempura";
}

