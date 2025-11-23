#line 1 "buildOutput.c"
#line 1 "D:\\GitHub\\University\\PP\\folder_proj\\Lab7\\1.All source modules on C\\cuslib.h"
char* findEnv(const char* name, char *envp[]);
char* nextToken(char *str);
void buildOutput(const char *token);
char output_buffer[];

#line 2 "buildOutput.c"

char output_buffer[10240];

void buildOutput(const char *token) {
    if (token == NULL) return;

    if (output_buffer[0] != '\0') {
        strcat(output_buffer, " ");
    }
    strcat(output_buffer, token);
}
