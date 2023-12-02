#ifndef __TV_PICKIT2_SHIFT_GLCD_192x64_C__
#define __TV_PICKIT2_SHIFT_GLCD_192x64_C__
#include<TV_PICKIT2_SHIFT_GLCD_192x64.h>
void glcd_clear(data)
{
   unsigned int8 i, j,color;
   if(data) color =0xff;
   else     color =0;
   for(i = 0; i < 8; ++i)
    for(j = 0; j < 192; ++j)
     displayData[i][j]= color; 
   area_codinate.x1 = 0;
   area_codinate.x2 = 191;
   area_codinate.y1 = 0;
   area_codinate.y2 = 63;   
}
void glcd_pixel(unsigned int8 x, unsigned int8 y, int1 color)
{
   if(color)
      bit_set(displayData[y/8][x], y%8);
   else
      bit_clear(displayData[y/8][x], y%8);
   area_codinate.x1 = x;
   area_codinate.x2 = x;
   area_codinate.y1 = y;
   area_codinate.y2 = y;
}

void glcd_pixel_temp(unsigned int8 x, unsigned int8 y, int1 color)
{
   if(color)
      bit_set(displayData[y/8][x], y%8);
   else
      bit_clear(displayData[y/8][x], y%8);
}

void glcd_vertical_line(unsigned int8 x, unsigned int8 y1,unsigned int8 y2, int1 color)
{
   unsigned int8 i,top,bot;
   top=y1/8; bot = y2/8;
   if (top==bot) 
   {
          if(color)     
               displayData[top][x]= displayData[top][x] | ((0xff<<(y1%8)) & (0xff>>(7-(y2%8))));   
          else 
               displayData[top][x]= displayData[top][x] &(~((0xff<<(y1%8)) & (0xff>>(7-(y2%8)))));
   }
   else 
   {
          if(color)
          {    
               displayData[top][x]= displayData[top][x] | (0xff<<(y1%8));
               displayData[bot][x]= displayData[bot][x] | (0xff>>(7-(y2%8)));
               for(i = top + 1; i < bot; i++) displayData[i][x]=0xff;
          }
          else 
          {    
               displayData[top][x]= displayData[top][x] & (~(0xff<<(y1%8)));
               displayData[bot][x]= displayData[bot][x] & (~(0xff>>(7-(y2%8))));
               for(i = top + 1; i < bot; i++)displayData[i][x]=0;
          } 
   }
}
void glcd_update_last_raw()
{
    unsigned int8 i, j;
    area_codinate.y1=area_codinate.y1/8;
    area_codinate.y2=area_codinate.y2/8;
    for(i = area_codinate.y1; i <=area_codinate.y2; i++)
    {  
         output_high(GLCD_CSA);
         output_high(GLCD_CSB);
         output_high(GLCD_CSC);
         if(area_codinate.x1<64)
          {    output_low(GLCD_CSA);
               glcd_column(area_codinate.x1);      
          }
         else if(area_codinate.x1<128)
          {    output_low(GLCD_CSB);
               glcd_column((area_codinate.x1)-64); 
          }
         else 
          {    output_low(GLCD_CSC);
               glcd_column((area_codinate.x1)-128); 
          }  
         glcd_page(i); 
         for (j=area_codinate.x1;j<= area_codinate.x2;j++)
         {
               if(j==64)      {output_high(GLCD_CSA);output_low(GLCD_CSB);glcd_column(0);glcd_page(i); }
               else if(j==128){output_high(GLCD_CSB);output_low(GLCD_CSC);glcd_column(0);glcd_page(i); }
               glcd_data(displayData[i][j]);  
         }
    }        
}

void glcd_update_area(unsigned int8 x1, unsigned int8 y1, unsigned int8 x2, unsigned int8 y2)
{
   area_codinate.x1 = x1;
   area_codinate.x2 = x2;
   area_codinate.y1 = y1;
   area_codinate.y2 = y2;
   glcd_update_last_raw(); 
}

void glcd_update_full()
{
   unsigned int8 i, j;
   output_low(GLCD_CSA);      // write ks1080 A
   for(i = 0; i < 8; ++i)
   {  
      glcd_page(i);         
      glcd_column(0); 
      for(j = 0; j < 64; ++j)
      {
         
         glcd_data(displayData[i][j]);  
      }
   }
   output_high(GLCD_CSA);     // write ks1080 B
   output_low(GLCD_CSB);
   for(i = 0; i < 8; ++i)
   {  
      glcd_page(i);         
      glcd_column(0);  
      for(j = 64; j < 128; ++j)
      {
         
         glcd_data(displayData[i][j]);  
      }
   }
   output_high(GLCD_CSB);     // write ks1080 C
   output_low(GLCD_CSC);
   for(i = 0; i < 8; ++i)
   {  
      glcd_page(i);         
      glcd_column(0);  
      for(j = 128; j < 192; ++j)
      {
         
         glcd_data(displayData[i][j]);  
      }
   }
   output_high(GLCD_CSC);
}

