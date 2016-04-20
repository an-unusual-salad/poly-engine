#include <stdio.h>
#include <stdlib.h>
#include "../hdr/types.h"

int gen_asm_init(int,
		 int,
		 int,
		 int,
		 unsigned char **,
		 unsigned char,
		 unsigned int,
		 int);

int gen_asm_init(int reg_flag,
		 int work_reg, 
		 int left_reg,
		 int addr_reg,
		 unsigned char **asm_init,
		 unsigned char max_size_init,
		 unsigned int shellcode_size,
		 int key)
{
  char *ptr;
  int size=0;

  //Generate local key.
  key = ((key & 0x000000F0)>>4);


  ptr = (char *)malloc(max_size_init); 
  
  //POP addr_reg
  ptr[size++] = (unsigned char)(0x58 + (unsigned int)addr_reg);
  

  //size of shellcode
  ptr[size] = '\x31';                                 
  ptr[size + 1] = (unsigned char)(0xC0 + 9*(unsigned int)left_reg);//xor     
  
  ptr[size + 2] = (unsigned char)(0xB0 + (unsigned int)left_reg);//movb
  if(shellcode_size<=255)
    ptr[size + 3] = (unsigned char)shellcode_size; 
  else
    {
      printf("Shellcode too long\n");
      exit(1);
    }
  
  size+=4;
  

  

  (*asm_init) = ptr;
  return size;
}
