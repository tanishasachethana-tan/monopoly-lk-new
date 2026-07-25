#ifndef BOARD_H
#define BOARD_H
#define BOARD_SIZE 40

typedef enum  {
    GO,Pettah,Community_Development_Fund,Maradana,Income_Tax,Colombo_Fort_Railway_Station,Bambalapitiya,National_Event_Card1,Wellawatte,Mount_Lavinia,Jail_visiting,Nugegoda,CEB,Maharagama,Kottawa,Kandy_Railway_Station,Negombo,Sri_Lanka_Insurance,Katunayake,Ja_Ea,Free_Parking,Kandy_City,National_Event_Card2,Peradeniya,Katugastota,Galle_Railway_Station,Galle_Fort,Unawatuna,National_Water_Supply_and_Drainage_Board,Hikkaduwa,Go_To_Jail,Jaffna_Town,Nallur,Ceylinco_Insurance,Trincomalee,Jaffna_Railway_Station,National_Event_Card3,Nuwara_Eliya,BOC,Galle_Face
}squarename;
typedef enum  {
    start,property,event,tax,railway,special,utility,insurance,bank
}squaretype;

typedef struct {
    squarename name;
    squaretype type;
} Square;

extern Square board[BOARD_SIZE];
void boardin(Square board[BOARD_SIZE]);

#endif // BOARD_H