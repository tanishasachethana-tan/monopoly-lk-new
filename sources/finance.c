#include <stdio.h>
#include "players.h"
#include "board.h"
#include "finance.h"

//loan
void eligible_collateral(Player players[4],Square board[40],int player_index){

   for(int i=0;i<40;i++){
      players[player_index].eligible_collateral[i] = 0;
   }
   for(int i=0;i<40;i++){
      if(board[i].owner==players[player_index].player_id && (board[i].type==property || board[i].type==utility || board[i].type==railway) && board[i].lock_status==0){
         players[player_index].eligible_collateral[i]=1;   
      }
   }

}

double total_collateral(Player players[4],Square board[40],int player_index){
   double total_mortgage=0;
   for(int i=0;i<40;i++){
   if(players[player_index].eligible_collateral[i]==1){
      total_mortgage+=board[i].mortgage_value;
   }
}
return total_mortgage;
}

int maximum_loan(Player players[4],Square board[40],int player_index){
   int max_loan=(int)(total_collateral(players,board,player_index)*0.75);

 return max_loan;
}

int select_collateral(Player players[4],Square board[40],int player_index){
      int selected_collateral = -1;
      double highest_mortgage = 0;
     
     for(int j=0;j<40;j++){
      if(players[player_index].eligible_collateral[j]==1){
              if(board[j].mortgage_value > highest_mortgage){
               highest_mortgage=board[j].mortgage_value;
               selected_collateral=j;
              }
         }
      }
   return selected_collateral;
}

void pledge_collateral(Player players[4], Square board[40], int player_index){
   int pledge_collateral=select_collateral(players,board,player_index);
   if(pledge_collateral!=-1){
   board[pledge_collateral].lock_status=1;
   players[player_index].pledged_property=pledge_collateral;
   }
}

void refinancing_loan(Player players[4],Square board[40],int player_index){
   if(players[player_index].outstanding_loan>0){
      if(players[player_index].current_position==board[38].id){

         int max_loan=maximum_loan(players,board,player_index);
         int additional_loan=max_loan-players[player_index].outstanding_loan;

         if(additional_loan > 0){

         players[player_index].outstanding_loan+=additional_loan;
         players[player_index].total_money+=additional_loan;
      }
   }
}
}

int get_loan(Player players[4],Square board[40],int current_position,int player_index){
   if(players[player_index].outstanding_loan>0){
      printf("%s already has an outstanding loan.\n\n",players[player_index].name);
      return 0;
   }

   if(players[player_index].current_position==board[38].id){
      eligible_collateral(players,board,player_index);
      int max_loan=maximum_loan(players,board,player_index);
        if(max_loan <= 0){
         return 0;
        }
         pledge_collateral(players,board,player_index);

         printf("%s took a loan of LKR %d.\n\n",players[player_index].name,max_loan);
         
         players[player_index].total_money+=max_loan;
         players[player_index].outstanding_loan+=max_loan;
         
         players[player_index].loan_start=players[player_index].round_count;

         return max_loan;
   }
   return 0;

}

void loan_duration(Player players[4],Square board[40],int player_index){
   if(players[player_index].outstanding_loan>0){
   if(players[player_index].round_count - players[player_index].loan_start>=20){

    loan_default(players,board,player_index);
      
   }
   }
}

void loan_default(Player players[4],Square board[40],int player_index){
   printf("%s's pledged property(%s) has taken by the bank\n\n",players[player_index].name,board[players[player_index].pledged_property].name);
   board[players[player_index].pledged_property].owner=bank;
  

   if(board[players[player_index].pledged_property].house_count > 0){
      printf("%s property's houses are demolished\n\n",board[players[player_index].pledged_property].name);
      board[players[player_index].pledged_property].house_count=0;
   }
   if(board[players[player_index].pledged_property].hotel_count > 0){
      printf("%s property's hotels are demolished\n\n",board[players[player_index].pledged_property].name);
      board[players[player_index].pledged_property].hotel_count=0;
   }
   
   players[player_index].pledged_property=-1;
   players[player_index].outstanding_loan=0;

}

void loan_settling(Player players[4],Square board[40],int player_index){
 //Aggressive investor
 if(players[player_index].player_id==0){
  if(players[player_index].current_position==board[38].id){
   if(players[player_index].outstanding_loan>0 && (players[player_index].round_count - players[player_index].loan_start<=20)){

      if(players[player_index].total_money > players[player_index].outstanding_loan*2){
        
         if(players[player_index].total_money > players[player_index].outstanding_loan*3){
         
         int repayment=players[player_index].outstanding_loan;
         players[player_index].total_money-=repayment;
         printf("%s repaid LKR %d\n\n",players[player_index].name,repayment);

         players[player_index].outstanding_loan=0;
         board[players[player_index].pledged_property].lock_status=0;
         players[player_index].pledged_property=-1;
         }
         
       //assuming they repay half of the amount of the outstanding loan
          else if(players[player_index].total_money > players[player_index].outstanding_loan * 2 &&
                  players[player_index].total_money <= players[player_index].outstanding_loan * 3) { 
         
         int repayment=players[player_index].outstanding_loan/2;
         players[player_index].total_money-=repayment;
         printf("%s repaid LKR %d\n\n",players[player_index].name,repayment);

         players[player_index].outstanding_loan-=repayment;
        
        }
      }
      
   }
 }
}

//conservative banker
else if(players[player_index].player_id==1){
   if(players[player_index].current_position==board[38].id){
      if(players[player_index].outstanding_loan > 0 && players[player_index].total_money >= players[player_index].outstanding_loan){

         int repayment=players[player_index].outstanding_loan;
         players[player_index].total_money-=repayment;
         printf("%s repaid LKR %d\n\n",players[player_index].name,repayment);

         players[player_index].outstanding_loan=0;
         board[players[player_index].pledged_property].lock_status=0;
         players[player_index].pledged_property=-1;

      }
   }
}

//risk taker
/*if(players[player_index].player_id==2){
        if(players[player_index].current_position==board[38].id){
}*/
}


