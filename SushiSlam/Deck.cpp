#include "Deck.h"

void Deck::populateDeck() {

    for (int i = 0; i < 14; i++) {
        _cards.push_back(new TempuraCard());
    }

    for (int i = 0; i < 14; i++) {
        _cards.push_back(new SashimiCard());
    }

    for (int i = 0; i < 5; i++) {
        _cards.push_back(new NigiriCard(NigiriType::Egg));
    }

    for (int i = 0; i < 5; i++) {
        _cards.push_back(new NigiriCard(NigiriType::Squid));
    }

    for (int i = 0; i < 10; i++) {
        _cards.push_back(new NigiriCard(NigiriType::Salmon));
    }

    for (int i = 0; i < 12; i++) {
        _cards.push_back(new MakiRollCard(MakiAmount::two));
    }

    for (int i = 0; i < 8; i++) {
        _cards.push_back(new MakiRollCard(MakiAmount::three));
    }

    for (int i = 0; i < 6; i++) {
        _cards.push_back(new MakiRollCard(MakiAmount::one));
    }

    for (int i = 0; i < 14; i++) {
        _cards.push_back(new DumplingCard());
    }

}

std::vector<Card*> Deck::getCards() {
    return Deck::_cards;
}

void Deck::shuffle() {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(_cards.begin(), _cards.end(), generator);
};

Deck::~Deck() {
    for (Card* card : _cards) {
        delete card;
    }
}
