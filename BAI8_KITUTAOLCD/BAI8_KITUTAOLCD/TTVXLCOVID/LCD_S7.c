#include<TV_PICKIT2_SHIFT_1.c>
#include<TV_PICKIT2_SHIFT_LCD.c>
void main()
{
      unsigned int8 dem=0;
      set_up_port_ic_chot();
      setup_lcd();                      // luon goi ham nay sau set_up..chot();
      lcd_goto_xy( 0, 3);               // Hien thi duoc bat ky vi tri nao tren LCD
      lcd_data("HO VA TEN");            // Hien thi  duoc chuoi ky tu
      lcd_goto_xy( 1, 6);               // Hien thi duoc bat ky vi tri nao tren LCD
      lcd_data("08:36:56");            // Hien thi  duoc chuoi ky tu
      lcd_goto_xy( 2, 0);        
      lcd_data("GH:XX         SP:YY");                   // Hien thi duoc ky tu khong danh may duoc - tra ma trong sach (ASCII)
      
      lcd_goto_xy( 3, 5);               // Hien thi duoc bat ky vi tri nao tren LCD
      lcd_data("COUNT UP");            // Hien thi  duoc chuoi ky tu
      while(true)
      {
          
      }
}
