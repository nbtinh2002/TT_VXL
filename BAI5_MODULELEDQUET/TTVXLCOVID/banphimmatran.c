#include<TV_PICKIT2_SHIFT_1.c>
#include<TV_PICKIT2_SHIFT_KEY4x4_138.c>
unsigned int8 mp,dem=0;
signed int8 n;
unsigned int16 y,m;
int1 tt=0;

void sangdan()
{
      for(n=16;n>=0;n--)
      {
            y = 0xffff>>n;
            xuat_32led_don_2word(y,dem);
            for(m=0;m<100;m++)
            {
                mp= KEY_4x4_DW();
                if(mp==10)dem++;        // khong lap lai lien tuc 
                xuat_32led_don_2word(y,dem);
            }
      }
}
void main()
{
      set_up_port_ic_chot();
      while(true)
      {
           mp= KEY_4x4_DW();
           if(mp==10)dem++;        // khong lap lai lien tuc
           if(mp==15)tt=1;
           if(tt==1) sangdan();    // lap di lap lai tien tuc

           xuat_32led_don_2word(y,dem);
      }
}
