#ifndef PLAYERS_H
#define PLAYERS_H 

#include "board.h"

typedef struct {
    char name[50];
    int player_id;
    int total_money;
    int current_position;
    int dicevalue;
    int bankrupt;
    int rank;
    int property_count;
    //int properties[40]; // Array to hold property ownership 
} Player;


extern Player players[4]; 
void playerinfo(Player players[4]);
int move_player(Player players[4], int dicevalue);
int bankrupt_check(Player players[4]);
int bankrupt_count(Player players[4]);
int monopoly(Player players[4],Square board[40],int player_index,int current_position);

int property_purchase(Player players[4],Square board[40],int player_index,int current_position);
int pay_rent(Player players[4],Square board[40],int player_index,int current_position);
int construction(Player players[4],Square board[40],int player_index,int current_position);


#endif // PLAYERS_H

