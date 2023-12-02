#include<TV_PICKIT2_SHIFT_1.c> 
unsigned int8 T0, T0_TAM;
void main()
{
      set_up_port_ic_chot();
      setup_timer_0(t0_off); // cau hinh che do hoat dong cho timer
      set_timer0(10);                        // dat truoc gia tri dem
      while(true)   
      {
            T0 = get_timer0();  // khong dat trong bat cu  lenh khac
            if(input(ON)==0)  setup_timer_0(t0_ext_h_to_l|t0_div_1); 
            if(input(OFF)==0) setup_timer_0(t0_off);
            if(T0>99) set_timer0(10);  // khong duoc reset bien ma phai dung set_timer
            xuat_4led_7doan_giaima_xoa_so0(T0);  // chi hien thi gia tri so, tan cung ben phai tro di    
      }
}

