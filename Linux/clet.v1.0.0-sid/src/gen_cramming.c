#include <stdio.h>
#include <stdlib.h>

extern unsigned int my_random (unsigned int min, unsigned int max);

unsigned int **generate_cramming_tab(char *fich);
void generate_cramming_code(unsigned int **tab,int size,
			    unsigned char *code);
unsigned char recherche_dicho(int key, unsigned int **tab);

void modify_cramtab(unsigned int **tab,
		    unsigned char *header, int size_h,
		    unsigned char *nopzone, int size_n,
		    unsigned char *shell, int size_s,
		    int b);

unsigned int **generate_cramming_tab(char *fich)
{
  FILE *f;
  unsigned int **tab;
  int i;
  int index=0;
  int nb=0;
  unsigned int c;
  unsigned int value=0;
  unsigned int sum=0;

  f=fopen(fich,"r");
  fscanf(f,"%x %d",&c,&value);
  for (i=0;i<255;i++)
  {
    fscanf(f,"%x %d",&c,&value);
    if (value!=0)
      nb++;
  }
  fclose(f);

  tab=(unsigned int **)malloc((nb+1)*sizeof(unsigned int *));

  tab[0]=(unsigned int*)malloc(sizeof(unsigned int));
  tab[0][0]=nb; //keep the size

  for (i=1;i<nb+1;i++)
    tab[i]=(unsigned int *)malloc(2*sizeof(unsigned int));

  index=1;

  f=fopen(fich,"r");
  fscanf(f,"%x %d",&c,&value);
  for (i=0;i<255;i++)
  {
    fscanf(f,"%x %d",&c,&value);  
    if (value!=0)
    {
      tab[index][1]=c;
      tab[index][0]=value+sum;
      index++;
      sum=sum+value;
    }
  }

  fclose(f);
  return(tab);
}

void generate_cramming_code(unsigned int **tab,int size,unsigned char *code)
{
  int nb,i;
  int sum;
  int randm;
  unsigned char c;

  nb=tab[0][0];
  sum=tab[nb][0];
  for (i=0;i<size;i++)
  {
    randm=my_random(1,sum);
    c=recherche_dicho(randm,tab);
    code[i]=c;
  }
}  

//search method in log

unsigned char recherche_dicho(int key, unsigned int **tab)
{
  int i,j,m;
  unsigned char c;
  i=1;
  j=tab[0][0];
 
  while ((j-i)>1)
  {
    m=(i+j)/2;
    if (tab[m][0]<=key)
      i=m;
    else
      j=m;
  }
  if (key==tab[i][0])
    c=(unsigned char)(tab[i][1]);
  else
    c=(unsigned char)(tab[j][1]);
  return(c);
}


void modify_cramtab(unsigned int **tab,
		    unsigned char *header, int size_h,
		    unsigned char *nopzone, int size_n,
		    unsigned char *shell, int size_s,
		    int b)
{
  int nb = tab[0][0];
  int Ntot = tab[nb][0];

  unsigned char c;
  int i,j;
  int q=0;
  int dc;
  unsigned int temp;
  unsigned int ecart;

  temp=0;
  for (i=1;i<nb+1;i++)
  {
    c=(unsigned char)(tab[i][1]);
    q=0;
    for (j=0;j<size_h;j++)
    {
      if (header[j]==c)
	q++;
    }

    for (j=0;j<size_n;j++)
    {
      if (nopzone[j]==c)
	q++;
    }

    for (j=0;j<size_s;j++)
    {
      if (shell[j]==c)
	q++;
    }

    dc=(q*Ntot)/b;

    if (tab[i][0]>temp+dc)
    {
      for (j=i;j<nb+1;j++)
      {	
	tab[j][0]=tab[j][0]-dc;
      }
      temp=tab[i][0];
    }
    else
    {
      ecart=tab[i][0]-temp;
      for (j=i;j<nb;j++)
      {
    	tab[j][0]=tab[j+1][0]-ecart;
    	tab[j][1]=tab[j+1][1];
      }
      nb=nb-1;
      i=i-1;
    }
  }

  tab[0][0]=nb;
  
}
