#include<TV_PICKIT2_SHIFT_1.c>
void main()
{
      set_up_port_ic_chot();
      while(true)
      {
           xuat_32led_don_4byte(0,0,0xff,0xff); 
           delay_ms(300);
           xuat_32led_don_4byte(0,0,0,0); 
           delay_ms(300);
      }
}

