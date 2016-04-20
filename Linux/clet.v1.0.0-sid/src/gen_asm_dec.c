#include <stdio.h>
#include <stdlib.h>
#include "../hdr/types.h"
int gen_asm_dec(int reg_flag ,
		int work_reg ,
		int left_reg ,
		int addr_reg ,
		unsigned char **asm_dec ,
		unsigned char max_size_dec ,
		unsigned int shellcode_size,
		int key)
{
  char *ptr;
  int i,size=0;
  
  //Generate local key.
  key = ((key & 0x00000F00)>>8);

  ptr = (char *)malloc(max_size_dec); 

  
  fprintf(stderr,"Gen_asm_dec key : %u \n",key);

  if(addr_reg == REG_EAX)
    {
      if((key%4)!=0)
	{
	  ptr[size++] = '\x2D'; //SUB EAX,-key%4 	  
	  ptr[size++] = -key%4;
	  ptr[size++] = '\xFF';
	  ptr[size++] = '\xFF';
	  ptr[size++] = '\xFF';
	}
      for(i=0;i<(4-key%4);i++)
	{
	  ptr[size++] = (unsigned char)( 0x40 + (unsigned int)(addr_reg));
	}
    }
  else
    {
      if((key%4)!=0)
	{
	  ptr[size++] = '\x81'; //SUB reg,-key%4
	  ptr[size++] = (unsigned char)( 0xE8 + (unsigned char )addr_reg);
	  ptr[size++] = -key%4;
	  ptr[size++] = '\xFF';
	  ptr[size++] = '\xFF';
	  ptr[size++] = '\xFF';
	}
      for(i=0;i<(4-key%4);i++)
	{
	  ptr[size++] = (unsigned char)( 0x40 + (unsigned int)(addr_reg));
	}
    }
     
  
  

  if(left_reg == REG_EAX)
    {
      if((((key>>1))%4)!=0)
	{
	  ptr[size++] = '\x2C'; //SUB EAX,4
	  ptr[size++] = (key>>1)%4;
	}
       for(i=0;i<(4-((key>>1))%4);i++)
	{
	  ptr[size++] = (unsigned char)( 0x48 + (unsigned int)(left_reg));
	}
    }
  else
    {
      if(((key>>1)%4)!=0)
	{
	  ptr[size++] = '\x80'; //SUB reg,4
	  ptr[size++] = (unsigned char)(0xE8 + (unsigned char )left_reg);
	  ptr[size++] = (key>>1)%4;
	}
      for(i=0;i<(4-(key>>1)%4);i++)
	{
	  ptr[size++] = (unsigned char)( 0x48 + (unsigned int)(left_reg));
	}
    }  

  //JZ
  ptr[size++] = '\x74'; 
  ptr[size++] = 5 + 2; //sizeof(CALL rel32)+sizeof(JMP rel8)

  
  
  (* asm_dec) = ptr;
  return size;
}
