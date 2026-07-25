#include<stdio.h>
#include "board.h"
#include "dice.h"

int main(){
    boardin(board); //board initialization
    roll_dice(); //rolling dice
      printf("Dice value: %d\n", roll_dice());


}