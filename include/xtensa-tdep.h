/* Target-dependent code for the Xtensa port of GDB, the GNU debugger.

   Copyright (C) 2003-2022 Free Software Foundation, Inc.

   This file is part of GDB.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#ifndef XTENSA_TDEP_H
#define XTENSA_TDEP_H

/* XTENSA_TDEP_VERSION can/should be changed along with XTENSA_CONFIG_VERSION
   whenever the "tdep" structure changes in an incompatible way.  */

#ifdef __cplusplus
extern "C" {
#endif

#define XTENSA_TDEP_VERSION 0x60

/*  Xtensa register type.  */

typedef enum 
{
  xtRegisterTypeArRegfile = 1,	/* Register File ar0..arXX.  */
  xtRegisterTypeSpecialReg,	/* CPU states, such as PS, Booleans, (rsr).  */
  xtRegisterTypeUserReg,	/* User defined registers (rur).  */
  xtRegisterTypeTieRegfile,	/* User define register files.  */
  xtRegisterTypeTieState,	/* TIE States (mapped on user regs).  */
  xtRegisterTypeMapped,		/* Mapped on Special Registers.  */
  xtRegisterTypeUnmapped,	/* Special case of masked registers.  */
  xtRegisterTypeWindow,		/* Live window registers (a0..a15).  */
  xtRegisterTypeVirtual,	/* PC, FP.  */
  xtRegisterTypeUnknown
} xtensa_register_type_t;


/*  Xtensa register group.  */

#define XTENSA_MAX_COPROCESSOR	0x10  /* Number of Xtensa coprocessors.  */

typedef enum 
{
  xtRegisterGroupUnknown = 0,
  xtRegisterGroupRegFile	= 0x0001,    /* Register files without ARx.  */
  xtRegisterGroupAddrReg	= 0x0002,    /* ARx.  */
  xtRegisterGroupSpecialReg	= 0x0004,    /* SRxx.  */
  xtRegisterGroupUserReg	= 0x0008,    /* URxx.  */
  xtRegisterGroupState 		= 0x0010,    /* States.  */

  xtRegisterGroupGeneral	= 0x0100,    /* General registers, Ax, SR.  */
  xtRegisterGroupUser		= 0x0200,    /* User registers.  */
  xtRegisterGroupFloat		= 0x0400,    /* Floating Point.  */
  xtRegisterGroupVectra		= 0x0800,    /* Vectra.  */
  xtRegisterGroupSystem		= 0x1000,    /* System.  */

  xtRegisterGroupNCP	    = 0x00800000,    /* Non-CP non-base opt/custom.  */
  xtRegisterGroupCP0	    = 0x01000000,    /* CP0.  */
  xtRegisterGroupCP1	    = 0x02000000,    /* CP1.  */
  xtRegisterGroupCP2	    = 0x04000000,    /* CP2.  */
  xtRegisterGroupCP3	    = 0x08000000,    /* CP3.  */
  xtRegisterGroupCP4	    = 0x10000000,    /* CP4.  */
  xtRegisterGroupCP5	    = 0x20000000,    /* CP5.  */
  xtRegisterGroupCP6	    = 0x40000000,    /* CP6.  */
  xtRegisterGroupCP7	    = 0x80000000,    /* CP7.  */

} xtensa_register_group_t;


/*  Xtensa target flags.  */

typedef enum 
{
  xtTargetFlagsNonVisibleRegs	= 0x0001,
  xtTargetFlagsUseFetchStore	= 0x0002,
} xtensa_target_flags_t;


/*  Mask.  */

typedef struct 
{
  int reg_num;
  int bit_start;
  int bit_size;
} xtensa_reg_mask_t;

typedef struct 
{
  int count;
  xtensa_reg_mask_t *mask;
} xtensa_mask_t;


/*  Xtensa register representation.  */

typedef struct 
{
  const char *name;            	/* Register name.  */
  int offset;             	/* Offset.  */
  xtensa_register_type_t type;  /* Register type.  */
  xtensa_register_group_t group;/* Register group.  */
  struct type* ctype;		/* C-type.  */
  int bit_size;  		/* The actual bit size in the target.  */
  int byte_size;          	/* Actual space allocated in registers[].  */
  int align;			/* Alignment for this register.  */

  unsigned int target_number;	/* Register target number.  */

  int flags;			/* Flags.  */
  int coprocessor;		/* Coprocessor num, -1 for non-CP, else -2.  */

  const xtensa_mask_t *mask;	/* Register is a compilation of other regs.  */
  const char *fetch;		/* Instruction sequence to fetch register.  */
  const char *store;		/* Instruction sequence to store register.  */
} xtensa_register_t;

/*  For xtensa-config.c to expand to the structure above.  */
#define XTREG(index,ofs,bsz,sz,al,tnum,flg,cp,ty,gr,name,fet,sto,mas,ct,x,y) \
       {#name, ofs, (xtensa_register_type_t) (ty), \
	((xtensa_register_group_t) \
	 ((gr) | ((xtRegisterGroupNCP >> 2) << (cp + 2)))), \
	 ct, bsz, sz, al, tnum, flg, cp, mas, fet, sto},
#define XTREG_END \
  {0, 0, (xtensa_register_type_t) 0, (xtensa_register_group_t) 0,	\
   0, 0, 0, 0, (unsigned) -1, 0, 0, 0, 0, 0},


#ifdef __cplusplus
}
#endif
#endif /* XTENSA_TDEP_H */
