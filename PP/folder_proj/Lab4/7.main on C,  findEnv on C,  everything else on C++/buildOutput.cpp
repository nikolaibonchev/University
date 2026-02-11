#include <stdio.h>
#include <string.h>



char output_buffer[10240];

void buildOutput(const char *token) {
    if (token == NULL) return;

    if (output_buffer[0] != '\0') {
        strcat(output_buffer, " ");
    }
    strcat(output_buffer, token);
}
