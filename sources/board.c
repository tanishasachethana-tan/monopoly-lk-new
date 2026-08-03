#include<stdio.h>
#include<string.h>
#include "board.h"
#include "dice.h"

Square board[40];
void boardin(Square board[40]) {
 
strcpy(board[0].name, "GO");
board[0].type = start;
board[0].color = NO_COLOR; 
board[0].purchase_price = 0;
board[0].base_rent = 0;
board[0].house_price = 0;
board[0].hotel_price = 0;
board[0].mortgage_value = 0;
board[0].owner = -1;
board[0].house_count = 0;

    
strcpy(board[1].name, "Pettah");
board[1].type = property;
board[1].color= Brown;
board[1].purchase_price = 1500;
board[1].base_rent = 100;
board[1].house_price = 500;
board[1].hotel_price = 2000;
board[1].mortgage_value = 750;
board[1].owner = -1;
board[1].house_count = 0;

strcpy(board[2].name, "Community_Development_Fund");
board[2].type = event;
board[2].color = NO_COLOR;
board[2].purchase_price = 0;
board[2].base_rent = 0;
board[2].house_price = 0;
board[2].hotel_price = 0;
board[2].mortgage_value = 0;
board[2].owner = -1;
board[2].house_count = 0;


strcpy(board[3].name, "Maradana");
board[3].type = property;
board[3].color= Brown;
board[3].purchase_price = 1800;
board[3].base_rent = 120;
board[3].house_price = 500;
board[3].hotel_price = 2000;
board[3].mortgage_value = 750;
board[3].owner = -1;
board[3].house_count = 0;



strcpy(board[4].name, "Income_Tax");
board[4].type = tax;
board[4].color = NO_COLOR; 
board[4].purchase_price = 0;
board[4].base_rent = 0;
board[4].house_price = 0;
board[4].hotel_price = 0;
board[4].mortgage_value = 0;
board[4].owner = -1;
board[4].house_count = 0;



strcpy(board[5].name, "Colombo_Fort_Railway_Station");
board[5].type = railway;
board[5].color = NO_COLOR; 
board[5].purchase_price = 0;
board[5].base_rent = 0;
board[5].house_price = 0;
board[5].hotel_price = 0;
board[5].mortgage_value = 0;
board[5].owner = -1;
board[5].house_count = 0;


strcpy(board[6].name, "Bambalapitiya");
board[6].type = property;
board[6].color= Light_blue;
board[6].purchase_price = 2500;
board[6].base_rent = 250;
board[6].house_price = 750;
board[6].hotel_price = 3000;
board[6].mortgage_value = 1250;
board[6].owner = -1;
board[6].house_count = 0;



strcpy(board[7].name, "National_Event_Card1");
board[7].type = event;
board[7].color = NO_COLOR; 
board[7].purchase_price = 0;
board[7].base_rent = 0;
board[7].house_price = 0;
board[7].hotel_price = 0;
board[7].mortgage_value = 0;
board[7].owner = -1;
board[7].house_count = 0;


strcpy(board[8].name, "Wellawatte");
board[8].type = property;
board[8].color= Light_blue;
board[8].purchase_price = 2700;
board[8].base_rent = 200;
board[8].house_price = 750;
board[8].hotel_price = 3000;
board[8].mortgage_value = 1250;
board[8].owner = -1;
board[8].house_count = 0;



strcpy(board[9].name, "Mount_Lavinia");
board[9].type = property;
board[9].color= Light_blue;
board[9].purchase_price = 3000;
board[9].base_rent = 220;
board[9].house_price = 750;
board[9].hotel_price = 3000;
board[9].mortgage_value = 1250;
board[9].owner = -1;
board[9].house_count = 0;



strcpy(board[10].name, "Jail_visiting");
board[10].type = special;
board[10].color = NO_COLOR; 
board[10].purchase_price = 0;
board[10].base_rent = 0;
board[10].house_price = 0;
board[10].hotel_price = 0;  
board[10].mortgage_value = 0;
board[10].owner = -1;
board[10].house_count = 0;


strcpy(board[11].name, "Nugegoda");
board[11].type = property;
board[11].color= Pink;
board[11].purchase_price = 3500;
board[11].base_rent = 260;
board[11].house_price = 1000;
board[11].hotel_price = 4000;
board[11].mortgage_value = 1750;
board[11].owner = -1;
board[11].house_count = 0;



strcpy(board[12].name, "CEB");
board[12].type = utility;
board[12].color = NO_COLOR;
board[12].purchase_price = 0;
board[12].base_rent = 0;
board[12].house_price = 0;
board[12].hotel_price = 0;
board[12].mortgage_value = 0;
board[12].owner = -1;
board[12].house_count = 0;

 

strcpy(board[13].name, "Maharagama");
board[13].type = property;
board[13].color= Pink;
board[13].purchase_price = 3800;
board[13].base_rent = 280;
board[13].house_price = 1000;
board[13].hotel_price = 4000;
board[13].mortgage_value = 1750;
board[13].owner = -1;
board[13].house_count = 0;



strcpy(board[14].name, "Kottawa");
board[14].type = property;
board[14].color= Pink;
board[14].purchase_price = 4000;
board[14].base_rent = 300;
board[14].house_price = 1000;
board[14].hotel_price = 4000;
board[14].mortgage_value = 1750;
board[14].owner = -1;
board[14].house_count = 0;



strcpy(board[15].name, "Kandy_Railway_Station");
board[15].type = railway;
board[15].color = NO_COLOR; 
board[15].purchase_price = 0;
board[15].base_rent = 0;
board[15].house_price = 0;
board[15].hotel_price = 0;
board[15].mortgage_value = 0;
board[15].owner = -1;
board[15].house_count = 0;



strcpy(board[16].name, "Negombo");
board[16].type = property;
board[16].color= Orange;
board[16].purchase_price = 4500;
board[16].base_rent = 350;
board[16].house_price = 1250;
board[16].hotel_price = 5000;
board[16].mortgage_value = 2250;
board[16].owner = -1;
board[16].house_count = 0;



strcpy(board[17].name, "Sri_Lanka_Insurance");
board[17].type = insurance;
board[17].color = NO_COLOR; 
board[17].purchase_price = 0;
board[17].base_rent = 0;
board[17].house_price = 0;
board[17].hotel_price = 0;
board[17].mortgage_value = 0;
board[17].owner = -1;
board[17].house_count = 0;



strcpy(board[18].name, "Katunayake");
board[18].type = property;
board[18].color= Orange;
board[18].purchase_price = 4700;
board[18].base_rent = 370;
board[18].house_price = 1250;
board[18].hotel_price = 5000;
board[18].mortgage_value = 2250;
board[18].owner = -1;
board[18].house_count = 0;



strcpy(board[19].name, "Ja_Ea");
board[19].type = property;
board[19].color= Orange;
board[19].purchase_price = 5000;
board[19].base_rent = 400;
board[19].house_price = 1250;
board[19].hotel_price = 5000;
board[19].mortgage_value = 2250;
board[19].owner = -1;
board[19].house_count = 0;



strcpy(board[20].name, "Free_Parking");
board[20].type = special;
board[20].color = NO_COLOR; 
board[20].purchase_price = 0;
board[20].base_rent = 0;
board[20].house_price = 0;
board[20].hotel_price = 0;
board[20].mortgage_value = 0;
board[20].owner = -1;
board[20].house_count = 0;



strcpy(board[21].name, "Kandy_City");
board[21].type = property;
board[21].color= Red;
board[21].purchase_price = 5500;
board[21].base_rent = 450;
board[21].house_price = 1500;
board[21].hotel_price = 6000;
board[21].mortgage_value = 2750;
board[21].owner = -1;
board[21].house_count = 0;



strcpy(board[22].name, "National_Event_Card2");
board[22].type = event;
board[22].color = NO_COLOR; 
board[22].purchase_price = 0;
board[22].base_rent = 0;
board[22].house_price = 0;
board[22].hotel_price = 0;
board[22].mortgage_value = 0;
board[22].owner = -1;
board[22].house_count = 0;



strcpy(board[23].name, "Peradeniya");
board[23].type = property;
board[23].color= Red;
board[23].purchase_price = 5800;
board[23].base_rent = 480;
board[23].house_price = 1500;
board[23].hotel_price = 6000;
board[23].mortgage_value = 2750;
board[23].owner = -1;
board[23].house_count = 0;



strcpy(board[24].name, "Katugastota");
board[24].type = property;
board[24].color= Red;
board[24].purchase_price = 6000;
board[24].base_rent = 500;
board[24].house_price = 1500;
board[24].hotel_price = 6000;
board[24].mortgage_value = 2750;
board[24].owner = -1;
board[24].house_count = 0;



strcpy(board[25].name, "Galle_Railway_Station");
board[25].type = railway;
board[25].color = NO_COLOR; 
board[25].purchase_price = 0;
board[25].base_rent = 0;
board[25].house_price = 0;
board[25].hotel_price = 0;
board[25].mortgage_value = 0;
board[25].owner = -1;
board[25].house_count = 0;



strcpy(board[26].name, "Galle_Fort");
board[26].type = property;
board[26].color= Yellow;
board[26].purchase_price = 6500;
board[26].base_rent = 600;
board[26].house_price = 2000;
board[26].hotel_price = 8000;
board[26].mortgage_value = 3250;
board[26].owner = -1;
board[26].house_count = 0;



strcpy(board[27].name, "Unawatuna");
board[27].type = property;
board[27].color= Yellow;
board[27].purchase_price = 6800;
board[27].base_rent = 620;
board[27].house_price = 2000;
board[27].hotel_price = 8000;
board[27].mortgage_value = 3250;
board[27].owner = -1;
board[27].house_count = 0;


strcpy(board[28].name, "National_Water_Supply_and_Drainage_Board");
board[28].type = utility;
board[28].color = NO_COLOR;
board[28].purchase_price = 0;
board[28].base_rent = 0;
board[28].house_price = 0;
board[28].hotel_price = 0;
board[28].mortgage_value = 0;
board[28].owner = -1;
board[28].house_count = 0;


strcpy(board[29].name, "Hikkaduwa");
board[29].type = property;
board[29].color= Yellow;
board[29].purchase_price = 7000;
board[29].base_rent = 650;
board[29].house_price = 2000;
board[29].hotel_price = 8000;
board[29].mortgage_value = 3250;
board[29].owner = -1;
board[29].house_count = 0;



strcpy(board[30].name, "Go_To_Jail");
board[30].type = special;
board[30].color = NO_COLOR; 
board[30].purchase_price = 0;
board[30].base_rent = 0;
board[30].house_price = 0;
board[30].hotel_price = 0;
board[30].mortgage_value = 0;
board[30].owner = -1;
board[30].house_count = 0;


strcpy(board[31].name, "Jaffna_Town");
board[31].type = property;
board[31].color= Green;
board[31].purchase_price = 8000;
board[31].base_rent = 750;
board[31].house_price = 2500;
board[31].hotel_price = 10000;
board[31].mortgage_value = 4000;
board[31].owner = -1;
board[31].house_count = 0;



strcpy(board[32].name, "Nallur");
board[32].type = property;
board[32].color= Green;
board[32].purchase_price = 8300;
board[32].base_rent = 780;
board[32].house_price = 2500;
board[32].hotel_price = 10000;
board[32].mortgage_value = 4000;
board[32].owner = -1;
board[32].house_count = 0;



strcpy(board[33].name, "Ceylinco_Insurance");
board[33].type = insurance;
board[33].color = NO_COLOR;
board[33].purchase_price = 0;
board[33].base_rent = 0;
board[33].house_price = 0;
board[33].hotel_price = 0;
board[33].mortgage_value = 0;
board[33].owner = -1;
board[33].house_count = 0;


strcpy(board[34].name, "Trincomalee");
board[34].type = property;
board[34].color= Green;
board[34].purchase_price = 8500;
board[34].base_rent = 800;
board[34].house_price = 2500;
board[34].hotel_price = 10000;
board[34].mortgage_value = 4000;
board[34].owner = -1;
board[34].house_count = 0;



strcpy(board[35].name, "Jaffna_Railway_Station");
board[35].type = railway;
board[35].color = NO_COLOR; 
board[35].purchase_price = 0;
board[35].base_rent = 0;
board[35].house_price = 0;
board[35].hotel_price = 0;
board[35].mortgage_value = 0;
board[35].owner = -1;
board[35].house_count = 0;



strcpy(board[36].name, "National_Event_Card3");
board[36].type = event;
board[36].color = NO_COLOR; 
board[36].purchase_price = 0;
board[36].base_rent = 0;
board[36].house_price = 0;
board[36].hotel_price = 0;
board[36].mortgage_value = 0;
board[36].owner = -1;
board[36].house_count = 0;



strcpy(board[37].name, "Nuwara_Eliya");
board[37].type = property;
board[37].color= Dark_blue;
board[37].purchase_price = 10000;
board[37].base_rent = 1000;
board[37].house_price = 3000;
board[37].hotel_price = 12000;
board[37].mortgage_value = 5000;
board[37].owner = -1;
board[37].house_count = 0;



strcpy(board[38].name, "BOC");
board[38].type = bank;
board[38].color = NO_COLOR; 
board[38].purchase_price = 0;
board[38].base_rent = 0;
board[38].house_price = 0;
board[38].hotel_price = 0;
board[38].mortgage_value = 0;
board[38].owner = -1;
board[38].house_count = 0;



strcpy(board[39].name, "Galle_Face");
board[39].type = property;
board[39].color= Dark_blue;
board[39].purchase_price = 12000;
board[39].base_rent = 1200;
board[39].house_price = 3000;
board[39].hotel_price = 12000;
board[39].mortgage_value = 5000;
board[39].owner = -1;
board[39].house_count = 0;




}



