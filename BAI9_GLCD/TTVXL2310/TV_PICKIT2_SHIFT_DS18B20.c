#define TOUCH_PIN   pin_c4
#include"touch.c"
unsigned int8 _____romcode[3][8];
unsigned char docromDS18B20()
{
   BYTE
      i, soic=0,                           
      last_desc_pos = 0,              
      desc_marker = 0,                 
      contents[8] = {0,0,0,0,0,0,0,0};          
   int1
      bitA,                            
      bitB,                            
      last_desc = 0;                   
   BOOLEAN
      firstrom = TRUE,
      done = FALSE;
   do
   {
      last_desc_pos = desc_marker;
      reset_pulse();
      touch_write_byte(0xF0);
      for(i = 0; i < 64; i++)
      {
         bitA = touch_read_bit(); 
         bitB = touch_read_bit(); 
         if((!bitA) && (!bitB))
         {
            desc_marker = i;
            if(i == last_desc_pos)
               last_desc = !last_desc;
            shift_right(contents, 8, last_desc);
            touch_write_bit(last_desc);
         }
         else
         {
            shift_right(contents, 8, bitA);
            touch_write_bit(bitA);
         }
      }
      if(firstrom)
      {
         for(i = 0; i < 8; i++)
               _____romcode[0][i] =contents[i];
         firstrom = FALSE; soic++;
      }
      else
      {
         for(i = 0; i < 8; i++)_____romcode[soic][i] =contents[i];
         soic++;
         done = TRUE;
         for(i = 0; i < 8; i++)
            if(_____romcode[0][i] != contents[i])
               done = FALSE;
      }
   } while(!done);
   return soic-1;
}

void match_rom(BYTE romdata[])
{
   BYTE  i;
   touch_write_byte(0x55);
   for(i = 0; i < 8; i++)
      touch_write_byte(romdata[i]);
}
unsigned int16 docDS18B20(unsigned int8 n)
{
    unsigned int8 ndh,ndl;
    if(touch_present())
    {
       match_rom(_____romcode[n]);
       touch_write_byte(0x44);
    }
    if(touch_present())
    {
       match_rom(_____romcode[n]);
       touch_write_byte(0xBE);
       ndl= touch_read_byte();
       ndh= touch_read_byte();
       return make16(ndh,ndl);  
    }
    return 0xffff;
}



