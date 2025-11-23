char* findEnv(const char* name, char *envp[]) {
    for (int i = 0; envp[i] != NULL; i++) {

        size_t len = strlen(name);
        if (strncmp(envp[i], name, len) == 0 && envp[i][len] == '=') {
            return envp[i] + len + 1;
        }
    }
    return NULL;
}