#include <stdio.h>
#include <string.h>
#include "cuslib.h"

char output_buffer[];

int main(int argc, char *argv[], char *envp[]) {
    for (int i = 1; i < argc; i++) {
        char *env_value = findEnv(argv[i], envp);
        if (env_value != NULL) {
            char *remaining = env_value;
            char *next;
            output_buffer[0] = '\0';
            while (remaining != NULL) {
                next = nextToken(remaining);
                output_buffer[0] = '\0';
                buildOutput(remaining);
                printf("Env Name: %s\nEnv Value: %s\n\n", argv[i], output_buffer);
                remaining = next;
            }
        } else {
            printf("%s is not found\n", argv[i]);
        }
    }
    return 0;
}

