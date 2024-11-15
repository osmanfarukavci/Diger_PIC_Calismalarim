#include <RS232_CALISMA_1.h> 
#include <pin_dosyam.c> 
#define USE_PORT_B 
#include <lcd_lib.c>
                  
#use rs232 (baud=9600, xmit=pin_C6, rcv=pin_C7, parity=N, stop=1)


char klavye[80];

#int_rda
void serihaberlesme(){            

disable_interrupts(int_rda);
output_high(pin_c5);
gets(klavye); 
printf("\n\r Yazdiginiz Metin> %s\n",klavye);
printf(lcd_veri,"\f%s",klavye); 
delay_ms(100);
output_low(pin_c5); 
printf("\n\rKlavyeden bir veri giriniz ve enter tusuna basiniz>");
                                     
}

void main()                         
{    
   output_low(pin_c5);
   lcd_init();    
   printf("\r*****************Merhaba*******************");
   printf("\n\r Klavyeden girdiðiniz veri LCD'de gorulecektir\n\n");
   printf("\n\r Klavyeden bir veri giriniz ve enter tusuna basiniz>");
                            
  
   enable_interrupts(GLOBAL);
   enable_interrupts(int_rda); 
   while(TRUE)
   {
      enable_interrupts(int_rda); 
   }

}                          
