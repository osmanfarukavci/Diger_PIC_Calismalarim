      
      
#define ENABLE  1      
#define DISABLE 0       
#define GET_MSB_FROM_16(DATA) ((DATA >> 8) & 0xFF )          
#define GET_LSB_FROM_16(DATA) (DATA & 0xFF)  


void general_int_enable(){
   
   PTR = &INTCON;
   PTR->bit7 = ENABLE;
   PTR->bit6 = ENABLE;


}
