/** @file chunk.h
  * Defines the opcodes,the chunk structure and the functions that create,
  * free and write to the chunk.
  *
  * It also defines the addConstant function.
  */

#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

/** @enum OpCode
  * Defines the opcodes of the vm.
  */
typedef enum {
    OP_CONSTANT, /**< Is a constant value. */
    OP_ADD, /**< Add two values. */
    OP_SUBTRACT, /**< Subtract two values. */
    OP_MULTIPLY, /**< Multiply two values. */
    OP_DIVIDE, /**< Divide two values. */
    OP_NEGATE, /**< Negate value. */
    OP_RETURN, /**< Is a return. */
} OpCode;

/** @struct Chunk
  * Defines a chunk of the program.
  */
typedef struct {
    int count; /**< The count of elements in the {@link #code } chunk. */
    int capacity; /**< The capacity of the {@link #code } chunk. */
    uint8_t* code; /**< The code chunk, a byte array. */
    int* lines; /**< Stores the source code lines, very ineficient method */
    ValueArray constants; /**< Store costants of the program */
} Chunk;

/**
  * A function that init a empty Chunk with null {@link Chunk#code } and 0 (zero) {@link Chunk#capacity } and {@link Chunk#count}.
  *
  * @param chunk An pointer to the resulting chunk
  * @see Chunk
  */
void initChunk(Chunk* chunk);

/**
  * A function that frees the Chunk
  *
  * @param chunk Te chunk to be freed
  * @see Chunk
  */
void freeChunk(Chunk* chunk);

/**
  * A function that writes a value to {@link Chunk#code}
  *
  * @param chunk The code chunk
  * @param byte The byte to be written in the chunk
  * @param line The line in the source code
  * @see Chunk
  */
void writeChunk(Chunk* chunk, uint8_t byte, int line);

/**
  * A function that add a constant Value to the constant space of the Chunk
  *
  * @param chunk A program chunk
  * @param value A constant Value
  * @return The constant address
  * @see Chunk
  * @see Value
  */
int addConstant(Chunk* chunk, Value value);

#endif
