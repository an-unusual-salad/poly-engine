#include <stdio.h> 
#include <stdlib.h>
#include "../hdr/gen_decrypt.h"
#include "../hdr/types.h"

void gen_decrypt(int, p_inst p[]);
p_inst gen_p_inst(void); 

void gen_decrypt(int n, p_inst p[])  // number of pseudo_instructions >1
{                                      
  int i;
  int XOR_p;                // position of XOR
      
  unsigned int yoda;
	
  XOR_p = (int)my_random(0,n-1);
  p[XOR_p].instruct='\x00';   // this a XOR
  yoda = my_random(0,MAX_INT);
  /* if yoda contains 0x00 then replace it by 0x01 */
  if(!(yoda & 0xFF000000)) yoda |= 0x01000000;
  if(!(yoda & 0x00FF0000)) yoda |= 0x00010000;
  if(!(yoda & 0x0000FF00)) yoda |= 0x00000100;
  if(!(yoda & 0x000000FF)) yoda |= 0x00000001;
  //  printf("--- %u ---\n",yoda);
  p[XOR_p].arg=yoda;
  
  for (i=0;i<XOR_p;i++)
    {
      p[i]=gen_p_inst();
    }
  
  for (i=XOR_p+1;i<n;i++)
    {
      p[i]=gen_p_inst();
    }
  
}

p_inst gen_p_inst(void) 
{
  p_inst p;
  int inst;
  unsigned int yoda;
  
  inst=(int)my_random(1,MAX_KINDOF_INST);
  
  switch(inst)
    {
    case 1: 
      {
	p.instruct='\x01';      // it's an add 
	yoda = my_random(0,MAX_INT);
	/* if yoda contains 0x00 then replace it by 0x01 */
	if(!(yoda & 0xFF000000)) yoda |= 0x01000000;
	if(!(yoda & 0x00FF0000)) yoda |= 0x00010000;
	if(!(yoda & 0x0000FF00)) yoda |= 0x00000100;
	if(!(yoda & 0x000000FF)) yoda |= 0x00000001;
	//      printf("--- %u ---\n",yoda);
	p.arg=yoda;
      break;
      }
      
    case 2: 
      {
      p.instruct='\x02';      // it's a sub 
      yoda = my_random(0,MAX_INT);
      /* if yoda contains 0x00 then replace it by 0x01 */
      if(!(yoda & 0xFF000000)) yoda |= 0x01000000;
      if(!(yoda & 0x00FF0000)) yoda |= 0x00010000;
      if(!(yoda & 0x0000FF00)) yoda |= 0x00000100;
      if(!(yoda & 0x000000FF)) yoda |= 0x00000001;
      //       printf("--- %u ---\n",yoda);
      p.arg=yoda;
      break;
      }
      
    case 3:
      {
	p.instruct='\x03';      // it's a ror 
	yoda = my_random(1,32);
	//      printf("--- %u ---\n",yoda);
	p.arg=yoda;
	break;
      }
      
    case 4:
      {
	p.instruct='\x04';      // it's a rol 
	yoda = my_random(1,32);
	//      printf("--- %u ---\n",yoda);
	p.arg=yoda;
	break;
      }
      
    default: 
      {
	printf("Instrution not available\n");
	exit(1);
      }
      
    }
  
  return(p);
}    
	 
