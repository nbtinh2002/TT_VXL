#include<16f887.h>
#fuses  hs 
#use delay(clock =20M)
#include<TV_KEY4x4.c>
unsigned int8 mp,m;
int1 tt=0;
void main()
{
      set_tris_b(0x0f);
      while(true)
      {
           
             mp = KEY_4x4();
             if(mp==11) output_toggle(pin_d0);
             if(mp==7) tt=1;
             if(tt)  
             {
                output_toggle(pin_d7);
                for(m=0;m<200;m++)
                {
                   mp = KEY_4x4();
                   if(mp==11) output_toggle(pin_d0);
                   if(mp==7) tt=1;
                }
                
             }
      }
}
