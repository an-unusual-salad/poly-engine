#include <stdio.h>
#include <stdlib.h>
#include "../hdr/types.h"

unsigned int execute (unsigned int c, p_inst p);


/* Apply the p.inst to an unsigned int */
unsigned int execute (unsigned int c, p_inst p)
{

  switch(p.instruct)
  {

    case '\x00':
    {
      c^=p.arg;
      break;
    }

    case '\x01':               // it's an add
    {
      c=(unsigned int)( ((unsigned int)c + (unsigned int)(p.arg)) );
      break;
    }

    case '\x02':               // it's a sub
    {
      c=(unsigned int)( ((unsigned int)c - (unsigned int)(p.arg)) );
      break;
    }

    case '\x03':               // it's a ror
    {
      c = (c << (32 - (int)p.arg)) | (c >> ((int)p.arg));
      break;
    }

    case '\x04':               // it's a rol
    {
      c = (c >> (32 - (int)p.arg)) | (c << ((int)p.arg));
      break;
    }

    default:
    {
      printf("instruction not available in execute\n");
      exit(1);
    }
  }
  
  return(c);
}
