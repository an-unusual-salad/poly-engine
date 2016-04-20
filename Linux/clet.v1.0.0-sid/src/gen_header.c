#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../hdr/types.h"

int gen_header(int ,
	       int ,
	       int ,
	       int,
	       p_inst *,
	       int ,
	       unsigned char **,
	       unsigned char ,
	       unsigned char ,
	       unsigned char ,
	       unsigned char,
	       unsigned char,
	       unsigned char,
               unsigned char); 

int gen_header(int reg_flag ,
	       int work_reg ,
	       int left_reg ,
	       int addr_reg ,
	       p_inst p[] ,
	       int n ,
	       unsigned char **asm_header ,
	       unsigned char max_size_decrypt ,
	       unsigned char max_size_init ,
	       unsigned char shellcode_size ,
	       unsigned char max_size_dec ,
	       unsigned char max_size_end,
	       unsigned char max_size_rm,
	       unsigned char max_size_mr)
{
  int size_init, size_dec, size_end, size_reg_to_mem,size_jmp,size_mem_to_reg, size_decrypt;
  unsigned char *asm_init;
  unsigned char *asm_dec;
  unsigned char *asm_end;
  unsigned char *asm_rm;
  unsigned char *asm_mr;
  unsigned char *asm_jmp;
  unsigned char *asm_decrypt;

  //Determine which version must be generate.
  int key = my_random(0,MAX_INT); 
  /* 
     - key = 4*8 bits = 32 bits ;
     -> 4 bits par fonction :
     Dans l'ordre des poids les plus faibles au poids les plus importants:
     - gen_asm_decrypt 0
     - gen_asm_init 4
     - gen_asm_dec 8 
     - gen_asm_rm 12
     - gen_asm_mr 16
     - gen_asm_end 20
     - gen_asm_jmp 24
     - pas utilisé pour l'instant.

     code pour obtenir la clef propre à chaque fonction :
     key = ((key & 0x0000000F)>>0); pour gen_asm_decrypt

  */
  


  size_decrypt = gen_asm_decrypt(reg_flag, work_reg, p, n,
				  &asm_decrypt, max_size_decrypt,key);
  
  size_init = gen_asm_init(reg_flag, work_reg, left_reg, addr_reg,&asm_init,
			   max_size_init, shellcode_size,key);
  
  size_dec = gen_asm_dec(reg_flag, work_reg, left_reg, addr_reg,&asm_dec,
			 max_size_dec, shellcode_size,key);

  size_reg_to_mem = gen_asm_rm(reg_flag, work_reg, left_reg, addr_reg,&asm_rm,
  			 max_size_rm, shellcode_size,key);


  size_mem_to_reg = gen_asm_mr(reg_flag, work_reg, left_reg, addr_reg,&asm_mr,
			 max_size_mr, shellcode_size,key);


  size_end = gen_asm_end(reg_flag, work_reg, left_reg, addr_reg,&asm_end,
			 7, shellcode_size,
			 size_reg_to_mem,
			 size_decrypt,
			 size_mem_to_reg,
			 size_init,
			 size_dec,
			 key);


  // 7 utilisé dans gen_asm_dec

  size_jmp = gen_asm_jmp(&asm_jmp,
			 size_reg_to_mem,
			 size_decrypt,
			 size_dec,
			 size_mem_to_reg,
			 size_init,
			 key);
  
  
  *asm_header= (unsigned char *)malloc((size_jmp+size_dec
				      +size_init+size_reg_to_mem
				      +size_decrypt+size_mem_to_reg
				      +size_end)*sizeof(char));

  strncpy(*asm_header,asm_jmp,size_jmp);
  strncpy(*asm_header+size_jmp,asm_init,size_init);
  strncpy(*asm_header+size_jmp+size_init,asm_mr,size_mem_to_reg);
  strncpy(*asm_header+size_jmp+size_init+size_mem_to_reg,asm_decrypt,
	  size_decrypt);
  strncpy(*asm_header+size_jmp+size_init+size_mem_to_reg+size_decrypt,
	  asm_rm,size_reg_to_mem);
  strncpy(*asm_header+size_jmp+size_init+size_mem_to_reg+size_decrypt
	  +size_reg_to_mem,asm_dec,size_dec);
  strncpy(*asm_header+size_jmp+size_init+size_mem_to_reg+size_decrypt
	  +size_reg_to_mem+size_dec,asm_end,size_end);
  return size_jmp+size_dec + size_init+size_reg_to_mem
    +size_decrypt+size_mem_to_reg
    +size_end;
}
