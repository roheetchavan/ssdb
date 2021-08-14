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

		//check if it's db command
        if(input_buffer->buffer[0] == '.')
        {
            switch(do_meta_command(input_buffer))
			{
				case META_COMMAND_SUCCESS:
					continue;
				case META_COMMAND_UNRECOGNZED:
					printf("Unrecognized command '%s'\n", input_buffer->buffer);
					continue;
			}
        }

		Statement statement;
		switch(prepare_statement(input_buffer, &statement))
		{
			case PREPARE_SUCCESS:
				break;
			case PREPARE_UNRECOGNIZED_STATEMENT:
				printf("Unrecognized keyword at start of '%s'.\n", input_buffer->buffer);
				continue;
		}

		execute_statement(&statement);
		printf("Executed\n");
    }
    return 0;
}