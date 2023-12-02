#include<TV_PICKIT2_SHIFT_1.c>
signed int8 n;
unsigned int16 m;
int1 tt=0;
void sangdan()
{
     for(n=32;n>=0;n--)
     {
         xuat_32led_don_1dw(0xffffffff>>n);
         delay_ms(50); 
            
     }
}
void sangdich()
{
     for(n=32;n>=0;n--)    
     {
         xuat_32led_don_1dw(0x80000000>>n);
         delay_ms(50);
     }
}
void sangdanif()
{
     if(n>=0)
     {
        xuat_32led_don_1dw(0xffffffff>>n);
        delay_ms(50);
        n--;
     }
     else
     {
        n=32;
     }
     
}
void sangdichif()
{
     if(n>=0)
     {
         xuat_32led_don_1dw(0x8000000>>n);
         delay_ms(50);
         n--;
     }
     else 
     {
        n=32; 
     }
}
void main()
{
      set_up_port_ic_chot();
      while(true)
      {
          if(tt==0) sangdanif();
          else      sangdichif();
          if(inputcd(INV)==0){tt=!tt;}
      }
}
