/*
 *  Convert a CLET dump into an Mathematica exploitable file.
 *  Yann Malcom <yannmalcom@altern.org>
 */

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    FILE *file;
    unsigned int c;
    
    if(argc!=2)
    {
            printf("Analysis by Yann Malcom <yannmalcom@altern.org> \n"
                   " Usage : %s file \n "
                   " Use ReadList into Mathematica to load data.",argv[0]);
            exit(1);
    }

    if((file=fopen(argv[1],"r")))
    {
            while((c = getc(file))!=EOF)
            {
                    printf("%u\n",c);
            };
        
            printf("\n");
            fclose(file);
            exit(0);
    }
    else
    {
      exit(1);
    }

        
};

