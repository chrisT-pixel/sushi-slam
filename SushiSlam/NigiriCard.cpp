
#include "NigiriCard.h"


NigiriCard::NigiriCard(NigiriType nigiriType) : _nigiriType(nigiriType) {
	_cardType = Nigiri;
};

const NigiriCard::CardType& NigiriCard::type() const {
	return Card::CardType::Nigiri;
}


std::string NigiriCard::nigiriTypeToString(NigiriType nt) const {
	switch (nt) {
	case NigiriType::Egg:
		return "Egg";
	case NigiriType::Squid:
		return "Squid";
	case NigiriType::Salmon:
		return "Salmon";
	default:
		return "Unknown type of Nigiri";
	}
}


std::string NigiriCard::str() const {
    
	NigiriType nt = this->getNigiriType();

	switch (nt) {
	case NigiriType::Egg:
		return "Nigiri (Egg)";
	case NigiriType::Squid:
		return "Nigiri (Squid)";
	case NigiriType::Salmon:
		return "Nigiri (Salmon)";
	default:
		return "Unknown type of Nigiri";
	}

}

int NigiriCard::score(CardCollection tableau, CardCollection otherPlayerTableau) const {

	int nigiriScore = 0;

	for (Card* ptr : tableau) {

		if (ptr->type() == Nigiri) {
			
			// down cast the card to a Nigiri and get the nigiri type on the card
			NigiriCard* nPtr = dynamic_cast<NigiriCard*>(ptr);
			NigiriType nt = nPtr->getNigiriType();

			// increment score based on nigiri types counted 
			if (nt == NigiriType::Egg) {
				nigiriScore += 1;
			} else if (nt == NigiriType::Salmon) {
				nigiriScore += 2;
			} else if (nt == NigiriType::Squid) {
				nigiriScore += 3;
			} else {
				nigiriScore += 0;
			}
		}
	}

	return nigiriScore;

};


