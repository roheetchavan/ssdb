#ifndef __ssdb__
#define __ssdb__

typedef struct {
    char*   buffer;
    ssize_t buff_len;
    ssize_t input_len;
}InputBuffer;

InputBuffer* get_new_buffer(void);
void read_input(InputBuffer* input_buffer);
void clean_input_buffer(InputBuffer* input_buffer);

void print_db_prompt(void);

#endif /*__ssdb__*/