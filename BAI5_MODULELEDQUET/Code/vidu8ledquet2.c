#include"E:\Teaching\Day TTVXL\NHOM_1_ST3_THOAN\TV_PICKIT2_SHIFT_1.c"
signed int8 n,m,i;
void hienthi()
{       // 0111 1111 => 1011 1111=> 1101 1111 
     for(i=0;i<8;i++)
      {
         XUAT_8LED_7DOAN_QUET_2(i, MA7DOAN[9-i]); delay_ms(1); XUAT_8LED_7DOAN_QUET_2(0xff, 0xff);
      }
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
