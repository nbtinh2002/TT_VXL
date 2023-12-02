#include<TV_PICKIT2_SHIFT_1.c>
#include<TV_PICKIT2_SHIFT_LCD.c>
void main()
{
      set_up_port_ic_chot();
      setup_lcd();
      lcd_data("Phan Van Hoan");
      output_j(0);
      while(true)
      {
           xuat_32led_don_4byte(0,0,0xff,0xff); 
           delay_ms(300);
           xuat_32led_don_4byte(0,0,0,0); 
           delay_ms(300);
           lcd_command(0x80);
           lcd_data("Phan Van Hoan");
      }
}

