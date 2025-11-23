extern "C" {
char output_buffer[10240];
char* findEnv(const char* name, char *envp[]);
char* nextToken(char *str);
void buildOutput(const char *token);
}