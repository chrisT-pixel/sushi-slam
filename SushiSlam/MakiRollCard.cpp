#include "MakiRollCard.h"


MakiRollCard::MakiRollCard(MakiAmount makiAmount) : _makiAmount(makiAmount) {
	_cardType = MakiRoll;
}
const MakiRollCard::CardType& MakiRollCard::type() const {
	return Card::CardType::MakiRoll;
}

std::string MakiRollCard::makiAmountToString(MakiAmount ma) const {
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

int MakiRollCard::score(CardCollection tableau, CardCollection otherPlayerTableau) const {

	int playerMakiCount = 0;
	int otherPlayerMakiCount = 0;

	for (Card* ptr : tableau) {

		if (ptr->type() == MakiRoll) {
			
			// down cast the card to a MakiRoll and get the number of Maki rolls on the card
			MakiRollCard* mPtr = dynamic_cast<MakiRollCard*>(ptr);
			MakiAmount ma = mPtr->getMakiAmount();

			// increment makiroll count appropriately 
			if (ma == MakiAmount::one) {
				playerMakiCount += 1;
			} else if (ma == MakiAmount::two) {
				playerMakiCount += 2;
			} else if (ma == MakiAmount::three) {
				playerMakiCount += 3;
			} else {
				playerMakiCount += 0;
			}
		}
	}

	for (Card* ptr : otherPlayerTableau) {

		if (ptr->type() == MakiRoll) {
			
			// down cast the card to a MakiRoll and get the number of Maki rolls on the card
			MakiRollCard* mPtr = dynamic_cast<MakiRollCard*>(ptr);
			MakiAmount ma = mPtr->getMakiAmount();

			// increment makiroll count appropriately
			if (ma == MakiAmount::one) {
				otherPlayerMakiCount += 1;
			} else if (ma == MakiAmount::two) {
				otherPlayerMakiCount += 2;
			} else if (ma == MakiAmount::three) {
				otherPlayerMakiCount += 3;
			} else {
				otherPlayerMakiCount += 0;
			}
		}
	}

	// return appropriate score based on makirolls counted
	if (playerMakiCount > otherPlayerMakiCount) {
		return 6;
	} else if (playerMakiCount < otherPlayerMakiCount) {
		return 3;
	} else {
		return 3;
	}

};



