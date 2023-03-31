
#include "NigiriCard.h"


NigiriCard::NigiriCard(NigiriType nigiriType) : nigiriType_(nigiriType) {
	this->cardType = Nigiri;
};

const NigiriCard::CardType& NigiriCard::type() const {
	return Card::CardType::Nigiri;
}


std::string NigiriCard::nigiriTypeToString(NigiriType nt) {
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


