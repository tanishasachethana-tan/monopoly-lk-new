#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cards.h"
#include "board.h"
#include "players.h"


//Regional cards
Regionalcards cards[12];
int Rcard_set[12];
void Rcard_details(Regionalcards cards[12]){

    cards[0].card_id = 0;
    strcpy(cards[0].card_name ,"Southern Tourism Boom");
    cards[0].effects[0].effect_type=Rent;
    cards[0].effects[0].effect_amount=0.40;

    cards[0].effects[0].affected_properties[0] = 26;
    cards[0].effects[0].affected_properties[1] = 27;
    cards[0].effects[0].affected_properties[2] = 29;
    cards[0].effects[0].affected_count=3;

    cards[0].effect_count=1;
    cards[0].active = 0;
    cards[0].remaining_rounds = 0;


    cards[1].card_id = 1;
    strcpy(cards[1].card_name ,"Port City Expansion");
    cards[1].effects[0].effect_type = Purchase_price;
    cards[1].effects[0].effect_amount = 0.25;

    cards[1].effects[0].affected_properties[0] = 1;
    cards[1].effects[0].affected_properties[1] = 3;
    cards[1].effects[0].affected_properties[2] = 5;
    cards[1].effects[0].affected_count=3;


    cards[1].effect_count=1;
    cards[1].active = 0;
    cards[1].remaining_rounds = 0;


    cards[2].card_id = 2;
    strcpy(cards[2].card_name ,"IT Industry Growth");
    cards[2].effects[0].effect_type = Purchase_price;
    cards[2].effects[0].effect_amount = 0.20;

    cards[2].effects[0].affected_properties[0] = 11;
    cards[2].effects[0].affected_properties[1] = 13;
    cards[2].effects[0].affected_properties[2] = 14;
    cards[2].effects[0].affected_count=3;


    cards[2].effect_count=1;
    cards[2].active = 0;
    cards[2].remaining_rounds = 0;


    cards[3].card_id = 3;
    strcpy(cards[3].card_name ,"Northern Development Programme");
    cards[3].effects[0].effect_type = Purchase_price;
    cards[3].effects[0].effect_amount = 0.30;

    cards[3].effects[0].affected_properties[0] = 31;
    cards[3].effects[0].affected_properties[1] = 32;
    cards[3].effects[0].affected_properties[2] = 34;
    cards[3].effects[0].affected_count=3;


    cards[3].effect_count=1;
    cards[3].active = 0;
    cards[3].remaining_rounds = 0;


    cards[4].card_id = 4;
    strcpy(cards[4].card_name ,"Tea Export Boom");
    cards[4].effects[0].effect_type = Purchase_price;
    cards[4].effects[0].effect_amount = 0.35;

    cards[4].effects[0].affected_properties[0] = 37;
    cards[4].effects[0].affected_count=1;

   
    cards[4].effect_count=1;
    cards[4].active = 0;
    cards[4].remaining_rounds = 0;


    cards[5].card_id = 5;
    strcpy(cards[5].card_name ,"Airport Expansion");
    cards[5].effects[0].effect_type = Rent;
    cards[5].effects[0].effect_amount = 0.30;

    cards[5].effects[0].affected_properties[0] = 16;
    cards[5].effects[0].affected_properties[1] = 18;
    cards[5].effects[0].affected_properties[2] = 19;
    cards[5].effects[0].affected_count=3;


    cards[5].effect_count=1;
    cards[5].active = 0;
    cards[5].remaining_rounds = 0;


    cards[6].card_id = 6;
    strcpy(cards[6].card_name ,"University City Growth");
    cards[6].effects[0].effect_type = Purchase_price;
    cards[6].effects[0].effect_amount = 0.20;

    cards[6].effects[0].affected_properties[0] = 21;
    cards[6].effects[0].affected_properties[1] = 23;
    cards[6].effects[0].affected_count=2;

    
    cards[6].effect_count=1;
    cards[6].active = 0;
    cards[6].remaining_rounds = 0;


    cards[7].card_id = 7;
    strcpy(cards[7].card_name ,"Beach Pollution");
    cards[7].effects[0].effect_type = Rent;
    cards[7].effects[0].effect_amount = (-0.30);

    cards[7].effects[0].affected_properties[0] = 26;
    cards[7].effects[0].affected_properties[1] = 27;
    cards[7].effects[0].affected_properties[2] = 29;
    cards[7].effects[0].affected_count=3;


    cards[7].effect_count=1;
    cards[7].active = 0;
    cards[7].remaining_rounds = 0;


    cards[8].card_id = 8;
    strcpy(cards[8].card_name ,"Flood Damage");
    cards[8].effects[0].effect_type=Purchase_price;
    cards[8].effects[0].effect_amount=(-0.20);

    cards[8].effects[0].affected_properties[0] = 26;
    cards[8].effects[0].affected_properties[1] = 27;
    cards[8].effects[0].affected_properties[2] = 29;
    cards[8].effects[0].affected_count=3;


    cards[8].effect_count=1;
    cards[8].active = 0;
    cards[8].remaining_rounds = 0;


    cards[9].card_id = 9;
    strcpy(cards[9].card_name ,"Transport Strike");
    cards[9].effects[0].effect_type = Revenue;
    cards[9].effects[0].effect_amount = (-0.40);

    cards[9].effects[0].affected_properties[0] = 5;
    cards[9].effects[0].affected_properties[1] = 15;
    cards[9].effects[0].affected_properties[2] = 25;
    cards[9].effects[0].affected_properties[3] = 35;
    cards[1].effects[0].affected_count=4;


    cards[9].effect_count=1;
    cards[9].active = 0;
    cards[9].remaining_rounds = 0;


    cards[10].card_id = 10;
    strcpy(cards[10].card_name ,"Electricity Tariff Increase");
    cards[10].effects[0].effect_type = Rent;
    cards[10].effects[0].effect_amount = 0.25;

    cards[10].effects[0].affected_properties[0] = 12;
    cards[10].effects[0].affected_properties[1] = 28;
    cards[10].effects[0].affected_count=2;
    
    cards[10].effect_count=1;
    cards[10].active = 0;
    cards[10].remaining_rounds = 0;


    cards[11].card_id = 11;
    strcpy(cards[11].card_name ,"Water Shortage");
    cards[11].effects[0].effect_type = Revenue;
    cards[11].effects[0].effect_amount = 0.20;

    cards[11].effects[0].affected_properties[0] = 28;
    cards[11].effects[0].affected_count=1;

    cards[11].effects[1].effect_type = Purchase_price;
    cards[11].effects[1].effect_amount =(-0.10);

    cards[11].effects[1].affected_properties[0] = 27;
    cards[11].effects[1].affected_properties[1] = 29;
    cards[11].effects[1].affected_count=2;

    cards[11].effect_count=2;
    cards[11].active = 0;
    cards[11].remaining_rounds = 0;


}

