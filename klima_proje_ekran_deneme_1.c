
 
                     //********** KL�MA PROJES� **********//  
                     //                                   //                    
                     //                                   //                     
                     //                                   //
                     //                                   //
                     ///////////////////////////////////////
                                                 
                                         

// ********** KUTUPHANELER **********          
#include <16F877A.h>
#device ADC=10
#FUSES NOWDT,NOBROWNOUT,NOLVP 
#use delay(crystal=4MHz)  
#include <benim_LCD.c>   // KEND� LCD KUTUPHANEM  
                                  
// ********** TANIMLAMALAR **********                                             
                          

                  
#use fast_io(ALL)
                                                      
//                     ********** BUTONLAR **********

#define YUKARI   PIN_B4
#define ASAGI    PIN_B5        
#define ENTER    PIN_B6                   
#define ON_OFF   PIN_B0
 
#priority ext, rb, timer0  // KESME ONCELIGI                                                    


//                 ********** GLOBAL DEGISKENLER **********

int8 menu_sayac =  1; // MENU Se�imlerinde kullan�lan degi�ken   
int8 tmp = 0;         // Menu Se�imlerinde kullan�lan Algoritma degi�keni                                       
//                 ********* FONKSIYON ORNEKLERI  ********** 
                       


void lcd_menu(int8 liste_secim);
void ok_isareti(int8 konum);             
void fan_ayar_fonksiyonu_menu(); 
              


//                    INTCON REGISTER PINLERI 
struct{        
int1 RBIF;     // RB Portunun De�i�im Bayrag� biti        
int1 INTF;     // RB0 External Kesme Bayrag� biti
int1 TMR0IF;   // TMR0 Kesme Bayrag�      
int1 RBIE;     // RB Portu Kesme Aktif biti
int1 INTE;     // RB0 Pin Kesme Aktif biti                             
int1 TMR0IE;   // TMR0 Kesme Aktif/Pasif              
int1 PEIE;     // �evresel Kesmeler Aktif                    
int1 GIE;      // Global Kesme Aktif     
}INTCON;  

struct{
int1 T2CKPSC0;
int1 T2CKPSC1;            
int1 TMR2ON;
int1 TOUTPS0;
int1 TOUTPS1;   
int1 TOUTPS2;
int1 TOUTPS3;
int1 NA;                                              
}T2CON;                

//                        REGISTER ADRESLER�

#byte INTCON  =  0x8B
#byte T2CON   =  0x12   //  Timer 2 Kontrol Register
#byte PR2     =  0x92   //  PR2 Register� TMR2 ile kar��la�t�r�l�r                       
#byte TMR2    =  0x11   //  TMR2 Register� PR2 ile kar��la�t�r�l�r 
#byte PIR1    =  0x0C   //  Timer 2 Kesmede kullan�lmas� i�in     
#byte PIE1    =  0x8C   //  Timer 2 Kesmede kullan�lmas� i�in                                   
#byte CCP1CON =  0x17   //  CCP Kontrol Register� PWM Moduna Ayarlanacak Main'de 
#byte CCPR1L  =  0x15                                                          
#byte CCPR1H  =  0x16  


#byte TRISA   =  0x85                
#byte TRISB   =  0x86                            
#byte TRISC   =  0x87   
#byte TRISD   =  0x88
#byte TRISE   =  0x89                    
#byte PORTA   =  0x05
#byte PORTB   =  0x06         
#byte PORTC   =  0x07
#byte PORTD   =  0x08 
#byte PORTE   =  0x09   

////                ********** KESMELER **********                ///// 

//********** B0 Kesmesi 
#INT_EXT
void acma_kapa_butonu_kesme(void){

                                                
                       
             
    
    INTCON.INTF = 0; // B0 bayrag� reset. Tekrardan kesmeye haz�r
    
}

                                                                                      
                                                  
// B PORTU 4 ve 7 PINLERI KESME 
#INT_RB                   
void RB_Port_degisim_aktif(void){       

                                        
   if(!input(YUKARI)){    
        delay_ms(20);
        menu_sayac++;  
   }                                      
   if(!input(ASAGI)){
        delay_ms(20);
        menu_sayac--;            
   }
   
   
   if(menu_sayac > 4 || menu_sayac < 1)                                                  
      menu_sayac = tmp;   
   
   if(!input(ENTER)){
      
        switch()
     
   }
   
   if(tmp != menu_sayac){
                                        
      lcd_menu(menu_sayac);
      ok_isareti(menu_sayac);      
      delay_ms(20);    
      tmp = menu_sayac;        
   
   }                                                  
    
   
   INTCON.RBIF = 0;  // RB bayrag� reset. Tekrardan kesmeye haz�r 
}                           
//                     *********** FONKSIYONLAR ***********
void fan_ayar_fonksiyonu_menu(){
         

}


                               
 
//                ********** LCD ye MENUYU YAZDIRMA **********

// liste_secim menude gozukecek Listeyi belirler 
void lcd_menu(int8 liste_secim)                    
{                                                              
        
   if(liste_secim<=2){    
     lcd_komut(0x01);                           
     printf(lcd_veri," Sicaklik Ayari"); 
     lcd_komut(0xC0); 
     printf(lcd_veri," Fan Ayari");                     
                                              
   }
   else if(liste_secim>2){
      lcd_komut(0x01);                         
      printf(lcd_veri," 3.Menu");               
      lcd_komut(0xC0); 
      printf(lcd_veri," 4.Menu");          
   }
   imlec(2,13);                                                  
   printf(lcd_veri," %d",liste_secim);                                
    
}                            

                     
//                   ********** LCD SEC�M �SARETI **********  
void ok_isareti(int8 konum){

   if(konum%2 == 0)
      konum = 2;                             
   else
      konum = 1;
   imlec(konum,1);
   printf(lcd_veri,">");
   
}
                                                  
                                                             
//                     *********** ANA KOD ************     
void main()           
{  
                                
   TRISA   =  0x00;                 
   PORTA   =  0x00;                  
   TRISB   =  0xFF;                                              
   PORTB   =  0x00;         
   TRISC   =  0x00;                     
   PORTC   =  0x00;
   
   CCPR1L  =  0x10;      
   CCP1CON =  0x0C;       
   T2CON   =  0x01;          
                       
   PR2 = 249;          // PR2 Timer 2 nin Kar��la�t�rma Reg. dir.                     
   TMR2 = 0;           // Timer 2 Register� 0 
   lcd_init();         // LCD Ba�lat                   
   lcd_menu(1);        // LCD ilk men� yaz�lmas� i�in               
   INTCON  =  0x98;    // INTCON REGISTER Global, B0 ve RB Port Kesme Aktif
   T2CON.TMR2ON = 1;   // Timer 2 ON Aktif 
                                                       
   
   
   while(TRUE)
   {                          
          
   }                                        

}                                        
