/**
 * Project Sushi Slam
 */


#include "MakiRollCard.h"

MakiRollCard::MakiRollCard() {
	this->cardType = MakiRoll;
}
const MakiRollCard::CardType& MakiRollCard::type() const {
	return Card::CardType::MakiRoll;
}

std::string MakiRollCard::str() const {
	return "Maki Roll";
}
