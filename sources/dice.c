#include <stdio.h>
#include "dice.h"
#include <stdlib.h>
#include <time.h>
#include "players.h"

int reroll[4]={0,0,0,0};

int roll_dice() {
    int dice_num1=(rand() % 6) + 1; 
    int dice_num2=(rand() % 6) + 1;
    int dice_value = dice_num1 + dice_num2;
    return dice_value;
}
void order_decide(Player players[4]){
    srand(time(0));
    printf("Initial Roll\n");
    printf("------------\n"); 
    for(int i=0;i<4;i++){
        players[i].rank=0;
        players[i].dicevalue=roll_dice();

        printf("%s    : %d\n",players[i].name,players[i].dicevalue);
    }

    int count_arr[4]={0,0,0,0};
    for(int i=0;i<4;i++){
        int count=0;
        for(int j=0;j<4;j++){
            if(players[i].dicevalue==players[j].dicevalue){
            count++;
        }
    }
        count_arr[i]=count;
    }    
    
    int rank_arr[4]={0,0,0,0};
    for(int k=0;k<4;k++){
        if(count_arr[k]==1){
            //ranking
                int higher=0;
                for(int j=0;j<4;j++){
                    if(players[j].dicevalue>players[k].dicevalue){
                        higher++;
                    }
                    }
                    rank_arr[k]=higher+1;
            }
        } 
    
    while(1){    
        for(int i=0;i<4;i++){
            if(count_arr[i]>1){
                printf("\nTie detected! Re-rolling...\n");
                printf("-------------------------------\n");
                players[i].dicevalue=roll_dice();
                 printf("%s re-rolled : %d\n", players[i].name, players[i].dicevalue);
            }
        } 

        for(int x=0;x<4;x++){
            if(rank_arr[x]==0){
                count_arr[x]=0;

                for(int y=0;y<4;y++){
                    if(rank_arr[y]==0 && players[x].dicevalue==players[y].dicevalue){
                        count_arr[x]++;
                    }
                }
            }
        }

    int tie=0;
    for(int i=0;i<4;i++){
        if(count_arr[i]>1){
            tie=1;
        }
    }
    if(tie==0){
        break;
    }
}
            
    int rank_used[4]={0,0,0,0}; 
     for(int i=0;i<4;i++){
        if(rank_arr[i]!=0){
            rank_used[rank_arr[i]-1]=1;
        }
     }

     for(int r=1;r<=4;r++){
    int highest=-1;
    int index=-1;

    for(int k=0;k<4;k++){
        if(rank_arr[k]==0 && players[k].dicevalue>highest){
            highest=players[k].dicevalue;
            index=k;
        }
    }

    if(index!=-1){
        while(rank_used[r-1])
            r++;

        rank_arr[index]=r;
        rank_used[r-1]=1;
    }
}

    for(int m=0;m<4;m++){
        players[m].rank=rank_arr[m];
    }
    

    printf("\nPlayer Order\n");
      printf("------------\n");

for(int r=1; r<=4; r++){
    for(int i=0; i<4; i++){
        if(players[i].rank == r){
            printf("%d. %s\n", r, players[i].name);
        }
    }
}
        
        
}

    
   







    
    