int1 __tt_write_text__=1;
void glcd_text_setup(unsigned int16 x, unsigned int16 y,int8 size, int8 mau)
{
      glcd_grt.mau = mau;
      glcd_grt.size = size;
      glcd_grt.x    = x;
      glcd_grt.y    =y;
      __tt_write_text__=0;
}

void glcd_text( char t)
{
      unsigned int8 j, k, l, m;                      
      unsigned int8 pixelData[5]; 
      if(__tt_write_text__==0)
      {
          area_codinate.x1=glcd_grt.x;
          area_codinate.y1=glcd_grt.y;
          __tt_write_text__=1;
      }
      if(t < 'S')
         memcpy(pixelData, FONT[t - ' '], 5);
      else if(t <= '~') 
         memcpy(pixelData, FONT2[t - 'S'], 5);
      else
         memcpy(pixelData, FONT[0], 5);   
      if(glcd_grt.x+5*glcd_grt.size >= GLCD_WIDTH)         
      {
         glcd_grt.x = 0;                           
         glcd_grt.y += 7*glcd_grt.size + 1;                 
      }
      for(j=0; j<5; ++j, glcd_grt.x+=glcd_grt.size)         
      {
         for(k=0; k < 7; ++k)             
         {
            if(bit_test(pixelData[j], k)) 
            {
               for(l=0; l < glcd_grt.size; ++l)   
               {                         
                  for(m=0; m < glcd_grt.size; ++m)
                  {
                     glcd_pixel_temp(glcd_grt.x+m, glcd_grt.y+k*glcd_grt.size+l, glcd_grt.mau); 
                  }
               }
            }
         }
      }
      area_codinate.x2 = glcd_grt.x;
      glcd_grt.x+=glcd_grt.size;
      area_codinate.y2= glcd_grt.y + 7*glcd_grt.size;
 }
 

void glcd_spkt_logo_raw(int x) 
{ 
   unsigned int8 i=0, j=0, k=0,y=0; 
   unsigned int16 count=0; 
   area_codinate.x1=x;
   area_codinate.y1=0;
   area_codinate.x2=x+64;
   area_codinate.y2=63;
   for(j=0;j<64;j++) 
      {    
         for(;i<64;) 
         { 
            for(k=8;k>0;k--)
            {
               glcd_pixel_temp(i+x,j+y,bit_test(Logo_DHSPKTTP[count],(k-1))); 
               i++; 
            } 
            count++; 
         } 
      i=0; 
      } 
} 

void glcd_line(unsigned int8 x1, unsigned int8 y1, unsigned int8 x2, unsigned int8 y2, int1 color)
{
   unsigned int16        dy, dx;
   signed int8  addx=1, addy=1;
   signed int16 P, diff;
   unsigned int8 i=0;
   area_codinate.x1=x1;
   area_codinate.y1=y1;
   area_codinate.x2=x2;
   area_codinate.y2=y2;
   dx = abs((signed int8)(x2 - x1));
   dy = abs((signed int8)(y2 - y1));
   if(x1 > x2)
   {
      addx = -1;
      area_codinate.x2=x1;
      area_codinate.x1=x2;
   }
   if(y1 > y2)
   {
      addy = -1;
      area_codinate.y2=y1;
      area_codinate.y1=y2;
   }
   if(dx >= dy)
   {
      dy *= 2;
      P = dy - dx;
      diff = P - dx;

      for(; i<=dx; ++i)
      {
         glcd_pixel_temp(x1, y1, color);

         if(P < 0)
         {
            P  += dy;
            x1 += addx;
         }
         else
         {
            P  += diff;
            x1 += addx;
            y1 += addy;
         }
      }
   }
   else
   {
      dx *= 2;
      P = dx - dy;
      diff = P - dy;

      for(; i<=dy; ++i)
      {
         glcd_pixel_temp(x1, y1, color);

         if(P < 0)
         {
            P  += dx;
            y1 += addy;
         }
         else
         {
            P  += diff;
            x1 += addx;
            y1 += addy;
         }
      }
   }
}

