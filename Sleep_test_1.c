#include <Sleep_test_1.h>

#FUSES WDT                
                  
#use fast_io(d)  
#use fast_io(b)
#use fast_io(c)
                                
struct{
int1 DC;
int1 Z ;
int1 PD;
int1 TO;   
int1 RP0;
int1 RP1;
int1 IRP; 
}STATUS;
#byte STATUS = 0x03

 
#int_rb
void rb_kesme(){
if(input(pin_b4)){
   output_toggle(pin_d2);
}

}                         
                                 

void main()      
{    
   set_tris_d(0x00); 
   set_tris_c(0x00);
   set_tris_b(0xFF);
   output_d(0x00);
   output_c(0x00);                      
   setup_WDT(WDT_2304MS);
   enable_interrupts(int_rb);
   enable_interrupts(GLOBAL);
   int8 sayac = 0;  
   

   if(restart_cause() == MCLR_FROM_RUN){
                       
        output_high(pin_d2);        
   }
  
   while(TRUE)                            
   {                                            
                                   
              
     if(STATUS.TO == 0)         
         sayac++;
      
     
     output_toggle(pin_d3);
     
                
     sleep();
   }

}                                                               
