#include <16F877A.h>  
#device ADC=10
#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=4MHz)    

#use fast_io(ALL)
#define use_portb_lcd TRUE
#include <lcd.c>
                             
#INT_AD
void ADC_ISR(){                       
output_high(pin_c5); 
delay_ms(200);                           
output_low(pin_c5); 

}
unsigned long int bilgi;
float voltaj;

void main(){
   set_tris_c(0x00);
   set_tris_e(0x0F);
   
   output_c(0x00);    
   
   setup_adc(adc_clock_div_32);
   setup_adc_ports(ALL_ANALOG);
   
   enable_interrupts(INT_AD);
   enable_interrupts(GLOBAL);
   
   lcd_init();
   printf(lcd_putc,"\f adc uygulama");
   delay_ms(1500);


   while(1){
   
      set_adc_channel(5);
                                 
      delay_us(20);
      
      bilgi = read_adc();
      
      voltaj = 0.0048828125*bilgi;
      printf(lcd_putc,"\fAN5 Kanali");  
      delay_ms(1500);
      printf(lcd_putc,"\fDijital=%lu",bilgi);  
      delay_ms(1500);                       
      printf(lcd_putc,"\nVoltaj=%fV",Voltaj);  
      delay_ms(1500);
   
   
   }




}
