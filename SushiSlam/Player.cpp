#include "Player.h"

std::string Player::getName() const{
    return _name;
}

int Player::getScore() const{
    return _playerScore;
}

CardCollection Player::getTableau() const{
    return _tableau;
}

void Player::clearTableau() {
    _tableau.clear();
}

void Player::addCardToTableau(Card* card, CardCollection& hand) {

    //add the card to the tableau
    _tableau.push_back(card);

    // iterator for current hand
    auto it = std::find(hand.begin(), hand.end(), card);
    
    //delete the card from the hand (as its in the tableau now)
    if (it != hand.end()) {
        hand.erase(it);
    }
}

int Player::calcScoreForRound(CardCollection& tableau, CardCollection& otherPlayerTableau) {

    // vector to hold card types already scored
    std::vector<Card::CardType> scored = {};
    // need to see if makiCounter is still 0 at the end 
    int makiCounter = 0;
    int score = 0;

    for (Card* ptr : tableau) {
        
        Card::CardType ct = ptr->type();
        
        //makiRoll is type = 1
        if (ct == 1) {
            makiCounter++;
        }

        // iterator for card types already scored
        auto iter = std::find(scored.begin(), scored.end(), ct);

        if (iter == scored.end()) {
            // score all of that card type and put the card type into the scored vector
            score += ptr->score(tableau, otherPlayerTableau);
            scored.push_back(ct);
        }
    }

    //if there were no makirolls in the tableau then they have not yet bee scored. Award three points in this case
    if (makiCounter == 0) {
        score += 3;
    }

    _playerScore += score;
    return score;
}

Player::~Player(){
    for (Card* card : _tableau) {
        delete card;
    }
}