void initialize_deck(){
    for(int i=0;i<12;i++){
        Rcard_set[i]=i;
    }
}

int draw_Rcard(){
    int temporary=Rcard_set[0];

    for(int i=0;i<11;i++){
    Rcard_set[i]=Rcard_set[i+1];
}
 
  Rcard_set[11]=temporary;
  
  return temporary;
}

void card_activation(Regionalcards cards[12],int card_id){
    cards[card_id].active = 1;
    cards[card_id].remaining_rounds = 15;
}

void Rcard_duration(Regionalcards cards[12]){
     for(int i=0;i<12;i++){
       if(cards[i].active==1){
         cards[i].remaining_rounds--;
          if(cards[i].remaining_rounds==0){
             cards[i].active=0;
         }
      }
   }
}



int regional_rent(Regionalcards cards[12],Square board[40], int current_position,int player_index){
     

    int rent = (int)board[current_position].base_rent;
     for(int i = 0; i < 12; i++){

        if(cards[i].active == 1){
            for(int j = 0; j < cards[i].effect_count; j++){  
                if(cards[i].effects[j].effect_type == Rent){
                    for(int k = 0; k < cards[i].effects[j].affected_count; k++){
                         
                        int position=cards[i].effects[j].affected_properties[k];
                       if(position == current_position && board[position].owner > -1 && board[position].owner != player_index){
                          
                        double amount=cards[i].effects[j].effect_amount;
                        
                        rent*=(1+amount);

                        
                      }
                  }
              }

           }
         }
      }
      return rent;
}

int regional_purchase(Regionalcards cards[12],Square board[40],int current_position,int player_index){

    int purchase= (int)board[current_position].purchase_price;
     for(int i = 0; i < 12; i++){

        if(cards[i].active == 1){
            for(int j = 0; j < cards[i].effect_count; j++){  
                if(cards[i].effects[j].effect_type == Purchase_price){
                    for(int k = 0; k < cards[i].effects[j].affected_count; k++){
                         
                        int position=cards[i].effects[j].affected_properties[k];
                       if(position == current_position && board[position].owner == -1){
                          
                        double amount=cards[i].effects[j].effect_amount;
                        
                        purchase*=(1+amount);

                        
                      }
                  }
              }

           }
         }
      }
      return purchase;
}
    
