#include<TV_PICKIT2_SHIFT_1.c>
#include<TV_PICKIT2_SHIFT_LCD.c>
unsigned int8 T0;
void main()
{
      set_up_port_ic_chot();
      setup_lcd();                   // Luon goi setup_lcd() o day
      lcd_goto_xy(0, 2);             // Hien thi duoc o vi tri bat ky ( hang 0-3, cot 0-19)
      lcd_data("THUC TAP VXL CT4");  // Hien thi duoc chuoi ky tu
      lcd_goto_xy(1, 4);
      lcd_data(0xf6);                // Hien thi ky tu khong danh may dc - tra ma trong sach
      lcd_data("Lon:");
      setup_timer_0(t0_ext_l_to_h|t0_div_1);
      set_timer0(0);
      while(true)
      {
            T0 = get_timer0();
            if(T0>24)set_timer0(1);
            lcd_goto_xy(1, 9);       // hien thi duoc gia tri cua bien
            lcd_data(T0/10%10 + 48);
            lcd_data(T0/1%10  + 48);
                     
      }
}
