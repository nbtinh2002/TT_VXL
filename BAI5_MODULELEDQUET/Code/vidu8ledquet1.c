#include"E:\Teaching\Day TTVXL\NHOM_1_ST3_THOAN\TV_PICKIT2_SHIFT_1.c"
signed int8 n,m;
void hienthi()
{       // 0111 1111 => 1011 1111=> 1101 1111 
      XUAT_8LED_7DOAN_QUET_1(0x7f, MA7DOAN[9]); delay_ms(1); XUAT_8LED_7DOAN_QUET_1(0xff, 0xff);
      XUAT_8LED_7DOAN_QUET_1(0xbf, MA7DOAN[8]); delay_ms(1); XUAT_8LED_7DOAN_QUET_1(0xff, 0xff);
      XUAT_8LED_7DOAN_QUET_1(0xdf, MA7DOAN[7]); delay_ms(1); XUAT_8LED_7DOAN_QUET_1(0xff, 0xff);
      XUAT_8LED_7DOAN_QUET_1(0xef, MA7DOAN[6]); delay_ms(1); XUAT_8LED_7DOAN_QUET_1(0xff, 0xff);
      XUAT_8LED_7DOAN_QUET_1(0xf7, MA7DOAN[5]); delay_ms(1); XUAT_8LED_7DOAN_QUET_1(0xff, 0xff);
      XUAT_8LED_7DOAN_QUET_1(0xfb, MA7DOAN[4]); delay_ms(1); XUAT_8LED_7DOAN_QUET_1(0xff, 0xff);
      XUAT_8LED_7DOAN_QUET_1(0xfd, MA7DOAN[3]); delay_ms(1); XUAT_8LED_7DOAN_QUET_1(0xff, 0xff);
      XUAT_8LED_7DOAN_QUET_1(0xfe, MA7DOAN[2]); delay_ms(1); XUAT_8LED_7DOAN_QUET_1(0xff, 0xff);
}
void main()
{
      SET_UP_PORT_IC_CHOT();
      
      while(true)
      {
            for(n=32;n>=0;n--)
            {
                  XUAT_32LED_DON_1DW(0xffffffff>>n);
                  for(m=0;m<50;m++)hienthi();
            }
      }
  
}
