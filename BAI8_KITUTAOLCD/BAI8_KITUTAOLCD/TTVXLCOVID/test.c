#include<TV_PICKIT2_SHIFT_1.c>
void lcd_command(int8 d)
{
      output_low(Pin_j0);
      output_h(d);
      output_high(pin_j1);
      output_low(pin_j1);
      delay_us(200);
}
void lcd_data(int8 d)
{
      output_high(Pin_j0);
      output_h(d);
      output_high(pin_j1);
      output_low(pin_j1);
      delay_us(200);
}
void setup_lcd()
{
      lcd_command(0x38); delay_ms(5);
      lcd_command(0x38); delay_ms(5);
      lcd_command(0x0c);
      lcd_command(0x01); delay_ms(2);
}
void main()
{
      set_up_port_ic_chot();
      setup_lcd();
      lcd_data("Phan Van Hoan");
      while(true)
      {
           xuat_32led_don_4byte(0,0,0xff,0xff); 
           delay_ms(300);
           xuat_32led_don_4byte(0,0,0,0); 
           delay_ms(300);
      }
}

