#pragma once
#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>
#include <iostream>
#include <iterator>
#include <sstream>
#include <algorithm>

#include "Card.h"

typedef std::vector<Card*> CardCollection;

class Player {

public:

    Player() { _name = _names[rand() % 10]; };
    
    std::string getName();
    int getScore();
    CardCollection getTableau();
    void clearTableau();
    void addCardToTableau(Card* card, CardCollection& hand);
    int calcScoreForRound(CardCollection tableau, CardCollection otherPlayerTableau);

private:
    std::string _names[10] = { "Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue", "Sasha", "Tina", "Marge" };
    std::string _name;
    int _playerScore = 0;
    CardCollection _tableau;

};

#endif