// hien thi hang so 0 chuoi "Ket Qua Dem SP", hang so 1 hien thi ket qua dem san pham tu 20 ve 10, hang so 2 hien thi dau sizma kem theo tong so san pham dem duoc sau no
#include"E:\Teaching\Day TTVXL\NHOM_1_ST3_THOAN\TV_PICKIT2_SHIFT_1.c"
#include"E:\Teaching\Day TTVXL\NHOM_1_ST3_THOAN\TV_PICKIT2_SHIFT_LCD.c" // Add th? vi?n LCD
#include"E:\Teaching\Day TTVXL\NHOM_1_ST3_THOAN\TV_PICKIT2_SHIFT_KEY4X4_138.c"
#include"E:\Teaching\Day TTVXL\NHOM_1_CT3_THOAN\TV_PICKIT2_SHIFT_32LED_DON.c"
unsigned int8 mp;     // Khai báo bi?n ?? ch?a mã phím ??c v?
signed int16 sp=0,tong=0;  // Khai báo bi?n ch?a k?t qu? ??m
SIGNED INT8       BDN,gio=2,phut=0,giay=0;
#int_timer1                // Ch??ng trình con ph?c v? ng?t timer1
void ngatt1()
{     
    SET_TIMER1(3036);    // n?p l?i giá tr? ??u
    BDN++;                // N?u công vi?c ph?i th?c hi?n thành nhi?u l?n ( r?i vào tr??ng h?p ?ã s?  
                          // ?ã s? d?ng b? chia tr??c r?i mà v?n còn l?n h?n 65535 thì ti?n hành ghi 
                          // ghi nh?n ?ã tràn thêm 1 l?n
}

void main()
{
      SET_UP_PORT_IC_CHOT();
      SETUP_LCD ();             
      LCD_GOTO_XY(0,2);  
      LCD_DATA("Ket Qua Dem SP");
      LCD_GOTO_XY(2,7);
      LCD_DATA(0xf6);
      LCD_DATA(':');
      setup_timer_0(T0_EXT_L_TO_H|T0_DIV_1 );// ch?n ch? ?? ??m xung ngo?i và b? chia tr??c tùy                                                                            //thu?c vào giá tr? ??m và gi?i h?n ??m( 65535) ??i v?i ch? ?? 16 bit
      SET_TIMER0(0); 
      SETUP_TIMER_1(T1_INTERNAL | T1_DIV_BY_8);  // C?u hình timer1 ??m xung n?i và ch?n b? chia 
      SET_TIMER1(3036);                         // ??t tr??c giá tr? ??m - nh? ?ã tính toán vd2                     
      ENABLE_INTERRUPTS(GLOBAL);                 // Cho phép ng?t toàn c?c
      ENABLE_INTERRUPTS(INT_TIMER1);              // Cho phép ng?t timer1
      while(true)
      {       
              SANG_DON_PST_32LED(40,1);
              mp=KEY_4X4_DW();
              if(mp!=0xff)XUAT_4LED_7DOAN_GIAIMA_XOA_SO0 (mp) ;
              If(BDN>=10)
                {
                      BDN=BDN-10;
                      giay++;
                      if(giay==60)
                      {
                           giay=0;phut++;
                           if(phut==60)
                           {
                                 phut=0;gio++;
                                 if(gio==13)gio=1;
                           }
                      }
                        LED_7DQ[0]= MA7DOAN [giay%10];    
                        LED_7DQ[1]= MA7DOAN [giay/10];
                        LED_7DQ[2]= 0xbf;   
                        LED_7DQ[3]= MA7DOAN [phut%10];
                        LED_7DQ[4]= MA7DOAN [phut/10];
                        LED_7DQ[5]= 0xbf;
                        LED_7DQ[6]= MA7DOAN [gio%10];
                        LED_7DQ[7]= MA7DOAN [gio/10];
                }             
            HIEN_THI_8LED_7DOAN_QUET_ALL(); 
            sp = 20- get_timer0();                                         // ??c k?t qu? ??m v? - nh? là ph?i ?? trong while(true)
            if(sp<10){sp=20; SET_TIMER0(0);tong=tong+11;}
            LCD_GOTO_XY(1,9);
            LCD_DATA(sp/10%10+ 0x30);     // hi?n th? hàng ch?c
            LCD_DATA(sp%10+ 0x30);          // hi?n th? hàng ??n v?
            LCD_GOTO_XY(2,9);
            if(tong>999) tong=0;
            LCD_DATA(((get_timer0()+tong)/100%10)+ 0x30);   // hi?n th? hàng tr?m
            LCD_DATA(((get_timer0()+tong)/10%10)+ 0x30);     // hi?n th? hàng ch?c
            LCD_DATA(((get_timer0()+tong)%10)+ 0x30);          // hi?n th? hàng ??n v?  
      }
}

