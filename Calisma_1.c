#include <16F877A.h>
#FUSES NOWDT, NOBROWNOUT, NOLVP
#use delay(crystal = 4MHz)

#use fast_io(ALL)
struct port{
int1 pin_0;
int1 pin_1;
int1 pin_2;
int1 pin_3;
int1 pin_4;
int1 pin_5;
int1 pin_6;
int1 pin_7;  
};                     
struct port port_d;
struct port port_c;
struct port port_d_tris;
struct port *d;                              
struct port *c;      
struct port *dt;

#byte port_d = 0x08      
#byte port_c = 0x07    
#byte port_d_tris = 0x88 

void main()                                
{  
          
   d = &port_d; 
   c = &port_c;
   dt = &port_d_tris;
   *dt = 0x00;    
   set_tris_c(0xFF);            
   int8 data = 0;  
   output_d(data); 
                                             
   while(TRUE)                        
   {                           
      data = 0x80;
      if(c->pin_0 == 1){   
         for(unsigned int i = 0;i < 7; i++) {                                                                                                               
            data =  data>> 1;
            *d = data;            
            delay_ms(100);                                   
        }  
      }
      else{
           for(unsigned int i = 0;i < 7; i++) {                                                                                                               
               data =  data>> 1;
               data += 0x80;
               *d = data;            
               delay_ms(100);                                   
           }                   
      }
   }                              

}                                                                              
