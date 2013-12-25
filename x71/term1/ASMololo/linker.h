/*
Eugene Auduchinok (c) 2013
ASMololo interpret
*/

#ifndef _LINKER_H_
#define _LINKER_H_

#include "instruction.h"
#include "hash.h"

Instruction *link(Instruction *program, int size, Hash_Table *labels);

#endif