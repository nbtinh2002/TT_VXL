#include<TV_PICKIT2_SHIFT_1.c>
unsigned int8 gio=13,phut=24, giay=53;
unsigned int8 bdn=0;

void main()
{
      set_up_port_ic_chot();
      setup_timer_1(t1_internal|t1_div_by_8);
      set_timer1(3036);
      enable_interrupts(int_timer1);
      enable_interrupts(global);

      while(true)
      {
            if(bdn>=10) 
            {
                     bdn=bdn-10;
                     giay++;
                     if(giay==60) 
                     {
                           giay=0; phut++;
                           if(phut==60) 
                           {
                                 phut=0; gio++;
                                 if(gio==13) gio=1;
                           }
                     }
             }

            LED_7DQ[7] = ma7doan[gio/10%10];
            LED_7DQ[6] = ma7doan[gio/1%10];
            LED_7DQ[5] = 0xbf;
            LED_7DQ[4] = ma7doan[phut/10%10];
            LED_7DQ[3] = ma7doan[phut/1%10];
            LED_7DQ[2] = 0xbf;
            LED_7DQ[1] = ma7doan[giay/10%10];
            LED_7DQ[0] = ma7doan[giay/1%10];
            
            HIEN_THI_8LED_7DOAN_QUET_ALL();
            

      }
}

#int_timer1        // khong viet gi vao giua 2 hang nay
void ngatt1()
{
     set_timer1(3036); 
     bdn++;
}

