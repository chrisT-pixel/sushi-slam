
#pragma once
#include "Card.h"
#include "DumplingCard.h"
#include "TempuraCard.h"
#include "MakiRollCard.h"
#include "NigiriCard.h"
#include "SashimiCard.h"
#include <vector>
#include <algorithm>
#include <random>
#ifndef _DECK_H
#define _DECK_H

typedef std::vector<Card*> CardCollection;

class Deck {

public:
    
    Deck() {};

    void populateDeck();
    std::vector<Card*> getCards() const;
    void shuffle();
 
    ~Deck();

private:
  
    CardCollection _cards;
    
};

#endif //_DECK_H