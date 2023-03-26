/**
 * Project Sushi Slam
 */

#pragma once
#ifndef _GAME_H
#define _GAME_H

class Game {
public: 
    
void initGame();
    
void endGame();
    
void createDeck();
    
void shuffleDeck();
    
void populateHand();
    
void createPlayer();
    
void controlTurn();
    
void swapHands();
    
void currentRound();
    
void currentTurn();
    
void currentPlayer();
};

#endif //_GAME_H