WALL=  
CFLAGS= $(WALL) 

all: main convert analysis

main:  execute.o crypt_shell.o random.o main.o gen_decrypt.o gen_asm_decrypt.o gen_asm_init.o gen_asm_jmp.o gen_asm_mr.o gen_asm_rm.o gen_asm_dec.o gen_asm_end.o gen_header.o gen_nop.o analyse.o gen_cramming.o gen_add.o

	gcc  $(CFLAGS) execute.o crypt_shell.o random.o main.o gen_decrypt.o gen_asm_decrypt.o gen_asm_init.o gen_asm_jmp.o gen_asm_mr.o gen_asm_rm.o gen_asm_dec.o gen_asm_end.o gen_header.o gen_nop.o analyse.o gen_cramming.o gen_add.o -o clet 

debug: execute.o crypt_shell.o random.o main.o gen_decrypt.o gen_asm_decrypt.o gen_asm_init.o gen_asm_jmp.o gen_asm_mr.o gen_asm_rm.o gen_asm_dec.o gen_asm_end.o  gen_header.o gen_nop.o analyse.o gen_cramming.o gen_add.o

	gcc $(CFLAGS) execute.o crypt_shell.o random.o main.o gen_decrypt.o gen_asm_decrypt.o gen_asm_init.o gen_asm_jmp.o gen_asm_mr.o gen_asm_rm.o gen_asm_dec.o gen_asm_end.o gen_header.o gen_nop.o analyse.o gen_cramming.o gen_add.o -o clet_debug

analysis: ./Analysis/analysis.c
	gcc $(CFLAGS) ./Analysis/analysis.c -o ./Analysis/analysis


convert: ./Convert/convert.c
	gcc $(CFLAGS) ./Convert/convert.c -o ./Convert/convert

main.o: main.c ../hdr/types.h
	gcc $(CFLAGS) -c main.c

execute.o: execute.c ../hdr/types.h
	gcc $(CFLAGS) -c execute.c

random.o: random.c 
	gcc $(CFLAGS) -c random.c 

gen_decrypt.o: gen_decrypt.c ../hdr/types.h
	gcc $(CFLAGS) -c gen_decrypt.c

crypt_shell.o: crypt_shell.c ../hdr/types.h
	gcc $(CFLAGS) -c crypt_shell.c 

gen_asm_decrypt.o: gen_asm_decrypt.c ../hdr/types.h
	gcc $(CFLAGS) -c gen_asm_decrypt.c

gen_asm_init.o: gen_asm_init.c ../hdr/types.h
	gcc $(CFLAGS) -c gen_asm_init.c

gen_asm_jmp.o: gen_asm_jmp.c ../hdr/types.h
	gcc $(CFLAGS) -c gen_asm_jmp.c

gen_asm_mr.o: gen_asm_mr.c ../hdr/types.h
	gcc $(CFLAGS) -c gen_asm_mr.c 

gen_asm_rm.o: gen_asm_rm.c ../hdr/types.h
	gcc $(CFLAGS) -c gen_asm_rm.c

gen_asm_dec.o: gen_asm_dec.c ../hdr/types.h
	gcc $(CFLAGS) -c gen_asm_dec.c

gen_asm_end.o: gen_asm_end.c ../hdr/types.h
	gcc $(CFLAGS) -c gen_asm_end.c

gen_header.o: gen_header.c ../hdr/types.h
	gcc $(CFLAGS) -c gen_header.c

gen_nop.o: gen_nop.c ../hdr/types.h 
	gcc $(CFLAGS) -c gen_nop.c

analyse.o: analyse.c 
	gcc $(CFLAGS) -c analyse.c

gen_cramming.o: gen_cramming.c
	gcc $(CFLAGS) -c gen_cramming.c

gen_add.o: gen_add.c
	gcc $(CFLAGS) -c gen_add.c

clean: 
	rm -f *~; rm -f *.o; rm -f clet;rm -f clet_debug; 
	rm -f ./Convert/convert ; rm -f ./Convert/*~
	rm -f ./Analysis/analysis ; rm -f ./Analysis/*~ 
