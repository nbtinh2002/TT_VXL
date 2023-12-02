#ifndef    __TV_PICKIT2_SHIFT_1_C__
#define    __TV_PICKIT2_SHIFT_1_C__
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
CONST UNSIGNED CHAR MA7DOAN[16]= {0XC0,0XF9,0xA4,0XB0,0X99,0X92,0X82,0XF8,
0X80,0X90,0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};  
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

void xuat_4led_7doan_4s0(int8 b3,int8 b2,int8 b1,int8 b0)
{
      spi_write2(b0);spi_write2(b1);
      spi_write2(b2);spi_write2(b3);
      output_high(pin_d7); output_low(pin_d7);
}

void xuat_4led_7doan_giaima_xoa_so0(unsigned int16 tam)
{
      unsigned int8 ngan,tram,chuc,dv;
      ngan = ma7doan[tam/1000%10];
      tram = ma7doan[tam/100%10];
      chuc = ma7doan[tam/10%10];
      dv   = ma7doan[tam/1%10];
      if(ngan==0xc0) 
      {
            ngan = 0xff;  // tat led
            if(tram==0xc0)
            {
                  tram = 0xff;
                  if(chuc==0xc0) chuc = 0xff;
            }
      }
      xuat_4led_7doan_4s0(ngan,tram,chuc,dv);     
}

void xuat_8led_7doan_2byte(int8 data,int8 maquet)
{
      spi_write2(maquet);spi_write2(data);
      output_high(pin_d3); output_low(pin_d3);
}
void xuat_8led7doanquet_2byte(int8 dlht,int8 maquet)
{
      spi_write2(maquet);spi_write2(dlht);
      output_high(pin_d3); output_low(pin_d3);
}
unsigned int8 LED_7DQ[8]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
void hien_thi_8led_7doan_quet_all()
{
      unsigned int8 n;
      for(n=0;n<8;n++)
      {                                                              
            xuat_8led7doanquet_2byte(LED_7DQ[n],~(0x80>>n)); 
            delay_ms(1); xuat_8led7doanquet_2byte(0xff,0xff);
      }
}

void set_up_port_ic_chot()
{
      set_tris_a(0x10);
      set_tris_d(0);
      set_tris_j(0xf0);
      set_tris_b(0x0f);
      port_b_pullups(0x0f);
      xuat_4led_7doan_4s0(0xff,0xff,0xff,0xff);
}
#endif
