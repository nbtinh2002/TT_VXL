#include"E:\Teaching\Day TTVXL\NHOM_1_ST3_THOAN\TV_PICKIT2_SHIFT_1.c"
#include"E:\Teaching\Day TTVXL\NHOM_1_ST3_THOAN\TV_PICKIT2_SHIFT_LCD.c" // Add th? vi?n LCD
#include"math.h"
unsigned int16 kq1,kq2,kq3;
unsigned int8 n;
void main()
{
      SET_UP_PORT_IC_CHOT();
      SETUP_LCD (); 
      LCD_COMMAND(0x80);  
      LCD_DATA("Nhiet do LM351:  'C");  
      LCD_COMMAND(0xc0);  
      LCD_DATA("Nhiet do LM352:  'C"); 
      LCD_COMMAND(0x94);  
      LCD_DATA("Khoang Cach:   Cm"); 
      setup_adc(ADC_CLOCK_DIV_32);
      setup_adc_ports(AN0_TO_AN2|VSS_VDD );
      while(true)
      {
          set_adc_channel(0);
          kq1=0;                 // do trung binh kenh so 0
          for(n=0;n<100;n++)
          {
             kq1=kq1+ read_adc();
          }
          kq1=kq1/2.046;
          kq1=kq1/100;
          
          set_adc_channel(1);     // kenh so 1 do binh thuong
          kq2= read_adc();
          kq2=kq2/2.046;
          
          set_adc_channel(2);     // kenh so 2 do binh thuong
          kq3 = read_adc();
          kq3 = pow(4277/kq3,1.106);
          if(kq3>80)kq3=80;
          
          if(kq2<43) TRIAC_2_ON();   // vi du ve on dinh nhiet do
          else TRIAC_2_OFF();
          
          LCD_COMMAND(0x80+15);     // hien thi
          LCD_DATA(kq1/10+48); 
          LCD_DATA(kq1%10+48);
          LCD_COMMAND(0xc0+15);   
          LCD_DATA(kq2/10+48); 
          LCD_DATA(kq2%10+48);
          LCD_COMMAND(0x94+12);   
          LCD_DATA(kq3/10+48); 
          LCD_DATA(kq3%10+48);
      }       
}

