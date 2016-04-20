#include <stdio.h>
#include <stdlib.h>
#include "../hdr/types.h"

int gen_asm_rm(int ,
	       int ,
	       int ,
	       int, 
	       unsigned char ** ,
	       unsigned char ,
	       unsigned int,
	       int);

int gen_asm_rm(int reg_flag ,
	       int work_reg ,
	       int left_reg ,
	       int addr_reg ,
	       unsigned char **asm_rm ,
	       unsigned char max_size_rm ,
	       unsigned int shellcode_size,
	       int key)
{
  char *ptr;
  int size=0;
  

  //Generate local key.
  key = ((key & 0x0000F000)>>12);


  ptr = (char *)malloc(max_size_rm); 
  
 
  //mov reg vers mem.  
  ptr[size] = '\x89';
  ptr[size + 1] = (unsigned char)( 8*(unsigned int)work_reg + (unsigned int)addr_reg );

  size+=2;

 
  *asm_rm = ptr;
  
  return size;
}
