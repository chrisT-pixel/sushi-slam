/**
 * Project Sushi Slam
 */


#include "SashimiCard.h"

SashimiCard::SashimiCard() {
	this->cardType = Sashimi;
}
const SashimiCard::CardType& SashimiCard::type() const {
	return Card::CardType::Sashimi;
}

std::string SashimiCard::str() const {
	return "Sashimi";
}