void loan_interest_cal(Player players[4]){
    for(int i=0;i<4;i++){
      if(players[i].outstanding_loan > 0){
         double interest=players[i].outstanding_loan*players[i].loan_interest;

         players[i].outstanding_loan+=(int)interest;
      }
    }
}


//insurance
void insurance_purchase(Player players[4], Square board[40], int player_index, int current_position){

   if(current_position!=17 && current_position!=33){
      return;
   }

   if(players[player_index].insurance_owned ==1){
      return;
   }

   if(players[player_index].player_id == 0){
     
      aggressive_investor_insurance(players,board,player_index);

   }

   if(players[player_index].player_id == 1){

      conservative_banker_insurance(players,board,player_index);

   }

   if(players[player_index].player_id == 2){
      risk_taker_insurance(players,board,player_index);
   }

   if(players[player_index].player_id == 3){
      opportunistic_trader_insurance(players,board,player_index);
   }



  
}

void aggressive_investor_insurance(Player players[4], Square board[40], int player_index){
   int policy;
   int property_position;
   double premium;


   int property_found=0;
     for(int i=0;i<40;i++){
      if(board[i].owner == players[player_index].player_id){
         if(board[i].house_count > 0 || board[i].hotel_count > 0){

            if(board[i].hotel_count > 0 && property_found==0){
               policy=2;
               property_position=i;
               property_found=1; 

            }
           
            else if(board[i].house_count > 0 && property_found==0){
               policy=1;
               property_position=i;
               property_found=1;

            }
         }
      }
     }

     if(property_found==0){
      printf("No eligible property\n\n");
      return;
     }

     
     if(policy==1){
      premium=board[property_position].purchase_price*0.05;
     }

     else if(policy==2){
      premium=board[property_position].purchase_price*0.10;
      }  

     if(players[player_index].total_money < premium){
      printf("Not enough money to purchase insurance.\n\n");
      return;
     }

     players[player_index].total_money-=premium;
     players[player_index].insurance_owned=1;
     players[player_index].insurance_type=policy;
     players[player_index].insured_property=property_position;

     players[player_index].insurance_duration=20;

     if(policy==1){
          printf("Basic Property Insurance purchased.\n\n");
          printf("Property : %s\n\n",board[property_position].name);
          printf("Premium : LKR %d\n\n",(int)premium);
     }
     else if(policy==2){
          printf("Comprehensive Insurance purchased.\n\n");
          printf("Property : %s\n\n",board[property_position].name);
          printf("Premium : LKR %d\n\n",(int)premium);
     }



}

void conservative_banker_insurance(Player players[4],Square board[40],int player_index){
    
    int policy;
    int property_position;
    double premium;

    int property_found=0;
    policy=2;

    for(int i=0;i<40;i++){
      if(board[i].owner == players[player_index].player_id){
         if(board[i].house_count > 0 || board[i].hotel_count > 0){
             property_position=i;
             property_found=1;
         }
      }
    }

    if(property_found==0){
      printf("No eligible property.\n\n");
      return;
    }

    premium = board[property_position].purchase_price * 0.10;
    
    if(players[player_index].total_money < premium){
       printf("Not enough money to purchase insurance.\n\n");
       return;
    }

     players[player_index].total_money-=premium;
     players[player_index].insurance_owned=1;
     players[player_index].insurance_type=policy;
     players[player_index].insured_property=property_position;

     players[player_index].insurance_duration=20;

     printf("Comprehensive Insurance purchased.\n\n");
     printf("Property : %s\n\n",board[property_position].name);
     printf("Premium : LKR %d\n\n",(int)premium);

}

void risk_taker_insurance(Player players[4],Square board[40],int player_index){
    if(players[player_index].financial_loss==0){
      return;
    }

    int policy;
    int property_position;
    double premium;
    int property_found = 0; 

    policy = rand() % 3 + 1;

    for(int i = 0; i < 40; i++){
      if(board[i].owner == players[player_index].player_id){
        if(board[i].house_count > 0 || board[i].hotel_count > 0){
            property_position = i;
            property_found = 1;
            break;
         }
      }
    }

    if(policy == 1){
    premium = board[property_position].purchase_price * 0.05;
    }
    else if(policy == 2){
    premium = board[property_position].purchase_price * 0.10;
    }
    else if(policy == 3){
    premium = board[property_position].purchase_price * 0.15;
    }

    if(players[player_index].total_money < premium){
       printf("Not enough money to purchase insurance.\n\n");
       return;
    }


     players[player_index].total_money-=premium;
     players[player_index].insurance_owned=1;
     players[player_index].insurance_type=policy;
     players[player_index].insured_property=property_position;

     players[player_index].insurance_duration=20;

     if(policy == 1){
        printf("Basic Property Insurance purchased.\n\n");
     }
     else if(policy == 2){
        printf("Comprehensive Insurance purchased.\n\n");
     }
    else if(policy == 3){
        printf("Business Interruption Insurance purchased.\n\n");
     }

     printf("Property : %s\n\n", board[property_position].name);
     printf("Premium : LKR %d\n\n", (int)premium);



}

void opportunistic_trader_insurance(Player players[4],Square board[40],int player_index){
   
}



