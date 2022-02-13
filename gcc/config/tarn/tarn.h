/* Target Definitions for tarn.
   Copyright (C) 2008-2021 Free Software Foundation, Inc.
   Contributed by Anthony Green.

   This file is part of GCC.

   GCC is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 3, or (at your
   option) any later version.

   GCC is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with GCC; see the file COPYING3.  If not see
   <http://www.gnu.org/licenses/>.  */

#ifndef GCC_TARN_H
#define GCC_TARN_H

#undef  STARTFILE_SPEC
#define STARTFILE_SPEC "%{!mno-crt0:crt0%O%s} crti.o%s crtbegin.o%s"

/* Provide an ENDFILE_SPEC appropriate for svr4.  Here we tack on our own
   magical crtend.o file (see crtstuff.c) which provides part of the
   support for getting C++ file-scope static object constructed before
   entering `main', followed by the normal svr3/svr4 "finalizer" file,
   which is either `gcrtn.o' or `crtn.o'.  */

#undef  ENDFILE_SPEC
#define ENDFILE_SPEC "crtend.o%s crtn.o%s"

/* Provide a LIB_SPEC appropriate for svr4.  Here we tack on the default
   standard C library (unless we are building a shared library) and
   the simulator BSP code.  */

#undef LIB_SPEC
#define LIB_SPEC "%{!shared:%{!symbolic:-lc}}"

#undef  LINK_SPEC
#define LINK_SPEC "%{h*} %{v:-V} %{!mel:-EB} %{mel:-EL}\
		   %{static:-Bstatic} %{shared:-shared} %{symbolic:-Bsymbolic}"

#ifndef MULTILIB_DEFAULTS
#define MULTILIB_DEFAULTS { "meb" }
#endif

/* Layout of Source Language Data Types */

#define INT_TYPE_SIZE 16
#define SHORT_TYPE_SIZE 16
#define LONG_TYPE_SIZE 32
#define LONG_LONG_TYPE_SIZE 32

#define FLOAT_TYPE_SIZE 32
#define DOUBLE_TYPE_SIZE 64
#define LONG_DOUBLE_TYPE_SIZE 64

#define DEFAULT_SIGNED_CHAR 0

#undef  SIZE_TYPE
#define SIZE_TYPE "unsigned int"

#undef  PTRDIFF_TYPE
#define PTRDIFF_TYPE "int"

#undef  WCHAR_TYPE
#define WCHAR_TYPE "unsigned int"

#undef  WCHAR_TYPE_SIZE
#define WCHAR_TYPE_SIZE BITS_PER_WORD

/* Registers...

   $fp  - frame pointer
   $sp  - stack pointer
   $r0  - general purpose 32-bit register.
   $r1  - general purpose 32-bit register.
   $r2  - general purpose 32-bit register.
   $r3  - general purpose 32-bit register.
   $r4  - general purpose 32-bit register.
   $r5  - general purpose 32-bit register.
   $r6  - general purpose 32-bit register.
   $r7  - general purpose 32-bit register.
   $r8  - general purpose 32-bit register.
   $r9  - general purpose 32-bit register.
   $r10 - general purpose 32-bit register.
   $r11 - general purpose 32-bit register.
   $r12 - general purpose 32-bit register.
   $r13 - reserved for execution environment.

   Special Registers...

   $pc - 32-bit program counter.

*/

#define REGISTER_NAMES { \
    "r",      \
    "adh",    \
    "adl",    \
    "alua",   \
    "alub",   \
    "aluc",   \
    "alusel", \
    "bs",     \
    "il",     \
    "inth",   \
    "intl",   \
    "jmph",   \
    "jmpl",   \
    "mem",    \
    "nop",    \
    "one",    \
    "p0",     \
    "pic",    \
    "reti",   \
    "stack",  \
    "zero",   \
    "?sp",    \
    "?qfp",   \
    "?fp",    \
    "?arg",   \
    "?cum"    \
    }

#define TARN_R       0 // General purpose
#define TARN_ADH     1 // The rest, not. v
#define TARN_ADL     2
#define TARN_ALUA    3
#define TARN_ALUB    4
#define TARN_ALUC    5
#define TARN_ALUSEL  6
#define TARN_BS      7
#define TARN_IL      8
#define TARN_INTH    9
#define TARN_INTL    10
#define TARN_JMPH    11
#define TARN_JMPL    12
#define TARN_MEM     13
#define TARN_NOP     14
#define TARN_ONE     15
#define TARN_P0      16
#define TARN_PIC     17
#define TARN_RETI    18
#define TARN_STACK   19
#define TARN_ZERO    20 // Last real register
#define TARN__SP     21 // fake stack pointer
#define TARN__QFP    22 // fake frame pointer
#define TARN__FP     23 // fake frame pointer
#define TARN__ARG    24 // fake arg pointer
#define TARN__CUM    25 // fake cumulative thing

