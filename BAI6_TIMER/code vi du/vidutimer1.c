#INCLUDE "E:\Teaching\Day TTVXL\NHOM_1_ST3_THOAN\TV_PICKIT2_SHIFT_1.c"
SIGNED INT8       BDN,dem=0;
#int_timer1                // Ch??ng tr�nh con ph?c v? ng?t timer1
void ngatt1()
{     
    SET_TIMER1(3036);    // n?p l?i gi� tr? ??u
    BDN++;                // N?u c�ng vi?c ph?i th?c hi?n th�nh nhi?u l?n ( r?i v�o tr??ng h?p ?� s?  
                          // ?� s? d?ng b? chia tr??c r?i m� v?n c�n l?n h?n 65535 th� ti?n h�nh ghi 
                          // ghi nh?n ?� tr�n th�m 1 l?n
}
    
VOID MAIN()
{     
      SET_UP_PORT_IC_CHOT();    
      SETUP_TIMER_1(T1_INTERNAL | T1_DIV_BY_8);  // C?u h�nh timer1 ??m xung n?i v� ch?n b? chia 
                                                 // tr??c cho ph� h?p v?i k?t qu? t�nh to�n 
      SET_TIMER1(3036);                         // ??t tr??c gi� tr? ??m - nh? ?� t�nh to�n vd2                     
      ENABLE_INTERRUPTS(GLOBAL);                 // Cho ph�p ng?t to�n c?c
      ENABLE_INTERRUPTS(INT_TIMER1);              // Cho ph�p ng?t timer1
      WHILE(TRUE)
      {  
            // So s�nh BDN v?i s? l?n c?n th?c hi?n(? v� d? n�y l� 5) n?u ?? th� ti?n h�nh th?c thi
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
                     // X? l� c�ng vi?c kh�c khi ch?a ??nh th?i ??
                     
                }
 

      }
}

