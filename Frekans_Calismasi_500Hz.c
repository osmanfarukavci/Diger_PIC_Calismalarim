
#include <16F877A.h>  
#use delay(crystal=4MHz)  
                 
                         
#fuses   XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG,NOCPD
#use     fast_io(ALL)                      
           
                
#define GET_MSB_FROM_16(DATA) ((DATA >> 8) & 0xFF )          
#define GET_LSB_FROM_16(DATA) (DATA & 0xFF) 

                

#define COUNTER_MOD         1 
#define TIMER_MOD           0               
#define PRESCALER_2         0 
#define PRESCALER_4         1 
#define PRESCALER_8         2
#define PRESCALER_16        3         
#define PRESCALER_32        4                                                        
#define PRESCALER_64        5  
#define PRESCALER_128       6       
#define PRESCALER_256       7                     

                    
struct timer_0_s{                            
int1 bit0;                
int1 bit1;                                                        
int1 bit2;
int1 bit3;                                                                    
int1 bit4;                
int1 bit5;                              
int1 bit6;                                  
int1 bit7;              
}; 

                                   
struct timer_0_s OPTION_REG;   
struct timer_0_s TMR0;                          
struct timer_0_s INTCON;             
struct timer_0_s *PTR;  

#byte PORT_D     = 0x08    
#byte TRISD      = 0x88                                    
#byte TMR0       = 0x01        
#byte INTCON     = 0x0B
#byte OPTION_REG = 0x81  
                             
void timer_0_mode(int8 MODE){                       
                                      
      PTR = &OPTION_REG;
      PTR->bit5 = MODE; 
                                                  
}                                     
                 
void timer_value(int8 VALUE){
              
     TMR0 = VALUE;                                   
}                                      

void timer_pres(int8 PRESC){                           
      
      PTR = &OPTION_REG;
      PTR->bit0 = (PRESC & 0x01);
      PTR->bit1 = (PRESC & 0x02);
      PTR->bit2 = (PRESC & 0x04);
      
                                      
}  

#int_timer0                       
void timer0_isr(){
   timer_value(60); 
   PORT_D = !PORT_D;
   
                   
}                                  
void main()                          
{                                     
   timer_0_mode(TIMER_MOD);
   TRISD = 0x00;
   timer_value(60); 
   timer_pres(PRESCALER_256);
       
   while(TRUE)                        
   {                          
                                                                        
   }                             
                                                
}                                                             
