#include <stdio.h> 
#include <string.h>
#include "players.h"
#include "dice.h"


void playerinfo(Player players[]){
     
    strcpy(players[0].name, "Aggresive Investor");
    players[0].total_money = 30000;
    players[0].current_position = 0;
    players[0].dicevalue = 0;
    players[0].bankrupt = 0;

    strcpy(players[1].name, "Conservative Banker");
    players[1].total_money = 30000;
    players[1].current_position = 0;
    players[1].dicevalue = 0;
    players[1].bankrupt = 0;

    strcpy(players[2].name, "Risk Taker");
    players[2].total_money = 30000;
    players[2].current_position = 0;
    players[2].dicevalue = 0;
    players[2].bankrupt = 0;

    strcpy(players[3].name, "Opportunistic Trader");
    players[3].total_money = 30000;
    players[3].current_position = 0;
    players[3].dicevalue = 0;
    players[3].bankrupt = 0;

}

int bankrupt_check(Player players[4]){
    for(int i=0;i<4;i++){
        if(players[i].total_money<=0){
            players[i].bankrupt=1;
           // printf("\n%s is bankrupt!\n",players[i].name);
        }
        return 0;
    }
}

int bankrupt_count(Player players[4]){
    int count=0;
    for(int i=0;i<4;i++){
        if(players[i].bankrupt==1){
            count++;
        }
    }
    return count;
}

int move_player(Player players[4],int dicevalue){
    int i;
    for(i=0;i<4;i++){
    players[i].current_position+=players[i].dicevalue;

}
}

//void move_player(Player *player, int dice_value){
   // player->current_position += dice_value;
//}

/*int position_1(Player current_position, int dice_value){
    players[0].current_position += dice_value;
    return players[0].current_position;
}
int position_2(Player current_position, int dice_value){
    players[1].current_position += dice_value;
    return players[1].current_position;
}
int position_3(Player current_position, int dice_value){
    players[2].current_position += dice_value;
    return players[2].current_position;
}
int position_4(Player current_position, int dice_value){
    players[3].current_position += dice_value;
    return players[3].current_position;
}
*/
