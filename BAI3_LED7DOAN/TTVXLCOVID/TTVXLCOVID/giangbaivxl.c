#include<16f887.h>
#fuses  hs
#use delay (clock=20M)
#include<lcd.c>
#include"TV_PICKIT2_SHIFT_1.c"
#include"TVLCD.c"
unsigned int8 gio, phut, giay;
void capnhatthoigian()
{
      // dogiophutgiayturealtime
}
void chinhthoigian()
{
      //  neuconhannutchinhgio
        gio++;
}
void main()
{
      gio=9;          // nhung tac vu xu ly 1 lan duy nhat
      phut=0;
      giay=0;
      while(true)
      {              // nhung tac vu xu ly lap di lap lai lien tuc
            capnhatthoigian();
      }
}






