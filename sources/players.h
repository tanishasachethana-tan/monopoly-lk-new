#ifndef PLAYERS_H
#define PLAYERS_H   

typedef struct {
    char name[50];
    int total_money;
    int current_position;
    int dicevalue;
    int bankrupt;
    int rank;
    //int properties[40]; // Array to hold property ownership 
} Player;


extern Player players[4]; 
void playerinfo(Player players[4]);
int move_player(Player players[4], int dicevalue);
int bankrupt_check(Player players[4]);
int bankrupt_count(Player players[4]);

#endif // PLAYERS_H

