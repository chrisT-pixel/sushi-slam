#include "TempuraCard.h"


TempuraCard::TempuraCard() {
	_cardType = Tempura;
}
const TempuraCard::CardType& TempuraCard::type() const {
	return Card::CardType::Tempura;
}

std::string TempuraCard::str() const {
	return "Tempura";
}

int TempuraCard::score(CardCollection tableau, CardCollection otherPlayerTableau) const {

	int tempuraCount = 0;

	for (Card* ptr : tableau) {

		if (ptr->type() == Tempura) {
			++tempuraCount;
		}

	}

	return (tempuraCount / 2) * 5;
};

