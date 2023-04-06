/**
 * Project Sushi Slam
 */

#pragma once
#include <string>
#include <iostream>
#ifndef _PLAYER_H
#define _PLAYER_H
#endif
#include "Card.h"

#include <iterator>
#include <sstream>
#include <algorithm>

typedef std::vector<Card*> CardCollection;

class Player {

public:

    std::string name;
    int playerScore = 0;
    std::string names[10] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue", "Sasha", "Tina", "Marge" };
    
    Player() {

        name = names[rand() % 10];
    };

    std::string getName() {
        return name;
    }

    CardCollection tableau;
    
    
    void addCardToTableau(Card* card, CardCollection& hand) {
    
        tableau.push_back(card);

        auto it = std::find(hand.begin(), hand.end(), card);
        if (it != hand.end()) {
            hand.erase(it);
        }
    }

    int calcScoreForRound(CardCollection tableau, CardCollection otherPlayerTableau) {
           
        std::vector<Card::CardType> scored = {};
        int counter = 0;
        int score = 0;
        
        for (Card* ptr : tableau) {

            Card::CardType ct = ptr->type();

            auto iter = std::find(scored.begin(), scored.end(), ct);

            if (iter == scored.end()) {
                
                score += ptr->score(tableau, otherPlayerTableau);

                scored.push_back(ct);
               
            }

        }
        
        playerScore += score;
        return score;
    
    }







    

    
    
    
    
   /* Score calcScore();


    void clearTableau(Tableau tableau);


    std::string printTableau(Tableau tableau);


    int getScore(Score score);*/

};

