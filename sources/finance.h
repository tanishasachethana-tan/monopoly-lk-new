#ifndef FINANCE_H
#define FINANCE_H
#include "players.h"
#include "board.h"

//loans
int get_loan(Player players[4],Square board[40],int current_position,int player_index);
void eligible_collateral(Player players[4],Square board[40],int player_index);
double total_collateral(Player players[4],Square board[40],int player_index);
int maximum_loan(Player players[4],Square board[40],int player_index);
int select_collateral(Player players[4],Square board[40],int player_index);
void pledge_collateral(Player players[4], Square board[40], int player_index);
void refinancing_loan(Player players[4],Square board[40],int player_index);
void loan_duration(Player players[4],Square board[40],int player_index);
void loan_settling(Player players[4],Square board[40],int player_index);
void loan_default(Player players[4],Square board[40],int player_index);
void loan_interest_cal(Player players[4]);

//insurance
void insurance_purchase(Player players[4], Square board[40], int player_index, int current_position);
void aggressive_investor_insurance(Player players[4], Square board[40], int player_index);
void conservative_banker_insurance(Player players[4],Square board[40],int player_index);
void risk_taker_insurance(Player players[4],Square board[40],int player_index);
void opportunistic_trader_insurance(Player players[4],Square board[40],int player_index);

#endif //FINANCE_H