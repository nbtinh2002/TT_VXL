#include<TV_PICKIT2_SHIFT_1.c>
unsigned int8 bdn=0,dem=0,m;

void main()
{
      set_up_port_ic_chot();
      setup_timer_1(t1_internal|t1_div_by_8);
      set_timer1(3036);
      enable_interrupts(int_timer1);
      enable_interrupts(global);

      while(true)
      {
          if(bdn>=5) 
            {
                  bdn=bdn-5;
                  dem++;
                  if(dem==100)dem=0;
            }

         led_7dq[0]= ma7doan[0];
         led_7dq[1]= ma7doan[3];
         led_7dq[2]= 0xbf;
         led_7dq[3]= ma7doan[5];
         led_7dq[4]= ma7doan[3];
         led_7dq[5]= 0xbf;
         led_7dq[6]= ma7doan[9];
         led_7dq[7]= ma7doan[0];
         hien_thi_8led_7doan_quet_all();
         
      }
}
#int_timer1        // khong viet gi vao giua 2 hang nay
void ngatt1()
{
     set_timer1(3036); 
     bdn++;
}

