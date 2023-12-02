#include    <18f8722.h>
#fuses      hs
#use        delay(clock=20000000)
#USE        SPI(SPI2)
#DEFINE  BT0     PIN_j4
#DEFINE  BT1     PIN_j5
#DEFINE  BT2     PIN_j6
#DEFINE  BT3     PIN_j7
#DEFINE  ON      BT0 
#DEFINE  UP      BT0  
#DEFINE  ON1     BT0 
#DEFINE  OFF     BT1
#DEFINE  DW      BT1
#DEFINE  OFF1    BT1
#DEFINE  INV     BT2
#DEFINE  ON2     BT2
#DEFINE  CLR     BT2
#DEFINE  MOD     BT3
#DEFINE  STOP    BT3    
#DEFINE  OFF2    BT3

void xuat_32led_don_4byte(int8 b3,int8 b2,int8 b1,int8 b0)
{
      spi_write2(b3);spi_write2(b2);
      spi_write2(b1);spi_write2(b0);
      output_high(pin_d5); output_low(pin_d5);
}
void xuat_32led_don_2word(int16 w1,int16 w0)
{
      spi_write2(w1>>8);spi_write2(w1);
      spi_write2(w0>>8);spi_write2(w0);
      output_high(pin_d5); output_low(pin_d5);
}
void  xuat_32led_don_1dw(int32 dwl)
{
      spi_write2(dwl>>24);spi_write2(dwl>>16);
      spi_write2(dwl>>8);spi_write2(dwl);
      output_high(pin_d5); output_low(pin_d5);
}
void set_up_port_ic_chot()
{
      set_tris_d(0);
      set_tris_j(0xf0);
      set_tris_b(0x0f);
}
int1 inputcd (int16 chan)
{
      if(input(chan)==0)
       {
            delay_ms(20);
            if(input(chan)==0)
            {
                  while(input(chan)==0);
                  return 0;
            }
       }
       return 1;
}
