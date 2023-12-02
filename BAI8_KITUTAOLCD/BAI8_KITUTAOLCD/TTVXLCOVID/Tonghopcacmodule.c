#include<TV_PICKIT2_SHIFT_1.c>
#include<TV_PICKIT2_SHIFT_LCD.c>
#include<TV_PICKIT2_SHIFT_KEY4x4_138.c>
#include<TV_PICKIT2_SHIFT_GLCD_192x64.c>
#define PIN_DS18B20_DATA PIN_c4
#include<TV_PICKIT2_SHIFT_DS18B20.c>
#include<math.h>
#include<DS18B20.c>
unsigned int8 gio=7, phut=26,giay=39;
unsigned int16 kc;
signed int16 ds18b201, ds18b202;
void xulydongho()
{
      giay++;
      if(giay==60)
      {
            giay=0; phut++;
            if(phut==60) 
            {
                  phut=0; gio++;
                  if(gio==13) gio=1;
            }
      }
      glcd_circle(31,31,31,1,0);
      glcd_graphic_text_setup(25,1,1,1);
      glcd_graphic_text("12");
      glcd_pixel(31,9,1);
      glcd_graphic_text_setup(29,56,1,1);
      glcd_graphic_text("6");
      glcd_pixel(31,54,1);
      glcd_graphic_text_setup(0,28,1,1);
      glcd_graphic_text("9");
      glcd_pixel(6,31,1);
      glcd_graphic_text_setup(58,28,1,1);
      glcd_graphic_text("3");
      glcd_pixel(56,31,1);
      glcd_triangle_fill(31,31,31+17*cos(pi*(gio-3)/6), 31+17*sin(pi*(gio-3)/6),31+13*cos(pi*(gio-3.3)/6), 31+13*sin(pi*(gio-3.3)/6),1);          
      glcd_triangle_fill(31,31,31+17*cos(pi*(gio-3)/6), 31+17*sin(pi*(gio-3)/6),31+13*cos(pi*(gio-2.7)/6), 31+13*sin(pi*(gio-2.7)/6),1);   
      
      glcd_bar(31, 31,  31+23*cos(pi*(phut-15)/30), 31+23*sin(pi*(phut-15)/30),2 ,1);
      glcd_line(31, 31, 31+30*cos(pi*(giay-15)/30), 31+30*sin(pi*(giay-15)/30),1);
      glcd_update_last_area(0, 0, 64, 63); 
      
}
unsigned int8 T0,mp,dem=0,L0=0,L1=0,L2=0,L3=0; 
void main()
{
      set_up_port_ic_chot();
      setup_adc(adc_clock_div_32);
      setup_adc_ports(AN0_TO_AN2|VSS_VDD);
      set_adc_channel(2); 
      setup_lcd();                   

      setup_timer_0(t0_ext_l_to_h|t0_div_1);
      set_timer0(0);
      LED_7DQ[0]= ma7doan[0];
      LED_7DQ[1]= ma7doan[1];
      LED_7DQ[2]= ma7doan[2];
      LED_7DQ[3]= ma7doan[3];
      
      LED_7DQ[5]= ma7doan[5];
      LED_7DQ[6]= ma7doan[6];
      LED_7DQ[7]= ma7doan[7];
      setup_glcd();
      glcd_update_full();
      xuat_4led_7doan_giaima_xoa_so0(1234);
   //   docromDS18B20();
      while(true)
      {
//!               ds18b201= docDS18B20(0);
//!               if(ds18b201!=0xffff)
//!               {
//!               ds18b201=ds18b201>>4;
//!               lcd_goto_xy(1,0);
//!               lcd_data(ds18b201/10%10+48);
//!               lcd_data(ds18b201/1%10+48);
//!               }
//!               ds18b202= docDS18B20(1);
//!               if(ds18b202!=0xffff)
//!               {
//!               ds18b202=ds18b202>>4;
//!               lcd_goto_xy(2,0);
//!               lcd_data(ds18b202/10%10+48);
//!               lcd_data(ds18b202/1%10+48);
//!               }
               hien_thi_8led_7doan_quet_all();
            lcd_command(0x28);  delay_ms(1000); 
            lcd_goto_xy(0,0);
            lcd_data(0xf9);
            lcd_command(0x2C); delay_ms(1000);
             lcd_data("y");
            lcd_goto_xy(1,0);
            lcd_data("VXL");
      
      
//!            T0 = get_timer0();
//!            kc = read_adc();
//!            kc=pow(2930/kc,1.106);
//!            if (kc>80)kc=80; 
//!            
//!            if(T0>24)set_timer0(1);
//!            lcd_hienthi_so_z_toado_xy(T0/10, 1,5);
//!            lcd_hienthi_so_z_toado_xy(T0%10, 1,8);
//!            //write_4lines_num(T0/10, 5);
//!            //write_4lines_num(T0%10, 9);
//!            mp= KEY_4X4_DW();
//!            if(mp==5)dem++;
//!            LED_7DQ[4]= ma7doan[dem%10];
//!        
//!            hien_thi_8led_7doan_quet_all();
//!            if(inputcd(ON)==0)  L0=~L0;
//!            if(inputcd(OFF)==0) L1=~L1;
//!            if(inputcd(INV)==0) L2=~L2;
//!            if(inputcd(MOD)==0) L3=~L3;
//!            xuat_32led_don_4byte(l3,l2,l1,l0); 
//!            glcd_rect(90,20,150,40,1,0);
//!            glcd_graphic_text_setup(90,20,3, 1);
//!            printf(glcd_graphic_text,"%lu",kc);
//!            glcd_update_last_raw();
            
           // glcd_graphic_text( T0%10+48);
          //  glcd_clear(1);
         //   glcd_update_full();
            //glcd_graphic_text( "HOAN");
//!           glcd_graphic_text( T0%10+48);
//!            glcd_update_last_change();
//!            glcd_bar(5,5,70,58,6,1);
//!             glcd_update_last_change();
        //   glcd_spkt_logo_raw(80);
          //glcd_rect(1,1,60,60,0,1);
           // glcd_update_last_change();
         //  glcd_bar(5,5,70,58,6,1);
           // glcd_update_last_raw();
         //  glcd_graphic_text_setup(30,2,5, 1);
        //   glcd_graphic_text( "HOAN");
          // glcd_update_last_change();
      //     glcd_circle(130,31,31,1,1);
         //  glcd_circle(130,31,25,1,0);
       //    glcd_update_last_area(0, 0, 150, 60); 
         //  glcd_vertical_line(2, 2,61, 0);
          // glcd_pixel(4,2,0);glcd_pixel(4,61,0);
         // glcd_update_full();
       //  glcd_triangle_fill(1,5, 120, 5, 90, 60,1);
       // glcd_update_full();
        
      //   xulydongho();
          // glcd_update_last_raw();
      }//
}
