#ifndef    __TV_PICKIT2_SHIFT_1_C__
#define    __TV_PICKIT2_SHIFT_1_C__
#include<TV_PICKIT2_SHIFT_1.h>
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

int1 inputcd (int16 pin)
{
      static int16 oldpin=0xffff;
      static int1 tt=0;
      static int8 dem=0;
      if((input(pin)==0)&&(dem<_slcd_))
       {
         if(tt==0) {oldpin = pin;tt=1;}
         if(pin==oldpin) dem++; 
         if(dem==_slcd_) return 0;
      }
      else if((input(pin)==0)&&(dem>=_slcd_))
      {
          if(pin==oldpin) dem=_slcd_;
      }
      else if(input(pin)&&(dem<_slcd_))
      {
          if(pin==oldpin) dem=0;
      }
      else if(input(pin))
      {
          if(pin==oldpin) dem++;
          if(dem==2*_slcd_){tt=0; dem=0;oldpin=0xffff;}
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
void hien_thi_8led_7doan_quet_all()
{
      unsigned int8 n;
      for(n=0;n<8;n++)
      {        
            output_e(LED_7DQ[n]);
            output_f(~(0x80>>n));
            delay_ms(1); 
            output_f(0xff);
      }
}
void set_up_port_ic_chot()
{
      set_tris_a(0x10);
      set_tris_d(0);
      set_tris_j(0xf0);
      set_tris_b(0x0f);
      output_f(0xff);                             // tat led quet
      xuat_4led_7doan_4s0(0xff,0xff,0xff,0xff);   // tat 4 led 7 doan
      xuat_32led_don_1dw(0);                      // tat led don
}
#endif
