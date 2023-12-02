//Vi du dieu khien 32 led don sang 3 kieu duoc chon boi cac phim so 0,1,2 cua ban phim ma tran
#include"E:\Teaching\Day TTVXL\NHOM_1_ST3_THOAN\TV_PICKIT2_SHIFT_1.c"
#include"E:\Teaching\Day TTVXL\NHOM_1_ST3_THOAN\TV_PICKIT2_SHIFT_KEY4X4_138.c"
#include"E:\Teaching\Day TTVXL\NHOM_1_ST3_THOAN\TV_PICKIT2_SHIFT_32LED_DON.c"
unsigned int8 mp,mpt;
void main()
{
      SET_UP_PORT_IC_CHOT();
      while(true)
      {
            mpt=KEY_4X4_DW();
            if(mpt!=0xff) mp=mpt;
            if(mp==0)DIEM_SANG_DICH_TRAI_MAT_DAN_32LED(40,0);
            else if(mp==1) SANG_TAT_DAN_TRAI_SANG_PHAI_2X16LED(40,0);
            else if(mp==2) SANG_DON_PST_32LED(40,0);
      }
}
