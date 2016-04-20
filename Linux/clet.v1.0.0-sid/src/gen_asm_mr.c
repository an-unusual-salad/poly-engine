#include <stdio.h>
#include <stdlib.h>
#include "../hdr/types.h"

int gen_asm_mr(int ,
	       int ,
	       int ,
	       int, 
	       unsigned char ** ,
	       unsigned char ,
	       unsigned int,
	       int);

int gen_asm_mr(int reg_flag ,
	       int work_reg ,
	       int left_reg ,
	       int addr_reg ,
	       unsigned char **asm_mr ,
	       unsigned char max_size_mr ,
	       unsigned int shellcode_size,
	       int key)
{
  char *ptr;
  int size=0;


  //Generate local key.
  key = ((key & 0x000F0000)>>16);
  
  ptr = (char *)malloc(max_size_mr); 



  //mov mem vers reg.  
  ptr[size] = '\x8B';
  ptr[size + 1] = (unsigned char)( 8*(unsigned int)work_reg + (unsigned int)addr_reg );

  size+=2;



  *asm_mr = ptr;
  return size;
}
