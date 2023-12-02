#ifndef  __TV_PICKIT2_SHIFT_LCD_C__
#define  __TV_PICKIT2_SHIFT_LCD_C__
#include<TV_PICKIT2_SHIFT_LCD.h>
void lcd_write_4bit(int8 d)
{
      output_bit(LCD_D4, bit_test(d,0));
      output_bit(LCD_D5, bit_test(d,1));
      output_bit(LCD_D6, bit_test(d,2));
      output_bit(LCD_D7, bit_test(d,3));
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
      int8 n;
      lcd_command(0x32);  delay_ms(5);
      lcd_command(0x2C);  delay_ms(5);
      lcd_command(0x0C);    
      lcd_command(0x40);                             // di chuyen den dia chi dau vung nho CGRAM
      for(n=0;n<64;n++) lcd_data(LCD_MA_8DOAN[n]);   // ghi ma cua ky tu moi tao vao CGRAM
      lcd_command(0x01); delay_ms(2);      
}

void lcd_goto_xy( int8 x, int8 y)  // x :0-3, y:0-19
{
      const unsigned int8 dc[]={0x80,0xc0,0x94,0xd4};
       lcd_command(dc[x]+y);
}

void lcd_hienthi_so_z_toado_xy(signed int8 lcd_so, x1, y1) 
{     int8 i;
      lcd_goto_xy(x1,y1);
      for (i=0;i<6;i++)     
      {                  
        if (i==3)   lcd_goto_xy(x1+1,y1);             
        lcd_data(lcd_so_x[lcd_so][i]);     
      } 
}

void write_4lines_num(int8 so, int8 x)
{
      int8 n;
      for(n=0;n<12;n++)
      {
            if(n%3==0)LCD_GOTO_XY(n/3,x); 
            LCD_DATA(LCD_SO_X1[so][n]);
      }
}

#endif