void glcd_rect(unsigned int8 x1, unsigned int8 y1, unsigned int8 x2, unsigned int8 y2, int1 fill, int1 color)
{
      unsigned int8  xmin, xmax, ymin, ymax,i;
      xmin = x1;
      xmax = x2;
      ymin = y1;
      ymax = y2;
      if(x1 > x2)                            
      {
         xmin = x2;
         xmax = x1;
      }
      if(y1 > y2)                           
      {
         ymin = y2;
         ymax = y1;
      }
      if(fill)
      {
         for(i=xmin; i <= xmax; i++)
            glcd_vertical_line(i, ymin,ymax,color);
      }
      else
      {
         glcd_vertical_line(xmin, ymin,ymax, color);
         glcd_vertical_line(xmax, ymin,ymax, color);
         glcd_line(x1, y1, x2, y1, color);      // Draw the 4 sides
         glcd_line(x1, y2, x2, y2, color);
      }
      area_codinate.x1=xmin;
      area_codinate.x2=xmax;
      area_codinate.y1=ymin;
      area_codinate.y2=ymax;
}

void glcd_bar(unsigned int8 x1, unsigned int8 y1, unsigned int8 x2, unsigned int8 y2, unsigned int8 width, int1 color)
{
   unsigned int8         half_width;
   signed int16 dy, dx;
   signed int8  addx=1, addy=1, j;
   signed int16 P, diff, c1, c2;
   unsigned int8 i=0;
   dx = abs((signed int8)(x2 - x1));
   dy = abs((signed int8)(y2 - y1));
   half_width = width/2;
   c1 = -(dx*x1 + dy*y1);
   c2 = -(dx*x2 + dy*y2);  
   area_codinate.x1=x1-half_width;
   area_codinate.x2=x2+half_width;
   area_codinate.y1=y1-half_width;
   area_codinate.y2=y2+half_width;

   if(x1 > x2)
   {
      signed int16 temp;
      temp = c1;
      c1 = c2;
      c2 = temp;
      addx = -1;
      area_codinate.x1=x2-half_width;
      area_codinate.x2=x1+half_width;  
   }
   if(y1 > y2)
   {
      signed int16 temp;
      temp = c1;
      c1 = c2;
      c2 = temp;
      addy = -1;
      area_codinate.y1=y2-half_width;
      area_codinate.y2=y1+half_width;
   }
   if(area_codinate.x1>191)   area_codinate.x1=0;
   if(area_codinate.y1>191)   area_codinate.y1=0;
   if(area_codinate.x2>191) area_codinate.x2=191;
   if(area_codinate.y2>63)  area_codinate.y2=63;
   
   if(dx >= dy)
   {
      P = 2*dy - dx;
      diff = P - dx;

      for(i=0; i<=dx; ++i)
      {
         for(j=-half_width; j<half_width+width%2; ++j)
         {
               glcd_pixel_temp(x1, y1+j, color);
         }
         if(P < 0)
         {
            P  += 2*dy;
            x1 += addx;
         }
         else
         {
            P  += diff;
            x1 += addx;
            y1 += addy;
         }
      }
   }
   else
   {
      P = 2*dx - dy;
      diff = P - dy;

      for(i=0; i<=dy; ++i)
      {
         if(P < 0)
         {
            P  += 2*dx;
            y1 += addy;
         }
         else
         {
            P  += diff;
            x1 += addx;
            y1 += addy;
         }
         for(j=-half_width; j<half_width+width%2; ++j)
         {
               glcd_pixel_temp(x1+j, y1, color);
         }
      }
   }
}

