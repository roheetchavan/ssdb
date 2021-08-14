#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ssdb.h"

int main(int argc, char** argv)
{
    //ReadExecutePrintLoop
    InputBuffer* input_buffer =
        get_new_buffer();

    while(1)
    {
		print_db_prompt();
        read_input(input_buffer);

        if(strcmp(input_buffer->buffer, ".exit") == 0)
        {
            clean_input_buffer(input_buffer);
            printf("Closing db...\n");
            exit(EXIT_SUCCESS);
        }
        else
        {
            printf("Unrecognized command '%s'\n", input_buffer->buffer);
        }
    }
    return 0;
}