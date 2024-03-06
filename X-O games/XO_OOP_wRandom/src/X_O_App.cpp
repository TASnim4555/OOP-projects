// Class definition for XO_App class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include <iostream>
#include"../include/BoardGame_Classes.hpp"
#include "Player.cpp"
#include "RandomPlayer.cpp"
#include "GameManager.cpp"
#include "Pyramid_Random_Player.cpp"
#include "Pyramid_Board.cpp"
#include "_5x5_X_O_Board.cpp"
using namespace std;

int main() {
    cout << "Welcome to FCAI X-O Game. :)\n";
cout <<"if you want to play ordinary X_O 3X3 press 1\n"<<"if you want to play Pyramid_Tic_Tac press 2\n"<<"if you want to play  Four-in-a-row press 3\n"<<"if you want to play5 x 5 Tic Tac Toe preaa 4 \n ";
   int number;
   cin>>number;
   if(number==1){
       int choice;
       Player* players[2];
       players[0] = new Player (1, 'x');

       cout << "Press 1 if you want to play with computer \n"<<"ans press2 if you want to play with another player\n";
       cin >> choice;
       if (choice ==2)
           players[1] = new Player (2, 'o');
       else if(choice==1)
           //Player pointer points to child
           players[1] = new RandomPlayer ('o', 3);

       GameManager x_o_game (new X_O_Board(), players);
       x_o_game.run();
       system ("pause");
   }
   else if(number==2){
       int choice;
       Player* players[2];
       players[0] = new Player (1, 'x');

       cout << "Press 1 if you want to play with computer: \n"<<"ans press2 if you want to play with another player:";
       cin >> choice;
       if (choice ==2)
           players[1] = new Player (2, 'o');
       else if(choice==1)
           //Player pointer points to child
           players[1] = new Pyramid_Tic_Tac_RandomPlayer ('o', 3,5);

       GameManager x_o_game (new Pyramid_Tic_Tac(), players);
       x_o_game.run();
       system ("pause");
   }
   else if(number ==3){
       int choice;
       Player *players[2];
       players[0] = new Player(1, 'x');

       cout << "Welcome to FCAI X-O Game. :)\n";
       cout << "Press 1 if you want to play with computer or 2 for two players: ";
       cin >> choice;
       if (choice != 1)
           players[1] = new Player(2, 'o');
       else
//Player pointer points to child
           players[1] = new Four_RandomPlayer('o', 6);

       GameManager Four_game(new Four_Board(), players);
       Four_game.Four_run();
       system("pause");
   }
   if(number==4){
        int choice;
        Player* players[2];
        players[0] = new Player (1, 'x');

        cout << "Press 1 if you want to play with computer \n"<<"Or press 2 if you want to play with another player\n";
        cin >> choice;
        if (choice ==2)
            players[1] = new Player (2, 'o');
        else if(choice==1)
            //Player pointer points to child
            players[1] = new RandomPlayer ('o', 5);

        GameManager x_o_game (new _5x5_X_O_Board(), players);
        x_o_game.run();
        system ("pause");
    }
}
