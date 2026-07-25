#include "dice.h"
#include <stdlib.h>
#include <time.h>

int roll_dice() {
    srand(time(0)); 
    int die_num=(rand() % 12) + 1; 
    return die_num;
}