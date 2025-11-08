#ifdef __cplusplus
extern "C" {
#endif

char* findEnv(const char* name, char *envp[]);

#ifdef __cplusplus
}
#endif

char* nextToken(char *str);
void buildOutput(const char *token);
extern char output_buffer[];