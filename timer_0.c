
                                 
                                 
#define COUNTER_MOD         1 
#define TIMER_MOD           0               
#define PRESCALER_2         0x00 
#define PRESCALER_4         0x01 
#define PRESCALER_8         0x02 
#define PRESCALER_16        0x03         
#define PRESCALER_32        0x04                                                        
#define PRESCALER_64        0x05  
#define PRESCALER_128       0x06       
#define PRESCALER_256       0x07                     
#define ENABLE              1
#define DISABLE             0
                      
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
                                  
#byte TMR0       = 0x01        
#byte INTCON     = 0x0B
#byte OPTION_REG = 0x81  

void timer_0_mode(int8 MODE){                       
                                      
      PTR = &OPTION_REG;   
      PTR->bit5 = MODE; 
                                                  
}                                     
void timer_0_int_enable(void){

      PTR = &INTCON;
      PTR->bit5 = ENABLE;



}
void timer_value(int8 VALUE){
              
     TMR0 = VALUE;                                   
}                                      

void timer_pres(int8 PRESC){                           
                                                  
      PTR = &OPTION_REG;                       
      PTR->bit0 =  (PRESC & 0x01)  ;
      PTR->bit1 =  (PRESC & 0x02)  ;                    
      PTR->bit2 =  (PRESC & 0x04)  ;                    
      PTR->bit3 = DISABLE;
                                      
}                                
                                       
