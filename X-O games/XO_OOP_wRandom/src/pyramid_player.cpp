
#include"../include/Pyramid_tic_tac._classes.h"
#include "../src/player.cpp"
#include "iostream"
using namespace std;
using namespace std;
// give the symbol to player class

Pyramid_Tic_Tac_Player::Pyramid_Tic_Tac_Player(char symbol):Player(symbol) {
    this->symbol=symbol;

}
//make player enter his number if there are two player
Pyramid_Tic_Tac_Player::Pyramid_Tic_Tac_Player(int order,char symbol): Player(symbol) {
    cout<<" HELLO ,player "<<order<<"\n";
    cout<<"Pls,enter your name "<<" ";
    getline(cin,name);
    this->symbol=symbol;
}
// we will take number of move which x from 0 to 2 and y from 0 to 4
void Pyramid_Tic_Tac_Player::get_move(int &x, int &y) {
    cout<<"---------------------\n";
    cout<<"please enter your next move and take care that x from 0 to 2 and y from 0 to 4 the cells {(0,0),(0,1),(0,3),(0,4),(1,0),(1,4)} are forbiden cells\n";
cin>>x>>y;

}
// to return user eith his name and informaton
string Pyramid_Tic_Tac_Player::to_string() {
    return "welcome player "+ name+" happy that you choose the pyramid_Tic_Tac\n "
                                   "---------------------The rules---------------------------\n"
                                   "you need to win to get three consective cells with same symbol diagonally,virtucally,hortiontially\n";
}

char Pyramid_Tic_Tac_Player::get_symbol() {
return symbol;
}
//int main(){
//    Pyramid_Tic_Tac_Player p1(1,'X');
//    cout<<p1.info_string();
//}
