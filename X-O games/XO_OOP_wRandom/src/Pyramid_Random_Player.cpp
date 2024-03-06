#include "iostream"
#include "../include/BoardGame_Classes.hpp"
#include "algorithm"
using namespace std;
Pyramid_Tic_Tac_RandomPlayer::Pyramid_Tic_Tac_RandomPlayer(char symbol, int dimension, int dimension2) : RandomPlayer(symbol,dimension) {
    this->dimension=dimension;
    this->dimension2=dimension2;
    this->name ="WELCOME,Iam random computer player iwill play against you";
    cout<<name<<"\n";
}

void Pyramid_Tic_Tac_RandomPlayer::get_move(int &x, int &y) {

while(true){
    x = (int)(rand()/(RAND_MAX+1.0)*dimension);
    y = (int)(rand()/(RAND_MAX+1.0)*dimension2);
 if((x==0&&y==2)||x==1&&(y==1||y==2||y==3)||(x==2)&&(y==0||y==1||y==2||y==3||y==4)){
     break;
 }
}
}
