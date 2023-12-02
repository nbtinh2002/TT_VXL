#INCLUDE "E:\Teaching\Day TTVXL\NHOM_1_ST3_THOAN\TV_PICKIT2_SHIFT_1.c"
SIGNED INT8       BDN,dem=0;
#int_timer1                // Ch??ng trình con ph?c v? ng?t timer1
void ngatt1()
{     
    SET_TIMER1(3036);    // n?p l?i giá tr? ??u
    BDN++;                // N?u công vi?c ph?i th?c hi?n thành nhi?u l?n ( r?i vào tr??ng h?p ?ã s?  
                          // ?ã s? d?ng b? chia tr??c r?i mà v?n còn l?n h?n 65535 thì ti?n hành ghi 
                          // ghi nh?n ?ã tràn thêm 1 l?n
}
    
VOID MAIN()
{     
      SET_UP_PORT_IC_CHOT();    
      SETUP_TIMER_1(T1_INTERNAL | T1_DIV_BY_8);  // C?u hình timer1 ??m xung n?i và ch?n b? chia 
                                                 // tr??c cho phù h?p v?i k?t qu? tính toán 
      SET_TIMER1(3036);                         // ??t tr??c giá tr? ??m - nh? ?ã tính toán vd2                     
      ENABLE_INTERRUPTS(GLOBAL);                 // Cho phép ng?t toàn c?c
      ENABLE_INTERRUPTS(INT_TIMER1);              // Cho phép ng?t timer1
      WHILE(TRUE)
      {  
            // So sánh BDN v?i s? l?n c?n th?c hi?n(? ví d? này là 5) n?u ?? thì ti?n hành th?c thi
              If(BDN>=5)
                {
                      BDN=BDN-5;
                      dem++;
                      if(dem==60) dem=0;
                      LED_7DQ[3]= MA7DOAN [dem%10];    
                      LED_7DQ[4]= MA7DOAN [dem/10]; 
                }
              Else
                {
                     HIEN_THI_8LED_7DOAN_QUET_ALL();
                     // X? lý công vi?c khác khi ch?a ??nh th?i ??
                     
                }
 

      }
}

