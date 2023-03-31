
#pragma once
#ifndef _GAME_H
#define _GAME_H
#endif
#include "deck.h";
#include <iostream>
#include <vector>
#include <algorithm>
#include "Player.h"

typedef std::vector<Card*> CardCollection;


class Game {

public: 
    Game() {
        Deck deck;
        deck.shuffle();
        for (int i = 0; i < 88; i++) {
            Card* card = deck.get_card(i);
            std::cout << card->str() << "\n";
        }

        std::cout << deck.cards.size() << "\n";

        // Remove 10 cards from deck1 and add them to hand1
        for (int i = 0; i < 10; i++) {
            hand1.push_back(deck.cards.back());
            deck.cards.pop_back();
        }

        // Remove 10 more cards from deck1 and add them to hand2
        for (int i = 0; i < 10; i++) {
            hand2.push_back(deck.cards.back());
            deck.cards.pop_back();
        }

        std::cout << deck.cards.size() << "\n";
        std::cout << hand1.size() << "\n";
        std::cout << hand2.size() << "\n";

        player1 = Player();
        player2 = Player();

       //std::cout <<  player1.getName();
      // std::cout << player2.getName();

    }

    void turn() {
        std::cout << "PLAYER " << player1.getName() << " TURN \n";
        std::cout << "Tableau: \n";
        std::cout << "Current hand: \n";

        for (Card* ptr : hand1) {
            std::cout << ptr->str() << "\n";
        }

        std::cout << "Select a card to add to your tableau: \n";

        std::cout << "PLAYER " << player2.getName() << " TURN \n";
        std::cout << "Tableau: \n";
        std::cout << "Current hand: \n";

        for (Card* ptr : hand2) {
            std::cout << ptr->str() << "\n";
        }

        std::cout << "Select a card to add to your tableau: \n";

        //access the card at index 3 of the hand
        Card* c = hand1.at(3);
        std::cout << c->str();

        player1.addCardToTableau(c, hand1);

        std::cout << "\n hand 1 size now " << hand1.size() << "\n";
        for (Card* ptr : hand1) {
            std::cout << ptr->str() << "\n";
        }

        std::cout << "\n tableau player 1 size now " << player1.tableau.size() << "\n";
        for (Card* ptr : player1.tableau) {
            std::cout << ptr->str() << "\n";
        }
        
       
    }

private:
    CardCollection hand1;
    CardCollection hand2;
    Player player1;
    Player player2;
};

