/**
 * Project Sushi Slam
 */


#include "NigiriCard.h"

NigiriCard::NigiriCard() {
	this->cardType = Nigiri;
}
const NigiriCard::CardType& NigiriCard::type() const {
	return Card::CardType::Nigiri;
}

std::string NigiriCard::str() const {
	return "Nigiri";
}
