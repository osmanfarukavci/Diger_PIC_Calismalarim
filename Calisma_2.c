#include <Calisma_2.h>

#use fast_io(ALL)  
#define led pin_d0   
     
struct portbits{                                                                                            
int1 pin0;
int1 pin1;
int1 pin2;     
int1 pin3;   
int1 pin4;
int1 pin5;     
int1 pin6;          
int1 pin7;                              
};                           
              
#byte OPTION_REG = 0x81                                                                  
#byte TMR_0      = 0x01                  
                                                    
char i;   

void main()
{  
   set_tris_d(0);                
   OPTION_REG = 0xD7;
   TMR_0      = 0;
     
   while(TRUE)
   {
     output_toggle(led);
     i = 0;
     bekle:                                                              
     TMR_0 = 60;
     while(TMR_0 >= 60);
      i++;
     if(i < 2)
      goto bekle;
   }                       

}
