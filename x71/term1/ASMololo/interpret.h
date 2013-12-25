/*
Eugene Auduchinok (c) 2013
ASMololo interpret
*/

#ifndef _INTERPRET_H_
#define _INTERPRET_H_

#include "instruction.h"

#define DEFAULT_MEM_SIZE 262144

int run(Instruction *instr);

#endif