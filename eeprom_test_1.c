#include <eeprom_test_1.h>
                         
#use fast_io(d)
#use fast_io(b)

#define use_portd_lcd TRUE
#include <LCD.c>

int8 _10ms = 0;
unsigned int8 saniye = 0;

#int_timer0
void timer_0_kesme_fonksiyonu(void){
   set_timer0(217);
   _10ms++;
   
   if(_10ms == 100)
   {
      _10ms = 0;
      saniye++;
      if(saniye==255)  
         saniye = 0;
          
   
   }

}
 
void main()
{                   
   set_tris_a(0x0F);        
   lcd_init();
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_256);
   set_timer0(217);
   lcd_gotoxy(1,1);
   printf(lcd_putc,"Sure=%03u.%02d",saniye,_10ms);
   lcd_gotoxy(1,2);
   printf(lcd_putc,"Sonuc=%03u.%02d",read_eeprom(0),read_eeprom(1));
   
   
                                           
   while(TRUE)
   {
        if(input(pin_a3)){
            saniye = _10ms = 0;
            write_eeprom(0,saniye);
            write_eeprom(1,_10ms);
            lcd_gotoxy(1,1);
            printf(lcd_putc,"Sure=%03u.%02d",saniye,_10ms); 
            lcd_gotoxy(1,2);
            printf(lcd_putc,"Sonuc=%03u.%02d",saniye,_10ms);  
            while(!input(pin_a3));                     
        }
        
        if(input(pin_a0)){
            while(!input(pin_a2))
             {
                 enable_interrupts(int_timer0);
                 enable_interrupts(GLOBAL);
                 
                 lcd_gotoxy(1,1);
                 printf(lcd_putc,"Sure=%03u.%02d",saniye,_10ms);
                 lcd_gotoxy(1,2);
                 printf(lcd_putc,"Sonuc=%03u.%02d",read_eeprom(0),read_eeprom(1));
                 
                 if(input(pin_a1)){
                     write_eeprom(0,saniye);
                     write_eeprom(1,_10ms);
                     
                     lcd_gotoxy(7,2);
                     printf(lcd_putc,"Sonuc=%03u.%02d",read_eeprom(0),read_eeprom(1));
                     while(input(pin_a1)); 
                 }
                 lcd_gotoxy(6,1);
                 printf(lcd_putc,"%03u.%02d",saniye,_10ms);                        
             }
             
             disable_interrupts(GLOBAL);     
            
        
        }
        
   }     
                                 
}
