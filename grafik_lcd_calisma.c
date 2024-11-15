#include <grafik_lcd_calisma.h>
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG,NOCPD
#use fast_io(b)
#define use_portb_lcd TRUE

#include <lcd.c>

int x;
float y;
char z;



void main()
{       
   
   set_tris_b(0x00);
   lcd_init();
   x = 10;
   y = 32.6;
   
   
      
      
   while(TRUE)
   {
      lcd_send_byte(0,0x0d);
      printf(lcd_putc,"\f    CCS C");
      delay_ms(1000);
      printf(lcd_putc,"\n DERleyiCisi");
      delay_ms(1000);
      lcd_gotoxy(1,2);    
      printf(lcd_putc,"\f X DEGERI=%d",x);
      delay_ms(1000);
      printf(lcd_putc,"\f\nY DEGERI=%f",y);
      delay_ms(1000);  
      printf(lcd_putc,"\f DIRENC");
      delay_ms(1000);             
      z = lcd_getc(3,1);
      printf(lcd_putc,"\f%c",z);
      delay_ms(1000);  
      
   }

}                                                                 
