#include "Game.h"

Game::Game() {

    Deck* deck = new Deck{};
    deck->populateDeck();
    deck->shuffle();

    _player1 = new Player{};
    _player2 = new Player{};

    CardCollection gameCards = deck->getCards();

    //loop three times, one for each round of the game
    for (int i = 0; i < 3; i++) {
        ++_roundNumber;
        // Remove 10 cards from deck and add them to hand1
        for (int i = 0; i < 10; i++) {
            _hand1.push_back(gameCards.back());
            gameCards.pop_back();
        }

        // Remove 10 more cards from deck and add them to hand2
        for (int i = 0; i < 10; i++) {
            _hand2.push_back(gameCards.back());
            gameCards.pop_back();
        }
        round();
    }

    std::string winnerMessage = printWinner(_player1, _player2);
    std::cout << winnerMessage;

    // clean up hand memory
    for (Card* card : _hand1) {
        delete card;
    }
    
    for (Card* card : _hand2) {
        delete card;
    }

    // clean up deck and player memory
    delete deck;
    delete _player1;
    delete _player2;
    // exit the program
    exit(0);
}

//prints the winner at the end of the game
std::string Game::printWinner(Player* p1, Player* p2) const{

    std::cout << "~~~ End of game! ~~~\n";
    std::cout << "   PLAYER " << p1->getName() << " final score: " << p1->getScore() << "\n";
    std::cout << "   PLAYER " << p2->getName() << " final score: " << p2->getScore() << "\n";

    if (p1->getScore() > p2->getScore()) {
        return "PLAYER " + p1->getName() + " WINS!\n";
    }

    else if (p1->getScore() < p2->getScore()) {
        return "PLAYER " + p2->getName() + " WINS!\n";
    }

    else {
        return "The game is a draw!";
    }

}

//performs all tasks in a turn 
void Game::turn() {
    
    std::cout << "PLAYER " << _player1->getName() << " TURN\n";
    std::cout << "Tableau: \n";

    CardCollection player1Tableau = _player1->getTableau();

    //print current player1 tableau
    for (Card* ptr : player1Tableau) {
        std::cout << ptr->str() << "\n";
    }

    std::cout << "Current hand: \n";

    int hand1Counter = 1;

    //output card number and each card in hand1
    for (Card* ptr : _hand1) {
        std::cout << hand1Counter << ". " << ptr->str() << "\n";
        ++hand1Counter;
    }

    std::cout << "Select a card to add to your tableau: \n";

    int player1Input;
    std::cin >> player1Input;

    //player1 input validation 
    while (player1Input > _hand1.size() || player1Input <= 0 || std::cin.fail()) {
        std::cout << "Select a card to add to your tableau: \n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> player1Input;
    }

    //after validation add selected card to tableau
    Card* c1 = _hand1.at(player1Input - 1);
    _player1->addCardToTableau(c1, _hand1);

    std::cout << "PLAYER " << _player2->getName() << " TURN \n";
    std::cout << "Tableau: \n";

    CardCollection player2Tableau = _player2->getTableau();

    for (Card* ptr : player2Tableau) {
        std::cout << ptr->str() << "\n";
    }

    std::cout << "Current hand: \n";

    int hand2Counter = 1;

    //output card number and each card in hand2
    for (Card* ptr : _hand2) {
        std::cout << hand2Counter << ". " << ptr->str() << "\n";
        ++hand2Counter;
    }

    std::cout << "Select a card to add to your tableau: \n";

    int player2Input;
    std::cin >> player2Input;

    //player2 input validation 
    while (player2Input > _hand2.size() || player1Input <= 0 || std::cin.fail()) {
        std::cout << "Select a card to add to your tableau: \n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> player2Input;
    }

    //after validation add selected card to tableau
    Card* c2 = _hand2.at(player2Input - 1);
    _player2->addCardToTableau(c2, _hand2);

    // Create new CardCollection vectors
    CardCollection copy1;
    CardCollection copy2;

    // Copy the contents of the original hands to new hands
    copy1.assign(_hand1.begin(), _hand1.end());
    copy2.assign(_hand2.begin(), _hand2.end());

    _hand1.assign(copy2.begin(), copy2.end());
    _hand2.assign(copy1.begin(), copy1.end());
}

void Game::round() {

    std::cout << "~~~ round " << _roundNumber << "/3 ~~~\n";

    // ten turns per round
    for (int i = 0; i < 10; i++) {
        turn();
    }

    // after all turns complete, get tableaus 
    CardCollection player1Tableau = _player1->getTableau();
    CardCollection player2Tableau = _player2->getTableau();

    //calculate end of round scoring
    std::cout << "~~~ end of round scoring ~~~\n";
    std::cout << "   PLAYER " << _player1->getName() << " round score: " << _player1->calcScoreForRound(player1Tableau, player2Tableau) << "\n";
    std::cout << "   PLAYER " << _player2->getName() << " round score: " << _player2->calcScoreForRound(player2Tableau, player1Tableau) << "\n\n";

    //end of round, so clear both tableaus and both hands
    _hand1.clear();
    _hand2.clear();
    _player1->clearTableau();
    _player2->clearTableau();
}

