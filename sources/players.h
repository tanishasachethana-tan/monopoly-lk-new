#ifndef PLAYERS_H
#define PLAYERS_H 

#include "board.h"
#include "cardtype.h"



typedef struct {
    char name[50];
    int player_id;
    int total_money;
    int current_position;
    int dicevalue;
    int bankrupt;
    int rank;
    int property_count;
    int utility_count;
    int railway_count;
    int monopoly_owned[9];
    int round_count;

    int jail_in;
    int jail_attempts;

    int eligible_collateral[40];
    int outstanding_loan;
    int loan_start;
    int loan_interest;
    int pledged_property;

    int Ncard_active;
    int Ncard_duration;
    int Ncard_id;
    int Ncard_remain;
    int construction_suspended;

    int insurance_owned;
    int insurance_duration;
    int insurance_type;
    int insured_property;

    int financial_loss;
    
    //int properties[40]; // Array to hold property ownership 
} Player;


extern Player players[40]; 
void playerinfo(Player players[4]);
int move_player(Player players[4], int dicevalue);
int bankrupt_check(Player players[4]);
int bankrupt_count(Player players[4]);
int monopoly(Player players[4],Square board[40],int player_index,int current_position);
int house_limit(Square board[40],int current_position);
int property_purchase(Player players[4],Square board[40],Regionalcards cards[12],int player_index,int current_position);
int pay_rent(Player players[4],Square board[40],Regionalcards cards[12],Nationalcards Ncards[20],int player_index,int current_position);
int railway_rent(Player players[4],Square board[40],int player_index,int current_position);
int utility_rent(Player players[4],Square board[40],int player_index,int current_position);
void construction(Player players[4],Square board[40],int player_index,int current_position);
void jail(Player players[4],int player_index);
void jail_escape(Player players[4],int player_index);
int rounds_completed(Player players[4]);
int next_build(Player players[40],Square board[40],int player_index);
void Aggressive_investor_loan(Player players[4],Square board[40],int current_position,int player_index);
void conservative_banker_loan(Player players[4],Square board[40],int current_position,int player_index);
void risk_taker_loan(Player players[4],Square board[40],int current_position,int player_index);
int house_rent(Player players[4],Square board[40],int current_position,int player_index);
int hotel_rent(Player players[4],Square board[40],int current_position,int player_index);
void apply_Ncard(Player players[4], Square board[40],int current_position, int player_index,int *rent, int card_id);

#endif // PLAYERS_H

