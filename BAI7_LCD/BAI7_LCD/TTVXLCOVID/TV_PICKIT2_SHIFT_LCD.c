#ifndef   __TV_PICKIT2_SHIFT_LCD_C__
#define   __TV_PICKIT2_SHIFT_LCD_C__
#define  LCD_D4   PIN_J0   // Khai báo các chân giao tiêp LCD
#define  LCD_D5   PIN_J1
#define  LCD_D6   PIN_J2
#define  LCD_D7   PIN_J3
#define  LCD_RS   PIN_D0
#define  LCD_E    PIN_D1
#DEFINE  LCD_CLEAR_DISPLAY      0X01
#DEFINE  LCD_SHIFT_LEFT         0X18
#DEFINE  LCD_SHIFT_RIGHT        0X1C
#DEFINE  LCD_ADDR_LINE1         0X80
#DEFINE  LCD_ADDR_LINE2         0XC0
#DEFINE  LCD_ADDR_LINE3         0X94
#DEFINE  LCD_ADDR_LINE4         0XD4

void lcd_write_4bit(int8 d)
{
       output_bit(LCD_D4,bit_test(d,0));
       output_bit(LCD_D5,bit_test(d,1));
       output_bit(LCD_D6,bit_test(d,2));
       output_bit(LCD_D7,bit_test(d,3));
       output_high(LCD_E);output_low(LCD_E);
       delay_us(200);
}
void lcd_command(int8 d)
{
      output_low(LCD_RS);
      lcd_write_4bit(d>>4);
      lcd_write_4bit(d);
}
void lcd_data(int8 d)
{
      output_high(LCD_RS);
      lcd_write_4bit(d>>4);
      lcd_write_4bit(d);
}
void setup_lcd()
{
      lcd_command(0x32); delay_ms(5);
      lcd_command(0x2c); delay_ms(5);
      lcd_command(0x0c); 
      lcd_command(0x01); delay_ms(2);    
}
void lcd_goto_xy(int8 hang, int8 cot) // hang 0-3, cot 0-19
{
      const int8 dc[]={0x80,0xC0,0x94,0xD4};
      lcd_command(dc[hang]+cot);
}

#endif
