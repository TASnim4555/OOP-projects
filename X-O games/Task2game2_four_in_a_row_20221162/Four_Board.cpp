// Class definition for Four_in_a_row_Board class
// Author: Malak Hisham
// ID : 20221162
// Section : S7
// Date:    15/12/2023
// Version: 1
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include "include/BoardGame_Classes.hpp"
using namespace std;
// set the board
Four_Board::Four_Board(){
    n_rows = 6;
    n_cols =7;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
};
// Display the board and the pieces on it
void Four_Board::display_board() {
    for (int i: {0,1,2,3,4,5}) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4,5,6}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}
// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool Four_Board::update_board (int x, int y, char mark){
    // Only update if move is valid
    if (!(x < 0 || x > 5 || y < 0 || y > 6) ) {
        for(int i =5;i>=x;i--) {
            if(board[i][y]==0) {
                board[i][y] = toupper(mark);
                n_moves++;
                return true;
            }
        }
        return false;
    }
    else
        return false;
}
// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
bool Four_Board::is_winner() {
    char   diag_win[24];
    vector <char> row_win,col_win;
    for (int i=0;i<6;i++) {
        row_win.push_back(board[i][0] & board[i][1] & board[i][2] & board[i][3]);
        row_win.push_back(board[i][1] & board[i][2] & board[i][3] & board[i][4]);
        row_win.push_back(board[i][2] & board[i][3] & board[i][4] & board[i][5]);
        row_win.push_back(board[i][3] & board[i][4] & board[i][5] & board[i][6]);

        col_win.push_back(board[0][i] & board[1][i] & board[2][i] & board[3][i]);
        col_win.push_back(board[1][i] & board[2][i] & board[3][i] & board[4][i]);
        col_win.push_back(board[2][i] & board[3][i] & board[4][i] & board[5][i]);
    }
    diag_win[0] =board[2][0] & board[3][1] & board[4][2] & board[5][3] ;
    diag_win[1] =board[1][0] & board[2][1] & board[3][2] & board[4][3] ;
    diag_win[2] =board[2][1] & board[3][2] & board[4][3] &board[5][4]  ;
    diag_win[3] =board[0][0] & board[1][1] & board[2][2] &board[3][3]  ;
    diag_win[4] = board[1][1] & board[2][2] &board[3][3]& board[4][4]  ;
    diag_win[5] = board[2][2] &board[3][3] &board[4][4] & board[5][5]   ;

    diag_win[6] = board[0][1] &board[1][2] &board[2][3] & board[3][4]   ;
    diag_win[7] = board[1][2] &board[2][3] & board[3][4] &board[4][5]   ;

    diag_win[8] = board[2][3] & board[3][4]  &board[4][5] &board[5][6]  ;

    diag_win[9] = board[0][2] & board[1][3]  &board[2][4] &board[3][5]  ;
    diag_win[10] =board[1][3]  &board[2][4] &board[3][5] & board[4][6]   ;

    diag_win[11] = board[0][3] & board[1][4]  &board[2][5] &board[3][6]  ;



    diag_win[12] =board[2][6] & board[3][5] & board[4][4] & board[5][3] ;
    diag_win[13] =board[1][6] & board[2][5] & board[3][4] & board[4][3] ;
    diag_win[14] =board[2][5] & board[3][4] & board[4][3] &board[5][2]  ;
    diag_win[15] =board[0][6] & board[1][5] & board[2][4] &board[3][3]  ;
    diag_win[16] = board[1][5] & board[2][4] &board[3][3]& board[4][2]  ;
    diag_win[17] = board[2][4] &board[3][3] &board[4][2] & board[5][1]   ;

    diag_win[18] = board[0][5] &board[1][4] &board[2][3] & board[3][2]   ;
    diag_win[19] = board[1][4] &board[2][3] & board[3][2] &board[4][1]   ;

    diag_win[20] = board[2][3] & board[3][2]  &board[4][1] &board[5][0]  ;

    diag_win[21] = board[0][4] & board[1][3]  &board[2][2] &board[3][1]  ;
    diag_win[22] =board[1][3]  &board[2][2] &board[3][1] & board[4][0]   ;

    diag_win[23] = board[0][3] & board[1][2]  &board[2][1] &board[3][0]  ;


    for (int i=0;i<6;i++) {
        if  (row_win[i*4] && (row_win[i*4] == board[i][0]))
            return true;
        if  (row_win[(i*4)+1] && (row_win[(i*4)+1] == board[i][1]))
            return true;
        if  (row_win[(i*4)+2] && (row_win[(i*4)+2] == board[i][2]))
            return true;
        if  (row_win[(i*4)+3] && (row_win[(i*4)+3] == board[i][3]))
            return true;
    }
    for (int i=0;i<7;i++) {
        if  (col_win[i*3] && (col_win[i*3] == board[0][i]))
            return true;
        if  (col_win[(i*3)+1] && (col_win[(i*3)+1] == board[1][i]))
            return true;
        if  (col_win[(i*3)+2] && (col_win[(i*3)+2] == board[2][i]))
            return true;
        if  (col_win[(i*3)+3] && (col_win[(i*3)+3] == board[3][i]))
            return true;
    }
    if ((diag_win[0] && diag_win[0] == board[2][0]) ||
        (diag_win[1] && diag_win[1] == board[1][0]) ||
        (diag_win[2] && diag_win[2] == board[2][1]) ||
        (diag_win[3] && diag_win[3] == board[0][0]) ||
        (diag_win[4] && diag_win[4] == board[1][1]) ||
        (diag_win[5] && diag_win[5] == board[2][2]))
    {return true;}
    if ((diag_win[6] && diag_win[6] == board[0][1]) ||
        (diag_win[7] && diag_win[7] == board[1][2]) ||
        (diag_win[8] && diag_win[8] == board[2][3]) ||
        (diag_win[9] && diag_win[9] == board[0][2]) ||
        (diag_win[10] && diag_win[10] == board[1][3]) ||
        (diag_win[11] && diag_win[11] == board[0][3]))
    {return true;}
    if ((diag_win[12] && diag_win[12] == board[2][6]) ||
        (diag_win[13] && diag_win[13] == board[1][6]) ||
        (diag_win[14] && diag_win[14] == board[2][5]) ||
        (diag_win[15] && diag_win[15] == board[0][6]) ||
        (diag_win[16]&& diag_win[16] == board[1][5]) ||
        (diag_win[17] && diag_win[17] == board[2][4]))
    {return true;}
    if ((diag_win[18] && diag_win[18] == board[0][5]) ||
        (diag_win[19] && diag_win[19] == board[1][4]) ||
        (diag_win[20] && diag_win[20] == board[2][3]) ||
        (diag_win[21] && diag_win[21] == board[0][4]) ||
        (diag_win[22]&& diag_win[22] == board[1][3]) ||
        (diag_win[23] && diag_win[23] == board[0][3]))
    {return true;}
    return false;
}
bool Four_Board::is_draw() {
    return (n_moves == 42 && !is_winner());
}

bool Four_Board::game_is_over () {
    return n_moves >= 42;
}