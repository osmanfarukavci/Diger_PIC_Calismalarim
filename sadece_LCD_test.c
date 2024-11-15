#include <sadece_LCD_test.h>

#FUSES NOWDT                    
#FUSES NOBROWNOUT               
#FUSES NOLVP                       
 
#define Yukari pin_b4
#define Asagi  pin_b5
#define enter  pin_b6
#define use_portd_lcd TRUE
 
#include <lcd.c>                          
                  
#use fast_io(ALL)

void ana_menu(void);
void ok_isareti(int8 konum);
                                                                           
void sicaklik_menu(void);
 
void sicaklik_ayar(void); 
void fan_menu(void);
void ekran_temizle(void);
void fan_kademe_ayar(void);
void ana_ekrana_don(void);
void mod_menu(void);
void mod_secim(void);
#separate
void tarih_ve_saat_menu(void);
#separate
void tarih_ayar(void);
void saat_ayar(void);

void durum_ekrani(void);
void menu_sablon(void);


int16 ana_sayac = 1;
int16 ana_sayac_old = 1;
int8 sayfa = 10;
int1 enter_toggel = 0;
int16 sayfa_limit = 4;
int8 sicaklik = 25;                    
int1 sicaklik_mod = 0; // 0 Soguk / 1 Sicak
int8 sicaklik_durum = 0;
int8 fan_hiz_kademe = 0;
int16 sayfa_alt_limit = 1;
int8 gun = 1;
int8 ay  = 1;
int16 yil = 2023;
int8 saniye = 0;
int8 dakika = 0;
int8 saat = 12;                    
int8 i = 0;

  
#int_rb 
void B_port_degisim_kesmesi(){

   if(!input(Yukari)){
     ana_sayac++;
     delay_ms(20);                                   
    
   }
   
   if(!input(Asagi)){
     ana_sayac--;
     delay_ms(20);               
   }                                         
   
   if(!input(enter)){
      enter_toggel = 1;                                                                                       
   }
  
   if(ana_sayac < sayfa_alt_limit || ana_sayac > sayfa_limit)
         ana_sayac = ana_sayac_old;
    
   menu_sablon();

   
                                    
   enter_toggel = 0;     
}                                          

void menu_sablon(void){

     switch(sayfa){
      case 0:                      
         ana_menu();
         ok_isareti(ana_sayac);
         break;                   
      case 1:              //   SICAKLIK MENU 
         sicaklik_menu();
         ok_isareti(ana_sayac);
         break;          
      case 2:          
         fan_menu();       //   FAN     MENU
         ok_isareti(ana_sayac);
         break;                            
      case 3:              //   MOD     MENU
         mod_menu();
         ok_isareti(ana_sayac);
         break;         
      case 4:              //   TARÝH SAAAT MENU
         tarih_ve_saat_menu();
         ok_isareti(ana_sayac);
         break;        
      case 5:              // Sýcaklik Ayari Fonksiyonu      
         sicaklik_ayar();
         break;           
      case 6:              // Fan Kademe Ayari Fonksiyonu
         fan_kademe_ayar();
         break;
      case 7:              // Modlar 
         mod_secim();
         ok_isareti(ana_sayac);
         break;                                 
      case 8:              // Tarih Ayari Fonksiyonu
         tarih_ayar();
         break;
      case 9:              // Saat Ayari Fonksiyonu
         saat_ayar();
         break;
      case 10:
         durum_ekrani();
      default:                                     
         sayfa = 0;
         break; 
   }
}
                                              
void ana_menu(void){
   
  sayfa_limit = 4;             
  if(ana_sayac<=2){
     ekran_temizle();                         
     printf(lcd_putc," Sicaklik");
     lcd_gotoxy(2,2);                      
     printf(lcd_putc,"Fan");
   }
   else if(ana_sayac>2 && ana_sayac<=4){
     ekran_temizle();
     printf(lcd_putc," Mod");
     lcd_gotoxy(2,2);
     printf(lcd_putc,"Tarih ve Saat");
   
   }
   lcd_gotoxy(15,1);
   printf(lcd_putc,"%ld",ana_sayac);
   
   if(enter_toggel){
                                                  
       sayfa = ana_sayac;        
       ana_sayac = 1;
       ana_sayac_old = 1;
   }                  
   
}              
                                       
