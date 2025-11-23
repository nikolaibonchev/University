extern "C" {
char* findEnv(const char* name, char *envp[]);
char* nextToken(char *str);
void buildOutput(const char *token);
char output_buffer[];
}