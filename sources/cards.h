#ifndef CARDS_H
#define CARDS_H

#include "board.h"
#include "players.h"
#include "cardtype.h"

// Regional cards
/*typedef enum{
    Rent,Purchase_price,Revenue
}cardtype;

typedef struct {
    cardtype effect_type;
    double effect_amount;
    int affected_properties[4];
    int affected_count;

} CardEffect;

typedef struct Regionalcards{
    int card_id;
    char card_name[30];
    CardEffect effects[2];
    int effect_count;
    int active;
    int remaining_rounds;


}Regionalcards;


typedef enum {
    Double_Hotel_Rent,
    Railway_Rent_Increase,
    Coastal_Property_Damage,
    Random_Property_Rent_Double,
    Property_Value_Increase,
    Property_Value_Decrease,
    House_Cost_Decrease,
    Loan_Interest_Decrease,
    Loan_Interest_Increase,
    Tax_Amnesty,
    Utility_Income_Decrease,
    Commercial_Value_Increase,
    Railway_Value_Increase,
    Festival_Season,
    Labour_Strike,
    Insurance_Discount,
    Property_Revaluation,
    Currency_Depreciation,
    Government_Grant,
    National_Disaster
} NationalEffectType;

typedef struct {
    int card_id;
    char card_name[50];

    NationalEffectType effect_type;
    double effect_amount;

    int duration;
    int active;

} Nationalcards;*/

extern Nationalcards Ncards[20];
extern int Ncard_set[20];
extern int Ncards_duration[20];

extern Regionalcards cards[12];
extern int Rcard_set[12];

void Rcard_details(Regionalcards cards[12]);
void initialize_deck();
int draw_Rcard();
void card_activation(Regionalcards cards[12], int card_id);
void Rcard_duration(Regionalcards cards[12]);
int apply_card_effect(Regionalcards cards[12], Square board[40], int card_id);
int regional_rent(Regionalcards cards[12], Square board[40], int current_position, int player_index);
int regional_purchase(Regionalcards cards[12], Square board[40], int current_position, int player_index);
int regional_revenue(Regionalcards cards[12], Square board[40], int current_position, int player_index, int revenue);

// National event cards

void Ncard_details(Nationalcards Ncards[20]);
void initialize_Ndeck();
int draw_Ncard();
void Ncard_activation(Nationalcards cards[20], Player players[4], int player_index, int card_id, int duration);
// void apply_Ncard(Player players[4], Square board[40],int current_position, int player_index,int *rent,int card_id);

#endif // CARDS_H