#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include "board.h"
#include "players.h"
#include "dice.h"
#include "finance.h"
#include "cards.h"


void playerinfo(Player players[]){
     
    strcpy(players[0].name, "Aggresive Investor");
    players[0].player_id = 0;
    players[0].total_money = 30000;
    players[0].current_position = 0;
    players[0].dicevalue = 0;
    players[0].bankrupt = 0;
    players[0].property_count = 0;
    players[0].utility_count = 0;
    players[0].railway_count = 0;
    players[0].round_count = 0;
    players[0].jail_in = 0;
    players[0].jail_attempts = 0;
    players[0].outstanding_loan = 0;
    players[0].loan_start = 0;
    players[0].loan_interest = 0.08;
    players[0].pledged_property = -1;
    players[0].Ncard_active = 0;
    players[0].Ncard_duration = 0;
    players[0].Ncard_id = -1;
    players[0].Ncard_remain = 0;
    players[0].construction_suspended = 0;
    players[0].insurance_owned = 0;
    players[0].insurance_type = -1;
    players[0].insurance_duration = 0;
    players[0].insured_property = -1;
    players[0].financial_loss = 0;

    for(int i = 0; i < 9; i++){
    players[0].eligible_collateral[i] = 0;
    }

    for(int i = 0; i < 9; i++){
    players[0].monopoly_owned[i] = 0;
    }

   

    strcpy(players[1].name, "Conservative Banker");
    players[1].player_id = 1;
    players[1].total_money = 30000;
    players[1].current_position = 0;
    players[1].dicevalue = 0;
    players[1].bankrupt = 0;
    players[1].property_count = 0;
    players[1].utility_count = 0;
    players[1].railway_count = 0;
    players[1].round_count = 0;
    players[1].jail_in = 0;
    players[1].jail_attempts = 0;
    players[1].outstanding_loan = 0;
    players[1].loan_start = 0;
    players[1].loan_interest = 0.08;
    players[1].pledged_property = -1;
    players[1].Ncard_active = 0;
    players[1].Ncard_duration = 0;
    players[1].Ncard_id = -1;
    players[1].Ncard_remain = 0;
    players[1].construction_suspended = 0;
    players[1].insurance_owned = 0;
    players[1].insurance_type = -1;
    players[1].insurance_duration = 0;
    players[1].insured_property = -1;
    players[1].financial_loss = 0;


    for(int i = 0; i < 9; i++){
    players[1].eligible_collateral[i] = 0;
    }

    
    for(int i = 0; i < 9; i++){
    players[1].monopoly_owned[i] = 0;
    }

   


    strcpy(players[2].name, "Risk Taker");
    players[2].player_id = 2;
    players[2].total_money = 30000;
    players[2].current_position = 0;
    players[2].dicevalue = 0;
    players[2].bankrupt = 0;
    players[2].property_count = 0;
    players[2].utility_count = 0;
    players[2].railway_count = 0;
    players[2].monopoly_owned[0] = 0;
    players[2].round_count = 0;
    players[2].jail_in = 0;
    players[2].jail_attempts = 0;
    players[2].outstanding_loan = 0;
    players[2].loan_start = 0;
    players[2].loan_interest = 0.08;
    players[2].pledged_property = -1;
    players[2].Ncard_active = 0;
    players[2].Ncard_duration = 0;
    players[2].Ncard_id = -1;
    players[2].Ncard_remain = 0;
    players[2].construction_suspended = 0;
    players[2].insurance_owned = 0;
    players[2].insurance_type = -1;
    players[2].insurance_duration = 0;
    players[2].insured_property = -1;
    players[2].financial_loss = 0;
 

    for(int i = 0; i < 9; i++){
    players[2].eligible_collateral[i] = 0;
    } 

    
    for(int i = 0; i < 9; i++){
    players[2].monopoly_owned[i] = 0;
    }

   


    strcpy(players[3].name, "Opportunistic Trader");
    players[3].player_id = 3;
    players[3].total_money = 30000;
    players[3].current_position = 0;
    players[3].dicevalue = 0;
    players[3].bankrupt = 0;
    players[3].property_count = 0;
    players[3].utility_count = 0;
    players[3].railway_count = 0;
    players[3].round_count = 0;
    players[3].jail_in = 0;
    players[3].jail_attempts = 0;
    players[3].outstanding_loan = 0;
    players[3].loan_start = 0;
    players[3].loan_interest = 0.08;
    players[3].pledged_property = -1;
    players[3].Ncard_active = 0;
    players[3].Ncard_duration = 0;
    players[3].Ncard_id = -1;
    players[3].Ncard_remain = 0;
    players[3].construction_suspended = 0;
    players[3].insurance_owned = 0;
    players[3].insurance_type = -1;
    players[3].insurance_duration = 0;
    players[3].insured_property = -1;
    players[3].financial_loss = 0;


     for(int i = 0; i < 9; i++){
    players[3].eligible_collateral[i] = 0;
    }


     for(int i = 0; i < 9; i++){
    players[3].monopoly_owned[i] = 0;
    }

   
    

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

int rounds_completed(Player players[4]){
    int min_round=-1;
    for(int j=0;j<4;j++){
       if( players[j].bankrupt == 0 ){
        if(min_round ==-1 || players[j].round_count<min_round){
           min_round=players[j].round_count;
        }
       }
}
 return min_round;
}

void jail(Player players[4],int player_index){
   if(players[player_index].current_position==Go_To_Jail){
         players[player_index].current_position=Jail_visiting;
         players[player_index].jail_in = 1;
         printf("%s went to jail",players[player_index].name);
   }
}

void jail_escape(Player players[4],int player_index){
     if(players[player_index].total_money >= 300){
        players[player_index].total_money-=300;
        players[player_index].jail_in = 0;
        players[player_index].jail_attempts = 0;

        printf("%s paid LKR 300 to escape jail\n", players[player_index].name);
        return;
     }
  
     
     int dice1 = (rand() % 6) + 1;
     int dice2 = (rand() % 6) + 1;
     if(dice1==dice2){
        players[player_index].jail_in = 0;
        players[player_index].jail_attempts = 0;
        
        printf("%s rolled doubles and escaped jail\n", players[player_index].name);
        return;
     }

     else{
        players[player_index].jail_attempts++;
         if(players[player_index].jail_attempts==3){
            players[player_index].jail_in = 0;
            players[player_index].jail_attempts = 0;
           
            printf("%s escaped jail after 3 attempts\n", players[player_index].name);
            return;
         }
     }
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
            if(board[i].owner!=players[player_index].player_id){
                monopoly_owns=0;
                break;
            }
        }
    }
     
    if(monopoly_owns==1){
        if(players[player_index].monopoly_owned[board[current_position].color]==0){
        players[player_index].monopoly_owned[board[current_position].color] = 1;   
        construction(players, board, player_index, current_position);
       // printf("%s owns a monopoly\n\n",players[player_index].name);
    }
    return monopoly_owns;
}
}

