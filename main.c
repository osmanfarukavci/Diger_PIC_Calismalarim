#include <main.h>
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG
#use delay (clock=4000000)

#use fast_io(b)
#use fast_io(c)
#use fast_io(a)

int i = 5;

#int_ext
void kesme ()
{
   output_high(pin_b1);
   delay_ms(1000);
   output_low(pin_b1);
   delay_ms(1000);
   

}


void main()
{
   setup_psp(PSP_DISABLED);
   setup_timer_1(T1_DISABLED);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   
   set_tris_a(0x03);
   set_tris_c(0x00);
   
   setup_CCP1(CCP_PWM);
   setup_CCP2(CCP_PWM);
   
   setup_timer_2(T2_DIV_BY_16,170,1);
   
   set_pwm1_duty(i);
   set_pwm2_duty(i);
   
   set_tris_b(0x01);
   output_b(0x00);
   
   ext_int_edge(H_TO_L);
   enable_interrupts(INT_EXT);
   enable_interrupts(GLOBAL);
   
   
   while(TRUE)
   {
      if(input(pin_a0))
      {
         delay_ms(20);
         while(input(pin_a0));
         i+=3;
         if(i>170)
            i=170;
         set_pwm1_duty(i);
         set_pwm2_duty(i);
         
      
      }
            if(input(pin_a1))
      {
         delay_ms(20);
         while(input(pin_a0));
         i-=3;
         if(i<5)
            i=5;
         set_pwm1_duty(i);
         set_pwm2_duty(i);
         
      
      }
   }

}
