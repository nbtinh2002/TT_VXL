#ifndef  __TV_PICKIT2_SHIFT_LCD_H__
#define  __TV_PICKIT2_SHIFT_LCD_H__
#include<TV_PICKIT2_SHIFT_1.c>
#define  LCD_RS      PIN_D0
#define  LCD_E       PIN_D1
#define  LCD_D4      PIN_J0
#define  LCD_D5      PIN_J1
#define  LCD_D6      PIN_J2
#define  LCD_D7      PIN_J3

#DEFINE LCD_CLEAR_DISPLAY      0X01
#DEFINE LCD_SHIFT_LEFT         0X18
#DEFINE LCD_SHIFT_RIGHT        0X1C
#DEFINE LCD_ADDR_LINE1         0X80
#DEFINE LCD_ADDR_LINE2         0XC0
#DEFINE LCD_ADDR_LINE3         0X94
#DEFINE LCD_ADDR_LINE4         0XD4
CONST UNSIGNED CHAR LCD_SO_X[11][6] ={       // Font 3x2
                  0,1,2,5,3,4,               // SO 0
                  1,2,32,3,7,3,              // SO 1
                  6,6,2,5,3,3,               // SO 2
                  6,6,2,3,3,4,               // SO 3
                  5,3,7,32,32,7,             // SO 4
                  7,6,6,3,3,4,             // SO 5
                  0,6,6,5,3,4,               // SO 6
                  1,1,7,32,32,7,             // SO 7
                  0,6,2,5,3,4,               // SO 8
                  0,6,2,3,3,4,               // SO 9
                  32,32,32,32,32,32          // XOA
                  };             
CONST UNSIGNED int8 LCD_SO_X1[11][12] ={           //Font 3x4
                  0,1,2,7,32,7,7,32,7,5,3,4,       //0   
                  1,2,32,32,7,32,32,7,32,3,7,3,    //1  
                  1,1,2,3,3,7,7,32,32,5,3,3,       //2           
                  0,1,2,32,3,4,32,32,2,5,3,4,      //3
                  7,32,7,5,3,7,32,32,7,32,32,7,    //4             
                  7,1,1,7,3,3,32,32,7,5,3,4,       //5           
                  0,1,2,7,3,3,7,32,7,5,3,4,        //6             
                  1,1,7,32,32,4,32,0,32,32,7,32,   //7             
                  0,1,2,5,3,4,0,32,2,5,3,4,        //8     
                  0,1,2,5,3,7,32,32,7,5,3,4,       //9 
                  32,32,32,32,32,32,32,32,32,32,32,32}; //XOA                  
                  
CONST UNSIGNED int8 LCD_MA_8DOAN[] = {
                  0x07,0x0F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,  
                  0x1F,0x1F,0x1F,0X00,0X00,0X00,0X00,0X00,  
                  0x1C,0x1E,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F, 
                  0X00,0X00,0X00,0X00,0X00,0x1F,0x1F,0x1F,  
                  0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1E,0x1C,  
                  0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x0F,0x07, 
                  0x1F,0x1F,0x1F,0X00,0X00,0X00,0x1F,0x1F,  
                  0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F}; 
   
//!const unsigned char traitao[]={
//!               0,0,0,0x0c,0x1f,0x1f,0x1f,0x1f,
//!               0x0e,0x1c,0x10,0x06,0x1f,0x1f,0x1f,0x1f
//!               ,0x0f,0x07,0x03,0,0,0,0,0,
//!               0x1e,0x1c,0x18,0,0,0,0,0};

void lcd_command(int8 d);
void lcd_data(int8 d);
void setup_lcd();
void lcd_goto_xy( int8 x, int8 y);
void lcd_hienthi_so_z_toado_xy(signed int8 lcd_so, x1, y1) ;
void write_4lines_num(int8 so, int8 x);
#endif