int color_check(Player players[4],Square board[40],int player_index,int current_position){
     for(int i=0;i<40;i++){
        if(board[i].owner==player_index && board[current_position].color==board[i].color){
            
            return 1;
        }
     }
return 0;
}

int property_purchase(Player players[4],Square board[40],Regionalcards cards[12],int player_index,int current_position){
    
    double purchase = regional_purchase(cards, board,current_position, player_index);
    //Aggressive Investor
    if(players[player_index].player_id==0){
         if((board[current_position].type == property && board[current_position].owner==-1 && (players[player_index].total_money- purchase)>=1200 && players[player_index].bankrupt==0) 
             && (board[current_position].name==Galle_Face || board[current_position].name==Nuwara_Eliya)){

            printf("%s purchased %s for LKR %d\n\n",players[player_index].name,board[current_position].name,(int)purchase);
            players[player_index].total_money-=purchase;
            printf("Remaining Balance: LKR %d\n\n",(int)players[player_index].total_money);
            board[current_position].owner=players[player_index].player_id;
             
            players[player_index].property_count++;

             monopoly(players,board,player_index,current_position);
            // int net_worth

            return 1;
        }

    if(color_check(players,board,player_index,current_position)){
         printf("%s purchased %s for LKR %d\n\n",players[player_index].name,board[current_position].name,(int)purchase);
            players[player_index].total_money-=purchase;
            printf("Remaining Balance: LKR %d\n\n",(int)players[player_index].total_money);
            board[current_position].owner=players[player_index].player_id;
             
            players[player_index].property_count++;
            monopoly(players,board,player_index,current_position);
            return 1;
     }

        
     if(board[current_position].type == property && board[current_position].owner==-1 && (players[player_index].total_money-purchase)>=1200 && players[player_index].bankrupt==0) {
             printf("%s purchased %s for LKR %d\n\n",players[player_index].name,board[current_position].name,(int)purchase);
             players[player_index].total_money-=purchase;
             printf("Remaining Balance: LKR %d\n\n",(int)players[player_index].total_money);
             board[current_position].owner=players[player_index].player_id;

             players[player_index].property_count++;
             monopoly(players,board,player_index,current_position);
             return 1;
            }

           
            
        }
    
    
    //Conservative Banker
    else if(players[player_index].player_id==1){
         
         if((board[current_position].type == utility || board[current_position].type == railway) && board[current_position].owner==-1 && (players[player_index].total_money-purchase)>=players[player_index].total_money*0.5 && players[player_index].bankrupt==0){
            printf("%s purchased %s for LKR %d\n\n",players[player_index].name,board[current_position].name,(int)purchase);
            players[player_index].total_money-=purchase;
            printf("Remaining Balance: LKR %d\n\n",(int)players[player_index].total_money);
            board[current_position].owner=players[player_index].player_id;

            if(board[current_position].type==utility && board[current_position].owner==1){
                players[player_index].utility_count++;
            }
            if(board[current_position].type==railway && board[current_position].owner==1){
                players[player_index].railway_count++;
            }
            return 1;
         }

         if(board[current_position].type == property && board[current_position].owner==-1 && (players[player_index].total_money-purchase)>=players[player_index].total_money*0.5 && players[player_index].bankrupt==0){
            printf("%s purchased %s for LKR %d\n\n",players[player_index].name,board[current_position].name,(int)purchase);
            players[player_index].total_money-=purchase;
            printf("Remaining Balance: LKR %d\n\n",(int)players[player_index].total_money);
            board[current_position].owner=players[player_index].player_id;

            players[player_index].property_count++;


            return 1;
         }
    }
   
    //Risk Taker
    else if(players[player_index].player_id==2){
         if(board[current_position].type == property && board[current_position].owner==-1 && players[player_index].bankrupt==0){
            printf("%s purchased %s for LKR %d\n\n",players[player_index].name,board[current_position].name,(int)purchase);
            players[player_index].total_money-=purchase;
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
            printf("%s purchased %s for LKR %d\n\n",players[player_index].name,board[current_position].name,(int)purchase);
            players[player_index].total_money-=purchase;
            printf("Remaining Balance: LKR %d\n\n",(int)players[player_index].total_money);
            board[current_position].owner=players[player_index].player_id;
            
            players[player_index].property_count++;


            return 1;
         }
        }
    return 0;

}



