#include <rb_kesme_deneme_1.h>
 
#use fast_io(b)




#int_rb
void rb_kesme()                  
{                              
                      
   if(input(pin_b4))
       output_d(0xFF);   
    
      
   delay_ms(1000);      
   output_b(0x00);
  
}                    
  
void main()                              
{
                    
set_tris_b(0xF0);
set_tris_d(0x00);
output_b(0x00);                
enable_interrupts(INT_RB);                   
enable_interrupts(GLOBAL);       
   while(TRUE)
   {
   output_d(0x00);
   output_high(pin_b2);
   delay_ms(200);
   output_low(pin_b2);
   delay_ms(200);
   }                   

}                                   