// #define TARN_FP     0
// #define TARN_SP     1
// #define TARN_R0     2
// #define TARN_R1     3
// #define TARN_R2     4
// #define TARN_R3     5
// #define TARN_R4     6
// #define TARN_R5     7
// #define TARN_R6     8
// #define TARN_R7     9
// #define TARN_R8     10
// #define TARN_R9     11
// #define TARN_R10    12
// #define TARN_R11    13
// #define TARN_R12    14
// #define TARN_R13    15
// #define TARN_QFP    16
// #define TARN_QAP    17
// #define TARN_PC     18
// #define TARN_CC     19

#define FIRST_PSEUDO_REGISTER 26

enum reg_class
{
  NO_REGS,
  GENERAL_REGS,
  SPECIAL_REGS,
  // CC_REGS,
  ALL_REGS,
  LIM_REG_CLASSES
};

//0123456789012345678901234567
//1111111111111111111111111111

#define TARN_ALL_REGS 0x07ffffff
#define TARN_GENERAL_REG_BITS ((1<<TARN_R)|(1<<TARN__SP)|(1<<TARN__FP)|(1<<TARN__ARG))
#define TARN_SPECIAL_REG_BITS (TARN_ALL_REGS & ~TARN_GENERAL_REG_BITS)


#define REG_CLASS_CONTENTS                      \
    { { 0x00000000                      }, /* Empty */             \
            { TARN_GENERAL_REG_BITS     }, /* $fp, $sp, $r0 to $r13, ?fp */ \
            { TARN_SPECIAL_REG_BITS     }, /* $pc */ \
            { TARN_ALL_REGS             }  /* All registers */ \
}
//  { 0x00000000 }, /* ?cc */

#define N_REG_CLASSES LIM_REG_CLASSES

#define REG_CLASS_NAMES {\
    "NO_REGS", \
    "GENERAL_REGS", \
    "SPECIAL_REGS", \
    "ALL_REGS" }

#define FIXED_REGISTERS     { 0, 1, 1, 1, \
			      1, 1, 1, 1, \
			      1, 1, 1, 1, \
			      1, 1, 1, 1, \
			      1, 1, 1, 1, \
			      1, 1, 1, 1, \
            1, 1 }

#define CALL_REALLY_USED_REGISTERS { 0, 1, 1, 1, \
                                     1, 1, 1, 1, \
                                     1, 1, 1, 1, \
                                     1, 1, 1, 1, \
   			             1, 1, 1, 1, \
   			             1, 1, 1, 1, \
            1, 1 }

/* We can't copy to or from our CC register. */
#define AVOID_CCMODE_COPIES 1

/* A C expression whose value is a register class containing hard
   register REGNO.  */
#define REGNO_REG_CLASS(R) ((R == TARN_R) ? GENERAL_REGS : SPECIAL_REGS)

/* The Overall Framework of an Assembler File */

#undef  ASM_SPEC
#define ASM_SPEC "%{!mel:-EB} %{mel:-EL}"
#define ASM_COMMENT_START "#"
#define ASM_APP_ON ""
#define ASM_APP_OFF ""

#define FILE_ASM_OP     "\t.file\n"

/* Switch to the text or data segment.  */
#define TEXT_SECTION_ASM_OP  "\t.text"
#define DATA_SECTION_ASM_OP  "\t.data"

/* Assembler Commands for Alignment */

#define ASM_OUTPUT_ALIGN(STREAM,POWER) \
	fprintf (STREAM, "\t.p2align\t%d\n", POWER);

/* Output and Generation of Labels */

#define GLOBAL_ASM_OP "\t.global\t"

/* Passing Arguments in Registers */

/* A C type for declaring a variable that is used as the first
   argument of `FUNCTION_ARG' and other related values.  */
#define CUMULATIVE_ARGS unsigned int

/* If defined, the maximum amount of space required for outgoing arguments
   will be computed and placed into the variable
   `current_function_outgoing_args_size'.  No space will be pushed
   onto the stack for each call; instead, the function prologue should
   increase the stack frame size by this amount.  */
#define ACCUMULATE_OUTGOING_ARGS 1

