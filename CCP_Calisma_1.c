#include <CCP_Calisma_1.h>
#include <timer_0.c> 
#include <my_lib.c> 
#use fast_io(ALL) 

struct bits{
int1 bit0;
int1 bit1;                                                        
int1 bit2;
int1 bit3;                             
int1 bit4;                
int1 bit5;
int1 bit6;                                  
int1 bit7;  
};           
  
                                                    
struct bits PORT_C;               
struct bits TRISC;       
struct bits PORT_D;
struct bits PIE1;     
struct bits PIR1;                                            
struct bits T1CON;
struct bits *P;      
                               
#byte TMR0       = 0x01        
#byte INTCON     = 0x0B
#byte OPTION_REG = 0x81 
#byte PORT_C     = 0x07
#byte TRISC      = 0x87            
#byte PORT_D     = 0x08
#byte TRISD      = 0x88 
#byte TMR1L      = 0x0E    
#byte TMR1H      = 0x0F   
#byte T1CON      = 0x10
#byte PIE1       = 0x8C 
#byte PIR1       = 0x0C   
              
#int_timer0
void timer0_kesmesi() {
    static int8 i = 0;               
    timer_value(60);
    i++;
    if(i == 10)  {
      P  = &PORT_D;   
      P->bit3 = !P->bit3; 
      i = 0;
    }
}                              

void main()             
{                                                       
    timer_0_mode(TIMER_MOD);
    timer_pres(PRESCALER_128);
    timer_value(60);
    general_int_enable();
    timer_0_int_enable();           
    
    TRISD = 0x00;
    PORT_D = 0x00; 
    
   while(TRUE)
   {
      //TODO: User Code 
   }                                                           

}                        
