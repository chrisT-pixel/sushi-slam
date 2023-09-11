
#pragma once
#ifndef _GAME_H
#define _GAME_H

#include "deck.h";
#include <iostream>
#include <vector>
#include <algorithm>
#include "Player.h"

class Game {

public: 
    
    Game();

    std::string printWinner(Player* p1, Player* p2) const;
    void turn();
    void round();

private:
    
    CardCollection _hand1;
    CardCollection _hand2;
    Player* _player1;
    Player* _player2;
    int _roundNumber = 0;
};

#endif