/* A C statement (sans semicolon) for initializing the variable CUM
   for the state at the beginning of the argument list.
   For tarn, the first arg is passed in register 2 (aka $r0).  */
#define INIT_CUMULATIVE_ARGS(CUM,FNTYPE,LIBNAME,FNDECL,N_NAMED_ARGS) \
  (CUM = TARN__CUM)

/* How Scalar Function Values Are Returned */

/* STACK AND CALLING */

#define PUSH_ROUNDING(BYTES) (BYTES)

/* Define this macro if pushing a word onto the stack moves the stack
   pointer to a smaller address.  */
#define STACK_GROWS_DOWNWARD 1

/* Define this if the above stack space is to be considered part of the
   space allocated by the caller.  */
#define OUTGOING_REG_PARM_STACK_SPACE(FNTYPE) 1
#define STACK_PARMS_IN_REG_PARM_AREA

/* Define this if it is the responsibility of the caller to allocate
   the area reserved for arguments passed in registers.  */
#define REG_PARM_STACK_SPACE(FNDECL) (6 * UNITS_PER_WORD)

/* Offset from the argument pointer register to the first argument's
   address.  On some machines it may depend on the data type of the
   function.  */
#define FIRST_PARM_OFFSET(F) 12

/* Define this macro to nonzero value if the addresses of local variable slots
   are at negative offsets from the frame pointer.  */
#define FRAME_GROWS_DOWNWARD 1

/* Define this macro as a C expression that is nonzero for registers that are
   used by the epilogue or the return pattern.  The stack and frame
   pointer registers are already assumed to be used as needed.  */
#define EPILOGUE_USES(R) 0

/* A C expression whose value is RTL representing the location of the
   incoming return address at the beginning of any function, before
   the prologue.  */
#define INCOMING_RETURN_ADDR_RTX					\
  gen_frame_mem (Pmode,							\
		 plus_constant (Pmode, stack_pointer_rtx, UNITS_PER_WORD))

/* Describe how we implement __builtin_eh_return.  */
#define EH_RETURN_DATA_REGNO(N)	((N) < 4 ? (N+2) : INVALID_REGNUM)

/* Store the return handler into the call frame.  */
#define EH_RETURN_HANDLER_RTX						\
  gen_frame_mem (Pmode,							\
		 plus_constant (Pmode, frame_pointer_rtx, UNITS_PER_WORD))

/* Storage Layout */

#define BITS_BIG_ENDIAN 0
#define BYTES_BIG_ENDIAN 1
#define WORDS_BIG_ENDIAN 1

/* Alignment required for a function entry point, in bits.  */
#define FUNCTION_BOUNDARY 16

/* Define this macro as a C expression which is nonzero if accessing
   less than a word of memory (i.e. a `char' or a `short') is no
   faster than accessing a word of memory.  */
#define SLOW_BYTE_ACCESS 0

/* Number of storage units in a word; normally the size of a
   general-purpose register, a power of two from 1 or 8.  */
#define UNITS_PER_WORD 1

/* Define this macro to the minimum alignment enforced by hardware
   for the stack pointer on this machine.  The definition is a C
   expression for the desired alignment (measured in bits).  */
#define STACK_BOUNDARY 32

/* Normal alignment required for function parameters on the stack, in
   bits.  All stack parameters receive at least this much alignment
   regardless of data type.  */
#define PARM_BOUNDARY 32

/* Alignment of field after `int : 0' in a structure.  */
#define EMPTY_FIELD_BOUNDARY  32

/* No data type wants to be aligned rounder than this.  */
#define BIGGEST_ALIGNMENT 32

/* The best alignment to use in cases where we have a choice.  */
#define FASTEST_ALIGNMENT 32

/* Every structures size must be a multiple of 8 bits.  */
#define STRUCTURE_SIZE_BOUNDARY 8

/* Look at the fundamental type that is used for a bit-field and use
   that to impose alignment on the enclosing structure.
   struct s {int a:8}; should have same alignment as "int", not "char".  */
#define	PCC_BITFIELD_TYPE_MATTERS	1

/* Largest integer machine mode for structures.  If undefined, the default
   is GET_MODE_SIZE(DImode).  */
#define MAX_FIXED_MODE_SIZE 32

/* Make arrays of chars word-aligned for the same reasons.  */
#define DATA_ALIGNMENT(TYPE, ALIGN)		\
  (TREE_CODE (TYPE) == ARRAY_TYPE		\
   && TYPE_MODE (TREE_TYPE (TYPE)) == QImode	\
   && (ALIGN) < FASTEST_ALIGNMENT ? FASTEST_ALIGNMENT : (ALIGN))

