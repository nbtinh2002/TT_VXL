#include"E:\Teaching\Day TTVXL\NHOM_1_ST3_THOAN\TV_PICKIT2_SHIFT_1.c"
signed int8 n,m;
void giaima()
{       // 0111 1111 => 1011 1111=> 1101 1111 
      LED_7DQ[0]= MA7DOAN [9];    
      LED_7DQ[1]= MA7DOAN [8];
      LED_7DQ[2]= MA7DOAN [7];    
      LED_7DQ[3]= MA7DOAN [6];
      LED_7DQ[4]= MA7DOAN [5];    
      LED_7DQ[5]= MA7DOAN [4];
      LED_7DQ[6]= MA7DOAN [3];    
      LED_7DQ[7]= MA7DOAN [2];

}
void main()
{
      SET_UP_PORT_IC_CHOT();
      giaima();
      while(true)
      {
            for(n=32;n>=0;n--)
            {
                  XUAT_32LED_DON_1DW(0xffffffff>>n);
                  for(m=0;m<50;m++)HIEN_THI_8LED_7DOAN_QUET_ALL();
            }
      }
  
}
