#ifdef __cplusplus
extern "C" {
#endif

extern char output_buffer[10240];  // <- extern only

char* findEnv(const char* name, char *envp[]);
char* nextToken(char *str);
void buildOutput(const char *token);

#ifdef __cplusplus
}
#endif