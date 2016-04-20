#include <stdio.h>
#include <stdlib.h>
#include "../hdr/types.h"

int gen_asm_end(int ,
		int ,
		int ,
		int,
		unsigned char ** ,
		unsigned char ,
		unsigned int,
		unsigned int,
		unsigned int,
		unsigned int,
		unsigned int,
		unsigned int,
		int);

int gen_asm_end(int reg_flag ,
		int work_reg ,
		int left_reg ,
		int addr_reg ,
		unsigned char **asm_end ,
		unsigned char max_size_end ,
		unsigned int shellcode_size,
		unsigned int size_reg_to_mem,
		unsigned int size_decrypt,
		unsigned int size_mem_to_reg,
		unsigned int size_init,
		unsigned int size_dec,
		int key)
{
  char *ptr;
  int size=0;


  //Generate local key.
  key = ((key & 0x00F00000)>>20);


  ptr = (char *)malloc(max_size_end);
  
  ptr[size] = '\xEB'; // JUMP 
  ptr[size + 1] = -(2 +
		    size_reg_to_mem 
		    + size_decrypt+ size_dec
		    + size_mem_to_reg);
  size+=2;

  ptr[size] = '\xE8'; // Call jusqu'au début.
  ptr[size + 1] = -( size + 5 
		     + size_reg_to_mem 
		     + size_dec
		     + size_decrypt 
		     + size_mem_to_reg 
		     + size_init);
  ptr[size + 2] = '\xFF';
  ptr[size + 3] = '\xFF';
  ptr[size + 4] = '\xFF';
  size+=5;  
  (*asm_end)=ptr;
  
  return size;

}
