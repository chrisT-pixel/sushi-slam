#include "Game.h"

Game::Game() {

    Deck* deck = new Deck();
    deck->populateDeck();
    deck->shuffle();

    player1 = new Player();
    player2 = new Player();

    std::vector<Card*> gameCards = deck->getCards();

    std::cout << std::endl;

    for (int i = 0; i < 3; i++) {
        ++roundNumber;
        // Remove 10 cards from deck and add them to hand1
        for (int i = 0; i < 10; i++) {
            hand1.push_back(gameCards.back());
            gameCards.pop_back();
        }

        // Remove 10 more cards from deck and add them to hand2
        for (int i = 0; i < 10; i++) {
            hand2.push_back(gameCards.back());
            gameCards.pop_back();
        }
        round();
    }

    std::string winnerMessage = printWinner(player1, player2);
    std::cout << winnerMessage;

    //clean up memory and exit program
    for (Card* card : hand1) {
        delete card;
    }
    
    for (Card* card : hand2) {
        delete card;
    }

    delete deck;
    delete player1;
    delete player2;
    exit(0);
}

std::string Game::printWinner(Player* p1, Player* p2) {

    std::cout << "~~~ End of game! ~~~\n";
    std::cout << "PLAYER " << p1->getName() << " final score: " << p1->getScore() << "\n";
    std::cout << "PLAYER " << p2->getName() << " final score: " << p2->getScore() << "\n";

    if (p1->getScore() > p2->getScore()) {
        return "Player " + p1->getName() + " WINS\n";
    }

    else if (p1->getScore() < p2->getScore()) {
        return "Player " + p2->getName() + " WINS\n";
    }

    else {
        return "The game is a draw!";
    }

}

void Game::turn() {
    
    std::cout << "PLAYER " << player1->getName() << " TURN\n";
    std::cout << "Tableau: \n";

    CardCollection player1Tableau = player1->getTableau();

    for (Card* ptr : player1Tableau) {

        std::cout << ptr->str() << "\n";

    }

    std::cout << "Current hand: \n";

    int hand1Counter = 1;

    for (Card* ptr : hand1) {

        std::cout << hand1Counter << ". " << ptr->str() << "\n";
        ++hand1Counter;
    }

    std::cout << "Select a card to add to your tableau: \n";

    int player1Input;
    std::cin >> player1Input;

    while (player1Input > hand1.size() || player1Input <= 0 || std::cin.fail()) {

        std::cout << "Select a card to add to your tableau: \n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> player1Input;

    }

    Card* c1 = hand1.at(player1Input - 1);
    std::cout << c1->str();

    player1->addCardToTableau(c1, hand1);

    std::cout << "\nPLAYER " << player2->getName() << " TURN \n";
    std::cout << "Tableau: \n";

    CardCollection player2Tableau = player2->getTableau();

    for (Card* ptr : player2Tableau) {

        std::cout << ptr->str() << "\n";

    }

    std::cout << "Current hand: \n";

    int hand2Counter = 1;

    for (Card* ptr : hand2) {

        std::cout << hand2Counter << ". " << ptr->str() << "\n";
        ++hand2Counter;

    }

    std::cout << "Select a card to add to your tableau: \n";

    int player2Input;
    std::cin >> player2Input;

    while (player2Input > hand2.size() || player1Input <= 0 || std::cin.fail()) {

        std::cout << "Select a card to add to your tableau: \n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> player2Input;

    }

    Card* c2 = hand2.at(player2Input - 1);

    player2->addCardToTableau(c2, hand2);

    // Create the new vectors
    CardCollection copy1;
    CardCollection copy2;

    // Copy the contents of the original hands to new hands
    copy1.assign(hand1.begin(), hand1.end());
    copy2.assign(hand2.begin(), hand2.end());

    hand1.assign(copy2.begin(), copy2.end());
    hand2.assign(copy1.begin(), copy1.end());

}

void Game::round() {

    std::cout << "~~~ round " << roundNumber << "/3 ~~~";

    for (int i = 0; i < 10; i++) {
        turn();
    }

    CardCollection player1Tableau = player1->getTableau();
    CardCollection player2Tableau = player2->getTableau();

    std::cout << "~~~ end of round scoring ~~~\n";
    std::cout << "player " << player1->getName() << " round score: " << player1->calcScoreForRound(player1Tableau, player2Tableau) << "\n";
    std::cout << "player " << player2->getName() << " round score: " << player2->calcScoreForRound(player2Tableau, player1Tableau) << "\n";

    //clear both tableaus and both hands
    hand1.clear();
    hand2.clear();
    player1->clearTableau();
    player2->clearTableau();
}

