/**
* @file libasm/src/arch/mips/handlers/asm_mips_abs_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_abs_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_ABS_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_abs_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_abs_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_ABS_PS;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_abs_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_abs_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_ABS_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_add.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_add(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_ADD;
   ins->type = ASM_TYPE_ARITH /* | ASM_TYPE_ */;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Integer overflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_add_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_add_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_ADD_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].regset = ASM_MIPS_REG_FPU;
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow, Underflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_addi.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_addi(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_ADDI;
   ins->type = ASM_TYPE_ARITH /* |  ASM_TYPE_ */;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exception: Integer Overflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_addiu.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_addiu(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_ADDIU;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

  /* Exceptione: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_add_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_add_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_ADD_PS;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].regset = ASM_MIPS_REG_FPU;
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow, Underflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_add_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_add_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_ADD_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].regset = ASM_MIPS_REG_FPU;
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow, Underflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_addu.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_addu(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_ADDU;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_alnv_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_alnv_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop1x temp;

   ins->instr = ASM_MIPS_ALNV_PS;
   ins->type = ASM_TYPE_ARCH;
   mips_convert_format_cop1x(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.f1;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].regset = ASM_MIPS_REG_FPU;
   ins->op[2].baser = temp.in;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[3].baser = temp.bs;
   asm_mips_operand_fetch(&ins->op[3], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_and.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_and(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_AND;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_andi.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_andi(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_ANDI;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exception: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_bal.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_bal(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_BAL;
   ins->type =  /* ASM_TYPE_BRANCH */ ASM_TYPE_CALLPROC;
   mips_convert_format_i(&temp, buf);
   ins->op[0].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_BRANCH, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_b.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_b(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_B;
   ins->type = ASM_TYPE_BRANCH;
   mips_convert_format_i(&temp, buf);
   ins->op[0].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_BRANCH, ins); 

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_bc1f.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_bc1f(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_BC1F;
   ins->type =  ASM_TYPE_ARCH | ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
   mips_convert_format_i(&temp, buf);
   ins->op[0].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_BRANCH, ins);

   /* Exceptions: Coprocessor Unusable, Reserved instruction */
   /* FPU Exceptions: Unimplemented Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_bc1fl.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_bc1fl(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_BC1FL;
   ins->type =  ASM_TYPE_ARCH | ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
   mips_convert_format_i(&temp, buf);
   ins->op[0].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_BRANCH, ins);

   /* Exceptions: Coprocessor Unusable, Reserved instruction */
   /* FPU Exceptions: Unimplemented Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_bc1t.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_bc1t(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_BC1T;
   ins->type =  ASM_TYPE_ARCH | ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
   mips_convert_format_i(&temp, buf);
   ins->op[0].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_BRANCH, ins);

   /* Exceptions: Coprocessor Unusable, Reserved instruction */
   /* FPU Exceptions: Unimplemented Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_bc1tl.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_bc1tl(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_BC1TL;
   ins->type =  ASM_TYPE_ARCH | ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
   mips_convert_format_i(&temp, buf);
   ins->op[0].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_BRANCH, ins);

   /* Exceptions: Coprocessor Unusable, Reserved instruction */
   /* FPU Exceptions: Unimplemented Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_bc2f.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_bc2f(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_BC2F;
   ins->type =  ASM_TYPE_ARCH | ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
   mips_convert_format_i(&temp, buf);
   ins->op[0].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_BRANCH, ins);

   /* Exceptions: Coprocessor Unusable, Reserved instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_bc2fl.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_bc2fl(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_BC2FL;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
   mips_convert_format_i(&temp, buf);
   ins->op[0].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_BRANCH, ins);

   /* Exceptions: Coprocessor Unusable, Reserved instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_bc2t.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_bc2t(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_BC2T;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
   mips_convert_format_i(&temp, buf);
   ins->op[0].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_BRANCH, ins);

   /* Exceptions: Coprocessor Unusable, Reserved instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_bc2tl.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_bc2tl(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_BC2TL;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
   mips_convert_format_i(&temp, buf);
   ins->op[0].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_BRANCH, ins);

   /* Exceptions: Coprocessor Unusable, Reserved instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_beq.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_beq(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;
   u_int converted = 0;

   memcpy((char *)&converted,buf,sizeof(converted));

   switch ((converted >> 16) & 0x3FF) {

      case ASM_MIPS_OTYPE_NONE:
         asm_mips_b(ins,buf,len,proc);
         break;
      default:
         ins->instr = ASM_MIPS_BEQ;
         ins->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
         mips_convert_format_i(&temp, buf);
         ins->op[0].baser = temp.rs;
	 asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
         ins->op[1].baser = temp.rt;
         asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
         ins->op[2].imm = temp.im;
         asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_BRANCH, ins);
         break;
   }

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_beql.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_beql(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_BEQL;
   ins->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_BRANCH, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_bgezal.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_bgezal(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_BGEZAL;
   ins->type = ASM_TYPE_CONDCONTROL | ASM_TYPE_CALLPROC;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_BRANCH, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_bgezall.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_bgezall(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_BGEZALL;
   ins->type = ASM_TYPE_CONDCONTROL | ASM_TYPE_CALLPROC;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_BRANCH, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_bgez.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_bgez(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_BGEZ;
   ins->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_BRANCH, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_bgezl.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_bgezl(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_BGEZL;
   ins->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_BRANCH, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_bgtz.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_bgtz(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_BGTZ;
   ins->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_BRANCH, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_bgtzl.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_bgtzl(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_BGTZL;
   ins->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_BRANCH, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_blez.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_blez(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_BLEZ;
   ins->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_BRANCH, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_blezl.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_blezl(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_BLEZL;
   ins->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_BRANCH, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_bltzal.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_bltzal(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_BLTZAL;
   ins->type = ASM_TYPE_CONDCONTROL | ASM_TYPE_CALLPROC;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_BRANCH, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_bltzall.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_bltzall(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_BLTZALL;
   ins->type = ASM_TYPE_CONDCONTROL | ASM_TYPE_CALLPROC;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_BRANCH, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_bltz.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_bltz(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_BLTZ;
   ins->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_BRANCH, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_bltzl.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_bltzl(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_BLTZL;
   ins->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_BRANCH, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_bne.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_bne(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_BNE;
   ins->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_BRANCH, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_bnel.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_bnel(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_BNEL;
   ins->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_BRANCH, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_break.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_break(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_BREAK;
   ins->type = ASM_TYPE_STOP /* ?????? */;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_NOOP /* ASM_MIPS_OTYPE_TRAP */, ins);

   /* Exceptions: Breakpoint */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_ceil_l_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_ceil_l_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_CEIL_L_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_ceil_l_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_ceil_l_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_CEIL_L_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_ceil_w_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_ceil_w_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_CEIL_W_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_ceil_w_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_ceil_w_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_CEIL_W_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_eq_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_eq_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_EQ_D;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_eq_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_eq_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_EQ_PS;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_eq_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_eq_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_EQ_S;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_cfc1.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_cfc1(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_CFC1;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_cfc2.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_cfc2(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_CFC2;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_f_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_f_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_F_D;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_f_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_f_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_F_PS;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_f_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_f_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_F_S;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_le_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_le_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_LE_D;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_le_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_le_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_LE_PS;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_le_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_le_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_LE_S;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_clo.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* CLO rd,rs */

int asm_mips_clo(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_CLO;
   ins->type = ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_lt_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_lt_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_LT_D;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_lt_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_lt_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_LT_PS;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_lt_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_lt_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_LT_S;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_clz.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* CLZ rd,rs */

int asm_mips_clz(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_CLZ;
   ins->type = ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_nge_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_nge_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_NGE_D;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_nge_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_nge_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_NGE_PS;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_nge_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_nge_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_NGE_S;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_ngl_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_ngl_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_NGL_D;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_ngle_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_ngle_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_NGLE_D;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_ngle_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_ngle_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_NGLE_PS;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_ngle_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_ngle_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_NGLE_S;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_ngl_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_ngl_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_NGL_PS;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_ngl_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_ngl_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_NGL_S;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_ngt_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_ngt_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_NGT_D;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_ngt_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_ngt_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_NGT_PS;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_ngt_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_ngt_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_NGT_S;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_ole_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_ole_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_OLE_D;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_ole_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_ole_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_OLE_PS;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_ole_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_ole_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_OLE_S;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_olt_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_olt_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_OLT_D;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_olt_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_olt_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_OLT_PS;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_olt_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_olt_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_OLT_S;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_cop2.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_cop2(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_COP2;
   ins->type = ASM_TYPE_ARCH;

   /* Exceptions: Coprocessor Unusable, Reserved instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_seq_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_seq_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_SEQ_D;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_seq_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_seq_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_SEQ_PS;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_seq_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_seq_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_SEQ_S;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_sf_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_sf_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_SF_D;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_sf_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_sf_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_SF_PS;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_sf_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_sf_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_SF_S;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_ctc1.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_ctc1(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_CTC1;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation, Division-by-zero, Inexact, Overflow, Underflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_ctc2.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_ctc2(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_CTC2;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation, Division-by-zero, Inexact, Overflow, Underflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_ueq_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_ueq_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_UEQ_D;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_ueq_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_ueq_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_UEQ_PS;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_ueq_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_ueq_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_UEQ_S;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_ule_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_ule_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_ULE_D;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_ule_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_ule_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_ULE_PS;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_ule_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_ule_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_ULE_S;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_ult_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_ult_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_ULT_D;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_ult_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_ult_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_ULT_PS;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_ult_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_ult_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_ULT_S;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_un_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_un_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_UN_D;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_un_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_un_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_UN_PS;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_c_un_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_c_un_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_C_UN_S;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_cvt_d_l.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_cvt_d_l(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_CVT_D_L;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_cvt_d_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_cvt_d_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_CVT_D_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_cvt_d_w.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_cvt_d_w(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_CVT_D_W;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_cvt_l_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_cvt_l_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_CVT_L_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_cvt_l_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_cvt_l_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_CVT_L_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_cvt_ps_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_cvt_ps_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_CVT_PS_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].regset = ASM_MIPS_REG_FPU;
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_cvt_s_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_cvt_s_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_CVT_S_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow, Underflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_cvt_s_l.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_cvt_s_l(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_CVT_S_L;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow, Underflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_cvt_s_pl.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_cvt_s_pl(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_CVT_S_PL;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow, Underflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_cvt_s_pu.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_cvt_s_pu(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_CVT_S_PU;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow, Underflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_cvt_s_w.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_cvt_s_w(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_CVT_S_W;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow, Underflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_cvt_w_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_cvt_w_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_CVT_W_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_cvt_w_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_cvt_w_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_CVT_W_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_dadd.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* DADD rd,rs,rt */

int asm_mips_dadd(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_DADD;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Integer overflow, Reserved instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_daddi.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_daddi(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_DADDI;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: Integer overflow, Reserved instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_daddiu.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_daddiu(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_DADDIU;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_daddu.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_daddu(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp; 

   ins->instr = ASM_MIPS_DADDU;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_dclo.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* DCLO rd,rs */

int asm_mips_dclo(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_DCLO;
   ins->type = ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_dclz.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* DCLZ rd,rs */

int asm_mips_dclz(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_DCLZ;
   ins->type = ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_ddiv.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_ddiv(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_trap temp;

   ins->instr = ASM_MIPS_DDIV;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_t(&temp,buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_ddivu.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_ddivu(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_trap temp;

   ins->instr = ASM_MIPS_DDIVU;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_t(&temp,buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_deret.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* DERET */

int asm_mips_deret(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_DERET;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_RETPROC;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_NOOP, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_div.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_div(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_trap temp;

   ins->instr = ASM_MIPS_DIV;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_t(&temp,buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_div_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_div_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_DIV_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].regset = ASM_MIPS_REG_FPU;
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation, Division-by-zero, Overflow, Underflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_div_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_div_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_DIV_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].regset = ASM_MIPS_REG_FPU;
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation, Division-by-zero, Overflow, Underflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_divu.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_divu(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_trap temp;

   ins->instr = ASM_MIPS_DIVU;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_t(&temp,buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_dmfc0.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* DMFC0 rt,rd,sl */

int asm_mips_dmfc0(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_priv temp;

   ins->instr = ASM_MIPS_DMFC0;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_priv(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.sl;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_dmfc1.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_dmfc1(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_DMFC1;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_dmfc2.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_dmfc2(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_DMFC2;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.sl;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_dmtc0.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* DMTC0 rt,rd,sl */

int asm_mips_dmtc0(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_priv temp;

   ins->instr = ASM_MIPS_DMTC0;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_priv(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.sl;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_dmtc1.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_dmtc1(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_DMTC1;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_dmtc2.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_dmtc2(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_DMTC2;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.sl;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_dmult.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_dmult(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_trap temp;

   ins->instr = ASM_MIPS_DMULT;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_t(&temp,buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_dmultu.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_dmultu(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_trap temp;

   ins->instr = ASM_MIPS_DMULTU;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_t(&temp,buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_dsll32.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_dsll32(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_DSLL32;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.sa;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_dsll.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_dsll(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_DSLL;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.sa;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_dsllv.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* DSLLV rd,rt,rs */

int asm_mips_dsllv(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_DSLLV;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_dsra32.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_dsra32(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_DSRA32;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.sa;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_dsra.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_dsra(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_DSRA;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.sa;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_dsrav.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* DSRAV rd,rt,rs */

int asm_mips_dsrav(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_DSRAV;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_dsrl32.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_dsrl32(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_DSRL32;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.sa;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_dsrl.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_dsrl(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_DSRL;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.sa;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_dsrlv.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* DSRLV rd,rt,rs */

int asm_mips_dsrlv(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_DSRLV;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_dsub.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_dsub(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_DSUB;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Integer Overflow, Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_dsubu.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_dsubu(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_DSUBU;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_ehb.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include "libasm.h"

int asm_mips_ehb(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_BAD;
   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_eret.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* ERET */

int asm_mips_eret(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_ERET;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_RETPROC;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_NOOP, ins);

   /* Exceptions: Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_ext.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include "libasm.h"

int asm_mips_ext(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_EXT;
   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_floor_l_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_floor_l_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_FLOOR_L_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_floor_l_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_floor_l_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_FLOOR_L_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_floor_w_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_floor_w_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_FLOOR_W_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_floor_w_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_floor_w_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_FLOOR_W_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_ins.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include "libasm.h"

int asm_mips_ins(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_INS;
   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_jal.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_jal(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_jump temp;

   ins->instr = ASM_MIPS_JAL;
   ins->type = ASM_TYPE_CALLPROC;
   mips_convert_format_j(&temp,buf);
   ins->op[0].imm = temp.ta;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_JUMP, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_jalr.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_jalr(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_JALR;
   ins->type = ASM_TYPE_CALLPROC;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_jalr.hb.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_jalr_hb(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
//   ins->instr = ASM_MIPS_JALR;
//   asm_mips_operand_r(&ins->op[0], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   asm_mips_jalr(ins, buf, len, proc);

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_j.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_j(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_jump temp;

   ins->instr = ASM_MIPS_J;
   ins->type = ASM_TYPE_BRANCH;
   mips_convert_format_j(&temp,buf);
   ins->op[0].imm = temp.ta;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_JUMP, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_jr.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_jr(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_JR;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   if (temp.rs == ASM_MIPS_REG_RA)
      ins->type = ASM_TYPE_RETPROC;
   else
      ins->type = ASM_TYPE_BRANCH;

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_jr.hb.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_jr_hb(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
//   ins->instr = ASM_MIPS_JR;
//   asm_mips_operand_r(&ins->op[0], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   asm_mips_jr(ins, buf, len, proc);

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_lb.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_lb(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_LB;
   ins->type = ASM_TYPE_LOAD;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: TLB Refill, TLB Invalid, Address Error */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_lbu.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_lbu(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_LBU;
   ins->type = ASM_TYPE_LOAD;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: TLB Refill, TLB Invalid, Address Error */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_ld.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_ld(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_LD;
   ins->type = ASM_TYPE_LOAD;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: TLB Refill, TLB Invalid, Bus Error, Address Error, Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_ldc1.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_ldc1(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_LDC1;
   ins->type = ASM_TYPE_LOAD | ASM_TYPE_ARCH;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction, TLB Refill, TLB Invalid, Address Error */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_ldc2.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_ldc2(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_LDC2;
   ins->type = ASM_TYPE_LOAD | ASM_TYPE_ARCH;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction, TLB Refill, TLB Invalid, Address Error */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_ldl.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_ldl(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_LDL;
   ins->type = ASM_TYPE_LOAD | ASM_TYPE_ARCH;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: TLB Refill, TLB Invalid, Bus Error, Address Error, Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_ldr.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_ldr(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_LDR;
   ins->type = ASM_TYPE_LOAD | ASM_TYPE_ARCH;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: TLB Refill, TLB Invalid, Bus Error, Address Error, Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_ldxc1.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_ldxc1(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop1x temp;

   ins->instr = ASM_MIPS_LDXC1;
   ins->type = ASM_TYPE_LOAD | ASM_TYPE_ARCH;
   mips_convert_format_cop1x(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.in;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.bs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exception: TLB Refill, TLB Invalid, Address Error, Reserved Instruction, Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_lh.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_lh(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_LH;
   ins->type = ASM_TYPE_LOAD;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: TLB Refill, TLB Invalid, Bus Error, Address Error */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_lhu.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_lhu(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_LHU;
   ins->type = ASM_TYPE_LOAD;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: TLB Refill, TLB Invalid, Address Error */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_ll.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_ll(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_LL;
   ins->type = ASM_TYPE_LOAD;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: TLB Refill, TLB Invalid, Address Error, Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_lld.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_lld(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_LLD;
   ins->type = ASM_TYPE_LOAD;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: TLB Refill, TLB Invalid, Address Error, Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_lui.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_lui(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_LUI;
   ins->type = ASM_TYPE_LOAD;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_luxc1.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_luxc1(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop1x temp;

   ins->instr = ASM_MIPS_LUXC1;
   ins->type = ASM_TYPE_LOAD | ASM_TYPE_ARCH;
   mips_convert_format_cop1x(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.in;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.bs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exception: TLB Refill, TLB Invalid, TLB Modified, Reserved Instruction, Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_lw.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_lw(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_LW;
   ins->type = ASM_TYPE_LOAD;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: TLB Refill, TLB Invalid, Bus Error, Address Error */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_lwc1.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_lwc1(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_LWC1;
   ins->type = ASM_TYPE_LOAD | ASM_TYPE_ARCH;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: TLB Refill, TLB Invalid, Address Error, Reserved Instruction, Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_lwc2.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_lwc2(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_LWC2;
   ins->type = ASM_TYPE_LOAD | ASM_TYPE_ARCH;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: TLB Refill, TLB Invalid, Address Error, Reserved Instruction, Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_lwl.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_lwl(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_LWL;
   ins->type = ASM_TYPE_LOAD;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: None / TLB Refill, TLB Invalid, Bus Error, Address Error */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_lwr.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_lwr(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_LWR;
   ins->type = ASM_TYPE_LOAD | ASM_TYPE_ARCH;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: TLB Refill, TLB Invalid, Bus Error, Address Error */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_lwu.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_lwu(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_LWU;
   ins->type = ASM_TYPE_LOAD | ASM_TYPE_ARCH;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: TLB Refill, TLB Invalid, Address Error, Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_lwxc1.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_lwxc1(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop1x temp;

   ins->instr = ASM_MIPS_LWXC1;
   ins->type = ASM_TYPE_LOAD | ASM_TYPE_ARCH;
   mips_convert_format_cop1x(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.in;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.bs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exception: TLB Refill, TLB Invalid, Address Error, Reserved Instruction, Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_madd.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* MADD rs,rt */

int asm_mips_madd(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_MADD;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_madd_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_madd_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop1x temp;

   ins->instr = ASM_MIPS_MADD_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_cop1x(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.bs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].regset = ASM_MIPS_REG_FPU;
   ins->op[2].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[3].regset = ASM_MIPS_REG_FPU;
   ins->op[3].baser = temp.in;
   asm_mips_operand_fetch(&ins->op[3], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_madd_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_madd_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop1x temp;

   ins->instr = ASM_MIPS_MADD_PS;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_cop1x(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.bs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].regset = ASM_MIPS_REG_FPU;
   ins->op[2].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[3].regset = ASM_MIPS_REG_FPU;
   ins->op[3].baser = temp.in;
   asm_mips_operand_fetch(&ins->op[3], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_madd_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_madd_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop1x temp;

   ins->instr = ASM_MIPS_MADD_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_cop1x(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.bs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].regset = ASM_MIPS_REG_FPU;
   ins->op[2].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[3].regset = ASM_MIPS_REG_FPU;
   ins->op[3].baser = temp.in;
   asm_mips_operand_fetch(&ins->op[3], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_maddu.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* MADDU rs,rt */

int asm_mips_maddu(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_MADDU;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_mfc0.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* MFC0 rt,rd */

int asm_mips_mfc0(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_priv temp;

   ins->instr = ASM_MIPS_MFC0;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_priv(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_mfc1.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* MFC1 rt,rd */

int asm_mips_mfc1(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_priv temp;

   ins->instr = ASM_MIPS_MFC1;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_priv(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_mfc2.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_mfc2(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_MFC2;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_cop2(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.sl;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: Coprocesor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_mfhi.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_mfhi(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_MFHI;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_mflo.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_mflo(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_MFLO;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_movcf_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_movcf_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;
   u_int converted = 0;
   
   memcpy((char *)&converted,buf,sizeof(converted));

   if ((converted >> 16) & 0x1)
      ins->instr = ASM_MIPS_MOVT_D;
   else
      ins->instr = ASM_MIPS_MOVF_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.rt >> 2;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);      

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Unimplemented Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_movcf_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_movcf_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;
   u_int converted = 0;
   
   memcpy((char *)&converted,buf,sizeof(converted));

   if ((converted >> 16) & 0x1)
      ins->instr = ASM_MIPS_MOVT_PS;
   else
      ins->instr = ASM_MIPS_MOVF_PS;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.rt >> 2;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Unimplemented Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_movcf_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_movcf_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;
   u_int converted = 0;
   
   memcpy((char *)&converted,buf,sizeof(converted));

   if ((converted >> 16) & 0x1)
      ins->instr = ASM_MIPS_MOVT_S;
   else
      ins->instr = ASM_MIPS_MOVF_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.rt >> 2;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Unimplemented Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_mov_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_mov_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_MOV_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Unimplemented Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_movf.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_movf(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_mov temp;

   ins->instr = ASM_MIPS_MOVF;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_mov(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.cc;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: Reserved Instruction, Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_movn.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include "libasm.h"

/* MOVN rd,rs,rt  */

int asm_mips_movn(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_MOVN;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_movn_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_movn_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_MOVN_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Unimplemented Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_movn_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_movn_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_MOVN_PS;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Unimplemented Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_movn_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_movn_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_MOVN_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Unimplemented Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_mov_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_mov_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_MOV_PS;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Unimplemented Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_mov_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_mov_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_MOV_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Unimplemented Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_movt.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_movt(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_mov temp;

   ins->instr = ASM_MIPS_MOVT;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_mov(&temp,buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.cc;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: Reserved Instruction, Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_movz.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* MOVZ rd,rs,rt */

int asm_mips_movz(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_MOVZ;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_movz_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_movz_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_MOVZ_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Unimplemented Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_movz_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_movz_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_MOVZ_PS;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Unimplemented Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_movz_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_movz_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_MOVZ_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Unimplemented Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_msub.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* MSUB rs,rt  */

int asm_mips_msub(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_MSUB;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_msub_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_msub_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop1x temp;

   ins->instr = ASM_MIPS_MSUB_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_cop1x(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.bs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].regset = ASM_MIPS_REG_FPU;
   ins->op[2].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[3].regset = ASM_MIPS_REG_FPU;
   ins->op[3].baser = temp.in;
   asm_mips_operand_fetch(&ins->op[3], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_msub_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_msub_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop1x temp;

   ins->instr = ASM_MIPS_MSUB_PS;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_cop1x(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.bs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].regset = ASM_MIPS_REG_FPU;
   ins->op[2].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[3].regset = ASM_MIPS_REG_FPU;
   ins->op[3].baser = temp.in;
   asm_mips_operand_fetch(&ins->op[3], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_msub_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_msub_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop1x temp;

   ins->instr = ASM_MIPS_MSUB_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_cop1x(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.bs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].regset = ASM_MIPS_REG_FPU;
   ins->op[2].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[3].regset = ASM_MIPS_REG_FPU;
   ins->op[3].baser = temp.in;
   asm_mips_operand_fetch(&ins->op[3], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_msubu.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* MSUBU rs,rt */

int asm_mips_msubu(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_MSUBU;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_mtc0.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* MTC0 rt,rd */

int asm_mips_mtc0(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_priv temp;

   ins->instr = ASM_MIPS_MTC0;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_priv(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_mtc1.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* MTC1 rt,rd */

int asm_mips_mtc1(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_priv temp;

   ins->instr = ASM_MIPS_MTC1;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_priv(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_mtc2.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_mtc2(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop2 temp;

   ins->instr = ASM_MIPS_MTC2;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_cop2(&temp,buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.sl;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_mthi.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_mthi(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_MTHI;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_mtlo.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_mtlo(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_MTLO;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_ASSIGN;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_mul.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* MUL rd,rs,rt */

int asm_mips_mul(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_MUL;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_mul_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_mul_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_MUL_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].regset = ASM_MIPS_REG_FPU;
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation, Overflow, Underflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_mul_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_mul_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_MUL_PS;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].regset = ASM_MIPS_REG_FPU;
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation, Overflow, Underflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_mul_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_mul_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_MUL_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].regset = ASM_MIPS_REG_FPU;
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation, Overflow, Underflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_mult.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* MULT rs,rt */

int asm_mips_mult(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_trap temp;

   ins->instr = ASM_MIPS_MULT;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_t(&temp,buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_multu.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* MULTU rs,rt */

int asm_mips_multu(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_trap temp;

   ins->instr = ASM_MIPS_MULTU;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_t(&temp,buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_neg_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_neg_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_NEG_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_neg_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_neg_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_NEG_PS;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_neg_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_neg_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_NEG_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_nmadd_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_nmadd_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop1x temp;

   ins->instr = ASM_MIPS_NMADD_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_cop1x(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.bs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].regset = ASM_MIPS_REG_FPU;
   ins->op[2].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[3].regset = ASM_MIPS_REG_FPU;
   ins->op[3].baser = temp.in;
   asm_mips_operand_fetch(&ins->op[3], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_nmadd_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_nmadd_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop1x temp;

   ins->instr = ASM_MIPS_NMADD_PS;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_cop1x(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.bs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].regset = ASM_MIPS_REG_FPU;
   ins->op[2].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[3].regset = ASM_MIPS_REG_FPU;
   ins->op[3].baser = temp.in;
   asm_mips_operand_fetch(&ins->op[3], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_nmadd_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_nmadd_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop1x temp;

   ins->instr = ASM_MIPS_NMADD_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_cop1x(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.bs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].regset = ASM_MIPS_REG_FPU;
   ins->op[2].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[3].regset = ASM_MIPS_REG_FPU;
   ins->op[3].baser = temp.in;
   asm_mips_operand_fetch(&ins->op[3], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_nmsub_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_nmsub_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop1x temp;

   ins->instr = ASM_MIPS_NMSUB_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_cop1x(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.bs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].regset = ASM_MIPS_REG_FPU;
   ins->op[2].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[3].regset = ASM_MIPS_REG_FPU;
   ins->op[3].baser = temp.in;
   asm_mips_operand_fetch(&ins->op[3], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_nmsub_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_nmsub_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop1x temp;

   ins->instr = ASM_MIPS_NMSUB_PS;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_cop1x(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.bs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].regset = ASM_MIPS_REG_FPU;
   ins->op[2].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[3].regset = ASM_MIPS_REG_FPU;
   ins->op[3].baser = temp.in;
   asm_mips_operand_fetch(&ins->op[3], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_nmsub_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_nmsub_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop1x temp;

   ins->instr = ASM_MIPS_NMSUB_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_cop1x(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.bs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].regset = ASM_MIPS_REG_FPU;
   ins->op[2].baser = temp.f2;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[3].regset = ASM_MIPS_REG_FPU;
   ins->op[3].baser = temp.in;
   asm_mips_operand_fetch(&ins->op[3], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_nop.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_nop(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_NOP;
   ins->type = ASM_TYPE_NOP;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_NOOP, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_nor.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* NOR rd,rs,rt */

int asm_mips_nor(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_NOR;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_or.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* OR rd,rs,rt */

int asm_mips_or(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_OR;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_ori.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_ori(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_ORI;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_pref.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_pref(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_PREF;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_LOAD;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: None :) */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_prefx.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_prefx(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop1x temp;

   ins->instr = ASM_MIPS_PREFX;
   ins->type = ASM_TYPE_ASSIGN | ASM_TYPE_ARCH;
   mips_convert_format_cop1x(&temp, buf);
   ins->op[0].baser = temp.f1;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.in;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.bs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exception: TLB Refill, TLB Invalid, Address Error, Reserved Instruction, Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_rdhwr.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_rdhwr(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_RDHWR;
   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_recip_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_recip_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_RECIP_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Division-by-zero, Overflow, Underflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_recip_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_recip_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_RECIP_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Division-by-zero, Overflow, Underflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_rotr.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_rotr(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_ROTR;
   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_rotrv.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_rotrv(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_ROTRV;
   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_round_l_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_round_l_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_ROUND_L_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_round_l_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_round_l_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_ROUND_L_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_round_w_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_round_w_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_ROUND_W_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_round_w_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_round_w_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_ROUND_W_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_rsqrt_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_rsqrt_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_RSQRT_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Division-by-zero, Overflow, Underflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_rsqrt_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_rsqrt_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_RSQRT_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Division-by-zero, Overflow, Underflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_sb.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_sb(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_SB;
   ins->type = ASM_TYPE_STORE;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: TLB Refill, TLB Invalid, TLB Modified, Bus Error, Address Error */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_sc.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_sc(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_SC;
   ins->type = ASM_TYPE_STORE;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: TLB Refill, TLB Invalid, TLB Modified, Address Error, Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_scd.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_scd(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_SCD;
   ins->type = ASM_TYPE_STORE;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: TLB Refill, TLB Invalid, TLB Modified, Address Error, Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_sdbbp.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* SDBBP code */

int asm_mips_sdbbp(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_jump temp;

   ins->instr = ASM_MIPS_SDBBP;
   ins->type = ASM_TYPE_ARCH;
   mips_convert_format_j(&temp,buf);
   ins->op[0].imm = (temp.ta >> 6) & 0xFFFFF;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_JUMP, ins);

   /* Exceptions: Debug Breakpoint Exception */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_sd.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_sd(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_SD;
   ins->type = ASM_TYPE_STORE;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: TLB Refill, TLB Invalid, TLB Modified, Address Error, Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_sdc1.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_sdc1(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_SDC1;
   ins->type = ASM_TYPE_STORE | ASM_TYPE_ARCH;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction, TLB Refill, TLB Invalid, TLB Modified, Address Error */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_sdc2.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_sdc2(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_SDC2;
   ins->type = ASM_TYPE_STORE | ASM_TYPE_ARCH;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction, TLB Refill, TLB Invalid, TLB Modified, Address Error */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_sdl.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_sdl(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_SDL;
   ins->type = ASM_TYPE_STORE;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: TLB Refill, TLB Invalid, TLB Modified, Bus Error, Address Error, Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_sdr.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_sdr(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_SDR;
   ins->type = ASM_TYPE_STORE;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: TLB Refill, TLB Invalid, TLB Modified, Bus Error, Address Error, Reserved Instruction */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_sdxc1.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_sdxc1(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop1x temp;

   ins->instr = ASM_MIPS_SDXC1;
   ins->type = ASM_TYPE_STORE | ASM_TYPE_ARCH;
   mips_convert_format_cop1x(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.f1;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.in;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.bs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exception: TLB Refill, TLB Invalid, TLB Modified, Address Error, Reserved Instruction, Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_seb.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_seb(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_SEB;
   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_seh.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_seh(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_SEH;
   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_sh.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_sh(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_SH;
   ins->type = ASM_TYPE_STORE;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: TLB Refill, TLB Invalid, TLB Modified, Address Error */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_sll.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_sll(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;
   u_int converted = 0;

   memcpy((char *)&converted,buf,sizeof(converted));

   switch ((converted >> 6) & 0xFFFFF) {

      case MIPS_OPCODE_NOP:
         asm_mips_nop(ins,buf,len,proc);
         break;
      case MIPS_OPCODE_SSNOP:
         asm_mips_ssnop(ins,buf,len,proc);
         break;
      default:
         ins->instr = ASM_MIPS_SLL;
         ins->type = ASM_TYPE_ARITH;
         mips_convert_format_r(&temp, buf);
         ins->op[0].baser = temp.rd;
         asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
         ins->op[1].baser = temp.rt;
         asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
         ins->op[2].imm = temp.sa;
         asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

         /* Exceptions: None */

         break;
   }
   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_sllv.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* SLLV rd,rt,rs */

int asm_mips_sllv(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_SLLV;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_slt.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* SLT rd,rs,rt */

int asm_mips_slt(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_SLT;
   ins->type = ASM_TYPE_COMPARISON;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_slti.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_slti(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_SLTI;
   ins->type = ASM_TYPE_COMPARISON;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_sltiu.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_sltiu(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_SLTIU;
   ins->type = ASM_TYPE_COMPARISON;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_sltu.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* SLTU rd,rs,rt */

int asm_mips_sltu(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_SLTU;
   ins->type = ASM_TYPE_COMPARISON;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_sqrt_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_sqrt_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_SQRT_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_sqrt_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_sqrt_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_SQRT_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_sra.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_sra(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_SRA;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.sa;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_srav.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* SRAV rd,rt,rs */

int asm_mips_srav(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_SRAV;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_srl.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_srl(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_SRL;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.sa;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_srlv.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* SRLV rd,rt,rs */

int asm_mips_srlv(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_SRLV;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_ssnop.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_ssnop(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_SSNOP;
   ins->type = ASM_TYPE_NOP;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_NOOP, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_sub.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* SUB rd,rs,rt */

int asm_mips_sub(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_SUB;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rt; 
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Integer Overflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_sub_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_sub_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_SUB_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].regset = ASM_MIPS_REG_FPU;
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow, Underflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_sub_ps.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_sub_ps(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_SUB_PS;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].regset = ASM_MIPS_REG_FPU;
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow, Underflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_sub_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_sub_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_SUB_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].regset = ASM_MIPS_REG_FPU;
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow, Underflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_subu.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* SUBU rd,rs,rt */

int asm_mips_subu(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_SUBU;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_suxc1.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_suxc1(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop1x temp;

   ins->instr = ASM_MIPS_SUXC1;
   ins->type = ASM_TYPE_STORE | ASM_TYPE_ARCH;
   mips_convert_format_cop1x(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.f1;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.in;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.bs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exception: TLB Refill, TLB Invalid, TLB Modified, Reserved Instruction, Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_sw.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_sw(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_SW;
   ins->type = ASM_TYPE_STORE;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: TLB Refill, TLB Invalid, TLB Modified, Address Error */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_swc1.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_swc1(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_SWC1;
   ins->type = ASM_TYPE_STORE | ASM_TYPE_ARCH;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction, TLB Refill, TLB Invalid, TLB Modified, Address Error */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_swc2.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_swc2(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_SWC2;
   ins->type = ASM_TYPE_STORE | ASM_TYPE_ARCH;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: Coprocessor Unusable, Reserved Instruction, TLB Refill, TLB Invalid, TLB Modified, Address Error */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_swl.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_swl(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_SWL;
   ins->type = ASM_TYPE_STORE;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: TLB Refill, TLB Invalid, TLB Modified, Bus Error, Address Error */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_swr.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_swr(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_SWR;
   ins->type = ASM_TYPE_STORE;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);
   ins->op[2].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exceptions: TLB Refill, TLB Invalid, TLB Modified, Bus Error, Address Error */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_swxc1.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_swxc1(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_cop1x temp;

   ins->instr = ASM_MIPS_SWXC1;
   ins->type = ASM_TYPE_STORE | ASM_TYPE_ARCH;
   mips_convert_format_cop1x(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.f1;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.in;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.bs;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGBASE, ins);

   /* Exception: TLB Refill, TLB Invalid, TLB Modified, Address Error, Reserved Instruction, Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_sync.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_sync(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_SYNC;
   ins->type = ASM_TYPE_LOAD | ASM_TYPE_STORE | ASM_TYPE_ARCH;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_NOOP, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_synci.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_synci(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_SYNCI;
   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_syscall.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_syscall(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_SYSCALL;
   ins->type = ASM_TYPE_ARCH;
   asm_mips_operand_fetch(&ins->op[0], buf,  ASM_MIPS_OTYPE_NOOP /* ASM_MIPS_OTYPE_TRAP */ , ins);

   /* Exceptions: System Call */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_teq.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* TEQ rs,rt */

int asm_mips_teq(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_trap temp;

   ins->instr = ASM_MIPS_TEQ;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_COMPARISON | ASM_TYPE_INT;
   mips_convert_format_t(&temp,buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Trap */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_teqi.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_teqi(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_TEQI;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_COMPARISON | ASM_TYPE_INT;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: Trap */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_tge.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* TGE rs,rt */

int asm_mips_tge(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_trap temp;

   ins->instr = ASM_MIPS_TGE;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_COMPARISON | ASM_TYPE_INT;
   mips_convert_format_t(&temp,buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Trap */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_tgei.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_tgei(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_TGEI;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_COMPARISON | ASM_TYPE_INT;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: Trap */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_tgeiu.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_tgeiu(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_TGEIU;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_COMPARISON | ASM_TYPE_INT;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: Trap */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_tgeu.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* TGEU rs,rt */

int asm_mips_tgeu(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_trap temp;

   ins->instr = ASM_MIPS_TGEU;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_COMPARISON | ASM_TYPE_INT;
   mips_convert_format_t(&temp,buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Trap */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_tlbp.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* TLBP */

int asm_mips_tlbp(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_TLBP;
   ins->type = ASM_TYPE_ARCH;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_NOOP, ins);

   /* Exceptions: Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_tlbr.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* TLBR */

int asm_mips_tlbr(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_TLBR;
   ins->type = ASM_TYPE_ARCH;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_NOOP, ins);

   /* Exceptions: Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_tlbwi.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* TLBWI */

int asm_mips_tlbwi(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_TLBWI;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_CONTROL;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_NOOP, ins);

   /* Exceptions: Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_tlbwr.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* TLBWR */

int asm_mips_tlbwr(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_TLBWR;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_CONTROL;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_NOOP, ins);

   /* Exceptions: Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_tlt.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* TLT rs,rt */

int asm_mips_tlt(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_trap temp;

   ins->instr = ASM_MIPS_TLT;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_COMPARISON | ASM_TYPE_INT;
   mips_convert_format_t(&temp,buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Trap */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_tlti.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_tlti(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_TLTI;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_COMPARISON | ASM_TYPE_INT;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: Trap */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_tltiu.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_tltiu(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_TLTIU;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_COMPARISON | ASM_TYPE_INT;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: Trap */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_tltu.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* TLTU rs,rt */

int asm_mips_tltu(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_trap temp;

   ins->instr = ASM_MIPS_TLTU;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_COMPARISON | ASM_TYPE_INT;
   mips_convert_format_t(&temp,buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Trap */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_tne.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* TNE rs,rt */

int asm_mips_tne(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_trap temp;

   ins->instr = ASM_MIPS_TNE;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_COMPARISON | ASM_TYPE_INT;
   mips_convert_format_t(&temp,buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: Trap */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_tnei.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_tnei(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp;

   ins->instr = ASM_MIPS_TNEI;
   ins->type = ASM_TYPE_ARCH | ASM_TYPE_COMPARISON | ASM_TYPE_INT;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: Trap */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_trunc_l_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_trunc_l_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_TRUNC_L_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_trunc_l_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_trunc_l_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_TRUNC_L_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_trunc_w_d.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_trunc_w_d(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_TRUNC_W_D;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_trunc_w_s.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_trunc_w_s(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_TRUNC_W_S;
   ins->type = ASM_TYPE_ARITH | ASM_TYPE_ARCH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].regset = ASM_MIPS_REG_FPU;
   ins->op[0].baser = temp.sa;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].regset = ASM_MIPS_REG_FPU;
   ins->op[1].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exception: Reserved Instruction, Coprocessor Unusable */
   /* FPU Exceptions: Inexact, Unimplemented Operation, Invalid Operation, Overflow */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_wait.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* WAIT */

int asm_mips_wait(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_WAIT;
   ins->type = ASM_TYPE_ARCH;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_NOOP, ins);

   /* Exceptions: Coprocessor Unusable */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_wsbh.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_wsbh(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   ins->instr = ASM_MIPS_WSBH;
   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_xor.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

/* XOR rd,rs,rt */

int asm_mips_xor(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_reg temp;

   ins->instr = ASM_MIPS_XOR;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_r(&temp, buf);
   ins->op[0].baser = temp.rd;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_REGISTER, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/handlers/asm_mips_xori.c
** @ingroup MIPS_instrs
*/
/* Adam 'pi3' Zabrocki */
/* Manuel Martin - 2007 */

#include <libasm.h>

int asm_mips_xori(asm_instr *ins, u_char *buf, u_int len,
                  asm_processor *proc)
{
   struct s_mips_decode_imm temp; 

   ins->instr = ASM_MIPS_XORI;
   ins->type = ASM_TYPE_ARITH;
   mips_convert_format_i(&temp, buf);
   ins->op[0].baser = temp.rt;
   asm_mips_operand_fetch(&ins->op[0], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[1].baser = temp.rs;
   asm_mips_operand_fetch(&ins->op[1], buf, ASM_MIPS_OTYPE_REGISTER, ins);
   ins->op[2].imm = temp.im;
   asm_mips_operand_fetch(&ins->op[2], buf, ASM_MIPS_OTYPE_IMMEDIATE, ins);

   /* Exceptions: None */

   return 4;
}
/**
* @file libasm/src/arch/mips/operand_handlers/asm_mips_operand_branch.c
** @ingroup MIPS_operands
*/
/*
 * - Adam 'pi3' Zabrocki
 *
 */

#include <libasm.h>

void    asm_mips_operand_branch(asm_operand *op, u_char *opcode, int otype,
                                          asm_instr *ins)
{
   op->type = ASM_MIPS_OTYPE_BRANCH;
//   memcpy(&op->scale,opcode,4);
}
/**
 * @defgroup MIPS_operands MIPS operands API.
 * @ingroup mips
 */
/**
* @file libasm/src/arch/mips/operand_handlers/asm_mips_operand_fetch.c
** @ingroup MIPS_operands
*/
/*
 * Started by Adam 'pi3' Zabrocki
 * $Id$
 */

#include <libasm.h>

int asm_mips_operand_fetch(asm_operand *op, u_char *opcode, int otype,
                                          asm_instr *ins)

{ 
  vector_t      *vec;
  u_int         dim[1];
  int           ret;
  int           (*func_op)(asm_operand *op, u_char *opcode, int otype, asm_instr *ins);
  
  vec = aspect_vector_get(LIBASM_VECTOR_OPERAND_MIPS);
  dim[0] = otype;
  
  func_op = aspect_vectors_select(vec, dim);
  if ( (ret = func_op(op, opcode, otype, ins)) == -1) {
    printf("%s:%i Unsupported operand content : %i\n", __FILE__, __LINE__, 
    	     otype);
  }

  return (ret);
}
/**
* @file libasm/src/arch/mips/operand_handlers/asm_mips_operand_i.c
** @ingroup MIPS_operands
*/
/*
 * - Adam 'pi3' Zabrocki
 *
 */

#include <libasm.h>

void	asm_mips_operand_i(asm_operand *op, u_char *opcode, int otype,
                                          asm_instr *ins)
{
   op->type = ASM_MIPS_OTYPE_IMMEDIATE;
//   memcpy(&op->scale,opcode,4);
}
/**
* @file libasm/src/arch/mips/operand_handlers/asm_mips_operand_j.c
** @ingroup MIPS_operands
*/
/*
 * - Adam 'pi3' Zabrocki
 *
 */

#include <libasm.h>

void    asm_mips_operand_j(asm_operand *op, u_char *opcode, int otype,
                                          asm_instr *ins)
{
   op->type = ASM_MIPS_OTYPE_JUMP;
//   memcpy(&op->scale,opcode,4);
}
/**
* @file libasm/src/arch/mips/operand_handlers/asm_mips_operand_none.c
** @ingroup MIPS_operands
*/
/*
 * - Adam 'pi3' Zabrocki
 *
 */

#include <libasm.h>

void    asm_mips_operand_none(asm_operand *op, u_char *opcode, int otype,
                                          asm_instr *ins)
{
   op->type = ASM_MIPS_OTYPE_NONE;
}
/**
* @file libasm/src/arch/mips/operand_handlers/asm_mips_operand_noop.c
** @ingroup MIPS_operands
*/
/*
 * - Adam 'pi3' Zabrocki
 *
 */

#include <libasm.h>

void    asm_mips_operand_noop(asm_operand *op, u_char *opcode, int otype,
                                          asm_instr *ins)
{
   op->type = ASM_MIPS_OTYPE_NOOP;
}
/**
* @file libasm/src/arch/mips/operand_handlers/asm_mips_operand_r.c
** @ingroup MIPS_operands
*/
/*
 * - Adam 'pi3' Zabrocki
 *
 */

#include <libasm.h>

void    asm_mips_operand_r(asm_operand *op, u_char *opcode, int otype,
                                          asm_instr *ins)
{
   op->type = ASM_MIPS_OTYPE_REGISTER;
//   memcpy(&op->scale,opcode,4);
}
/**
* @file libasm/src/arch/mips/operand_handlers/asm_mips_operand_regbase.c
** @ingroup MIPS_operands
*/
/*
 * - Adam 'pi3' Zabrocki
 *
 */

#include <libasm.h>

void    asm_mips_operand_regbase(asm_operand *op, u_char *opcode, int otype,
                                          asm_instr *ins)
{
   op->type = ASM_MIPS_OTYPE_REGBASE;
//   memcpy(&op->scale,opcode,4);
}