void sicaklik_menu(void){
   
   sayfa_limit = 2;
   ekran_temizle();                                     
   printf(lcd_putc," Sicaklik Ayari"); 
   lcd_gotoxy(2,2);
   printf(lcd_putc,"Geri");                     
   lcd_gotoxy(14,2);       
   printf(lcd_putc,"%02d",sicaklik);
   lcd_putc(223);     // sicaklik Derece isareti   
   if(enter_toggel){    
     if(ana_sayac == 1)
     {     
          sayfa = 5;
          sayfa_limit = 60;
          ana_sayac = sicaklik;
     
     }
     else if(ana_sayac == 2)
     {
       ana_ekrana_don();      
     }
      
       
   } 


}
void sicaklik_ayar(void){

   
   ekran_temizle();      
   printf(lcd_putc," Sicaklik Ayari :\n %02d",sicaklik);
   sicaklik = ana_sayac; 
   if(enter_toggel){                
       
      sayfa = 1;
      ana_sayac = 1;
   }
   
}
void fan_menu(void){                
     
    ekran_temizle();
    sayfa = 2;
    sayfa_limit = 2;
    printf(lcd_putc," Fan Kademe Ayari"); 
    lcd_gotoxy(2,2);
    printf(lcd_putc,"Geri");
    lcd_gotoxy(8,2);
    printf(lcd_putc,"%d.Kademe",fan_hiz_kademe);
    if(enter_toggel){
      if(ana_sayac == 1){
          sayfa = 6;
          sayfa_limit = 5;
          sayfa_alt_limit = 0;
          ana_sayac = fan_hiz_kademe;
      
      }
      else if(ana_sayac == 2){
          
          ana_ekrana_don();
          
      } 
     
    
    }  
                                                  
}
void fan_kademe_ayar(void){ 
   
   ekran_temizle();          
   printf(lcd_putc," FAN KADEMESI : \n%d",fan_hiz_kademe);
   fan_hiz_kademe = ana_sayac;              
   if(enter_toggel){
       sayfa = 2;
       ana_sayac = 1;
       sayfa_alt_limit = 1;
   }
}
void mod_menu(void){                               
   
   sayfa = 3;
   sayfa_limit = 3;               
   if(ana_sayac <= 2){ 
                
      ekran_temizle(); 
      printf(lcd_putc," Mod SECIMI YAP :"); 
      lcd_gotoxy(2,2);
      if(sicaklik_mod == 0)         
         printf(lcd_putc,"MOD: SOGUK");
      else                         
         printf(lcd_putc,"MOD: SICAK");                                       
   } 
   else if(ana_sayac >=3)
   {
      ekran_temizle();   
      printf(lcd_putc," Geri");     
   }                            
   if(enter_toggel){
      if(ana_sayac == 1){
          sayfa = 7;
          sayfa_limit = 2;
                                        
      }
      else if(ana_sayac == 3){
      
          ana_ekrana_don();
          
      }
                     
    }   
                         

}                                        
void mod_secim(void){
                                
     ekran_temizle();
     printf(lcd_putc," SICAK");
     lcd_gotoxy(2,2); 
     printf(lcd_putc,"SOGUK");
     if(enter_toggel)
     {
         if(ana_sayac == 1)
            sicaklik_mod = 1;
         else
            sicaklik_mod = 0;
         sayfa = 3;
     }                                     
}
#separate 
void tarih_ve_saat_menu(){
   ok_isareti(ana_sayac);                                 
   sayfa = 4;
   sayfa_limit = 3;
   if(ana_sayac <= 2){             
      ekran_temizle();
      printf(lcd_putc," Tarih:%02d/%02d/%02ld",gun,ay,yil); 
      lcd_gotoxy(2,2);
      printf(lcd_putc,"SAAT:%02d:%02d:%02d"saat,dakika,saniye);                             
                   
   }                             
   else if(ana_sayac <=3)           
   {                          
      ekran_temizle();   
      printf(lcd_putc," Geri");     
   }
   if(enter_toggel){
      
      if(ana_sayac == 1){                 
          sayfa = 8;
      }
      else if(ana_sayac == 2){
          sayfa = 9;      
      }
      else if(ana_sayac == 3){ 
       ana_ekrana_don();
      }
   
   
   }
                    
                                     

}
#separate 
void tarih_ayar(){
    
    if(enter_toggel){
      i++;    
      ana_sayac = 1; 
    }                               
    if(i == 0)
    {
    ekran_temizle();
    sayfa_limit = 30;
    sayfa_alt_limit = 0;    
    printf(lcd_putc," GUN :%02d",gun);
    gun = ana_sayac;   
    }
    else if(i == 1){
    ekran_temizle();
    sayfa_limit = 12;       
    sayfa_alt_limit = 1;
    printf(lcd_putc," AY : %02d",ay);
    ay = ana_sayac;         
                           
    }
    else if(i == 2){   // YIL BAÞLANGIÇ AYARI ÝÇÝN Basit bir hile yapýlmýþtýr
      ana_sayac = 2023;
      i++;
    }
    if(i == 3){
    ekran_temizle();
    sayfa_limit = 3000;                   
    sayfa_alt_limit = 2000;
    ana_sayac_old = 2023;     
    printf(lcd_putc," YIL : %ld",yil);
    yil = ana_sayac;                
                         
    }                                                                                            
    else if(i == 4)  
    {         
      sayfa = 4;
      i = 0;
      sayfa_limit = 4;       
      sayfa_alt_limit = 1;
      ana_sayac = 1;                                                            
      ana_sayac_old = 1;
    }                          
                          
}           
void saat_ayar(){                     
    if(enter_toggel){
      i++;    
      ana_sayac = 0;                                       
    }                               
    if(i == 0)
    {
    ekran_temizle();           
    sayfa_limit = 23;             
    sayfa_alt_limit = 0;           
    printf(lcd_putc," Saat :%02d",saat);
    saat = ana_sayac;     
    }                                                               
    else if(i == 1){       
    ekran_temizle();                                                                                                                   
    sayfa_limit = 59;       
    sayfa_alt_limit = 0;                                                              
    printf(lcd_putc," Dakika : %02d",dakika); 
    dakika = ana_sayac;         
                           
    }                                                                                                               
    else if(i == 2)                                    
    {                                                                   
      sayfa = 4;
      i = 0;
      sayfa_limit = 4;       
      sayfa_alt_limit = 1;
      ana_sayac = 1;                                                            
      ana_sayac_old = 1;
    } 

}                                 
void ok_isareti(int8 konum){                                             
     if(konum%2 == 0)
      konum = 2;
     else
      konum = 1;
     lcd_gotoxy(1,konum);
     printf(lcd_putc,">");                                               

}  
void ekran_temizle(){         
   lcd_send_byte(0,0x01);
}
void ana_ekrana_don(void){
   sayfa = 0;
   ana_sayac = 1;    
}
void durum_ekrani(){
   
   ekran_temizle();
   lcd_gotoxy(1,1);
   printf(lcd_putc," Sicaklik %02d",sicaklik_durum);
   lcd_putc(223);                                          
   lcd_gotoxy(1,2);
   printf(lcd_putc,"Saat %02d:%02d",saat,dakika);            
   printf(lcd_putc," Fan %d",fan_hiz_kademe);
   if(enter_toggel)
   {
      sayfa = 0;                    
   }
                                        
}
void main()                                                                                                                                                                      
{                                                                                                         
                                            
   set_tris_d(0x00);
   
   lcd_init();                                                               
   enable_interrupts(int_rb);
   enable_interrupts(GLOBAL);
   sayfa = 10;                                      
                                          
   while(TRUE)
   {            
  
                             
                                
   }                               
}                                                         
