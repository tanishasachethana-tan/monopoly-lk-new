#include<stdio.h>
#include "board.h"

Square board[BOARD_SIZE];
void boardin(Square board[BOARD_SIZE]) {
 
board[0].name = GO;
board[0].type = start;
board[0].purchase_price = 0;
board[0].base_rent = 0;
board[0].color = NO_COLOR; 
    
board[1].name = Pettah;
board[1].type = property;
board[1].purchase_price = 1500;
board[1].base_rent = 100;
board[1].color= Brown;

board[2].name = Community_Development_Fund;
board[2].type = event;
board[2].purchase_price = 0;
board[2].base_rent = 0;
board[2].color = NO_COLOR; 

board[3].name = Maradana;
board[3].type = property;
board[3].purchase_price = 1800;
board[3].base_rent = 120;
board[3].color= Brown;

board[4].name = Income_Tax;
board[4].type = tax;
board[4].purchase_price = 0;
board[4].base_rent = 0;
board[4].color = NO_COLOR; 

board[5].name = Colombo_Fort_Railway_Station;
board[5].type = railway;
board[5].purchase_price = 0;
board[5].base_rent = 0;
board[5].color = NO_COLOR; 

board[6].name = Bambalapitiya;
board[6].type = property;
board[6].purchase_price = 2500;
board[6].base_rent = 250;
board[6].color= Light_blue;

board[7].name = National_Event_Card1;
board[7].type = event;
board[7].purchase_price = 0;
board[7].base_rent = 0;
board[7].color = NO_COLOR; 

board[8].name = Wellawatte;
board[8].type = property;
board[8].purchase_price = 2700;
board[8].base_rent = 200;
board[8].color= Light_blue;

board[9].name = Mount_Lavinia;
board[9].type = property;
board[9].purchase_price = 3000;
board[9].base_rent = 220;
board[9].color= Light_blue;

board[10].name = Jail_visiting;
board[10].type = special;
board[10].purchase_price = 0;
board[10].base_rent = 0;
board[10].color = NO_COLOR; 

board[11].name = Nugegoda;
board[11].type = property;
board[11].purchase_price = 3500;
board[11].base_rent = 260;
board[11].color= Pink;

board[12].name = CEB;
board[12].type = utility;
board[12].purchase_price = 0;
board[12].base_rent = 0;
board[12].color = NO_COLOR; 

board[13].name = Maharagama;
board[13].type = property;
board[13].purchase_price = 3800;
board[13].base_rent = 280;
board[13].color= Pink;

board[14].name = Kottawa;
board[14].type = property;
board[14].purchase_price = 4000;
board[14].base_rent = 300;
board[14].color= Pink;

board[15].name = Kandy_Railway_Station;
board[15].type = railway;
board[15].purchase_price = 0;
board[15].base_rent = 0;
board[15].color = NO_COLOR; 

board[16].name = Negombo;
board[16].type = property;
board[16].purchase_price = 4500;
board[16].base_rent = 350;
board[16].color= Orange;

board[17].name = Sri_Lanka_Insurance;
board[17].type = insurance;
board[17].purchase_price = 0;
board[17].base_rent = 0;
board[17].color = NO_COLOR; 

board[18].name = Katunayake;
board[18].type = property;
board[18].purchase_price = 4700;
board[18].base_rent = 370;
board[18].color= Orange;

board[19].name = Ja_Ea;
board[19].type = property;
board[19].purchase_price = 5000;
board[19].base_rent = 400;
board[19].color= Orange;

board[20].name = Free_Parking;
board[20].type = special;
board[20].purchase_price = 0;
board[20].base_rent = 0;
board[20].color = NO_COLOR; 

board[21].name = Kandy_City;
board[21].type = property;
board[21].purchase_price = 5500;
board[21].base_rent = 450;
board[21].color= Red;

board[22].name = National_Event_Card2;
board[22].type = event;
board[22].purchase_price = 0;
board[22].base_rent = 0;
board[22].color = NO_COLOR; 

board[23].name = Peradeniya;
board[23].type = property;
board[23].purchase_price = 5800;
board[23].base_rent = 480;
board[23].color= Red;

board[24].name = Katugastota;
board[24].type = property;
board[24].purchase_price = 6000;
board[24].base_rent = 500;
board[24].color= Red;

board[25].name = Galle_Railway_Station;
board[25].type = railway;
board[25].purchase_price = 0;
board[25].base_rent = 0;
board[25].color = NO_COLOR; 

board[26].name = Galle_Fort;
board[26].type = property;
board[26].purchase_price = 6500;
board[26].base_rent = 600;
board[26].color= Yellow;

board[27].name = Unawatuna;
board[27].type = property;
board[27].purchase_price = 6800;
board[27].base_rent = 620;
board[27].color= Yellow;

board[28].name = National_Water_Supply_and_Drainage_Board;
board[28].type = utility;
board[28].purchase_price = 0;
board[28].base_rent = 0;
board[28].color = NO_COLOR; 

board[29].name = Hikkaduwa;
board[29].type = property;
board[29].purchase_price = 7000;
board[29].base_rent = 650;
board[29].color= Yellow;

board[30].name = Go_To_Jail;
board[30].type = special;
board[30].purchase_price = 0;
board[30].base_rent = 0;
board[30].color = NO_COLOR; 

board[31].name = Jaffna_Town;
board[31].type = property;
board[31].purchase_price = 8000;
board[31].base_rent = 750;
board[31].color= Green;

board[32].name = Nallur;
board[32].type = property;
board[32].purchase_price = 8300;
board[32].base_rent = 780;
board[32].color= Green;

board[33].name = Ceylinco_Insurance;
board[33].type = insurance;
board[33].purchase_price = 0;
board[33].base_rent = 0;
board[33].color = NO_COLOR; 

board[34].name = Trincomalee;
board[34].type = property;
board[34].purchase_price = 8500;
board[34].base_rent = 800;
board[34].color= Green;

board[35].name = Jaffna_Railway_Station;
board[35].type = railway;
board[35].purchase_price = 0;
board[35].base_rent = 0;
board[35].color = NO_COLOR; 

board[36].name = National_Event_Card3;
board[36].type = event;
board[36].purchase_price = 0;
board[36].base_rent = 0;
board[36].color = NO_COLOR; 

board[37].name = Nuwara_Eliya;
board[37].type = property;
board[37].purchase_price = 10000;
board[37].base_rent = 1000;
board[37].color= Dark_blue;

board[38].name = BOC;
board[38].type = bank;
board[38].purchase_price = 0;
board[38].base_rent = 0;
board[38].color = NO_COLOR; 

board[39].name = Galle_Face;
board[39].type = property;
board[39].purchase_price = 12000;
board[39].base_rent = 1200;
board[39].color= Dark_blue;


}

