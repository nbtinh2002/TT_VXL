#include<TV_PICKIT2_SHIFT_1.c>
#include<TV_PICKIT2_SHIFT_KEY4x4_138.c>
unsigned int8 mp,n;
unsigned int8 ht[8]={0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f};
void main()
{
      set_up_port_ic_chot();
      while(true)
      {
            mp = key_4x4_dw();
            if(mp<10)
            {
                  for(n=7;n>0;n--) ht[n]= ht[n-1];
                  ht[0]= ma7doan[mp];
            }
            if(mp==11)
            {
                  for(n=0;n<7;n++) ht[n]= ht[n+1];
                  ht[7]= 0x7f;
            }
            if(mp==12)
            {
                  for(n=0;n<8;n++) ht[n]= 0x7f;
            }
            xuat_4led_7doan_4s0(ht[3],ht[2],ht[1],ht[0]);
      }
}
