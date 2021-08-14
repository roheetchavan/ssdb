#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "ssdb.h"

InputBuffer*
get_new_buffer(void)
{
    InputBuffer* new_buff =
        (InputBuffer*)malloc(sizeof(InputBuffer));
    if(!new_buff)
    {
        printf("Input buffer allocation failed\n");
        exit(EXIT_FAILURE);
    }

    new_buff->buffer = NULL;
    new_buff->input_len = 0;
    new_buff->buff_len = 0;

    return new_buff;
}
void
read_input(InputBuffer* input_buffer)
{
    ssize_t bytes_read = getline(&(input_buffer->buffer),
                                 &(input_buffer->buff_len),
                                 stdin);
    if(bytes_read <= 0)
    {
        printf("Error reading input\n");
        exit(EXIT_FAILURE);
    }

    // trim trailing new line character
    input_buffer->input_len = bytes_read - 1;
    input_buffer->buffer[bytes_read - 1] = 0;
}

void
clean_input_buffer(InputBuffer* input_buffer)
{
    free(input_buffer->buffer);
    free(input_buffer);
}

void
print_db_prompt(void)
{
    printf("db> ");
}