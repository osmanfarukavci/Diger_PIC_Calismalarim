#include <Kesme_Calisma_1.h>
                         
#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG,NOCPD
                             
#use fast_io(ALL)  

#define ENABLE  1
#define DISABLE 0
#define GET_MSB_FROM_16(DATA) ((DATA >> 8) & 0xFF )          
#define GET_LSB_FROM_16(DATA) (DATA & 0xFF)  

                        

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
  
struct bits OPTION_REG;  
struct bits TMR0;                  
struct bits INTCON;                                                      
struct bits PORT_C;
struct bits TRISC;       
struct bits PORT_D;
struct bits PIE1;     
struct bits PIR1; 
struct bits T1CON;
struct bits *PTR;      

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
 
long TMR1  = 0;  
              
 
#int_timer0
void timer0_kesmesi() {
   
    TMR0 = 254; 
    PTR  = &PORT_D;
    PTR->bit3 = !PTR->bit3;                  
    PTR->bit1 = !PTR->bit1;                    
    PTR  = &INTCON;
    PTR->bit2 = DISABLE;
}                    
  
#int_timer1
void timer1_kesme(){
  static int i = 0;                                                        
  TMR1 =  1000;                                             
  TMR1H      = GET_MSB_FROM_16(TMR1);
  TMR1L      = GET_LSB_FROM_16(TMR1);
  PTR = &PORT_D;
  i++;
  if(i == 5){
      PTR->bit2 = !PTR->bit2;             
      i = 0;        
  }
  PTR = &PIR1;
  PTR->bit0 = 0; 
}
                                      
void main()
{
        
                                 
   TRISD      = 0x00;      
   PORT_D     = 0x00;
   
   OPTION_REG = 0x20;                  
   INTCON     = 0xE0;                
   TMR0       = 254;     
   
   TMR1       = 60000;                             
   TMR1H      = GET_MSB_FROM_16(TMR1);
   TMR1L      = GET_LSB_FROM_16(TMR1);
   T1CON      = 0x3D;          
   PTR = &PIE1;    
   PTR->bit0 = 1; 
   PTR = &PIR1;
    
   while(TRUE)                         
   {                                  
        PORT_D.bit0 = !PORT_D.bit0;
        delay_ms(500);
   }           

}                                                          
