
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
        //for (int i = 0; i < 88; i++) {
        //    Card* card = deck.get_card(i);
         //   std::cout << card->str() << "\n";
        //}

        //std::cout << deck.cards.size() << "\n";

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

        //std::cout << deck.cards.size() << "\n";
        //std::cout << hand1.size() << "\n";
        //std::cout << hand2.size() << "\n";

        player1 = Player();
        player2 = Player();

       //std::cout <<  player1.getName();
      // std::cout << player2.getName();

    }

    void turn() {
        std::cout << "PLAYER " << player1.getName() << " TURN \n";
        std::cout << "Tableau: \n";
        
        for (Card* ptr : player1.tableau) {

            std::cout << ptr->str() << "\n";
           
        }
        
        
        std::cout << "Current hand: \n";

        

        int hand1Counter = 1;

        for (Card* ptr : hand1) {
            
            std::cout << hand1Counter << ". " << ptr->str() << "\n";
            ++hand1Counter;
        }

        std::cout << "Select a card to add to your tableau: \n";

        //access the card at index 3 of the hand
        Card* c1 = hand1.at(3);
        //std::cout << c->str();

        player1.addCardToTableau(c1, hand1);

        std::cout << "PLAYER " << player2.getName() << " TURN \n";
        std::cout << "Tableau: \n";
        
        for (Card* ptr : player2.tableau) {

            std::cout << ptr->str() << "\n";

        }
        
        
        std::cout << "Current hand: \n";

        int hand2Counter = 1;

        for (Card* ptr : hand2) {
           
            std::cout << hand2Counter << ". " << ptr->str() << "\n";
            ++hand2Counter;

        }

        std::cout << "Select a card to add to your tableau: \n";

        //access the card at index 6 of the hand
        Card* c2 = hand2.at(6);

        player2.addCardToTableau(c2, hand2);

        std::cout << "\nswapping hands now\n";

        // Create the new vectors
        CardCollection copy1;
        CardCollection copy2;

        // Copy the contents of the original hands to new hands
        copy1.assign(hand1.begin(), hand1.end());
        copy2.assign(hand2.begin(), hand2.end());

        hand1.assign(copy2.begin(), copy2.end());
        hand2.assign(copy1.begin(), copy1.end());
        

       

        /*std::cout << "\n hand 1 size now " << hand1.size() << "\n";
        for (Card* ptr : hand1) {
            std::cout << ptr->str() << "\n";
        }

        std::cout << "\n tableau player 1 size now " << player1.tableau.size() << "\n";
        for (Card* ptr : player1.tableau) {
            std::cout << ptr->str() << "\n";
        }*/
        
       
    }

private:
    CardCollection hand1;
    CardCollection hand2;
    Player player1;
    Player player2;
};

