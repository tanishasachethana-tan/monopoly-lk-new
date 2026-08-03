#ifndef BOARD_H
#define BOARD_H


typedef enum  {
    GO,Pettah,Community_Development_Fund,Maradana,Income_Tax,Colombo_Fort_Railway_Station,Bambalapitiya,National_Event_Card1,Wellawatte,Mount_Lavinia,Jail_visiting,Nugegoda,CEB,Maharagama,Kottawa,Kandy_Railway_Station,Negombo,Sri_Lanka_Insurance,Katunayake,Ja_Ea,Free_Parking,Kandy_City,National_Event_Card2,Peradeniya,Katugastota,Galle_Railway_Station,Galle_Fort,Unawatuna,National_Water_Supply_and_Drainage_Board,Hikkaduwa,Go_To_Jail,Jaffna_Town,Nallur,Ceylinco_Insurance,Trincomalee,Jaffna_Railway_Station,National_Event_Card3,Nuwara_Eliya,BOC,Galle_Face
}squarename;

//const char *namearr[] = {"GO","Pettah","Community_Development_Fund","Maradana","Income_Tax","Colombo_Fort_Railway_Station","Bambalapitiya","National_Event_Card1","Wellawatte","Mount_Lavinia","Jail_visiting","Nugegoda","CEB","Maharagama","Kottawa","Kandy_Railway_Station","Negombo","Sri_Lanka_Insurance","Katunayake","Ja_Ea","Free_Parking","Kandy_City","National_Event_Card2","Peradeniya","Katugastota","Galle_Railway_Station","Galle_Fort","Unawatuna","National_Water_Supply_and_Drainage_Board","Hikkaduwa","Go_To_Jail","Jaffna_Town","Nallur","Ceylinco_Insurance","Trincomalee","Jaffna_Railway_Station","National_Event_Card3","Nuwara_Eliya","BOC","Galle_Face"};

typedef enum  {
    start,property,event,tax,railway,special,utility,insurance,bank
}squaretype;

typedef enum{
   NO_COLOR,Brown,Light_blue,Pink,Orange,Red,Yellow,Green,Dark_blue
}squarecolor;

typedef struct {
    char name[50];
    squaretype type;
    squarecolor color;
    double purchase_price;
    double base_rent;
    double house_price;
    double hotel_price;
    double mortgage_value;
    int owner;
    int house_count;

    
} Square;

extern Square board[40];
void boardin(Square board[40]);

#endif // BOARD_H