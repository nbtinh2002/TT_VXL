#include<16f887.h>
#fuses hs
#use delay(clock=20M)
#include<lcd.c>
unsigned int8 gio, phut, giay;
void chinhgio()
{
   gio++;
}

void main()
{
      // nhung tac vu xu ly 1 lan
      gio=0;
      phut=0;
      giay=0;
      while(true)
      {
            // nhung tac vu xu ly lien tuc
            chinhgio();
      }
}

