#include<TV_PICKIT2_SHIFT_1.c>
unsigned int16 T0,t0tam;
void main()
{
      setup_timer_0(t0_off);
      set_timer0(240);
      while(true)
      {
            if(input(on)==0) setup_timer_0(t0_ext_h_to_l|T0_div_1);
            if(input(off)==0) setup_timer_0(t0_off);
            T0 =get_timer0(); // de trong while(true) va khong dat trong bat cu lenh khac
            if(T0>254) set_timer0(240);
            xuat_4led_7doan_giaima_xoa_so0(T0);  // chi hien thi tan cung ben phai tro di va gia tri so
      }
}

