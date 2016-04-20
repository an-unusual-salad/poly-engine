#include <stdio.h>
#include <stdlib.h>
#include <string.h>


unsigned int * analyse(unsigned char *);

unsigned int * analyse(unsigned char * buffer)
{
    unsigned int i=0;
    unsigned int *gnarf = (unsigned int *) malloc(256*sizeof(unsigned int));
    
    /* Initialisation .*/
    for(i=0;i<256;i++)
    {
        gnarf[i]=0;
    }

    
    for(i=0;i<strlen(buffer);i++)
    {
        gnarf[buffer[i]]++;
    }
   
    return gnarf; 
}
