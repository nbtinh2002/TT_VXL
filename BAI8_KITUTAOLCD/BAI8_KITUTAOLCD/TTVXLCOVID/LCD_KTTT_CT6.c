#include<TV_PICKIT2_SHIFT_1.c>
#include<TV_PICKIT2_SHIFT_LCD.c>
unsigned int8 dem=0;

void main()
{
      set_up_port_ic_chot();
      setup_lcd();
      while(true)
      {
           dem++; 
           if(dem==100)dem=0;
           lcd_hienthi_so_z_toado_xy(dem/10%10, 1, 0) ;
           lcd_hienthi_so_z_toado_xy(dem/1%10, 1, 3) ;
           
           write_4lines_num(dem/10%10,10);
            write_4lines_num(dem/1%10,14);
      }
           delay_ms(200);
           
            
}

