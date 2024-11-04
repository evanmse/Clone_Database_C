#include "buffer.h"
#include <stddef.h>
#include <sys/types.h>
#include <stdio.h>

#ifndef __include_meta_command_h__
#define __include_meta_command_h__

typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

typedef enum {
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNIZED_STATEMENT
} PrepareResult;

typedef enum {
    STATEMENT_INSERT,
    STATEMENT_SELECT
} StatementType;

typedef struct {
    StatementType type;
} Statement;


void execute_statement(Statement* statement);

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);

MetaCommandResult do_meta_command(InputBuffer* input_buffer);

#endif /* #ifndef __include_meta_command_h__*/