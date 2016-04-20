   #include "ADMmutapi.h"

int main()
{
   struct morphctl *mctlp;
   struct morphctl mut;
   mut.upper = 0; mut.lower = 0; mut.banned = 0; mctlp = &mut;
   mut.arch = IA32;
   ...
   init_mutate(mctlp);
   apply_key(buff, strlen(shellcode), nops-1, mctlp);
   apply_jnops(buff, nops-1, mut);
   apply_engine(buff, strlen(shellcode), nops-1, mut);
   return 0;
}