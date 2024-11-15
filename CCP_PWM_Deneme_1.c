#include <CCP_PWM_Deneme_1.h>
 
#byte PR2 = 0x92   
#include "lcd.c"
int16 ang_bilgi = 0;     
  

void main()
{
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_adc_ports(AN0);
   setup_ccp1(CCP_PWM);             
   set_pwm1_duty(0);               
   setup_timer_2(T2_DIV_BY_4,249,1);
   set_tris_d(0x00);            
   
                      
                      
   lcd_init();
   lcd_gotoxy(1,1);
   lcd_putc("ADC Degeri:      ");
   lcd_gotoxy(1,2);
   lcd_putc("PWM orani :      ");
   
                                 
   while(TRUE)
   {
      set_adc_channel(0);
      delay_us(10);
      ang_bilgi = read_adc();
      set_pwm1_duty(512);
      lcd_gotoxy(12,1);
      printf(lcd_putc, "%4ld",ang_bilgi);
      lcd_gotoxy(12,2);
      printf(lcd_putc, "%4ld",ang_bilgi/10);  
      delay_ms(50);
   }

}
