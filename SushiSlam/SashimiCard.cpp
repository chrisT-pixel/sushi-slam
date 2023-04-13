/**
 * Project Sushi Slam
 */


#include "SashimiCard.h"

SashimiCard::SashimiCard() {
	_cardType = Sashimi;
}
const SashimiCard::CardType& SashimiCard::type() const {
	return Card::CardType::Sashimi;
}

std::string SashimiCard::str() const {
	return "Sashimi";
}

int SashimiCard::score(CardCollection tableau, CardCollection otherPlayerTableau) const {

	int sashimiCount = 0;

	// increment sashimi count as necessary
	for (Card* ptr : tableau) {
		if (ptr->type() == Sashimi) {
			++sashimiCount;
		}
	}

	//return 10 points for every three sashimi
	return (sashimiCount / 3) * 10;

}