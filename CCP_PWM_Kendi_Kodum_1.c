#include <CCP_PWM_Kendi_Kodum_1.h>
 

#use fast_io(b)
#use fast_io(c) 

                                    
struct{
int1 T2CKPSC0;
int1 T2CKPSC1;            
int1 TMR2ON;
int1 TOUTPS0;
int1 TOUTPS1;   
int1 TOUTPS2;
int1 TOUTPS3;
int1 NA;                                              
}T2CON;                          

#byte T2CON   =  0x12   //  Timer 2 Kontrol Register
#byte PR2     =  0x92   //  PR2 Registerý TMR2 ile karþýlaþtýrýlýr                       
#byte TMR2    =  0x11   //  TMR2 Registerý PR2 ile karþýlaþtýrýlýr           
                              
#byte INTCON  =  0x0B   // KESME KONTROL REGISTERI

#byte PIR1    =  0x0C        
#byte PIE1    =  0x8C

#byte CCP1CON =  0x17
#byte CCPR1L  =  0x15
#byte CCPR1H  =  0x16  

                              
                             
                        
          
void main()                                    
{  
   CCPR1L  =  0x10;  // DUTY AYARLAMA
   CCP1CON =  0x0C;  // DUTY AYARLAMA              
   set_tris_b(0x00);
   set_tris_c(0x00);         
                        
   output_c(0x00);                                           
   output_b(0x00);
                 
   T2CON = 0x01; 
   PR2 = 249;
   TMR2 = 0;          
   T2CON.TMR2ON = 1;      
             
   while(TRUE)
   {           
      
   }

}
