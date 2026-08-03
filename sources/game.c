#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "players.h"
#include "dice.h"
#include "board.h"

void game_play(Player players[4]) {
    printf("\n\n**Game Starts!**\n\n");
    // game loop
    int round = 1;
    while(round<=5 && bankrupt_count(players)<3){
      printf("\n**Round %d\n\n", round);
      for(int r=1; r<=4; r++){
       for(int i=0;i<4;i++){
         if(players[i].rank==r && players[i].bankrupt==0){
                    printf("\n%s's turn\n", players[i].name);
                    printf("------------\n");
                    
             players[i].dicevalue=roll_dice();
            
            printf("%s rolled %d\n\n", players[i].name, players[i].dicevalue);
            // move player
            int previous_position=players[i].current_position;
            
            players[i].current_position+=players[i].dicevalue;
            
            if(players[i].current_position>=40){
                players[i].current_position-=40;
                players[i].total_money+=2000;
                printf("%s passed GO\nCollected LKR 2000\nCurrent Balance: LKR %d\n\n",players[i].name,players[i].total_money);
            }

            printf("%s moves from Square %d to Square %d(%s)\n\n",players[i].name,previous_position,players[i].current_position,board[players[i].current_position].name);

            property_purchase(players, board, i, players[i].current_position);
            pay_rent(players, board, i, players[i].current_position);

            
         }
       
        }

     }
     
     printf("===================\nRound %d Summary\n===================\n\n",round);
     for(int i=0;i<4;i++){
        printf("**%s\n\nCash : LKR %d\n\n",players[i].name,players[i].total_money);
        printf("Properties : %d\n\n",players[i].property_count);
     }
    round++;
    }
    
    printf("=======================\n\n*End of Game\n\n=======================\n\n");
    printf("GAME OVER\n\nWinner\n\n");
    
}   