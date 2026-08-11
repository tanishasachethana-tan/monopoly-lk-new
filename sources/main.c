#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "board.h"
#include "dice.h"
#include "players.h"
#include "game.h"

int main(){
  printf("==========================\n%s\n==========================\n", "  MONOPOLY-LK Simulation");
  printf("Player 1 : Aggresive Investor\nPlayer 2 : Conservative Banker\nPlayer 3 : Risk Taker\nPlayer 4 : Opportunistic Trader\n\nEach player begins with LKR 30,000\n\n");
    boardin(board); //board initialization
       
       //printf("                      dice value\n");
      Player players[4];
      playerinfo(players);//player initialization
      
      order_decide(players);

      initialize_deck();
      Rcard_details(cards);

      
      initialize_Ndeck();
      Ncard_details(Ncards);
      

      game_play(players,board,cards,Ncards);
      
    
      
     
         
 }        
       
       
     