#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "players.h"
#include "dice.h"
#include "board.h"
#include "finance.h"
#include "cards.h"

extern int Ncard_duration[20];

void game_play(Player players[4],Square board[40],Regionalcards cards[12],Nationalcards Ncards[20]) {
    printf("\n\n**Game Starts!**\n\n");
    // game loop
    int last_summary_round = 0;
    int last_card_round = 0;

while(rounds_completed(players)<20 && bankrupt_count(players)<3){
       
      printf("DEBUG: %d %d %d %d\n",
       players[0].round_count,
       players[1].round_count,
       players[2].round_count,
       players[3].round_count);

      //printf("\n**Round %d\n\n", rounds_completed(players)+1);
      int current_round=rounds_completed(players) +1;

      printf("\n**Round %d\n\n", current_round);
         
     

printf("DEBUG STATUS:\n");
for(int i=0; i<4; i++){
    printf("%s | rank=%d | bankrupt=%d | round=%d\n",
           players[i].name,
           players[i].rank,
           players[i].bankrupt,
           players[i].round_count);
}

      for(int r=1; r<=4; r++){

         for(int i=0;i<4;i++){

         if(players[i].rank==r && players[i].bankrupt==0){
                    printf("\n%s's turn\n", players[i].name);
                    printf("------------\n");


                    printf("DEBUG PLAYER: %s | round=%d | jail=%d\n",
                      players[i].name,
                      players[i].round_count,
                      players[i].jail_in);

          
               
                    
          if(players[i].jail_in==1){
                  jail_escape(players,i);
               }

          if(players[i].jail_in==0){
                  players[i].dicevalue=roll_dice();
            
                  printf("%s rolled %d\n\n", players[i].name, players[i].dicevalue);
                 // move player
                int previous_position=players[i].current_position;
            
                players[i].current_position+=players[i].dicevalue;

         if(players[i].current_position == 30){
                   players[i].jail_in = 1;
                 }   


         if(players[i].current_position>=40){
                players[i].current_position-=40; 
                players[i].total_money+=2000; 
                players[i].round_count++;
               
                printf("%s passed GO\nCollected LKR 2000\nCurrent Balance: LKR %d\n\n",players[i].name,players[i].total_money);


                if(players[i].Ncard_remain > 0){
                  players[i].Ncard_remain--;

                  if(players[i].Ncard_remain==0){
                     
                       if(players[i].Ncard_id == 7 || players[i].Ncard_id == 8){
                           players[i].loan_interest= 0.08;
                       }
                       players[i].Ncard_id = -1;
                  }
                }

                if(players[i].construction_suspended > 0){
                     players[i].construction_suspended--;
                }
         } 
                
         printf("%s moves from Square %d to Square %d(%s)\n\n",players[i].name,previous_position,players[i].current_position,board[players[i].current_position].name); 
         property_purchase(players, board,cards,i, players[i].current_position); 
         pay_rent(players, board,cards,Ncards,i, players[i].current_position);


         if(board[players[i].current_position].type == event){
            int card_id = draw_Ncard();

            printf("%s drew National Event Card %d!\n",players[i].name, card_id);

            Ncard_activation(Ncards,players,i,card_id,Ncard_duration[card_id]);

            if(card_id == 2 || card_id == 3 || card_id == 4 || card_id == 5 || card_id == 6 || card_id == 7 || card_id == 8 || card_id == 9 ||card_id == 11 || card_id == 12 || card_id == 14 || card_id == 16 || card_id == 17 || card_id == 18 || card_id == 19){
               int rent = 0;
               apply_Ncard(players, board,players[i].current_position,i, &rent, card_id);
            }

           
            //int rent = 0;

            //apply_Ncard(players, board,players[i].current_position,i,&rent,card_id);
         }

         
      
            //FINANCE
            //loans
         if(players[i].current_position==board[38].id){
            if(players[i].player_id==0){
               Aggressive_investor_loan(players,board,players[i].current_position,i);
            }

            else if(players[i].player_id==1){
               conservative_banker_loan(players,board,players[i].current_position,i);
            }

            else if(players[i].player_id==2){

               if(players[i].outstanding_loan==0){
               risk_taker_loan(players,board,players[i].current_position,i);
              }
              else{
                refinancing_loan(players,board,i);
              }

            }

           // if(players[player_index].player_id==3){}

           //Loan settling
          
         }

         if(players[i].outstanding_loan > 0){
          
             loan_settling(players,board,i);
             
             loan_duration(players,board,i);
           }


            
           
            
            
         } //here ends jail in==0
      }

      
        }

     } 
       
     if(rounds_completed(players) > current_round - 1){
         loan_interest_cal(players);
     }
    
     int new_round = rounds_completed(players);

     if(new_round > last_summary_round){
         
         Rcard_duration(cards);

     if(new_round % 15 == 0 && new_round > last_card_round){

         int card_id = draw_Rcard();
         card_activation(cards,card_id);

      printf("Regional Card: %s\n", cards[card_id].card_name);
      
      last_card_round=new_round;
   } 

    
     printf("===================\nRound %d Summary\n===================\n\n",new_round);

      for(int i=0;i<4;i++){
        printf("**%s\n\nCash : LKR %d\n\n",players[i].name,players[i].total_money);
        printf("Properties : %d\n\n",players[i].property_count);
     }
     
     last_summary_round=new_round;
    
   
 }
}
    
    printf("=======================\n\n*End of Game\n\n=======================\n\n");
    printf("GAME OVER\n\nWinner\n\n");
    

}