#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include"../include/BoardGame_Classes.hpp"

using namespace std;

// Set the board
_5x5_X_O_Board::_5x5_X_O_Board() {
      n_rows = n_cols = 5;
      board = new char*[n_rows];
      for (int i = 0; i < n_rows; i++) {
         board [i] = new char[n_cols];
         for (int j = 0; j < n_cols; j++)
              board[i][j] = 0;
        }
}
/////////////////////////////////////////////////////

bool _5x5_X_O_Board::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 5 || y < 0 || y > 5) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}
////////////////////////////////////////////////////////
void _5x5_X_O_Board::display_board(){
    for (int i: {0,1,2,3,4}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

bool _5x5_X_O_Board::is_winner()  {
    int Row_X = 0, Row_O = 0, Col_X = 0, Col_O = 0, Diag_X = 0, Diag_O = 0;
    int sum_X=0;
    int sum_O=0;

    // Rows
    // X_O Rows
    // for X
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'X' && board[i][j + 1] == 'X' && board[i][j + 2] == 'X') {
                Row_X++;
            } else if (board[i][j] == 'O' && board[i][j + 1] == 'O' && board[i][j + 2] == 'O') {
                Row_O++;
            }
        }
    }

    // X_O Columns
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            if (board[j][i] == 'X' && board[j + 1][i] == 'X' && board[j + 2][i] == 'X') {
                Col_X++;
            } else if (board[j][i] == 'O' && board[j + 1][i] == 'O' && board[j + 2][i] == 'O') {
                Col_O++;
            }
        }
    }

    // X_O diagonals
    // 2 main diagonals
    for (int i = 0; i < 2; i++) {
        if (board[i][i] == 'X' && board[i + 1][i + 1] == 'X' && board[i + 2][i + 2] == 'X') {
            Diag_X++;
        } else if (board[i][i] == 'O' && board[i + 1][i + 1] == 'O' && board[i + 2][i + 2] == 'O') {
            Diag_O++;
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 4; j >= 2; j--) {
            if (board[i][j] == 'X' && board[i + 1][j - 1] == 'X' && board[i + 2][j - 2] == 'X') {
                Diag_X++;
            } else if (board[i][j] == 'O' && board[i + 1][j - 1] == 'O' && board[i + 2][j - 2] == 'O') {
                Diag_O++;
            }
        }
    }
// for X
// above right main diagonal
    if (board[0][1] =='X'&& board[1][2] =='X'&& board[2][3] == 'X' )Diag_X++;
    if ( board[1][2] =='X'&& board[2][3] =='X' &&board[3][4] == 'X') Diag_X++;
    if (board[0][2] =='X'&& board[1][3] =='X'&& board[2][4] == 'X') Diag_X++;
// below right main diagonal
    if (board[1][0] =='X'&& board[2][1] =='X'&& board[3][2] == 'X' )Diag_X++;
    if (board[2][1] =='X'&& board[3][2] =='X'&& board[4][3] == 'X') Diag_X++;
    if (board[2][0] =='X'&& board[3][1] =='X'&& board[4][2] == 'X') Diag_X++;

// for O
// above right main diagonal
    if (board[0][1] =='O'&& board[1][2] =='O'&& board[2][3] == 'O')Diag_O++;
    if (board[1][2] =='O'&& board[2][3] =='O'&& board[3][4] == 'O') Diag_O++;
    if (board[0][2] =='O'&& board[1][3] =='O'&& board[2][4] == 'O') Diag_O++;
// below right main diagonal
    if (board[1][0] =='O'&& board[2][1] =='O'&& board[3][2] == 'O' )Diag_O++;
    if(board[2][1] =='O'&& board[3][2] =='O'&& board[4][3] == 'O') Diag_O++;
    if (board[2][0] =='O'&& board[3][1] =='O'&& board[4][2] == 'O') Diag_O++;

///////////////////////////////////////////////////////////////////////////

// for X
// above left main diagonal
    if (board[0][3] =='X'&& board[1][2] =='X'&& board[2][1] == 'X') Diag_X++;
    if(board[1][2] =='X'&& board[2][1] =='X'&& board[3][0] == 'X') Diag_X++;
    if (board[0][2] =='X'&& board[1][1] =='X'&& board[2][0] == 'X') Diag_X++;
// below left main diagonal
    if (board[1][4] =='X'&& board[2][3] =='X'&& board[3][2] == 'X')Diag_X++;
    if (board[2][3] =='X'&& board[3][2] =='X'&& board[4][1] == 'X') Diag_X++;
    if (board[2][4] =='X'&& board[3][3] =='X'&& board[4][2] == 'X') Diag_X++;

// for O
// above left main diagonal
    if (board[0][3] =='O'&& board[1][2] =='O'&& board[2][1] == 'O' ) Diag_O++;
    if (board[1][2] =='O'&& board[2][1] =='O'&& board[3][0] == 'O') Diag_O++;
    if (board[0][2] =='O'&& board[1][1] =='O'&& board[2][0] == 'O') Diag_O++;
// below left main diagonal
    if (board[1][4] =='O'&& board[2][3] =='O'&& board[3][2] == 'O' )Diag_O++;
    if ( board[2][3] =='O'&& board[3][2] =='O'&& board[4][1] == 'O') Diag_O++;
    if (board[2][4] =='O'&& board[3][3] =='O'&& board[4][2] == 'O') Diag_O++;
    sum_X=Row_X+Col_X+Diag_X;
    sum_O=Row_O+Col_O+Diag_O;
    if (n_moves==24){
        if (sum_X> sum_O || sum_X < sum_O) {
            cout << "Player "<< (sum_X> sum_O? 'X' : 'O') << " wins!\n";
        } else if (sum_X == sum_O) {
            cout << "draw!"<<endl;
        }
    }

    return false;
}
bool _5x5_X_O_Board::is_draw() {
    return (n_moves == 24&&is_winner());
}

bool _5x5_X_O_Board::game_is_over () {
    return n_moves >= 24;
}
