#include <iostream>
using namespace std;

char board[3][3];

void initBoard() {
    char ch = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ch++;
}

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool checkWin(char mark) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == mark && board[i][1] == mark && board[i][2] == mark)
            return true;
        if (board[0][i] == mark && board[1][i] == mark && board[2][i] == mark)
            return true;
    }

    if (board[0][0] == mark && board[1][1] == mark && board[2][2] == mark)
        return true;
    if (board[0][2] == mark && board[1][1] == mark && board[2][0] == mark)
        return true;

    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

int main() {
    char currentPlayer = 'X';
    int move;

    initBoard();

    cout << "===== Tic Tac Toe Game =====\n";

    while (true) {
        displayBoard();
        cout << "Player " << currentPlayer << ", enter your move: ";
        cin >> move;

        if (move < 1 || move > 9) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        int row = (move - 1) / 3;
        int col = (move - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Cell already occupied! Try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;

        if (checkWin(currentPlayer)) {
            displayBoard();
            cout << " Player " << currentPlayer << " wins!\n";
            break;
        }

        if (isDraw()) {
            displayBoard();
            cout << " Game Draw!\n";
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