/* Set this nonzero if move instructions will actually fail to work
   when given unaligned data.  */
#define STRICT_ALIGNMENT 1

/* Generating Code for Profiling */
#define FUNCTION_PROFILER(FILE,LABELNO) (abort (), 0)

/* Trampolines for Nested Functions.  */
#define TRAMPOLINE_SIZE (2 + 6 + 4 + 2 + 6)

/* Alignment required for trampolines, in bits.  */
#define TRAMPOLINE_ALIGNMENT 32

/* An alias for the machine mode for pointers.  */
#define Pmode         SImode

/* An alias for the machine mode used for memory references to
   functions being called, in `call' RTL expressions.  */
#define FUNCTION_MODE QImode

/* The register number of the stack pointer register, which must also
   be a fixed register according to `FIXED_REGISTERS'.  */
#define STACK_POINTER_REGNUM TARN__SP

/* The register number of the frame pointer register, which is used to
   access automatic variables in the stack frame.  */
#define FRAME_POINTER_REGNUM TARN__QFP

/* The register number of the arg pointer register, which is used to
   access the function's argument list.  */
#define ARG_POINTER_REGNUM TARN__ARG

// #define HARD_FRAME_POINTER_REGNUM TARN__FP

#define ELIMINABLE_REGS							\
{{ FRAME_POINTER_REGNUM, HARD_FRAME_POINTER_REGNUM },			\
 { ARG_POINTER_REGNUM,   HARD_FRAME_POINTER_REGNUM }}

/* This macro returns the initial difference between the specified pair
   of registers.  */
#define INITIAL_ELIMINATION_OFFSET(FROM, TO, OFFSET) 2

/* A C expression that is nonzero if REGNO is the number of a hard
   register in which function arguments are sometimes passed.  */
#define FUNCTION_ARG_REGNO_P(r) (r == TARN__ARG || r == TARN__CUM)

/* A macro whose definition is the name of the class to which a valid
   base register must belong.  A base register is one used in an
   address which is the register value plus a displacement.  */
#define BASE_REG_CLASS GENERAL_REGS

#define INDEX_REG_CLASS NO_REGS

#define HARD_REGNO_OK_FOR_BASE_P(NUM) \
  ((unsigned) (NUM) < FIRST_PSEUDO_REGISTER \
   && (REGNO_REG_CLASS(NUM) == GENERAL_REGS \
       || (NUM) == HARD_FRAME_POINTER_REGNUM))

/* A C expression which is nonzero if register number NUM is suitable
   for use as a base register in operand addresses.  */
#ifdef REG_OK_STRICT
#define REGNO_OK_FOR_BASE_P(NUM)		 \
  (HARD_REGNO_OK_FOR_BASE_P(NUM) 		 \
   || HARD_REGNO_OK_FOR_BASE_P(reg_renumber[(NUM)]))
#else
#define REGNO_OK_FOR_BASE_P(NUM)		 \
  ((NUM) >= FIRST_PSEUDO_REGISTER || HARD_REGNO_OK_FOR_BASE_P(NUM))
#endif

/* A C expression which is nonzero if register number NUM is suitable
   for use as an index register in operand addresses.  */
// this macro bad in moxie?
#define REGNO_OK_FOR_INDEX_P(NUM) (NUM == TARN__FP)

/* The maximum number of bytes that a single instruction can move
   quickly between memory and registers or between two memory
   locations.  */
#define MOVE_MAX 1

/* All load operations zero extend.  */
#define LOAD_EXTEND_OP(MEM) ZERO_EXTEND

/* A number, the maximum number of registers that can appear in a
   valid memory address.  */
#define MAX_REGS_PER_ADDRESS 1

/* An alias for a machine mode name.  This is the machine mode that
   elements of a jump-table should have.  */
#define CASE_VECTOR_MODE QImode

/* Run-time Target Specification */

#define TARGET_CPU_CPP_BUILTINS() \
  { \
    builtin_define_std ("tarn");			\
    builtin_define_std ("TARN");			\
    if (TARGET_LITTLE_ENDIAN)				\
      builtin_define ("__TARN_LITTLE_ENDIAN__");	\
    else						\
      builtin_define ("__TARN_BIG_ENDIAN__");		\
  }

#define HAS_LONG_UNCOND_BRANCH true

// static memory locations
#define TARN_MEM_RETVAL_LOC  0x7f00


#endif /* GCC_TARN_H */
