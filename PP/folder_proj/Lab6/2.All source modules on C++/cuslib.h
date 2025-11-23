extern "C" char* findEnv(const char* name, char *envp[]);
extern "C" char* nextToken(char *str);
extern "C" void buildOutput(const char *token);
extern "C" char output_buffer[];