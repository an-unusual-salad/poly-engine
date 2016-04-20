#include <stdio.h>

int main(int argc, char *argv[])
{
  int tab[256];
  FILE *fichin;
  FILE *fichout;
  int c;
  int i;
  int comp=0;
  int sum;

  for (i=0;i<256;i++)
    tab[i]=0;

  fichin=fopen(argv[1],"r");

  while ((c=fgetc(fichin))!=EOF)
  {
    comp++;  
    tab[c]++;
  }

  fclose(fichin);
  sum=0;
  fichout=fopen(argv[2],"w");
  for (i=0;i<256;i++)
    fprintf(fichout,"%x %d\n",i,tab[i]);
  fclose(fichout);
}
