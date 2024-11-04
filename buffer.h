#include <stddef.h>
#include <sys/types.h>
#include <stdio.h>

#ifndef __include_buffer_h__
#define __include_buffer_h__

typedef struct {
    char* buffer;
    size_t buffer_length; // size_t is an unsigned integer type that is the result of the sizeof keyword
    ssize_t input_length; // ssize_t is a signed integer type that is the result of the sizeof keyword
} InputBuffer;

InputBuffer *new_input_buffer();

void read_input(InputBuffer* input_buffer);

void print_prompt();

ssize_t getline(char** lineptr, size_t* n, FILE* stream);

void close_input_buffer(InputBuffer* input_buffer);

#endif /* #ifndef __include_buffer_h__*/