int pay_rent(Player players[4],Square board[40],Regionalcards cards[12],Nationalcards Ncards[20],int player_index,int current_position){
    if(board[current_position].owner>-1 && board[current_position].owner!=player_index && board[current_position].type==property){
        printf("%s landed on %s\n\n",players[player_index].name,board[current_position].name);

        int rent;

       if(board[current_position].hotel_count > 0){
             rent = hotel_rent(players, board, current_position, player_index);
        }

       else if(board[current_position].house_count > 0){
             rent = house_rent(players, board, current_position, player_index);
       }

       else{
            rent = regional_rent(cards, board, current_position, player_index);
       }


       rent = regional_revenue(cards, board, current_position, player_index, rent);

        
       //Ncard apply
       if(players[player_index].Ncard_remain > 0){
             apply_Ncard(players, board, current_position,player_index, &rent,players[player_index].Ncard_id);
        }

        printf("Rent paid : LKR %d\n\n",(int)rent);
        

        if(players[player_index].player_id==1){
            conservative_banker_loan(players,board,current_position,player_index);
        }
        players[player_index].total_money-=rent;

        if(players[player_index].total_money < 0){
            players[player_index].bankrupt=1;
        }

        players[board[current_position].owner].total_money+=rent;
         
        printf("Owner : %s\n\n",players[board[current_position].owner].name);
        
        return 1;

    }

    if(board[current_position].owner>-1 && board[current_position].owner!=player_index && board[current_position].type==railway){
   
        printf("%s landed on %s\n\n",players[player_index].name,board[current_position].name);
        int rent = railway_rent(players,board,player_index,current_position);  
        rent = regional_revenue(cards,board,current_position,player_index,rent);

        if(players[player_index].Ncard_remain > 0){
             apply_Ncard(players, board, current_position,player_index, &rent,players[player_index].Ncard_id);
          }

        int owner = board[current_position].owner;

          players[player_index].total_money -= rent;
          players[owner].total_money += rent;

        printf("Rent paid : LKR %d\n\n",rent);


        
    }

    if(board[current_position].owner>-1 && board[current_position].owner!=player_index && board[current_position].type==utility){
   
        printf("%s landed on %s\n\n",players[player_index].name,board[current_position].name);
        int rent = utility_rent(players,board,player_index,current_position);
        rent = regional_revenue(cards,board,current_position,player_index,rent);

        if(players[player_index].Ncard_remain > 0){
               apply_Ncard(players, board, current_position,player_index, &rent,players[player_index].Ncard_id);
        }

        int owner = board[current_position].owner;

          players[player_index].total_money -= rent;
          players[owner].total_money += rent;

        printf("Rent paid : LKR %d\n\n",rent);

    return 0;
}
}


