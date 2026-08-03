#include <stdio.h> 
#include <string.h>
#include "board.h"
#include "players.h"
#include "dice.h"


void playerinfo(Player players[]){
     
    strcpy(players[0].name, "Aggresive Investor");
    players[0].player_id = 0;
    players[0].total_money = 30000;
    players[0].current_position = 0;
    players[0].dicevalue = 0;
    players[0].bankrupt = 0;
    players[0].property_count = 0;

    strcpy(players[1].name, "Conservative Banker");
    players[1].player_id = 1;
    players[1].total_money = 30000;
    players[1].current_position = 0;
    players[1].dicevalue = 0;
    players[1].bankrupt = 0;
    players[1].property_count = 0;

    strcpy(players[2].name, "Risk Taker");
    players[2].player_id = 2;
    players[2].total_money = 30000;
    players[2].current_position = 0;
    players[2].dicevalue = 0;
    players[2].bankrupt = 0;
    players[2].property_count = 0;

    strcpy(players[3].name, "Opportunistic Trader");
    players[3].player_id = 3;
    players[3].total_money = 30000;
    players[3].current_position = 0;
    players[3].dicevalue = 0;
    players[3].bankrupt = 0;
    players[3].property_count = 0;

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

int monopoly(Player players[4],Square board[40],int player_index,int current_position){
    int monopoly_owns=1;
    for(int i=0;i<40;i++){
        if((board[current_position].color==board[i].color) && ((board[current_position].type==property) && (board[i].type==property))){
            if(board[i].owner!=player_index){
                monopoly_owns=0;
                break;
            }
        }
    }
     
    if(monopoly_owns==1){
        printf("%s owns a monopoly\n\n",players[player_index].name);
    }
    return monopoly_owns;
}

int color_check(Player players[4],Square board[40],int player_index,int current_position){
     for(int i=0;i<40;i++){
        if(board[i].owner==player_index && board[current_position].color==board[i].color){
            
            return 1;
        }
     }
return 0;
}

int property_purchase(Player players[4],Square board[40],int player_index,int current_position){
  
    //Aggressive Investor
    if(players[player_index].player_id==0){
         if((board[current_position].type == property && board[current_position].owner==-1 && (players[player_index].total_money-board[current_position].purchase_price)>=1200 && players[player_index].bankrupt==0) 
             && (board[current_position].name==Galle_Face || board[current_position].name==Nuwara_Eliya)){

            printf("%s purchased %s for LKR %d\n\n",players[player_index].name,board[current_position].name,(int)board[current_position].purchase_price);
            players[player_index].total_money-=board[current_position].purchase_price;
            printf("Remaining Balance: LKR %d\n\n",(int)players[player_index].total_money);
            board[current_position].owner=players[player_index].player_id;
             
            players[player_index].property_count++;
            // int net_worth

            return 1;
        }

    if(color_check(players,board,player_index,current_position)){
         printf("%s purchased %s for LKR %d\n\n",players[player_index].name,board[current_position].name,(int)board[current_position].purchase_price);
            players[player_index].total_money-=board[current_position].purchase_price;
            printf("Remaining Balance: LKR %d\n\n",(int)players[player_index].total_money);
            board[current_position].owner=players[player_index].player_id;
             
            players[player_index].property_count++;

            return 1;
     }

        
     if(board[current_position].type == property && board[current_position].owner==-1 && (players[player_index].total_money-board[current_position].purchase_price)>=1200 && players[player_index].bankrupt==0) {
             printf("%s purchased %s for LKR %d\n\n",players[player_index].name,board[current_position].name,(int)board[current_position].purchase_price);
             players[player_index].total_money-=board[current_position].purchase_price;
             printf("Remaining Balance: LKR %d\n\n",(int)players[player_index].total_money);
             board[current_position].owner=players[player_index].player_id;

             players[player_index].property_count++;

             return 1;
            }

           
            
        }
    
    
    //Conservative Banker
    else if(players[player_index].player_id==1){
         if(board[current_position].type == property && board[current_position].owner==-1 && (players[player_index].total_money-board[current_position].purchase_price)>=players[player_index].total_money*0.5 && players[player_index].bankrupt==0){
            printf("%s purchased %s for LKR %d\n\n",players[player_index].name,board[current_position].name,(int)board[current_position].purchase_price);
            players[player_index].total_money-=board[current_position].purchase_price;
            printf("Remaining Balance: LKR %d\n\n",(int)players[player_index].total_money);
            board[current_position].owner=players[player_index].player_id;

            players[player_index].property_count++;


            return 1;
         }
    }
   
    //Risk Taker
    else if(players[player_index].player_id==2){
         if(board[current_position].type == property && board[current_position].owner==-1 && players[player_index].bankrupt==0){
            printf("%s purchased %s for LKR %d\n\n",players[player_index].name,board[current_position].name,(int)board[current_position].purchase_price);
            players[player_index].total_money-=board[current_position].purchase_price;
            printf("Remaining Balance: LKR %d\n\n",(int)players[player_index].total_money);
            board[current_position].owner=players[player_index].player_id;
            
            players[player_index].property_count++;


            return 1;
         }
    }
   
    //Opportunistic Trader
    else if(players[player_index].player_id==3){

        int projected_appreciation = board[current_position].base_rent*20; // Assume 20 times rent get paid
        int construction_cost = board[current_position].house_price + board[current_position].hotel_price;

        if(board[current_position].type == property && board[current_position].owner==-1 && projected_appreciation>construction_cost){
            printf("%s purchased %s for LKR %d\n\n",players[player_index].name,board[current_position].name,(int)board[current_position].purchase_price);
            players[player_index].total_money-=board[current_position].purchase_price;
            printf("Remaining Balance: LKR %d\n\n",(int)players[player_index].total_money);
            board[current_position].owner=players[player_index].player_id;
            
            players[player_index].property_count++;


            return 1;
         }
        }
    return 0;

}

int pay_rent(Player players[4],Square board[40],int player_index,int current_position){
    if(board[current_position].owner>-1 && board[current_position].owner!=player_index){
        printf("%s landed on %s\n\n",players[player_index].name,board[current_position].name);
        printf("Rent paid : LKR %d\n\n",(int)board[current_position].base_rent);

        players[player_index].total_money-=board[current_position].base_rent;
        players[board[current_position].owner].total_money+=board[current_position].base_rent;
         
        printf("Owner : %s\n\n",players[board[current_position].owner].name);
        
        return 1;

    }
    return 0;
}

/*void house_limit(Square board[40],int current_position){
    if(board[current_position].house_count<4){
        return 1;
    }
    return 0;
}*/

/*int construction(Player players[4],Square board[40],int player_index,int current_position){
    //Aggresive Investor
    if(monopoly(players, board, player_index, current_position)==1 && (players[player_index].total_money > board[current_position].house_price*12)){
          printf("%s built   ")
    }
}*/