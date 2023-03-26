/**
 * Project Sushi Slam
 */


#include "Card.h"
#include "Tableau.h"
#include <string>
#ifndef _CARD_H
#define _CARD_H

class Card {
public:
    enum CardType {
        CLUBS,
        DIAMONDS,
        HEARTS,
        SPADES
    };
    bool needsSet;

    const CardType& type() const {
        return cardType_;
    }

    /**
     * @param CardType
     */
    std::string str(enum CardType ct) {
        switch (ct) {
        case CLUBS: return "Clubs";
        case DIAMONDS: return "Diamonds";
        case HEARTS: return "Hearts";
        case SPADES: return "Spades";
        }
        return "";
    }

    /**
     * @param firstTableau
     * @param secondTableau
     */
    int score(Tableau firstTableau, Tableau secondTableau) {
        // Implementation of score calculation goes here
        return 0;
    }

private:
    CardType cardType_;
};

#endif //_CARD_H
