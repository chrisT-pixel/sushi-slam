/**
 * Project Sushi Slam
 */

#pragma once
#ifndef _MAKIROLLCARD_H
#define _MAKIROLLCARD_H
#include <iostream>
#include "Card.h"
#include "Player.h"

const enum class MakiAmount {
	one,
	two,
	three
};

class MakiRollCard: public Card {

public: 
   
	CardType cardType;
	MakiRollCard(MakiAmount makiAmount_);
	
	virtual const CardType& type() const override;
	virtual std::string str() const override;

	MakiAmount getMakiAmount() const { return makiAmount_; };
	std::string makiAmountToString(MakiAmount ma);

	virtual int score(CardCollection tableau, CardCollection otherPlayerTableau) const override {
		
		int playerMakiCount = 0;
		int otherPlayerMakiCount = 0;

		for (Card* ptr : tableau) {

			if (ptr->type() == MakiRoll) {
				MakiRollCard* mPtr = dynamic_cast<MakiRollCard*>(ptr);
				//once I know the maki type I can score each type appropriatley 
				MakiAmount ma = mPtr->getMakiAmount();

				if (ma == MakiAmount::one) {
					playerMakiCount += 1;
				}

				else if (ma == MakiAmount::two) {
					playerMakiCount += 2;
				}

				if (ma == MakiAmount::three) {
					playerMakiCount += 3;
				}

				else {
					playerMakiCount += 0;
				}
			}

		}

		for (Card* ptr : otherPlayerTableau) {

			if (ptr->type() == MakiRoll) {
				MakiRollCard* mPtr = dynamic_cast<MakiRollCard*>(ptr);
				//once I know the maki type I can score each type appropriatley 
				MakiAmount ma = mPtr->getMakiAmount();

				if (ma == MakiAmount::one) {
					otherPlayerMakiCount += 1;
				}

				else if (ma == MakiAmount::two) {
					otherPlayerMakiCount += 2;
				}

				if (ma == MakiAmount::three) {
					otherPlayerMakiCount += 3;
				}

				else {
					otherPlayerMakiCount += 0;
				}
			}

		}

		//std::cout << "player 1 maki count " << playerMakiCount << "\n";
		//std::cout << "player 2 maki count " << otherPlayerMakiCount << "\n";



		if (playerMakiCount > otherPlayerMakiCount) {
			return 6;
		}

		else if (playerMakiCount < otherPlayerMakiCount) {
			return 3;
		}

		else {
			return 3;
		}

	};


private:
	MakiAmount makiAmount_;
};

#endif //_MAKIROLLCARD_H