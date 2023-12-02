#ifndef    __TV_PICKIT2_SHIFT_1_H__
#define    __TV_PICKIT2_SHIFT_1_H__
#include    <18f8722.h>
#device     adc =10
#fuses      hs,PUT, NOWDT
#use        delay(clock=20M)
#USE        SPI(SPI2)
#define    _slcd_  3           // Neu ban phim, nut nhan bi doi thi sua so nay
#DEFINE  BT0     PIN_j4
#DEFINE  BT1     PIN_j5
#DEFINE  BT2     PIN_j6
#DEFINE  BT3     PIN_j7
#DEFINE  ON      BT0 
#DEFINE  UP      BT0  
#DEFINE  ON1     BT0 
#DEFINE  OFF     BT1
#DEFINE  DW      BT1
#DEFINE  OFF1    BT1
#DEFINE  INV     BT2
#DEFINE  ON2     BT2
#DEFINE  CLR     BT2
#DEFINE  MOD     BT3
#DEFINE  STOP    BT3    
#DEFINE  OFF2    BT3
   
CONST UNSIGNED CHAR MA7DOAN[16]= {0XC0,0XF9,0xA4,0XB0,0X99,0X92,0X82,0XF8,
0X80,0X90,0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};  
unsigned int8 LED_7DQ[8]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
void xuat_32led_don_4byte(int8 b3,int8 b2,int8 b1,int8 b0);
void xuat_32led_don_2word(int16 w1,int16 w0);
void xuat_32led_don_1dw(int32 dwl);
int1 inputcd (int16 pin);
void xuat_4led_7doan_4s0(int8 b3,int8 b2,int8 b1,int8 b0);
void xuat_4led_7doan_giaima_xoa_so0(unsigned int16 tam);
void xuat_8led_7doan_2byte(int8 data,int8 maquet);
void hien_thi_8led_7doan_quet_all();
void set_up_port_ic_chot();
#endif
