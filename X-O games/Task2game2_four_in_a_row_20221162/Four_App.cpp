// Class definition for Four_in_a_row_App class
// Author: Malak Hisham
// ID : 20221162
// Section : S7
// Date:    15/12/2023
// Version: 1
#include <iostream>
#include"include/BoardGame_Classes.hpp"

using namespace std;
int main() {
    int choice;
    Player *players[2];
    players[0] = new Player(1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player(2, 'o');
    else
//Player pointer points to child
        players[1] = new RandomPlayer('o', 6);

    GameManager Four_game(new Four_Board(), players);
    Four_game.run();
    system("pause");
}