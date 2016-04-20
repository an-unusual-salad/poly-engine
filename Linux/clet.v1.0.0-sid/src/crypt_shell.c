#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../hdr/types.h"

//extern unsigned char execute (unsigned char, p_inst); 

int crypt_shell (unsigned char shellcode[], int n, p_inst p[]);

void decrypt_shell (unsigned char shellcode[], int n, p_inst p[]);
unsigned int crypt_uint (unsigned int c,int n, p_inst p[]);
unsigned int decrypt_uint (unsigned int c,int n, p_inst p[]);
int is_there_zero (unsigned char shellcode[], int n, p_inst p[]);

int crypt_shell (unsigned char shellcode[], int n, p_inst p[])
{
  int i=0;
 //  int temp=0;
  int length;
  intchar j;
  
  length = strlen(shellcode);
  while(i<length)
    {
      strncpy(j.vchar, (char*) shellcode+i,4);
      
//      printf("Version non codée : ");
//      for(temp=0;temp<4;temp++)
//	{
//	  printf("\\x%.2X",j.vchar[temp]);
//	}
//      printf("\n");
      
      j.vint=crypt_uint(j.vint,n,p);

//      printf("Version  codée : ");
//      for(temp=0;temp<4;temp++)
//	{
//	  printf("\\x%.2X",j.vchar[temp]);
//	}
//      printf("\n");
      
      strncpy((char *)shellcode+i,j.vchar,4);
      i+=4;
    }
//  printf("i : %u\n",i);
  shellcode[i]='\x0';


  return 0;
}

void decrypt_shell (unsigned char shellcode[], int n, p_inst p[])
{
  int i=0;
  int length;
//  int temp=0;
  //unsigned int j=0;
  intchar j;

  length = strlen(shellcode);
  fprintf(stderr,"longueur : %u\n",length);
  while(i<length)
    {
      strncpy(j.vchar, (char*) shellcode+i,4);

//      printf("Version codée : ");
//     for(temp=0;temp<4;temp++)
//	{
//	  printf("\\x%.2X",j.vchar[temp]);
//	}
//      printf("\n");
      
      j.vint=decrypt_uint(j.vint,n,p);

//      printf("Version non codée : ");
//      for(temp=0;temp<4;temp++)
//	{
//	  printf("\\x%.2X",j.vchar[temp]);
//	}
//      printf("\n");

      strncpy((char *)shellcode+i,j.vchar,4);
      i+=4;
    }
  shellcode[i+4]='\x0';

}
		   

unsigned int crypt_uint (unsigned int c,int n, p_inst p[])
{
  int i;
  unsigned int a;
  p_inst f;

  a=c;
  for (i=n-1;i>=0;i--)
  {
    f.arg=p[i].arg;

    switch(p[i].instruct)
    {
      case '\x00': 
      {
	f.instruct='\x00';
	break;
      }

      case '\x01': 
      {
	f.instruct='\x02';
	break;
      }

      case '\x02': 
      {
	f.instruct='\x01';
	break;
      }

      case '\x03': 
      {
	f.instruct='\x04';
	break;
      }
	  
      case '\x04': 
      {
	f.instruct='\x03';
	break;
      }

      default:
      {
        fprintf(stderr,"instruction not available in crypt_char\n");
        exit(1);
      }

    }
    
    a=execute(a,f);
  }
  
  return(a);

}


unsigned int decrypt_uint (unsigned int c,int n, p_inst p[])
{
  int i;
  unsigned int a;
  a=c;

  for (i=0;i<n;i++)
  {
    a=execute(a,p[i]);
  }

  return(a);
}



int is_there_zero (unsigned char shellcode[], int n, p_inst p[])
{
  int i=0;
  intchar j;

  while (shellcode[i]!='\0')
  {
//    j=((unsigned int)shellcode[i])<<24;
//    j=(((unsigned int)shellcode[i+1])<<16) + j;
//    j=(((unsigned int)shellcode[i+2])<<8) + j;
//    j=((unsigned int)shellcode[i+3]) + j;
    
      strncpy(j.vchar, (char*) shellcode+i,4);
          
    j.vint=crypt_uint(j.vint,n,p);
    if(j.vchar[0]==0) return 1;
    if(j.vchar[1]==0) return 1;
    if(j.vchar[2]==0) return 1;
    if(j.vchar[3]==0) return 1;
    
//    if(!(unsigned char)((j>>16)&(0x000000FF))) return 1;
//    if(!(unsigned char)(j>>24)) return 1;
//    if(!(unsigned char)((j>>8)&(0x000000FF))) return 1;
//    if(!(unsigned char)(j&(0x000000FF))) return 1;

    i+=4;
  }

  return 0;
}

/*
 *
 *int is_there_zero (unsigned char shellcode[], int n, p_inst p[])
 *{
 * int i;
 * unsigned char zero;
 *
 * i=0;
 * zero=crypt_char('\0',n,p);
 * 
 * while ((shellcode[i]!='\0')&&(shellcode[i]!=zero))
 * {
 *   i++;
 * }
 *
 * if (shellcode[i]=='\0') return(0);
 *   else return(1);
 *
 *}
 */

