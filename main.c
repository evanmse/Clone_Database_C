#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "buffer.h"
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    InputBuffer* input_buffer = new_input_buffer();
    while(true){
        print_prompt();
        read_input(input_buffer);

        if(strcmp(input_buffer->buffer, ".exit") == 0){
            close_input_buffer(input_buffer);
            exit(EXIT_SUCCESS);
        } else{
        printf("Unrecognized command '%s'.\n", input_buffer->buffer);
        }
    }
    return 0;
}
