from pwn import *
import sys

file = open('clet_bdf_reverse_tcp','r')

shellcode = ""
for line in file:
	shellcode += line[:-1]

print shellcode

shellcode_hex = shellcode.replace("x","")
shellcode_hex = shellcode_hex.replace("\\","")
shellcode_hex = shellcode_hex.lower()

print shellcode_hex

print disasm(shellcode.decode('hex'))