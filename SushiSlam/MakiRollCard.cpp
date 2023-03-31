/**
 * Project Sushi Slam
 */


#include "MakiRollCard.h"


MakiRollCard::MakiRollCard(MakiAmount makiAmount) : makiAmount_(makiAmount) {
	this->cardType = MakiRoll;
}
const MakiRollCard::CardType& MakiRollCard::type() const {
	return Card::CardType::MakiRoll;
}

std::string MakiRollCard::makiAmountToString(MakiAmount ma) {
    switch (ma) {
    case MakiAmount::one:
        return "(1)";
    case MakiAmount::two:
        return "(2)";
    case MakiAmount::three:
        return "(3)";
    default:
        return "Unknown amount of Maki Roll";
    }
}

std::string MakiRollCard::str() const {
	
	MakiAmount ma = this->getMakiAmount();

    switch (ma) {
    case MakiAmount::one:
        return "Maki Roll (1)";
    case MakiAmount::two:
        return "Maki Roll (2)";
    case MakiAmount::three:
        return "Maki Roll (3)";
    default:
        return "Unknown amount of Maki Roll";
    }

}



