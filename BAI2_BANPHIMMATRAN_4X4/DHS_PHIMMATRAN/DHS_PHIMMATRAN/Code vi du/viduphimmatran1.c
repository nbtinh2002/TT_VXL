//Vi du dieu khien 32 led don sang dan bang cach nhan phim so 0 va tat dan bang cach nhan phim so 1 cua ban phim ma tran(chu y moi lan nhan thi se lam cho 1 led sang hoac tat di)
#include"E:\Teaching\Day TTVXL\NHOM_1_ST3_THOAN\TV_PICKIT2_SHIFT_1.c"
#include"E:\Teaching\Day TTVXL\NHOM_1_ST3_THOAN\TV_PICKIT2_SHIFT_KEY4X4_138.c"
unsigned int32 y=0;
unsigned int8 mp;
void main()
{
      SET_UP_PORT_IC_CHOT();
      while(true)
      {
            mp=KEY_4X4_DW();
            if(mp==0)y=(y<<1)+1;
            else if(mp==1) y=y>>1;
            XUAT_32LED_DON_1DW(y);
      }
}
