#include <iostream>
#include <vector>
#include <limits> // For numeric_limits
#include <cstdlib> // For exit

using namespace std;

class TicTacToe {
private:
    vector<vector<char>> board; // Game board represented as a 2D vector
    vector<char> players;       // Vector to store player symbols
    int currentPlayer;          // Index of the current player in the players vector

public:
    // Constructor to initialize the game board and players
    TicTacToe(int rows, int cols, const vector<char>& playerSymbols)
        : board(rows, vector<char>(cols, ' ')), players(playerSymbols), currentPlayer(0)
    {
        // Validate number of player symbols matches number of players
        if (players.size() < 2) {
            cerr << "Error: At least two player symbols are required." << endl;
            exit(EXIT_FAILURE);
        }
    }

    // Function to print the current state of the game board
    void printBoard()
    {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                cout << board[i][j];
                if (j < board[i].size() - 1) {
                    cout << " | "; // Separate cells within a row
                }
            }
            cout << endl;
            if (i < board.size() - 1) {
                for (int k = 0; k < board[i].size() * 4 - 1; ++k) {
                    cout << "-";
                }
                cout << endl; // Separate rows with a horizontal line
            }
        }
    }

    // Function to check if the game board is fully occupied (no empty spaces left)
    bool isBoardFull() const
    {
        for (const auto& row : board) {
            for (char cell : row) {
                if (cell == ' ') {
                    return false; // Board is not full if any empty space is found
                }
            }
        }
        return true; // Board is full if no empty spaces are found
    }

    // Function to make a move at a specified row and column by the current player
    bool makeMove(int row, int col)
    {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != ' ') {
            return false; // Invalid move if out of bounds or cell already occupied
        }
        board[row][col] = players[currentPlayer]; // Place player's symbol on the board
        currentPlayer = (currentPlayer + 1) % players.size(); // Switch to the next player
        return true; // Move successful
    }

    // Function to check if any player has won the game
    bool checkWinner() const
    {
        char currentSymbol;

        // Check rows for a win
        for (int i = 0; i < board.size(); ++i) {
            currentSymbol = board[i][0];
            if (currentSymbol != ' ') {
                bool rowWin = true;
                for (int j = 1; j < board[i].size(); ++j) {
                    if (board[i][j] != currentSymbol) {
                        rowWin = false;
                        break;
                    }
                }
                if (rowWin) {
                    return true; // Row win
                }
            }
        }

        // Check columns for a win
        for (int j = 0; j < board[0].size(); ++j) {
            currentSymbol = board[0][j];
            if (currentSymbol != ' ') {
                bool colWin = true;
                for (int i = 1; i < board.size(); ++i) {
                    if (board[i][j] != currentSymbol) {
                        colWin = false;
                        break;
                    }
                }
                if (colWin) {
                    return true; // Column win
                }
            }
        }

        // Check diagonals for a win (if board is square)
        if (board.size() == board[0].size()) {
            // Check main diagonal (top-left to bottom-right)
            currentSymbol = board[0][0];
            if (currentSymbol != ' ') {
                bool mainDiagWin = true;
                for (int i = 1; i < board.size(); ++i) {
                    if (board[i][i] != currentSymbol) {
                        mainDiagWin = false;
                        break;
                    }
                }
                if (mainDiagWin) {
                    return true; // Main diagonal win
                }
            }

            // Check anti-diagonal (top-right to bottom-left)
            currentSymbol = board[0][board[0].size() - 1];
            if (currentSymbol != ' ') {
                bool antiDiagWin = true;
                for (int i = 1; i < board.size(); ++i) {
                    if (board[i][board[0].size() - 1 - i] != currentSymbol) {
                        antiDiagWin = false;
                        break;
                    }
                }
                if (antiDiagWin) {
                    return true; // Anti-diagonal win
                }
            }
        }

        return false; // No winner found
    }

    // Function to get the symbol of the current player
    char getCurrentPlayerSymbol() const
    {
        return players[currentPlayer];
    }
};

int main()
{
    // Define the board dimensions and player symbols
    int rows, cols;
    cout << "Enter number of rows and columns for the board: ";
    cin >> rows >> cols;

    int numPlayers;
    cout << "Enter number of players: ";
    cin >> numPlayers;

    vector<char> playerSymbols(numPlayers);
    cout << "Enter symbols for each player (e.g., X, O, A, B, etc.): ";
    for (int i = 0; i < numPlayers; ++i) {
        cin >> playerSymbols[i];
    }

    // Create TicTacToe game object with the specified board size and players
    TicTacToe game(rows, cols, playerSymbols);

    int row, col;

    // Game loop continues until the board is full or there's a winner
    while (!game.isBoardFull() && !game.checkWinner()) {
        game.printBoard(); // Display the current state of the board

        // Prompt the current player for a move
        cout << "Player " << game.getCurrentPlayerSymbol() << ", enter your move (row and column): ";
        cin >> row >> col;

        if (game.makeMove(row, col)) {
            cout << "Move successful!" << endl;
        }
        else {
            cout << "Invalid move. Try again." << endl;
            cin.clear(); // Clear error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        }
    }

    game.printBoard(); // Display the final state of the board

    // Determine the game result based on whether there's a winner or if it's a draw
    if (game.checkWinner()) {
        cout << "Player " << game.getCurrentPlayerSymbol() << " wins!" << endl;
    }
    else {
        cout << "It's a draw!" << endl;
    }

    return 0;
}
