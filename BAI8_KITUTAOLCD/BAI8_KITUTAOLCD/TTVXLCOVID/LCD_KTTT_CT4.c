#include<TV_PICKIT2_SHIFT_1.c>
#include<TV_PICKIT2_SHIFT_LCD.c>
#include<TV_PICKIT2_SHIFT_KEY4x4_138.c>
unsigned int8 n,dem=0,mp,kq=0,led=0,led1=0,led2=0,led3=0;

void main() 
{
      set_up_port_ic_chot();
      setup_lcd();
      lcd_command(0x40);                          // di chuyen toi vung nho CGRAM
      for(n=0;n<64;n++) lcd_data(LCD_MA_8DOAN[n]);
      LED_7DQ[0]= ma7doan[kq];
      LED_7DQ[1]= 0xbf;
      LED_7DQ[2]= ma7doan[2];
      LED_7DQ[3]= ma7doan[3];
      LED_7DQ[4]= ma7doan[4];
      LED_7DQ[5]= ma7doan[5];
      LED_7DQ[6]= ma7doan[6];
      LED_7DQ[7]= ma7doan[7];
      while(true)
      {
          lcd_hienthi_so_z_toado_xy(dem, 1,9);
          dem++; if(dem==10) dem=0;
          hien_thi_8led_7doan_quet_all();
          mp =key_4x4_dw();
          LED_7DQ[0]= ma7doan[kq];
          if(mp!=0xff) kq = mp;
          if(inputcd(ON)==0)LED=~LED;
          if(inputcd(OFF)==0)LED1=~LED1;
          if(inputcd(INV)==0)LED2=~LED2;
          if(inputcd(MOD)==0)LED3=~LED3;
          xuat_32led_don_4byte(led3,led2,led1,led);
          
      }
}

