#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ch2int(char);
unsigned char * gen_add(unsigned char*,int,unsigned char*);
unsigned char* ch2add(unsigned char*);

unsigned char* gen_add(unsigned char *add, int number, unsigned char *code)
{
  int i;
  int add_length=strlen(add);

  code=(unsigned char *)malloc(number*sizeof(unsigned char)*add_length);
  for (i=0;i<number;i++)
  {
    strncpy((code+(i*add_length)),add,add_length);
  }

  return(code);
}

unsigned char* ch2add(unsigned char *add)
{
  int i;
  unsigned char *code;
  unsigned char c;

  code=(unsigned char*)malloc((strlen(add)/2)*sizeof(unsigned char));

  for (i=0;i<((strlen(add))/2);i++)
  {
    c=(unsigned char)(((ch2int(add[2*i]))*16)+ch2int(add[(2*i)+1]));
    code[i]=c;
  }

  return(code);

}

int ch2int(char a)
{
  switch (a)
  {
  case '0':
    return(0);
  case '1':
    return(1);
  case '2':
    return(2);
  case '3':
    return(3);
  case '4':
    return(4);
  case '5':
    return(5);
  case '6':
    return(6);
  case '7':
    return(7);
  case '8':
    return(8);
  case '9':
    return(9);
  case 'a':
    return(10);
  case 'b':
    return(11);
  case 'c':
    return(12);
  case 'd':
    return(13);
  case 'e':
    return(14);
  case 'f':
    return(15);
  case 'A':
    return(10);
  case 'B':
    return(11);
  case 'C':
    return(12);
  case 'D':
    return(13);
  case 'E':
    return(14);
  case 'F':
    return(15);
  }
  return 0;
}
