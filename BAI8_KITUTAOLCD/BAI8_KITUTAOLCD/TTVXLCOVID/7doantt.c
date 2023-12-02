#include<TV_PICKIT2_SHIFT_1.c>
unsigned int8 sp;
void main()
{
      set_up_port_ic_chot();
      setup_timer_0(T0_off);
      set_timer0(26);
      while(true)
      {
            if(inputcd(ON)==0)  setup_timer_0(t0_ext_h_to_l|t0_div_1);
            if(inputcd(OFF)==0) setup_timer_0(t0_off);
            sp = get_timer0();  // dat trong while
            xuat_4led_7doan_giaima_xoa_so0(sp);

      }
}

