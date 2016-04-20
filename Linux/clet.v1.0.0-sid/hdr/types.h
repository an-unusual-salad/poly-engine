#define XOR '\x00' 
#define ADD '\x01' 
#define SUB '\x02' 
#define ROR '\x03' 
#define ROL '\x04' 

#define REG_EDI 7 
#define REG_ESI 6 
#define REG_EBP 5 
#define REG_ESP 4 
#define REG_EBX 3 
#define REG_EDX 2 
#define REG_ECX 1 
#define REG_EAX 0 

#define MAX_INT 4294967296 - 1

typedef struct 
{
  unsigned char instruct;
  unsigned int arg;
} p_inst ;                  // struct for pseudo instruction

typedef union 
{
  unsigned int vint;
  unsigned char vchar[5];
} intchar;
