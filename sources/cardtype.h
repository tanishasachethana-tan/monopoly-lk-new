#ifndef CARD_TYPES_H
#define CARD_TYPES_H

typedef enum {
    Rent,
    Purchase_price,
    Revenue
} cardtype;

typedef struct {
    cardtype effect_type;
    double effect_amount;
    int affected_properties[4];
    int affected_count;
} CardEffect;

typedef struct {
    int card_id;
    char card_name[30];
    CardEffect effects[2];
    int effect_count;
    int active;
    int remaining_rounds;
} Regionalcards;

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
    
} Nationalcards;

#endif