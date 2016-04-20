/**
* @file libasm/src/arch/ia32/handlers/i386_bsf.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction bsf, opcode 0x0f 0xbc
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
*/

int i386_bsf(asm_instr *new, u_char *opcode, u_int len, 
	     asm_processor *proc) 
{
  new->len += 1;
  new->instr = ASM_BSF;

  new->type = ASM_TYPE_BITTEST | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL, 
			       new, 0);
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED, 
				new, 0);
#else 
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL, 
			       new);
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED, 
				new);
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction bsr rv, rms, opcode 0x0f 0xbd
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
 */

int i386_bsr_rv_rmb(asm_instr *new, u_char *opcode, u_int len,
		    asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_BSR;

  new->type = ASM_TYPE_BITTEST | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
 <i386 func="i386_bswap" opcode="0xc8"/>
 <i386 func="i386_bswap" opcode="0xc9"/>
 <i386 func="i386_bswap" opcode="0xca"/>
 <i386 func="i386_bswap" opcode="0xcb"/>
 <i386 func="i386_bswap" opcode="0xcc"/>
 <i386 func="i386_bswap" opcode="0xcd"/>
 <i386 func="i386_bswap" opcode="0xce"/>
 <i386 func="i386_bswap" opcode="0xcf"/>
*/

int i386_bswap(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{

  struct s_modrm        *modrm;
  modrm = (struct s_modrm *) opcode;

  new->len += 1;

  new->ptr_instr = opcode;
  new->instr = ASM_BSWAP;

  new->type = ASM_TYPE_OTHER;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_OPMOD, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_OPMOD, new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/i386_btrl.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction btrl, opcode 0x0f 0xba
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
 */

int     i386_btrl(asm_instr *new, u_char *opcode, u_int len,
		  asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_BTRL;

  new->type = ASM_TYPE_BITTEST | ASM_TYPE_BITSET | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_CF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,				ASM_OTYPE_ENCODED, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,				ASM_OTYPE_ENCODED, new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,				ASM_OTYPE_IMMEDIATEBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,				ASM_OTYPE_IMMEDIATEBYTE, new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/i386_bt_rm_r.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction bt rm, r, opcode 0x0f 0xa3
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
*/

int i386_bt_rm_r(asm_instr *new, u_char *opcode, u_int len,
                 asm_processor *proc) {
  struct s_modrm        *modrm;

  modrm = (struct s_modrm *) opcode + 1;
  new->instr = ASM_BT;
  new->len += 1;

  new->type = ASM_TYPE_BITTEST | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_CF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/i386_bts.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_bts" opcode="0xab"/>
 */

int i386_bts(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) {
  new->len += 1;
  new->instr = ASM_BTS;

  new->type = ASM_TYPE_BITTEST | ASM_TYPE_BITSET | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_CF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_cmova" opcode="0x47"/>
 */

int     i386_cmova(asm_instr *new, u_char *opcode, u_int len,
		   asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_CMOVA;

  new->type = ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_cmovae" opcode="0x43"/>
*/


int i386_cmovae(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_CMOVAE;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
#else
  new->op[0].type = ASM_OTYPE_GENERAL;
  new->op[1].type = ASM_OTYPE_ENCODED;
  operand_rv_rmv(new, opcode + 1, len - 1, proc);
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_cmovb" opcode="0x42"/>
*/


int i386_cmovb(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) {
  new->len += 1;
  new->instr = ASM_CMOVB;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
#else
  new->op[0].type = ASM_OTYPE_GENERAL;
  new->op[1].type = ASM_OTYPE_ENCODED;
  operand_rv_rmv(new, opcode + 1, len - 1, proc);
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_cmovbe" opcode="0x46"/>
*/


int i386_cmovbe(asm_instr *new, u_char *opcode, u_int len,
		asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_CMOVBE;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
#else
  new->op[0].type = ASM_OTYPE_GENERAL;
  new->op[1].type = ASM_OTYPE_ENCODED;
  operand_rv_rmv(new, opcode + 1, len - 1, proc);
#endif
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/i386_cmove.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_cmove" opcode="0x44"/>
*/


int i386_cmove(asm_instr *new, u_char *opcode, u_int len,
	       asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_CMOVE;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
#else
  new->op[0].type = ASM_OTYPE_GENERAL;
  new->op[1].type = ASM_OTYPE_ENCODED;
  operand_rv_rmv(new, opcode + 1, len - 1, proc);
  #endif
  return (new->len);
}

/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_cmovl" opcode="0x4c"/>
 */

int     i386_cmovl(asm_instr *new, u_char *opcode, u_int len,
		   asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_CMOVL;
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
#else
  new->op[0].type = ASM_OTYPE_GENERAL;
  new->op[1].type = ASM_OTYPE_ENCODED;
  operand_rv_rmv(new, opcode + 1, len - 1, proc);
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_cmovle" opcode="0x4e"/>
 */

int     i386_cmovle(asm_instr *new, u_char *opcode, u_int len,
		    asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_CMOVLE;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
#else
  new->op[0].type = ASM_OTYPE_GENERAL;
  new->op[1].type = ASM_OTYPE_ENCODED;
  operand_rv_rmv(new, opcode + 1, len - 1, proc);
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_cmovne" opcode="0x45"/>
*/


int i386_cmovne(asm_instr *new, u_char *opcode, u_int len,
		asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_CMOVNE;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
#else
  new->op[0].type = ASM_OTYPE_GENERAL;
  new->op[1].type = ASM_OTYPE_ENCODED;
  operand_rv_rmv(new, opcode + 1, len - 1, proc);
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_cmovnl" opcode="0x4d"/>
 */

int     i386_cmovnl(asm_instr *new, u_char *opcode, u_int len,
		    asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_CMOVNL;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
#else
  new->op[0].type = ASM_OTYPE_GENERAL;
  new->op[1].type = ASM_OTYPE_ENCODED;
  operand_rv_rmv(new, opcode + 1, len - 1, proc);
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_cmovnle" opcode="0x4f"/>
 */

int     i386_cmovnle(asm_instr *new, u_char *opcode, u_int len,
		     asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_CMOVNLE;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL, new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED, new);
#endif
#else
  new->op[0].type = ASM_OTYPE_GENERAL;
  new->op[1].type = ASM_OTYPE_ENCODED;
  operand_rv_rmv(new, opcode + 1, len - 1, proc);
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_cmovno" opcode="0x41"/>
*/


int i386_cmovno(asm_instr *new, u_char *opcode, u_int len,
		asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_CMOVNO;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED, new);
#endif
#else
  new->op[0].type = ASM_OTYPE_GENERAL;
  new->op[1].type = ASM_OTYPE_ENCODED;
  operand_rv_rmv(new, opcode + 1, len - 1, proc);
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_cmovnp" opcode="0x4b"/>
 */

int     i386_cmovnp(asm_instr *new, u_char *opcode, u_int len,
		    asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_CMOVNP;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
#else
  new->op[0].type = ASM_OTYPE_GENERAL;
  new->op[1].type = ASM_OTYPE_ENCODED;
  operand_rv_rmv(new, opcode + 1, len - 1, proc);
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_cmovns" opcode="0x49"/>
 */

int     i386_cmovns(asm_instr *new, u_char *opcode, u_int len,
		    asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_CMOVNS;
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
#else
  new->op[0].type = ASM_OTYPE_GENERAL;
  new->op[1].type = ASM_OTYPE_ENCODED;
  operand_rv_rmv(new, opcode + 1, len - 1, proc);
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_cmovo" opcode="0x40"/>
*/


int i386_cmovo(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_CMOVO;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
#else
  new->op[0].type = ASM_OTYPE_GENERAL;
  new->op[1].type = ASM_OTYPE_ENCODED;
  operand_rv_rmv(new, opcode + 1, len - 1, proc);
#endif
  return (new->len);
}

/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_cmovp" opcode="0x4a"/>
 */

int     i386_cmovp(asm_instr *new, u_char *opcode, u_int len,
		   asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_CMOVP;
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,			       new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,			       new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
#else
  new->op[0].type = ASM_OTYPE_GENERAL;
  new->op[1].type = ASM_OTYPE_ENCODED;
  operand_rv_rmv(new, opcode + 1, len - 1, proc);
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_cmovs" opcode="0x48"/>
 */

int     i386_cmovs(asm_instr *new, u_char *opcode, u_int len,
		   asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_CMOVA;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
#else
  new->op[0].type = ASM_OTYPE_GENERAL;
  new->op[1].type = ASM_OTYPE_ENCODED;
  operand_rv_rmv(new, opcode + 1, len - 1, proc);
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  Opcode :              0x0f 0xa2
  Instruction :         CPUID
 */

int i386_cpuid(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_CPUID;
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_emms" opcode="0x77"/>
 */

int     i386_emms(asm_instr *new, u_char *opcode, u_int len,
		  asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_MOVQ;

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_group12" opcode="0x71"/>
*/

int			i386_group12(asm_instr *new, u_char *opcode,
				     u_int len, asm_processor *proc)
{
  int			olen;
  struct s_modrm	*modrm;

  modrm = (struct s_modrm *) opcode + 1;
  new->ptr_instr = opcode;
  new->len += 1;
  switch (modrm->r)
    {
    case 2:
      new->instr = ASM_PSRLW;

      break;

    case 4:
      new->instr = ASM_PSRAW;
      break;

    case 6:
      new->instr = ASM_PSLLW;
      break;

    default:
      new->instr = ASM_BAD;
      return (new->len = 0);
      break;
    }
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += (olen = asm_operand_fetch(&new->op[0], opcode + 1,					ASM_OTYPE_PMMX, new, 0));
#else
  new->len += (olen = asm_operand_fetch(&new->op[0], opcode + 1,					ASM_OTYPE_PMMX, new));
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1 + olen,				ASM_OTYPE_IMMEDIATEBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1 + olen,				ASM_OTYPE_IMMEDIATEBYTE, new);
#endif
#else
  new->op[0].type = ASM_OTYPE_PMMX;
  new->op[0].size = ASM_OSIZE_QWORD;
  new->op[1].type = ASM_OTYPE_IMMEDIATE;
  new->op[1].size = ASM_OSIZE_BYTE;

  operand_rmb_ib(new, opcode + 1, len - 1, proc);
  new->op[0].regset = ASM_REGSET_MM;
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_group14" opcode="0x73"/>
 */

int     i386_group14(asm_instr *new, u_char *opcode, u_int len,
		     asm_processor *proc)
{
  int	olen;
  struct s_modrm *modrm = (struct s_modrm *) opcode + 1;

  new->ptr_instr = opcode;
  new->len += 1;
  switch (modrm->r)
    {
    case 2:
      new->instr = ASM_PSRLQ;
      break;

    case 6:
      new->instr = ASM_PSLLQ;
      new->op[0].type = ASM_OTYPE_PMMX;
      new->op[0].size = ASM_OSIZE_QWORD;
      new->op[1].type = ASM_OTYPE_IMMEDIATE;
      new->op[1].size = ASM_OSIZE_BYTE;

      operand_rmb_ib(new, opcode + 1, len - 1, proc);
      new->op[0].regset = ASM_REGSET_MM;
      break;

    default:
      new->instr = ASM_BAD;
      return (new->len = 0);
      break;
    }

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += (olen = asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_PMMX,					new, 0));
#else
  new->len += (olen = asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_PMMX,					new));
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1 + olen,				ASM_OTYPE_IMMEDIATEBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1 + olen,				ASM_OTYPE_IMMEDIATEBYTE, new);
#endif
#else
  new->op[0].type = ASM_OTYPE_PMMX;
  new->op[0].size = ASM_OSIZE_QWORD;
  new->op[1].type = ASM_OTYPE_IMMEDIATE;
  new->op[1].size = ASM_OSIZE_BYTE;

  operand_rmb_ib(new, opcode + 1, len - 1, proc);
  new->op[0].regset = ASM_REGSET_MM;
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="i386_group15" opcode="0xae"/>
 */

int i386_group15(asm_instr *new, u_char *opcode, u_int len,
		 asm_processor *proc)
{
  struct s_modrm        *modrm;
  modrm = (struct s_modrm *) opcode + 1;

  new->len += 1;

  switch(modrm->r)
    {
    case 2:
      new->instr = ASM_LDMXCSR;
      new->op[0].type = ASM_OTYPE_ENCODED;
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				    new, 0);
#else
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				    new);
#endif
#else
      operand_rmv(&new->op[0], opcode + 1, len - 1, proc);
      new->len += new->op[0].len;
#endif
      break;

    case 3:
      new->instr = ASM_STMXCSR;
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				    new, 0);
#else
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				    new);
#endif
#else
      new->op[0].type = ASM_OTYPE_ENCODED;
      operand_rmv(&new->op[0], opcode + 1, len - 1, proc);
      new->len += new->op[0].len;
#endif
      break;

    case 7:
      new->instr = ASM_CLFLUSH;
      new->op[0].type = ASM_OTYPE_GENERAL;
      break;

    default:
      new->len = 0;
      break;
    }

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/i386_group16.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 * Changelog
 * 2007-05-29: operand type fixed.
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction group 16, opcode 0x0f 0xae
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction
*/

int i386_group16(asm_instr *new, u_char *opcode, u_int len,
		 asm_processor *proc)
{
  struct s_modrm	*modrm;
  if (new->ptr_instr != 0)
    new->ptr_instr = opcode - 1;
  new->len += 1;
  new->instr = ASM_BAD;


  modrm = (struct s_modrm *) opcode + 1;
  switch(modrm->r)
    {
    case 0:
      new->instr = ASM_FXSAVE;
#if WIP
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				    new, 0);
#else
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				    new);
#endif
      break;
    case 1:
      new->instr = ASM_FXRSTORE;
#if WIP
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				    new, 0);
#else
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				    new);
#endif
      break;
    case 2:
      new->instr = ASM_LDMXCSR;
#if WIP
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				    new, 0);
#else
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				    new);
#endif
      break;
    case 3:
      new->instr = ASM_STMXCSR;
#if WIP
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				    new, 0);
#else
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				    new);
#endif
      break;
    case 4:
      new->instr = ASM_BAD;
      break;
    case 5:
      new->instr = ASM_LFENCE;
      break;
    case 6:
      new->instr = ASM_MFENCE;
      break;
    case 7:
      new->instr = ASM_SFENCE;
      ///CLFUSH
      break;
    }

#if LIBASM_USE_OPERAND_VECTOR
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_imul_rv_rmv" opcode="0xaf"/>
*/

int i386_imul_rv_rmv(asm_instr *new, u_char *opcode, u_int len,
		     asm_processor *proc)
{
    new->instr = ASM_IMUL;
    new->len += 1;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
    new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				  new, 0);
#else
    new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				  new);
#endif
#if WIP
    new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				  new, 0);
#else
    new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				  new);
#endif
#else
    new->op[0].type = ASM_OTYPE_GENERAL;
    new->op[0].size = ASM_OSIZE_VECTOR;
    new->op[1].type = ASM_OTYPE_ENCODED;
    new->op[1].size = ASM_OSIZE_VECTOR;
    operand_rv_rmv(new, opcode + 1, len - 1, proc);
#endif
    return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/i386_ja.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for far ja far instruction, opcode 0x0f 0x87
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 *
  <i386 func="i386_ja" opcode="0x87"/>
*/


int i386_ja(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  new->instr = ASM_BRANCH_U_GREATER;
  new->len += 1;
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new);
#endif
#else
  new->op[0].type = ASM_OTYPE_JUMP;
  new->op[0].content = ASM_OP_VALUE | ASM_OP_ADDRESS;
  new->op[0].ptr = opcode + 1;
  new->op[0].len = 4;
  memcpy(&new->op[0].imm, opcode + 1, 4);
  new->len += 4;
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_jae" opcode="0x83"/>
*/

int i386_jae(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  // new->type = IS_COND_BRANCH;
  new->instr = ASM_BRANCH_U_GREATER_EQUAL;
  new->len += 1;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new);
#endif
#else

  new->op[0].type = ASM_OTYPE_JUMP;
  new->op[0].content = ASM_OP_VALUE | ASM_OP_ADDRESS;
  new->op[0].ptr = opcode + 1;
  new->op[0].len = 4;
  memcpy(&new->op[0].imm, opcode + 1, 4);
  new->len += 4;
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_jb" opcode="0x82"/>
*/

int i386_jb(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  // new->type = IS_COND_BRANCH;
  new->instr = ASM_BRANCH_U_LESS;
  new->len += 1;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new);
#endif
#else

  new->op[0].type = ASM_OTYPE_JUMP;
  new->op[0].content = ASM_OP_VALUE | ASM_OP_ADDRESS;
  new->op[0].ptr = opcode + 1;
  new->op[0].len = 4;
  memcpy(&new->op[0].imm, opcode + 1, 4);
  new->len += 4;
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_jbe" opcode="0x86"/>
*/


int i386_jbe(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  // new->type = IS_COND_BRANCH;
  new->instr = ASM_BRANCH_U_LESS_EQUAL;
  new->len += 1;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new);
#endif
#else

  new->op[0].type = ASM_OTYPE_JUMP;
  new->op[0].content = ASM_OP_VALUE | ASM_OP_ADDRESS;
  new->op[0].ptr = opcode + 1;
  new->op[0].len = 4;
  memcpy(&new->op[0].imm, opcode + 1, 4);
  new->len += 4;
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_je" opcode="0x84"/>
*/


int i386_je(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  new->instr = ASM_BRANCH_EQUAL;
  new->len += 1;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP,				new);
#endif
#else

  new->op[0].type = ASM_OTYPE_JUMP;
  new->op[0].content = ASM_OP_VALUE | ASM_OP_ADDRESS;
  new->op[0].ptr = opcode + 1;
  new->op[0].len = 4;
  memcpy(&new->op[0].imm, opcode + 1, 4);
  new->len += 4;
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_jg" opcode="0x8f"/>
*/


int i386_jg(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  new->instr = ASM_BRANCH_S_GREATER;
  new->len += 1;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new);
#endif
#else

  new->op[0].type = ASM_OTYPE_JUMP;
  new->op[0].content = ASM_OP_VALUE | ASM_OP_ADDRESS;
  new->op[0].ptr = opcode + 1;
  new->op[0].len = 4;
  memcpy(&new->op[0].imm, opcode + 1, 4);
  new->len += 4;
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_jge" opcode="0x8d"/>
*/


int i386_jge(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  new->instr = ASM_BRANCH_S_GREATER_EQUAL;
  new->len += 1;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new);
#endif
#else

  new->op[0].type = ASM_OTYPE_JUMP;
  new->op[0].content = ASM_OP_VALUE | ASM_OP_ADDRESS;
  new->op[0].ptr = opcode + 1;
  new->op[0].len = 4;
  memcpy(&new->op[0].imm, opcode + 1, 4);
  new->len += 4;
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_jl" opcode="0x8c"/>
*/


int i386_jl(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  new->instr = ASM_BRANCH_S_LESS;
  new->len += 1;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new);
#endif
#else
  new->op[0].type = ASM_OTYPE_JUMP;
  new->op[0].content = ASM_OP_VALUE | ASM_OP_ADDRESS;
  new->op[0].ptr = opcode + 1;
  new->op[0].len = 4;
  memcpy(&new->op[0].imm, opcode + 1, 4);
  new->len += 4;
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_jle" opcode="0x8e"/>
*/


int i386_jle(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  new->instr = ASM_BRANCH_S_LESS_EQUAL;
  new->len += 1;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new);
#endif
#else

  new->op[0].type = ASM_OTYPE_JUMP;
  new->op[0].content = ASM_OP_VALUE | ASM_OP_ADDRESS;
  new->op[0].ptr = opcode + 1;
  new->op[0].len = 4;
  memcpy(&new->op[0].imm, opcode + 1, 4);
  new->len += 4;
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_jne" opcode="0x85"/>
*/


int i386_jne(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  // new->type = IS_COND_BRANCH;
    new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
    new->instr = ASM_BRANCH_NOT_EQUAL;
    new->len += 1;

    #if LIBASM_USE_OPERAND_VECTOR
#if WIP
    new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new, 0);
#else
    new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new);
#endif
    #else

    new->op[0].type = ASM_OTYPE_JUMP;
    new->op[0].content = ASM_OP_VALUE | ASM_OP_ADDRESS;
    new->op[0].ptr = opcode + 1;
    new->op[0].len = 4;
    memcpy(&new->op[0].imm, opcode + 1, 4);
    new->len += 4;
    #endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
<i386 func="i386_jnp" opcode="0x8b"/>
*/


int i386_jnp(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  new->instr = ASM_BRANCH_NOT_PARITY;
    new->len += 1;

    #if LIBASM_USE_OPERAND_VECTOR
#if WIP
    new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new, 0);
#else
    new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new);
#endif
    #else

  new->op[0].type = ASM_OTYPE_JUMP;
  new->op[0].content = ASM_OP_VALUE | ASM_OP_ADDRESS;
  new->op[0].ptr = opcode + 1;
  new->op[0].len = 4;
  memcpy(&new->op[0].imm, opcode + 1, 4);
  new->len += 4;
  #endif
return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_jns" opcode="0x89"/>
*/


int i386_jns(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
    new->instr = ASM_BRANCH_NOT_SIGNED;
    new->len += 1;

    #if LIBASM_USE_OPERAND_VECTOR
#if WIP
    new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new, 0);
#else
    new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new);
#endif
    #else

    new->op[0].type = ASM_OTYPE_JUMP;
    new->op[0].content = ASM_OP_VALUE | ASM_OP_ADDRESS;
    new->op[0].ptr = opcode + 1;
    new->op[0].len = 4;
    memcpy(&new->op[0].imm, opcode + 1, 4);
    new->len += 4;
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
<i386 func="i386_jp" opcode="0x8a"/>
*/


int i386_jp(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  new->instr = ASM_BRANCH_PARITY;
  new->len += 1;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP,				new);
#endif
#else

  new->op[0].type = ASM_OTYPE_JUMP;
  new->op[0].content = ASM_OP_VALUE | ASM_OP_ADDRESS;
  new->op[0].ptr = opcode + 1;
  new->op[0].len = 4;
  memcpy(&new->op[0].imm, opcode + 1, 4);
  new->len += 4;
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_js" opcode="0x88"/>
*/


int i386_js(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  // new->type = IS_COND_BRANCH;
  new->instr = ASM_BRANCH_SIGNED;
  new->len += 1;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new);
#endif
#else


  new->op[0].type = ASM_OTYPE_JUMP;
  new->op[0].content = ASM_OP_VALUE | ASM_OP_ADDRESS;
  new->op[0].ptr = opcode + 1;
  new->op[0].len = 4;
  memcpy(&new->op[0].imm, opcode + 1, 4);
  new->len += 4;
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

int i386_mov_cr_rm(asm_instr *new, u_char *opcode, u_int len,
		   asm_processor *proc)
{
  struct s_modrm        *modrm;

  modrm = (struct s_modrm *) (opcode + 1);
  new->len += 1;
  new->instr = ASM_MOV;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_CONTROL, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_CONTROL, new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_REGISTER, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_REGISTER, new);
#endif
#else
  new->op[0].type = ASM_OTYPE_CONTROL;
  new->op[0].content = ASM_OP_BASE;
  new->op[0].regset = ASM_REGSET_CREG;
  new->op[0].baser = modrm->r;

  new->op[1].type = ASM_OTYPE_REGISTER;
  new->op[1].content = ASM_OP_BASE;
  new->op[1].regset = ASM_REGSET_R32;
  new->op[1].baser = modrm->m;
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_movq_pq_qq" opcode="0x6e"/>
 */

int     i386_movd_pd_qd(asm_instr *new, u_char *opcode, u_int len,
			asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_MOVD;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,				ASM_OTYPE_GENERAL, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,				ASM_OTYPE_GENERAL, new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,				ASM_OTYPE_ENCODED, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,				ASM_OTYPE_ENCODED, new);
#endif
#else

  new->op[0].type = ASM_OTYPE_PMMX;
  new->op[0].size = ASM_OSIZE_DWORD;
  new->op[1].type = ASM_OTYPE_QMMX;
  new->op[1].size = ASM_OSIZE_DWORD;

  operand_rv_rmv(new, opcode + 1, len - 1, proc);
  new->op[0].regset = ASM_REGSET_MM;
  #endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

int i386_mov_dr_rm(asm_instr *new, u_char *opcode, u_int len,
		   asm_processor *proc)
{
  struct s_modrm        *modrm;

  modrm = (struct s_modrm *) (opcode + 1);
    new->len += 1;
    new->instr = ASM_MOV;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_DEBUG,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_DEBUG,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_REGISTER,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_REGISTER,				new);
#endif
#else
    new->op[0].type = ASM_OTYPE_DEBUG;
    new->op[0].content = ASM_OP_BASE;
    new->op[0].regset = ASM_REGSET_DREG;
    new->op[0].baser = modrm->r;
    new->op[1].type = ASM_OTYPE_REGISTER;
    new->op[1].content = ASM_OP_BASE;
    new->op[1].regset = ASM_REGSET_R32;
    new->op[1].baser = modrm->m;
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_movq_pq_qq" opcode="0x6f"/>
 */

int     i386_movq_pq_qq(asm_instr *new, u_char *opcode, u_int len,
			asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_MOVQ;

  #if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_PMMX, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_PMMX, new);
#endif

  #else

  new->op[0].type = ASM_OTYPE_PMMX;
  new->op[0].size = ASM_OSIZE_QWORD;
  new->op[1].type = ASM_OTYPE_QMMX;
  new->op[1].size = ASM_OSIZE_QWORD;

  operand_rv_rmv(new, opcode + 1, len - 1, proc);
  new->op[0].regset = ASM_REGSET_MM;
  #endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_movq_qq_pq" opcode="0x7f"/>
 */

int     i386_movq_qq_pq(asm_instr *new, u_char *opcode, u_int len,
			asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_MOVQ;

  #if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL, new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_PMMX, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_PMMX, new);
#endif
#else

  new->op[0].type = ASM_OTYPE_QMMX;
  new->op[0].size = ASM_OSIZE_QWORD;
  new->op[1].type = ASM_OTYPE_PMMX;
  new->op[1].size = ASM_OSIZE_QWORD;

  operand_rmv_rv(new, opcode + 1, len - 1, proc);
  new->op[1].regset = ASM_REGSET_MM;
  #endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

int i386_mov_rm_cr(asm_instr *new, u_char *opcode, u_int len,
		   asm_processor *proc)
{
  struct s_modrm        *modrm;

  modrm = (struct s_modrm *) (opcode + 1);
  new->len += 1;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_REGISTER,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_REGISTER,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_CONTROL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_CONTROL,				new);
#endif
#else

    new->instr = ASM_MOV;
    new->op[0].type = ASM_OTYPE_REGISTER;
    new->op[0].content = ASM_OP_BASE;
    new->op[0].regset = ASM_REGSET_R32;
    new->op[0].baser = modrm->m;
    new->op[1].type = ASM_OTYPE_SEGMENT;
    new->op[1].content = ASM_OP_BASE;
    new->op[1].regset = ASM_REGSET_CREG;
    new->op[1].baser = modrm->r;
    new->len += 1;
    #endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_movsbl_rv_rmb" opcode="0xbe"/>
*/

int i386_movsbl_rv_rmb(asm_instr *new, u_char *opcode, u_int len,
		       asm_processor *proc)
{
  if (asm_proc_opsize(proc))
    new->instr = ASM_MOVSBW;
  else
    new->instr = ASM_MOVSBL;
  new->len += 1;
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODEDBYTE,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODEDBYTE,				new);
#endif
#else
  new->op[0].type = ASM_OTYPE_GENERAL;
  new->op[1].type = ASM_OTYPE_ENCODED;
  operand_rv_rmb(new, opcode + 1, len - 1, proc);
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_movswl_rv_rm2" opcode="0xbf"/>
*/


int i386_movswl_rv_rm2(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  if (asm_proc_opsize(proc))
    new->instr = ASM_MOVSBW;
  else
    new->instr = ASM_MOVSWL;
  new->len += 1;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
#else

  new->op[0].type = ASM_OTYPE_GENERAL;
  new->op[1].type = ASM_OTYPE_ENCODED;
  operand_rv_rm2(new, opcode + 1, len - 1, proc);
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_movzbl_rv_rmb" opcode="0xb6"/>
*/

int i386_movzbl_rv_rmb(asm_instr *new, u_char *opcode, u_int len,
		       asm_processor *proc)
{
  new->len += 1;
    if (asm_proc_opsize(proc))
      new->instr = ASM_MOVZBW;
    else
      new->instr = ASM_MOVZBL;
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
    new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				  new, 0);
#else
    new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				  new);
#endif
#if WIP
    new->len += asm_operand_fetch(&new->op[1], opcode + 1,				  ASM_OTYPE_ENCODEDBYTE, new, 0);
#else
    new->len += asm_operand_fetch(&new->op[1], opcode + 1,				  ASM_OTYPE_ENCODEDBYTE, new);
#endif
#else

    new->op[0].type = ASM_OTYPE_GENERAL;
    new->op[0].size = ASM_OSIZE_VECTOR;
    new->op[1].type = ASM_OTYPE_ENCODED;
    new->op[1].size = ASM_OSIZE_BYTE;
    operand_rv_rmb(new, opcode + 1, len - 1, proc);
#endif
    return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_movzwl_rv_rm2" opcode="0xb7"/>
*/

int i386_movzwl_rv_rm2(asm_instr *new, u_char *opcode, u_int len,
		       asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_MOVZWL;

  #if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
#else
  new->op[0].type = ASM_OTYPE_GENERAL;
  new->op[1].type = ASM_OTYPE_ENCODED;
  operand_rv_rm2(new, opcode + 1, len - 1, proc);
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_packuswb_pq_qq" opcode="0x67"/>
 */

int     i386_packuswb_pq_qq(asm_instr *new, u_char *opcode, u_int len,
			    asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_PACKUSWB;

  new->op[0].type = ASM_OTYPE_PMMX;
  new->op[0].size = ASM_OSIZE_QWORD;
  new->op[1].type = ASM_OTYPE_QMMX;
  new->op[1].size = ASM_OSIZE_QWORD;

  #if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
  new->op[0].regset = ASM_REGSET_MM;
  new->op[1].regset = ASM_REGSET_MM;
  #else
  operand_rv_rmv(new, opcode + 1, len - 1, proc);
  new->op[0].regset = ASM_REGSET_MM;
  new->op[1].regset = ASM_REGSET_MM;
  #endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/i386_paddusb_pq_qq.c
 *
 * @ingroup IA32_instrs
* $Id$
*
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 *
 *
 <i386 func="i386_paddusb_pq_qq" opcode="0xdc"/>
 */

int     i386_paddusb_pq_qq(asm_instr *new, u_char *opcode, u_int len,
			   asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_PADDUSB;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
  new->op[0].regset = ASM_REGSET_MM;
  new->op[1].regset = ASM_REGSET_MM;
#else

  new->op[0].type = ASM_OTYPE_PMMX;
  new->op[0].size = ASM_OSIZE_QWORD;
  new->op[1].type = ASM_OTYPE_QMMX;
  new->op[1].size = ASM_OSIZE_QWORD;

  operand_rv_rmv(new, opcode + 1, len - 1, proc);
  new->op[0].regset = ASM_REGSET_MM;
  new->op[1].regset = ASM_REGSET_MM;
#endif
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/i386_paddusw_pq_qq.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 *
 * <i386 func="i386_paddusw_pq_qq" opcode="0xdd"/>
 */

int     i386_paddusw_pq_qq(asm_instr *new, u_char *opcode, u_int len,
			   asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_PADDUSW;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
  new->op[0].regset = ASM_REGSET_MM;
  new->op[1].regset = ASM_REGSET_MM;
#else
  new->op[0].type = ASM_OTYPE_PMMX;
  new->op[0].size = ASM_OSIZE_QWORD;
  new->op[1].type = ASM_OTYPE_QMMX;
  new->op[1].size = ASM_OSIZE_QWORD;

  operand_rv_rmv(new, opcode + 1, len - 1, proc);
  new->op[0].regset = ASM_REGSET_MM;
  new->op[1].regset = ASM_REGSET_MM;
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_pand_pq_qq" opcode="0xdb"/>
 */

int     i386_pand_pq_qq(asm_instr *new, u_char *opcode, u_int len,
			asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_PAND;

  #if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
  new->op[0].regset = ASM_REGSET_MM;
  new->op[1].regset = ASM_REGSET_MM;
#else

  new->op[0].type = ASM_OTYPE_PMMX;
  new->op[0].size = ASM_OSIZE_QWORD;
  new->op[1].type = ASM_OTYPE_QMMX;
  new->op[1].size = ASM_OSIZE_QWORD;

  operand_rv_rmv(new, opcode + 1, len - 1, proc);
  new->op[0].regset = ASM_REGSET_MM;
  new->op[1].regset = ASM_REGSET_MM;
  #endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_pmullw_pq_qq" opcode="0xd5"/>
 */

int     i386_pmullw_pq_qq(asm_instr *new, u_char *opcode, u_int len,
			  asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_PMULLW;

  #if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
  new->op[0].regset = ASM_REGSET_MM;
  new->op[1].regset = ASM_REGSET_MM;
#else

  new->op[0].type = ASM_OTYPE_PMMX;
  new->op[0].size = ASM_OSIZE_QWORD;
  new->op[1].type = ASM_OTYPE_QMMX;
  new->op[1].size = ASM_OSIZE_QWORD;

  operand_rv_rmv(new, opcode + 1, len - 1, proc);
  new->op[0].regset = ASM_REGSET_MM;
  new->op[1].regset = ASM_REGSET_MM;
  #endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  Opcode :              0x0f 0xa1
  Instruction :         POP
*/

int i386_pop_fs(asm_instr *new, u_char *opcode, u_int len,
                asm_processor *proc)
{
    new->instr = ASM_POP;
    new->len += 1;
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
    new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new, 				
				  asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
						 asm_proc_is_protected(proc) ?
						 ASM_REGSET_R32 : ASM_REGSET_R16));

#else
    new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
#endif
    new->op[0].regset = ASM_REGSET_SREG;
    new->op[0].content = ASM_OP_BASE | ASM_OP_FIXED;
    new->op[0].len = 0;
    new->op[0].ptr = 0;
    new->op[0].baser = ASM_REG_FS;
#else
    new->op[0].type = ASM_OTYPE_FIXED;
    new->op[0].regset = ASM_REGSET_SREG;
    new->op[0].content = ASM_OP_BASE | ASM_OP_FIXED;
    new->op[0].len = 0;
    new->op[0].ptr = 0;
    new->op[0].baser = ASM_REG_FS;
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_por_pq_qq" opcode="0xeb"/>
 */

int     i386_por_pq_qq(asm_instr *new, u_char *opcode, u_int len,
		       asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_POR;

  #if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
  new->op[0].regset = ASM_REGSET_MM;
  new->op[1].regset = ASM_REGSET_MM;
#else


  new->op[0].type = ASM_OTYPE_PMMX;
  new->op[0].size = ASM_OSIZE_QWORD;
  new->op[1].type = ASM_OTYPE_QMMX;
  new->op[1].size = ASM_OSIZE_QWORD;

  operand_rv_rmv(new, opcode + 1, len - 1, proc);
  new->op[0].regset = ASM_REGSET_MM;
  new->op[1].regset = ASM_REGSET_MM;
  #endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_punpckhbw_pq_qq" opcode="0x68"/>
 */

int     i386_punpckhbw_pq_qq(asm_instr *new, u_char *opcode, u_int len,
			     asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_PUNPCKHBW;

  #if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
  new->op[0].regset = ASM_REGSET_MM;
  new->op[1].regset = ASM_REGSET_MM;
  #else

  new->op[0].type = ASM_OTYPE_PMMX;
  new->op[0].size = ASM_OSIZE_QWORD;
  new->op[1].type = ASM_OTYPE_QMMX;
  new->op[1].size = ASM_OSIZE_QWORD;

  operand_rv_rmv(new, opcode + 1, len - 1, proc);
  new->op[0].regset = ASM_REGSET_MM;
  new->op[1].regset = ASM_REGSET_MM;
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_punpcklbw_pq_qq" opcode="0x60"/>
 */

int     i386_punpcklbw_pq_qd(asm_instr *new, u_char *opcode, u_int len,
			     asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_PUNPCKLBW;

  #if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
  new->op[0].regset = ASM_REGSET_MM;
  new->op[1].regset = ASM_REGSET_MM;
  #else

  new->op[0].type = ASM_OTYPE_PMMX;
  new->op[0].size = ASM_OSIZE_QWORD;
  new->op[1].type = ASM_OTYPE_QMMX;
  new->op[1].size = ASM_OSIZE_DWORD;

  operand_rv_rmv(new, opcode + 1, len - 1, proc);
  new->op[0].regset = ASM_REGSET_MM;
  new->op[1].regset = ASM_REGSET_MM;
  #endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  Opcode :              0x0f 0xa0
  Instruction :         PUSH
  <i386 func="i386_push_fs" opcode="0xa0"/>
*/

int i386_push_fs(asm_instr *new, u_char *opcode, u_int len,
                 asm_processor *proc)
{
  new->instr = ASM_PUSH;
  new->len += 1;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new, 				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));

#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
#endif
  new->op[0].content = ASM_OP_BASE | ASM_OP_FIXED;
  new->op[0].regset = ASM_REGSET_SREG;
  new->op[0].len = 0;
  new->op[0].ptr = 0;
  new->op[0].baser = ASM_REG_FS;
#else
  new->op[0].type = ASM_OTYPE_FIXED;
  new->op[0].content = ASM_OP_BASE | ASM_OP_FIXED;
  new->op[0].regset = ASM_REGSET_SREG;
  new->op[0].len = 0;
  new->op[0].ptr = 0;
  new->op[0].baser = ASM_REG_FS;
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_pxor_pq_qq" opcode="0xef"/>
 */

int     i386_pxor_pq_qq(asm_instr *new, u_char *opcode, u_int len,
			asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_PXOR;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
  new->op[0].regset = ASM_REGSET_MM;
  new->op[1].regset = ASM_REGSET_MM;
#else
  new->op[0].type = ASM_OTYPE_PMMX;
  new->op[0].size = ASM_OSIZE_QWORD;
  new->op[1].type = ASM_OTYPE_QMMX;
  new->op[1].size = ASM_OSIZE_QWORD;

  operand_rv_rmv(new, opcode + 1, len - 1, proc);
  new->op[0].regset = ASM_REGSET_MM;
  new->op[1].regset = ASM_REGSET_MM;
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/**
   <i386 func="i386_rdmsr" opcode="0x32"/>
 */

int     i386_rdmsr(asm_instr *new, u_char *opcode, u_int len,
		   asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_RDMSR;
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_rdtsc" opcode="0x31"/>
 */

int     i386_rdtsc(asm_instr *new, u_char *opcode, u_int len,
		   asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_RDTSC;
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/i386_shld.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction shld, opcode 0x0f 0xa4
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
*/

int i386_shld(asm_instr *new, u_char *opcode, u_int len,
	      asm_processor *proc)
{
  struct s_modrm        *modrm;
  new->len += 1;

  modrm = (struct s_modrm *) opcode + 1;
  new->instr = ASM_SHLD;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,				ASM_OTYPE_REGISTER, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,				ASM_OTYPE_REGISTER, new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,				ASM_OTYPE_GENERAL, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,				ASM_OTYPE_GENERAL, new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[2], opcode + 2,				ASM_OTYPE_IMMEDIATEBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[2], opcode + 2,				ASM_OTYPE_IMMEDIATEBYTE, new);
#endif
  new->len += 1;
#else

  new->op[0].type = ASM_OTYPE_REGISTER;
  new->op[0].regset = ASM_REGSET_R32;
  new->op[0].content = ASM_OP_BASE;
  new->op[0].ptr = opcode + 1;
  new->op[0].len = 0;
  new->op[0].baser = modrm->m;

  new->op[1].type = ASM_OTYPE_GENERAL;
  new->op[1].regset = ASM_REGSET_R32;
  new->op[1].content = ASM_OP_BASE;
  new->op[1].ptr = opcode + 1;
  new->op[1].len = 1;
  new->op[1].baser = modrm->r;

  new->op[2].type = ASM_OTYPE_IMMEDIATE;
  new->op[2].content = ASM_OP_VALUE;
  new->op[2].ptr = opcode + 2;
  new->op[2].len = 1;
  new->op[2].imm = 0;
  memcpy(&new->op[2].imm, opcode + 2, 1);
  new->len += new->op[0].len + new->op[1].len + new->op[2].len;
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_shld_rmv_rv_cl" opcode="0xa5"/>
*/

int i386_shld_rmv_rv_cl(asm_instr *new, u_char *opcode, u_int len,
			asm_processor *proc)
{
  new->instr = ASM_SHRD;
  new->len += 1;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[2], opcode + 1, ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));

#else
  new->len += asm_operand_fetch(&new->op[2], opcode + 1, ASM_OTYPE_FIXED, new);
#endif
  new->op[2].content = ASM_OP_BASE;
  new->op[2].regset = ASM_REGSET_R8;
  new->op[2].ptr = opcode;
  new->op[2].len = 0;
  new->op[2].baser = ASM_REG_CL;

#else
  new->op[0].type = ASM_OTYPE_ENCODED;
  new->op[0].size = ASM_OSIZE_VECTOR;
  new->op[1].type = ASM_OTYPE_GENERAL;
  new->op[1].size = ASM_OSIZE_VECTOR;
  operand_rmv_rv(new, opcode + 1, len - 1, proc);
  new->op[2].type = ASM_OTYPE_FIXED;
  new->op[2].content = ASM_OP_BASE;
  new->op[2].regset = ASM_REGSET_R8;
  new->op[2].ptr = opcode;
  new->op[2].len = 0;
  new->op[2].baser = ASM_REG_CL;
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
 <i386 func="i386_shrd_rmv_rv_cl" opcode="0xad"/>
*/

int i386_shrd_rmv_rv_cl(asm_instr *new, u_char *opcode, u_int len,
			asm_processor *proc)
{
    new->instr = ASM_SHRD;
    new->len += 1;
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
    new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				  new, 0);
#else
    new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				  new);
#endif
#if WIP
    new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERAL,				  new, 0);
#else
    new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERAL,				  new);
#endif
#if WIP
    new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_FIXED,				  new, 
				  				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));

#else
    new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_FIXED,				  new);
#endif
    new->op[2].content = ASM_OP_BASE;
    new->op[2].regset = ASM_REGSET_R8;
    new->op[2].ptr = opcode;
    new->op[2].len = 0;
    new->op[2].baser = ASM_REG_CL;
#else
    new->op[0].type = ASM_OTYPE_ENCODED;
    new->op[0].size = ASM_OSIZE_VECTOR;
    new->op[1].type = ASM_OTYPE_GENERAL;
    new->op[1].size = ASM_OSIZE_VECTOR;
    operand_rmv_rv(new, opcode + 1, len - 1, proc);
    new->op[2].type = ASM_OTYPE_FIXED;
    new->op[2].content = ASM_OP_BASE;
    new->op[2].regset = ASM_REGSET_R8;
    new->op[2].ptr = opcode;
    new->op[2].len = 0;
    new->op[2].baser = ASM_REG_CL;
#endif
    return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/i386_shrd_rmv_rv_ib.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction shrd, opcode 0x0f 0xac
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
*/

int i386_shrd_rmv_rv_ib(asm_instr *new, u_char *opcode, u_int len,
			asm_processor *proc)
{
  int		olen;
  new->instr = ASM_SHRD;
  new->len += 1;
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += (olen = asm_operand_fetch(&new->op[0], opcode + 1,					ASM_OTYPE_ENCODED, new, 0));
#else
  new->len += (olen = asm_operand_fetch(&new->op[0], opcode + 1,					ASM_OTYPE_ENCODED, new));
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,				ASM_OTYPE_GENERAL, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,				ASM_OTYPE_GENERAL, new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[2], opcode + 1 + olen,				ASM_OTYPE_IMMEDIATEBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[2], opcode + 1 + olen,				ASM_OTYPE_IMMEDIATEBYTE, new);
#endif
#else
    new->op[0].type = ASM_OTYPE_ENCODED;
  new->op[0].size = ASM_OSIZE_VECTOR;
  new->op[1].type = ASM_OTYPE_GENERAL;
  new->op[1].size = ASM_OSIZE_VECTOR;
  new->op[2].type = ASM_OTYPE_IMMEDIATE;
  new->op[2].size = ASM_OSIZE_BYTE;
  operand_rmv_rv(new, opcode + 1, len - 1, proc);
  new->op[2].type = ASM_OTYPE_IMMEDIATE;
  new->op[2].content = ASM_OP_VALUE;
  new->op[2].ptr = opcode + 2;
  new->op[2].len = 1;

  new->op[2].imm = 0;
  memcpy(&new->op[2].imm, opcode + 2, 1);
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

int     i386_wbinvd(asm_instr *new, u_char *opcode, u_int len,
		    asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_WBINVD;
  return (new->len);

}
/**
* @file libasm/src/arch/ia32/handlers/i386_xadd.c
 *
 * @ingroup IA32_instrs
 *  $Id$
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for the opcode FF C1
 <i386 func="" opcode="0xc1"/>
*/

int i386_xadd(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  struct s_modrm        *modrm;
  modrm = (struct s_modrm *) opcode;
  new->instr = ASM_XADD;
  new->len += 1;
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#else
  new->op[0].type = ASM_OTYPE_GENERAL;
  new->op[1].type = ASM_OTYPE_GENERAL;
  operand_rmv_rv(new, opcode + 1, len - 1, proc);
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="i386_shld_rmv_rv_cl" opcode="0xa7"/>
*/

int     i386_xstorenrg(asm_instr *new, u_char *opcode, u_int len,
		       asm_processor *proc)
{
  switch(*(opcode + 1))
    {
    case 0xc0:  new->instr = ASM_XSTORERNG; break;
    case 0xd0:  new->instr = ASM_XCRYPTCBC; break;
    case 0xe0:  new->instr = ASM_XCRYPTCFB; break;
    case 0xe8:  new->instr = ASM_XCRYPTOFB; break;
    default: new->instr = ASM_NONE;
    }
  new->len += 2;
  return (new->len);
}

/**
* @file libasm/src/arch/ia32/handlers/op_386sp.c
 *
 * @ingroup IA32_instrs
 * $Id$
 * ChangeLog:
 * 2007-05-30	Fixed a bug in fetching. The vector used was the previously defined.
 *		strauss set up a new disasm vector and didn't know about it which
 *		was called here.
 *		Filled instruction opcode pointer.
 *		Removed the old unused handler.
 *		Added minimal error management.
 */
#include <libasm.h>
#include <libasm-int.h>


/**
 * This is the handler for 2 bytes instruction, opcode 0x0f
 * The second byte is used to fetch a new handler in the vector
 * starting at offset 0x100.
 * @param ins Pointer to instruction structure.
 * @param buf Pointer to data to disassemble.
 * @param len Length of dat to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction or -1 error.
 */

int     op_386sp(asm_instr *ins, u_char *buf, u_int len, asm_processor *proc)
{
  int        opcode;
  int           (*fetch)(asm_instr *, u_char *, u_int, asm_processor *);

  // XXX: Use asm_set_error to set error code to LIBASM_ERROR_TOOSHORT
  if (len < 2)
    return (-1);
  
  opcode = *(buf + 1);
  opcode += 0x100;
  fetch = asm_opcode_fetch(LIBASM_VECTOR_OPCODE_IA32, opcode);
  if (!fetch)
    return (-1);
  if (!ins->ptr_instr)
    ins->ptr_instr = buf;
  ins->len += 1;
  return (fetch(ins, buf + 1, len - 1, proc));
}

/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for the aaa instruction, opcode 0x37
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of disassembled instruction.
*/

int     op_aaa(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_AAA;
  new->type = ASM_TYPE_WRITEFLAG | ASM_TYPE_READFLAG | ASM_TYPE_ARITH;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF;
  new->flagsread = ASM_FLAG_AF;
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_aad.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for the aad instruction, opcode 0xd5
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of disassembled instruction.
 */
int op_aad(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_AAD;
  new->type = ASM_TYPE_WRITEFLAG | ASM_TYPE_ARITH;
  new->flagswritten = ASM_FLAG_SF | ASM_FLAG_ZF | ASM_FLAG_PF;
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
 * Handler for the aam instruction, opcode 0xd4
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of disassembled instruction.
*/

int op_aam(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_AAM;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_SF | ASM_FLAG_ZF | ASM_FLAG_PF;
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for the aas instruction, opcode 0x3f
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of disassembled instruction.
 */

int     op_aas(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_AAS;
  new->type = ASM_TYPE_WRITEFLAG | ASM_TYPE_READFLAG | ASM_TYPE_ARITH;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF;
  new->flagsread = ASM_FLAG_AF;
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_adc_al_ib" opcode="0x14"/>
*/

int op_adc_al_ib(asm_instr *new, u_char *opcode, u_int len,
		 asm_processor *proc)
{
  new->instr = ASM_ADC;
  new->len += 1;
  new->ptr_instr = opcode;

  new->type = ASM_TYPE_ARITH | ASM_TYPE_READFLAG | ASM_TYPE_WRITEFLAG;
  new->flagsread = ASM_FLAG_CF;
  new->flagswritten = ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF |
                       ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));

#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_FIXED, new);
#endif
  new->op[0].content = ASM_OP_BASE | ASM_OP_FIXED;
  new->op[0].ptr = opcode;
  new->op[0].len = 0;
  new->op[0].baser = ASM_REG_AL;
  new->op[0].regset = ASM_REGSET_R8;
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,			                  	ASM_OTYPE_IMMEDIATEBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,			                  	ASM_OTYPE_IMMEDIATEBYTE, new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_adc_eax_iv" opcode="0x15"/>
*/

int op_adc_eax_iv(asm_instr *new, u_char *opcode, u_int len,
		  asm_processor *proc)
{
  new->instr = ASM_ADC;
  new->ptr_instr = opcode;
  new->len += 1;

  new->type = ASM_TYPE_ARITH | ASM_TYPE_READFLAG | ASM_TYPE_WRITEFLAG;
  new->flagsread = ASM_FLAG_CF;
  new->flagswritten = ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF |
                       ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));

#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
#endif
  new->op[0].type = ASM_OTYPE_FIXED;
  new->op[0].size = new->op[1].size = asm_proc_vector_size(proc);

  new->op[0].content = ASM_OP_FIXED | ASM_OP_BASE;
  new->op[0].baser = ASM_REG_EAX;
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_IMMEDIATE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_IMMEDIATE,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_adc_rb_rmb" opcode="0x12"/>
*/

int op_adc_rb_rmb(asm_instr *new, u_char *opcode, u_int len,
		  asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_ADC;
  new->ptr_instr = opcode;

  new->type = ASM_TYPE_ARITH | ASM_TYPE_READFLAG | ASM_TYPE_WRITEFLAG;
  new->flagsread = ASM_FLAG_CF;
  new->flagswritten = ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF |
                       ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,                                ASM_OTYPE_GENERALBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,                                ASM_OTYPE_GENERALBYTE, new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,                                ASM_OTYPE_ENCODEDBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,                                ASM_OTYPE_ENCODEDBYTE, new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_adc_rmb_rb" opcode="0x10"/>
*/

int op_adc_rmb_rb(asm_instr *new, u_char *opcode, u_int len,
		  asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_ADC;

  new->type = ASM_TYPE_ARITH | ASM_TYPE_READFLAG | ASM_TYPE_WRITEFLAG;
  new->flagsread = ASM_FLAG_CF;
  new->flagswritten = ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF |
                       ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE,                                new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERALBYTE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERALBYTE,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_adc_rmv_rv" opcode="0x11"/>
*/

int op_adc_rmv_rv(asm_instr *new, u_char *opcode, u_int len,
		  asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_ADC;

  new->type = ASM_TYPE_ARITH | ASM_TYPE_READFLAG | ASM_TYPE_WRITEFLAG;
  new->flagsread = ASM_FLAG_CF;
  new->flagswritten = ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF |
                       ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,                                new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERAL,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERAL,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_adc_rv_rmv" opcode="0x13"/>
*/

int op_adc_rv_rmv(asm_instr *new, u_char *opcode, u_int len,
		  asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_ADC;

  new->type = ASM_TYPE_ARITH | ASM_TYPE_READFLAG | ASM_TYPE_WRITEFLAG;
  new->flagsread = ASM_FLAG_CF;
  new->flagswritten = ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF |
                       ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,                                new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  Opcode :              0x04
  Instruction :         ADD
*/

int op_add_al_ib(asm_instr *new, u_char *opcode, u_int len,
                      asm_processor *proc) {
  new->instr = ASM_ADD;
  new->ptr_instr = opcode;
  new->len += 1;

  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF |
                       ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));

#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
#endif
  new->op[0].content = ASM_OP_BASE | ASM_OP_FIXED;
  new->op[0].ptr = opcode;
  new->op[0].len = 0;
  new->op[0].baser = ASM_REG_AL;
  new->op[0].regset = ASM_REGSET_R8;
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,                                ASM_OTYPE_IMMEDIATEBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,                                ASM_OTYPE_IMMEDIATEBYTE, new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  Opcode :              0x05
  Instruction :         ADD
*/

int op_add_eax_iv(asm_instr *new, u_char *opcode, u_int len,
		  asm_processor *proc)
{

  new->instr = ASM_ADD;
  new->ptr_instr = opcode;
  new->len += 1;

  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_CF | ASM_FLAG_ZF | ASM_FLAG_PF |
                      ASM_FLAG_OF | ASM_FLAG_AF | ASM_FLAG_SF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));

#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_FIXED, new);
#endif
  new->op[0].content = ASM_OP_FIXED | ASM_OP_BASE;
  new->op[0].len = 0;
  new->op[0].baser = ASM_REG_EAX;
  new->op[0].regset = asm_proc_opsize(proc) ? ASM_REGSET_R16 :
    ASM_REGSET_R32;
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_IMMEDIATE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_IMMEDIATE,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
 * Opcode :             0x02
 * Instruction :                ADD
 * Destination is a byte register
 * Source is a byte encoded
 */

int op_add_rb_rmb(asm_instr *new, u_char *opcode, u_int len,
                  asm_processor *proc)
{
  new->instr = ASM_ADD;
  new->ptr_instr = opcode;
  new->len++;

  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_CF | ASM_FLAG_ZF | ASM_FLAG_PF |
                      ASM_FLAG_OF | ASM_FLAG_AF | ASM_FLAG_SF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERALBYTE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERALBYTE,                                new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODEDBYTE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODEDBYTE,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
 * Opcode :             0x00
 * ADD
 * Destination is an encoded byte.
 * Source is a byte register.
 */

int op_add_rmb_rb(asm_instr *new, u_char *opcode, u_int len,
                  asm_processor *proc)
{
  new->instr = ASM_ADD;
  new->ptr_instr = opcode;
  new->len++;

  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_CF | ASM_FLAG_ZF | ASM_FLAG_PF |
                      ASM_FLAG_OF | ASM_FLAG_AF | ASM_FLAG_SF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE,                                new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERALBYTE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERALBYTE,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
 * Opcode :             0x01
 * Instruction :                ADD
 * Operands:            Destination: encoded vector.
 * Source: is a vector register.
 */

int op_add_rmv_rv(asm_instr *new, u_char *opcode, u_int len,
                  asm_processor *proc)
{
  new->len++;
  new->ptr_instr = opcode;
  new->instr = ASM_ADD;

  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_CF | ASM_FLAG_ZF | ASM_FLAG_PF |
                      ASM_FLAG_OF | ASM_FLAG_AF | ASM_FLAG_SF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,                                new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERAL,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERAL,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for the add rv, rmv instruction, opcode 0x03
 * @param new Pointer to the instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of the data to disassemble.
 * @param proc Pointer to the processor structure.
 * @return Length of the disassembled instruction.
 */

int op_add_rv_rmv(asm_instr *new, u_char *opcode, u_int len,
		  asm_processor *proc)
{
  new->instr = ASM_ADD;
  new->len++;
  new->ptr_instr = opcode;

  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_CF | ASM_FLAG_ZF | ASM_FLAG_PF |
                      ASM_FLAG_OF | ASM_FLAG_AF | ASM_FLAG_SF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,                                new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_addsize" opcode="0x67"/>
 */

int     op_addsize(asm_instr *new, u_char *opcode, u_int len,
                   asm_processor *proc)
{
  asm_i386_processor    *i386p;

  if (!new->ptr_prefix)
    new->ptr_prefix = opcode;

  i386p = (asm_i386_processor *) proc;
  new->prefix |= ASM_PREFIX_ADDSIZE;

  i386p->internals->addsize = !i386p->internals->addsize;
  len = proc->fetch(new, opcode + 1, len - 1, proc);
  i386p->internals->addsize = !i386p->internals->addsize;

  return (len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_and_al_ib" opcode="0x24"/>
*/

int op_and_al_ib(asm_instr *new, u_char *opcode, u_int len,
		 asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_AND;
  new->ptr_instr = opcode;

  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_CF | ASM_FLAG_ZF | ASM_FLAG_PF |
                      ASM_FLAG_OF | ASM_FLAG_SF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));

#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_FIXED, new);
#endif
  new->op[0].content = ASM_OP_BASE | ASM_OP_FIXED;
  new->op[0].regset = ASM_REGSET_R8;
  new->op[0].ptr = opcode;
  new->op[0].len = 0;
  new->op[0].baser = ASM_REG_AL;
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_IMMEDIATEBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_IMMEDIATEBYTE, new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_and_eax_iv" opcode="0x25"/>
*/

int op_and_eax_iv(asm_instr *new, u_char *opcode, u_int len,
		  asm_processor *proc)
{
  new->instr = ASM_AND;
  new->len += 1;
  new->ptr_instr = opcode;

  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_CF | ASM_FLAG_ZF | ASM_FLAG_PF |
                      ASM_FLAG_OF | ASM_FLAG_SF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));

#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
#endif
  new->op[0].content = ASM_OP_BASE | ASM_OP_FIXED;
  new->op[0].regset = ASM_REGSET_R32;
  new->op[0].ptr = opcode;
  new->op[0].len = 0;
  new->op[0].baser = ASM_REG_EAX;
  new->op[0].regset = asm_proc_is_protected(proc) ?
    ASM_REGSET_R32 : ASM_REGSET_R16;
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_IMMEDIATE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_IMMEDIATE,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_and_rb_rmb" opcode="0x22"/>
*/

int op_and_rb_rmb(asm_instr *new, u_char *opcode, u_int len,
                  asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_AND;

  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_CF | ASM_FLAG_ZF | ASM_FLAG_PF |
                      ASM_FLAG_OF | ASM_FLAG_SF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERALBYTE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERALBYTE,                                new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODEDBYTE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODEDBYTE,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_and_rmb_rb" opcode="0x20"/>
*/

int op_and_rmb_rb(asm_instr *new, u_char *opcode, u_int len,
                  asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_AND;

  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_CF | ASM_FLAG_ZF | ASM_FLAG_PF |
                      ASM_FLAG_OF | ASM_FLAG_SF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE,                                new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERALBYTE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERALBYTE,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_and_rmv_rv" opcode="0x21"/>
*/

int op_and_rmv_rv(asm_instr *new, u_char *opcode, u_int len,
                  asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_AND;

  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_CF | ASM_FLAG_ZF | ASM_FLAG_PF |
                      ASM_FLAG_OF | ASM_FLAG_SF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,                                ASM_OTYPE_ENCODED, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,                                ASM_OTYPE_ENCODED, new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,                                ASM_OTYPE_GENERAL, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,                                ASM_OTYPE_GENERAL, new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_and_rv_rmv" opcode="0x23"/>
*/

int op_and_rv_rmv(asm_instr *new, u_char *opcode, u_int len,
                  asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_AND;

  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_CF | ASM_FLAG_ZF | ASM_FLAG_PF |
                      ASM_FLAG_OF | ASM_FLAG_SF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,                                new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_arpl_ew_rw" opcode="0x63"/>
*/

int     op_arpl_ew_rw(asm_instr *new, u_char *opcode, u_int len,
		      asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->instr = ASM_ARPL;
  new->len += 1;
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_bound_gv_ma" opcode="0x62"/>
*/

int     op_bound_gv_ma(asm_instr *new, u_char *opcode, u_int len,
		       asm_processor *proc)
{
#if !LIBASM_USE_OPERAND_VECTOR
  struct s_modrm        *modrm;
#endif

  new->instr = ASM_BOUND;
  new->len += 1;
  new->ptr_instr = opcode;

  #if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_MEMORY,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_MEMORY,				new);
#endif
#else

  modrm = (struct s_modrm *) (opcode + 1);
  new->op[0].type = ASM_OTYPE_GENERAL;
  new->op[1].type = ASM_OTYPE_MEMORY;
  operand_rmv(&new->op[0], opcode + 1, len - 1, proc);

  new->op[1].content = ASM_OP_BASE;
  new->op[1].regset = ASM_REGSET_R32;
  new->op[1].baser = modrm->r;
  new->len += new->op[0].len;
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="op_btr_rmv_rv" opcode="0xb3"/>
*/

int     op_btr_rmv_rv(asm_instr *new, u_char *opcode, u_int len,
		      asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_BTR;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#else
  new->op[0].type = ASM_OTYPE_GENERAL;
  new->op[1].type = ASM_OTYPE_ENCODED;
  operand_rmv_rv(new, opcode + 1, len - 1, proc);
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_call_iv" opcode="0xe8"/>
*/

int op_call_iv(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->instr = ASM_CALL;
  new->type = ASM_TYPE_CALLPROC | ASM_TYPE_TOUCHSP;
  new->len += 1;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_clc" opcode="0xf8"/>
*/

int op_clc(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_CLC;
  new->type = ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_CF;
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_cld" opcode="0xfc"/>
*/

int op_cld(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_CLD;
  new->type = ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_DF;
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_cli" opcode="0xfa"/>
*/

int op_cli(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_CLI;
  new->type = ASM_TYPE_WRITEFLAG;
  /* Should be VIF for CPL = 3 and IOPL < CPL */
  new->flagswritten = ASM_FLAG_IF;
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
 <instruction func="op_cltd" opcode="0x99"/>
*/

int op_cltd(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->type = ASM_TYPE_ARITH;

  if (asm_proc_opsize(proc))
    new->instr = ASM_CWTD;
  else
  new->instr = ASM_CLTD;

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_cmc" opcode="0xf5"/>
*/

int op_cmc(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_CMC;
  new->type = ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_CF;
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_cmp_al_ib" opcode="0x3c"/>
*/

int op_cmp_al_ib(asm_instr *new, u_char *opcode, u_int len,
                 asm_processor *proc)
{
  new->instr = ASM_CMP;
  new->len += 1;

  new->type = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_CF | ASM_FLAG_PF | ASM_FLAG_AF |
                        ASM_FLAG_SF | ASM_FLAG_OF | ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));

#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
#endif
  new->op[0].content = ASM_OP_BASE | ASM_OP_FIXED;
  new->op[0].regset = ASM_REGSET_R8;
  new->op[0].ptr = opcode;
  new->op[0].len = 0;
  new->op[0].baser = ASM_REG_AL;
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,                                ASM_OTYPE_IMMEDIATEBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,                                ASM_OTYPE_IMMEDIATEBYTE, new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_cmp_eax_iv" opcode="0x3d"/>
*/

int op_cmp_eax_iv(asm_instr *new, u_char *opcode, u_int len,
                  asm_processor *proc)
{
  new->instr = ASM_CMP;
  new->ptr_instr = opcode;
  new->len += 1;

  new->type = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF |
                        ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));

#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
#endif
  new->op[0].content = ASM_OP_FIXED | ASM_OP_BASE;
  new->op[0].baser = ASM_REG_EAX;
  new->op[0].regset = asm_proc_opsize(proc) ?
    ASM_REGSET_R16 : ASM_REGSET_R32;
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_IMMEDIATE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_IMMEDIATE,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_cmp_rb_rmb" opcode="0x3a"/>
*/

int op_cmp_rb_rmb(asm_instr *new, u_char *opcode, u_int len,
                  asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_CMP;

  new->type = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF |
                        ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF;


#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERALBYTE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERALBYTE,                                new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODEDBYTE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODEDBYTE,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_cmp_rmb_rb" opcode="0x38"/>
*/

int op_cmp_rmb_rb(asm_instr *new, u_char *opcode, u_int len,
                  asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_CMP;

  new->type = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF |
                        ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE,                                new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERALBYTE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERALBYTE,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_cmp_rmv_rv" opcode="0x39"/>
*/

int op_cmp_rmv_rv(asm_instr *new, u_char *opcode, u_int len,
                  asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_CMP;

  new->type = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF |
                        ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,                                new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERAL,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERAL,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_cmp_rv_rmv" opcode="0x3b"/>
*/

int op_cmp_rv_rmv(asm_instr *new, u_char *opcode, u_int len,
                  asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_CMP;

  new->type = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF |
                        ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,                                new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,                                new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_cmpsb.c
 * @brief Handler for instruction cmpsb opcode 0xa6
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Handler for instruction cmpsb opcode 0xa6
 * @param instr Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction .
 */

int op_cmpsb(asm_instr *instr, u_char *opcode, u_int len, asm_processor *proc)
{
  instr->instr = ASM_CMPSB;
  instr->len += 1;
  instr->ptr_instr = opcode;

  instr->type = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
  instr->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF |
                        ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  instr->len += asm_operand_fetch(&instr->op[0], opcode + 1, ASM_OTYPE_XSRC, instr, 0);
#else
  instr->len += asm_operand_fetch(&instr->op[0], opcode + 1, ASM_OTYPE_XSRC, instr);
#endif
#if WIP
  instr->len += asm_operand_fetch(&instr->op[1], opcode + 1, ASM_OTYPE_YDEST, instr, 0);
#else
  instr->len += asm_operand_fetch(&instr->op[1], opcode + 1, ASM_OTYPE_YDEST, instr);
#endif

  return (instr->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_cmpsd" opcode="0xa7"/>
*/

int op_cmpsd(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_CMPSD;

  new->type = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF |
                        ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_XSRC, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_XSRC, new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_YDEST, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_YDEST, new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="op_cmp_xchg" opcode="0xb1"/>
*/

int     op_cmp_xchg(asm_instr *new, u_char *opcode, u_int len,
		    asm_processor *proc)
{
  new->len += 1;
  new->type = ASM_TYPE_COMPARISON | ASM_TYPE_CONTROL;
  new->instr = ASM_CMPXCHG;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#else
  new->op[0].type = ASM_OTYPE_GENERAL;
  new->op[1].type = ASM_OTYPE_ENCODED;
  operand_rmv_rv(new, opcode + 1, len - 1, proc);
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_cwtl" opcode="0x98"/>
*/

int     op_cwtl(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) {
  new->len += 1;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_ARITH;
  if (asm_proc_opsize(proc))
    new->instr = ASM_CBTW;
  else
    new->instr = ASM_CWTL;
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_daa" opcode="0x27"/>
*/

int     op_daa(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_DAA;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_READFLAG | ASM_TYPE_WRITEFLAG;
  new->flagsread = ASM_FLAG_AF | ASM_FLAG_CF;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF | ASM_FLAG_SF | ASM_FLAG_ZF;
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_das" opcode="0x2f"/>
 */

int     op_das(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_DAS;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_READFLAG | ASM_TYPE_WRITEFLAG;
  new->flagsread = ASM_FLAG_AF | ASM_FLAG_CF;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF | ASM_FLAG_SF | ASM_FLAG_ZF;
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_dec_reg" opcode="0x48"/>
  <instruction func="op_dec_reg" opcode="0x49"/>
  <instruction func="op_dec_reg" opcode="0x4a"/>
  <instruction func="op_dec_reg" opcode="0x4b"/>
  <instruction func="op_dec_reg" opcode="0x4c"/>
  <instruction func="op_dec_reg" opcode="0x4d"/>
  <instruction func="op_dec_reg" opcode="0x4e"/>
  <instruction func="op_dec_reg" opcode="0x4f"/>
*/

int op_dec_reg(asm_instr *new, u_char *opcode, u_int len,
               asm_processor *proc)
{
  struct s_modrm        *modrm;

  modrm = (struct s_modrm *) opcode;
  new->ptr_instr = opcode;
  new->instr = ASM_DEC;
  new->len += 1;

  new->type = ASM_TYPE_ARITH | ASM_TYPE_INCDEC | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_OF | ASM_FLAG_PF |
                        ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_OPMOD, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_OPMOD, new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for the enter instruction, opcode 0xc8
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
*/

int op_enter(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->instr = ASM_ENTER;
  new->len += 1;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_TOUCHSP;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,				ASM_OTYPE_IMMEDIATEWORD, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,				ASM_OTYPE_IMMEDIATEWORD, new);
#endif
#else

  new->op[0].type = ASM_OTYPE_IMMEDIATE;
  new->op[0].content = ASM_OP_VALUE;
  new->op[0].len = 2;
  new->op[0].ptr = opcode + 1;

  new->op[0].imm = 0;
  memcpy(&new->op[0].imm, opcode + 1, 2);
  new->len += 2;
#endif
  new->spdiff = -new->op[0].imm;
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_esc0" opcode="0xd8"/>
*/

int op_esc0(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  struct s_modrm        *modrm;

  new->ptr_instr = opcode;
  modrm = (struct s_modrm *) opcode + 1;
  new->len += 1;
  switch(modrm->r) {
  case 0:
    new->instr = ASM_FADD;

    break;
  case 1:
    new->instr = ASM_FMUL;
    break;
  case 2:
    new->instr = ASM_FCOM;
    break;
  case 3:
    new->instr = ASM_FCOMP;
    break;
  case 4:
    new->instr = ASM_FSUB;
    break;
  case 5:
    new->instr = ASM_FSUBR;
    break;
  case 6:
    new->instr = ASM_FDIV;
    break;
  case 7:
    new->instr = ASM_FDIVR;
    break;
  }
  if (modrm->mod < 3)
    {
      #if LIBASM_USE_OPERAND_VECTOR
#if WIP
      new->len += asm_operand_fetch(&new->op[0], opcode + 1,				    ASM_OTYPE_ENCODED, new, 0);
#else
      new->len += asm_operand_fetch(&new->op[0], opcode + 1,				    ASM_OTYPE_ENCODED, new);
#endif
      #else
      new->op[0].type = ASM_OTYPE_FIXED;
      operand_rmv(&new->op[0], opcode + 1, len - 1, proc);
      new->len += new->op[0].len;
      #endif
    }
  else
    {
      new->len += 1;
      switch(modrm->r)
	{
	case 6:
	case 0:
	case 5:
	case 1:
	case 4:
	case 7:
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
	  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED,					new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));

#else
	  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED,					new);
#endif
	  new->op[0].content = ASM_OP_FPU | ASM_OP_BASE;
#if WIP
	  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_FIXED,					new, 0);
#else
	  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_FIXED,					new);
#endif
	  new->op[1].content = ASM_OP_FPU | ASM_OP_SCALE | ASM_OP_BASE;
	  new->op[1].scale = modrm->m;
#else
	  new->op[0].type = ASM_OTYPE_FIXED;
	  new->op[0].content = ASM_OP_FPU | ASM_OP_BASE;
	  new->op[1].type = ASM_OTYPE_FIXED;
	  new->op[1].content = ASM_OP_FPU | ASM_OP_SCALE | ASM_OP_BASE;
	  new->op[1].scale = modrm->m;
#endif
	  break;

	case 2:
	case 3:
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
	  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new,
					asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
						       asm_proc_is_protected(proc) ?
						       ASM_REGSET_R32 : ASM_REGSET_R16));

#else
	  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
#endif
	  new->op[0].content = ASM_OP_FPU | ASM_OP_SCALE | ASM_OP_BASE;
	  new->op[0].scale = modrm->m;
#else
	  new->op[0].type = ASM_OTYPE_FIXED;
	  new->op[0].content = ASM_OP_FPU | ASM_OP_SCALE | ASM_OP_BASE;
	  new->op[0].scale = modrm->m;
#endif
	  break;
	}
    }
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_esc1.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for fpu instruction group 1, opcode 0xd9
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
*/

int op_esc1(asm_instr *new, u_char *opcode, u_int len,
	    asm_processor *proc)
{
  struct s_modrm        *modrm;

  modrm = (struct s_modrm *) opcode + 1;
  new->ptr_instr = opcode;
  new->len += 1;
  if (modrm->mod == 3)
    {
    switch(modrm->r)
      {
      case 0:
	new->instr = ASM_FLD;
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
	new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new, 
				      asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
						     asm_proc_is_protected(proc) ?
						     ASM_REGSET_R32 : ASM_REGSET_R16));
	
#else
	new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED,				      new);
#endif
	new->len += 1;
	new->op[0].content = ASM_OP_FPU | ASM_OP_SCALE | ASM_OP_BASE;
	new->op[0].len = 1;
	new->op[0].scale = modrm->m;
#else
	new->op[0].type = ASM_OTYPE_FIXED;
	new->op[0].content = ASM_OP_FPU | ASM_OP_SCALE | ASM_OP_BASE;
	new->op[0].len = 1;
	new->op[0].scale = modrm->m;
#endif
	break;
      case 1:
	new->instr = ASM_FXCH;
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
	new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED,				      new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));

#else
	new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED,				      new);
#endif
	new->len += 1;
	new->op[0].type = ASM_OTYPE_FIXED;
	new->op[0].len = 1;
	new->op[0].content = ASM_OP_FPU | ASM_OP_SCALE | ASM_OP_BASE;
	new->op[0].scale = modrm->m;
#else
	new->op[0].type = ASM_OTYPE_FIXED;
	new->op[0].len = 1;
	new->op[0].content = ASM_OP_FPU | ASM_OP_SCALE | ASM_OP_BASE;
	new->op[0].scale = modrm->m;
#endif
	break;
      case 2:
	new->instr = ASM_FNOP; break;
      case 4:
	new->len += 1;
	switch(modrm->m) {
	case 0: new->instr = ASM_FCHS; break;
	case 1: new->instr = ASM_FABS; break;
	case 4: new->instr = ASM_FTST; break;
	case 5: new->instr = ASM_FXAM; break;
	default: new->instr = ASM_BAD; break;
	}
	break;
      case 5:
	new->len += 1;
	switch(modrm->m) {
	case 0: new->instr = ASM_FLD1; break;
	case 1: new->instr = ASM_FLDL2T; break;
	case 2: new->instr = ASM_FLDL2E; break;
	case 3: new->instr = ASM_FLDPI; break;
	case 4: new->instr = ASM_FLDLG2; break;
	case 5: new->instr = ASM_FLDLN2; break;
	case 6: new->instr = ASM_FLDZ; break;
	}
	break;
      case 6:
	new->len += 1;
	switch(modrm->m) {
	case 0: new->instr = ASM_F2XM1; break;
	case 1: new->instr = ASM_FYL2X; break;
	case 2: new->instr = ASM_FPTAN; break;
	case 3: new->instr = ASM_FPATAN; break;
	case 4: new->instr = ASM_FXTRACT; break;
	  //case 5: new->instr = ASM_FPREM1; break;
	case 6: new->instr = ASM_FDECSTP; break;
	case 7: new->instr = ASM_FINCSTP; break;
	}
	break;
      case 7:
	new->len += 1;
	switch(modrm->m) {
	case 0: new->instr = ASM_FPREM; break;
	case 1: new->instr = ASM_FYL2XP1; break;
	case 2: new->instr = ASM_FSQRT; break;
	case 3: new->instr = ASM_FSINCOS; break;
	case 4: new->instr = ASM_FRNDINT; break;
	case 5: new->instr = ASM_FSCALE; break;
	  //case 6: new->instr = ASM_SIN; break;
	  //case 7: new->instr = ASM_COS; break;
	}
	break;
      }
    }
  else /* modrm != 3 */
    {
      switch(modrm->r)
	{
	case 0:
	  new->instr = ASM_FLD;
	  break;
	case 1:
	  new->instr = ASM_BAD;
	  break;
	case 2:
	  new->instr = ASM_FST;
	  break;
	case 3:
	  new->instr = ASM_FSTP;
	  break;
	case 4:
	  new->instr = ASM_FLDENV;
	  break;
	case 5:
	  new->instr = ASM_FLDCW;
	  break;
	case 6:
	  if (!(new->prefix & ASM_PREFIX_FWAIT))
	    new->instr = ASM_FNSTENV;
	  else
	    new->instr = ASM_FSTENV;
	  break;
	case 7:
	  if (!(new->prefix & ASM_PREFIX_FWAIT))
	    new->instr = ASM_FNSTCW;
	  else
	    new->instr = ASM_FSTCW;
	  break;
	}
    }
  if (modrm->mod < 3)
    {
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				    new, 0);
#else
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				    new);
#endif
#else
      new->op[0].type = ASM_OTYPE_ENCODED;
      operand_rmv(&new->op[0], opcode + 1, len - 1, proc);
#endif
    }

#if LIBASM_USE_OPERAND_VECTOR
#else
  if (new->op[0].type)
    new->len += new->op[0].len;
  else
    new->len += 1;
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
   <instruction func="op_esc2" opcode="0xda"/>
*/

int op_esc2(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  struct s_modrm        *modrm;

  modrm = (struct s_modrm *) opcode + 1;
  new->ptr_instr = opcode;
  new->len += 1;
  if (modrm->mod == 3)
    switch (modrm->r) {
    case 5: new->instr = ASM_FUCOMPP; break;
    default: new->instr = ASM_BAD; break;
    }
  else
    switch(modrm->r) {
    case 0:
      new->instr = ASM_FIADD;
      break;
    case 1:
      new->instr = ASM_FIMUL;
      break;
    case 2:
      new->instr = ASM_FICOM;
      break;
    case 3:
      new->instr = ASM_FICOMP;
      break;
    case 4:
      new->instr = ASM_FISUB;
      break;
    case 5:
      new->instr = ASM_FISUBR;
      break;
    case 6:
      new->instr = ASM_FIDIV;
      break;
    case 7:
      new->instr = ASM_FIDIVR;
      break;
    }
  if (!(*(opcode + 1) == 0xe9)) {
    #if LIBASM_USE_OPERAND_VECTOR
#if WIP
    new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				  new, 0);
#else
    new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				  new);
#endif
    #else
    new->op[0].type = ASM_OTYPE_ENCODED;
    operand_rmv(&new->op[0], opcode + 1, len - 1, proc);
    new->len += new->op[0].len;
    #endif
  } else
    new->len += 1;
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_esc3" opcode="0xdb"/>
*/

int op_esc3(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  struct s_modrm        *modrm;

  new->ptr_instr = opcode;
  modrm = (struct s_modrm *) opcode + 1;
  new->len += 1;
  switch(modrm->r)
    {
  case 0:
    new->instr = ASM_FILD;
    break;
  case 1:
    new->instr = ASM_BAD;
    break;
  case 2:
    new->instr = ASM_FIST;
    break;
  case 3:
    new->instr = ASM_FISTP;
    break;
  case 4:
    // bad
    break;
  case 5:
    new->instr = ASM_FLD;
    break;
  case 6:

  case 7:
    new->instr = ASM_FSTP;
    break;
  }
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
#else
  new->op[0].type = ASM_OTYPE_ENCODED;
  operand_rmv(&new->op[0], opcode + 1, len - 1, proc);
  new->len += new->op[0].len;
#endif
  return (new->len);
}
/**
 * $Id$
* @file libasm/src/arch/ia32/handlers/op_esc4.c
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler of FPU instruction group esc4 opcode 0xdc
  <instruction func="op_esc4" opcode="0xdc"/>
*/

int op_esc4(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  struct s_modrm        *modrm;

  new->ptr_instr = opcode;
  modrm = (struct s_modrm *) opcode + 1;
  new->len += 1;
  switch(modrm->r)
    {
    case 0:
      new->instr = ASM_FADD;
      break;
    case 1:
      new->instr = ASM_FMUL;
      break;
    case 2:
      new->instr= ASM_FCOM;
      break;
    case 3:
      new->instr = ASM_FCOMP;
      break;
    case 4:
      new->instr = ASM_FSUB;
      break;
    case 5:
      new->instr = ASM_FSUBR;
      break;
    case 6:
      new->instr = ASM_FDIV;
      break;
    case 7:
      new->instr = ASM_FDIVR;
      break;
    }

  if (modrm->mod == 3)
    {
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_FIXED, new, 
				    asm_fixed_pack(0, ASM_OP_FPU | ASM_OP_BASE | ASM_OP_SCALE, 
						   modrm->m, 0));
      
#else
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_FIXED, new);
#endif
      new->op[0].type = ASM_OTYPE_FIXED;
      new->op[0].content = ASM_OP_FPU | ASM_OP_BASE | ASM_OP_SCALE;
      new->op[0].len = 1;
      new->op[0].scale = modrm->m;
#if WIP
      new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_FIXED, 0,
				    asm_fixed_pack(0, ASM_OP_FPU | ASM_OP_BASE, 0,
						   asm_proc_is_protected(proc) ?
						   ASM_REGSET_R32 : ASM_REGSET_R16));
#else
      new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_FIXED, new);
#endif
      new->op[1].type = ASM_OTYPE_FIXED;
      new->op[1].content = ASM_OP_FPU | ASM_OP_BASE;
      new->len += 1;
#else
      new->op[0].type = ASM_OTYPE_FIXED;
      new->op[0].content = ASM_OP_FPU | ASM_OP_BASE | ASM_OP_SCALE;
      new->op[0].len = 1;
      new->op[0].scale = modrm->m;
      new->op[1].type = ASM_OTYPE_FIXED;
      new->op[1].content = ASM_OP_FPU | ASM_OP_BASE;
#endif
    }
  else
    {
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED, new, 0);
#else
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				    new);
#endif
#else
      new->op[0].type = ASM_OTYPE_FIXED;
      operand_rmv(&new->op[0], opcode + 1, len - 1, proc);
#endif
    }
#if LIBASM_USE_OPERAND_VECTOR
#else
  if (new->op[0].type)
    new->len += new->op[0].len;
#endif
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_esc5.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for esc5 instruction group, opcode 0xdd
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
*/

int op_esc5(asm_instr *new, u_char *opcode, u_int len,
	    asm_processor *proc)
{
  struct s_modrm        *modrm;
  new->ptr_instr = opcode;

  modrm = (struct s_modrm *) opcode + 1;
  new->len += 1;
  if (modrm->mod == 3)
    {
      new->len += 1;
      switch(modrm->r)
	{
	case 3:
	  new->instr = ASM_FSTP;
	  break;
	case 4:
	  new->instr = ASM_FUCOM;
	  break;
	case 5:
	  new->instr = ASM_FUCOMP;
	  break;
	default:
	  new->instr = ASM_BAD;
	  break;
	}
    }
  else
    switch (modrm->r) {
    case 0:
      new->instr = ASM_FLD;
      break;
    case 1:
      new->instr = ASM_BAD;
      break;
    case 2:
      new->instr = ASM_FST;
      break;
    case 3:
      new->instr = ASM_FSTP;
      break;
    case 4:
      new->instr = ASM_BAD; // ASM_FRSTOR;
      break;
    case 5:
      new->instr = ASM_BAD; // ;
      break;
    case 6:
      if (!(new->prefix & ASM_PREFIX_FWAIT))
	new->instr = ASM_FNSAVE;
      else
	new->instr = ASM_FSAVE;
      break;
    case 7:
      if (!(new->prefix & ASM_PREFIX_FWAIT))
	new->instr = ASM_FNSAVE;
      else
	new->instr = ASM_FSAVE;
      break;
    }

  if (modrm->mod == 3)
    {
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_FPU | ASM_OP_BASE | ASM_OP_SCALE, 
					       modrm->m, 0));

#else
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_FIXED, new);
#endif
      new->op[0].content = ASM_OP_FPU | ASM_OP_BASE | ASM_OP_SCALE;
      new->op[0].len = 1;
      new->op[0].ptr = opcode + 1;
      new->op[0].scale = modrm->m;
#else
      new->op[0].type = ASM_OTYPE_FIXED;
      new->op[0].content = ASM_OP_FPU | ASM_OP_BASE | ASM_OP_SCALE;
      new->op[0].len = 1;
      new->op[0].ptr = opcode + 1;
      new->op[0].scale = modrm->m;
#endif
    }
  else
    {
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				    new, 0);
#else
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				    new);
#endif
#else
      new->op[0].type = ASM_OTYPE_ENCODED;
      operand_rmv(&new->op[0], opcode + 1, len - 1, proc);
#endif
    }
#if LIBASM_USE_OPERAND_VECTOR
#else
  if (new->op[0].type)
    new->len += new->op[0].len;
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_esc6" opcode="0xde"/>
 */

int op_esc6(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  struct s_modrm        *modrm;
  new->ptr_instr = opcode;

  modrm = (struct s_modrm *) opcode + 1;
  new->len += 1;
  if (modrm->mod <= 2) {
    switch(modrm->r) {
      case 0:
        new->instr = ASM_FIADD;
        break;
      case 1:
        new->instr = ASM_FIMUL;
        break;
      case 2:
        new->instr = ASM_FICOM;
        break;
      case 3:
        new->instr = ASM_FICOMP;
        break;
      case 4:
        new->instr = ASM_FISUB;
        break;
      case 5:
        new->instr = ASM_FISUBR;
        break;
      case 6:
        new->instr = ASM_FIDIV;

        break;
      case 7:
        new->instr = ASM_FIDIVR;
        break;
      }
    } else {
      switch(modrm->r) {
      case 0: new->instr = ASM_FADDP; break;
      case 1:
        new->instr = ASM_FMULP;
        break;
      case 2:
        new->instr = ASM_FCOMPS;
        break;
      case 3: new->instr = ASM_FCOMPP;
        break;
      case 4: new->instr = ASM_FSUBP;
        break;
      case 5: new->instr = ASM_FSUBRP;
        break;
      case 6:
        switch(modrm->m) {
        case 3: case 5: case 2: case 4: case 6: case 1:
	  new->instr = ASM_FDIVP; break;
        default: case 0: new->instr = ASM_FDIVP; break;
        }
        break;
      case 7:
        switch(modrm->m) {
        case 3: new->instr = ASM_FDIVR; break;
        default: new->instr = ASM_FDIV; break;
        }
        break;
      }
    }

    if (!(*(opcode + 1) == 0xd9)) {
      #if LIBASM_USE_OPERAND_VECTOR
#if WIP
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_FIXED,				    new,
				asm_fixed_pack(0, ASM_OP_FPU | ASM_OP_BASE | ASM_OP_SCALE,
					       modrm->m,
					       0));

#else
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_FIXED,				    new);
#endif
      new->op[0].content = ASM_OP_FPU | ASM_OP_BASE | ASM_OP_SCALE;
      new->op[0].len = 1;
      new->op[0].scale = modrm->m;
#if WIP
      new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_FIXED,				    new,
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));

#else
      new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_FIXED,				    new);
#endif
      new->op[1].content = ASM_OP_FPU | ASM_OP_BASE;
      new->op[1].len = 0;
      #else
      new->op[0].type = ASM_OTYPE_FIXED;
      new->op[0].content = ASM_OP_FPU | ASM_OP_BASE | ASM_OP_SCALE;
      new->op[0].len = 1;
      new->op[0].scale = modrm->m;
      new->op[1].type = ASM_OTYPE_FIXED;
      new->op[1].content = ASM_OP_FPU | ASM_OP_BASE;
      new->op[1].len = 0;
#endif
    } else
      new->len++;
    #if LIBASM_USE_OPERAND

    #else
    if (new->op[0].type)
      new->len += new->op[0].len;
#endif
  return (new->len);
}
/**
 * $Id$
 * @param 
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for fpu instruction for opcode 0xdf
 *
 * @param instr Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 *
 <instruction func="op_esc7" opcode="0xdf"/>
*/

int op_esc7(asm_instr *instr, u_char *opcode, u_int len, asm_processor *proc)
{
  struct s_modrm        *modrm;

  modrm = (struct s_modrm *) opcode + 1;
  instr->ptr_instr = opcode;
  instr->len += 1;
  if (*(opcode + 1) == 0xe0) 
  {
    if (!(instr->prefix & ASM_PREFIX_FWAIT))
      instr->instr = ASM_FNSTSW;
    else
      instr->instr = ASM_FSTSW;
    instr->op[0].type = ASM_OTYPE_FIXED;
    instr->op[0].content = ASM_OP_BASE;
    instr->op[0].regset = ASM_REGSET_R16;
    instr->op[0].baser = ASM_REG_EAX;
  } 
  else
  switch (modrm->r) 
  {
    case 0:    
    instr->instr = ASM_FILD;
    break;
    case 1:
    // bad instr->instr = ASM_;
    break;
    case 2:
    instr->instr = ASM_FIST;
    break;
    case 3:
    instr->instr = ASM_FISTP;
    break;
    case 4:
    instr->instr = ASM_FBLD;
    break;
    case 5:
    instr->instr = ASM_FILD;
    break;
    case 6:
    instr->instr = ASM_FBSTP;
    break;
    case 7:
    instr->instr = ASM_FISTP;
    break;
  }
  if (*(opcode + 1) != 0xe0) {
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
    instr->len += asm_operand_fetch(&instr->op[0], opcode + 1, ASM_OTYPE_ENCODED,
				  instr, 0);
#else
    instr->len += asm_operand_fetch(&instr->op[0], opcode + 1, ASM_OTYPE_ENCODED,
				  instr);
#endif
#else
    instr->op[0].type = ASM_OTYPE_ENCODED;
    operand_rmv(&instr->op[0], opcode + 1, len - 1, proc);
    instr->len += instr->op[0].len;
#endif
  } else
  instr->len++;
  return (instr->len);
}
/** 
 * $Id$
* @file libasm/src/arch/ia32/handlers/op_fwait.c
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Instruction handler for opcode 0x9b.
 * This opcode is the for fwait prefix opcode.
 * Disassembling is forwarded on next byte after execution of this
 * handler.
 * 
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to buffer to disassemble.
 * @param len Length of buffer to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of disassembled instruction.
 */

int op_fwait(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  if (!new->ptr_prefix)
    new->ptr_instr = opcode;
  new->prefix |= ASM_PREFIX_FWAIT;
  return (proc->fetch(new, opcode + 1, len - 1, proc));
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

int     op_group6(asm_instr *new, u_char *opcode, u_int len,
		  asm_processor *proc)
{
  struct s_modrm        *modrm;

  new->len += 1;
  modrm = (struct s_modrm *) opcode + 1;
  switch(modrm->r) {
  case 0:
    new->instr = ASM_SLDT;
    break;
  case 1:
    new->instr = ASM_STR;
    break;
  case 2:
    new->instr = ASM_LLDT;
    break;
  case 3:
    new->instr = ASM_LTR;
    break;
  case 4:
  case 5:
  case 6:
  case 7:
    break;
  }

  #if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
  new->op[0].regset = ASM_REGSET_R16;
  #else
  new->op[0].type = ASM_OTYPE_ENCODED;
  new->op[0].size = ASM_OSIZE_VECTOR;
  operand_rmv(&new->op[0], opcode + 1, len - 1, proc);
  new->len += new->op[0].len;
  new->op[0].regset = ASM_REGSET_R16;
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

int     op_group7(asm_instr *new, u_char *opcode, u_int len,
		  asm_processor *proc)
{
  struct s_modrm        *modrm;

  new->len += 1;
  modrm = (struct s_modrm *) opcode + 1;

  switch(modrm->r)
    {
    case 0:
      new->instr = ASM_SGDT;
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				    new, 0);
#else
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				    new);
#endif
#else
      new->op[0].type = ASM_OTYPE_ENCODED;
      operand_rmv(&new->op[0], opcode + 1, len - 1, proc);
      new->len += new->op[0].len;
#endif
      break;
    case 1:
      new->instr = ASM_SIDT;
      break;
    case 2:
      new->instr = ASM_LGDT;
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				    new, 0);
#else
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				    new);
#endif
#else
      new->op[0].type = ASM_OTYPE_ENCODED;
      operand_rmv(&new->op[0], opcode + 1, len - 1, proc);
      new->len += new->op[0].len;
#endif
      break;
    case 3:
      new->instr = ASM_LIDT;
#if LIBASM_USE_OPERAND_VECTOR
#if WIP
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				    new, 0);
#else
      new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				    new);
#endif
#else
      new->op[0].type = ASM_OTYPE_ENCODED;
      operand_rmv(&new->op[0], opcode + 1, len - 1, proc);
      new->len += new->op[0].len;
#endif
      break;
    case 4:
      break;
    case 5:
      new->instr = ASM_BAD;
      break;
    case 6:

      break;
    case 7:

      break;
    }
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_hlt" opcode="0xf4"/>
*/

int op_hlt(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_HLT;
  new->type = ASM_TYPE_STOP;
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_immed_rmb_ib" opcode="0x80"/>
  <instruction func="op_immed_rmb_ib" opcode="0x82"/>
*/

int op_immed_rmb_ib(asm_instr *new, u_char *opcode, u_int len,
                    asm_processor *proc)
{
  int                   olen;
  struct s_modrm        *modrm;

  new->ptr_instr = opcode;
  modrm = (struct s_modrm *) opcode + 1;
  new->len+= 1;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_OF |
                        ASM_FLAG_PF | ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  new->len += (olen = asm_operand_fetch(&new->op[0], opcode + 1,                                        ASM_OTYPE_ENCODEDBYTE, new, 0));
#else
  new->len += (olen = asm_operand_fetch(&new->op[0], opcode + 1,                                        ASM_OTYPE_ENCODEDBYTE, new));
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1 + olen,                                ASM_OTYPE_IMMEDIATEBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1 + olen,                                ASM_OTYPE_IMMEDIATEBYTE, new);
#endif

  switch(modrm->r)
    {
    case 0:
      new->instr = ASM_ADD;
      break;
    case 1:
      new->instr = ASM_ORB;
      new->flagswritten ^= ASM_FLAG_AF;
      new->op[1].imm &= 0xff;
      break;
    case 2:
      new->instr = ASM_ADC;
      new->type |= ASM_TYPE_READFLAG;
      new->flagsread = ASM_FLAG_CF;
      break;
    case 3:
      new->instr = ASM_SBB;
      new->type |= ASM_TYPE_READFLAG;
      new->flagsread = ASM_FLAG_CF;
      break;
    case 4:
      new->instr = ASM_AND;
      new->flagswritten ^= ASM_FLAG_AF;
      new->op[1].imm &= 0xff;
      break;
    case 5:
      new->instr = ASM_SUB;
      if (new->op[0].content == ASM_OP_BASE &&
            new->op[0].baser == ASM_REG_ESP)
        new->type |= ASM_TYPE_EPILOG;
      break;
    case 6:
      new->instr = ASM_XOR;
      new->flagswritten ^= ASM_FLAG_AF;
      break;
    case 7:
      new->instr = ASM_CMP;
      new->type = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
      new->op[1].imm &= 0xff;
      break;
    }

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_immed_rmv_ib" opcode="0x83"/>
*/

int op_immed_rmv_ib(asm_instr *new, u_char *opcode, u_int len,
                    asm_processor *proc)
{
  int                   olen;
  struct s_modrm        *modrm;

  modrm = (struct s_modrm *) (opcode + 1);
  new->ptr_instr = opcode;
  new->len += 1;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_OF |
                        ASM_FLAG_PF | ASM_FLAG_SF | ASM_FLAG_ZF;

  switch(modrm->r) {
    case 0:
      new->instr = ASM_ADD;
      break;
    case 1:
      new->instr = ASM_OR;
      new->flagswritten ^= ASM_FLAG_AF;
      break;
    case 2:
      new->instr = ASM_ADC;
      new->type |= ASM_TYPE_READFLAG;
      new->flagsread = ASM_FLAG_CF;
      break;
    case 3:
      new->instr = ASM_SBB;
      new->type |= ASM_TYPE_READFLAG;
      new->flagsread = ASM_FLAG_CF;
      break;
    case 4:
      new->instr = ASM_AND;
      new->flagswritten ^= ASM_FLAG_AF;
      break;
    case 5:
      new->instr = ASM_SUB;
      if (new->op[0].content == ASM_OP_BASE &&
            new->op[0].baser == ASM_REG_ESP)
        new->type |= ASM_TYPE_EPILOG;
      break;
    case 6:
      new->instr = ASM_XOR;
      new->flagswritten ^= ASM_FLAG_AF;
      break;
    case 7:
      new->instr = ASM_CMP;
      new->type = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
      break;
    }

#if WIP
  new->len += (olen = asm_operand_fetch(&new->op[0], opcode + 1,                                        ASM_OTYPE_ENCODED, new, 0));
#else
  new->len += (olen = asm_operand_fetch(&new->op[0], opcode + 1,                                        ASM_OTYPE_ENCODED, new));
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1 + olen,                                ASM_OTYPE_IMMEDIATEBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1 + olen,                                ASM_OTYPE_IMMEDIATEBYTE, new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_immed_rmv_iv" opcode="0x81"/>
 */

int op_immed_rmv_iv(asm_instr *new, u_char *opcode, u_int len,
                    asm_processor *proc)
{
  int                   olen;
  struct s_modrm        *modrm;
  new->ptr_instr = opcode;

  modrm = (struct s_modrm *) opcode + 1;
  new->len += 1;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_OF |
                        ASM_FLAG_PF | ASM_FLAG_SF | ASM_FLAG_ZF;

  switch(modrm->r) {
    case 0:
      new->instr = ASM_ADD;
      break;
    case 1:
      new->instr = ASM_OR;
      new->flagswritten ^= ASM_FLAG_AF;
      break;
    case 2:
      new->instr = ASM_ADC;
      new->type |= ASM_TYPE_READFLAG;
      new->flagsread = ASM_FLAG_CF;
      break;
    case 3:
      new->instr = ASM_SBB;
      new->type |= ASM_TYPE_READFLAG;
      new->flagsread = ASM_FLAG_CF;
      break;
    case 4:
      new->instr = ASM_AND;
      new->flagswritten ^= ASM_FLAG_AF;
      break;
    case 5:
      new->instr = ASM_SUB;
      if (new->op[0].content == ASM_OP_BASE &&
            new->op[0].baser == ASM_REG_ESP)
        new->type |= ASM_TYPE_EPILOG;
      break;
    case 6:
      new->instr = ASM_XOR;
      new->flagswritten ^= ASM_FLAG_AF;
      break;
    case 7:
      new->instr = ASM_CMP;
      new->type = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
      break;
  }

#if WIP
  new->len += (olen = asm_operand_fetch(&new->op[0], opcode + 1,                                        ASM_OTYPE_ENCODED, new, 0));
#else
  new->len += (olen = asm_operand_fetch(&new->op[0], opcode + 1,                                        ASM_OTYPE_ENCODED, new));
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1 + olen,                                ASM_OTYPE_IMMEDIATE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1 + olen,                                ASM_OTYPE_IMMEDIATE, new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_imul_gv_ev_ib" opcode="0x6b"/>
*/

int     op_imul_gv_ev_ib(asm_instr *new, u_char *opcode, u_int len,
			 asm_processor *proc)
{
  int	olen;
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_IMUL;

  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_OF | ASM_FLAG_CF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL, new);
#endif
#if WIP
  new->len += (olen = asm_operand_fetch(&new->op[1], opcode + 1,                                        ASM_OTYPE_ENCODED, new, 0));
#else
  new->len += (olen = asm_operand_fetch(&new->op[1], opcode + 1,                                        ASM_OTYPE_ENCODED, new));
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[2], opcode + 1 + olen,                                ASM_OTYPE_IMMEDIATEBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[2], opcode + 1 + olen,                                ASM_OTYPE_IMMEDIATEBYTE, new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_imul_rv_rmv_iv.c
 * @brief Handler for instruction op_imul_rv_rmv_iv opcode 0x69
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Handler for instruction op_imul_rv_rmv_iv opcode 0x69
 *
 *
 */

int     op_imul_rv_rmv_iv(asm_instr *new, u_char *opcode, u_int len,
			  asm_processor *proc)
{
  int		olen;
  new->instr = ASM_IMUL;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->ptr_instr = opcode;
  new->len += 1;
  new->flagswritten = ASM_FLAG_OF | ASM_FLAG_CF;


#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL, new);
#endif
#if WIP
  new->len += (olen = asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED, new, 0));
#else
  new->len += (olen = asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED, new));
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[2], opcode + 1 + olen, ASM_OTYPE_IMMEDIATE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[2], opcode + 1 + olen, ASM_OTYPE_IMMEDIATE, new);
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_in_al_dx" opcode="0xec"/>
 */

int     op_in_al_dx(asm_instr *new, u_char *opcode, u_int len,
                         asm_processor *proc) {
  new->len += 1;
  new->instr = ASM_IN;
  new->type = ASM_TYPE_LOAD | ASM_TYPE_IO;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new,
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_AL,
					       ASM_REGSET_R8));
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
#endif

  new->ptr_instr = opcode;
  new->op[0].content = ASM_OP_BASE;
  new->op[0].regset = ASM_REGSET_R8;
  new->op[0].baser = ASM_REG_AL;

#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));

#else
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_FIXED, new);
#endif

  new->op[1].content = ASM_OP_BASE | ASM_OP_REFERENCE;
  new->op[1].regset = ASM_REGSET_R16;
  new->op[1].baser = ASM_REG_DX;

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_in_al_ref_ib.c
 *
 * @ingroup IA32_instrs
 * @brief Handler for instruction in al,ib opcode 0xe4
 
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Handler for instruction in al,ib opcode 0xe4
 *
  <instruction func="op_in_al_ref_ib" opcode="0xe4"/>
*/

int op_in_al_ref_ib(asm_instr *new, u_char *opcode, u_int len,
                    asm_processor *proc)
{
  new->instr = ASM_IN;
  new->ptr_instr = opcode;
  new->len += 1;
  new->type = ASM_TYPE_LOAD | ASM_TYPE_IO;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_AL,
					       ASM_REGSET_R8));

#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_FIXED, new);
#endif
  new->op[0].content = ASM_OP_BASE;
  new->op[0].regset = ASM_REGSET_R8;
  new->op[0].baser = ASM_REG_AL;
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_IMMEDIATEBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_IMMEDIATEBYTE, new);
#endif

  new->op[0].type = ASM_OTYPE_FIXED;
  new->op[0].content = ASM_OP_BASE;
  new->op[0].regset = ASM_REGSET_R8;
  new->op[0].baser = ASM_REG_AL;

  new->op[1].type = ASM_OTYPE_IMMEDIATE;
  new->op[1].content = ASM_OP_VALUE;

  new->len += 1;
  new->op[1].imm = 0;
  memcpy(&new->op[1].imm, opcode + 1, 1);

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_incdec_rmb" opcode="0xfe"/>
*/

int op_incdec_rmb(asm_instr *new, u_char *opcode, u_int len,
                  asm_processor *proc)
{
  struct s_modrm        *modrm;

  new->ptr_instr = opcode;
  modrm = (struct s_modrm *) opcode + 1;
  new->len += 1;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_INCDEC | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_OF | ASM_FLAG_PF |
                        ASM_FLAG_SF | ASM_FLAG_ZF;

  switch(modrm->r) {
    case 0:
      new->instr = ASM_INC;
      break;
    case 1:
      new->instr = ASM_DEC;
      break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
      break;
    default:
      break;
  }

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_inc_reg" opcode="0x40"/>
  <instruction func="op_inc_reg" opcode="0x41"/>
  <instruction func="op_inc_reg" opcode="0x42"/>
  <instruction func="op_inc_reg" opcode="0x43"/>
  <instruction func="op_inc_reg" opcode="0x44"/>
  <instruction func="op_inc_reg" opcode="0x45"/>
  <instruction func="op_inc_reg" opcode="0x46"/>
  <instruction func="op_inc_reg" opcode="0x47"/>
*/


int op_inc_reg(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  struct s_modrm        *modrm;

  modrm = (struct s_modrm *) opcode;
  new->len += 1;
  new->instr = ASM_INC;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_INCDEC | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_OF | ASM_FLAG_PF |
                        ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_OPMOD, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_OPMOD, new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_indir_rmv" opcode="0xff"/>
*/

int op_indir_rmv(asm_instr *new, u_char *opcode, u_int len,
		 asm_processor *proc)
{
  struct s_modrm        *modrm;

  new->ptr_instr = opcode;
  modrm = (struct s_modrm *) (opcode + 1);
  new->len += 1;
  switch(modrm->r) {
  case 0:
    new->instr = ASM_INC;
    new->type = ASM_TYPE_INCDEC | ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
    new->flagswritten = ASM_FLAG_AF | ASM_FLAG_OF | ASM_FLAG_PF |
                        ASM_FLAG_SF | ASM_FLAG_ZF;
    new->op[0].type = ASM_OTYPE_ENCODED;
    new->op[0].size = ASM_OSIZE_VECTOR;
    break;
  case 1:
    new->instr = ASM_DEC;
    new->type = ASM_TYPE_INCDEC | ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
    new->flagswritten = ASM_FLAG_AF | ASM_FLAG_OF | ASM_FLAG_PF |
                        ASM_FLAG_SF | ASM_FLAG_ZF;
    new->op[0].type = ASM_OTYPE_ENCODED;
    new->op[0].size = ASM_OSIZE_VECTOR;
    break;
  case 2:
    new->type = ASM_TYPE_CALLPROC | ASM_TYPE_TOUCHSP;
    new->spdiff = -4;
    new->instr = ASM_CALL;
    new->op[0].type = ASM_OTYPE_MEMORY;
    break;
  case 3:
    new->type = ASM_TYPE_CALLPROC | ASM_TYPE_TOUCHSP;
    new->instr = ASM_CALL;
    new->op[0].type = ASM_OTYPE_MEMORY;

    break;
  case 4:
    new->type = ASM_TYPE_BRANCH;
    new->instr = ASM_BRANCH;
    new->op[0].type = ASM_OTYPE_MEMORY;
    break;
  case 5:
    new->type = ASM_TYPE_BRANCH;
    new->instr = ASM_BRANCH;
    new->op[0].type = ASM_OTYPE_MEMORY;
    break;
  case 6:
    new->instr = ASM_PUSH;
    new->type = ASM_TYPE_TOUCHSP | ASM_TYPE_STORE;
    new->op[0].type = ASM_OTYPE_ENCODED;
    new->op[0].size = ASM_OSIZE_VECTOR;
    break;
  case 7:
    new->instr = ASM_BAD;
    new->op[0].type = ASM_OTYPE_ENCODED;
    new->op[0].size = ASM_OSIZE_VECTOR;
    break;
  default:
    break;
  } /* switch */
  if ((new->op[0].type == ASM_OTYPE_ENCODED) ||
      (new->op[0].type == ASM_OTYPE_MEMORY)) {
#if WIP
    new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				  new, 0);
#else
    new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,				  new);
#endif
    if (new->op[0].type == ASM_OTYPE_MEMORY)
      new->op[0].content |= ASM_OP_ADDRESS;
  }
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction in eax,dx opcode 0xed
 * <instruction func="op_in_eax_dx" opcode="0xed"/>
 */

int op_in_eax_dx(asm_instr *new, u_char *opcode, u_int len,
                 asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_IN;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_LOAD | ASM_TYPE_IO;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new,
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));

#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
#endif
  new->op[0].content = ASM_OP_BASE;
  new->op[0].regset = ASM_REGSET_R32;
  new->op[0].baser = ASM_REG_EAX;
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_FIXED, new,
				asm_fixed_pack(0, ASM_OP_BASE | ASM_OP_REFERENCE, ASM_REG_DX,
					       ASM_REGSET_R16));

#else
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_FIXED, new);
#endif
  new->op[1].regset = ASM_REGSET_R16;
  new->op[1].baser = ASM_REG_DX;
  new->op[1].content = ASM_OP_BASE | ASM_OP_REFERENCE;

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_in_eax_ref_ib" opcode="0xe5"/>
*/

int op_in_eax_ref_ib(asm_instr *new, u_char *opcode, u_int len,
		     asm_processor *proc)
{
  new->instr = ASM_IN;
  new->ptr_instr = opcode;
  new->len += 1;
  new->type = ASM_TYPE_LOAD | ASM_TYPE_IO;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_FIXED, new, 
								asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));

#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_FIXED, new);
#endif
  new->op[0].content = ASM_OP_BASE | ASM_OP_FIXED;
  new->op[0].baser = ASM_REG_EAX;
  new->op[0].regset = asm_proc_opsize(proc) ?
    ASM_REGSET_R16 : ASM_REGSET_R32;
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_IMMEDIATEBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_IMMEDIATEBYTE, new);
#endif
  new->op[1].content = ASM_OP_REFERENCE | ASM_OP_VALUE;

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_insb" opcode="0x6b"/>
*/

int     op_insb(asm_instr *new, u_char *opcode, u_int len,
		asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_INSB;
  new->ptr_instr = opcode;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_YDEST, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_YDEST, new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_BASE | ASM_OP_REFERENCE, ASM_REG_DX,
					       ASM_REGSET_R16));
  
