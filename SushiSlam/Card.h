
#include <string>
#include <vector>

#ifndef _CARD_H
#define _CARD_H

class Card {
public: 
    const enum CardType {
        Dumpling,
        MakiRoll,
        Nigiri,
        Sashimi,
        Tempura
    };
    //bool needsSet = true; 
    //CardType cardType;

   
    
virtual const CardType& type() const = 0;
virtual std::string str() const = 0;
    
//std::string str(enum CardType);
    

virtual int score(std::vector<Card*> firstTableau, std::vector<Card*> secondTableau) const = 0;
};

#endif //_CARD_H