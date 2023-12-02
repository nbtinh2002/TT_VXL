#include<16f887.h>
#fuses  hs  
#use    delay(clock=20M)
void main()
{
      while(true)
      {
            output_toggle(pin_d0);
            delay_ms(300);
      }
}





