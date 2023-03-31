/**
 * Project Sushi Slam
 */

#pragma once
#include <string>
#include "Hand.h"
#include "Score.h"
#ifndef _PLAYER_H
#define _PLAYER_H
#endif

typedef std::vector<Card*> CardCollection;

class Player {

public:

    Hand hand;
    std::string name;
    Score score;
    //Tableau tableau;
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







    

    
    
    
    
   /* Score calcScore();


    void clearTableau(Tableau tableau);


    std::string printTableau(Tableau tableau);


    int getScore(Score score);*/

};

