#include <lcd_kendi_kutuphane_deneme_1.h> 

#include <benim_LCD.c>  
//#include <LCD_b_v1.c>
                                                                 
void main()      
{                        
   
   lcd_init();
  
 
   while(TRUE)                                 
   {   
                                                                              
                    
      imlec(1,1);
      printf(lcd_veri,"Kendi LCD Dosya");            
      delay_ms(1000);
      imlec(2,4);                                             
      printf(lcd_veri,"Denememiz"); 
      delay_ms(1000);
      lcd_komut(0x01);       
      lcd_komut(0x0E);               
      imlec(1,6);                        
      printf(lcd_veri,"C"); delay_ms(1000);                     
      printf(lcd_veri,"C"); delay_ms(1000);
      printf(lcd_veri,"S"); delay_ms(1000);
      printf(lcd_veri,"C"); delay_ms(1000);
      lcd_komut(0x01);
   }                                        
                                                         
}                                   
