// dem san pham tu 1 den 10 hien thi 4 led 7 doan truc tiep
#include"E:\Teaching\Day TTVXL\NHOM_1_ST3_THOAN\TV_PICKIT2_SHIFT_1.c"
unsigned int8 sp;
void main()
{
      SET_UP_PORT_IC_CHOT();
      setup_timer_0(T0_EXT_L_TO_H|T0_DIV_1 );// chon nguon xung clock, chon bo chia truoc, cac che do hoat dong
      SET_TIMER0(1 ); // Muon dem tu dau tro len thi dat truoc vao day
      while(true)
      {
            sp =  get_timer0();
            if(sp>10){sp=1; SET_TIMER0(1 );}  // So sanh voi gioi han dem toi da, neu vuot qua thi reset ve gia tri bat dau dem
            XUAT_4LED_7DOAN_GIAIMA_XOA_SO0 (sp);
      }
}
