#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../hdr/gen_nop.h"

extern unsigned char ame_arg;

char* gen_nop(unsigned int );

char* gen_nop(unsigned int Nnop)
{
  char *temp,c;
  int i=0;
  int t=0,t2=0;
  FILE *dic;
  
  if(Nnop!=0)
    {
      temp = (char *) malloc((Nnop+1)*sizeof(char));

      if(!ame_arg)
      {
      while(i<Nnop)
      {
	    temp[i++]=NOP_char[my_random(0,strlen(NOP_char))];
      }
      }
      else 
      {
        if(!(dic = fopen("../hdr/american-english","r")))
        {
                printf("\033[0;31mCannot Open american-english dictionnary."
                       "\033[0m\n");
                exit(1);
        }
        while(i<Nnop)
        {
          t=my_random(0,45392);
          t2=0;
          while(t2<t)
          {
            if(getc(dic)=='\n')
            {
             t2++;
            }
          }
          while(((c=getc(dic))!='\n')&(i<Nnop))
          {
            temp[i++]=c;
          }
          //caractère de séparation à trouver.
          /*if(i<Nnop)
          {
                  temp[i++]=0x2d;
          }
          */
          fseek(dic,0,SEEK_SET);
        }
        fclose(dic);
      }
      return temp;
    }
  else
    return NULL;
}