#else
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_FIXED, new);
#endif
  new->op[1].content = ASM_OP_BASE | ASM_OP_REFERENCE;
  new->op[1].regset = ASM_REGSET_R16;
  new->op[1].baser = ASM_REG_EDX;
#else
  new->op[1].type = ASM_OTYPE_FIXED;
  new->op[1].content = ASM_OP_BASE | ASM_OP_REFERENCE;
  new->op[1].regset = ASM_REGSET_R16;
  new->op[1].baser = ASM_REG_EDX;

  new->op[0].type = ASM_OTYPE_YDEST;
  new->op[0].content = ASM_OP_BASE | ASM_OP_REFERENCE;
  new->op[0].prefix = ASM_PREFIX_DS;
  new->op[0].baser = ASM_REG_EDI;
  new->op[0].regset = asm_proc_addsize(proc) ? ASM_REGSET_R16 :
    ASM_REGSET_R32;
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_insw" opcode="0x6d"/>
  <instruction func="op_insd" opcode="0x6d"/>
*/

int     op_insw(asm_instr *new, u_char *opcode, u_int len,
		asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;

  if (!asm_proc_opsize(proc))
    new->instr = ASM_INSW;
  else
    new->instr = ASM_INSD;
  new->ptr_instr = opcode;

#if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_YDEST, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_YDEST, new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_FIXED, new,
				asm_fixed_pack(0, ASM_OP_BASE | ASM_OP_REFERENCE, ASM_REG_DX,
					       ASM_REGSET_R16));

