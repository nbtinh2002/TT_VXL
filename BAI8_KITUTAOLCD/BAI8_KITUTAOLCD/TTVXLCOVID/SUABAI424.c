#include<TV_PICKIT2_SHIFT_1.c>
#include<TV_PICKIT2_SHIFT_KEY4x4_138.c>
unsigned int8 led[8]={0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f,0x7f};
unsigned int8 mp,n;
void main()
{
      set_up_port_ic_chot();
      while(true)
      {
           mp = key_4x4_dw();
           if(mp<10)
           {
                  for(n=7;n>0;n--) led[n] = led[n-1];
                  led[0] = ma7doan[mp];     
           }
           else if(mp==11)
           {
                  for(n=0;n<7;n++) led[n] = led[n+1];
                  led[7] = 0x7f;  
           }
           else if(mp==12)
           {
                  for(n=0;n<=7;n++) led[n] = 0x7f;
           }
           xuat_4led_7doan_4s0(led[3],led[2],led[1],led[0]);
      }
}
