#include <iostream>
#include <vector>
#include <random>
#include <string>
class Player {
   public:
       std::string name;
       int position;
       int moves;
       Player(std::string n) {
           name = n;
           position = 0;
           moves = 0;
       }
       int rollDice() {
           std::random_device rd;
           std::mt19937 gen(rd());
           std::uniform_int_distribution<> dis(1, 6);
           return dis(gen);
       }
       void move(int spaces) {
           position += spaces;
           moves++;
       }
};
class Board {
   public:
       int size;
       std::vector<int> playerPositions;
       std::vector<int> snakePositions;
       std::vector<int> ladderPositions;
       Board(int s) {
           size = s;
       }
       void movePlayer(Player &p, int roll) {
           int newPos = p.position + roll;
           if (newPos > size) {
               return;
           }
           for (int i = 0; i < ladderPositions.size(); i += 2) {
               if (newPos == ladderPositions[i]) {
                   newPos = ladderPositions[i + 1];
                   break;
               }
           }
           for (int i = 0; i < snakePositions.size(); i += 2) {
               if (newPos == snakePositions[i]) {
newPos = snakePositions[i + 1];
                     break;
               }
           }
           p.position = newPos;
       }
       bool checkWinner(Player &p) {
           if (p.position == size) {
               std::cout << p.name << " wins!" << std::endl;
               return true;
           }
           return false;
       }
};
class Game {
   public:
       Board board;
       std::vector<Player> players;
       std::vector<std::pair<int, int>> snakes;
       std::vector<std::pair<int, int>> ladders;
       Game(int boardSize, std::vector<std::string> playerNames, std::vector<std::pair<int, int>> s, std::vector<std::pair<int, int>> l) : board(boardSize) {
           for (int i = 0; i < playerNames.size(); i++) {
               players.push_back(Player(playerNames[i]));
           }
           snakes = s;
           ladders = l;
           initializeBoard();
       }
       void initializeBoard() {
           for (int i = 0; i < snakes.size(); i++) {
               board.snakePositions.push_back(snakes[i].first);
               board.snakePositions.push_back(snakes[i].second);
                           }
           for (int i = 0; i < ladders.size(); i++) {
               board.ladderPositions.push_back(ladders[i].first);
               board.ladderPositions.push_back(ladders[i].second);
           }
       }
       void play() {
           while (true) {
               for (int i = 0; i < players.size(); i++) {
                   int roll = players[i].rollDice();
                   std::cout << players[i].name << " rolled a " << roll << std::endl;
                   board.movePlayer(players[i], roll);
                   std::cout << players[i].name << " is now on square " << players[i].position << std::endl;
                   if (board.checkWinner(players[i])) {
                       return;
                   }
               }
           }
       }
};
int main() {
   std::vector<std::string> playerNames = {"Player 1", "Player 2"};
   std::vector<std::pair<int, int>> snakes = {{17, 7}, {54, 34}};
   std::vector<std::pair<int, int>> ladders = {{62, 81}, {87, 96}};
   Game game(100, playerNames, snakes, ladders);
   game.play();
   return 0;
}