/**
* @file libasm/src/arch/arm/handlers/asm_arm_adc.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_adc(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_dataproc opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_dataproc(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->dataproc_table[(opcode.op2 << 5) | (opcode.cond << 1) | opcode.s];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ARITH | ASM_TYPE_READFLAG);

  ins->flagsread |= ASM_ARM_FLAG_C;

  ins->nb_op = 3;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);
  ins->op[1].baser = opcode.rn;
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_dataproc_shfop(ins, buf, 2, &opcode);

  /* Decode flags related behaviour */
  arm_decode_dataproc_flagswritten(ins, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_add.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_add(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_dataproc opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_dataproc(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->dataproc_table[(opcode.op2 << 5) | (opcode.cond << 1) | opcode.s];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ARITH);

  ins->nb_op = 3;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);
  ins->op[1].baser = opcode.rn;
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_dataproc_shfop(ins, buf, 2, &opcode);

  /* Decode flags related behaviour */
  arm_decode_dataproc_flagswritten(ins, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);

}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_and.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_and(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_dataproc opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_dataproc(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->dataproc_table[(opcode.op2 << 5) | (opcode.cond << 1) | opcode.s];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ARITH);

  ins->nb_op = 3;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);
  ins->op[1].baser = opcode.rn;
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_dataproc_shfop(ins, buf, 2, &opcode);

  /* Decode flags related behaviour */
  arm_decode_dataproc_flagswritten(ins, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_b.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_b(asm_instr * ins, u_char * buf, u_int len, 
                                        asm_processor * proc)
{
  struct s_arm_decode_branch1 opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_branch1(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->branch1_table[(opcode.l_h << 4) | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_BRANCH);

  ins->nb_op = 1;

  /* Decode operands */
  ins->op[0].imm = opcode.signed_imm;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_DISP, ins);

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_bic.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_bic(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_dataproc opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_dataproc(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->dataproc_table[(opcode.op2 << 5) | (opcode.cond << 1) | opcode.s];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_BITSET);

  ins->nb_op = 3;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);
  ins->op[1].baser = opcode.rn;
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_dataproc_shfop(ins, buf, 2, &opcode);

  /* Decode flags related behaviour */
  arm_decode_dataproc_flagswritten(ins, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_bkpt.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_bkpt(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_bkpt opcode;

  LIBASM_PROFILE_FIN();

  arm_convert_bkpt(&opcode, buf);

  ins->instr = ASM_ARM_BKPT;

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_INT);

  ins->nb_op = 1;

  /* Decode operands */
  ins->op[0].imm = (opcode.immed1 << 4) | opcode.immed2;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_IMMEDIATE, ins);

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_bl.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_bl(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_branch1 opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_branch1(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->branch1_table[(opcode.l_h << 4) | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_CALLPROC);

  ins->nb_op = 1;

  /* Decode operands */
  ins->op[0].imm = opcode.signed_imm;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_DISP, ins);

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_blx1.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_blx1(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_branch1 opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_branch1(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->branch1_table[(opcode.l_h << 4) | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  /* Imperative call proc */
  MASSIGNTYPE(ins, (ASM_TYPE_CALLPROC | ASM_TYPE_ARCH));

  ins->nb_op = 1;

  /* Decode operands */
  ins->op[0].imm = opcode.signed_imm;
  asm_arm_op_fetch(&ins->op[0], buf, opcode.l_h ? ASM_ARM_OTYPE_DISP_HALF : ASM_ARM_OTYPE_DISP, ins);

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_blx2.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_blx2(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_branch2 opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_branch2(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->branch2_table[(opcode.op << 4) | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, (ASM_TYPE_CALLPROC | ASM_TYPE_INDCONTROL | ASM_TYPE_ARCH));

  ins->nb_op = 1;

  /* Decode operands */
  ins->op[0].baser = opcode.rm;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_bx.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_bx(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_branch2 opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_branch2(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->branch2_table[(opcode.op << 4) | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  if (opcode.rm == ASM_ARM_REG_R14)
    /* This is a return */
    MASSIGNTYPE(ins, ASM_TYPE_RETPROC);
  else
    MASSIGNTYPE(ins, ASM_TYPE_BRANCH);
  MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL | ASM_TYPE_ARCH); /* Change to Thumb/ARM */

  ins->nb_op = 1;

  /* Decode operands */
  ins->op[0].baser = opcode.rm;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_cdp.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_cdp(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_coproc_dataproc opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_coproc_dataproc(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->coproc_dataproc_table[opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ARITH);

  ins->nb_op = 6;

  /* Decode operands */
  ins->op[0].imm = opcode.cpnum;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_COPROC, ins);

  ins->op[1].imm = opcode.op1;
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_IMMEDIATE, ins);

  ins->op[2].baser = opcode.crd;
  ins->op[2].destination = 1;
  asm_arm_op_fetch(&ins->op[2], buf, ASM_ARM_OTYPE_COPROC_REGISTER, ins);

  ins->op[3].baser = opcode.crn;
  asm_arm_op_fetch(&ins->op[3], buf, ASM_ARM_OTYPE_COPROC_REGISTER, ins);

  ins->op[4].baser = opcode.crm;
  asm_arm_op_fetch(&ins->op[4], buf, ASM_ARM_OTYPE_COPROC_REGISTER, ins);

  ins->op[5].imm = opcode.op2;
  asm_arm_op_fetch(&ins->op[5], buf, ASM_ARM_OTYPE_IMMEDIATE, ins);

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_clz.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_clz(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_dataproc opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_dataproc(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->clz_table[opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_BITTEST);

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[1].baser = opcode.rm;
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REGISTER, ins);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_cmn.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_cmn(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_dataproc opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_dataproc(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->dataproc_table[(opcode.op2 << 5) | (opcode.cond << 1) | opcode.s];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_COMPARISON);

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = opcode.rn;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_dataproc_shfop(ins, buf, 1, &opcode);

  /* Decode flags related behaviour */
  arm_decode_dataproc_flagswritten(ins, &opcode);

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_cmp.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_cmp(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_dataproc opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_dataproc(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->dataproc_table[(opcode.op2 << 5) | (opcode.cond << 1) | opcode.s];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_COMPARISON);

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = opcode.rn;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_dataproc_shfop(ins, buf, 1, &opcode);

  /* Decode flags related behaviour */
  arm_decode_dataproc_flagswritten(ins, &opcode);

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_eor.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_eor(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_dataproc opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_dataproc(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->dataproc_table[(opcode.op2 << 5) | (opcode.cond << 1) | opcode.s];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ARITH);

  ins->nb_op = 3;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);
  ins->op[1].baser = opcode.rn;
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_dataproc_shfop(ins, buf, 2, &opcode);

  /* Decode flags related behaviour */
  arm_decode_dataproc_flagswritten(ins, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
#include "libasm.h"

int     asm_arm_illegal(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  LIBASM_PROFILE_FIN();

  ins->instr = ASM_ARM_BAD;

  MASSIGNTYPE(ins, ASM_TYPE_STOP);

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_ldc.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_ldc(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_coproc_ldst opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_coproc_ldst(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->coproc_ldst_table[(opcode.l << 5) | (opcode.cond << 1) | opcode.n];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_LOAD);

  ins->nb_op = 3;

  /* Decode operands */
  ins->op[0].imm = opcode.cpnum;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_COPROC, ins);

  ins->op[1].baser = opcode.crd;
  ins->op[1].destination = 1;
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_COPROC_REGISTER, ins);

  arm_decode_coproc_ldst_offop(ins, buf, 2, &opcode);

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_ldm.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_ldm1(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_ldst_mult opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_ldst_mult(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->ldst_mult_table[(opcode.l << 6) | (opcode.cond << 2) | (opcode.p << 1) | opcode.u];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_LOAD | ASM_TYPE_ARCH);

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = opcode.rn;
  if (opcode.w)
    ins->op[0].indexing = ASM_ARM_ADDRESSING_POSTINDEXED;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[1].imm = opcode.reg_list;
  ins->op[1].destination = 1;
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REG_LIST, ins);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_ldm.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_ldm2(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_ldst_mult opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_ldst_mult(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->ldst_mult_table[(opcode.l << 6) | (opcode.cond << 2) | (opcode.p << 1) | opcode.u];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_LOAD);

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = opcode.rn;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[1].imm = opcode.reg_list;
  ins->op[1].destination = 1;
  /* User mode registers are loaded */
  ins->op[1].regset = ASM_ARM_REGSET_USR;
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REG_LIST, ins);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_ldm.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_ldm3(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_ldst_mult opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_ldst_mult(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->ldst_mult_table[(opcode.l << 6) | (opcode.cond << 2) | (opcode.p << 1) | opcode.u];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_LOAD | ASM_TYPE_WRITEFLAG | ASM_TYPE_ARCH);

  /* If any flag is added to e_arm_flags, please update this assignment */
  ins->flagswritten = ASM_ARM_FLAG_N | ASM_ARM_FLAG_Z | ASM_ARM_FLAG_C | ASM_ARM_FLAG_V | ASM_ARM_FLAG_Q;

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = opcode.rn;
  if (opcode.w)
    ins->op[0].indexing = ASM_ARM_ADDRESSING_POSTINDEXED;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[1].imm = opcode.reg_list;
  ins->op[1].destination = 1;
  /* A small workaround. Actually when PC is present in the list (the case of LDM(3)
     CPSR receives current mode SPSR, and all general purpose registers are loaded
  */
  ins->op[1].regset = ASM_ARM_REGSET_USR; 
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REG_LIST, ins);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_ldrb.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_ldrb(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_ldst opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_ldst(&opcode,buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->ldst_table[(opcode.l << 6) | ((!opcode.p && opcode.w) << 5) | opcode.b << 4 | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_LOAD);

  ins->nb_op = 2;

  /* Decode operands */
  /* Result is UNPREDICTABLE if this register is PC */
  ins->op[0].baser = opcode.rd;
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_ldst_offop(ins, buf, 1, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_ldrbt.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_ldrbt(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_ldst opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_ldst(&opcode,buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->ldst_table[(opcode.l << 6) | ((!opcode.p && opcode.w) << 5) | opcode.b << 4 | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_LOAD);

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_ldst_offop(ins, buf, 1, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_ldr.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_ldr(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_ldst opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_ldst(&opcode,buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->ldst_table[(opcode.l << 6) | ((!opcode.p && opcode.w) << 5) | opcode.b << 4 | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_LOAD | ASM_TYPE_ARCH);

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_ldst_offop(ins, buf, 1, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_ldrd.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_ldrd(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_ldst_misc opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_ldst_misc(&opcode,buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->ldst_misc_table[(opcode.l << 6) | (opcode.s << 5) | opcode.h << 4 | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_LOAD);

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_ldst_misc_offop(ins, buf, 1, &opcode);

  // TODO: if rd is odd, this is an UNDEFINED instruction
  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_ldrh.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_ldrh(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_ldst_misc opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_ldst_misc(&opcode,buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->ldst_misc_table[(opcode.l << 6) | (opcode.s << 5) | opcode.h << 4 | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_LOAD);

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_ldst_misc_offop(ins, buf, 1, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_ldrsb.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_ldrsb(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_ldst_misc opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_ldst_misc(&opcode,buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->ldst_misc_table[(opcode.l << 6) | (opcode.s << 5) | opcode.h << 4 | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_LOAD);

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_ldst_misc_offop(ins, buf, 1, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_ldrsh.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_ldrsh(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_ldst_misc opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_ldst_misc(&opcode,buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->ldst_misc_table[(opcode.l << 6) | (opcode.s << 5) | opcode.h << 4 | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_LOAD);

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_ldst_misc_offop(ins, buf, 1, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_ldrt.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_ldrt(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_ldst opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_ldst(&opcode,buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->ldst_table[(opcode.l << 6) | ((!opcode.p && opcode.w) << 5) | opcode.b << 4 | opcode.cond];;

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_LOAD);

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_ldst_offop(ins, buf, 1, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_mcr.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_mcr(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_coproc_mov opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_coproc_mov(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->coproc_mov_table[(opcode.toarm << 4 | opcode.cond)];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ASSIGN);

  ins->nb_op = 5;
  if (opcode.op2 != 0)
    ins->nb_op = 6;

  /* Decode operands */
  ins->op[0].imm = opcode.cpnum;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_COPROC, ins);

  ins->op[1].imm = opcode.op1;
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_IMMEDIATE, ins);

  ins->op[2].baser = opcode.rd;
  asm_arm_op_fetch(&ins->op[2], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[3].baser = opcode.crn;
  ins->op[3].destination = 1;
  asm_arm_op_fetch(&ins->op[3], buf, ASM_ARM_OTYPE_COPROC_REGISTER, ins);

  ins->op[4].baser = opcode.crm;
  asm_arm_op_fetch(&ins->op[4], buf, ASM_ARM_OTYPE_COPROC_REGISTER, ins);

  if (ins->nb_op > 5)
    {
      ins->op[5].imm = opcode.op2;
      asm_arm_op_fetch(&ins->op[5], buf, ASM_ARM_OTYPE_IMMEDIATE, ins);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_mcrr.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_mcrr(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_coproc_mov2 opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_coproc_mov2(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->coproc_mov2_table[(opcode.toarm << 4 | opcode.cond)];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ASSIGN);

  ins->nb_op = 5;

  /* Decode operands */
  ins->op[0].imm = opcode.cpnum;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_COPROC, ins);

  ins->op[1].imm = opcode.op;
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_IMMEDIATE, ins);

  ins->op[2].baser = opcode.rd;
  asm_arm_op_fetch(&ins->op[2], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[3].baser = opcode.rn;
  asm_arm_op_fetch(&ins->op[3], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[4].baser = opcode.crm;
  ins->op[4].destination = 1;
  asm_arm_op_fetch(&ins->op[4], buf, ASM_ARM_OTYPE_COPROC_REGISTER, ins);

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_mla.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_mla(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_multiply opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_multiply(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->multiply_table[(opcode.op << 5) | (opcode.cond << 1) | opcode.s];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ARITH);
  if (opcode.s)
    {
      MASSIGNTYPE(ins, ASM_TYPE_WRITEFLAG);
      ins->flagswritten = ASM_ARM_FLAG_N | ASM_ARM_FLAG_Z;
    }

  ins->nb_op = 4;

  /* Decode operands */
  ins->op[0].baser = opcode.r1; /* This is Rd */
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[1].baser = opcode.r4; /* This is Rm */
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[2].baser = opcode.r3; /* This is Rs */
  asm_arm_op_fetch(&ins->op[2], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[3].baser = opcode.r2; /* This is Rn */
  asm_arm_op_fetch(&ins->op[3], buf, ASM_ARM_OTYPE_REGISTER, ins);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_mov.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_mov(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_dataproc opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_dataproc(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->dataproc_table[(opcode.op2 << 5) | (opcode.cond << 1) | opcode.s];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ASSIGN);

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_dataproc_shfop(ins, buf, 1, &opcode);

  /* Decode flags related behaviour */
  arm_decode_dataproc_flagswritten(ins, &opcode);

  /* Check if this MOV is a procedure return (MOV PC,LR) */
  if ((ins->op[1].content & ASM_ARM_OTYPE_REGISTER)
      && ins->op[1].baser == ASM_ARM_REG_R14
      && ins->op[0].baser == ASM_ARM_REG_PC)
    {
      /* clear types assigned in the register operand handler */
      MUNASSIGNTYPE(ins, ASM_TYPE_BRANCH);
      /* assign the real type */
      MASSIGNTYPE(ins, ASM_TYPE_RETPROC);
    }

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      if (!(ins->op[1].content & ASM_ARM_OTYPE_IMMEDIATE))
        MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_mrc.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_mrc(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_coproc_mov opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_coproc_mov(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->coproc_mov_table[(opcode.toarm << 4 | opcode.cond)];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ASSIGN);

  ins->nb_op = 5;
  if (opcode.op2 != 0)
    ins->nb_op = 6;

  /* Decode operands */
  ins->op[0].imm = opcode.cpnum;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_COPROC, ins);

  ins->op[1].imm = opcode.op1;
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_IMMEDIATE, ins);

  ins->op[2].baser = opcode.rd;
  ins->op[2].destination = 1;
  asm_arm_op_fetch(&ins->op[2], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[3].baser = opcode.crn;
  asm_arm_op_fetch(&ins->op[3], buf, ASM_ARM_OTYPE_COPROC_REGISTER, ins);

  ins->op[4].baser = opcode.crm;
  asm_arm_op_fetch(&ins->op[4], buf, ASM_ARM_OTYPE_COPROC_REGISTER, ins);

  if (ins->nb_op > 5)
    {
      ins->op[5].imm = opcode.op2;
      asm_arm_op_fetch(&ins->op[5], buf, ASM_ARM_OTYPE_IMMEDIATE, ins);
    }

  /* If Rd = PC, PC is not written, but the flags instead. */
  /* Remove the BRANCH flag assigned in the operand handler */
  MUNASSIGNTYPE(ins, ASM_TYPE_BRANCH);
  MASSIGNTYPE(ins, ASM_TYPE_WRITEFLAG);
  ins->flagswritten = ASM_ARM_FLAG_N | ASM_ARM_FLAG_Z | ASM_ARM_FLAG_C | ASM_ARM_FLAG_V;

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_mrrc.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_mrrc(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_coproc_mov2 opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_coproc_mov2(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->coproc_mov2_table[(opcode.toarm << 4 | opcode.cond)];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ASSIGN);

  ins->nb_op = 5;

  /* Decode operands */
  ins->op[0].imm = opcode.cpnum;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_COPROC, ins);

  ins->op[1].imm = opcode.op;
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_IMMEDIATE, ins);

  ins->op[2].baser = opcode.rd;
  ins->op[2].destination = 1;
  asm_arm_op_fetch(&ins->op[2], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[3].baser = opcode.rn;
  ins->op[3].destination = 1;
  asm_arm_op_fetch(&ins->op[3], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[4].baser = opcode.crm;
  asm_arm_op_fetch(&ins->op[4], buf, ASM_ARM_OTYPE_COPROC_REGISTER, ins);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_mrs.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_mrs(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_dataproc opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_dataproc(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->movpsr_table[(opcode.topsr << 4) | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ASSIGN);

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[1].baser = (opcode.r ? ASM_ARM_REG_SPSR : ASM_ARM_REG_CPSR);
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REGISTER, ins);

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_msr.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_msr(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_dataproc opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_dataproc(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->movpsr_table[(opcode.topsr << 4) | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ASSIGN | ASM_TYPE_ARCH);

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = (opcode.r ? ASM_ARM_REG_SPSR : ASM_ARM_REG_CPSR);
  ins->op[0].imm = opcode.field_mask;
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_dataproc_shfop(ins, buf, 1, &opcode);

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_mul.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_mul(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_multiply opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_multiply(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->multiply_table[(opcode.op << 5) | (opcode.cond << 1) | opcode.s];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ARITH);
  if (opcode.s)
    {
      MASSIGNTYPE(ins, ASM_TYPE_WRITEFLAG);
      ins->flagswritten = ASM_ARM_FLAG_N | ASM_ARM_FLAG_Z;
    }

  ins->nb_op = 3;

  /* Decode operands */
  ins->op[0].baser = opcode.r1; /* This is Rd */
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[1].baser = opcode.r4; /* This is Rm */
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[2].baser = opcode.r3; /* This is Rs */
  asm_arm_op_fetch(&ins->op[2], buf, ASM_ARM_OTYPE_REGISTER, ins);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_mvn.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_mvn(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_dataproc opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_dataproc(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->dataproc_table[(opcode.op2 << 5) | (opcode.cond << 1) | opcode.s];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ASSIGN);

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_dataproc_shfop(ins, buf, 1, &opcode);

  /* Decode flags related behaviour */
  arm_decode_dataproc_flagswritten(ins, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      if (!(ins->op[1].content & ASM_ARM_OTYPE_IMMEDIATE))
        MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_orr.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_orr(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_dataproc opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_dataproc(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->dataproc_table[(opcode.op2 << 5) | (opcode.cond << 1) | opcode.s];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ARITH);

  ins->nb_op = 3;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);
  ins->op[1].baser = opcode.rn;
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_dataproc_shfop(ins, buf, 2, &opcode);

  /* Decode flags related behaviour */
  arm_decode_dataproc_flagswritten(ins, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_pld.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_pld(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_ldst opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_ldst(&opcode,buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = ASM_ARM_PLD;

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_NOP | ASM_TYPE_ARCH);

  ins->nb_op = 1;

  /* Decode operands */
  arm_decode_ldst_offop(ins, buf, 0, &opcode);

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_qadd.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_qadd(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_multiply opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_multiply(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->dsp_arith_table[(opcode.op << 4) | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG);
  ins->flagswritten = ASM_ARM_FLAG_Q;

  ins->nb_op = 3;

  /* Decode operands */
  ins->op[0].baser = opcode.r2; /* This is Rd */
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[1].baser = opcode.r4; /* This is Rm */
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[2].baser = opcode.r1; /* This is Rn */
  asm_arm_op_fetch(&ins->op[2], buf, ASM_ARM_OTYPE_REGISTER, ins);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_qdadd.c
n** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_qdadd(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_multiply opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_multiply(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->dsp_arith_table[(opcode.op << 4) | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG);
  ins->flagswritten = ASM_ARM_FLAG_Q;

  ins->nb_op = 3;

  /* Decode operands */

  ins->op[0].baser = opcode.r2; /* This is Rd */
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[1].baser = opcode.r4; /* This is Rm */
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[2].baser = opcode.r1; /* This is Rn */
  asm_arm_op_fetch(&ins->op[2], buf, ASM_ARM_OTYPE_REGISTER, ins);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_qdsub.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_qdsub(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_multiply opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_multiply(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->dsp_arith_table[(opcode.op << 4) | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG);
  ins->flagswritten = ASM_ARM_FLAG_Q;

  ins->nb_op = 3;

  /* Decode operands */
  ins->op[0].baser = opcode.r2; /* This is Rd */
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[1].baser = opcode.r4; /* This is Rm */
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[2].baser = opcode.r1; /* This is Rn */
  asm_arm_op_fetch(&ins->op[2], buf, ASM_ARM_OTYPE_REGISTER, ins);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_qsub.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_qsub(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_multiply opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_multiply(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->dsp_arith_table[(opcode.op << 4) | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG);
  ins->flagswritten = ASM_ARM_FLAG_Q;

  ins->nb_op = 3;

  /* Decode operands */

  ins->op[0].baser = opcode.r2; /* This is Rd */
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[1].baser = opcode.r4; /* This is Rm */
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[2].baser = opcode.r1; /* This is Rn */
  asm_arm_op_fetch(&ins->op[2], buf, ASM_ARM_OTYPE_REGISTER, ins);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_rsb.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_rsb(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_dataproc opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_dataproc(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->dataproc_table[(opcode.op2 << 5) | (opcode.cond << 1) | opcode.s];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ARITH);

  ins->nb_op = 3;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);
  ins->op[1].baser = opcode.rn;
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_dataproc_shfop(ins, buf, 2, &opcode);

  /* Decode flags related behaviour */
  arm_decode_dataproc_flagswritten(ins, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_rsc.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_rsc(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_dataproc opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_dataproc(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->dataproc_table[(opcode.op2 << 5) | (opcode.cond << 1) | opcode.s];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ARITH | ASM_TYPE_READFLAG);

  ins->flagsread |= ASM_ARM_FLAG_C;

  ins->nb_op = 3;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);
  ins->op[1].baser = opcode.rn;
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_dataproc_shfop(ins, buf, 2, &opcode);

  /* Decode flags related behaviour */
  arm_decode_dataproc_flagswritten(ins, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_sbc.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_sbc(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_dataproc opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_dataproc(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->dataproc_table[(opcode.op2 << 5) | (opcode.cond << 1) | opcode.s];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ARITH | ASM_TYPE_READFLAG);

  ins->flagsread |= ASM_ARM_FLAG_C;

  ins->nb_op = 3;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);
  ins->op[1].baser = opcode.rn;
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_dataproc_shfop(ins, buf, 2, &opcode);

  /* Decode flags related behaviour */
  arm_decode_dataproc_flagswritten(ins, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_smlal.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_smlal(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_multiply opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_multiply(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->multiply_table[(opcode.op << 5) | (opcode.cond << 1) | opcode.s];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ARITH);
  if (opcode.s)
    {
      MASSIGNTYPE(ins, ASM_TYPE_WRITEFLAG);
      ins->flagswritten = ASM_ARM_FLAG_N | ASM_ARM_FLAG_Z;
    }

  ins->nb_op = 4;

  /* Decode operands */
  arm_decode_multiply_long(ins, buf, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_smlalxy.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_smlalxy(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{

  struct s_arm_decode_multiply opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_multiply(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->dsp_multiply_table[(opcode.op << 6) | (opcode.cond << 2) | (opcode.y << 1) | opcode.x];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ARITH);

  ins->nb_op = 4;

  /* Decode operands */
  arm_decode_multiply_long(ins, buf, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);

}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_smlawy.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_smlawy(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_multiply opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_multiply(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->dsp_multiply_table[(opcode.op << 6) | (opcode.cond << 2) | (opcode.y << 1) | opcode.x];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG);

  ins->flagswritten = ASM_ARM_FLAG_Q;

  ins->nb_op = 4;

  /* Decode operands */
  // TODO: create a function for smlawy|smlaxy (mla)
  ins->op[0].baser = opcode.r1; /* This is Rd */
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[1].baser = opcode.r4; /* This is Rm */
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[2].baser = opcode.r3; /* This is Rs */
  asm_arm_op_fetch(&ins->op[2], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[3].baser = opcode.r2; /* This is Rn */
  asm_arm_op_fetch(&ins->op[3], buf, ASM_ARM_OTYPE_REGISTER, ins);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);

}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_smlaxy.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_smlaxy(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_multiply opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_multiply(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->dsp_multiply_table[(opcode.op << 6) | (opcode.cond << 2) | (opcode.y << 1) | opcode.x];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG);

  ins->flagswritten = ASM_ARM_FLAG_Q;

  ins->nb_op = 4;

  /* Decode operands */
  ins->op[0].baser = opcode.r1; /* This is Rd */
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[1].baser = opcode.r4; /* This is Rm */
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[2].baser = opcode.r3; /* This is Rs */
  asm_arm_op_fetch(&ins->op[2], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[3].baser = opcode.r2; /* This is Rn */
  asm_arm_op_fetch(&ins->op[3], buf, ASM_ARM_OTYPE_REGISTER, ins);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_smull.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_smull(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_multiply opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_multiply(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->multiply_table[(opcode.op << 5) | (opcode.cond << 1) | opcode.s];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ARITH);
  if (opcode.s)
    {
      MASSIGNTYPE(ins, ASM_TYPE_WRITEFLAG);
      ins->flagswritten = ASM_ARM_FLAG_N | ASM_ARM_FLAG_Z;
    }

  ins->nb_op = 4;

  /* Decode operands */
  arm_decode_multiply_long(ins, buf, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_smulwy.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_smulwy(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_multiply opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_multiply(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->dsp_multiply_table[(opcode.op << 6) | (opcode.cond << 2) | (opcode.y << 1) | opcode.x];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ARITH);

  ins->nb_op = 3;

  /* Decode operands */
  ins->op[0].baser = opcode.r1; /* This is Rd */
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[1].baser = opcode.r4; /* This is Rm */
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[2].baser = opcode.r3; /* This is Rs */
  asm_arm_op_fetch(&ins->op[2], buf, ASM_ARM_OTYPE_REGISTER, ins);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_smulxy.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_smulxy(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_multiply opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_multiply(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->dsp_multiply_table[(opcode.op << 6) | (opcode.cond << 2) | (opcode.y << 1) | opcode.x];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ARITH);

  ins->nb_op = 3;

  /* Decode operands */
  ins->op[0].baser = opcode.r1; /* This is Rd */
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[1].baser = opcode.r4; /* This is Rm */
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[2].baser = opcode.r3; /* This is Rs */
  asm_arm_op_fetch(&ins->op[2], buf, ASM_ARM_OTYPE_REGISTER, ins);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_stc.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_stc(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_coproc_ldst opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_coproc_ldst(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->coproc_ldst_table[(opcode.l << 5) | (opcode.cond << 1) | opcode.n];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_STORE);

  ins->nb_op = 3;

  /* Decode operands */
  ins->op[0].imm = opcode.cpnum;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_COPROC, ins);

  ins->op[1].baser = opcode.crd;
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_COPROC_REGISTER, ins);

  arm_decode_coproc_ldst_offop(ins, buf, 2, &opcode);

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_stm.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_stm1(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_ldst_mult opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_ldst_mult(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->ldst_mult_table[(opcode.l << 6) | (opcode.cond << 2) | (opcode.p << 1) | opcode.u];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_STORE);

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = opcode.rn;
  if (opcode.w)
    ins->op[0].indexing = ASM_ARM_ADDRESSING_POSTINDEXED;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[1].imm = opcode.reg_list;
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REG_LIST, ins);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_stm.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_stm2(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_ldst_mult opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_ldst_mult(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->ldst_mult_table[(opcode.l << 6) | (opcode.cond << 2) | (opcode.p << 1) | opcode.u];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_STORE);

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = opcode.rn;
  if (opcode.w)
    ins->op[0].indexing = ASM_ARM_ADDRESSING_POSTINDEXED;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[1].imm = opcode.reg_list;
  ins->op[1].regset = ASM_ARM_REGSET_USR;
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REG_LIST, ins);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_strb.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_strb(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_ldst opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_ldst(&opcode,buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->ldst_table[(opcode.l << 6) | ((!opcode.p && opcode.w) << 5) | opcode.b << 4 | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_STORE);

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_ldst_offop(ins, buf, 1, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_strbt.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_strbt(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_ldst opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_ldst(&opcode,buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->ldst_table[(opcode.l << 6) | ((!opcode.p && opcode.w) << 5) | opcode.b << 4 | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_STORE);

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_ldst_offop(ins, buf, 1, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_str.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_str(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_ldst opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_ldst(&opcode,buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->ldst_table[(opcode.l << 6) | ((!opcode.p && opcode.w) << 5) | opcode.b << 4 | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_STORE);

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_ldst_offop(ins, buf, 1, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_strd.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_strd(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_ldst_misc opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_ldst_misc(&opcode,buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->ldst_misc_table[(opcode.l << 6) | (opcode.s << 5) | opcode.h << 4 | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_STORE);

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_ldst_misc_offop(ins, buf, 1, &opcode);

  // TODO: if rd is odd, this is an UNDEFINED instruction
  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_strh.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_strh(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_ldst_misc opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_ldst_misc(&opcode,buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->ldst_misc_table[(opcode.l << 6) | (opcode.s << 5) | opcode.h << 4 | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_STORE);

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_ldst_misc_offop(ins, buf, 1, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_strt.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_strt(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_ldst opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_ldst(&opcode,buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->ldst_table[(opcode.l << 6) | ((!opcode.p && opcode.w) << 5) | opcode.b << 4 | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_STORE);

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_ldst_offop(ins, buf, 1, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_sub.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_sub(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_dataproc opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_dataproc(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->dataproc_table[(opcode.op2 << 5) | (opcode.cond << 1) | opcode.s];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ARITH);

  ins->nb_op = 3;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);
  ins->op[1].baser = opcode.rn;
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_dataproc_shfop(ins, buf, 2, &opcode);

  /* Decode flags related behaviour */
  arm_decode_dataproc_flagswritten(ins, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_swi.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_swi(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_branch1 opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_branch1(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->swi_table[opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_INT);

  ins->nb_op = 1;

  /* Decode operands */
  ins->op[0].imm = opcode.signed_imm;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_IMMEDIATE, ins);

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_swpb.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_swpb(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  // TODO: verify the need of two different handlers for swp/swpb
  struct s_arm_decode_ldst opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_swap(&opcode,buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->swap_table[(opcode.b << 4) | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_LOAD | ASM_TYPE_STORE);

  ins->nb_op = 3;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[1].baser = opcode.rm;
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REGISTER, ins);

  /* Use register offset type to print with [] surrounding 
   * the register name.
   */
  ins->op[2].baser = opcode.rn;
  ins->op[2].indexing = ASM_ARM_ADDRESSING_OFFSET;
  ins->op[2].imm = 0;
  ins->op[2].offset_added = 1;
  asm_arm_op_fetch(&ins->op[2], buf, ASM_ARM_OTYPE_REG_OFFSET, ins);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_swp.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_swp(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_ldst opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_swap(&opcode,buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->swap_table[(opcode.b << 4) | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_LOAD | ASM_TYPE_STORE);

  ins->nb_op = 3;

  /* Decode operands */
  ins->op[0].baser = opcode.rd;
  ins->op[0].destination = 1;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  ins->op[1].baser = opcode.rm;
  asm_arm_op_fetch(&ins->op[1], buf, ASM_ARM_OTYPE_REGISTER, ins);

  /* Use register offset type to print with [] surrounding 
   * the register name.
   */
  ins->op[2].baser = opcode.rn;
  ins->op[2].indexing = ASM_ARM_ADDRESSING_OFFSET;
  ins->op[2].imm = 0;
  ins->op[2].offset_added = 1;
  asm_arm_op_fetch(&ins->op[2], buf, ASM_ARM_OTYPE_REG_OFFSET, ins);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_teq.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_teq(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_dataproc opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_dataproc(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->dataproc_table[(opcode.op2 << 5) | (opcode.cond << 1) | opcode.s];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_COMPARISON);

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = opcode.rn;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_dataproc_shfop(ins, buf, 1, &opcode);

  /* Decode flags related behaviour */
  arm_decode_dataproc_flagswritten(ins, &opcode);

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_tst.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_tst(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_dataproc opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_dataproc(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->dataproc_table[(opcode.op2 << 5) | (opcode.cond << 1) | opcode.s];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_COMPARISON | ASM_TYPE_BITTEST);

  ins->nb_op = 2;

  /* Decode operands */
  ins->op[0].baser = opcode.rn;
  asm_arm_op_fetch(&ins->op[0], buf, ASM_ARM_OTYPE_REGISTER, ins);

  arm_decode_dataproc_shfop(ins, buf, 1, &opcode);

  /* Decode flags related behaviour */
  arm_decode_dataproc_flagswritten(ins, &opcode);

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_umlal.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_umlal(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_multiply opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_multiply(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->multiply_table[(opcode.op << 5) | (opcode.cond << 1) | opcode.s];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ARITH);
  if (opcode.s)
    {
      MASSIGNTYPE(ins, ASM_TYPE_WRITEFLAG);
      ins->flagswritten = ASM_ARM_FLAG_N | ASM_ARM_FLAG_Z;
    }

  ins->nb_op = 4;

  /* Decode operands */
  arm_decode_multiply_long(ins, buf, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);

}
/**
* @file libasm/src/arch/arm/handlers/asm_arm_umull.c
** @ingroup ARM_instrs
*/
#include "libasm.h"

int     asm_arm_umull(asm_instr * ins, u_char * buf, u_int len,
                   asm_processor * proc)
{
  struct s_arm_decode_multiply opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_multiply(&opcode, buf);

  arm_decode_condition(ins, opcode.cond);

  ins->instr = inter->multiply_table[(opcode.op << 5) | (opcode.cond << 1) | opcode.s];

  ins->name = ins->proc->instr_table[ins->instr];

  MASSIGNTYPE(ins, ASM_TYPE_ARITH);
  if (opcode.s)
    {
      MASSIGNTYPE(ins, ASM_TYPE_WRITEFLAG);
      ins->flagswritten = ASM_ARM_FLAG_N | ASM_ARM_FLAG_Z;
    }

  ins->nb_op = 4;

  /* Decode operands */
  arm_decode_multiply_long(ins, buf, &opcode);

  if (MISTYPE(ins, ASM_TYPE_BRANCH)
      || MISTYPE(ins, ASM_TYPE_CALLPROC)
      || MISTYPE(ins, ASM_TYPE_RETPROC))
    {
      MASSIGNTYPE(ins, ASM_TYPE_INDCONTROL);
    }

  LIBASM_PROFILE_FOUT(4);
}
#include "libasm.h"

int     asm_arm_undef(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  LIBASM_PROFILE_FIN();

  ins->instr = ASM_ARM_;
  MASSIGNTYPE(ins, ASM_TYPE_INT);

  LIBASM_PROFILE_FOUT(4);
}
/**
* @file libasm/src/arch/arm/operand_handlers/asm_arm_op_fetch.c
** @ingroup ARM_operands
*/
#include <libasm.h>


/**
 * Main function, dispatch processing to handler.
 * @param op Pointer to operand to fill
 * @param opcode Pointer to operand data.
 * @param otype Content of operand to fetch : ASM_OTYPE_*
 * @param proc Pointer to processor structure.
 * @return Operand length or -1 on error (should currently never occur)
 */
int asm_arm_op_fetch(asm_operand *op, u_char *opcode, int otype, 
		       asm_instr *ins)
{ 
  vector_t      *vec;
  u_int         dim[1];
  int           to_ret;
  int           (*fetch)(asm_operand *, u_char *, int, asm_instr *);

  LIBASM_PROFILE_FIN();  

  vec = aspect_vector_get(LIBASM_VECTOR_OPERAND_ARM);
  dim[0] = otype;
  
  fetch = aspect_vectors_select(vec, dim);
  to_ret = fetch(op, opcode, otype, ins);

  if (to_ret == -1)
  {
    printf("%s:%i Unsupported operand content : %i\n", __FILE__, __LINE__, 
    	     otype);
  }

  op->name = asm_arm_get_op_name(op);

  LIBASM_PROFILE_FOUT(to_ret);
}
/**
* @file libasm/src/arch/arm/operand_handlers/asm_arm_op_fetch_coprocessor.c
** @ingroup ARM_operands
*/
#include <libasm.h>

int asm_arm_op_fetch_coprocessor(asm_operand *operand, u_char *opcode,
                                 int otype, asm_instr *ins)
{
  LIBASM_PROFILE_FIN();

  operand->content = ASM_ARM_OTYPE_COPROC;
  operand->type = ASM_OPTYPE_IMM;

  LIBASM_PROFILE_FOUT(0);
}
/**
* @file libasm/src/arch/arm/operand_handlers/asm_arm_op_fetch_coprocessor_register.c
** @ingroup ARM_operands
*/
#include <libasm.h>

int asm_arm_op_fetch_coprocessor_register(asm_operand *operand, u_char *opcode,
                                          int otype, asm_instr *ins)
{
  LIBASM_PROFILE_FIN();

  operand->content = ASM_ARM_OTYPE_COPROC_REGISTER;
  operand->type = ASM_OPTYPE_REG;

  LIBASM_PROFILE_FOUT(0);
}
/**
* @file libasm/src/arch/arm/operand_handlers/asm_arm_op_fetch_disp.c
** @ingroup ARM_operands
*/
#include <libasm.h>

int asm_arm_op_fetch_disp(asm_operand *operand, u_char *opcode,
                          int otype, asm_instr *ins)
{
  LIBASM_PROFILE_FIN();

  operand->content = ASM_ARM_OTYPE_DISP;
  operand->type = ASM_OPTYPE_IMM;

  LIBASM_PROFILE_FOUT(0);
}
/**
* @file libasm/src/arch/arm/operand_handlers/asm_arm_op_fetch_disp_half.c
** @ingroup ARM_operands
*/
#include <libasm.h>

int asm_arm_op_fetch_disp_half(asm_operand *operand, u_char *opcode,
                               int otype, asm_instr *ins)
{
  LIBASM_PROFILE_FIN();

  operand->content = ASM_ARM_OTYPE_DISP_HALF;
  operand->type = ASM_OPTYPE_IMM;

  LIBASM_PROFILE_FOUT(0);
}
/**
* @file libasm/src/arch/arm/operand_handlers/asm_arm_op_fetch_immediate.c
** @ingroup ARM_operands
*/
#include <libasm.h>

int asm_arm_op_fetch_immediate(asm_operand *operand, u_char *opcode,
                               int otype, asm_instr *ins)
{
  LIBASM_PROFILE_FIN();

  operand->content = ASM_ARM_OTYPE_IMMEDIATE;
  operand->type = ASM_OPTYPE_IMM;

  LIBASM_PROFILE_FOUT(0);
}
/**
* @file libasm/src/arch/arm/operand_handlers/asm_arm_op_fetch_register.c
** @ingroup ARM_operands
*/
#include <libasm.h>

int asm_arm_op_fetch_register(asm_operand *operand, u_char *opcode,
                              int otype, asm_instr *ins)
{
  LIBASM_PROFILE_FIN();

  operand->content = ASM_ARM_OTYPE_REGISTER;
  operand->type = ASM_OPTYPE_REG;

  if (operand->destination
      || operand->indexing == ASM_ARM_ADDRESSING_POSTINDEXED
      || operand->indexing == ASM_ARM_ADDRESSING_PREINDEXED)
    {
      /* PC shouldn't be used as base address with writeback */
      /* If by any chance someone uses it this way, we will flag the instruction as a branch */
      switch (operand->baser)
        {
        case ASM_ARM_REG_R13:
          /* R13 = SP */
          MASSIGNTYPE(ins, ASM_TYPE_TOUCHSP);
          break;
        case ASM_ARM_REG_PC:
          MASSIGNTYPE(ins, ASM_TYPE_BRANCH);
          break;
        case ASM_ARM_REG_CPSR:
          if (operand->imm & 0x08)
            {
              MASSIGNTYPE(ins, ASM_TYPE_WRITEFLAG);
              /* If any flag is added to e_arm_flags, please update this assignment */
              ins->flagswritten = ASM_ARM_FLAG_N | ASM_ARM_FLAG_Z | ASM_ARM_FLAG_C | ASM_ARM_FLAG_V | ASM_ARM_FLAG_Q;
            }
          break;
        }
    }

  LIBASM_PROFILE_FOUT(0);
}
/**
* @file libasm/src/arch/arm/operand_handlers/asm_arm_op_fetch_reg_list.c
** @ingroup ARM_operands
*/
#include "libasm.h"

int asm_arm_op_fetch_reg_list(asm_operand *operand, u_char *opcode,
                                int otype, asm_instr *ins)
{
  LIBASM_PROFILE_FIN();

  operand->content = ASM_ARM_OTYPE_REG_LIST;
  operand->type = ASM_OPTYPE_REG;

  if (operand->destination)
    {
      if (operand->imm & (1 << 13))
        {
          /* R13 = SP */
          MASSIGNTYPE(ins, ASM_TYPE_TOUCHSP);
        }
      if (operand->imm & (1 << 15))
        {
          /* PC */

          if (ins->instr == ASM_ARM_LDMIA
              && ins->op[0].baser == ASM_ARM_REG_R13
              && ins->op[0].indexing == ASM_ARM_ADDRESSING_POSTINDEXED)
            {
              /* LDMIA SP!, {Reg list} (POP) is usually used as return of a function */
              MASSIGNTYPE(ins, ASM_TYPE_RETPROC);
            }
          else
            {
              MASSIGNTYPE(ins, ASM_TYPE_BRANCH);
            }
        }
    }

  LIBASM_PROFILE_FOUT(0);
}
/**
* @file libasm/src/arch/arm/operand_handlers/asm_arm_op_fetch_reg_offset.c
** @ingroup ARM_operands
*/
#include <libasm.h>

int asm_arm_op_fetch_reg_offset(asm_operand *operand, u_char *opcode,
                                int otype, asm_instr *ins)
{
  LIBASM_PROFILE_FIN();

  operand->content = ASM_ARM_OTYPE_REG_OFFSET;
  operand->type = ASM_OPTYPE_REG;

  if (operand->indexr != ASM_ARM_REG_NUM)
    {
      if (operand->imm == 0)
        {
          switch (operand->shift_type)
            {
            case ASM_ARM_SHIFT_LSL:
              /* Register offset */
              operand->shift_type = ASM_ARM_SHIFT_NUM;
              break;
            case ASM_ARM_SHIFT_ROR:
              operand->shift_type = ASM_ARM_SHIFT_RRX;
              break;
            case ASM_ARM_SHIFT_LSR:
            case ASM_ARM_SHIFT_ASR:
              operand->imm = 32;
              break;
            default:
              /* TODO: Error! */
              break;
            }
        }
    }

  if (operand->indexing == ASM_ARM_ADDRESSING_PREINDEXED
      || operand->indexing == ASM_ARM_ADDRESSING_POSTINDEXED)
    {
      /* PC shouldn't be used as base address with writeback */
      /* If by any chance someone uses it this way, we will flag the instruction as a branch */
      switch (operand->baser)
        {
        case ASM_ARM_REG_R13:
          /* R13 = SP */
          MASSIGNTYPE(ins, ASM_TYPE_TOUCHSP);
          break;
        case ASM_ARM_REG_PC:
          MASSIGNTYPE(ins, ASM_TYPE_BRANCH);
          break;
        }
    }

  LIBASM_PROFILE_FOUT(0);
}
/**
* @file libasm/src/arch/arm/operand_handlers/asm_arm_op_fetch_reg_scaled.c
** @ingroup ARM_operands
*/
#include <libasm.h>

int asm_arm_op_fetch_reg_scaled(asm_operand *operand, u_char *opcode,
                                int otype, asm_instr *ins)
{
  LIBASM_PROFILE_FIN();

  operand->content = ASM_ARM_OTYPE_REG_SCALED;
  operand->type = ASM_OPTYPE_REG;

  if (operand->indexr == ASM_ARM_REG_NUM)
    {
      if (operand->imm == 0)
        {
          if (operand->shift_type == ASM_ARM_SHIFT_ROR)
            operand->shift_type = ASM_ARM_SHIFT_RRX;
          else
            operand->imm = 32;
        }
    }

  LIBASM_PROFILE_FOUT(0);
}
/**
 * @defgroup ARM_operands ARM operands API.
 * @ingroup arm
 */
/**
* @file libasm/src/arch/arm/operand_handlers/asm_arm_op_name.c
** @ingroup ARM_operands
*/
#include <libasm.h>

/*
#define ASM_POOL_SIZE 100
#define ASM_OP_NAME_LEN 64
*/
/* FIFO sort-of memory manager */
/*
char 		*asm_name_pool_alloc()
{
  static char	*asm_name_pool[ASM_POOL_SIZE] = {};
  static int	index = 0;

  char *ret;

  if (asm_name_pool[index] != NULL)
    free(asm_name_pool[index]);

  ret = asm_name_pool[index] = (char *) malloc(ASM_OP_NAME_LEN);
  
  index = (index+1)%ASM_POOL_SIZE;
  
  return ret;
}
*/
char 	*asm_arm_get_op_name(asm_operand *op)
{
  switch (op->content)
    {
    case ASM_ARM_OTYPE_REGISTER:
      return asm_arm_get_register(op->baser);
      // TODO:
    default:
      return NULL;
    }
}
