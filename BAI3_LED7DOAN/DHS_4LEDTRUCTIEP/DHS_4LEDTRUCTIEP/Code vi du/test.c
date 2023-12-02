#include"E:\Teaching\Day TTVXL\NHOM_1_ST3_THOAN\TV_PICKIT2_SHIFT_1.c"
unsigned int16 t = 321;
unsigned int8 tram, chuc, dv, matram, machuc,madv;
void main()
{
      SET_UP_PORT_IC_CHOT();
      tram = t/100%10;      // tach so
      chuc = t/10%10;
      dv   = t%10;
      matram = MA7DOAN[tram]; // giai ma
      machuc = MA7DOAN[chuc];
      madv = MA7DOAN[dv];
      XUAT_4LED_7DOAN_4SO(0XFF,matram,machuc,madv);  // hien thi
      // Ban nao thao tac quen thi co the lam tat nhu sau
      //XUAT_4LED_7DOAN_4SO(0XFF,MA7DOAN[t/100%10],MA7DOAN[t/10%10],MA7DOAN[t%10]);
      //XUAT_4LED_7DOAN_GIAIMA_XOA_SO0 (t) ;
      while(true)
      {
      }
}
