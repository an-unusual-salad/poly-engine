#include <stdio.h>
#include <stdlib.h>
#include "../hdr/types.h"


int gen_asm_jmp(unsigned char ** ,
		unsigned int,
		unsigned int,
		unsigned int,
		unsigned int,
		unsigned int,
		int key);

int gen_asm_jmp(unsigned char **asm_jmp,
		unsigned int size_reg_to_mem,
		unsigned int size_decrypt,
		unsigned int size_dec,
		unsigned int size_mem_to_reg,
		unsigned int size_init,
		int key)
{
  char *ptr;
  int size=0;
  
  
  //Generate local key.
  key = ((key & 0x0F000000)>>24);


  ptr = (char *)malloc(2); 
  
  ptr[size] = '\xEB';
  ptr[size + 1] = (unsigned char) (2 
				   + size_reg_to_mem 
				   + size_decrypt
				   + size_dec 
				   + size_mem_to_reg
				   + size_init );
  size+=2;

  (*asm_jmp)=ptr;

  return size;

}
