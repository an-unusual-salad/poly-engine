#define PUSHES      0x06    // %%   Push ES
#define POPES       0x07    // %%   Pop ES
#define PUSHCS      0x0E    // %%   Push CS
#define PUSHSS      0x16    // %%   Push SS
#define POPSS       0x17    // %%%  Pop SS
#define PUSHDS      0x1E    // %%   Push DS
#define POPDS       0x1F    // %    Pop DS
#define DAA         0x27    // %    Decimal Adjust for Addition
#define DAS         0x2F    // %    Decimal Adjust for Subtraction
#define AAA         0x37    // %    Ascii Adjust for Addition
#define AAS         0x3F    // %    Ascii Adjust for Subtraction
#define PUSHAD      0x60    // %%   Push All Registers onto Stack
#define POPAD       0x61    // %    Pop All Registers onto Stack
#define NOP         0x90    // %    No Operation
#define CWDE        0x98    // %    Convert Word to Extended Doubleword
#define CDQ         0x99    // %    Convert Double to Quad
#define PUSHFD      0x9C    // %%   Push Flags onto Stack
#define POPFD       0x9D    // %    Pop Flags off Stack
#define SAHF        0x9E    // %    Store AH Register into FLAGS
#define LAHF        0x9F    // %    Load Register AH From Flags
#define MOVSB       0xA4    // %%%  Move String (Byte)
#define MOVSD       0xA5    // %%%  Move String (Double)
#define CMPSB       0xA6    // %    Compare String (Byte)
#define CMPSW       0xA7    // %    Compare String (Word)
#define STOSB       0xAA    // %%%  Store String (Byte)
#define STOSD       0xAB    // %%%  Store String (Double)
#define SCASB       0xAE    // %    Scan String (Byte)
#define SCASD       0xAF    // %    Scan String (Double)
#define INALDX      0xEC    // %%   Input byte from I/O port in DX into AL
#define INEAXDX     0xED    // %%   Input doubleword from I/O port in DX 
                            //      into EAX
#define OUTDXAL     0xEE    // %%   Output byte in AL to I/O port address 
                            //      in DX
#define OUTDXEAX    0xEF    // %%   Output doubleword in EAX to I/O port 
                            //      address in DX
#define CMC         0xF5    // %    Complement Carry Flag
#define CLC         0xF8    // %    Clear Carry
#define STC         0xF9    // %    Set Carry
#define CLI         0xFA    // %%   Clear Interrupt Flag
#define STI         0xFB    // %    Set Interrupt Flag
#define CLD         0xFC    // %    Clear Direction Flag
#define STD         0xFD    // %%   Set Direction Flag
