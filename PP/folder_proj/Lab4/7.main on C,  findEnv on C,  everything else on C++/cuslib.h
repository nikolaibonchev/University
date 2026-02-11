
extern "C" {

char* nextToken(char *str);
void buildOutput(const char *token);
extern char output_buffer[];
}

char* findEnv(const char* name, char *envp[]);