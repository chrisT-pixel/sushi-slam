/**
 * Project Sushi Slam
 */


#include "DumplingCard.h"



DumplingCard::DumplingCard() {
	this->cardType = Dumpling;
}
const DumplingCard::CardType& DumplingCard::type() const{
	return Card::CardType::Dumpling;
}

std::string DumplingCard::str() const{
	return "Dumpling";
}



