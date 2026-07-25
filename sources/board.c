#include<stdio.h>
#include "board.h"

Square board[BOARD_SIZE];
void boardin(Square board[]){
board[0].name = GO;
board[0].type = start;

board[1].name = Pettah;
board[1].type = property;

board[2].name = Community_Development_Fund;
board[2].type = event;

board[3].name = Maradana;
board[3].type = property;

board[4].name = Income_Tax;
board[4].type = tax;

board[5].name = Colombo_Fort_Railway_Station;
board[5].type = railway;

board[6].name = Bambalapitiya;
board[6].type = property;

board[7].name = National_Event_Card1;
board[7].type = event;

board[8].name = Wellawatte;
board[8].type = property;

board[9].name = Mount_Lavinia;
board[9].type = property;

board[10].name = Jail_visiting;
board[10].type = special;

board[11].name = Nugegoda;
board[11].type = property;

board[12].name = CEB;
board[12].type = utility;

board[13].name = Maharagama;
board[13].type = property;

board[14].name = Kottawa;
board[14].type = property;

board[15].name = Kandy_Railway_Station;
board[15].type = railway;

board[16].name = Negombo;
board[16].type = property;

board[17].name = Sri_Lanka_Insurance;
board[17].type = insurance;

board[18].name = Katunayake;
board[18].type = property;

board[19].name = Ja_Ea;
board[19].type = property;

board[20].name = Free_Parking;
board[20].type = special;

board[21].name = Kandy_City;
board[21].type = property;

board[22].name = National_Event_Card2;
board[22].type = event;

board[23].name = Peradeniya;
board[23].type = property;

board[24].name = Katugastota;
board[24].type = property;

board[25].name = Galle_Railway_Station;
board[25].type = railway;

board[26].name = Galle_Fort;
board[26].type = property;

board[27].name = Unawatuna;
board[27].type = property;

board[28].name = National_Water_Supply_and_Drainage_Board;
board[28].type = utility;

board[29].name = Hikkaduwa;
board[29].type = property;

board[30].name = Go_To_Jail;
board[30].type = special;

board[31].name = Jaffna_Town;
board[31].type = property;

board[32].name = Nallur;
board[32].type = property;

board[33].name = Ceylinco_Insurance;
board[33].type = insurance;

board[34].name = Trincomalee;
board[34].type = property;

board[35].name = Jaffna_Railway_Station;
board[35].type = railway;

board[36].name = National_Event_Card3;
board[36].type = event;

board[37].name = Nuwara_Eliya;
board[37].type = property;

board[38].name = BOC;
board[38].type = bank;

board[39].name = Galle_Face;
board[39].type = property;  

}

