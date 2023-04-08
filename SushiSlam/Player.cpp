#include "Player.h"

std::string Player::getName() {
    return _name;
}

int Player::getScore() {
    return _playerScore;
}

CardCollection Player::getTableau() {
    return _tableau;
}

void Player::clearTableau() {
    _tableau.clear();
}

void Player::addCardToTableau(Card* card, CardCollection& hand) {

    _tableau.push_back(card);

    auto it = std::find(hand.begin(), hand.end(), card);
    
    if (it != hand.end()) {
        hand.erase(it);
    }
}

int Player::calcScoreForRound(CardCollection tableau, CardCollection otherPlayerTableau) {

    std::vector<Card::CardType> scored = {};
    int counter = 0;
    int score = 0;

    for (Card* ptr : tableau) {

        Card::CardType ct = ptr->type();

        auto iter = std::find(scored.begin(), scored.end(), ct);

        if (iter == scored.end()) {

            score += ptr->score(tableau, otherPlayerTableau);
            scored.push_back(ct);
        
        }

    }

    _playerScore += score;
    return score;

}

Player::~Player(){
    
    for (Card* card : _tableau) {

        delete card;

    }
}
