// SushiSlam.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Card.h"
#include "DumplingCard.h"
#include "MakiRollCard.h"
#include "NigiriCard.h"
#include "Deck.h"
#include "Game.h"


#ifndef UNTITLED_TITLETEXT_H
#define UNTITLED_TITLETEXT_H

const char* TITLE_TEXT =
"|       |  | |  |       |  | |  |   |       |   |   |   _   |  |_|  |  |\n"
"|  _____|  | |  |  _____|  |_|  |   |  _____|   |   |  |_|  |       |  |\n"
"| |_____|  |_|  | |_____|       |   | |_____|   |   |       |       |  |\n"
"|_____  |       |_____  |       |   |_____  |   |___|       |       |__|\n"
" _____| |       |_____| |   _   |   |_____| |       |   _   | ||_|| |__\n"
"|_______|_______|_______|__| |__|___|_______|_______|__| |__|_|   |_|__|\n";


#endif //UNTITLED_TITLETEXT_H


int main(){
    
    std::cout << TITLE_TEXT << "\n";
    Game g;
}