void glcd_circle(unsigned int8 x, unsigned int8 y, unsigned int8 radius, int1 fill, int1 color)
{
   signed int8  a, b, P;
   a = 0;
   b = radius;
   P = 1 - radius;
   do
   {
      if(fill)
      {
          glcd_vertical_line(x+b, y-a,y+a, color);
          glcd_vertical_line(x-b, y-a,y+a, color);
          glcd_vertical_line(x+a, y-b,y+b, color);
          glcd_vertical_line(x-a, y-b,y+b, color);
      }
      else
      {
         glcd_pixel_temp(a+x, b+y, color);
         glcd_pixel_temp(b+x, a+y, color);
         glcd_pixel_temp(x-a, b+y, color);
         glcd_pixel_temp(x-b, a+y, color);
         glcd_pixel_temp(b+x, y-a, color);
         glcd_pixel_temp(a+x, y-b, color);
         glcd_pixel_temp(x-a, y-b, color);
         glcd_pixel_temp(x-b, y-a, color);
      }

      if(P < 0)
         P += 3 + 2 * a++;
      else
         P += 5 + 2 * (a++ - b--);
    } while(a <= b);
    area_codinate.x1 = x-radius;
    area_codinate.x2 = x+radius;
    area_codinate.y1 = y-radius;
    area_codinate.y2 = y+radius;
    if(area_codinate.x1>191)   area_codinate.x1=0;
    if(area_codinate.y1>191)   area_codinate.y1=0;
    if(area_codinate.x2>191)   area_codinate.x2=191;
    if(area_codinate.y2>63)    area_codinate.y2=63;
}
void glcd_triangle(signed int16 x1,signed int16 y1, signed int16 x2, signed int16 y2, signed int16 x3, signed int16 y3,int1 fill,int1 color)
{
    signed int16 x[3],y[3],n,yt1,yt2,yt,dx1,dx2,dx3,dy1,dy2,dy3; 
    signed int16 sh1,sh2,sh3;
    x[0]=x1; x[1]=x2; x[2]=x3;y[0]=y1; y[1]=y2; y[2]=y3;
    if(x[0]>x[1]){yt=x[0];x[0]=x[1];x[1]=yt;yt=y[0];y[0]=y[1];y[1]=yt;}
    if(x[0]>x[2]){yt=x[0];x[0]=x[2];x[2]=yt;yt=y[0];y[0]=y[2];y[2]=yt;}
    if(x[1]>x[2]){yt=x[1];x[1]=x[2];x[2]=yt;yt=y[1];y[1]=y[2];y[2]=yt;}
    dx1= x[2]-x[0]; dx2= x[1]-x[0];dx3=x[2]-x[1];
    dy1= y[2]-y[0]; dy2= y[1]-y[0];dy3=y[2]-y[1];
    sh1=x[2]*y[0] - x[0]*y[2]; sh2=x[1]*y[0] - x[0]*y[1]; sh3=x[2]*y[1] - x[1]*y[2];
    if(fill)
    {
        for(n=x[0] ; n<x[1]; n++)
          {
              yt1= (dy1*n + sh1)/dx1;
              yt2= (dy2*n + sh2)/dx2;
              if(yt2<yt1){yt= yt1; yt1=yt2; yt2=yt;}
              glcd_vertical_line(n,yt1,yt2,color);
          }
          for(n=x[1] ; n<x[2]; n++)
          {
              yt1= (dy1*n + sh1)/dx1;
              yt2= (dy3*n + sh3)/dx3;
              if(yt2<yt1){yt= yt1; yt1=yt2; yt2=yt;}
              glcd_vertical_line(n,yt1,yt2,color);
          }  
    }
    else 
    {
         glcd_line(x1,y1,x2,y2,color);
         glcd_line(x1,y1,x3,y3,color);
         glcd_line(x2,y2,x3,y3,color);
    }
    area_codinate.x1 = x[0];
    area_codinate.x2 = x[2];
    if(y[0]>y[1]) area_codinate.y2= y[0]; else area_codinate.y2 = y[1];
    if(area_codinate.y2<y[2]) area_codinate.y2 = y[2]; 
    if(y[0]<y[1]) area_codinate.y1= y[0]; else area_codinate.y1 = y[1];
    if(area_codinate.y1>y[2]) area_codinate.y1 = y[2];
       
       
}
void glcd_data(int8 data)
{
   output_high(glcd_rs);
   output_glcd(data);             
   output_high(glcd_e);     
   output_low(glcd_e);  
   delay_cycles(4);
}
void glcd_command(int8 data)
{
   output_low(glcd_rs);
   output_glcd(data);             
   output_high(glcd_e);     
   output_low(glcd_e);  
   delay_us(4);
}
void setup_glcd()
{
   output_low(GLCD_CSA);
   output_low(GLCD_CSB);
   output_low(GLCD_CSC);
   glcd_on();
   glcd_clear(0);
   glcd_update_full();
   output_high(GLCD_CSA);
   output_high(GLCD_CSB);
   output_high(GLCD_CSC);
}
#endif

//                                           Mau dong ho kim
//! glcd_triangle_fill(31,31,31+17*cos(pi*(gio-3)/6), 31+17*sin(pi*(gio-3)/6),31+13*cos(pi*(gio-3.3)/6), 31+13*sin(pi*(gio-3.3)/6),1);          
//! glcd_triangle_fill(31,31,31+17*cos(pi*(gio-3)/6), 31+17*sin(pi*(gio-3)/6),31+13*cos(pi*(gio-2.7)/6), 31+13*sin(pi*(gio-2.7)/6),1);   
//! glcd_bar(31, 31,  31+23*cos(pi*(phut-15)/30), 31+23*sin(pi*(phut-15)/30),2 ,1);
//! glcd_line(31, 31, 31+30*cos(pi*(giay-15)/30), 31+30*sin(pi*(giay-15)/30),1);