int utility_rent(Player players[4],Square board[40],int player_index,int current_position){
  if(board[current_position].owner > -1){

    if(board[current_position].type==utility && board[current_position].owner!=player_index && players[board[current_position].owner].utility_count==1){
          return 4*players[player_index].dicevalue;
    }

    if(board[current_position].type==utility && board[current_position].owner!=player_index && players[board[current_position].owner].utility_count==2){
          return 10*players[player_index].dicevalue;
    }

  }
  return 0;
}

int railway_rent(Player players[4],Square board[40],int player_index,int current_position){

 if(board[current_position].owner > -1){
    
    if(board[current_position].type==railway && board[current_position].owner!=player_index && players[board[current_position].owner].railway_count==1){
          return 250;
    }

    if(board[current_position].type==railway && board[current_position].owner!=player_index && players[board[current_position].owner].railway_count==2){
          return 500;
    }

    if(board[current_position].type==railway && board[current_position].owner!=player_index && players[board[current_position].owner].railway_count==3){
           return 1000;
    }

    if(board[current_position].type==railway && board[current_position].owner!=player_index && players[board[current_position].owner].railway_count==4){
           return 2000;
    }
          
   }
   return 0;
}        

int house_limit(Square board[40],int current_position){
    if(board[current_position].house_count<4){
        return 1;
    }
    return 0;
}

