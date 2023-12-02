#include<16f887.h>
#fuses  hs  // tuan sau se lam ro
#use delay(clock=20M)
// add cac thu vien va cac ngoai vi su dung
#include<lcd.c>  // vi du add thu vien lcd
// khai bao bien toan cuc
unsigned int8 gio, phut,giay;
// Viet cac chuong trinh con
void chinhthoigian()
{
      gio++;
      phut++;
      giay++;
}
void docthoigianturealtime()
{
      
}
// Viet chuong trinh chinh
void main()
{
      // nhung tac vu chi thuc hien 1 lan duy nhat
      gio =10;
      phut= 50;
      giay=6;
      while(true)
      {
            // nhung tac vu xu ly lien tuc
            docthoigianturealtime();
      }
      // tuyet doi khong viet gi sau while(true)
}




