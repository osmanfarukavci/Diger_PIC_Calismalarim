#include <ADC_Calisma_2.h>
#define USE_PORT_B
#include <pin_dosyam.c>
#include <lcd_lib.c>
#include <adc_lib.c>
#use fast_io(ALL)
                            
  

                                                                                                                                                                      
void main()                      
{                                                  
   lcd_init();                
   set_tris_a(0xFF);        
   adc_init_baslat(ADC_CLOCK_2);                                                    
   adc_portlar(AN0_AN1_AN4_AN5_AN6_AN7_VREF_VREF);                       
   int16 deger = 0; 
   lcd_veri("ADC CALISMA");  
   delay_ms(500);                         
   lcd_temizle();               
   while(TRUE)                                                                                   
   {                          
     
    set_adc_kanali(0);                          
    deger = adc_oku();       
    printf(lcd_veri,"Deger = %ld",deger);
    imlec(2,1);
    printf(lcd_veri,"M=%x ",ADRESH);               
    printf(lcd_veri,"L=%x ",ADRESL);
    delay_ms(1000);
    lcd_temizle();                     
                                                    
   }                                                              
                                
}                                                   
