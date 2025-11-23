char* nextToken(char *str) {
    if (str == NULL || *str == '\0') return NULL;

    char *start = str;
    while (*str != '\0' && *str != ';') {
        str++;
    }
    if (*str != '\0') {
        *str = '\0';
        return str + 1;
    }
    return NULL;
}