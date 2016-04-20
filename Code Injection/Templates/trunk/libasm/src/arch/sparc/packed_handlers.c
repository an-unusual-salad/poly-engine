/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_add.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int 
asm_sparc_add(asm_instr * ins, u_char * buf, u_int len, 
					asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_ADD;        
  ins->type = ASM_TYPE_ARITH;

  ins->nb_op = 3;  
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);  
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {    
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {    
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  if (asm_config_get_synthinstr())
    {
      if ((ins->op[0].baser == ins->op[2].baser) &&
	  ins->op[1].content == ASM_SP_OTYPE_IMMEDIATE) {
	
	ins->instr = ASM_SP_INC;
	
	if (ins->op[1].imm == 1)
	  ins->nb_op = 1;
	else
	  ins->nb_op = 2;
      }
    }
  
  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_addc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_addc(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_ADD;  
  ins->type = ASM_TYPE_ARITH;

  ins->nb_op = 3;  
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);  
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {    
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {    
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
  
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_addcc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_addcc(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_ADD;      
  ins->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  ins->flagswritten = ASM_SP_FLAG_C | ASM_SP_FLAG_V | ASM_SP_FLAG_Z | ASM_SP_FLAG_N;

  ins->nb_op = 3;  
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);  
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {    
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {    
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  if (asm_config_get_synthinstr())
    {
      if ((ins->op[0].baser == ins->op[2].baser) &&
	  ins->op[1].content == ASM_SP_OTYPE_IMMEDIATE) {
	
	ins->instr = ASM_SP_INCCC;
	
	if (ins->op[1].imm == 1)
	  ins->nb_op = 1;
	else
	  ins->nb_op = 2;
      }
    }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_addccc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_addccc(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_ADD;  
  ins->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  ins->flagswritten = ASM_SP_FLAG_C | ASM_SP_FLAG_V | ASM_SP_FLAG_Z | ASM_SP_FLAG_N;

  ins->nb_op = 3;  
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);  
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {    
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {    
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_and.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_and(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_AND;        
  ins->type = ASM_TYPE_ARITH;

  ins->nb_op = 3;  
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_andcc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_andcc(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_AND;        
  ins->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  ins->flagswritten = ASM_SP_FLAG_C | ASM_SP_FLAG_V | ASM_SP_FLAG_Z | ASM_SP_FLAG_N;
  ins->nb_op = 3;  
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);  
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {    
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {    
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  if (asm_config_get_synthinstr())
    {
      if (ins->op[0].baser == ASM_REG_G0) {	
	ins->instr = ASM_SP_BTST;
	ins->nb_op = 2;
	ins->op[0] = ins->op[2];
      }
    }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_andn.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_andn(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_AND;        
  ins->type = ASM_TYPE_ARITH;

  ins->nb_op = 3;  
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);  
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {    
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {    
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  if (asm_config_get_synthinstr())
    {
      if (ins->op[0].baser == ins->op[2].baser) {
	ins->instr = ASM_SP_BCLR;
	ins->nb_op = 2;
      }
    }
  
  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_andncc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_andncc(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_AND | ASM_ARITH_NOT;  
  ins->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  ins->flagswritten = ASM_SP_FLAG_C | ASM_SP_FLAG_V | ASM_SP_FLAG_Z | ASM_SP_FLAG_N;
  ins->nb_op = 3;  
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);  
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {    
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {    
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_bicc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_bicc(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_branch opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_branch(&opcode, buf);

  inter = proc->internals;

  ins->instr = inter->bcc_table[opcode.cond];

  if (ins->instr == ASM_SP_BA)
    ins->type = ASM_TYPE_BRANCH;
  else if (ins->instr == ASM_SP_BN)
    ins->type = ASM_TYPE_NOP;
  else
    ins->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;

  ins->nb_op = 1;  
  ins->op[0].imm = opcode.imm;  
  ins->annul = opcode.a;
  ins->prediction = 1;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_DISPLACEMENT, ins);

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_bpcc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_bpcc(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_pbranch opcodep;
  struct s_asm_proc_sparc *inter;
  sparc_convert_pbranch(&opcodep, buf);

  inter = proc->internals;

  ins->instr = inter->bcc_table[opcodep.cond];

  if (ins->instr == ASM_SP_BA)
    ins->type = ASM_TYPE_BRANCH;
  else if (ins->instr == ASM_SP_BN)
    ins->type = ASM_TYPE_NOP;
  else
    ins->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;

  ins->nb_op = 2;  
  ins->op[0].imm = opcodep.imm;  
  ins->op[1].baser = opcodep.cc + 4;
  ins->annul = opcodep.a;
  ins->prediction = opcodep.p;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_DISPLACEMENT, ins);
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_CC, ins);

  if (ins->instr == ASM_SP_BN &&
      ins->annul && ins->prediction && ins->op[1].baser == ASM_SP_XCC) {

    ins->instr = ASM_SP_IPREFETCH;
    ins->nb_op = 1;
    ins->type = ASM_TYPE_NONE;
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_bpr.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_bpr(asm_instr * ins, u_char * buf, u_int len,
	      asm_processor * proc)
{
  struct s_decode_rbranch opcoder;
  struct s_asm_proc_sparc *inter;
  sparc_convert_rbranch(&opcoder, buf);

  inter = proc->internals;

  ins->instr = inter->brcc_table[opcoder.rcond];
  ins->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;
  ins->nb_op = 2;
  ins->op[0].imm = opcoder.d16;
  ins->op[1].baser = opcoder.rs1;
  ins->annul = opcoder.a;
  ins->prediction = opcoder.p;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_DISPLACEMENT, ins);
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_call.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int 
asm_sparc_call(asm_instr *ins, u_char *buf, u_int len, 
       			asm_processor *proc) 
{		       	
  struct s_decode_call	opcode;  
  sparc_convert_call(&opcode, buf);
  
  ins->ptr_instr = buf;  
  ins->instr = ASM_SP_CALL;
  ins->type = ASM_TYPE_CALLPROC;
  ins->nb_op = 1;
  ins->op[0].imm = opcode.displacement;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_DISP30, ins);

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_casa.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_casa(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON | ASM_TYPE_STORE;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[1].baser = opcode.rs2;
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i) {
    ins->op[2].baser = opcode.rs1;
    ins->op[2].imm = 0;
    ins->op[2].address_space = -1;
    asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[2].baser = opcode.rs1;
    ins->op[2].indexr = -1;
    ins->op[2].address_space = opcode.none;

    /* Synthethics */
    if (ins->op[2].address_space == ASM_SP_ASI_P)
      ins->instr = ASM_SP_CAS;
    else if (ins->op[2].address_space == ASM_SP_ASI_P_L) {
      ins->instr = ASM_SP_CASL;
      ins->op[2].address_space = ASM_SP_ASI_P;
    }

    asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_casxa.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_casxa(asm_instr * ins, u_char * buf, u_int len,
		asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON | ASM_TYPE_STORE;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[1].baser = opcode.rs2;
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i) {
    ins->op[2].baser = opcode.rs1;
    ins->op[2].imm = 0;
    ins->op[2].address_space = -1;
    asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[2].baser = opcode.rs1;
    ins->op[2].indexr = -1;
    ins->op[2].address_space = opcode.none;

    /* Synthethics */
    if (ins->op[2].address_space == ASM_SP_ASI_P)
      ins->instr = ASM_SP_CASX;
    else if (ins->op[2].address_space == ASM_SP_ASI_P_L) {
      ins->instr = ASM_SP_CASXL;
      ins->op[2].address_space = ASM_SP_ASI_P;
    }

    asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_done.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_done(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];
  
  ins->type = ASM_TYPE_RETPROC | ASM_TYPE_WRITEFLAG;
  ins->flagswritten = ASM_SP_FLAG_C | ASM_SP_FLAG_V | ASM_SP_FLAG_Z | ASM_SP_FLAG_N;

  if (opcode.rd == 0)		/* DONE */
    ins->instr = ASM_SP_DONE;
  else if (opcode.rd == 1)
    ins->instr = ASM_SP_RETRY;	/* RETRY */
  else
    ins->instr = ASM_SP_BAD;
    
  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_fbfcc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_fbfcc(asm_instr * ins, u_char * buf, u_int len,
		asm_processor * proc)
{
  struct s_decode_branch opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_branch(&opcode, buf);

  inter = proc->internals;

  ins->instr = inter->fbcc_table[opcode.cond];

  if (ins->instr == ASM_SP_FBA)
    ins->type = ASM_TYPE_BRANCH;
  else if (ins->instr == ASM_SP_FBN)
    ins->type = ASM_TYPE_NOP;
  else
    ins->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;

  ins->nb_op = 1;
  ins->op[0].imm = opcode.imm;
  ins->annul = opcode.a;
  ins->prediction = 1;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_DISPLACEMENT, ins);

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_fbpfcc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_fbpfcc(asm_instr * ins, u_char * buf, u_int len,
		 asm_processor * proc)
{
  struct s_decode_pbranch opcodep;
  struct s_asm_proc_sparc *inter;
  sparc_convert_pbranch(&opcodep, buf);

  inter = proc->internals;

  ins->instr = inter->fbcc_table[opcodep.cond];

  if (ins->instr == ASM_SP_FBA)
    ins->type = ASM_TYPE_BRANCH;
  else if (ins->instr == ASM_SP_FBN)
    ins->type = ASM_TYPE_NOP;
  else
    ins->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL;

  /* Removed during flags cleanup. */
  /* ins->type = ASM_TYPE_BRANCH | ASM_TYPE_CONDCONTROL; */
  ins->nb_op = 2;
  ins->op[0].imm = opcodep.imm;
  ins->op[1].baser = opcodep.cc;
  ins->annul = opcodep.a;
  ins->prediction = opcodep.p;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_DISPLACEMENT, ins);
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_CC, ins);
  
  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_fcmpd.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_fcmpd(asm_instr * ins, u_char * buf, u_int len,
		asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];
  
  ins->type = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
  ins->flagswritten = ASM_SP_FLAG_FCC0 << opcode.cc;
   
  ins->instr = inter->fcmp_table[(opcode.opf & 0x1f) - 16];
  ins->nb_op = 3;
  ins->op[0].baser = ((opcode.rs2 & 1) << 5) | (opcode.rs2 & 0x1E);
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_FREGISTER, ins);
  ins->op[1].baser = ((opcode.rs1 & 1) << 5) | (opcode.rs1 & 0x1E);
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_FREGISTER, ins);
  ins->op[2].baser = opcode.cc;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_CC, ins);
  
  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_fcmped.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_fcmped(asm_instr * ins, u_char * buf, u_int len,
		 asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];
  
  ins->type = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
  ins->flagswritten = ASM_SP_FLAG_FCC0 << opcode.cc;

  ins->instr = inter->fcmp_table[(opcode.opf & 0x1f) - 16];
  ins->nb_op = 3;
  ins->op[0].baser = ((opcode.rs2 & 1) << 5) | (opcode.rs2 & 0x1E);
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_FREGISTER, ins);
  ins->op[1].baser = ((opcode.rs1 & 1) << 5) | (opcode.rs1 & 0x1E);
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_FREGISTER, ins);
  ins->op[2].baser = opcode.cc;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_CC, ins);
  
  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_fcmpeq.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_fcmpeq(asm_instr * ins, u_char * buf, u_int len,
		 asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];
  
  ins->type = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
  ins->flagswritten = ASM_SP_FLAG_FCC0 << opcode.cc;

  ins->instr = inter->fcmp_table[(opcode.opf & 0x1f) - 16];
  ins->nb_op = 3;
  ins->op[0].baser = ((opcode.rs2 & 1) << 5) | (opcode.rs2 & 0x1E);
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_FREGISTER, ins);
  ins->op[1].baser = ((opcode.rs1 & 1) << 5) | (opcode.rs1 & 0x1E);
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_FREGISTER, ins);
  ins->op[2].baser = opcode.cc;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_CC, ins);
  
  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_fcmpes.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_fcmpes(asm_instr * ins, u_char * buf, u_int len,
		 asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];
  
  ins->type = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
  ins->flagswritten = ASM_SP_FLAG_FCC0 << opcode.cc;

  ins->instr = inter->fcmp_table[(opcode.opf & 0x1f) - 16];
  ins->nb_op = 3;
  ins->op[0].baser = opcode.rs2;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_FREGISTER, ins);
  ins->op[1].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_FREGISTER, ins);
  ins->op[2].baser = opcode.cc;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_CC, ins);
  
  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_fcmpq.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_fcmpq(asm_instr * ins, u_char * buf, u_int len,
		asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];
  
  ins->type = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
  ins->flagswritten = ASM_SP_FLAG_FCC0 << opcode.cc;

  ins->instr = inter->fcmp_table[(opcode.opf & 0x1f) - 16];
  ins->nb_op = 3;
  ins->op[0].baser = ((opcode.rs2 & 1) << 5) | (opcode.rs2 & 0x1E);
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_FREGISTER, ins);
  ins->op[1].baser = ((opcode.rs1 & 1) << 5) | (opcode.rs1 & 0x1E);
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_FREGISTER, ins);
  ins->op[2].baser = opcode.cc;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_CC, ins);
  
  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_fcmps.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_fcmps(asm_instr * ins, u_char * buf, u_int len,
		asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];
  
  ins->type = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
  ins->flagswritten = ASM_SP_FLAG_FCC0 << opcode.cc;

  ins->instr = inter->fcmp_table[(opcode.opf & 0x1f) - 16];
  ins->nb_op = 3;
  ins->op[0].baser = opcode.rs2;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_FREGISTER, ins);
  ins->op[1].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_FREGISTER, ins);
  ins->op[2].baser = opcode.cc;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_CC, ins);
  
  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_flush.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_flush(asm_instr * ins, u_char * buf, u_int len,
		asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];
  
  ins->type = ASM_TYPE_OTHER;

  ins->nb_op = 1;
  if (opcode.i) {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }
  
  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_flushw.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_flushw(asm_instr * ins, u_char * buf, u_int len,
		 asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  
  ins->type = ASM_TYPE_OTHER;

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_fmovdcc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_fmovdcc(asm_instr * ins, u_char * buf, u_int len,
		  asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->type = ASM_TYPE_ASSIGN | ASM_TYPE_READFLAG;

  if (opcode.opf_cc < 4) {
    ins->instr = inter->fmovfcc_table[(((opcode.opf & 0x1f) - 1) * 8)
				      + opcode.cond];

    ins->flagsread = ASM_SP_FLAG_FCC0 << opcode.opf_cc;
  }
  else if (opcode.opf_cc == 4 || opcode.opf_cc == 6) {
    ins->instr = inter->fmovcc_table[(((opcode.opf & 0x1f) - 1) * 8)
				     + opcode.cond];

    ins->flagsread = ASM_SP_FLAG_C | ASM_SP_FLAG_V | ASM_SP_FLAG_N | ASM_SP_FLAG_Z;
  }
  else {
    ins->instr = ASM_SP_BAD;
    return 4;
  }

  ins->nb_op = 3;
  ins->op[0].baser = ((opcode.rd & 1) << 5) | (opcode.rd & 0x1E);
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_FREGISTER, ins);
  ins->op[1].baser = ((opcode.rs2 & 1) << 5) | (opcode.rs2 & 0x1E);
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_FREGISTER, ins);
  ins->op[2].baser = opcode.opf_cc;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_CC, ins);

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_fmovdr.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_fmovdr(asm_instr * ins, u_char * buf, u_int len,
		 asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  
  ins->type = ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;

  inter = proc->internals;

  ins->instr = inter->fmovr_table[(((opcode.opf & 0x1f) - 6) * 8)
				  + opcode.rcond];

  ins->nb_op = 3;
  ins->op[0].baser = ((opcode.rd & 1) << 5) | (opcode.rd & 0x1E);
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_FREGISTER, ins);
  ins->op[1].baser = ((opcode.rs2 & 1) << 5) | (opcode.rs2 & 0x1E);
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_FREGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);
  
  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_fmovqcc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_fmovqcc(asm_instr * ins, u_char * buf, u_int len,
		  asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->type = ASM_TYPE_ASSIGN | ASM_TYPE_READFLAG;

  if (opcode.opf_cc < 4) {
    ins->instr = inter->fmovfcc_table[(((opcode.opf & 0x1f) - 1) * 8)
				      + opcode.cond];

    ins->flagsread = ASM_SP_FLAG_FCC0 << opcode.opf_cc;
  }
  else if (opcode.opf_cc == 4 || opcode.opf_cc == 6) {
    ins->instr = inter->fmovcc_table[(((opcode.opf & 0x1f) - 1) * 8)
				     + opcode.cond];

    ins->flagsread = ASM_SP_FLAG_C | ASM_SP_FLAG_V | ASM_SP_FLAG_N | ASM_SP_FLAG_Z;
  }
  else {
    ins->instr = ASM_SP_BAD;
    return 4;
  }

  ins->nb_op = 3;
  ins->op[0].baser = ((opcode.rd & 1) << 5) | (opcode.rd & 0x1E);
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_FREGISTER, ins);
  ins->op[1].baser = ((opcode.rs2 & 1) << 5) | (opcode.rs2 & 0x1E);
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_FREGISTER, ins);
  ins->op[2].baser = opcode.opf_cc;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_CC, ins);

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_fmovqr.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_fmovqr(asm_instr * ins, u_char * buf, u_int len,
		 asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->type = ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;

  ins->instr = inter->fmovr_table[(((opcode.opf & 0x1f) - 6) * 8)
				  + opcode.rcond];

  ins->nb_op = 3;
  ins->op[0].baser = ((opcode.rd & 1) << 5) | (opcode.rd & 0x1E);
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_FREGISTER, ins);
  ins->op[1].baser = ((opcode.rs2 & 1) << 5) | (opcode.rs2 & 0x1E);
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_FREGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_fmovscc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_fmovscc(asm_instr * ins, u_char * buf, u_int len,
		  asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->type = ASM_TYPE_ASSIGN | ASM_TYPE_READFLAG;

  if (opcode.opf_cc < 4) {
    ins->instr = inter->fmovfcc_table[(((opcode.opf & 0x1f) - 1) * 8)
  	    									+ opcode.cond];

    ins->flagsread = ASM_SP_FLAG_FCC0 << opcode.opf_cc;
  }
  else if (opcode.opf_cc == 4 || opcode.opf_cc == 6) {
    ins->instr = inter->fmovcc_table[(((opcode.opf & 0x1f) - 1) * 8)
   	    									+ opcode.cond];

    ins->flagsread = ASM_SP_FLAG_C | ASM_SP_FLAG_V | ASM_SP_FLAG_N | ASM_SP_FLAG_Z;
  }
  else {
    ins->instr = ASM_SP_BAD;
    return 4;
  }

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_FREGISTER, ins);
  ins->op[1].baser = opcode.rs2;
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_FREGISTER, ins);
  ins->op[2].baser = opcode.opf_cc;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_CC, ins);

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_fmovsr.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_fmovsr(asm_instr * ins, u_char * buf, u_int len,
		 asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->type = ASM_TYPE_ASSIGN | ASM_TYPE_COMPARISON;

  ins->instr = inter->fmovr_table[(((opcode.opf & 0x1f) - 6) * 8)
				  + opcode.rcond];

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_FREGISTER, ins);
  ins->op[1].baser = opcode.rs2;
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_FREGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_fpop1.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_fpop1(asm_instr * ins, u_char * buf, u_int len,
		asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;

  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;  
  ins->instr = inter->fpop1_table[opcode.opf];

  if (opcode.opf < 0x40 || opcode.opf >= 0x70) {
    ins->type = ASM_TYPE_ASSIGN;
    ins->nb_op = 2;
  }
  else { /* 0x40 < opf < 0x69 - add, sub, mul, div */
    ins->type = ASM_TYPE_ARITH;

    /* FIXME: what is the value to switch on here ? */
    /*
    switch ()
      {
      case:
	ins->arith = ASM_ARITH_ADD;        
	break;
      case:
	ins->arith = ASM_ARITH_SUB;        
	break;
      case:
	ins->arith = ASM_ARITH_MUL;        
	break;
      case:
	ins->arith = ASM_ARITH_DIV;        
	break;
      }
    */

    ins->nb_op = 3;
    ins->op[2].baser = opcode.rs1;
    asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_FREGISTER, ins);
  }

  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_FREGISTER, ins);
  ins->op[1].baser = opcode.rs2;
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_FREGISTER, ins);

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_illegal.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_illegal(asm_instr * ins, u_char * buf, u_int len,
		  asm_processor * proc)
{
  ins->instr = ASM_SP_BAD;
  ins->type  = ASM_TYPE_STOP;
  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_illtrap.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_illtrap(asm_instr * ins, u_char * buf, u_int len,
		  asm_processor * proc)
{
  struct s_decode_branch opcode;
  sparc_convert_branch(&opcode, buf);
  
  ins->type = ASM_TYPE_INT | ASM_TYPE_STOP;

  ins->instr = ASM_SP_ILLTRAP;
  ins->nb_op = 1;
  ins->op[0].imm = opcode.immediate;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_IMMEDIATE, ins);

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_impdep1.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_impdep1(asm_instr * ins, u_char * buf, u_int len,
		  asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  
  ins->type = ASM_TYPE_ARCH;

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_impdep2.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_impdep2(asm_instr * ins, u_char * buf, u_int len,
		  asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  
  ins->type = ASM_TYPE_ARCH;

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_jmpl.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_jmpl(asm_instr * ins, u_char * buf, u_int len,
	 asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];
  
  ins->type = ASM_TYPE_BRANCH;

  ins->nb_op = 2;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  if (ins->op[0].baser == ASM_REG_O7) {
    ins->nb_op = 1;
    ins->instr = ASM_SP_CALL;
    ins->type = ASM_TYPE_CALLPROC;
    ins->op[0] = ins->op[1];
  }
  else if (ins->op[0].baser == ASM_REG_G0) {
    if (ins->op[1].content == ASM_SP_OTYPE_IMM_ADDRESS &&
        ins->op[1].baser == ASM_REG_I7 && ins->op[1].imm == 8) {

      ins->instr = ASM_SP_RET;
      ins->type = ASM_TYPE_RETPROC;
      ins->nb_op = 0;
    }
    else if (ins->op[1].content == ASM_SP_OTYPE_IMM_ADDRESS &&
       ins->op[1].baser == ASM_REG_O7 && ins->op[1].imm == 8) {

      ins->instr = ASM_SP_RETL;
      ins->type = ASM_TYPE_RETPROC;
      ins->nb_op = 0;
    }
    else {
      ins->instr = ASM_SP_JMP;
      ins->nb_op = 1;
      ins->op[0] = ins->op[1];
    }
  }
  
  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_ldda.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_ldda(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    ins->op[1].address_space = -1;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    ins->op[1].address_space = opcode.none;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_ldd.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_ldd(asm_instr * ins, u_char * buf, u_int len,
	      asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN;
  
  ins->nb_op = 2;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_lddfa.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_lddfa(asm_instr * ins, u_char * buf, u_int len,
		asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  ins->op[0].baser = ((opcode.rd & 1) << 5) | (opcode.rd & 0x1E);
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_FREGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    ins->op[1].address_space = -1;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    ins->op[1].address_space = opcode.none;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_lddf.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_lddf(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  ins->op[0].baser = ((opcode.rd & 1) << 5) | (opcode.rd & 0x1E);
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_FREGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_ldfa.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_ldfa(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_FREGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    ins->op[1].address_space = -1;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    ins->op[1].address_space = opcode.none;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_ldf.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_ldf(asm_instr * ins, u_char * buf, u_int len,
	      asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_FREGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_ldfsr.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_ldfsr(asm_instr * ins, u_char * buf, u_int len,
		asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN;
  
  if (opcode.rd == 0)
    ins->instr = ASM_SP_LDFSR;
  else if (opcode.rd == 1)
    ins->instr = ASM_SP_LDXFSR;
  else {
    ins->instr = ASM_SP_BAD;
    return 4;
  }

  ins->nb_op = 2;
  ins->op[0].baser = ASM_FREG_FSR;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_FREGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_ldqfa.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_ldqfa(asm_instr * ins, u_char * buf, u_int len,
		asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  ins->op[0].baser = ((opcode.rd & 1) << 5) | (opcode.rd & 0x1E);
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_FREGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    ins->op[1].address_space = -1;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    ins->op[1].address_space = opcode.none;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_ldqf.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_ldqf(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  ins->op[0].baser = ((opcode.rd & 1) << 5) | (opcode.rd & 0x1E);
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_FREGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_ldsba.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_ldsba(asm_instr * ins, u_char * buf, u_int len,
		asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    ins->op[1].address_space = -1;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    ins->op[1].address_space = opcode.none;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_ldsb.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_ldsb(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];

  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_ldsha.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_ldsha(asm_instr * ins, u_char * buf, u_int len,
		asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN;
  
  ins->nb_op = 2;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    ins->op[1].address_space = -1;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    ins->op[1].address_space = opcode.none;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_ldsh.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_ldsh(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];

  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_ldstuba.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_ldstuba(asm_instr * ins, u_char * buf, u_int len,
		  asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN | ASM_TYPE_STORE;

  ins->nb_op = 2;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    ins->op[1].address_space = -1;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    ins->op[1].address_space = opcode.none;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_ldstub.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_ldstub(asm_instr * ins, u_char * buf, u_int len,
		 asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN | ASM_TYPE_STORE;
  
  ins->nb_op = 2;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_ldswa.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_ldswa(asm_instr * ins, u_char * buf, u_int len,
		asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    ins->op[1].address_space = -1;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    ins->op[1].address_space = opcode.none;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_ldsw.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_ldsw(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN;
  
  ins->nb_op = 2;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_lduba.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_lduba(asm_instr * ins, u_char * buf, u_int len,
		asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    ins->op[1].address_space = -1;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    ins->op[1].address_space = opcode.none;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_ldub.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_ldub(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN;
  
  ins->nb_op = 2;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_lduha.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_lduha(asm_instr * ins, u_char * buf, u_int len,
		asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    ins->op[1].address_space = -1;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    ins->op[1].address_space = opcode.none;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_lduh.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_lduh(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN;
  
  ins->nb_op = 2;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_lduwa.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_lduwa(asm_instr * ins, u_char * buf, u_int len,
		asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    ins->op[1].address_space = -1;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    ins->op[1].address_space = opcode.none;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_lduw.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_lduw(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN;
  
  ins->nb_op = 2;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_ldxa.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_ldxa(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    ins->op[1].address_space = -1;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    ins->op[1].address_space = opcode.none;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;

}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_ldx.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_ldx(asm_instr * ins, u_char * buf, u_int len,
	      asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD | ASM_TYPE_ASSIGN;
  
  ins->nb_op = 2;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_movcc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_movcc(asm_instr * ins, u_char * buf, u_int len,
		asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_decode_format4 opcode4;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  sparc_convert_format4(&opcode4, buf);

  inter = proc->internals;
  ins->type = ASM_TYPE_ASSIGN | ASM_TYPE_READFLAG;

  if (opcode4.cc2 == 0) { /* fcc{0,1,2,3,4} */
   	ins->instr = inter->movcc_table[opcode4.cond];  	  	
    ins->flagsread = ASM_SP_FLAG_FCC0 << opcode4.cc;
  }
  else if (opcode4.cc0 == 0) { /* icc or xcc */
   	ins->instr = inter->movfcc_table[opcode4.cond];
    ins->flagsread = ASM_SP_FLAG_C | ASM_SP_FLAG_V | ASM_SP_FLAG_N | ASM_SP_FLAG_Z;
  }
  else {
    ins->instr = ASM_SP_BAD;
    return 4;
  }

  ins->nb_op = 3;
  ins->op[0].baser = opcode4.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode4.cc;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_CC, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_movr.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_movr(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->type = ASM_TYPE_ASSIGN;

  ins->instr = inter->movr_table[opcode.rcond];
  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm10;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_mulscc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_mulscc(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_MUL;  
  ins->type = ASM_TYPE_ARITH;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_mulx.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_mulx(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_MUL;  
  ins->type = ASM_TYPE_ARITH;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_or.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_or(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_OR;        
  ins->type = ASM_TYPE_ARITH;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) 
    {
      ins->op[1].baser = opcode.rs2;
      asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
    }
  else 
    {
      ins->op[1].imm = opcode.imm;
      asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
    }

  if (asm_config_get_synthinstr())
    {  
      if (ins->op[0].baser == ins->op[2].baser) 
	{
	  ins->instr = ASM_SP_BSET;
	  ins->nb_op = 2;
	  ins->type = ASM_TYPE_BITSET;
	}
      else if (ins->op[2].baser == ASM_REG_G0) 
	{
	  if (ins->op[1].content == ASM_SP_OTYPE_REGISTER &&
	      ins->op[1].baser == ASM_REG_G0) 
	    {
	      ins->instr = ASM_SP_CLR;
	      ins->nb_op = 1;
	    }
	  else 
	    {
	      ins->instr = ASM_SP_MOV;
	      ins->nb_op = 2;
	      ins->type = ASM_TYPE_ASSIGN;
	    }
	}
    }
  
  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_orcc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_orcc(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_OR;          
  ins->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  ins->flagswritten = ASM_SP_FLAG_C | ASM_SP_FLAG_V | ASM_SP_FLAG_Z | ASM_SP_FLAG_N;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  if (ins->op[0].baser == ASM_REG_G0 &&
      ins->op[1].content == ASM_SP_OTYPE_REGISTER &&
      ins->op[2].baser == ASM_REG_G0) {

    ins->instr = ASM_SP_TST;
    ins->type = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
    ins->nb_op = 1;
    ins->op[0] = ins->op[1];
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_orn.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_orn(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->type = ASM_TYPE_LOAD;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_orncc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_orncc(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_OR | ASM_ARITH_NOT;  
  ins->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  ins->flagswritten = ASM_SP_FLAG_C | ASM_SP_FLAG_V | ASM_SP_FLAG_Z | ASM_SP_FLAG_N;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_popc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_popc(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];
  
  ins->type = ASM_TYPE_ASSIGN;

  if (opcode.rs1 == 0) {
    ins->instr = ASM_SP_POPC;
    ins->nb_op = 2;

    ins->op[0].baser = opcode.rd;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);

    if (opcode.i == 0) {
      ins->op[1].baser = opcode.rs2;
      asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
    }
    else {
      ins->op[1].imm = opcode.imm;
      asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
    }
  }
  else
    ins->instr = ASM_SP_BAD;

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_prefetcha.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_prefetcha(asm_instr * ins, u_char * buf, u_int len,
		    asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD;

  ins->nb_op = 2;
  ins->op[0].imm = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_IMMEDIATE, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    ins->op[1].address_space = -1;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    ins->op[1].address_space = opcode.none;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_prefetch.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_prefetch(asm_instr * ins, u_char * buf, u_int len,
		   asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD;

  ins->nb_op = 2;
  ins->op[0].imm = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_IMMEDIATE, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_rd.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_rd(asm_instr * ins, u_char * buf, u_int len,
	     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];
  
  ins->type = ASM_TYPE_ASSIGN;

  if (opcode.rs1 != 15) { /* RD*(-PR) */
    ins->nb_op = 2;

    ins->op[0].baser = opcode.rd;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
    ins->op[1].baser = opcode.rs1;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_SREGISTER, ins);

    if (ins->op[0].baser == ASM_SREG_Y) {
      ins->instr = ASM_SP_MOV;
    }
  }
  else {
    if (opcode.rd != 0)
      ins->instr = ASM_SP_BAD;
    else if (opcode.i == 0) {	/* STBAR */
      ins->type = ASM_TYPE_OTHER;
      ins->instr = ASM_SP_STBAR;
    }
    else if (opcode.i == 1) {	/* MEMBAR */
      ins->instr = ASM_SP_MEMBAR;
      ins->type = ASM_TYPE_OTHER;
      ins->nb_op = 1;

      /* operand = cmask OR mmask */
      ins->op[0].imm = ((opcode.imm & 0x70) >> 4) | (opcode.imm & 0xf);
      asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
    }
  }
  
  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_rdpr.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_rdpr(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];
  
  ins->type = ASM_TYPE_ASSIGN;

  if (opcode.rs1 < ASM_PREG_BAD16 || opcode.rs1 > ASM_PREG_BAD30) {
    ins->nb_op = 2;
    ins->op[0].baser = opcode.rd;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
    ins->op[1].baser = opcode.rs1;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_PREGISTER, ins);
  }
  else
    ins->instr = ASM_SP_BAD;

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_restore.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_restore(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];
  
  ins->type = ASM_TYPE_EPILOG;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_return.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

/**
 * Sparc handler for the return instruction.
 * @param ins Pointer to instruction structure.
 * @param buf Pointer to data to disassemble.
 * @param len Length of data to disassemble.
 * @param proc Pointer to processor structure.
 * @param Return instruction length.
 */

int
asm_sparc_return(asm_instr * ins, u_char * buf, u_int len,
		 asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->type = ASM_TYPE_RETPROC;

  ins->nb_op = 1;

  if (opcode.i) {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_save.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_save(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];
  
  ins->type = ASM_TYPE_PROLOG;

  ins->nb_op = 3;

  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_saved.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_saved(asm_instr * ins, u_char * buf, u_int len,
		asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];
  
  ins->type = ASM_TYPE_PROLOG;

  if (opcode.rd == 0)
    ins->instr = ASM_SP_SAVED;
  else if (opcode.rd == 1)
    ins->instr = ASM_SP_RESTORED;
  else
    ins->instr = ASM_SP_BAD;

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_sdiv.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_sdiv(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_DIV;        
  ins->type = ASM_TYPE_ARITH;

  ins->nb_op = 3;

  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_sdivcc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_sdivcc(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_DIV;        
  ins->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  ins->flagswritten = ASM_SP_FLAG_C | ASM_SP_FLAG_V | ASM_SP_FLAG_Z | ASM_SP_FLAG_N;

  ins->nb_op = 3;

  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_sdivx.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_sdivx(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_DIV;  
  ins->type = ASM_TYPE_ARITH;

  ins->nb_op = 3;

  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_sethi.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_sethi(asm_instr * ins, u_char * buf, u_int len,
		asm_processor * proc)
{
  struct s_decode_branch opcode;
  sparc_convert_branch(&opcode, buf);
  
  ins->type = ASM_TYPE_ASSIGN;

  if (!opcode.rd && !opcode.imm) {
    ins->instr = ASM_SP_NOP;
    ins->type = ASM_TYPE_NOP;
    ins->nb_op = 0;
  }
  else {
    ins->instr = ASM_SP_SETHI;
    ins->nb_op = 2;
    ins->op[0].baser = opcode.rd;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_SETHI, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_sll.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_sll(asm_instr * ins, u_char * buf, u_int len,
	      asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->arith = ASM_ARITH_SL;        
  ins->type = ASM_TYPE_ARITH;

  ins->instr = inter->shift_table[opcode.op3 - 0x25 +
                                 ((opcode.imm & 0x1000) ? 1 : 0)];

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.shcnt;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_smul.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_smul(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_MUL;  
  ins->type = ASM_TYPE_ARITH;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_smulcc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_smulcc(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_MUL;          
  ins->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  ins->flagswritten = ASM_SP_FLAG_C | ASM_SP_FLAG_V | ASM_SP_FLAG_Z | ASM_SP_FLAG_N;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_sra.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_sra(asm_instr * ins, u_char * buf, u_int len,
	      asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;

  ins->arith = ASM_ARITH_SR;      
  ins->type = ASM_TYPE_ARITH;

  ins->instr = inter->shift_table[opcode.op3 - 0x25 +
                                  ((opcode.imm & 0x1000) ? 1 : 0)];

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.shcnt;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  /* Synthetics */
  if (ins->op[1].content == ASM_SP_OTYPE_REGISTER &&
      ins->op[1].baser == ASM_REG_G0) {

    ins->instr = ASM_SP_SIGNX;
    if (ins->op[2].baser == ins->op[0].baser)
      ins->nb_op = 1;
    else {
      ins->nb_op = 2;
      ins->op[1] = ins->op[2];
    }
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_srl.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_srl(asm_instr * ins, u_char * buf, u_int len,
	      asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->type = ASM_TYPE_ARITH;
  ins->arith = ASM_ARITH_SL;      

  ins->instr = inter->shift_table[opcode.op3 - 0x25 +
				  ((opcode.imm & 0x1000) ? 1 : 0)];

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.shcnt;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  /* Synthetics */
  if (ins->op[1].content == ASM_SP_OTYPE_REGISTER &&
      ins->op[1].baser == ASM_REG_G0) {

    ins->instr = ASM_SP_CLRUW;
    if (ins->op[2].baser == ins->op[0].baser)
      ins->nb_op = 1;
    else {
      ins->nb_op = 2;
      ins->op[1] = ins->op[2];
    }
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_stba.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_stba(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];

  ins->type = ASM_TYPE_STORE | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  if (opcode.i) {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].imm = opcode.imm;
    ins->op[0].address_space = -1;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].indexr = opcode.rs2;
    ins->op[0].address_space = opcode.none;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  ins->op[1].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_stb.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_stb(asm_instr * ins, u_char * buf, u_int len,
	      asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_STORE | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  if (opcode.i) {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  ins->op[1].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (asm_config_get_synthinstr())
    {
      if (ins->op[1].baser == ASM_REG_G0) {
	ins->instr = ASM_SP_CLRB;
	ins->nb_op = 1;
      }
    }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_stda.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_stda(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_STORE | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  if (opcode.i) {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].imm = opcode.imm;
    ins->op[0].address_space = -1;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].indexr = opcode.rs2;
    ins->op[0].address_space = opcode.none;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  ins->op[1].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_std.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_std(asm_instr * ins, u_char * buf, u_int len,
	      asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_STORE | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  if (opcode.i) {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  ins->op[1].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (asm_config_get_synthinstr())
    {
      if (ins->instr == ASM_SP_STB && ins->op[1].baser == ASM_REG_G0) {
	ins->instr = ASM_SP_CLRB;
	ins->nb_op = 1;
      }
      else if (ins->instr == ASM_SP_STH && ins->op[1].baser == ASM_REG_G0) {
	ins->instr = ASM_SP_CLRH;
	ins->nb_op = 1;
      }
      else if (ins->instr == ASM_SP_STW && ins->op[1].baser == ASM_REG_G0) {
	ins->instr = ASM_SP_CLR;
	ins->nb_op = 1;
      }
      else if (ins->instr == ASM_SP_STX && ins->op[1].baser == ASM_REG_G0) {
	ins->instr = ASM_SP_CLRX;
	ins->nb_op = 1;
      }
    }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_stdfa.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_stdfa(asm_instr * ins, u_char * buf, u_int len,
		asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_STORE | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  if (opcode.i) {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].imm = opcode.imm;
    ins->op[0].address_space = -1;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].indexr = opcode.rs2;
    ins->op[0].address_space = opcode.none;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  ins->op[1].baser = ((opcode.rd & 1) << 5) | (opcode.rd & 0x1E);
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_FREGISTER, ins);

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_stdf.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_stdf(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_STORE | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  if (opcode.i) {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  ins->op[1].baser = ((opcode.rd & 1) << 5) | (opcode.rd & 0x1E);
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_FREGISTER, ins);

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_stfa.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_stfa(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_STORE | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  if (opcode.i) {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].imm = opcode.imm;
    ins->op[0].address_space = -1;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].indexr = opcode.rs2;
    ins->op[0].address_space = opcode.none;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  ins->op[1].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_FREGISTER, ins);

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_stf.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_stf(asm_instr * ins, u_char * buf, u_int len,
	      asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_STORE | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  if (opcode.i) {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  ins->op[1].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_FREGISTER, ins);

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_stfsr.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_stfsr(asm_instr * ins, u_char * buf, u_int len,
		asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_STORE | ASM_TYPE_ASSIGN;

  if (opcode.rd == 0)
    ins->instr = ASM_SP_LDFSR;
  else if (opcode.rd == 1)
    ins->instr = ASM_SP_LDXFSR;
  else {
    ins->instr = ASM_SP_BAD;
    return 4;
  }

  ins->nb_op = 2;
  if (opcode.i) {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  ins->op[1].baser = ASM_FREG_FSR;
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_FREGISTER, ins);

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_stha.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_stha(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_STORE | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  if (opcode.i) {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].imm = opcode.imm;
    ins->op[0].address_space = -1;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].indexr = opcode.rs2;
    ins->op[0].address_space = opcode.none;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  ins->op[1].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_sth.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_sth(asm_instr * ins, u_char * buf, u_int len,
	      asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_STORE | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  if (opcode.i) {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  ins->op[1].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (asm_config_get_synthinstr())
    {
      if (ins->op[1].baser == ASM_REG_G0) {
	ins->instr = ASM_SP_CLRH;
	ins->nb_op = 1;
      }
    }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_stqfa.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_stqfa(asm_instr * ins, u_char * buf, u_int len,
		asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_STORE | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  if (opcode.i) {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].imm = opcode.imm;
    ins->op[0].address_space = -1;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].indexr = opcode.rs2;
    ins->op[0].address_space = opcode.none;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  ins->op[1].baser = ((opcode.rd & 1) << 5) | (opcode.rd & 0x1E);
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_FREGISTER, ins);

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_stqf.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_stqf(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_STORE | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  if (opcode.i) {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  ins->op[1].baser = ((opcode.rd & 1) << 5) | (opcode.rd & 0x1E);
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_FREGISTER, ins);

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_stwa.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_stwa(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_STORE | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  if (opcode.i) {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].imm = opcode.imm;
    ins->op[0].address_space = -1;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].indexr = opcode.rs2;
    ins->op[0].address_space = opcode.none;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  ins->op[1].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_stw.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_stw(asm_instr * ins, u_char * buf, u_int len,
	      asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_STORE | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  if (opcode.i) {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  ins->op[1].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (asm_config_get_synthinstr())
    {
      if (ins->op[1].baser == ASM_REG_G0) {
	ins->instr = ASM_SP_CLR;
	ins->nb_op = 1;
      }
    }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_stxa.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_stxa(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_STORE | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  if (opcode.i) {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].imm = opcode.imm;
    ins->op[0].address_space = -1;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].indexr = opcode.rs2;
    ins->op[0].address_space = opcode.none;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  ins->op[1].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_stx.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_stx(asm_instr * ins, u_char * buf, u_int len,
	      asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_STORE | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  if (opcode.i) {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[0].baser = opcode.rs1;
    ins->op[0].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  ins->op[1].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (asm_config_get_synthinstr())
    {
      if (ins->op[1].baser == ASM_REG_G0) {
	ins->instr = ASM_SP_CLRX;
	ins->nb_op = 1;
      }
    }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_sub.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_sub(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_SUB;      
  ins->type = ASM_TYPE_ARITH;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  if (asm_config_get_synthinstr())
    {
      if ((ins->op[0].baser == ins->op[2].baser) &&
	  ins->op[1].content == ASM_SP_OTYPE_IMMEDIATE) {
	
	ins->instr = ASM_SP_DEC;
	
	if (ins->op[1].imm == 1)
	  ins->nb_op = 1;
	else
	  ins->nb_op = 2;
      }
      else if (ins->op[2].baser == ASM_REG_G0 &&
	       ins->op[1].content == ASM_SP_OTYPE_REGISTER) {
	
	ins->instr = ASM_SP_NEG;
	if (ins->op[1].baser == ins->op[0].baser)
	  ins->nb_op = 1;
	else
	  ins->nb_op = 2;
      }
    }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_subc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_subc(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_SUB;  
  ins->type = ASM_TYPE_ARITH;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_subcc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_subcc(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_SUB;    
  ins->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  ins->flagswritten = ASM_SP_FLAG_C | ASM_SP_FLAG_V | ASM_SP_FLAG_Z | ASM_SP_FLAG_N;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  if (asm_config_get_synthinstr())
    {
      if (ins->op[0].baser == ASM_REG_G0) 
	{
	  ins->instr = ASM_SP_CMP;
	  ins->type  = ASM_TYPE_COMPARISON | ASM_TYPE_WRITEFLAG;
	  ins->nb_op = 2;
	  ins->op[0] = ins->op[1];
	  ins->op[1] = ins->op[2];
	}
      else if ((ins->op[0].baser == ins->op[2].baser) &&
	       ins->op[1].content == ASM_SP_OTYPE_IMMEDIATE) 
	{
	  ins->instr = ASM_SP_DECCC;
	  if (ins->op[1].imm == 1)
	    ins->nb_op = 1;
	  else
	    ins->nb_op = 2;
	}
    }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_subccc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_subccc(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_SUB;  
  ins->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  ins->flagswritten = ASM_SP_FLAG_C | ASM_SP_FLAG_V | ASM_SP_FLAG_Z | ASM_SP_FLAG_N;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_swapa.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_swapa(asm_instr * ins, u_char * buf, u_int len,
		asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];
  
  ins->type = ASM_TYPE_LOAD | ASM_TYPE_STORE | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    ins->op[1].address_space = -1;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    ins->op[1].address_space = opcode.none;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_swap.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_swap(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op3_table[opcode.op3];

  ins->type = ASM_TYPE_LOAD | ASM_TYPE_STORE | ASM_TYPE_ASSIGN;

  ins->nb_op = 2;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i) {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[1].baser = opcode.rs1;
    ins->op[1].indexr = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_taddcc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_taddcc(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_ADD;        
  ins->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  ins->flagswritten = ASM_SP_FLAG_C | ASM_SP_FLAG_V | ASM_SP_FLAG_Z | ASM_SP_FLAG_N;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_taddcctv.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_taddcctv(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_ADD;        
  ins->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  ins->flagswritten = ASM_SP_FLAG_C | ASM_SP_FLAG_V | ASM_SP_FLAG_Z | ASM_SP_FLAG_N;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_tcc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_tcc(asm_instr * ins, u_char * buf, u_int len,
	      asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_decode_format4 opcode4;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  sparc_convert_format4(&opcode4, buf);

  inter = proc->internals;
  ins->type = ASM_TYPE_INT | ASM_TYPE_READFLAG;
  ins->flagsread = ASM_SP_FLAG_C | ASM_SP_FLAG_V | ASM_SP_FLAG_N | ASM_SP_FLAG_Z;

  ins->instr = inter->tcc_table[opcode4.cond];
  ins->nb_op = 2;
  if (opcode4.i) {
    ins->op[0].baser = opcode4.rs1;
    ins->op[0].imm = opcode4.sw_trap;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_IMM_ADDRESS, ins);
  }
  else {
    ins->op[0].baser = opcode4.rs1;
    ins->op[0].indexr = opcode4.rs2;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REG_ADDRESS, ins);
  }

  ins->op[1].baser = (opcode4.cc & 0x3) + 4;
  asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_CC, ins);

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_tsubcc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_tsubcc(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_SUB;  
  ins->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  ins->flagswritten = ASM_SP_FLAG_C | ASM_SP_FLAG_V | ASM_SP_FLAG_Z | ASM_SP_FLAG_N;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_tsubcctv.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_tsubcctv(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_SUB;
  ins->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  ins->flagswritten = ASM_SP_FLAG_C | ASM_SP_FLAG_V | ASM_SP_FLAG_Z | ASM_SP_FLAG_N;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_udiv.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_udiv(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_DIV;          
  ins->type = ASM_TYPE_ARITH;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_udivcc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_udivcc(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_DIV;  
  ins->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  ins->flagswritten = ASM_SP_FLAG_C | ASM_SP_FLAG_V | ASM_SP_FLAG_Z | ASM_SP_FLAG_N;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_udivx.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_udivx(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_DIV;  
  ins->type = ASM_TYPE_ARITH;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_umul.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_umul(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_MUL;        
  ins->type = ASM_TYPE_ARITH;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_umulcc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_umulcc(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_MUL;        
  ins->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  ins->flagswritten = ASM_SP_FLAG_C | ASM_SP_FLAG_V | ASM_SP_FLAG_Z | ASM_SP_FLAG_N;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_wr.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_wr(asm_instr * ins, u_char * buf, u_int len,
	     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];
  
  ins->type = ASM_TYPE_ASSIGN;

  if (opcode.rd == 1)
    ins->instr = ASM_SP_BAD;
  else if (opcode.rd == 15) {	/* SIR */
    ins->instr = ASM_SP_SIR;
    ins->type = ASM_TYPE_INT;
    ins->nb_op = 1;
    ins->op[0].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }
  else { /* WR */
    ins->nb_op = 3;

    if (opcode.rd == 2) { /* WRCCR overwrites the condition codes */
      ins->type |= ASM_TYPE_WRITEFLAG;
      ins->flagswritten = ASM_SP_FLAG_C | ASM_SP_FLAG_V | ASM_SP_FLAG_Z | ASM_SP_FLAG_N;
    }

    if (opcode.rd == 4 || opcode.rd == 5) /* can't write PC or TICK */
      ins->op[0].baser = ASM_SREG_BAD;
    else
      ins->op[0].baser = opcode.rd;

    asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_SREGISTER, ins);

    ins->op[2].baser = opcode.rs1;
    asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

    if (opcode.i == 0) {
      ins->op[1].baser = opcode.rs2;
      asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
    }
    else {
      ins->op[1].imm = opcode.imm;
      asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
    }

    if (ins->op[0].baser == ASM_SREG_Y && ins->op[2].baser == ASM_REG_G0) {
      ins->instr = ASM_SP_MOV;
      ins->nb_op = 2;
    }
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_wrpr.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_wrpr(asm_instr * ins, u_char * buf, u_int len,
	       asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);
  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];
  
  ins->type = ASM_TYPE_ASSIGN;

  ins->nb_op = 3;
  if (opcode.rd == 31) /* can't write VER */
    ins->op[0].baser = ASM_PREG_BAD16;
  else
    ins->op[0].baser = opcode.rd;

  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_PREGISTER, ins);

  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_xnor.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_xnor(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_XOR | ASM_ARITH_NOT;  
  ins->type = ASM_TYPE_ARITH;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  if (ins->op[1].content == ASM_SP_OTYPE_REGISTER &&
      ins->op[1].baser == ASM_REG_G0) {

    ins->instr = ASM_SP_NOT;
    if (ins->op[2].baser == ins->op[0].baser)
      ins->nb_op = 1;
    else {
      ins->nb_op = 2;
      ins->op[1] = ins->op[2];
    }
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_xnorcc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_xnorcc(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_XOR | ASM_ARITH_NOT;    
  ins->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  ins->flagswritten = ASM_SP_FLAG_C | ASM_SP_FLAG_V | ASM_SP_FLAG_Z | ASM_SP_FLAG_N;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_xor.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_xor(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_XOR;          
  ins->type = ASM_TYPE_ARITH;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  if (asm_config_get_synthinstr())
    {
      if (ins->op[0].baser == ins->op[2].baser) {
	ins->instr = ASM_SP_BTOG;
	ins->nb_op = 2;
      }
    }

  return 4;
}
/**
* @file libasm/src/arch/sparc/handlers/asm_sparc_xorcc.c
** @ingroup SPARC_instrs
*/
/*
**
** $Id$
**
*/
#include "libasm.h"

int
asm_sparc_xorcc(asm_instr * ins, u_char * buf, u_int len,
		     asm_processor * proc)
{
  struct s_decode_format3 opcode;
  struct s_asm_proc_sparc *inter;
  sparc_convert_format3(&opcode, buf);

  inter = proc->internals;
  ins->instr = inter->op2_table[opcode.op3];

  ins->arith = ASM_ARITH_XOR;          
  ins->type = ASM_TYPE_ARITH | ASM_TYPE_WRITEFLAG;
  ins->flagswritten = ASM_SP_FLAG_C | ASM_SP_FLAG_V | ASM_SP_FLAG_Z | ASM_SP_FLAG_N;

  ins->nb_op = 3;
  ins->op[0].baser = opcode.rd;
  asm_sparc_op_fetch(&ins->op[0], buf, ASM_SP_OTYPE_REGISTER, ins);
  ins->op[2].baser = opcode.rs1;
  asm_sparc_op_fetch(&ins->op[2], buf, ASM_SP_OTYPE_REGISTER, ins);

  if (opcode.i == 0) {
    ins->op[1].baser = opcode.rs2;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_REGISTER, ins);
  }
  else {
    ins->op[1].imm = opcode.imm;
    asm_sparc_op_fetch(&ins->op[1], buf, ASM_SP_OTYPE_IMMEDIATE, ins);
  }

  return 4;
}
/**
* @file libasm/src/arch/sparc/operand_handlers/asm_sparc_op_fetch.c
** @ingroup SPARC_operands
*/
#include <libasm.h>
#include <libasm-int.h>


/**
 * Main function, dispatch processing to handler.
 * @param op Pointer to operand to fill
 * @param opcode Pointer to operand data.
 * @param otype Content of operand to fetch : ASM_OTYPE_*
 * @param proc Pointer to processor structure.
 * @return Operand length or -1 on error (should currently never occur)
 */
int asm_sparc_op_fetch(asm_operand *op, u_char *opcode, int otype, 
		       asm_instr *ins)
{ 
  vector_t      *vec;
  u_int         dim[1];
  int           to_ret;
  int           (*fetch)(asm_operand *, u_char *, int, asm_instr *);
  
  vec = aspect_vector_get("operand-sparc");
  dim[0] = otype;
  
  fetch = aspect_vectors_select(vec, dim);
  to_ret = fetch(op, opcode, otype, ins);

  if (to_ret == -1)
  {
    printf("%s:%i Unsupported operand content : %i\n", __FILE__, __LINE__, 
    	     otype);
  }

  op->name = asm_sparc_get_op_name(op);

  return (to_ret);
}
/**
* @file libasm/src/arch/sparc/operand_handlers/asm_sparc_op_fetch_cc.c
** @ingroup SPARC_operands
*/
#include <libasm.h>
#include <libasm-sparc.h>

/**
 * Decode data for operand content ASM_SP_OTYPE_CC
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to opcode data.
 * @param otype Operand content.
 * @param ins Pointer to instruction structure.
 *
 * @return Operand length (currently unused in libasm-sparc)
 */

int asm_sparc_op_fetch_cc(asm_operand *operand, u_char *opcode, 
                 				   int otype, asm_instr *ins)
{
  operand->content = ASM_SP_OTYPE_CC;
  operand->type    = ASM_OPTYPE_REG;
  return (0);
}
/**
* @file libasm/src/arch/sparc/operand_handlers/asm_sparc_op_fetch_disp30.c
** @ingroup SPARC_operands
*/
#include <libasm.h>
#include <libasm-sparc.h>

/**
 * Decode data for operand content ASM_SP_OTYPE_DISP30
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to opcode data.
 * @param otype Operand content.
 * @param ins Pointer to instruction structure.
 *
 * @return Operand length (currently unused in libasm-sparc)
 */

int asm_sparc_op_fetch_disp30(asm_operand *operand, u_char *opcode, 
                     				   int otype, asm_instr *ins)
{
  operand->content = ASM_SP_OTYPE_DISP30;
  operand->type    = ASM_OPTYPE_IMM;
  return (0);
}
/**
* @file libasm/src/arch/sparc/operand_handlers/asm_sparc_op_fetch_displacement.c
** @ingroup SPARC_operands
*/
#include <libasm.h>
#include <libasm-sparc.h>

/**
 * Decode data for operand content ASM_SP_OTYPE_DISPLACEMENT
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to opcode data.
 * @param otype Operand content.
 * @param ins Pointer to instruction structure.
 *
 * @return Operand length (currently unused in libasm-sparc)
 */

int asm_sparc_op_fetch_displacement(asm_operand *operand, u_char *opcode, 
                           				   int otype, asm_instr *ins)
{
  operand->content = ASM_SP_OTYPE_DISPLACEMENT;
  operand->type    = ASM_OPTYPE_IMM;
  return (0);
}
/**
* @file libasm/src/arch/sparc/operand_handlers/asm_sparc_op_fetch_fregister.c
** @ingroup SPARC_operands
*/
#include <libasm.h>
#include <libasm-sparc.h>

/**
 * Decode data for operand content ASM_SP_OTYPE_FREGISTER
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to opcode data.
 * @param otype Operand content.
 * @param ins Pointer to instruction structure.
 *
 * @return Operand length (currently unused in libasm-sparc)
 */

int asm_sparc_op_fetch_fregister(asm_operand *operand, u_char *opcode, 
                       				   int otype, asm_instr *ins)
{
  operand->content = ASM_SP_OTYPE_FREGISTER;
  operand->type    = ASM_OPTYPE_REG;
  return (0);
}
/**
* @file libasm/src/arch/sparc/operand_handlers/asm_sparc_op_fetch_imm_address.c
** @ingroup SPARC_operands
*/
#include <libasm.h>
#include <libasm-sparc.h>

/**
 * Decode data for operand content ASM_SP_OTYPE_IMM_ADDRESS
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to opcode data.
 * @param otype Operand content.
 * @param ins Pointer to instruction structure.
 *
 * @return Operand length (currently unused in libasm-sparc)
 */

int asm_sparc_op_fetch_imm_address(asm_operand *operand, u_char *opcode, 
                         				   int otype, asm_instr *ins)
{
  operand->content = ASM_SP_OTYPE_IMM_ADDRESS;
  operand->type    = ASM_OPTYPE_MEM;
  return (0);
}
/**
* @file libasm/src/arch/sparc/operand_handlers/asm_sparc_op_fetch_immediate.c
** @ingroup SPARC_operands
*/
#include <libasm.h>
#include <libasm-sparc.h>

/**
 * Decode data for operand content ASM_SP_OTYPE_IMMEDIATE
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to opcode data.
 * @param otype Operand content.
 * @param ins Pointer to instruction structure.
 *
 * @return Operand length (currently unused in libasm-sparc)
 */

int asm_sparc_op_fetch_immediate(asm_operand *operand, u_char *opcode, 
                       				   int otype, asm_instr *ins)
{
  operand->content = ASM_SP_OTYPE_IMMEDIATE;
  operand->type    = ASM_OPTYPE_IMM;
  return (0);
}
/**
* @file libasm/src/arch/sparc/operand_handlers/asm_sparc_op_fetch_pregister.c
** @ingroup SPARC_operands
*/
#include <libasm.h>
#include <libasm-sparc.h>

/**
 * Decode data for operand content ASM_SP_OTYPE_PREGISTER
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to opcode data.
 * @param otype Operand content.
 * @param ins Pointer to instruction structure.
 *
 * @return Operand length (currently unused in libasm-sparc)
 */

int asm_sparc_op_fetch_pregister(asm_operand *operand, u_char *opcode, 
                       				   int otype, asm_instr *ins)
{
  operand->content = ASM_SP_OTYPE_PREGISTER;
  operand->type    = ASM_OPTYPE_REG;
  return (0);
}
/**
* @file libasm/src/arch/sparc/operand_handlers/asm_sparc_op_fetch_reg_address.c
** @ingroup SPARC_operands
*/
#include <libasm.h>
#include <libasm-sparc.h>

/**
 * Decode data for operand content ASM_SP_OTYPE_REG_ADDRESS
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to opcode data.
 * @param otype Operand content.
 * @param ins Pointer to instruction structure.
 *
 * @return Operand length (currently unused in libasm-sparc)
 */

int asm_sparc_op_fetch_reg_address(asm_operand *operand, u_char *opcode, 
				   int otype, asm_instr *ins)
{
  operand->content = ASM_SP_OTYPE_REG_ADDRESS;
  operand->type    = ASM_OPTYPE_MEM;
  return (0);
}
/**
* @file libasm/src/arch/sparc/operand_handlers/asm_sparc_op_fetch_register.c
** @ingroup SPARC_operands
*/
#include <libasm.h>
#include <libasm-sparc.h>

/**
 * Decode data for operand content ASM_SP_OTYPE_REGISTER
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to opcode data.
 * @param otype Operand content.
 * @param ins Pointer to instruction structure.
 *
 * @return Operand length (currently unused in libasm-sparc)
 */

int asm_sparc_op_fetch_register(asm_operand *operand, u_char *opcode, 
                       				   int otype, asm_instr *ins)
{
  operand->content = ASM_SP_OTYPE_REGISTER;
  operand->type    = ASM_OPTYPE_REG;
  return (0);
}
/**
* @file libasm/src/arch/sparc/operand_handlers/asm_sparc_op_fetch_sethi.c
** @ingroup SPARC_operands
*/
#include <libasm.h>
#include <libasm-sparc.h>

/**
 * Decode data for operand content ASM_SP_OTYPE_SETHI
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to opcode data.
 * @param otype Operand content.
 * @param ins Pointer to instruction structure.
 *
 * @return Operand length (currently unused in libasm-sparc)
 */

int asm_sparc_op_fetch_sethi(asm_operand *operand, u_char *opcode, 
                   				   int otype, asm_instr *ins)
{
  operand->content = ASM_SP_OTYPE_SETHI;
  operand->type    = ASM_OPTYPE_IMM;
  return (0);
}
/**
* @file libasm/src/arch/sparc/operand_handlers/asm_sparc_op_fetch_sregister.c
** @ingroup SPARC_operands
*/
#include <libasm.h>
#include <libasm-sparc.h>

/**
 * Decode data for operand content ASM_SP_OTYPE_SREGISTER
 * @param operand Pointer to operand structure to fill.
 * @param opcode Pointer to opcode data.
 * @param otype Operand content.
 * @param ins Pointer to instruction structure.
 *
 * @return Operand length (currently unused in libasm-sparc)
 */

int asm_sparc_op_fetch_sregister(asm_operand *operand, u_char *opcode, 
                       				   int otype, asm_instr *ins)
{
  operand->content = ASM_SP_OTYPE_SREGISTER;
  operand->type    = ASM_OPTYPE_REG;
  return (0);
}
/**
 * @defgroup SPARC_operands SPARC operands API.
 * @ingroup sparc
 */
/**
* @file libasm/src/arch/sparc/operand_handlers/asm_sparc_op_name.c
** @ingroup SPARC_operands
*/
#include <libasm.h>
#include <libasm-sparc.h>

#define ASM_POOL_SIZE 100
#define ASM_OP_NAME_LEN 64

/* FIFO sort-of memory manager */
char *asm_name_pool_alloc() {
  static char* asm_name_pool[ASM_POOL_SIZE] = {};
  static int index = 0;

  char *ret;

  if (asm_name_pool[index] != NULL)
    free(asm_name_pool[index]);

  ret = asm_name_pool[index] = (char *) malloc(ASM_OP_NAME_LEN);
  if (ret != NULL)
    index = (index + 1) % ASM_POOL_SIZE;
  return ret;
}

char *asm_sparc_get_op_name(asm_operand *op) {
  char *buf;

  switch (op->content) {

    case ASM_SP_OTYPE_REGISTER:
      return get_sparc_register(op->baser);
    case ASM_SP_OTYPE_SREGISTER:
      return get_sparc_sregister(op->baser);
    case ASM_SP_OTYPE_PREGISTER:
      return get_sparc_pregister(op->baser);
    case ASM_SP_OTYPE_FREGISTER:
      return get_sparc_fregister(op->baser);
    case ASM_SP_OTYPE_CC:
      return get_sparc_cc(op->baser);

    case ASM_SP_OTYPE_IMM_ADDRESS:
      buf = asm_name_pool_alloc();
      op->sbaser = get_sparc_register(op->baser);
      sprintf(buf, "[ %s", op->sbaser);
      if (op->imm)
        sprintf(buf+strlen(buf), " + 0x%x", op->imm);
        
      sprintf(buf+strlen(buf), " ]");
      
      if (op->address_space != ASM_SP_ASI_P)
        sprintf(buf+strlen(buf), " %%asi");

      return buf;
    case ASM_SP_OTYPE_REG_ADDRESS:
      buf = asm_name_pool_alloc();
      op->sbaser = get_sparc_register(op->baser);

      if (op->indexr > 0)
	{
	  op->sindex = get_sparc_register(op->indexr);
	  sprintf(buf, "[ %s + %s ]", op->sbaser, op->sindex);
	}
      else
	sprintf(buf, "[ %s ]", op->sbaser);
      
      if (op->address_space != ASM_SP_ASI_P)
        sprintf(buf+strlen(buf), " 0x%x", op->address_space);

      return buf;
      
    default:
      return NULL;

  }
}

