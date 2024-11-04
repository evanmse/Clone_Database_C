#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "buffer.h"
#include "meta_command.h"
#include <stdbool.h>

/*#################################################################
#          ________      __     _   _ __  __  _____ ______        #
#    ____ |  ____\ \    / /\   | \ | |  \/  |/ ____|  ____| .     #
#   / __ \| |__   \ \  / /  \  |  \| | \  / | (___ | |__          #
#  / / _` |  __|   \ \/ / /\ \ | . ` | |\/| |\___ \|  __|         #
# | | (_| | |____   \  / ____ \| |\  | |  | |____) | |____        #
#  \ \__,_|______|   \/_/    \_\_| \_|_|  |_|_____/|______|       #
#   \____/                                                        #                                                  
##################################################################*/

int main(int argc, char const *argv[])
{
    InputBuffer* input_buffer = new_input_buffer();
    while(true){
        print_prompt(); // Function that prints db >
        read_input(input_buffer); // Function that reads input from the user

        if (input_buffer->buffer[0] == '.'){ 
            switch (do_meta_command(input_buffer)){ // Function that handles meta commands
                case (META_COMMAND_SUCCESS):
                   continue;
                case (META_COMMAND_UNRECOGNIZED_COMMAND):
                    printf("Unrecognized command '%s'\n", input_buffer->buffer);
                    continue;
                }
        }

        Statement statement;
        switch (prepare_statement(input_buffer, &statement)){
            case(PREPARE_SUCCESS):
                break;
            case(PREPARE_UNRECOGNIZED_STATEMENT):
                printf("Unrecognized keyword at start of '%s'.\n", input_buffer->buffer);
                continue;
        }
            execute_statement(&statement); // Function that executes the statement
            printf("Executed.\n");
        }
    return 0;
}