#else
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_FIXED, new);
#endif
  new->op[1].content = ASM_OP_BASE | ASM_OP_REFERENCE;
  new->op[1].regset = ASM_REGSET_R16;
  new->op[1].baser = ASM_REG_DX;
#else
  new->op[0].type = ASM_OTYPE_YDEST;
  new->op[0].content = ASM_OP_BASE | ASM_OP_REFERENCE;
  new->op[0].baser = ASM_REG_EDI;
  new->op[0].prefix = ASM_PREFIX_DS;
  new->op[0].regset = asm_proc_addsize(proc) ? ASM_REGSET_R16 :
    ASM_REGSET_R32;

  new->op[1].type = ASM_OTYPE_FIXED;
  new->op[1].content = ASM_OP_BASE | ASM_OP_REFERENCE;
  new->op[1].regset = ASM_REGSET_R16;
  new->op[1].baser = ASM_REG_DX;

#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_lock" opcode="0xf1"/>
*/

int op_int1(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_INT1;
  new->type = ASM_TYPE_INT | ASM_TYPE_TOUCHSP;
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_int_3" opcode="0xcc"/>
*/

int op_int_3(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_INT3;
  new->type = ASM_TYPE_INT | ASM_TYPE_TOUCHSP;
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_int_ib" opcode="0xcd"/>
*/

int op_int_ib(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->instr = ASM_INT;
  new->type = ASM_TYPE_INT | ASM_TYPE_TOUCHSP;
  new->len += 1;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,                                ASM_OTYPE_IMMEDIATEBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,                                ASM_OTYPE_IMMEDIATEBYTE, new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction opcode="0xce" func="op_into"/>
*/

int op_into(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_INTO;
  new->type = ASM_TYPE_INT | ASM_TYPE_TOUCHSP | ASM_TYPE_READFLAG | ASM_TYPE_BITTEST;
  new->flagsread = ASM_FLAG_OF;
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_iret.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 *
 * <instruction opcode="0xcf" func="op_iret"/>
 */

int op_iret(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_IRET;
  new->type = ASM_TYPE_INT | ASM_TYPE_TOUCHSP | ASM_TYPE_RETPROC |
                ASM_TYPE_READFLAG;
  new->flagsread = ASM_FLAG_NT | ASM_FLAG_VM;
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_ja" opcode="0x77"/>
*/

int  op_ja(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  new->instr = ASM_BRANCH_U_GREATER;
  new->ptr_instr = opcode;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_jae" opcode="0x73"/>
*/


int  op_jae(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  new->instr = ASM_BRANCH_U_GREATER_EQUAL;
  new->ptr_instr = opcode;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_jb" opcode="0x72"/>
*/


int  op_jb(asm_instr *new, u_char *opcode, u_int len,
           asm_processor *proc)
{
  new->len += 1;
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  new->instr = ASM_BRANCH_U_LESS;
  new->ptr_instr = opcode;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_jbe" opcode="0x76"/>
*/

int  op_jbe(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  new->instr = ASM_BRANCH_U_LESS_EQUAL;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_je" opcode="0x74"/>
*/


int  op_je(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_BRANCH_EQUAL;
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  new->ptr_instr = opcode;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_je_cxz" opcode="0xe3"/>
 */

int op_je_cxz(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  new->instr = ASM_BRANCH_CXZ;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_jg" opcode="0x7f"/>
*/

int  op_jg(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  new->instr = ASM_BRANCH_S_GREATER;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_jge" opcode="0x7d"/>
*/

int  op_jge(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;

  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  new->instr = ASM_BRANCH_S_GREATER_EQUAL;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_jl" opcode="0x7c"/>
*/

int  op_jl(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  new->instr = ASM_BRANCH_S_LESS;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_jle" opcode="0x7e"/>
*/

int  op_jle(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  new->instr = ASM_BRANCH_S_LESS_EQUAL;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_jmp_ap" opcode="0xea"/>
 */

int     op_jmp_ap(asm_instr *new, u_char *opcode, u_int len,
                  asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->instr = ASM_LBRANCH;
  new->len += 1;
  new->type = ASM_TYPE_BRANCH;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ADDRESS, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ADDRESS, new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_jmp_ib" opcode="0xeb"/>
 */

int op_jmp_ib(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->instr = ASM_BRANCH;

  new->type = ASM_TYPE_BRANCH;
  new->ptr_instr = opcode;
  new->len += 1;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_jmp_iv" opcode="0xe9"/>
 */

int op_jmp_iv(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->instr = ASM_BRANCH;
  new->type = ASM_TYPE_BRANCH;
  new->ptr_instr = opcode;
  new->len += 1;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_jne" opcode="0x75"/>
*/


int  op_jne(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  new->instr = ASM_BRANCH_NOT_EQUAL;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_jno" opcode="0x71"/>
*/


int  op_jno(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  new->instr = ASM_BRANCH_NOT_OVERFLOW;
  new->ptr_instr = opcode;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_JUMP, new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_jnp" opcode="0x7b"/>
*/

int  op_jnp(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  new->instr = ASM_BRANCH_NOT_PARITY;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_jns" opcode="0x79"/>
*/

int  op_jns(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  new->instr = ASM_BRANCH_NOT_SIGNED;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_jo.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Instructiono jo handler for opcode 0x70
 * <instruction func="op_jo" opcode="0x70"/>
 */

int  op_jo(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  new->instr = ASM_BRANCH_OVERFLOW;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_jp" opcode="0x7a"/>
*/

int  op_jp(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  new->instr = ASM_BRANCH_PARITY;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_js" opcode="0x78"/>
*/

int  op_js(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  new->instr = ASM_BRANCH_SIGNED;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_lahf.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for lahf instruction opcode 0x9f
 *
  <instruction func="op_lahf" opcode="0x9f"/>
*/

int op_lahf(asm_instr *new, u_char *opcode, u_int len,
            asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_LAHF;
  new->type = ASM_TYPE_READFLAG;
  new->flagsread = ASM_FLAG_SF | ASM_FLAG_ZF | ASM_FLAG_AF |
                        ASM_FLAG_PF | ASM_FLAG_CF;
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction lds opcode 0xc5
 *
 <instruction func="op_lds_rm_rmp" opcode="0xc5"/>
*/

int op_lds_rm_rmp(asm_instr *new, u_char *opcode, u_int len,
		  asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->instr = ASM_LDS;
  new->len += 1;
  new->type = ASM_TYPE_LOAD;
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_lea_rv_m.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 *
 *
  <instruction func="op_lea_rv_m" opcode="0x8d"/>
 */

int op_lea_rv_m(asm_instr *new, u_char *opcode, u_int len,
                asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_LEA;
  new->type = ASM_TYPE_ARITH;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,                                new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,                                new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_leave.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for the leave instruction opcode 0xc9
 * @param new Pointer to the instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
*/

int op_leave(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_TOUCHSP;
  new->spdiff = 4;
  new->instr = ASM_LEAVE;
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_les_rm_rmp" opcode="0xc4"/>
*/

int op_les_rm_rmp(asm_instr *new, u_char *opcode, u_int len,
		  asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->instr = ASM_LES;
  new->len += 1;
  new->type = ASM_TYPE_LOAD;
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_lock" opcode="0xf0"/>
*/

int op_lock(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  if (!new->ptr_prefix)
    new->ptr_prefix = opcode;
  new->len += 1;
  new->prefix = ASM_PREFIX_LOCK;
  return (proc->fetch(new, opcode + 1, len - 1, proc));
}
/**
* @file libasm/src/arch/ia32/handlers/op_lodsb.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 *
 * <instruction func="op_lodsb" opcode="0xac"/>
 */

int op_lodsb(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->instr = ASM_LODSB;
  new->len += 1;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_LOAD;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_YDEST, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_YDEST, new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_FIXED, new,
								asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));

#else
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_FIXED, new);
#endif
  new->op[1].content = ASM_OP_BASE | ASM_OP_FIXED;
  new->op[1].regset = asm_proc_opsize(proc) ?
                      ASM_REGSET_R16 : ASM_REGSET_R32;
  new->op[1].baser = ASM_REG_EAX;

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_lodsd" opcode="0xad"/>
*/

int op_lodsd(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_LODSD;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_LOAD;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_YDEST, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_YDEST, new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_XSRC, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_XSRC, new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_loop" opcode="0xe2"/>
 */

int op_loop(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  new->instr = ASM_LOOP;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_loope" opcode="0xe1"/>
 */

int op_loope(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_LOOPE;
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL | ASM_TYPE_READFLAG;
  new->flagsread = ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_loopne" opcode="0xe0"/>
*/

int op_loopne(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->instr = ASM_LOOPNE;
  new->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL | ASM_TYPE_READFLAG;
  new->ptr_instr = opcode;
  new->len += 1;
  new->flagsread = ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SHORTJUMP,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <i386 func="op_lss_rv_rmv" opcode="0xb2"/>
*/

int     op_lss_rv_rmv(asm_instr *new, u_char *opcode, u_int len,
		      asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_LSS;

  #if LIBASM_USE_OPERAND_VECTOR
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,				new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,				new);
#endif
  #else
  new->op[0].type = ASM_OTYPE_GENERAL;
  new->op[1].type = ASM_OTYPE_ENCODED;
  operand_rv_rmv(new, opcode + 1, len - 1, proc);
  #endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_mov_al_ref_iv" opcode="0xa0"/>
*/

int op_mov_al_ref_iv(asm_instr *new, u_char *opcode, u_int len,
                     asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_MOV;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_ASSIGN;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_AL,
					       ASM_REGSET_R8));

#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
#endif
  new->op[0].content = ASM_OP_BASE;
  new->op[0].baser = ASM_REG_AL;
  new->op[0].regset = ASM_REGSET_R8;
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_OFFSET, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_OFFSET, new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_mov_eax_ref_iv.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Instruction handler for opcode 0xa1
 *
  <instruction func="op_mov_eax_ref_iv" opcode="0xa1"/>
*/

int op_mov_eax_ref_iv(asm_instr *new, u_char *opcode, u_int len,
                      asm_processor *proc)
{
  new->instr = ASM_MOV;
  new->ptr_instr = opcode;
  new->len += 1;
  new->type = ASM_TYPE_ASSIGN;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));
  
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_FIXED, new);
#endif
  new->op[0].content = ASM_OP_BASE;
  new->op[0].ptr = opcode;
  new->op[0].type = ASM_OTYPE_FIXED;
  new->op[0].regset = asm_proc_opsize(proc) ?
                      ASM_REGSET_R16 : ASM_REGSET_R32;
  new->op[0].baser = ASM_REG_EAX;
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_OFFSET, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_OFFSET, new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_mov_rb_rmb.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for opcode 0x8a : instruction op_mov_rb_rmb
  <instruction func="op_mov_rb_rmb" opcode="0x8a"/>
*/

int op_mov_rb_rmb(asm_instr *new, u_char *opcode, u_int len,
		  asm_processor *proc)
{
  new->len += 1;
  new->type = ASM_TYPE_ASSIGN;
  new->instr = ASM_MOV;
  new->ptr_instr = opcode;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERALBYTE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERALBYTE,                                new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODEDBYTE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODEDBYTE,                                new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_mov_ref_iv_al.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 *
 * <instruction func="op_mov_ref_iv_al" opcode="0xa2"/>
 */

int op_mov_ref_iv_al(asm_instr *new, u_char *opcode, u_int len,
		     asm_processor *proc)
{
  new->instr = ASM_MOV;
  new->type = ASM_TYPE_ASSIGN;
  new->ptr_instr = opcode;
  new->len += 1;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_OFFSET, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_OFFSET, new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_AL,
					       ASM_REGSET_R8));
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_FIXED, new);
#endif
  new->op[1].type = ASM_OTYPE_FIXED;
  new->op[1].regset = ASM_REGSET_R8;
  new->op[1].content = ASM_OP_BASE;
  new->op[1].baser = ASM_REG_AL;

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_mov_ref_iv_eax.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_mov_ref_iv_eax" opcode="0xa3"/>
*/

int op_mov_ref_iv_eax(asm_instr *new, u_char *opcode, u_int len,
                      asm_processor *proc)
{
  new->instr = ASM_MOV;
  new->type = ASM_TYPE_ASSIGN;
  new->len += 1;
  new->ptr_instr = opcode;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_OFFSET,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_OFFSET,                                new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERAL,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERAL,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_mov_reg_iv" opcode="0xb8"/>
  <instruction func="op_mov_reg_iv" opcode="0xb9"/>
  <instruction func="op_mov_reg_iv" opcode="0xba"/>
  <instruction func="op_mov_reg_iv" opcode="0xbb"/>
  <instruction func="op_mov_reg_iv" opcode="0xbc"/>
  <instruction func="op_mov_reg_iv" opcode="0xbd"/>
  <instruction func="op_mov_reg_iv" opcode="0xbe"/>
  <instruction func="op_mov_reg_iv" opcode="0xbf"/>
*/

int op_mov_reg_iv(asm_instr *new, u_char *opcode, u_int len,
asm_processor *proc)
{
  struct s_modrm        *modrm;

  modrm = (struct s_modrm *) opcode;
  new->type = ASM_TYPE_ASSIGN;
  new->ptr_instr = opcode;
  new->instr = ASM_MOV;
  new->len += 1;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 0, ASM_OTYPE_OPMOD,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 0, ASM_OTYPE_OPMOD,                                new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_IMMEDIATE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_IMMEDIATE,                                new);
#endif

  return (new->len);
}
/**
 *
* @file libasm/src/arch/ia32/handlers/op_mov_rmb_ib.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 *
 *
 <instruction func="op_mov_rmb_ib" opcode="0xc6"/>
*/

int op_mov_rmb_ib(asm_instr *new, u_char *opcode, u_int len,
                  asm_processor *proc)
{
  int olen;
  new->type = ASM_TYPE_ASSIGN;
  new->len += 1;
  new->instr = ASM_MOV;
  new->ptr_instr = opcode;

#if WIP
  new->len += (olen = asm_operand_fetch(&new->op[0], opcode + 1,                                        ASM_OTYPE_ENCODEDBYTE, new, 0));
#else
  new->len += (olen = asm_operand_fetch(&new->op[0], opcode + 1,                                        ASM_OTYPE_ENCODEDBYTE, new));
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1 + olen ,                                ASM_OTYPE_IMMEDIATEBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1 + olen ,                                ASM_OTYPE_IMMEDIATEBYTE, new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_mov_rmb_rb.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_mov_rmb_rb" opcode="0x88"/>
*/

int op_mov_rmb_rb(asm_instr *new, u_char *opcode, u_int len,
                  asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_ASSIGN;
  new->instr = ASM_MOV;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE,                                new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERALBYTE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERALBYTE,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_mov_rm_segr" opcode="0x8c"/>
*/

int op_mov_rm_segr(asm_instr *new, u_char *opcode, u_int len,
                   asm_processor *proc)
{
  struct s_modrm        *modrm;

  modrm = (struct s_modrm *) opcode + 1;
  new->type = ASM_TYPE_ASSIGN;
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_MOV;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,                                new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_SEGMENT,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_SEGMENT,                                new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_mov_rmv_iv.c
 *
 * @ingroup IA32_instrs
 * $Id$
 * ChangeLog:
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for opcode 0xc7
 * @param new
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
 */

int op_mov_rmv_iv(asm_instr *new, u_char *opcode, u_int len,
                  asm_processor *proc)
{
  int olen;
  new->len += 1;
  new->type = ASM_TYPE_ASSIGN;
  new->ptr_instr = opcode;
  new->instr = ASM_MOV;

#if WIP
  new->len += (olen = asm_operand_fetch(&new->op[0], opcode + 1,                                        ASM_OTYPE_ENCODED, new, 0));
#else
  new->len += (olen = asm_operand_fetch(&new->op[0], opcode + 1,                                        ASM_OTYPE_ENCODED, new));
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1 + olen,                                ASM_OTYPE_IMMEDIATE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1 + olen,                                ASM_OTYPE_IMMEDIATE, new);
#endif

  if (asm_instruction_is_prefixed(new, ASM_PREFIX_OPSIZE))
  {
    if (asm_operand_is_reference(&new->op[0]))
    {
      new->instr = ASM_MOVW;
    }
  }
  else
    new->instr = ASM_MOV;

 return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_mov_rmv_rv" opcode="0x89"/>
*/

int op_mov_rmv_rv(asm_instr *new, u_char *opcode, u_int len,
                  asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_ASSIGN;
  new->len += 1;
  new->instr = ASM_MOV;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,                                new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERAL,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERAL,                                new);
#endif

  if (new->op[0].content == ASM_OP_BASE &&
      new->op[0].baser == ASM_REG_EBP &&
      new->op[1].baser == ASM_REG_ESP) {

    new->type |= ASM_TYPE_PROLOG;
  }
  else if (new->op[0].content == ASM_OP_BASE &&
            new->op[0].baser == ASM_REG_ESP &&
            new->op[1].baser == ASM_REG_EBP) {

    new->type |= ASM_TYPE_EPILOG;
  }

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_mov_rv_rmv" opcode="0x8b"/>
*/

int op_mov_rv_rmv(asm_instr *new, u_char *opcode, u_int len,
                  asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->type = ASM_TYPE_ASSIGN;
  new->instr = ASM_MOV;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL,                                new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,                                new);
#endif

  if (new->op[1].content == ASM_OP_BASE &&
      new->op[0].baser == ASM_REG_EBP &&
      new->op[1].baser == ASM_REG_ESP) {

    new->type |= ASM_TYPE_PROLOG;
  }
  else if (new->op[1].content == ASM_OP_BASE &&
            new->op[0].baser == ASM_REG_ESP &&
            new->op[1].baser == ASM_REG_EBP) {

    new->type |= ASM_TYPE_EPILOG;
  }

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_movsb" opcode="0xa4"/>
 */

int op_movsb(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->instr = ASM_MOVSB;
  new->len += 1;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_LOAD | ASM_TYPE_STORE | ASM_TYPE_ASSIGN;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_YDEST, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_YDEST, new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_XSRC, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_XSRC, new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_movsd" opcode="0xa5"/>
*/

int op_movsd(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  if (asm_proc_opsize(proc))
    new->instr = ASM_MOVSW;
  else
    new->instr = ASM_MOVSD;

  new->type = ASM_TYPE_LOAD | ASM_TYPE_STORE | ASM_TYPE_ASSIGN;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_YDEST, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_YDEST, new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_XSRC, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_XSRC, new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_mov_segr_rm" opcode="0x8e"/>
*/

int op_mov_segr_rm(asm_instr *new, u_char *opcode, u_int len,
                   asm_processor *proc)
{
  struct s_modrm        *modrm;

  modrm = (struct s_modrm *) opcode + 1;
  new->type = ASM_TYPE_ASSIGN;
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_MOV;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SEGMENT,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_SEGMENT,                                new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED,                                new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_mov_subreg_ib.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_mov_subreg_ib" opcode="0xb0"/>
  <instruction func="op_mov_subreg_ib" opcode="0xb1"/>
  <instruction func="op_mov_subreg_ib" opcode="0xb2"/>
  <instruction func="op_mov_subreg_ib" opcode="0xb3"/>
  <instruction func="op_mov_subreg_ib" opcode="0xb4"/>
  <instruction func="op_mov_subreg_ib" opcode="0xb5"/>
  <instruction func="op_mov_subreg_ib" opcode="0xb6"/>
  <instruction func="op_mov_subreg_ib" opcode="0xb7"/>

*/

int op_mov_subreg_ib(asm_instr *new, u_char *opcode, u_int len,
                     asm_processor *proc)
{
  struct s_modrm        *modrm;

  modrm = (struct s_modrm *) opcode;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_ASSIGN;
  new->instr = ASM_MOV;
  new->len += 1;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_OPMOD, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_OPMOD, new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,                                ASM_OTYPE_IMMEDIATEBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,                                ASM_OTYPE_IMMEDIATEBYTE, new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_nop.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for the nop instruction, opcode 0x90
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of the instruction.
 */

int op_nop(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_NOP;
  new->type = ASM_TYPE_NOP;
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_opsize" opcode="0x66"/>
 */

int     op_opsize(asm_instr *new, u_char *opcode, u_int len,
		  asm_processor *proc)
{
  asm_i386_processor    *i386p;

  if (!new->ptr_prefix)
    new->ptr_prefix = opcode;
  i386p = (asm_i386_processor *) proc;

  i386p->internals->opsize = !i386p->internals->opsize;
  new->len += 1;
  new->prefix |= ASM_PREFIX_OPSIZE;
  len = proc->fetch(new, opcode + 1, len - 1, proc);
  i386p->internals->opsize = !i386p->internals->opsize;
  return (len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  Opcode :              0x0c
  Instruction :         OR
*/

int op_or_al_ib(asm_instr *new, u_char *opcode, u_int len,
                asm_processor *proc)
{
  new->instr = ASM_OR;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->ptr_instr = opcode;
  new->len += 1;
  new->flagswritten = ASM_FLAG_CF | ASM_FLAG_OF | ASM_FLAG_PF |
                        ASM_FLAG_ZF | ASM_FLAG_SF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new,
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       ASM_REGSET_R8));

#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
#endif
  new->op[0].content = ASM_OP_BASE | ASM_OP_FIXED;
  new->op[0].ptr = opcode;
  new->op[0].baser = ASM_REG_AL;
  new->op[0].regset = ASM_REGSET_R8;
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_IMMEDIATEBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_IMMEDIATEBYTE, new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  Opcode :              0x0d
  Instruction :         OR
  */

int op_or_eax_iv(asm_instr *new, u_char *opcode, u_int len,
                 asm_processor *proc)
{
  new->instr = ASM_OR;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->ptr_instr = opcode;
  new->len += 1;
  new->flagswritten = ASM_FLAG_CF | ASM_FLAG_OF | ASM_FLAG_PF |
                        ASM_FLAG_ZF | ASM_FLAG_SF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new,
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));

#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
#endif
  new->op[0].content = ASM_OP_FIXED | ASM_OP_BASE;
  new->op[0].regset = asm_proc_opsize(proc) ?
    ASM_REGSET_R16 : ASM_REGSET_R32;
  new->op[0].baser = ASM_REG_EAX;
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_IMMEDIATE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_IMMEDIATE, new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  Opcode :              0x0a
  */

int op_or_rb_rmb(asm_instr *new, u_char *opcode, u_int len,
                 asm_processor *proc)
{
  new->instr = ASM_OR;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->ptr_instr = opcode;
  new->len += 1;
  new->flagswritten = ASM_FLAG_CF | ASM_FLAG_OF | ASM_FLAG_PF |
                        ASM_FLAG_ZF | ASM_FLAG_SF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERALBYTE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERALBYTE,                                new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODEDBYTE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODEDBYTE,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  Opcode :              0x08
  Instruction :         OR
*/

int op_or_rmb_rb(asm_instr *new, u_char *opcode, u_int len,
                 asm_processor *proc)
{
  new->instr = ASM_OR;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->ptr_instr = opcode;
  new->len += 1;
  new->flagswritten = ASM_FLAG_CF | ASM_FLAG_OF | ASM_FLAG_PF |
                        ASM_FLAG_ZF | ASM_FLAG_SF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE,                                new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERALBYTE,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERALBYTE,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  Opcode :              0x09
  Instruction :         OR
*/

int op_or_rmv_rv(asm_instr *new, u_char *opcode, u_int len,
                 asm_processor *proc)
{
  new->len += 1;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->ptr_instr = opcode;
  new->instr = ASM_OR;
  new->flagswritten = ASM_FLAG_CF | ASM_FLAG_OF | ASM_FLAG_PF |
                        ASM_FLAG_ZF | ASM_FLAG_SF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,                                new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERAL,                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERAL,                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  Opcode :              0x0b
  Instruction :         OR
*/

int op_or_rv_rmv(asm_instr *new, u_char *opcode, u_int len,
                 asm_processor *proc)
{
  new->instr = ASM_OR;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->ptr_instr = opcode;
  new->len += 1;
  new->flagswritten = ASM_FLAG_CF | ASM_FLAG_OF | ASM_FLAG_PF |
                        ASM_FLAG_ZF | ASM_FLAG_SF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,                                ASM_OTYPE_GENERAL, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,                                ASM_OTYPE_GENERAL, new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,                                ASM_OTYPE_ENCODED, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,                                ASM_OTYPE_ENCODED, new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_out_dx_al" opcode="0xee"/>
 */

int     op_out_dx_al(asm_instr *new, u_char *opcode, u_int len,
                         asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_OUT;
  new->type = ASM_TYPE_IO | ASM_TYPE_STORE;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new,
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_DX,
					       ASM_REGSET_R16));
  
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
#endif
  new->op[0].content = ASM_OP_BASE | ASM_OP_REFERENCE;
  new->op[0].regset = ASM_REGSET_R16;
  new->op[0].baser = ASM_REG_DX;
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_FIXED, new,
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_AL,
					       ASM_REGSET_R8));
  
#else
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_FIXED, new);
#endif
  new->op[1].content = ASM_OP_BASE;
  new->op[1].regset = ASM_REGSET_R8;
  new->op[1].baser = ASM_REG_AL;

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_out_dx_eax.c
 *
 * @ingroup IA32_instrs
 *
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_out_dx_eax" opcode="0xef"/>
 */

int     op_out_dx_eax(asm_instr *new, u_char *opcode, u_int len,
                         asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_OUT;
  new->type = ASM_TYPE_IO | ASM_TYPE_STORE;


#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_DX,
					       ASM_REGSET_R16));
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
#endif
  new->op[0].content = ASM_OP_BASE | ASM_OP_REFERENCE;
  new->op[0].regset = ASM_REGSET_R16;
  new->op[0].baser = ASM_REG_DX;
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));
  
#else
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_FIXED, new);
#endif
  new->op[1].content = ASM_OP_BASE;
  new->op[1].regset = ASM_REGSET_R32;
  new->op[1].baser = ASM_REG_EAX;

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_out_ref_ib_al" opcode="0xe6"/>
*/


int op_out_ref_ib_al(asm_instr *new, u_char *opcode, u_int len,
                     asm_processor *proc)
{
  new->instr = ASM_OUT;
  new->ptr_instr = opcode;
  new->len += 1;
  new->type = ASM_TYPE_IO | ASM_TYPE_STORE;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_IMMEDIATEBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_IMMEDIATEBYTE, new);
#endif
#if WIP
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_AL,
					       ASM_REGSET_R8));

#else
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_FIXED, new);
#endif
  new->op[1].content = ASM_OP_BASE;
  new->op[1].regset = ASM_REGSET_R8;
  new->op[1].baser = ASM_REG_AL;

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_out_ref_ib_eax.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_out_ref_ib_eax" opcode="0xe7"/>
*/

int op_out_ref_ib_eax(asm_instr *new, u_char *opcode, u_int len, 
                      asm_processor *proc) 
{
  new->ptr_instr = opcode;
  new->instr = ASM_OUT;
  new->len += 1;
  new->type = ASM_TYPE_IO | ASM_TYPE_STORE;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
                                ASM_OTYPE_IMMEDIATEBYTE, new, 0);
  new->len += asm_operand_fetch(&new->op[1], opcode, 
                                ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));

#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
                                ASM_OTYPE_IMMEDIATEBYTE, new);
  new->len += asm_operand_fetch(&new->op[1], opcode, 
                                ASM_OTYPE_FIXED, new);
  new->op[1].content = ASM_OP_BASE;
  new->op[1].regset = ASM_REGSET_R32;
  new->op[1].baser = ASM_REG_EAX;
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_outsb" opcode="0x6e"/>
*/

int op_outsb(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) 
{
  new->len += 1;
  new->instr = ASM_OUTSB;
  new->ptr_instr = opcode;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_DX,
					       ASM_REGSET_R16));

  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_XSRC, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
  new->op[0].content = ASM_OP_BASE | ASM_OP_REFERENCE;
  new->op[0].regset = ASM_REGSET_R16;
  new->op[0].baser = ASM_REG_EDX;
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_XSRC, new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_outsw" opcode="0x6f"/>
  <instruction func="op_outsd" opcode="0x6f"/>
*/

int op_outsw(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) 
{
  new->ptr_instr = opcode;
  new->len += 1;
  
  if (!asm_proc_opsize(proc))
    new->instr = ASM_OUTSW;
  else
    new->instr = ASM_OUTSD;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new,
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_DX,
					       ASM_REGSET_R16));

  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_XSRC, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
  new->op[0].content = ASM_OP_BASE | ASM_OP_REFERENCE;
  new->op[0].regset = ASM_REGSET_R16;
  new->op[0].baser = ASM_REG_DX;
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_XSRC, new);
#endif
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for the popa instruction. Opcode = 0x61
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of buffer to disassemble.
 * @param proc Pointer to processor structure.
*/

int op_popa(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_POPA;
  new->spdiff = 8 * 4;
  new->type = ASM_TYPE_TOUCHSP | ASM_TYPE_LOAD;
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_pop_ds" opcode="0x1f"/>
*/

int     op_pop_ds(asm_instr *new, u_char *opcode, u_int len, 
                  asm_processor *proc) 
{
  new->instr = ASM_POP;
  new->ptr_instr = opcode;
  new->len += 1;
  new->type = ASM_TYPE_TOUCHSP | ASM_TYPE_LOAD | ASM_TYPE_ASSIGN;
  new->spdiff = 4;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new,
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_DS,
					       ASM_REGSET_SREG));

#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
  new->op[0].content = ASM_OP_BASE | ASM_OP_FIXED;
  new->op[0].regset = ASM_REGSET_SREG;
  new->op[0].baser = ASM_REG_DS;
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  Opcode :              0x07
  Instruction :         POP
*/

int op_pop_es(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) 
{
  new->instr = ASM_POP;
  new->type = ASM_TYPE_TOUCHSP | ASM_TYPE_ASSIGN | ASM_TYPE_LOAD;
  new->spdiff = 4;
  new->len += 1;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new,
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_ES,
					       ASM_REGSET_SREG));

#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
  new->op[0].content = ASM_OP_BASE | ASM_OP_FIXED;
  new->op[0].regset = ASM_REGSET_SREG;
  new->op[0].baser = ASM_REG_ES;
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction name="popf" func="op_popf" opcode="0x9d"/>
*/

int op_popf(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_POPF;
  new->type = ASM_TYPE_TOUCHSP | ASM_TYPE_LOAD | ASM_TYPE_WRITEFLAG;
  new->spdiff = 4;
  new->flagswritten = ASM_FLAG_CF | ASM_FLAG_PF | ASM_FLAG_AF |
                        ASM_FLAG_ZF | ASM_FLAG_SF | ASM_FLAG_TF |
                        ASM_FLAG_IF | ASM_FLAG_DF | ASM_FLAG_OF |
                        ASM_FLAG_IOPL | ASM_FLAG_NT | ASM_FLAG_RF |
                        ASM_FLAG_AC | ASM_FLAG_VIF | ASM_FLAG_VIP |
                        ASM_FLAG_ID;
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_pop_reg" opcode="0x58"/>
  <instruction func="op_pop_reg" opcode="0x59"/>
  <instruction func="op_pop_reg" opcode="0x5a"/>
  <instruction func="op_pop_reg" opcode="0x5b"/>
  <instruction func="op_pop_reg" opcode="0x5c"/>
  <instruction func="op_pop_reg" opcode="0x5d"/>
  <instruction func="op_pop_reg" opcode="0x5e"/>
  <instruction func="op_pop_reg" opcode="0x5f"/>
*/

int op_pop_reg(asm_instr *new, u_char *opcode, u_int len, 
               asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_POP;
  new->type = ASM_TYPE_TOUCHSP | ASM_TYPE_ASSIGN | ASM_TYPE_LOAD;
  new->spdiff = 4;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_OPMOD, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_OPMOD, new);
#endif
  if (new->op[0].baser == ASM_REG_EBP)
    new->type |= ASM_TYPE_EPILOG;

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for the pop [rmv] instruction opcode = 0x8f
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Lenght of buffer to disassemble.
 * @param proc Pointer to processor structure.
 *
*/

int op_pop_rmv(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) 
{
  new->len += 1;
  new->instr = ASM_POP;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_TOUCHSP | ASM_TYPE_ASSIGN | ASM_TYPE_LOAD;
  new->spdiff = 4;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,
                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,
                                new);
#endif

  return (new->len);
}
/**
 * @brief Handler for pop es instruction. Opcode = 0x17
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for pop es instruction. Opcode = 0x17
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 */

int     op_pop_ss(asm_instr *new, u_char *opcode, u_int len, 
                  asm_processor *proc)
{
  new->instr = ASM_POP;
  new->len += 1;
  new->type = ASM_TYPE_TOUCHSP | ASM_TYPE_ASSIGN | ASM_TYPE_LOAD;
  new->spdiff = 4;
  new->ptr_instr = opcode;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new,
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_ES,
					       ASM_REGSET_SREG));

#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
  new->op[0].content = ASM_OP_BASE | ASM_OP_FIXED;
  new->op[0].regset = ASM_REGSET_SREG;
  new->op[0].baser = ASM_REG_SS;
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_prefix_cs" opcode="0x2e"/>
*/

int     op_prefix_cs(asm_instr *new, u_char *opcode, u_int len,
		     asm_processor *proc)
{
  new->prefix |= ASM_PREFIX_CS;
  if (!new->ptr_prefix)
    new->ptr_prefix = opcode;
  new->len += 1;
  return (proc->fetch(new, opcode + 1, len - 1, proc));
}
/**
* @file libasm/src/arch/ia32/handlers/op_prefix_ds.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 * Changelog
 * 200-07-29 : instruction length was not incremented. fixed.
 */
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_prefix_ds" opcode="0x3e"/>
*/

int op_prefix_ds(asm_instr *new, u_char *opcode, u_int len,
		 asm_processor *proc)
{
  if (!new->ptr_prefix)
    new->ptr_prefix = opcode;
  new->len += 1;
  new->prefix |= ASM_PREFIX_DS;
  return (proc->fetch(new, opcode + 1, len - 1, proc));
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_prefix_es" opcode="0x26"/>
*/

int     op_prefix_es(asm_instr *new, u_char *opcode, u_int len,
		     asm_processor *proc)
{
  new->prefix |= ASM_PREFIX_ES;
  if (!new->ptr_prefix)
    new->ptr_prefix = opcode;
  new->len += 1;
  return (proc->fetch(new, opcode + 1, len - 1, proc));
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_prefix_fs" opcode="0x64"/>
 */

int     op_prefix_fs(asm_instr *new, u_char *opcode, u_int len,
		     asm_processor *proc)
{
  new->prefix |= ASM_PREFIX_FS;
  if (!new->ptr_prefix)
    new->ptr_prefix = opcode;
  new->len += 1;
  return (proc->fetch(new, opcode + 1, len - 1, proc));
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_prefix_gs" opcode="0x65"/>
 */

int     op_prefix_gs(asm_instr *new, u_char *opcode, u_int len,
		     asm_processor *proc)
{
  if (!new->ptr_prefix)
    new->ptr_prefix = opcode;
  new->prefix |= ASM_PREFIX_GS;
  new->len += 1;
  return (proc->fetch(new, opcode + 1, len - 1, proc));
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_prefix_ss" opcode="0x36"/>
*/

int     op_prefix_ss(asm_instr *new, u_char *opcode, u_int len,
		     asm_processor *proc)
{
  new->prefix |= ASM_PREFIX_SS;
  if (!new->ptr_prefix)
    new->ptr_prefix = opcode;
  return (proc->fetch(new, opcode + 1, len - 1, proc));
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_pusha" opcode="0x60"/>
*/

int op_pusha(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_PUSHA;
  new->type = ASM_TYPE_TOUCHSP | ASM_TYPE_STORE;
  new->spdiff = -4 * 8;
  return (new->len);
}
/**
 * @brief Handler for instruction push cs opcode 0x0e
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>


/**
 * @brief Handler for instruction push cs opcode 0x0e
 */
int op_push_cs(asm_instr *new, u_char *opcode, u_int len,
               asm_processor *proc) {
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_PUSH;
  new->type = ASM_TYPE_TOUCHSP | ASM_TYPE_STORE;
  new->spdiff = -4;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new,
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_CS,
					       ASM_REGSET_SREG));

#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
  new->op[0].content = ASM_OP_BASE | ASM_OP_FIXED;
  new->op[0].regset = ASM_REGSET_SREG;
  new->op[0].baser = ASM_REG_CS;
#endif

  return (new->len);
}
/**
 * @brief Handler for instruction push ds opcode 0x1e
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction push ds opcode 0x1e
 *
*/

int op_push_ds(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) 
{
  new->ptr_instr = opcode;
  new->instr = ASM_PUSH;
  new->type = ASM_TYPE_TOUCHSP | ASM_TYPE_STORE;
  new->spdiff = -4;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new,
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_DS,
					       ASM_REGSET_SREG));

  //asm_fixed_pack(content, type, regset, baser)
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
  new->op[0].content |= ASM_OP_BASE | ASM_OP_FIXED;
  new->op[0].regset = ASM_REGSET_SREG;
  new->op[0].baser = ASM_REG_DS;
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_push_es.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Handler for instruction push es opcode 0x06
*/

int op_push_es(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) 
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_PUSH;
  new->type = ASM_TYPE_TOUCHSP | ASM_TYPE_STORE;
  new->spdiff = -4;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_ES,
					       ASM_REGSET_SREG));

#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
  new->op[0].content |= ASM_OP_BASE | ASM_OP_FIXED;
  new->op[0].regset = ASM_REGSET_SREG;
  new->op[0].baser = ASM_REG_ES;
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction name="pushf" func="op_pushf" opcode="0x9c"/>
*/


int op_pushf(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_PUSHF;
  new->type = ASM_TYPE_TOUCHSP | ASM_TYPE_STORE | ASM_TYPE_READFLAG;
  new->spdiff = -4;
  new->flagsread = ASM_FLAG_CF | ASM_FLAG_PF | ASM_FLAG_AF |
                        ASM_FLAG_ZF | ASM_FLAG_SF | ASM_FLAG_TF |
                        ASM_FLAG_IF | ASM_FLAG_DF | ASM_FLAG_OF |
                        ASM_FLAG_IOPL | ASM_FLAG_NT | ASM_FLAG_RF |
                        ASM_FLAG_AC | ASM_FLAG_VIF | ASM_FLAG_VIP |
                        ASM_FLAG_ID;
  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_push_ib" opcode="0x6a"/>
*/

int op_push_ib(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) 
{
  new->instr = ASM_PUSH;
  new->len += 1;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_TOUCHSP | ASM_TYPE_STORE;
  new->spdiff = -4;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,
                                ASM_OTYPE_IMMEDIATEBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,
                                ASM_OTYPE_IMMEDIATEBYTE, new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_push_iv.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 *
 * Handler for opcode 0x68 , instruction push_iv
  <instruction func="op_push_iv" opcode="0x68"/>
*/

int op_push_iv(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) 
{
  new->instr = ASM_PUSH;
  new->len += 1;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_TOUCHSP | ASM_TYPE_STORE;
  new->spdiff = -4;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_IMMEDIATE,
                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_IMMEDIATE,
                                new);
#endif

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_push_reg" opcode="0x50"/>
  <instruction func="op_push_reg" opcode="0x51"/>
  <instruction func="op_push_reg" opcode="0x52"/>
  <instruction func="op_push_reg" opcode="0x53"/>
  <instruction func="op_push_reg" opcode="0x54"/>
  <instruction func="op_push_reg" opcode="0x55"/>
  <instruction func="op_push_reg" opcode="0x56"/>
  <instruction func="op_push_reg" opcode="0x57"/>
*/

int op_push_reg(asm_instr *new, u_char *opcode, u_int len, 
                asm_processor *proc)
{
  struct s_modrm        *modrm;

  modrm = (struct s_modrm *) opcode;
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_PUSH;
  new->type = ASM_TYPE_TOUCHSP | ASM_TYPE_STORE;
  new->spdiff = -4;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_OPMOD, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_OPMOD, new);
#endif

  if (new->op[0].baser == ASM_REG_EBP)
    new->type |= ASM_TYPE_PROLOG;

  return (new->len);
}
/*
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_push_ss" opcode="0x16"/>
*/

int     op_push_ss(asm_instr *new, u_char *opcode, u_int len, 
                   asm_processor *proc)
{
  new->instr = ASM_PUSH;
  new->len += 1;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_TOUCHSP | ASM_TYPE_STORE;
  new->spdiff = -4;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_SS,
					       ASM_REGSET_SREG));

#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
  new->op[0].content = ASM_OP_BASE;
  new->op[0].regset = ASM_REGSET_SREG;
  new->op[0].baser = ASM_REG_SS;
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_repnz.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_repnz" opcode="0xf2"/>
*/

int op_repnz(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  if (!new->ptr_prefix)
    new->ptr_prefix = opcode;
  new->len += 1;
  new->prefix = ASM_PREFIX_REPNE;

  return (proc->fetch(new, opcode + 1, len - 1, proc));
}
/**
* @file libasm/src/arch/ia32/handlers/op_repz.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_repz" opcode="0xf3"/>
 */

int op_repz(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  if (!new->ptr_prefix)
    new->ptr_prefix = opcode;
  new->len += 1;
  new->prefix = ASM_PREFIX_REP;
  return (proc->fetch(new, opcode + 1, len - 1, proc));
}
/**
* @file libasm/src/arch/ia32/handlers/op_ret.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_ret" opcode="0xc3"/>
*/


int op_ret(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_RETPROC | ASM_TYPE_TOUCHSP | ASM_TYPE_EPILOG;
  new->spdiff = 4;
  new->instr = ASM_RET;
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_retf.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_retf" opcode="0xcb"/>
*/

int op_retf(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_RETF;
  new->type = ASM_TYPE_RETPROC | ASM_TYPE_TOUCHSP | ASM_TYPE_EPILOG;
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_retf_i2.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_retf_i2" opcode="0xca"/>
*/

int op_retf_i2(asm_instr *instr, u_char *opcode, u_int len, 
               asm_processor *proc)
{
  instr->instr = ASM_RETF;
  instr->ptr_instr = opcode;
  instr->len += 1;
  instr->type = ASM_TYPE_RETPROC | ASM_TYPE_TOUCHSP | ASM_TYPE_EPILOG;

#if WIP
  instr->len += asm_operand_fetch(&instr->op[0], opcode + 1,
                                ASM_OTYPE_IMMEDIATEWORD, instr, 0);
#else
  instr->len += asm_operand_fetch(&instr->op[0], opcode + 1,
                                ASM_OTYPE_IMMEDIATEWORD, instr);
#endif
  return (instr->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_ret_i2.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for ret instruction, opcode 0xc2
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
*/

int op_ret_i2(asm_instr *new, u_char *opcode, u_int len, 
              asm_processor *proc)
{
  new->len += 1;
  new->type = ASM_TYPE_RETPROC | ASM_TYPE_TOUCHSP | ASM_TYPE_EPILOG;
  new->spdiff = 4;
  new->instr = ASM_RET;
  new->ptr_instr = opcode;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,
                                ASM_OTYPE_IMMEDIATEWORD, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,
                                ASM_OTYPE_IMMEDIATEWORD, new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_sahf.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction opcode="0x9e" func="op_sahf"/>
 */

int op_sahf(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_SAHF;
  new->type = ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_CF | ASM_FLAG_PF | ASM_FLAG_AF |
                        ASM_FLAG_SF | ASM_FLAG_ZF;
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_sbb_al_ib.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_sbb_al_ib" opcode="0x1c"/>
*/

int op_sbb_al_ib(asm_instr *new, u_char *opcode, u_int len, 
                 asm_processor *proc) 
{
  new->instr = ASM_SBB;
  new->len += 1;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG | ASM_TYPE_READFLAG;
  new->flagsread = ASM_FLAG_CF;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF |
                        ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_FIXED, new,
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_AL,
					       ASM_REGSET_R8));

  new->len += asm_operand_fetch(&new->op[1], opcode + 1,
                                ASM_OTYPE_IMMEDIATEBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_FIXED, new);
  new->op[0].size = new->op[1].size = ASM_OSIZE_BYTE;
  new->op[0].content = ASM_OP_BASE | ASM_OP_FIXED;
  new->op[0].ptr = opcode;
  new->op[0].len = 0;
  new->op[0].baser = ASM_REG_AL;
  new->op[0].regset = ASM_REGSET_R8;
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,
                                ASM_OTYPE_IMMEDIATEBYTE, new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_sbb_eax_iv.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_sbb_eax_iv" opcode="0x1d"/>
*/

int op_sbb_eax_iv(asm_instr *new, u_char *opcode, u_int len, 
                  asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_SBB;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG | ASM_TYPE_READFLAG;
  new->flagsread = ASM_FLAG_CF;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF |
                        ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new,
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));

  new->len += asm_operand_fetch(&new->op[1], opcode + 1,
                                ASM_OTYPE_IMMEDIATE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
  new->op[0].size = new->op[1].size = ASM_OSIZE_VECTOR;
  new->op[0].content = ASM_OP_FIXED | ASM_OP_BASE;
  new->op[0].baser = ASM_REG_EAX;
  new->op[0].regset = asm_proc_opsize(proc) ? ASM_REGSET_R32 :
    ASM_REGSET_R16;
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,
                                ASM_OTYPE_IMMEDIATE, new);
#endif
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_sbb_rb_rmb.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_sbb_rb_rmb" opcode="0x1a"/>
*/

int op_sbb_rb_rmb(asm_instr *new, u_char *opcode, u_int len, 
                  asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_SBB;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG | ASM_TYPE_READFLAG;
  new->flagsread = ASM_FLAG_CF;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF |
                        ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,
                                ASM_OTYPE_GENERALBYTE, new, 0);
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,
                                ASM_OTYPE_ENCODEDBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,
                                ASM_OTYPE_GENERALBYTE, new);
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,
                                ASM_OTYPE_ENCODEDBYTE, new);
#endif
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_sbb_rmb_rb.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_sbb_rmb_rb" opcode="0x18"/>
*/

int op_sbb_rmb_rb(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) 
{
  new->len += 1;
  new->instr = ASM_SBB;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG | ASM_TYPE_READFLAG;
  new->flagsread = ASM_FLAG_CF;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF |
                        ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,
                                ASM_OTYPE_ENCODEDBYTE, new, 0);
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,
                                ASM_OTYPE_GENERALBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,
                                ASM_OTYPE_ENCODEDBYTE, new);
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,
                                ASM_OTYPE_GENERALBYTE, new);
#endif

  return (new->len);
}
/** 
* @file libasm/src/arch/ia32/handlers/op_sbb_rmv_rv.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_sbb_rmv_rv" opcode="0x19"/>
*/

int op_sbb_rmv_rv(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) {
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_SBB;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG | ASM_TYPE_READFLAG;
  new->flagsread = ASM_FLAG_CF;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF |
                        ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED, new, 0);
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERAL, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED, new);
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERAL, new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_sbb_rv_rmv.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_sbb_rv_rmv" opcode="0x1b"/>
*/

int op_sbb_rv_rmv(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) {
  new->len += 1;
  new->instr = ASM_SBB;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG | ASM_TYPE_READFLAG;
  new->flagsread = ASM_FLAG_CF;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF |
                        ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode +1, ASM_OTYPE_GENERAL, new, 0);
  new->len += asm_operand_fetch(&new->op[1], opcode +1, ASM_OTYPE_ENCODED, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode +1, ASM_OTYPE_GENERAL, new);
  new->len += asm_operand_fetch(&new->op[1], opcode +1, ASM_OTYPE_ENCODED, new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_scasb.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_scasb" opcode="0xae"/>
*/

int op_scasb(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) {
  new->instr = ASM_SCASB;
  new->ptr_instr = opcode;
  new->len += 1;
  new->type = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF |
                        ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new,
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       ASM_REGSET_R8));

  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_YDEST, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
  new->op[0].content = ASM_OP_BASE;
  new->op[0].regset = ASM_REGSET_R8;
  new->op[0].baser = ASM_REG_EAX;
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_YDEST, new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_scasd.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_scasd" opcode="0xaf"/>
*/

int op_scasd(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) 
{
  new->len += 1;
  if (asm_proc_opsize(proc))
    new->instr = ASM_SCASW;
  else
    new->instr = ASM_SCASD;

  new->ptr_instr = opcode;
  new->type = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF |
                        ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new,
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_AL,
					       ASM_REGSET_R8));

  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_YDEST, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
  new->op[0].content = ASM_OP_BASE;
  new->op[0].regset = ASM_REGSET_R8;
  new->op[0].baser = ASM_REG_EAX;

  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_YDEST, new);
#endif
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_setae_rmb.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction setae, opcode 0x0f 0x93
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
*/

int op_setae_rmb(asm_instr *new, u_char *opcode, u_int len, 
		 asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_SET_U_GREATER_EQUAL;
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new);
#endif
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_seta_rmb.c
 *
 * @ingroup IA32_instrs
 * $Id$
*
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction seta, opcode 0x0f 0x97
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
*/

int op_seta_rmb(asm_instr *new, u_char *opcode, u_int len, 
		asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_SET_U_GREATER;
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new);
#endif
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_setbe_rmb.c
 *
 * @ingroup IA32_instrs
* $Id$
*
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction op_setbe, opcode 0x0f 0x96
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
*/

int op_setbe_rmb(asm_instr *new, u_char *opcode, u_int len, 
		 asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_SET_U_LESS_EQUAL;
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE, 
				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE, 
				new);
#endif
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_setb_rmb.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction setb, opcode 0x0f 0x92
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
*/

int op_setb_rmb(asm_instr *new, u_char *opcode, u_int len, 
		asm_processor *proc)
{
  new->instr = ASM_SET_U_LESS;
  new->len += 1;
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new);
#endif
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_sete_rmb.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction sete, opcode 0x0f 0x94
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble
 * @param proc Pointer to processor structure
 * @return Length of instruction
*/

int op_sete_rmb(asm_instr *new, u_char *opcode, u_int len, 
		asm_processor *proc)
{
  new->instr = ASM_SET_EQUAL;
  new->len += 1;
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new);
#endif
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_setge_rmb.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction setge, opcode 0x0f 0x9d
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
*/

int op_setge_rmb(asm_instr *new, u_char *opcode, u_int len, 
		 asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_SET_S_GREATER_EQUAL;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new);
#endif
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_setg_rmb.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction setg, opcode 0x0f 0x9f
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
*/

int op_setg_rmb(asm_instr *new, u_char *opcode, u_int len, 
		asm_processor *proc)
{
  new->instr = ASM_SET_S_GREATER;
  new->len += 1;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_setle_rmb.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction setle, opcode 0x0f 0x9e
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
*/

int op_setle_rmb(asm_instr *new, u_char *opcode, u_int len, 
		 asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_SET_S_LESS_EQUAL;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new);
#endif
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_setl_rmb.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction setl, opcode 0x0f 0x9c
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
*/

int op_setl_rmb(asm_instr *new, u_char *opcode, u_int len, 
		asm_processor *proc)
{
  new->instr = ASM_SET_S_LESS;
  new->len += 1;
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_setne_rmb.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction setne, opcode 0x0f 0x95
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
*/

int op_setne_rmb(asm_instr *new, u_char *opcode, u_int len, 
		 asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_SET_NOT_EQUAL;
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new);
#endif
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_setno_rmb.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction setno, opcode 0x0f 0x91
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
*/

int op_setno_rmb(asm_instr *new, u_char *opcode, u_int len, 
		 asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_SET_NOT_OVERFLOW;
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new);
#endif
  return (new->len);
}

/**
* @file libasm/src/arch/ia32/handlers/op_setnp_rmb.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction setnp, opcode 0x0f 0x9b
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
*/

int op_setnp_rmb(asm_instr *new, u_char *opcode, u_int len, 
		 asm_processor *proc) 
{
  new->len += 1;
  new->instr = ASM_SET_NOT_PARITY;
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new);
#endif
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_setns_rmb.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction setns, opcode 0x0f 0x99
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
*/

int op_setns_rmb(asm_instr *new, u_char *opcode, u_int len, 
		 asm_processor *proc) 
{
  new->len += 1;
  new->instr = ASM_SET_NOT_SIGNED;
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new);
#endif
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_seto_rmb.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction seto, opcode 0x0f 0x90
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction
*/

int op_seto_rmb(asm_instr *new, u_char *opcode, u_int len, 
		asm_processor *proc) 
{
  new->len += 1;
  new->instr = ASM_SET_OVERFLOW;
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, 
				ASM_OTYPE_ENCODEDBYTE, new);
#endif 
 return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_setp_rmb.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction setp, opcode 0x0f 0x9a
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
 */

int op_setp_rmb(asm_instr *new, u_char *opcode, u_int len, 
		asm_processor *proc) 
{
  new->len += 1;
  new->instr = ASM_SET_PARITY;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE, 
				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE, 
				new);
#endif
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_sets_rmb.c
 *
 * @ingroup IA32_instrs
 * $Id$
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction sets, opcode 0x0f 0x98
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
*/

int op_sets_rmb(asm_instr *new, u_char *opcode, u_int len, 
		asm_processor *proc) 
{
  new->len += 1;
  new->instr = ASM_SET_SIGNED;
#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE,
				new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE,
				new);
#endif
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_shift_rmb_1.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_shift_rmb_1" opcode="0xd0"/>
 */

int op_shift_rmb_1(asm_instr *new, u_char *opcode, u_int len, 
                   asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->len += 1;
  new->instr = ASM_SHR;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_PF | ASM_FLAG_ZF | ASM_FLAG_SF |
                        ASM_FLAG_CF | ASM_FLAG_OF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE, 
                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE, 
                                new);
#endif
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_shift_rmb_cl.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 * Changelog
 * 2007-05-29 : instruction set was not complete.
 *		operand type for operand 1 was incorrect.
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler for instruction shit rmb,cl opcode 0xd2
 * <instruction func="op_shift_rmb_cl" opcode="0xd2"/>
 */

int op_shift_rmb_cl(asm_instr *instr, u_char *opcode, u_int len, 
                    asm_processor *proc)
{
  struct s_modrm        *modrm;

  modrm = (struct s_modrm *) opcode + 1;
  instr->ptr_instr = opcode;
  instr->len += 1;
  instr->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  instr->flagswritten = ASM_FLAG_CF | ASM_FLAG_OF;

  switch(modrm->r)
  {
    case 0: instr->instr = ASM_ROL; break;
    case 1: instr->instr = ASM_ROR; break;
    case 2: instr->instr = ASM_RCL; break;
    case 3: instr->instr = ASM_RCR; break;
    case 4:
      instr->instr = ASM_SHL;
      instr->flagswritten |= ASM_FLAG_PF | ASM_FLAG_ZF | ASM_FLAG_SF;
      break;
    case 5:
      instr->instr = ASM_SHR;
      instr->flagswritten |= ASM_FLAG_PF | ASM_FLAG_ZF | ASM_FLAG_SF;
      break;
    case 6:
      instr->instr = ASM_SAL;
      instr->flagswritten |= ASM_FLAG_PF | ASM_FLAG_ZF | ASM_FLAG_SF;
      break;
    case 7:
      instr->instr = ASM_SAR;
      instr->flagswritten |= ASM_FLAG_PF | ASM_FLAG_ZF | ASM_FLAG_SF;
      break;
  }

#if WIP
  instr->len += asm_operand_fetch(&instr->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE,
                                instr, 0);
  instr->len += asm_operand_fetch(&instr->op[1], opcode + 1, ASM_OTYPE_FIXED, instr,
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_CL,
					       ASM_REGSET_R8));

#else
  instr->len += asm_operand_fetch(&instr->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE,
                                instr);
  instr->len += asm_operand_fetch(&instr->op[1], opcode + 1, ASM_OTYPE_FIXED, instr);
  instr->op[1].content = ASM_OP_BASE;
  instr->op[1].regset = ASM_REGSET_R8;
  instr->op[1].baser = ASM_REG_CL;
#endif

  return (instr->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_shift_rmv_1.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_shift_rmv_1" opcode="0xd1"/>
 */

int op_shift_rmv_1(asm_instr *new, u_char *opcode, u_int len, 
                   asm_processor *proc)
{
  struct s_modrm        *modrm;

  modrm = (struct s_modrm *) opcode + 1;
  new->ptr_instr = opcode;
  new->len += 1;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_PF | ASM_FLAG_ZF | ASM_FLAG_SF |
                        ASM_FLAG_CF | ASM_FLAG_OF;

  switch(modrm->r) {
  case ASM_REG_EDI:
    new->instr = ASM_SAR;
    break;
  case ASM_REG_ESP:
    new->instr = ASM_SHL;
    break;
  default:
    new->instr = ASM_SHR;
    break;
  }

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,
                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,
                                new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_shift_rmv_cl.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_shift_rmv_cl" opcode="0xd3"/>
*/

int op_shift_rmv_cl(asm_instr *new, u_char *opcode, u_int len, 
                    asm_processor *proc)
{
  struct s_modrm        *modrm;

  new->ptr_instr = opcode;
  modrm = (struct s_modrm *) opcode + 1;
  new->len += 1;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_CF | ASM_FLAG_OF;

  switch(modrm->r) {
  case 0:
    new->instr = ASM_ROL;
    break;
  case 5:
    new->instr = ASM_SHR;
    new->flagswritten |= ASM_FLAG_PF | ASM_FLAG_ZF | ASM_FLAG_SF;
    break;
  case 4:
    new->instr = ASM_SHL;
    new->flagswritten |= ASM_FLAG_PF | ASM_FLAG_ZF | ASM_FLAG_SF;
    break;
  case 7:
    new->instr = ASM_SAR;
    new->flagswritten |= ASM_FLAG_PF | ASM_FLAG_ZF | ASM_FLAG_SF;
    break;
  default:
    new->instr = ASM_BAD;
  }

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,
                                ASM_OTYPE_ENCODED, new, 0);
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_FIXED, new,
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_CL,
					       ASM_REGSET_R8));

#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,
                                ASM_OTYPE_ENCODED, new);
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_FIXED, new);
  new->op[1].content = ASM_OP_BASE | ASM_OP_FIXED;
  new->op[1].regset = ASM_REGSET_R8;
  new->op[1].baser = ASM_REG_CL;
  new->op[1].len = 0;
  new->op[1].ptr = 0;
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_shr_rmb_ib.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_shr_rmb_ib" opcode="0xc0"/>
*/

int op_shr_rmb_ib(asm_instr *new, u_char *opcode, u_int len, 
                  asm_processor *proc) {
  struct s_modrm        *modrm;
  int                   olen;

  modrm = (struct s_modrm *) (opcode + 1);
  new->ptr_instr = opcode;
  new->len += 1;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_CF | ASM_FLAG_OF;

  if (modrm->r == ASM_REG_EAX)
    new->instr = ASM_ROL;
  else if (modrm->r == ASM_REG_EBP) {
    new->instr = ASM_SHR;
    new->flagswritten |= ASM_FLAG_PF | ASM_FLAG_ZF | ASM_FLAG_SF;
  }
  else if (modrm->r == ASM_REG_EDI) {
    new->instr = ASM_SAR;
    new->flagswritten |= ASM_FLAG_PF | ASM_FLAG_ZF | ASM_FLAG_SF;
  }
  else if (modrm->r == ASM_REG_ECX)
      new->instr = ASM_ROR;
  else if (modrm->r == 3)
    new->instr = ASM_RCR;
  else {
    new->instr = ASM_SHL;
    new->flagswritten |= ASM_FLAG_PF | ASM_FLAG_ZF | ASM_FLAG_SF;
  }

#if WIP
  new->len += (olen = asm_operand_fetch(&new->op[0], opcode + 1,
                                        ASM_OTYPE_ENCODEDBYTE, new, 0));
  new->len += asm_operand_fetch(&new->op[1], opcode + 1 + olen,
                                ASM_OTYPE_IMMEDIATEBYTE, new, 0);
#else
  new->len += (olen = asm_operand_fetch(&new->op[0], opcode + 1,
                                        ASM_OTYPE_ENCODEDBYTE, new));
  new->len += asm_operand_fetch(&new->op[1], opcode + 1 + olen,
                                ASM_OTYPE_IMMEDIATEBYTE, new);
#endif
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_shr_rmv_ib.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_shr_rmv_ib" opcode="0xc1"/>
*/

int op_shr_rmv_ib(asm_instr *new, u_char *opcode, u_int len, 
                  asm_processor *proc) {
  struct s_modrm        *modrm;
  int                   olen;

  modrm = (struct s_modrm *) opcode + 1;
  new->ptr_instr = opcode;
  new->len += 1;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_OF | ASM_FLAG_CF;

  if (modrm->r == ASM_REG_EAX)
    new->instr = ASM_ROL;
  if (modrm->r == ASM_REG_EBP) {
    new->instr = ASM_SHR;
    new->flagswritten |= ASM_FLAG_PF | ASM_FLAG_ZF | ASM_FLAG_SF;
  }
  else if (modrm->r == ASM_REG_EDI) {
    new->instr = ASM_SAR;
    new->flagswritten |= ASM_FLAG_PF | ASM_FLAG_ZF | ASM_FLAG_SF;
  }
  else if (modrm->r == ASM_REG_ECX)
    new->instr = ASM_ROR;
  else if (modrm->r == ASM_REG_EAX)
    new->instr = ASM_ROL;
  else {
    new->instr = ASM_SHL;
    new->flagswritten |= ASM_FLAG_PF | ASM_FLAG_ZF | ASM_FLAG_SF;
  }

#if WIP
  new->len += (olen = asm_operand_fetch(&new->op[0], opcode + 1,
                                        ASM_OTYPE_ENCODED, new, 0));
  new->len += asm_operand_fetch(&new->op[1], opcode + 1 + olen,
                                ASM_OTYPE_IMMEDIATEBYTE, new, 0);
#else
  new->len += (olen = asm_operand_fetch(&new->op[0], opcode + 1,
                                        ASM_OTYPE_ENCODED, new));
  new->len += asm_operand_fetch(&new->op[1], opcode + 1 + olen,
                                ASM_OTYPE_IMMEDIATEBYTE, new);
#endif
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_stc.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief
 * <instruction func="op_stc" opcode="0xf9"/>
*/

int op_stc(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_STC;
  new->type = ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_CF;
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_std.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_std" opcode="0xfd"/>
*/

int op_std(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_STD;
  new->type = ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_DF;
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_sti.c
 *
 * @ingroup IA32_instrs
 *
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 * @todo: Set flags field.
 *
 *
  <instruction func="op_sti" opcode="0xfb"/>
*/

int op_sti(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_STI;
  new->type = ASM_TYPE_WRITEFLAG;
  /* Should be VIF for CPL = 3 and IOPL < CPL */
  new->flagswritten = ASM_FLAG_IF;
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_stosb.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_stosb" opcode="0xaa"/>
*/

int op_stosb(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) 
{
  new->ptr_instr = opcode;
  new->instr = ASM_STOSB;
  new->len += 1;
  new->type = ASM_TYPE_STORE;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_YDEST, new, 0);
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_XSRC, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_YDEST, new);
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_XSRC, new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_stosd.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_stosd" opcode="0xab"/>
*/

int op_stosd(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) 
{
  new->instr = ASM_STOSD;
  new->ptr_instr = opcode;
  new->len += 1;
  new->type = ASM_TYPE_STORE;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_YDEST, new, 0);
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));

#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_YDEST, new);
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_FIXED, new);
  new->op[1].content = ASM_OP_BASE;
  new->op[1].len = 0;
  new->op[1].regset = asm_proc_opsize(proc) ?
    ASM_REGSET_R16 : ASM_REGSET_R32;
  new->op[1].baser = ASM_REG_EAX;
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_sub_al_ib.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_sub_al_ib" opcode="0x2c"/>
*/

int op_sub_al_ib(asm_instr *new, u_char *opcode, u_int len, 
                 asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_SUB;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF |
                        ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new,
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_AL,
					       ASM_REGSET_R8));
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,
                                ASM_OTYPE_IMMEDIATEBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
  new->op[0].content = ASM_OP_BASE | ASM_OP_FIXED;
  new->op[0].ptr = opcode;
  new->op[0].len = 0;
  new->op[0].regset = ASM_REGSET_R8;
  new->op[0].baser = ASM_REG_AL;
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,
                                ASM_OTYPE_IMMEDIATEBYTE, new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_sub_eax_iv.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 *
 * @ingroup IA32_instrs
 * <instruction func="op_sub_eax_iv" opcode="0x2d"/>
*/

int op_sub_eax_iv(asm_instr *new, u_char *opcode, u_int len, 
                  asm_processor *proc)
{
  new->instr = ASM_SUB;
  new->len += 1;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF |
                        ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));

  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_IMMEDIATE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
  new->op[0].content = ASM_OP_BASE | ASM_OP_FIXED;
  new->op[0].ptr = opcode;
  new->op[0].len = 0;
  new->op[0].regset = ASM_REGSET_R32;
  new->op[0].baser = ASM_REG_EAX;
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_IMMEDIATE, new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_sub_rb_rmb.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_sub_rb_rmb" opcode="0x2a"/>
*/

int op_sub_rb_rmb(asm_instr *new, u_char *opcode, u_int len, 
                  asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_SUB;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF |
                        ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERALBYTE,
                                new, 0);
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODEDBYTE,
                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERALBYTE,
                                new);
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODEDBYTE,
                                new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_sub_rmb_rb.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/*
  <instruction func="op_sub_rmb_rb" opcode="0x28"/>
*/

int op_sub_rmb_rb(asm_instr *new, u_char *opcode, u_int len, 
                  asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_SUB;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF |
                        ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE,
                                new, 0);
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERALBYTE,
                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE,
                                new);
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERALBYTE,
                                new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_sub_rmv_rv.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Handler for instruction sub rmv,rv opcode 0x29
 * @param instr Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
 */

int op_sub_rmv_rv(asm_instr *new, u_char *opcode, u_int len, 
                  asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_SUB;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF |
                        ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,
                                new, 0);
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,
                                ASM_OTYPE_GENERAL, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODED,
                                new);
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,
                                ASM_OTYPE_GENERAL, new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_sub_rv_rmv.c
 * @brief Handler for instruction sub rv,rmv opcode 0x2b
 *
 * @ingroup IA32_instrs
 * 
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Handler for instruction sub rv,rmv opcode 0x2b
 * @param instr Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
 */

int op_sub_rv_rmv(asm_instr *instr, u_char *opcode, u_int len, 
                  asm_processor *proc)
{
  instr->len += 1;
  instr->instr = ASM_SUB;
  instr->ptr_instr = opcode;
  instr->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  instr->flagswritten = ASM_FLAG_AF | ASM_FLAG_CF | ASM_FLAG_PF |
                        ASM_FLAG_OF | ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  instr->len += asm_operand_fetch(&instr->op[0], opcode + 1, ASM_OTYPE_GENERAL, instr, 0);
  instr->len += asm_operand_fetch(&instr->op[1], opcode + 1, ASM_OTYPE_ENCODED, instr, 0);
#else
  instr->len += asm_operand_fetch(&instr->op[0], opcode + 1, ASM_OTYPE_GENERAL, instr);
  instr->len += asm_operand_fetch(&instr->op[1], opcode + 1, ASM_OTYPE_ENCODED, instr);
#endif

  return (instr->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_test_al_rb.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Handler for instruction test al,rb opcode 0xa8
 * @param instr Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
 */

int op_test_al_rb(asm_instr *new, u_char *opcode, u_int len, 
                  asm_processor *proc)
{
  new->instr = ASM_TEST;
  new->len += 1;
  new->type = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_OF | ASM_FLAG_CF | ASM_FLAG_PF |
                          ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_AL,
					       ASM_REGSET_R8));

  new->len += asm_operand_fetch(&new->op[1], opcode + 1,
                                ASM_OTYPE_IMMEDIATEBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
  new->op[0].content = ASM_OP_BASE;
  new->op[0].baser = ASM_REG_AL;
  new->op[0].regset = ASM_REGSET_R8;
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,
                                ASM_OTYPE_IMMEDIATEBYTE, new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_test_eax_iv.c
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Handler for instruction test eax,iv opcode 0xa9
 * @param instr Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
 */

int op_test_eax_iv(asm_instr *new, u_char *opcode, u_int len, 
                   asm_processor *proc)
{
  new->instr = ASM_TEST;
  new->len += 1;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_OF | ASM_FLAG_CF | ASM_FLAG_PF |
                          ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new,
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));

  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_IMMEDIATE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
  new->op[0].content = ASM_OP_BASE;
  new->op[0].regset = asm_proc_opsize(proc) ?
    ASM_REGSET_R16 : ASM_REGSET_R32;
  new->op[0].baser = ASM_REG_AX;
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_IMMEDIATE, new);
#endif

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_test_rmb_rb.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>


/**
 * @brief Handler for instruction test rmb,rb opcode 0x84
 * @param instr Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
 */

int op_test_rmb_rb(asm_instr *new, u_char *opcode, u_int len, 
                   asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_TEST;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_OF | ASM_FLAG_CF | ASM_FLAG_PF |
                      ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,
                                ASM_OTYPE_ENCODEDBYTE, new, 0);
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,
                                ASM_OTYPE_GENERALBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,
                                ASM_OTYPE_ENCODEDBYTE, new);
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,
                                ASM_OTYPE_GENERALBYTE, new);
#endif
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_test_rmv_rv.c
 *
 * @ingroup IA32_instrs
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Handler for instruction test rmv,rv opcode 0x85
 * @param instr Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
 */

int op_test_rmv_rv(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_TEST;
  new->ptr_instr = opcode;
  new->type = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_OF | ASM_FLAG_CF | ASM_FLAG_PF |
                      ASM_FLAG_SF | ASM_FLAG_ZF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,
                                ASM_OTYPE_ENCODED, new, 0);
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,
                                ASM_OTYPE_GENERAL, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1,
                                ASM_OTYPE_ENCODED, new);
  new->len += asm_operand_fetch(&new->op[1], opcode + 1,
                                ASM_OTYPE_GENERAL, new);
#endif
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_ud2a.c
 *
 * @ingroup IA32_instrs
 * @brief Handler for instruction ud2a opcode 0x??
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Handler for instruction ud2a opcode 0x??
 * @param instr Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
 */

int     op_ud2a(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->instr = ASM_UD2A;
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_unary_rmb.c
 *
 * @ingroup IA32_instrs
 * @brief Handler for instruction unary rmb opcode 0xf6
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Handler for instruction unary rmb opcode 0xf6
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
 */

int op_unary_rmb(asm_instr *new, u_char *opcode, u_int len, 
                 asm_processor *proc)
{
  struct s_modrm        *modrm;
  int                    olen;

  new->ptr_instr = opcode;
  modrm = (struct s_modrm *) opcode + 1;
  new->len += 1;
  new->type = ASM_TYPE_ARITH;

  switch(modrm->r) {
    case 0:
      new->instr = ASM_TEST;
      new->type = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
      new->flagswritten = ASM_FLAG_OF | ASM_FLAG_CF | ASM_FLAG_PF |
                          ASM_FLAG_SF | ASM_FLAG_ZF;
      new->op[0].type = ASM_OTYPE_ENCODED;

#if WIP
      new->len += (olen = asm_operand_fetch(&new->op[0], opcode + 1,
                                            ASM_OTYPE_ENCODEDBYTE, new, 0));
      new->len += asm_operand_fetch(&new->op[1], opcode + 1 + olen,
                                    ASM_OTYPE_IMMEDIATEBYTE, new, 0);
#else
      new->len += (olen = asm_operand_fetch(&new->op[0], opcode + 1,
                                            ASM_OTYPE_ENCODEDBYTE, new));
      new->len += asm_operand_fetch(&new->op[1], opcode + 1 + olen,
                                    ASM_OTYPE_IMMEDIATEBYTE, new);
#endif

      break;
    case 1:
      return (0);
      break;
    case 2:
      new->instr = ASM_NOT;
      break;
    case 3:
      new->instr = ASM_NEG;
      new->type |= ASM_TYPE_WRITEFLAG;
      new->flagswritten = ASM_FLAG_CF;
      break;
    case 4:
      new->instr = ASM_MUL;
      new->type |= ASM_TYPE_WRITEFLAG;
      new->flagswritten = ASM_FLAG_OF | ASM_FLAG_CF;
      break;
    case 5:
      new->instr = ASM_IMUL;
      new->type |= ASM_TYPE_WRITEFLAG;
      new->flagswritten = ASM_FLAG_OF | ASM_FLAG_CF;
      break;
    case 6:
      new->instr = ASM_DIV;
      break;
    case 7:
      new->instr = ASM_IDIV;
      break;
    default:
      break;
  }

  if (!new->op[0].type)
  {
#if WIP
    new->len += asm_operand_fetch(&new->op[0], opcode + 1,
                                  ASM_OTYPE_ENCODEDBYTE, new, 0);
#else
    new->len += asm_operand_fetch(&new->op[0], opcode + 1,
                                  ASM_OTYPE_ENCODEDBYTE, new);
#endif
  }
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_unary_rmv.c
 *
 * @ingroup IA32_instrs
 * @brief Handler for instruction unary rmv opcode 0xf7
 * $Id$
 *
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Handler for instruction unary rmv opcode 0xf7
 * @param instr Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
 */

int op_unary_rmv(asm_instr *new, u_char *opcode, u_int len, 
                 asm_processor *proc) 
{
  struct s_modrm        *modrm;
  int                   olen;

  modrm = (struct s_modrm *) (opcode + 1);
  new->ptr_instr = opcode;
  new->len += 1;
  new->type = ASM_TYPE_ARITH;
  switch (modrm->r) {
  case 0:
    new->instr = ASM_TEST;
    new->type = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
    new->flagswritten = ASM_FLAG_OF | ASM_FLAG_CF | ASM_FLAG_PF |
                          ASM_FLAG_SF | ASM_FLAG_ZF;
    break;
  case 1:
    return (0);
  case 2:
    new->instr = ASM_NOT;
    break;
  case 3:
    new->instr = ASM_NEG;
    new->type |= ASM_TYPE_WRITEFLAG;
    new->flagswritten = ASM_FLAG_CF;
    break;
  case 4:
    new->instr = ASM_MUL;
    new->type |= ASM_TYPE_WRITEFLAG;
    new->flagswritten = ASM_FLAG_OF | ASM_FLAG_CF;
    break;
  case 5:
    new->instr = ASM_IMUL;
    new->type |= ASM_TYPE_WRITEFLAG;
    new->flagswritten = ASM_FLAG_OF | ASM_FLAG_CF;
    break;
  case 6:
    new->instr = ASM_DIV;
    break;
  case 7:
    new->instr = ASM_IDIV;
    break;
  } /* switch */

#if WIP
  new->len += (olen = asm_operand_fetch(&new->op[0], opcode + 1,
                                        ASM_OTYPE_ENCODED, new, 0));

  if (new->instr == ASM_TEST) {
    new->len += asm_operand_fetch(&new->op[1], opcode + 1 + olen,
                                  ASM_OTYPE_IMMEDIATE, new, 0);
  }
#else
  new->len += (olen = asm_operand_fetch(&new->op[0], opcode + 1,
                                        ASM_OTYPE_ENCODED, new));

  if (new->instr == ASM_TEST) {
    new->len += asm_operand_fetch(&new->op[1], opcode + 1 + olen,
                                  ASM_OTYPE_IMMEDIATE, new);
  }
#endif
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_xchg_eax_reg.c
 *
 * @ingroup IA32_instrs
 * @brief Handler for instruction xchg eax,reg opcode 0x91 to 0x97
** $Id$
**
*/
#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Handler for instruction xchg eax,reg opcode 0x91 to 0x97
 * @param instr Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
 */

int op_xchg_eax_reg(asm_instr *new, u_char *opcode, u_int len, 
                    asm_processor *proc)
{
  new->instr = ASM_XCHG;
  new->ptr_instr = opcode;
  new->len += 1;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_FIXED, 
                                new,
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_OPMOD, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_FIXED, 
                                new);
  new->op[0].content = ASM_OP_BASE | ASM_OP_FIXED;
  new->op[0].len = 0;
  new->op[0].baser = ASM_REG_EAX;
  new->op[0].regset = asm_proc_opsize(proc) ?
    ASM_REGSET_R16 : ASM_REGSET_R32;
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_OTYPE_OPMOD, new);
#endif
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_xchg_rmb_rb.c
 * @brief Handler for instruction xchg rmb,rb opcode 0x86
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Handler for instruction xchg rmb,rb opcode 0x86
 * @param instr Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
 */

int op_xchg_rmb_rb(asm_instr *instr, u_char *opcode, u_int len, 
                   asm_processor *proc)
{
  instr->len += 1;
  instr->ptr_instr = opcode;
  instr->instr = ASM_XCHG;
  instr->type = ASM_TYPE_LOAD | ASM_TYPE_STORE;

#if WIP
  instr->len += asm_operand_fetch(&instr->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE, 
                                instr, 0);
  instr->len += asm_operand_fetch(&instr->op[1], opcode + 1, ASM_OTYPE_GENERALBYTE, 
                                instr, 0);
#else
  instr->len += asm_operand_fetch(&instr->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE, 
                                instr);
  instr->len += asm_operand_fetch(&instr->op[1], opcode + 1, ASM_OTYPE_GENERALBYTE, 
                                instr);
#endif

  return (instr->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_xchg_rmv_rv.c
 * @brief Handler for instruction xchg rmv,rv opcode 0x87
 *
 * @ingroup IA32_instrs
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Handler for instruction xchg rmv,rv opcode 0x87
 * @param instr Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
 */

int op_xchg_rmv_rv(asm_instr *instr, u_char *opcode, u_int len,
                   asm_processor *proc)
{
  instr->len += 1;
  instr->ptr_instr = opcode;
  instr->instr = ASM_XCHG;
  instr->type = ASM_TYPE_LOAD | ASM_TYPE_STORE;

#if WIP
  instr->len += asm_operand_fetch(&instr->op[0], opcode + 1, ASM_OTYPE_ENCODED, 
                                instr, 0);
  instr->len += asm_operand_fetch(&instr->op[1], opcode + 1, ASM_OTYPE_GENERAL, 
                                instr, 0);
#else
  instr->len += asm_operand_fetch(&instr->op[0], opcode + 1, ASM_OTYPE_ENCODED, 
                                instr);
  instr->len += asm_operand_fetch(&instr->op[1], opcode + 1, ASM_OTYPE_GENERAL, 
                                instr);
#endif
  return (instr->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_xlatb.c
 *
 * @ingroup IA32_instrs
 * @brief <instruction opcode="0xd7" func="op_xlatb"/>
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief <instruction opcode="0xd7" func="op_xlatb"/>
 */

int op_xlatb(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_XLATB;
  new->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN;
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_xor_al_ib.c
 *
 * @ingroup IA32_instrs
 * @brief Handler for instruction xor al,ib opcode 0x34
 * 
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Handler for instruction xor al,ib opcode 0x34
 * @param instr Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Return length of instruction.
 */

int op_xor_al_ib(asm_instr *instr, u_char *opcode, u_int len, asm_processor *proc) {
  instr->instr = ASM_XOR;
  instr->len += 1;
  instr->ptr_instr = opcode;
  instr->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  instr->flagswritten = ASM_FLAG_CF | ASM_FLAG_OF | ASM_FLAG_PF |
    ASM_FLAG_ZF | ASM_FLAG_SF;

#if WIP
  instr->len += asm_operand_fetch(&instr->op[0], opcode, ASM_OTYPE_FIXED, instr,
				  asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_AL,
						 ASM_REGSET_R8));
  instr->len += asm_operand_fetch(&instr->op[1], opcode + 1,
				  ASM_OTYPE_IMMEDIATEBYTE, instr, 0);
#else
  instr->len += asm_operand_fetch(&instr->op[0], opcode, ASM_OTYPE_FIXED, instr);
  instr->op[0].ptr = opcode;
  instr->op[0].len = 0;
  instr->op[0].baser = ASM_REG_AL;
  instr->op[0].regset = ASM_REGSET_R8;
  instr->len += asm_operand_fetch(&instr->op[1], opcode + 1,
				  ASM_OTYPE_IMMEDIATEBYTE, instr);
#endif

  return (instr->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_xor_eax_iv.c
 *
 * @ingroup IA32_instrs
 * @brief Handler for instruction xor eax,iv opcode 0x35
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Handler for instruction xor eax,iv opcode 0x35
 * @param instr Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
 */


int op_xor_eax_iv(asm_instr *new, u_char *opcode, u_int len, 
                  asm_processor *proc)
{
  new->instr = ASM_XOR;
  new->ptr_instr = opcode;
  new->len += 1;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_CF | ASM_FLAG_OF | ASM_FLAG_PF |
                        ASM_FLAG_ZF | ASM_FLAG_SF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new, 
				asm_fixed_pack(0, ASM_OP_BASE, ASM_REG_EAX,
					       asm_proc_is_protected(proc) ?
					       ASM_REGSET_R32 : ASM_REGSET_R16));
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_IMMEDIATE,
                                new, 0);
#else

  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_OTYPE_FIXED, new);
  new->op[0].ptr = opcode;
  new->op[0].len = 0;
  new->op[0].baser = ASM_REG_EAX;
  new->op[0].regset = asm_proc_is_protected(proc) ?
    ASM_REGSET_R32 : ASM_REGSET_R16;
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_IMMEDIATE,
                                new);
#endif

  return (new->len);
}

/**
* @file libasm/src/arch/ia32/handlers/op_xor_rb_rmb.c
 *
 * @ingroup IA32_instrs
 * @brief Handler for instruction xor rb,rmb opcode 0x32
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Handler for instruction xor rb,rmb opcode 0x32
 * @param instr Pointer to instruction structure
 * @param  opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
*/

int op_xor_rb_rmb(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) 
{
  new->instr = ASM_XOR;
  new->len += 1;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_CF | ASM_FLAG_OF | ASM_FLAG_PF |
                        ASM_FLAG_ZF | ASM_FLAG_SF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERALBYTE, new, 0);
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODEDBYTE, new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERALBYTE, new);
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODEDBYTE, new);
#endif  

  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_xor_rmb_rb.c
 *
 * @ingroup IA32_instrs
 * @brief Handler for instruction xor rmb,rb opcode 0x30
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Handler for instruction xor rmb,rb opcode 0x30
 * @param instr Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction disassembled.
*/

int op_xor_rmb_rb(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc) 
{
  new->len += 1;
  new->ptr_instr = opcode;
  new->instr = ASM_XOR;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_CF | ASM_FLAG_OF | ASM_FLAG_PF |
                        ASM_FLAG_ZF | ASM_FLAG_SF;

#if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE,
                                new, 0);
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERALBYTE,
                                new, 0);
#else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_ENCODEDBYTE,
                                new);
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_GENERALBYTE,
                                new);
#endif
  return (new->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_xor_rmv_rv.c
 *
 * @ingroup IA32_instrs
 * @brief Handler for instruction xor rmv,rv opcode 0x31
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Handler for instruction xor rmv,rv opcode 0x31
 * @param instr Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble
 * @param len Length of data to disassemble
 * @param proc Pointer to processor structure
 * @return Insruction length
  <instruction func="op_xor_rmv_rv" opcode="0x31"/>
*/

int op_xor_rmv_rv(asm_instr *instr, u_char *opcode, u_int len, 
                  asm_processor *proc)
{
  instr->len += 1;
  instr->ptr_instr = opcode;
  instr->instr = ASM_XOR;
  instr->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  instr->flagswritten = ASM_FLAG_CF | ASM_FLAG_OF | ASM_FLAG_PF |
                        ASM_FLAG_ZF | ASM_FLAG_SF;

#if WIP
  instr->len += asm_operand_fetch(&instr->op[0], opcode + 1, ASM_OTYPE_ENCODED, instr, 0);
  instr->len += asm_operand_fetch(&instr->op[1], opcode + 1, ASM_OTYPE_GENERAL, instr, 0);
#else
  instr->len += asm_operand_fetch(&instr->op[0], opcode + 1, ASM_OTYPE_ENCODED, instr);
  instr->len += asm_operand_fetch(&instr->op[1], opcode + 1, ASM_OTYPE_GENERAL, instr);
#endif
  return (instr->len);
}
/**
* @file libasm/src/arch/ia32/handlers/op_xor_rv_rmv.c
 *
 * @ingroup IA32_instrs
 * @brief Handler for instruction xor, opcode 0x33
 * $Id$
 *
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Handler for instruction xor, opcode 0x33
 * @param new Pointer to instruction structure.
 * @param opcode Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @return Length of instruction.
 */

int op_xor_rv_rmv(asm_instr *new, u_char *opcode, u_int len, 
                  asm_processor *proc)
{
  new->instr = ASM_XOR;
  new->ptr_instr = opcode;
  new->len += 1;
  new->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  new->flagswritten = ASM_FLAG_CF | ASM_FLAG_OF | ASM_FLAG_PF |
                        ASM_FLAG_ZF | ASM_FLAG_SF;

  #if WIP
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL, new, 0);
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED, new, 0);
  #else
  new->len += asm_operand_fetch(&new->op[0], opcode + 1, ASM_OTYPE_GENERAL, new);
  new->len += asm_operand_fetch(&new->op[1], opcode + 1, ASM_OTYPE_ENCODED, new);
  #endif
  return (new->len);
}
/**
 * @defgroup IA32_operands Libasm IA32 operands handlers.
 * @ingroup ia32
 */
/**
* @file libasm/src/arch/ia32/operand_handlers/asm_operand_fetch_address.c
 * @ingroup IA32_operands
 * $Id$
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * Fetch operands of 
 *
 *
 */
/**
 * @ingroup IA32_operands
 * Decode data for operand type ASM_OTYPE_YDEST
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to operand data
 * @param otype
 * @param ins Pointer to instruction structure.
 * @return Operand length
 */
#if WIP
int     asm_operand_fetch_address(asm_operand *operand, u_char *opcode, int otype, 
				asm_instr *ins, int opt)
#else
int     asm_operand_fetch_address(asm_operand *operand, u_char *opcode, 
				  int otype, 
                                  asm_instr *ins)
#endif
{
  u_int	len;

  operand->type = ASM_OTYPE_ADDRESS;
  operand->content = ASM_OP_VALUE;
  operand->ptr = opcode;
  operand->imm = 0;
  len = asm_proc_opsize(ins->proc) ? 2 : 4;
  operand->len = len;
  memcpy(&operand->imm, opcode, len);
  if (len == 2)
    operand->imm = operand->imm & 0xFFFF;
  return (len);
}
/**
* @file libasm/src/arch/ia32/operand_handlers/asm_operand_fetch.c
 *
 * @ingroup IA32_operands
 * @brief Implements top-level fetching handler for IA32 operands.
 *
 * $Id$
 */
#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Main function, dispatch processing to handler.
 *
 * @ingroup IA32_operands
 * @param op Pointer to operand to fill
 * @param opcode Pointer to operand data.
 * @param otype Type of operand to fetch : ASM_OTYPE_*
 * @param proc Pointer to processor structure.
 * @return Operand length or -1 on error (should currently never occur)
 */

#if WIP
int     asm_operand_fetch(asm_operand *operand, u_char *opcode, int otype, 
				asm_instr *ins, int opt)
#else
int     asm_operand_fetch(asm_operand *operand, u_char *opcode, int otype, 
			  asm_instr *ins)
#endif
{ 
  vector_t      *vec;
  u_int         dim[1];
  int           to_ret;
#if WIP
  int           (*fetch)(asm_operand *, u_char *, int, asm_instr *, int);
#else
  int           (*fetch)(asm_operand *, u_char *, int, asm_instr *);
#endif

  vec = aspect_vector_get(LIBASM_VECTOR_OPERAND_IA32);
  dim[0] = otype;
  
  fetch = aspect_vectors_select(vec, dim);
#if WIP
  to_ret = fetch(operand, opcode, otype, ins, opt);
#else
  to_ret = fetch(operand, opcode, otype, ins);
#endif
  if (to_ret == -1)
    {
      printf("%s:%i Unsupported operand type : %i\n", __FILE__, __LINE__, 
	     otype);
    }
  else
    {
      operand->sbaser = ((operand->content & ASM_OP_BASE) ? 
		    get_reg_intel(operand->baser, operand->regset) : "");
      operand->sindex = ((operand->content & ASM_OP_BASE) ? 
		    get_reg_intel(operand->indexr, operand->regset) : "");
    }
  return (to_ret);
}
/**
* @file libasm/src/arch/ia32/operand_handlers/asm_operand_fetch_control.c
 *
 * @ingroup IA32_operands
 * $Id$
 */

#include <libasm.h>
#include <libasm-int.h>

/**
 * Decode data for operand type ASM_OTYPE_CONTROL
 *
 * @ingroup IA32_operands
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to operand data
 * @param otype
 * @param ins Pointer to instruction structure.
 * @return Operand length
 */

#if WIP
int     asm_operand_fetch_control(asm_operand *operand, u_char *opcode, int otype, 
				asm_instr *ins, int opt)
#else
int     asm_operand_fetch_control(asm_operand *operand, u_char *opcode, int otype, 
                                  asm_instr *ins)
#endif
{
  struct s_modrm        *modrm;

  modrm = (struct s_modrm *) opcode;
  operand->type = ASM_OTYPE_CONTROL;
  operand->content = ASM_OP_BASE;
  operand->regset = ASM_REGSET_CREG;
  operand->baser = modrm->r;
  operand->ptr = opcode;
  operand->imm = 0;
  operand->len = 0;
  operand->sbaser = get_reg_intel(operand->baser, operand->regset);
  operand->sindex = get_reg_intel(operand->indexr, operand->regset);
  return (1);
}
/**
* @file libasm/src/arch/ia32/operand_handlers/asm_operand_fetch_debug.c
 *
 * @ingroup IA32_operands
 * $Id$
 */

#include <libasm.h>
#include <libasm-int.h>


/**
 *
 *
 */
/**
 * Decode data for operand type ASM_OTYPE_YDEST
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to operand data
 * @param otype
 * @param ins Pointer to instruction structure.
 * @return Operand length
 */

#if WIP
int     asm_operand_fetch_debug(asm_operand *operand, u_char *opcode, int otype, 
				asm_instr *ins, int opt)
#else
int     asm_operand_fetch_debug(asm_operand *operand, u_char *opcode, int otype,
				asm_instr *ins)
#endif
{ 
  struct s_modrm        *modrm;
  
  modrm = (struct s_modrm *) opcode;
  operand->type = ASM_OTYPE_DEBUG;
  operand->content = ASM_OP_BASE;
  operand->regset = ASM_REGSET_CREG;
  operand->baser = modrm->r;
  operand->ptr = opcode;
  operand->imm = 0;
  operand->len = 0;
  operand->sbaser = get_reg_intel(operand->baser, operand->regset);
  operand->sindex = get_reg_intel(operand->indexr, operand->regset);
  return (1);
}
/**
* @file libasm/src/arch/ia32/operand_handlers/asm_operand_fetch_encodedbyte.c
 *
 * @ingroup IA32_operands
 * $Id$
 */

#include <libasm.h>
#include <libasm-int.h>

/**
 *
 * @ingroup IA32_operands
 * Decode data for operand type ASM_OTYPE_ENCODEDBYTE
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to operand data
 * @param otype
 * @param ins Pointer to instruction structure.
 * @return Operand length
 */

#if WIP
int     asm_operand_fetch_encodedbyte(asm_operand *operand, u_char *opcode, int otype, 
				asm_instr *ins, int opt)
#else
int     asm_operand_fetch_encodedbyte(asm_operand *operand, u_char *opcode, 
				      int otype, asm_instr *ins)
#endif
{ 
  int	len;
  
  operand->type = ASM_OTYPE_ENCODED;
  len = operand_rmb(operand, opcode, 5, ins->proc);
  operand->sbaser = get_reg_intel(operand->baser, operand->regset);
  operand->sindex = get_reg_intel(operand->indexr, operand->regset);
  return (len);
}
/**
* @file libasm/src/arch/ia32/operand_handlers/asm_operand_fetch_encoded.c
 *
 * @ingroup IA32_operands
 * $Id$
 */

#include <libasm.h>
#include <libasm-int.h>


/**
 *
 * @ingroup IA32_operands
 * Decode data for operand type ASM_OTYPE_ENCODED
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to operand data
 * @param otype
 * @param ins Pointer to instruction structure.
 * @return Operand length
 */

#if WIP
int     asm_operand_fetch_encoded(asm_operand *operand, u_char *opcode, int otype, 
				asm_instr *ins, int opt)
#else
int     asm_operand_fetch_encoded(asm_operand *operand, u_char *opcode, 
				  int otype, asm_instr *ins)
#endif
{
  int	len;
  operand->type = ASM_OTYPE_ENCODED;
  len = operand_rmv(operand, opcode, 4, ins->proc);
  operand->sbaser = get_reg_intel(operand->baser, operand->regset);
  operand->sindex = get_reg_intel(operand->indexr, operand->regset);
  return (len);
}
/**
* @file libasm/src/arch/ia32/operand_handlers/asm_operand_fetch_fixed.c
 *
 * @ingroup IA32_operands
 * $Id$
 */

#include <libasm.h>
#include <libasm-int.h>

/**
 * @todo
 * Implement optional parameter for fixed operand fetching.
 */
/**
 *
 * @ingroup IA32_operands
 * Decode data for operand type ASM_OTYPE_YDEST
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to operand data
 * @param otype
 * @param ins Pointer to instruction structure.
 * @return Operand length
 */

#if WIP
int     asm_operand_fetch_fixed(asm_operand *operand, u_char *opcode, int otype, 
				asm_instr *ins, int opt)
#else
int     asm_operand_fetch_fixed(asm_operand *operand, u_char *opcode, 
				int otype, asm_instr *ins)
#endif
{
  operand->type = ASM_OTYPE_FIXED;
  #if WIP
  /**
   * @todo extract fields.
  operand->content = asm_fixed_unpack_content();
  operand->regset = asm_fixed_unpack_regset();
  operand->
  */
#endif
  return (0);
}
/**
* @file libasm/src/arch/ia32/operand_handlers/asm_operand_fetch_generalbyte.c
 *
 * @ingroup IA32_operands
 * $Id$
 */

#include <libasm.h>
#include <libasm-int.h>

/**
 * Decode data for operand type ASM_OTYPE_GENERALBYTE
 *
 * @ingroup IA32_operands
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to operand data
 * @param otype
 * @param ins Pointer to instruction structure.
 * @return Operand length
 */

#if WIP
int     asm_operand_fetch_generalbyte(asm_operand *operand, u_char *opcode, int otype, 
				asm_instr *ins, int opt)
#else
int     asm_operand_fetch_generalbyte(asm_operand *operand, u_char *opcode, 
				      int type, asm_instr *ins)
#endif
{ 
  struct s_modrm        *modrm;
  
  operand->type = ASM_OTYPE_GENERAL;
  operand->content = ASM_OP_BASE;
  operand->regset = ASM_REGSET_R8;
  modrm = (struct s_modrm *) opcode;
  operand->baser = modrm->r;
  operand->sbaser = get_reg_intel(operand->baser, operand->regset);
  operand->sindex = get_reg_intel(operand->indexr, operand->regset);
  return (operand->len = 0);
}
/**
* @file libasm/src/arch/ia32/operand_handlers/asm_operand_fetch_general.c
 *
 * @ingroup IA32_operands
 * $Id$
 * @brief Operand Handler to decode data for operand type ASM_OTYPE_GENERAL
 */

#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Decode data for operand type ASM_OTYPE_GENERAL
 *
 * @ingroup IA32_operands
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to operand data
 * @param type Not used.
 * @param ins Pointer to instruction structure.
 * @return Operand length
 */

#if WIP
int     asm_operand_fetch_general(asm_operand *operand, u_char *opcode, 
				  int type, asm_instr *ins, int opt)
#else
int     asm_operand_fetch_general(asm_operand *operand, u_char *opcode, 
				  int type, asm_instr *ins)
#endif
{
  struct s_modrm        *modrm;
  
  operand->type = ASM_OTYPE_GENERAL;
  operand->content = ASM_OP_BASE;
  operand->regset = asm_proc_is_protected(ins->proc) ? 
    ASM_REGSET_R32 : ASM_REGSET_R16;
  modrm = (struct s_modrm *) opcode;
  operand->baser = modrm->r;
  operand->sbaser = get_reg_intel(operand->baser, operand->regset);
  operand->len = 0;
  return (0);
}
/**
* @file libasm/src/arch/ia32/operand_handlers/asm_operand_fetch_immediatebyte.c
 *
 * @ingroup IA32_operands
 * $Id$
 */

#include <libasm.h>
#include <libasm-int.h>

/**
 * Handler to fetch ASM_OTYPE_IMMEDIATEBYTE operand.
 *
 * @ingroup IA32_operands
 * @param operand Pointer to operand structure.
 * @param opcode Pointer to data to disassemble.
 * @param otype Operand type.
 * @param proc Pointer to processor structure.
 * @return Operand Length
 */

#if WIP
int     asm_operand_fetch_immediatebyte(asm_operand *operand, u_char *opcode, int otype, 
				asm_instr *ins, int opt)
#else
int     asm_operand_fetch_immediatebyte(asm_operand *operand, u_char *opcode, 
					int otype, asm_instr *ins)
#endif
{ 
  u_int	len;

  operand->type = ASM_OTYPE_IMMEDIATE;
  operand->content = ASM_OP_VALUE;
  operand->ptr = opcode;
  operand->imm = 0;
  operand->len = 1;
  if (*opcode >= 0x80)
    {
      len = asm_proc_opsize(ins->proc) ? 2 : 4;
      //memset(&operand->imm, 0xff, 4);
      memset(&operand->imm, 0xff, len);
    }
  memcpy(&operand->imm, opcode, 1);
  return (1);
}
/**
* @file libasm/src/arch/ia32/operand_handlers/asm_operand_fetch_immediate.c
 *
 * @ingroup IA32_operands
 * $Id$
 */

#include <libasm.h>
#include <libasm-int.h>

/**
 *
 *
 */
/**
 * Decode data for operand type ASM_OTYPE_YDEST
 *
 * @ingroup IA32_operands
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to operand data
 * @param otype
 * @param ins Pointer to instruction structure.
 * @return Operand length
 */

#if WIP
int     asm_operand_fetch_immediate(asm_operand *operand, u_char *opcode, int otype, 
				asm_instr *ins, int opt)
#else
int     asm_operand_fetch_immediate(asm_operand *operand, u_char *opcode, 
				    int otype, asm_instr *ins)
#endif
{
  operand->type = ASM_OTYPE_IMMEDIATE;
  operand->content = ASM_OP_VALUE;
  operand->ptr = opcode;
  operand->imm = 0;
  operand->len = asm_proc_opsize(ins->proc) ? 2 : 4;
  memcpy(&operand->imm, opcode, operand->len);
  return (operand->len);
}
/**
* @file libasm/src/arch/ia32/operand_handlers/asm_operand_fetch_immediateword.c
 *
 * @ingroup IA32_operands
 * $Id$
 */

#include <libasm.h>
#include <libasm-int.h>

/**
 * Decode data for operand type ASM_OTYPE_YDEST
 *
 * @ingroup IA32_operands
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to operand data
 * @param otype
 * @param ins Pointer to instruction structure.
 * @return Operand length
 */

#if WIP
int     asm_operand_fetch_immediateword(asm_operand *operand, u_char *opcode, int otype, 
				asm_instr *ins, int opt)
#else
int     asm_operand_fetch_immediateword(asm_operand *operand, u_char *opcode, 
					int otype, asm_instr *ins)
#endif
{ 
  operand->type = ASM_OTYPE_IMMEDIATE;
  operand->content = ASM_OP_VALUE;
  operand->ptr = opcode;
  operand->imm = 0;
  operand->len = 2;
  memcpy(&operand->imm, opcode, 2);
  return (2);
}
/**
* @file libasm/src/arch/ia32/operand_handlers/asm_operand_fetch_jump.c
 *
 * @ingroup IA32_operands
 * $Id$
 */

#include <libasm.h>
#include <libasm-int.h>
/**
 *
 *
 */
/**
 * Decode data for operand type ASM_OTYPE_YDEST
 *
 * @ingroup IA32_operands
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to operand data
 * @param otype
 * @param ins Pointer to instruction structure.
 * @return Operand length
 */

#if WIP
int     asm_operand_fetch_jump(asm_operand *operand, u_char *opcode, int otype, 
				asm_instr *ins, int opt)
#else
int     asm_operand_fetch_jump(asm_operand *operand, u_char *opcode, 
			       int otype, asm_instr *ins)
#endif
{ 
  u_int	len;

  operand->type = ASM_OTYPE_JUMP;
  operand->content = ASM_OP_VALUE | ASM_OP_ADDRESS;
  operand->ptr = opcode;
  operand->imm = 0;
  len = asm_proc_opsize(ins->proc) ? 2 : 4;
  operand->len = len;
  memcpy(&operand->imm, opcode, len);
  operand->sbaser = get_reg_intel(operand->baser, operand->regset);
  return (len);
}
/**
* @file libasm/src/arch/ia32/operand_handlers/asm_operand_fetch_memory.c
 * $Id$
 */

#include <libasm.h>
#include <libasm-int.h>
/**
 *
 *
 */
/**
 * Decode data for operand type ASM_OTYPE_YDEST
 *
 * @ingroup IA32_operands
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to operand data
 * @param otype
 * @param ins Pointer to instruction structure.
 * @return Operand length
 */

#if WIP
int     asm_operand_fetch_memory(asm_operand *operand, u_char *opcode, int otype, 
				asm_instr *ins, int opt)
#else
int     asm_operand_fetch_memory(asm_operand *operand, u_char *opcode, 
				 int otype, asm_instr *ins)
#endif
{
  struct s_modrm        *modrm;

  modrm = (struct s_modrm *) opcode;
  operand->type = ASM_OTYPE_MEMORY;

  operand->content = ASM_OP_BASE;
  operand->regset = ASM_REGSET_R32;
  operand->baser = modrm->r;
  operand->sbaser = get_reg_intel(operand->baser, operand->regset);

  return (0);
}

/**
* @file libasm/src/arch/ia32/operand_handlers/asm_operand_fetch_offset.c
 * $Id$
 */

#include <libasm.h>
#include <libasm-int.h>
/**
 *
 *
 */
/**
 * Decode data for operand type ASM_OTYPE_YDEST
 *
 * @ingroup IA32_operands
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to operand data
 * @param otype
 * @param ins Pointer to instruction structure.
 * @return Operand length
 */

#if WIP
int     asm_operand_fetch_offset(asm_operand *operand, u_char *opcode, int otype, 
				asm_instr *ins, int opt)
#else
int     asm_operand_fetch_offset(asm_operand *operand, u_char *opcode, 
				 int otype, asm_instr *ins)
#endif
{
  u_int	len;

  operand->type = ASM_OTYPE_OFFSET;
  operand->content = ASM_OP_VALUE | ASM_OP_REFERENCE;
  operand->ptr = opcode;
  operand->imm = 0;
  operand->regset = asm_proc_is_protected(ins->proc) ? ASM_REGSET_R32 : ASM_REGSET_R16;
  len = asm_proc_opsize(ins->proc) ? 2 : 4;
  operand->len = len;
  memcpy(&operand->imm, opcode, len);
  operand->sbaser = get_reg_intel(operand->baser, operand->regset);
  return (len);
}
/**
* @file libasm/src/arch/ia32/operand_handlers/asm_operand_fetch_opmod.c
 * $Id$
 */

#include <libasm.h>
#include <libasm-int.h>

/**
 * Decode data for operand type ASM_OTYPE_YDEST
 *
 * @ingroup IA32_operands
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to operand data
 * @param otype
 * @param ins Pointer to instruction structure.
 * @return Operand length
 */

#if WIP
int     asm_operand_fetch_opmod(asm_operand *operand, u_char *opcode, int otype, 
				asm_instr *ins, int opt)
#else
int     asm_operand_fetch_opmod(asm_operand *operand, u_char *opcode, 
				int type, asm_instr *ins)
#endif
{
  struct s_modrm        *modrm;
  operand->regset = asm_proc_opsize(ins->proc) ? 
    ASM_REGSET_R16 : ASM_REGSET_R32;
  operand->type = ASM_OTYPE_OPMOD;
  operand->content = ASM_OP_BASE;
  operand->regset = asm_proc_opsize(ins->proc) ? 
    ASM_REGSET_R16 : ASM_REGSET_R32;
  modrm = (struct s_modrm *) opcode;
  operand->baser = modrm->m;
  operand->sbaser = get_reg_intel(operand->baser, operand->regset);
  return (0);
}
/**
* @file libasm/src/arch/ia32/operand_handlers/asm_operand_fetch_pmmx.c
 * $Id$
 */

#include <libasm.h>
#include <libasm-int.h>

/**
 * Fetch ASM_OTYPE_PMMX operand
 *
 *
 */
/**
 * Decode data for operand type ASM_OTYPE_PMMX
 *
 * @ingroup IA32_operands
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to operand data
 * @param otype
 * @param ins Pointer to instruction structure.
 * @return Operand length
 */

#if WIP
int     asm_operand_fetch_pmmx(asm_operand *operand, u_char *opcode, int otype, 
				asm_instr *ins, int opt)
#else
int     asm_operand_fetch_pmmx(asm_operand *operand, u_char *opcode, 
			       int otype, asm_instr *ins)
#endif
{
  int           len;
  operand->type = ASM_OTYPE_PMMX;
  len = operand_rmv(operand, opcode, 4, ins->proc);
  asm_content_pack(operand, operand->content, operand->type);
  operand->regset = ASM_REGSET_MM;
  operand->sbaser = get_reg_intel(operand->baser, operand->regset);
  return (len);
}
/**
* @file libasm/src/arch/ia32/operand_handlers/asm_operand_fetch_register.c
 * $Id$
 */

#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Decode data for operand type ASM_OTYPE_YDEST
 *
 * @ingroup IA32_operands
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to operand data
 * @param otype
 * @param ins Pointer to instruction structure.
 * @return Operand length
 */

#if WIP
int     asm_operand_fetch_register(asm_operand *operand, u_char *opcode, int otype, 
				asm_instr *ins, int opt)
#else
int     asm_operand_fetch_register(asm_operand *operand, u_char *opcode, 
				   int otype, asm_instr *ins)
#endif
{
  struct s_modrm        *modrm;

  modrm = (struct s_modrm *) opcode;
  asm_content_pack(operand, ASM_OP_BASE, ASM_OTYPE_REGISTER);
  //operand->type = ASM_OTYPE_REGISTER;
  //operand->content = ASM_OP_BASE;
  operand->regset = asm_proc_opsize(ins->proc) ? 
    ASM_REGSET_R16 : ASM_REGSET_R32;
  operand->baser = modrm->m;
  operand->sbaser = get_reg_intel(operand->baser, operand->regset);
  operand->ptr = opcode;
  operand->imm = 0;
  operand->len = 0;
  return (0);
}
/**
* @file libasm/src/arch/ia32/operand_handlers/asm_operand_fetch_segment.c
 *
 * @ingroup IA32_operands
 */

#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Decode data for operand type ASM_OTYPE_YDEST
 *
 * @ingroup IA32_operands
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to operand data
 * @param otype
 * @param ins Pointer to instruction structure.
 * @return Operand length
 */

#if WIP
int     asm_operand_fetch_segment(asm_operand *operand, u_char *opcode, 
				  int otype, asm_instr *ins, int opt)
#else
int     asm_operand_fetch_segment(asm_operand *operand, u_char *opcode, 
				  int otype, asm_instr *ins)
#endif
{
  struct s_modrm        *modrm;

  modrm = (struct s_modrm *) opcode;
  
#if WIP
  asm_content_pack(operand, ASM_OP_BASE, ASM_OTYPE_SEGMENT);
#else
  operand->type = ASM_OTYPE_SEGMENT;
  operand->content = ASM_OP_BASE;
#endif

  operand->regset = ASM_REGSET_SREG;
  operand->baser = modrm->r;
  operand->sbaser = get_reg_intel(operand->baser, operand->regset);

  return (0);
}
/**
* @file libasm/src/arch/ia32/operand_handlers/asm_operand_fetch_shortjump.c
 *
 * @ingroup IA32_operands
 */

#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Decode data for operand type ASM_OTYPE_SHORTJUMP
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to operand data
 * @param otype
 * @param ins Pointer to instruction structure.
 * @return Operand length
 */
#if WIP
int     asm_operand_fetch_shortjump(asm_operand *operand, u_char *opcode, 
				    int otype, asm_instr *ins, int opt)
#else
int     asm_operand_fetch_shortjump(asm_operand *operand, u_char *opcode, 
				    int otype, asm_instr *ins)
#endif
{
  u_int	len;

#if WIP
  asm_content_pack(operand, ASM_OP_VALUE | ASM_OP_ADDRESS, ASM_OTYPE_SHORTJUMP);
#else
  operand->content = ASM_OP_VALUE |ASM_OP_ADDRESS;
  operand->type = ASM_OTYPE_SHORTJUMP;
#endif
  operand->len = 1;
  operand->imm = 0;

  //if (*(opcode) >= 0x80u)
  //memcpy((char *) &operand->imm + 1, "\xff\xff\xff", 3);
  len = asm_proc_opsize(ins->proc) ? 1 : 3;
  if (*(opcode) >= 0x80u)
    memset((char *) &operand->imm + 1, 0xFF, len);

  memcpy(&operand->imm, opcode, 1);
  return (1);
}
/**
* @file libasm/src/arch/ia32/operand_handlers/asm_operand_fetch_xsrc.c
 *
 * @ingroup IA32_operands
 */

#include <libasm.h>
#include <libasm-int.h>


/**
 * Decode data for operand type ASM_OTYPE_YDEST
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to operand data
 * @param otype
 * @param ins Pointer to instruction structure.
 * @return Operand length
 */

#if WIP
int     asm_operand_fetch_xsrc(asm_operand *operand, u_char *opcode, 
			       int otype, asm_instr *ins, int opt)
#else
int     asm_operand_fetch_xsrc(asm_operand *operand, u_char *opcode, 
			       int otype, asm_instr *ins)
#endif
{
#if WIP
  asm_content_pack(operand, ASM_OP_BASE | ASM_OP_REFERENCE, ASM_OTYPE_XSRC);
#else
  operand->type = ASM_OTYPE_XSRC;
  operand->content = ASM_OP_BASE | ASM_OP_REFERENCE;
#endif
  operand->baser = ASM_REG_ESI;
  operand->regset = asm_proc_opsize(ins->proc) ? 
    ASM_REGSET_R16 : ASM_REGSET_R32;
  operand->sbaser = get_reg_intel(operand->baser, operand->regset);
  operand->prefix = ASM_PREFIX_DS;
  return (0);
}
/**
* @file libasm/src/arch/ia32/operand_handlers/asm_operand_fetch_ydest.c
 * @brief Wrapper to call operand handler.
 *
 * @ingroup IA32_operands
 */

#include <libasm.h>
#include <libasm-int.h>

/**
 * @brief Decode data for operand type ASM_OTYPE_YDEST
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to operand data
 * @param otype
 * @param ins Pointer to instruction structure.
 * @return Operand length
 */

#if WIP
int     asm_operand_fetch_ydest(asm_operand *operand, u_char *opcode, int otype, 
				asm_instr *ins, int opt)
#else
int     asm_operand_fetch_ydest(asm_operand *operand, u_char *opcode, int otype, 
				asm_instr *ins)
#endif
{
#if WIP
  asm_content_pack(operand, ASM_OP_BASE|ASM_OP_REFERENCE,ASM_OTYPE_YDEST);
#else
  operand->type = ASM_OTYPE_YDEST;
  operand->content = ASM_OP_BASE | ASM_OP_REFERENCE;
#endif
  //asm_content_pack()
  operand->baser = ASM_REG_EDI;
  operand->regset = asm_proc_opsize(ins->proc) ? ASM_REGSET_R16 : ASM_REGSET_R32;
  operand->sbaser = get_reg_intel(operand->baser, operand->regset);
  operand->prefix = ASM_PREFIX_ES;
  return (0);
}
