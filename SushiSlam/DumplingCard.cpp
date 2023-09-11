#include "DumplingCard.h"


DumplingCard::DumplingCard() {
	_cardType = Dumpling;
}
const DumplingCard::CardType& DumplingCard::type() const{
	return Card::CardType::Dumpling;
}

std::string DumplingCard::str() const{
	return "Dumpling";
}

int DumplingCard::score(CardCollection tableau, CardCollection otherPlayerTableau) const{

	int dumplingCount = 0;

	// calculate total number of dumplings in tableau
	for (Card* ptr : tableau) {
		if (ptr->type() == Card::CardType::Dumpling) {
			++dumplingCount;
		}
	}

	// return appropriate score based on count
	if (dumplingCount == 1) {
		return 1;
	} else if (dumplingCount == 2) {
		return 3;
	} else if (dumplingCount == 3) {
		return 6;
	} else if (dumplingCount == 4) {
		return 10;
	} else if (dumplingCount > 4) {
		return 15;
	} else {
		return 0;
	}
};