int regional_revenue(Regionalcards cards[12],Square board[40],int current_position,int player_index,int revenue){

     for(int i = 0; i < 12; i++){

        if(cards[i].active == 1){
            for(int j = 0; j < cards[i].effect_count; j++){  
                if(cards[i].effects[j].effect_type == Revenue){

                    for(int k = 0; k < cards[i].effects[j].affected_count; k++){
                         
                        int position=cards[i].effects[j].affected_properties[k];
                       if(position == current_position && board[position].owner > -1 && board[position].owner != player_index){
                          
                        double amount=cards[i].effects[j].effect_amount;
                        
                        revenue*=(1+amount);

                        
                      }
                  }
                  
              }

        }
     }
    }
     return (int)revenue;
}   


//National event cards
void Ncard_details(Nationalcards Ncards[20]){
   
    Ncards[0].card_id = 0;
    strcpy(Ncards[0].card_name, "Tourism Hype");
    Ncards[0].effect_type = Double_Hotel_Rent;
    Ncards[0].effect_amount = 2.0;
    Ncards[0].duration = 5;
    Ncards[0].active = 0;
    
    

    Ncards[1].card_id = 1;
    strcpy(Ncards[1].card_name, "Fuel Shortage");
    Ncards[1].effect_type = Railway_Rent_Increase;
    Ncards[1].effect_amount = 2.0;
    Ncards[1].duration = 5;
    Ncards[1].active = 0;
    


    Ncards[2].card_id = 2;
    strcpy(Ncards[2].card_name, "Heavy Floods");
    Ncards[2].effect_type = Coastal_Property_Damage;
    Ncards[2].effect_amount = 0;
    Ncards[2].duration = 16;
    Ncards[2].active = 0;
    


    Ncards[3].card_id = 3;
    strcpy(Ncards[3].card_name, "Political Rally");
    Ncards[3].effect_type =  Random_Property_Rent_Double;
    Ncards[3].effect_amount = 0;
    Ncards[3].duration = 2;
    Ncards[3].active = 0;
    


    Ncards[4].card_id = 4;
    strcpy(Ncards[4].card_name, "Stock Market Rise");
    Ncards[4].effect_type = Property_Value_Increase;
    Ncards[4].effect_amount = 0.1;
    Ncards[4].duration = 15;
    Ncards[4].active = 0;
    


    Ncards[5].card_id = 5;
    strcpy(Ncards[5].card_name, "Economic Downturn");
    Ncards[5].effect_type = Property_Value_Decrease;
    Ncards[5].effect_amount = (-0.15);
    Ncards[5].duration = 15;
    Ncards[5].active = 0;
    


    Ncards[6].card_id = 6;
    strcpy(Ncards[6].card_name, "Housing Subsidy");
    Ncards[6].effect_type = House_Cost_Decrease;
    Ncards[6].effect_amount = (-0.30);
    Ncards[6].duration = 15;
    Ncards[6].active = 0;
    


    Ncards[7].card_id = 7;
    strcpy(Ncards[7].card_name, "Interest Rate Cut");
    Ncards[7].effect_type =  Loan_Interest_Decrease;
    Ncards[7].effect_amount = (-0.2);
    Ncards[7].duration = 15;
    Ncards[7].active = 0;
    


    Ncards[8].card_id = 8;
    strcpy(Ncards[8].card_name, "Interest Rate Increase");
    Ncards[8].effect_type = Loan_Interest_Increase;
    Ncards[8].effect_amount = (-0.2);
    Ncards[8].duration = 15;
    Ncards[8].active = 0;
    


    Ncards[9].card_id = 9;
    strcpy(Ncards[9].card_name, "Tax Amnesty");
    Ncards[9].effect_type = Tax_Amnesty;
    Ncards[9].effect_amount = 0;
    Ncards[9].duration = 15;
    Ncards[9].active = 0;
   


    Ncards[10].card_id = 10;
    strcpy(Ncards[10].card_name, "Power Failure");
    Ncards[10].effect_type = Utility_Income_Decrease;
    Ncards[10].effect_amount = 0.5;
    Ncards[10].duration = 3;
    Ncards[10].active = 0;
    


    Ncards[11].card_id = 11;
    strcpy(Ncards[11].card_name, "Foreign Funding");
    Ncards[11].effect_type = Commercial_Value_Increase;
    Ncards[11].effect_amount = 0.15;
    Ncards[11].duration = 15;
    Ncards[11].active = 0;
    


    Ncards[12].card_id = 12;
    strcpy(Ncards[12].card_name, "Port Expansion");
    Ncards[12].effect_type = Railway_Value_Increase;
    Ncards[12].effect_amount = 0.20;
    Ncards[12].duration = 15;
    Ncards[12].active = 0;
    


    Ncards[13].card_id = 13;
    strcpy(Ncards[13].card_name, "Festival Season");
    Ncards[13].effect_type = Festival_Season;
    Ncards[13].effect_amount = 0.5;
    Ncards[13].duration = 15;
    Ncards[13].active = 0;
    


    Ncards[14].card_id = 14;
    strcpy(Ncards[14].card_name, "Labour Strike");
    Ncards[14].effect_type = Labour_Strike;
    Ncards[14].effect_amount = 0;
    Ncards[14].duration = 2;
    Ncards[14].active = 0;
    


    Ncards[15].card_id = 15;
    strcpy(Ncards[15].card_name, "Insurance Discount");
    Ncards[15].effect_type = Insurance_Discount;
    Ncards[15].effect_amount = (-0.20);
    Ncards[15].duration = 15;
    Ncards[15].active = 0;
    


    Ncards[16].card_id = 16;
    strcpy(Ncards[16].card_name, "Property Revaluation");
    Ncards[16].effect_type =  Property_Revaluation;
    Ncards[16].effect_amount = 0.15;
    Ncards[16].duration = 15;
    Ncards[16].active = 0;
    


    Ncards[17].card_id = 17;
    strcpy(Ncards[17].card_name, "Currency Depreciation");
    Ncards[17].effect_type = Currency_Depreciation;
    Ncards[17].effect_amount = 0.10;
    Ncards[17].duration = 15;
    Ncards[17].active = 0;
    


    Ncards[18].card_id = 18;
    strcpy(Ncards[18].card_name, "Government Grant");
    Ncards[18].effect_type = Government_Grant;
    Ncards[18].effect_amount = 0;
    Ncards[18].duration = 15;
    Ncards[18].active = 0;
    


    Ncards[19].card_id = 19;
    strcpy(Ncards[19].card_name, "National Disaster");
    Ncards[19].effect_type = National_Disaster;
    Ncards[19].effect_amount = 0;
    Ncards[19].duration = 15;
    Ncards[19].active = 0;
    


}

