#include <Deneme_1.h>
#include <LCD_B_v1.c>
#use fast_io(ALL)
      
                                      
void main()               
{                     
                                          
   set_tris_b(0x00);
   set_tris_d(0x00);                         
   lcd_init();          
   imlec(1,1);                                    
   printf(lcd_veri," Deneme");   
   while(TRUE)
   {                                             
      
   }

}                                                        
