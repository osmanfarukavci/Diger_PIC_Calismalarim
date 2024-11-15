///////////////////////////////////////////////////////        
//                                                   //  
//          KENDI LCD KUTUPHANE DENEMEM              //
//                       OFA                         //
//                                                   //
//    lcd_komut(komut_x)                             //
//    lcd_veri(veri_x)                               // 
//    lcd_init()                                     //           
//    lcd_imlec(x,y)                                 //
//    lcd_temizle();                                 //
//                                                   //
///////////////////////////////////////////////////////
#define e  pin_b0
#define rs pin_b1 // Register Select Pini. 0 ise veri yolunu komut olarak iþlem
                  // yapar. 1 ise veri yolunu karakter bilgisi olarak ayarlar 
                               
   
                                    
 
// LCD her iþlem (okuma,yazma,vs)sonrasý enable pin düþen kenar yapýlmasý 
void enable_pin_tetikleme()
{                             
   delay_cycles(1);    
   output_high(e);
   delay_cycles(1);                                                                   
   output_low(e);                              
                                                            
}                              

//******** LCD ye Komut Gönderme Fonksiyonu ***********
void lcd_komut(byte komut)                                                                                         
{                                                     
   output_b(komut&0xF0);     // Komutun yüksek deðerlikli 4 bitini gönderir                          
   output_low(rs);         // LCD Komut almak için ayarlanýr                                            
   enable_pin_tetikleme(); 
   delay_ms(2);
                                             
   output_b(komut<<4);          
   output_low(rs);                              
   enable_pin_tetikleme();                                                  
   delay_ms(2);
                                          
}                                 
                                      
void lcd_veri(byte veri)                     
{                                                   
   output_b(veri&0xF0);    
   output_high(rs);        // rs pini veri almak için ayarlandý
   delay_cycles(1);
   enable_pin_tetikleme();
   delay_ms(2);
   
   output_b(veri<<4);   // Düþük deðerlikli 4 bit gönder
   output_high(rs);     
   enable_pin_tetikleme();
   delay_ms(2);
}                                        
                                            
void imlec(byte satir,byte sutun)
{
   if(satir == 1)               
      lcd_komut(0x80 | (sutun-1)); 
                                                 
   if(satir == 2)
      lcd_komut(0x80 | (0x40 + (sutun-1)));  
}
                
void lcd_temizle(){
   
   lcd_komut(0x01);

}                                                 
                                                              
void lcd_init()                    
{                             
   int i = 0;                                                                               
   output_low(rs);                
   output_low(e);                                    
   delay_ms(30);        
   
   for(i = 0; i <= 3;i++)                           
   {                                                       
   
      lcd_komut(0x03);        
      delay_ms(5);      
               
   }
               
   lcd_komut(0x02);
   lcd_komut(0x28);
   lcd_komut(0x08);
   lcd_komut(0x0C);
   lcd_komut(0x06);
   lcd_komut(0x01);
}                                   
