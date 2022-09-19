/** @file debug.h
 * Debug utilities
 */

#ifndef clox_debug_h
#define clox_debug_h

#include "chunk.h"

/**
  Disassemble a Chunk and print the pseudo-assembly code
  * @param chunk The Chunk to disassemble
  * @param name The debug name of the Chunk
  */
void disassembleChunk(Chunk *chunk, const char *name);

/**
 * Disassemble a single instruction, print the pseudo-assembly and return the
 * size of the instruction
 * @param chunk The chunk
 * @param offset The offset of the instruction from the start of the code
 * @return The size of the instruction
 */
int disassembleInstruction(Chunk *chunk, int offset);

#endif
