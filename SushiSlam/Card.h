/**
 * Project Sushi Slam
 */


#include <string>
//forward declarations to avoid circular dependency with Tableau
class Tableau;

#ifndef _CARD_H
#define _CARD_H

class Card {
public: 
    enum CardType;
    bool needsSet;
    
const CardType& type() const;
    
/**
 * @param CardType
 */
std::string str(enum CardType);
    
/**
 * @param firstTableau
 * @param secondTableau
 */
virtual int score(Tableau firstTableau, Tableau secondTableau) const = 0;
};

#endif //_CARD_H