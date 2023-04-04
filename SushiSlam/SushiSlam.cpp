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

    g.round();


    /*Deck myDeck;
    for (int i = 0; i < 88; i++) {
        Card* card = myDeck.get_card(i);
        std::cout << card->str() << "\n";
    }

    myDeck.shuffle();
    for (int i = 0; i < 88; i++) {
        Card* card = myDeck.get_card(i);
        std::cout << card->str() << "\n";
    }
    
    
    
    DumplingCard* dPointer = new DumplingCard();
    const DumplingCard::CardType& dType = dPointer->type();

    if (dType == DumplingCard::CardType::Dumpling) {
        std::cout << "I am a dumpling \n";
    }

    std::cout << dPointer->str() << "\n";

    MakiRollCard* mPointer = new MakiRollCard(MakiAmount::one);
    const MakiRollCard::CardType& mType = mPointer->type();

    if (mType == MakiRollCard::CardType::MakiRoll) {
        std::cout << "I am a maki roll \n";
    }

    std::cout << mPointer->str() << "\n";

    NigiriCard* nPointer = new NigiriCard(NigiriType::Squid);
    const NigiriCard::CardType& nType = nPointer->type();

    if (nType == NigiriCard::CardType::Nigiri) {
        std::cout << "I am a Nigiri \n";
    }

    NigiriType nt = nPointer->getNigiriType();

    if (nt == NigiriType::Squid) {
        std::cout << "I am a Nigiri that is a squid \n";
    }

    std::string nTypeString = nPointer->nigiriTypeToString(nt);

    std::cout << "string version of nPointers nigiri type is " << nTypeString;*/


}


