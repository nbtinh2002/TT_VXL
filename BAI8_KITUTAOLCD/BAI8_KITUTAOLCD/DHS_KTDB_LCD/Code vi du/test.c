// Bai nay chi chay khi dung thu vien LCD da them chuong trinh con sl(so,x,y) va them phan luu ma 8 ky tu vao CGRAM trong setup_lcd()
#include"E:\Teaching\Day TTVXL\NHOM_1_ST3_THOAN\TV_PICKIT2_SHIFT_1.c"
#include"E:\Teaching\Day TTVXL\NHOM_1_ST3_THOAN\TV_PICKIT2_SHIFT_LCD.c" // Add th? vi?n LCD
void main()
{     unsigned int8 i;
      SET_UP_PORT_IC_CHOT();
      SETUP_LCD ();        
      while(true)
      {
             for(i=0;i<100;i++)
             {
                  sl(i/10, 1, 7);
                  sl(i%10, 1, 10);
                  delay_ms(1000);
             }
      }
}

