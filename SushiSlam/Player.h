/**
 * Project Sushi Slam
 */

#pragma once
#include <string>
#include "Tableau.h"
#include "Hand.h"
#include "Score.h"
#ifndef _PLAYER_H
#define _PLAYER_H

class Player {
public: 
    Hand hand;
    std::string name;
    Score score;
    Tableau tableau;
    
/**
 * @param card
 * @param hand
 * @param tableau
 */
void addCardToTableau(Card &card, Hand hand, Tableau tableau);
    
Score calcScore();
    
/**
 * @param tableau
 */
void clearTableau(Tableau tableau);
    
/**
 * @param tableau
 */
std::string printTableau(Tableau tableau);
    
/**
 * @param score
 */
int getScore(Score score);
    
std::string getName();
};

#endif //_PLAYER_H