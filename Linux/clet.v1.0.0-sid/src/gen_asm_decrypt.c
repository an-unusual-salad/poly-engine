#include <stdio.h>
#include <stdlib.h>
#include "../hdr/types.h"

int gen_asm_decrypt(int, 
		    int, 
		    p_inst p[],
		    int,
		    unsigned char **,
		    unsigned char,
		    int key);

int gen_asm_decrypt(int reg_flag,
		    int work_reg,
		    p_inst p[],
		    int n,
                    unsigned char **asm_decrypt,
		    unsigned char max_size_decrypt,
		    int key) 
{
    int i=0 ;
    int size=0 ;
    unsigned char *ptr;
    unsigned char *temp;


    //Generate local key.
    key = ((key & 0x0000000F)>>0);


    if (max_size_decrypt<3*n) // no heap overflow
    {
      fprintf(stderr,"erreur max_size");
      exit(1);
    }

    ptr=(unsigned char *)malloc(max_size_decrypt*sizeof(char)); 
        
    for(i=0; i<n; i++)
    {
      switch(work_reg)
	{
	  case REG_EAX :
	  {	
	    switch (p[i].instruct) 
	    {
	      case XOR:
	      {
		ptr[size] = '\x35' ;
		temp=(char *)(&(p[i].arg));
		ptr[size+1] = temp[0];
		ptr[size+2] = temp[1];
		ptr[size+3] = temp[2];
		ptr[size+4] = temp[3];             
		size=size+5;
		break;
	      }

	      case ADD:
	      {
		ptr[size] = '\x05' ;
		temp=(char *)(&(p[i].arg));
		ptr[size+1] = temp[0];
		ptr[size+2] = temp[1];
		ptr[size+3] = temp[2];
		ptr[size+4] = temp[3];             
		size=size+5;
		break;
	      }

	      case SUB:
	      {
		ptr[size] = '\x2D' ;
	    	temp=(char *)(&(p[i].arg));
		ptr[size+1] = temp[0];
		ptr[size+2] = temp[1];
		ptr[size+3] = temp[2];
		ptr[size+4] = temp[3];             
		size=size+5;
		break;
	      }

	      case ROL:
	      {
		ptr[size] = '\xC1' ;
		ptr[size+1]= (unsigned char)( 0xC0 + (unsigned int)work_reg);
		temp=(char *)(&(p[i].arg));
		ptr[size+2] = temp[0];
		size=size+3;
		break;
	      }

	      case ROR:
	      {
		ptr[size] = '\xC1' ;
		ptr[size+1]= (unsigned char)( 0xC8 + (unsigned int)work_reg);
	   	temp=(char *)(&(p[i].arg));
		ptr[size+2] = temp[0];
		size=size+3;
		break;
	      }
	    }
	    break;
	  }
	  
	default:
	{
	  switch (p[i].instruct) 
	  {
	    case XOR:
	    {
	      ptr[size] = '\x81' ;
	      ptr[size+1]=(unsigned char)( 0xF0 + (unsigned int)work_reg);
	      temp=(char *)(&(p[i].arg));
	      ptr[size+2] = temp[0];
	      ptr[size+3] = temp[1];
	      ptr[size+4] = temp[2];
	      ptr[size+5] = temp[3];             
	      size=size+6;
	      break;
	    }

	    case ADD:
	    {
	      ptr[size] = '\x81' ;
	      ptr[size+1]= (unsigned char)( 0xC0 + (unsigned int)work_reg);
	      temp=(char *)(&(p[i].arg));
	      ptr[size+2] = temp[0];
	      ptr[size+3] = temp[1];
	      ptr[size+4] = temp[2];
	      ptr[size+5] = temp[3];             
	      size=size+6;
	      break;
	    }

	    case SUB:
	    {
	      ptr[size] = '\x81' ;
	      ptr[size+1]= (unsigned char)( 0xE8 + (unsigned int)work_reg);
	      temp=(char *)(&(p[i].arg));
	      ptr[size+2] = temp[0];
	      ptr[size+3] = temp[1];
	      ptr[size+4] = temp[2];
	      ptr[size+5] = temp[3];             
	      size=size+6;
	      break;
	    }

	    case ROL:
	    {
	      ptr[size] = '\xC1' ;
	      ptr[size+1]= (unsigned char)( 0xC0 + (unsigned int)work_reg);
	      temp=(char *)(&(p[i].arg));
	      ptr[size+2] = temp[0];
	      size=size+3;
	      break;
	    }

	    case ROR:
	    {
	      ptr[size] = '\xC1' ;
	      ptr[size+1]= (unsigned char)( 0xC8 + (unsigned int)work_reg);
	      temp=(char *)(&(p[i].arg));
	      ptr[size+2] = temp[0];
	      size=size+3;
	      break;
	    }
	  }
	}   
      }
    }
      
    *asm_decrypt=ptr;
    return(size);
}

