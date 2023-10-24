#include <iostream>
#include <vector>

class TicTacToe {
public:
    TicTacToe() : board(3, std::vector<char>(3, ' ')), currentPlayer('X') {}

    void play() {
        int row, col;
        bool validMove = false;
        int moves = 0;

        while (true) {
            displayBoard();

            std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            std::cin >> row >> col;

            if (isValidMove(row, col)) {
                makeMove(row, col);
                validMove = true;
                moves++;
            } else {
                std::cout << "Invalid move. Try again." << std::endl;
            }

            if (checkWin(row, col)) {
                displayBoard();
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
                break;
            } else if (moves == 9) {
                displayBoard();
                std::cout << "It's a draw!" << std::endl;
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

private:
    std::vector<std::vector<char>> board;
    char currentPlayer;

    void displayBoard() {
        std::cout << "Tic-Tac-Toe" << std::endl;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << board[i][j];
                if (j < 2) std::cout << " | ";
            }
            std::cout << std::endl;
            if (i < 2) std::cout << "---------" << std::endl;
        }
        std::cout << std::endl;
    }

    bool isValidMove(int row, int col) {
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ')
            return true;
        return false;
    }

    void makeMove(int row, int col) {
        board[row][col] = currentPlayer;
    }

    bool checkWin(int row, int col) {
        if (board[row][0] == currentPlayer && board[row][1] == currentPlayer && board[row][2] == currentPlayer)
            return true;

        if (board[0][col] == currentPlayer && board[1][col] == currentPlayer && board[2][col] == currentPlayer)
            return true;

        if (row == col && board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (row + col == 2 && board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;

        return false;
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}
