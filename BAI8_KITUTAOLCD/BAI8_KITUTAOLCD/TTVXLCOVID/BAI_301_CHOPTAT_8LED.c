#include<TV_PICKIT2_SHIFT_1.c>
#include<TV_KEY4x4_138.c>
unsigned int8 mp;
void main()
{
      set_up_port_ic_chot();
      while(true)
      {
          mp = key_4x4_dw();
          if(mp!=0xff) xuat_32led_don_1dw(mp);
   
      }
}