void construction(Player players[4],Square board[40],int player_index,int current_position){

    if(players[player_index].construction_suspended > 0){
          
         printf("%s cannot construct for %d more rounds.\n",
               players[player_index].name,
               players[player_index].construction_suspended);
        return;

    }

    
    //Aggresive Investor
    if(players[player_index].player_id==0){
   /* if(monopoly(players, board, player_index, current_position)==1 && (players[player_index].total_money > board[current_position].house_price*12)){
          printf("%s built   ")*/
          for(int i=1;i<9;i++){
            if(players[player_index].monopoly_owned[i]==1){
                int total_houses=0;
                int max_houses;
                int remainder;
                int monopoly_properties=0;
                for(int j=0;j<40;j++){
                    if(board[j].type==property && board[j].color==i && board[j].owner==players[player_index].player_id){
                        monopoly_properties++;
                        total_houses+=board[j].house_count;
                        }
                    }
                
                 max_houses=monopoly_properties*4;
                 remainder=max_houses - total_houses;
           
                 while(remainder>0){
                    int lowest_houses=5;
                    int property_index=-1;

                    for(int j=0;j<40;j++){
                     if(board[j].type==property && board[j].color==i && board[j].owner==players[player_index].player_id){
                        if(board[j].house_count < lowest_houses && board[j].house_count < 4){
                             lowest_houses=board[j].house_count;
                             property_index=j;

                        }
                     }
                    }
                    
                    if(property_index==-1){
                        break;
                    }
                    if(players[player_index].total_money < board[property_index].house_price){
                        break;
                    }
                     
                    board[property_index].house_count++;
                    printf("%s built a house on %s (Houses: %d)\n",players[player_index].name, board[property_index].name, board[property_index].house_count);
                    players[player_index].total_money-=board[property_index].house_price;
                       
                    remainder--;
                 }
                

                    }
                } 
            }
  }


  //aggressive investor loan thing
int next_build(Player players[40],Square board[40],int player_index){
    int lowest_houses = 5;
    int property_index = -1;

    for(int i = 1; i < 9; i++){
    if(players[player_index].monopoly_owned[i] == 1){
           for(int j = 0; j < 40; j++){
                 if(board[j].type == property && board[j].color == i && board[j].owner == players[player_index].player_id){
                        if(board[j].house_count < lowest_houses && board[j].house_count < 4){
                           lowest_houses = board[j].house_count;
                           property_index = j;
                          
                        }
                 }
        }
     }
    }

    if(property_index==-1){
        return -1;
    }
    return board[property_index].house_price;
}  

    
void Aggressive_investor_loan(Player players[4],Square board[40],int current_position,int player_index){

    if(current_position!=board[38].id){
        return;
    }

    int house_cost=next_build(players,board,player_index);

    if(house_cost==-1){
        return;
    }

    if(players[player_index].total_money>=house_cost){
        return;
    }
     
    int money_needed=house_cost-players[player_index].total_money;

    eligible_collateral(players,board,player_index);
    int max_loan=maximum_loan(players,board,player_index);
   
    if(max_loan>=money_needed){
        get_loan(players,board,current_position,player_index);
    }
}


//conservative banker loan thing
void conservative_banker_loan(Player players[4],Square board[40],int current_position,int player_index){
    if(players[player_index].total_money < board[current_position].base_rent){
        int money_needed=board[current_position].base_rent-players[player_index].total_money;
        eligible_collateral(players,board,player_index);
        int max_loan=maximum_loan(players,board,player_index);

        if(max_loan>=money_needed){
        get_loan(players,board,current_position,player_index);
        }
    }
}

//risk taker loan thing
void risk_taker_loan(Player players[4],Square board[40],int current_position,int player_index){
    
        if(players[player_index].current_position==board[38].id){
            if(players[player_index].outstanding_loan==0){

                eligible_collateral(players,board,player_index);
                
                get_loan(players,board,current_position,player_index);
            }
        }
 }

 int house_rent(Player players[4],Square board[40],int current_position,int player_index){
      double rent=(board[current_position].house_count+1)*board[current_position].base_rent;
      return (int)rent;
 }

 int hotel_rent(Player players[4],Square board[40],int current_position,int player_index){
     double rent=10*board[current_position].base_rent;
    return (int)rent;
 }



