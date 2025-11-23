#line 1 "main.c"
#line 1 "D:\\GitHub\\University\\PP\\folder_proj\\Lab7\\1.All source modules on C\\cuslib.h"
char* findEnv(const char* name, char *envp[]);
char* nextToken(char *str);
void buildOutput(const char *token);
char output_buffer[];

#line 2 "main.c"

char output_buffer[];

int main (int argc, char *argv[], char *envp[]) {
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
