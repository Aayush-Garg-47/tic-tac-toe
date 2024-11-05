#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void initializeBoard(vector<char>& board) {
    for (int i = 0; i < 9; ++i) {
        board[i] = ' ';
    }
}

void printBoard(const vector<char>& board) {
    cout << "\nTic-Tac-Toe Board:\n\n";
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << " \n";
    cout << "---|---|---\n";
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << " \n\n";
}

bool checkWin(const vector<char>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i*3] == player && board[i*3 + 1] == player && board[i*3 + 2] == player) {
            return true;
        }
        if (board[i] == player && board[i + 3] == player && board[i + 6] == player) {
            return true;
        }
    }
    if (board[0] == player && board[4] == player && board[8] == player) {
        return true;
    }
    if (board[2] == player && board[4] == player && board[6] == player) {
        return true;
    }
    return false;
}
bool isBoardFull(const vector<char>& board) {
    for (int i = 0; i < 9; ++i) {
        if (board[i] == ' ') {
            return false;
        }
    }
    return true;
}
bool makeMove(vector<char>& board, int move, char player) {
    if (move >= 1 && move <= 9 && board[move - 1] == ' ') {
        board[move - 1] = player;
        return true;
    }
    return false;
}

int main() {
    vector<char> board(9);
    char player = 'X';
    int move;
    bool validMove;
    
    initializeBoard(board);
    while (true) {
        printBoard(board);
        
        cout << "Player " << player << ", enter your move (1-9): ";
        
        while (true) {
            cin >> move;
            if (cin.fail() || move < 1 || move > 9 || board[move - 1] != ' ') {
                cout << "Invalid move. Please enter a number between 1 and 9, corresponding to an empty cell: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                break;
            }
        }
        
        validMove = makeMove(board, move, player);

        if (checkWin(board, player)) {
            printBoard(board);
            cout << "Player " << player << " wins!" << endl;
            break;
        }

        if (isBoardFull(board)) {
            printBoard(board);
            cout << "It's a tie!" << endl;
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