Nationalcards Ncards[20];
int Ncard_set[20];
int Ncard_duration[20]={5,5,1,2,15,15,15,15,15,1,3,15,15,15,2,15,15,15,1,1};

void initialize_Ndeck(){
    for(int i = 0; i < 20; i++){
        Ncard_set[i] = i;
    }
}

int draw_Ncard(){
    int temporary = Ncard_set[0];

    for(int i = 0; i < 19; i++){
        Ncard_set[i] = Ncard_set[i+1];
    }

    Ncard_set[19] = temporary;

    return temporary;
}

void Ncard_activation(Nationalcards cards[20],Player players[4],int player_index, int card_id, int duration){
    cards[card_id].active = 1;
    cards[card_id].duration = duration;

    players[player_index].Ncard_id=card_id;
    players[player_index].Ncard_remain=duration;
}



void apply_Ncard(Player players[4], Square board[40],int current_position, int player_index,int *rent,int card_id){

    if(players[player_index].Ncard_remain <= 0){
          return;
    }  
    
    if(card_id==4 || card_id==5 || card_id==6 || card_id==11 || card_id==12 || card_id==16 || card_id==17){
        return;
    }
    
    switch(card_id){

       case 0: if(board[current_position].hotel_count > 0 && board[current_position].owner > -1 && board[current_position].owner!=players[player_index].player_id && board[current_position].type==property){
                  
                    *rent*=2;
                }
                 break;

        case 1: if(board[current_position].type == railway && board[current_position].owner!=player_index && board[current_position].owner > -1 ){

                   *rent= railway_rent(players,board,player_index,current_position);
                   *rent*=2;
                }  
                break;     
         
        case 2 : int random_index = rand() % coastal_count;
                 int damaged_position = coastal_properties[random_index];

                   printf("Coastal property %s has been damaged!\n", board[damaged_position].name);
                   break;
 
        case 3 : { int random_position;

                  do
                   {
                     random_position = rand() % 40;
                   }
                   while(board[random_position].type != property);

                   board[random_position].closed_rounds = 2;
                   board[random_position].closed = 1;
                   printf("Property %s has been closed for 2 rounds!\n", board[random_position].name);
                   break; 
                } 

        case 4 :  for(int i = 0; i < 40;i++) {
                    if(board[i].type == property){
                          board[i].purchase_price *= 1.10;
                        }
                 }

                   printf("All property purchase values have increased by 10%%!\n");
                   break;
       
        case 5 :    for(int i = 0; i < 40; i++){
                      if(board[i].type == property){
                        board[i].purchase_price *= 0.85;
                      }
                    }

                    printf("All property purchase values have decreased by 15%%!\n");
                    break;
        
        case 6 :    for(int i = 0; i < 40; i++){
                      if(board[i].type == property){
                        board[i].house_price *= 0.70;
                      }
                    }

                    printf("House construction cost has been reduced by 30%%!\n");
                    break;
        
        case 7 :    players[player_index].loan_interest-= 0.02;
                    printf("Loan interest rate reduced by 2%%!\n");
                    break;
       
        case 8 :    players[player_index].loan_interest-= 0.02;
                    printf("Loan interest rate increased by 2%%!\n");
                    break; 
        
        case 9 :    for(int i = 0; i < 4; i++){
                       if(players[i].bankrupt == 0){
                          players[i].total_money += 2000;
                       }
                    }

                    printf("Each player receives LKR 2000!\n");
                    break;
    
        case 10:    
                    *rent*=0.5;
        
                    printf("Utility income is halved for 3 rounds!\n");
                    break;
        
        case 11:    for(int i=0;i<40;i++){
                       if(board[i].id == 1 || board[i].id ==6 || board[i].id == 11){
                        board[i].purchase_price*=1.15;
                       }
                    }

                    printf("commercial property value increased by 15%% \n\n ");
                    break;
        
        case 12:    for(int i = 0; i < 40; i++){
                      if(board[i].type == railway){
                         board[i].purchase_price *= 1.20;
                      }
                    }

                    printf("Railway station values have increased by 20%%!\n");
                    break;
        
        case 13:   if(board[current_position].hotel_count > 0){
                    *rent = hotel_rent(players, board, current_position, player_index);
                    *rent *= 1.5;
                    }

                    printf("Hotels receive 50%% additional rent!\n");
                    break;
        
        case 14:    players[player_index].construction_suspended = 2;
                    printf("Construction is suspended for 2 rounds!\n");
                    break;
        
        case 15:    printf("Insurance premium reduced by 20%%!\n");
                    break;
        
        case 16:    {int random_position;
                     do
                    {
                     random_position = rand() % 40;
                    }
                    while(board[random_position].type != property);

                    int selected_color = board[random_position].color;

                    for(int i = 0; i < 40; i++){
                       if(board[i].type == property && board[i].color == selected_color){
                         board[i].purchase_price *= 1.15;
                       }
                    }

                    printf("A random property group has appreciated by 15%%!\n");
                    break;
                }
        
        case 17:    for(int i = 0; i < 40; i++){
                      if(board[i].type == property){
                       board[i].house_price *= 1.10;
                      }
                    }

                    printf("Construction cost has increased by 10%%!\n");
                    break;
        case 18:    int random_player;
                    do
                    {
                         random_player = rand() % 4;
                    }
                    while(players[random_player].bankrupt != 0);

                    players[random_player].total_money += 5000;

                    printf("%s receives LKR 5000!\n", players[random_player].name);
                    break;
        
        case 19:    {   
                       int random_position;
                       int developed_exists = 0;

                       for(int i = 0; i < 40; i++){
                         if(board[i].type == property && (board[i].house_count > 0 || board[i].hotel_count > 0)){
                            developed_exists = 1;
                         break;
                         }
                        }

                        if(developed_exists == 0){
                            printf("No developed property exists to damage.\n");
                            break;
                        }

                        do {
                             random_position = rand() % 40;
                           }
                          while(board[random_position].type != property || (board[random_position].house_count == 0 && board[random_position].hotel_count == 0));

                             board[random_position].house_count = 0;
                             board[random_position].hotel_count = 0;

                        printf("Developed property %s has been damaged!\n", board[random_position].name);

                        break;
                     }
                           

                    }
        



    }

