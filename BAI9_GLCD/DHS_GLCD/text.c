#include"E:\Teaching\Day TTVXL\NHOM_1_CT3_THOAN\TV_PICKIT2_SHIFT_1.c"
#include"E:\Teaching\Day TTVXL\NHOM_1_CT3_THOAN\TV_PICKIT2_SHIFT_GLCD128X64.c"
#include"C:\Program Files (x86)\PICC\Drivers\GRAPHICS.C"        
void main()
{
      SET_UP_PORT_IC_CHOT();
      SETUP_GLCD (0x30);                 // che do text
      GLCD_COMMAND(0x01);delay_ms(2);    // xoa man hinh che do text nho phai delay nhe
      GLCD_DATA("SPKT");  
      SETUP_GLCD (0x36);                 // che do graphic
      GLCD_MAU_NEN(0) ;                  // xoa man hinh o che do graphic
      glcd_rect(15,25,25,40,1,1);
      glcd_circle(20,20,5,1, 1);
      glcd_bar(15, 25,10,35, 2, 1);
      glcd_bar(25, 25,30,15, 2, 1);
      glcd_bar(15, 40,12,60, 4, 1);
      glcd_bar(25, 40,28,60, 4, 1);
      glcd_bar(20, 40,20,43, 2, 1);
      GLCD_XUAT_ANH(64,64,63,0);
      GDRAM_VDK_TO_GDRAM_GLCD_ALL();        // sau khi ve xong phai goi chuong trinh nay thi moi hien thi duoc
      while(true)
      {
      }
}
