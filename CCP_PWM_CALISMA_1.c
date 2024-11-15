#include <16F877A.h>
#device ADC=10
#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#use delay(crystal=4MHz)

#use fast_io(ALL)
#include<pin_dosyam.c>
#define USE_PORT_B  
#include<lcd_lib.c>

// REGISTER ADRESLERI             
#byte INTCON = 0x0B
#byte PIR1   = 0x0C
#byte PIR2   = 0x0D         
#byte PIE1   = 0x8C
#byte PIE2   = 0x8D
#byte TRISC  = 0x87
#byte TMR1L  = 0x0E
#byte TMR1H  = 0x0F
#byte T1CON  = 0x10                         
#byte T2CON  = 0x12
#byte CCPR1L = 0x15
#byte CCPR1H = 0x16
#byte CCP1CON= 0x17
#byte CCPR2L = 0x1B
#byte CCPR2H = 0x1C
#byte CCP2CON= 0x1D
#byte T2CON  = 0x12
#byte PR2    = 0x92
#byte TMR2   = 0x11
// REGISTER ADRESLERI 
unsigned int8   duty = 25;

/*    BURADAKI AYARLAR BAZ ALINARAK AYARLANMIÞTIR                                                   
  set_tris_c(0x00);                                                            
  setup_ccp1(CCP_PWM);
  setup_timer_2(T2_DIV_BY_16,170,1);
  set_pwm1_duty(duty);         
*/                                               
void PWM_Init(unsigned int duty){
        unsigned int16 tmp  = 0;
        unsigned int8 error_value = 0;
        PR2      = 170;                          // Periyot Ayar Deðeri  Timer 2 Periyot Register 
        tmp      = (error_value)+(1024/PR2)*duty;              // Burada PR2 deðerine göre oranlama yapýlarak PWM Doluluk Ayarlanýyor.
        
        CCP1CON = 0x0C | ((tmp & 0x000F) << 4); // Duty Cycle AYARI DEGERÝ  LSB 2 bit                           
        CCPR1L  = tmp>>2;                       // Duty Cycle AYARI DEGERÝ  MSB BÝTLER
        TMR2    = 0;                            // TMR 2 Baþlangýç Deðeri           
        T2CON   = 0x07;                         //                                     
        TRISC   = 0x00;                         // CCP için C Portu Output Olarak Ayarlanýr                         
}                                                
void pwm_update(unsigned int duty){                   
                          
      unsigned int16 tmp;
      tmp      =  (1024/PR2)*duty;  
      CCPR1L   =  tmp>>2;        
      CCP1CON  =  (CCP1CON & 0xCF) | ((tmp & 0x03) << 4);
                                          
}                                                            
void main()                      
{                                          // PWM ÇALIÞTIRMA TIMER 2 ile   
                                           
   lcd_init(); 
   lcd_veri("Merhaba");
   delay_ms(1000);
   INTCON  = 0xC0;                         // Genel ve Çevresel Kesmeleri Kontrol Biti                            
   PIE1    = 0x02;                         // CCP1 Kesme Enable 2.bit , Timer2 Kesme 1.Bit     
                                       
   PWM_Init(duty);
   printf(lcd_veri,"PWM = %d",duty);                                            
   set_tris_a(0xFF);        
                                                                                                
   while(TRUE)                                           
   {                                          
       if(input(pin_a2)){ 
         while(input(pin_a2)); 
         delay_ms(20);     
         duty+=1;          
          
         pwm_update(duty);                 
         lcd_temizle();
         printf(lcd_veri,"PWM = %u",duty); 
       }                               
       if(input(pin_a1)){ 
         while(input(pin_a1)); 
         delay_ms(20);     
         duty+=5; 
          
         pwm_update(duty);                 
         lcd_temizle();
         printf(lcd_veri,"PWM = %u",duty); 
       }                   
       if( input(pin_a4)) {
         while(input(pin_a4));                     
         delay_ms(20);
         duty-=5;          
         pwm_update(duty);
         lcd_temizle();  
         printf(lcd_veri,"PWM = %u",duty); 
                                         
       }
       
   }                    
                          
}                                             
