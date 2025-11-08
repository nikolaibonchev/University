char* findEnv(const char* name, char *envp[]);

extern "C" {
char output_buffer[10240];
char* nextToken(char *str);
void buildOutput(const char *token);
}