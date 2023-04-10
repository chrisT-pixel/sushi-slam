
#pragma once
#ifndef _GAME_H
#define _GAME_H

#include "deck.h";
#include <iostream>
#include <vector>
#include <algorithm>
#include "Player.h"

typedef std::vector<Card*> CardCollection;


class Game {

public: 
    
    Game();

    std::string printWinner(Player* p1, Player* p2);
    void turn();
    void round();

private:
    CardCollection hand1;
    CardCollection hand2;
    Player* player1;
    Player* player2;
    int roundNumber = 0;
};

#endif