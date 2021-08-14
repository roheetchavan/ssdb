#ifndef __ssdb__
#define __ssdb__

typedef enum {
	META_COMMAND_SUCCESS,
	META_COMMAND_UNRECOGNZED
}MetaCommandResult;

typedef enum {
	PREPARE_SUCCESS,
	PREPARE_UNRECOGNIZED_STATEMENT
}PrepareResult;

typedef enum {
	STATEMENT_INSERT,
	STATEMENT_SELECT
}StatementType;

typedef struct {
    char*   buffer;
    ssize_t buff_len;
    ssize_t input_len;
}InputBuffer;

typedef struct {
	StatementType type;
}Statement;

InputBuffer* get_new_buffer(void);
void read_input(InputBuffer* input_buffer);
void clean_input_buffer(InputBuffer* input_buffer);

MetaCommandResult do_meta_command(InputBuffer* input_buffer);
PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);
void execute_statement(Statement* statement);

void print_db_prompt(void);

#endif /*__ssdb__*/