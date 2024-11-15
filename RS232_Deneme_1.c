#include <RS232_Deneme_1.h>
#fuses HS,NOWDT,NOPROTECT,NOCPD,NOPUT,NOBROWNOUT,NOLVP,NOWRT
#use rs232(baud=9600,parity=N,uart1,bits=8)
#define LCD_ENABLE_PIN PIN_B1
#define LCD_RS_PIN     PIN_B2
#define LCD_RW_PIN     PIN_B3
#define LCD_DATA0      PIN_B4
#define LCD_DATA1      PIN_B5
#define LCD_DATA2      PIN_B6
#define LCD_DATA3      PIN_B7
#define LCD_DATA_PORT getenv("SFR:PORTB")
#include <LCD.c>
char readed = 0;


void main()
{ 
   setup_adc(NO_ANALOGS);
   setup_adc_ports(ADC_OFF);                           
   setup_ccp1(CCP_OFF);
   setup_ccp2(CCP_OFF);
   setup_psp(PSP_DISABLED);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL | RTCC_DIV_8 );
   setup_timer_1(T1_INTERNAL | T1_DIV_BY_1);
   setup_timer_2(T2_DIV_BY_4, 249, 1);
   
   output_b(0x00); set_tris_b(0x00);      
   set_tris_d(0x00); output_d(0x00);
   
   lcd_init();
   lcd_gotoxy(1,1); lcd_putc("KOU MKT");
   lcd_gotoxy(1,2); lcd_putc("Gelen : ");
   

   while(TRUE)
   {
         if(kbhit()){
         
            readed = getc();
            lcd_gotoxy(8,2);
            printf(lcd_putc,"%3u",readed);
         
         }
         
         
   }

}
