
      
#ifndef  MY_PORTS 
   #byte PORT_B = 0x06                               
   #byte PORT_D = 0x08
   #byte TRIS_B = 0x86   
   #byte TRIS_D = 0x88
   #byte PORT_A = 0x05   
   #byte TRIS_A = 0x85
   #byte PORT_E = 0x09
   #byte TRIS_E = 0x89
#else
   #warning "MY_PORT tanýmlanmadý !" 
#endif 



#define PINB0   &PORT_B,0                 
#define PINB1   &PORT_B,1  
#define PINB2   &PORT_B,2       
#define PINB3   &PORT_B,3       
#define PINB4   &PORT_B,4  
#define PINB5   &PORT_B,5  
#define PINB6   &PORT_B,6                       
#define PINB7   &PORT_B,7  
                                          
#define PIND0   &PORT_D,0              
#define PIND1   &PORT_D,1  
#define PIND2   &PORT_D,2  
#define PIND3   &PORT_D,3  
#define PIND4   &PORT_D,4   
#define PIND5   &PORT_D,5  
#define PIND6   &PORT_D,6                          
#define PIND7   &PORT_D,7  

#define PINA0   &PORT_A,0              
#define PINA1   &PORT_A,1  
#define PINA2   &PORT_A,2  
#define PINA3   &PORT_A,3  
#define PINA4   &PORT_A,4   
#define PINA5   &PORT_A,5   

                                  
                                  
                                                 
void pin_acik( int8 *port_x,int8 pin){

       *port_x |= (1<<pin);              
                                                 
}
void pin_kapali( int8 *port_x,int8 pin){

      *port_x &= ~(1<<pin);                      
}                                                              
