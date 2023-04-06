
#pragma once
#include "Card.h"
#include "DumplingCard.h";
#include "TempuraCard.h";
#include "MakiRollCard.h";
#include "NigiriCard.h";
#include "SashimiCard.h";
#include <vector>
#include <algorithm>
#include <random>
#ifndef _DECK_H
#define _DECK_H

typedef std::vector<Card*> CardCollection;

class Deck {

public:
    
    Deck() {
        
        for (int i = 0; i < 14; i++) {
            cards.push_back(new TempuraCard());
        }

        for (int i = 0; i < 14; i++) {
            cards.push_back(new SashimiCard());
        }

        for (int i = 0; i < 5; i++) {
            cards.push_back(new NigiriCard(NigiriType::Egg));
        }

        for (int i = 0; i < 5; i++) {
            cards.push_back(new NigiriCard(NigiriType::Squid));
        }

        for (int i = 0; i < 10; i++) {
            cards.push_back(new NigiriCard(NigiriType::Salmon));
        }

        for (int i = 0; i < 12; i++) {
            cards.push_back(new MakiRollCard(MakiAmount::two));
        }

        for (int i = 0; i < 8; i++) {
            cards.push_back(new MakiRollCard(MakiAmount::three));
        }

        for (int i = 0; i < 6; i++) {
            cards.push_back(new MakiRollCard(MakiAmount::one));
        }

        for (int i = 0; i < 14; i++) {
            cards.push_back(new DumplingCard());
        }

       

    }

    void shuffle() {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::shuffle(cards.begin(), cards.end(), generator);
    };

    Card* get_card(int index) const { return cards[index]; }

  

    ~Deck() {
        for (Card* card : cards) {
            delete card;
        }
    }

    std::vector<Card*> cards;
   

private:
  
    
};

#endif //_DECK_H