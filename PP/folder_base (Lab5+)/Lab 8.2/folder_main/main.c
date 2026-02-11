#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "strudata.h"
#include "buildoutput.h"
#include "../folder_xlib/findenv.h"

typedef char* (*NextTokenFunc)(char*);

int main(int argc, char *argv[], char *envp[]) {

    HINSTANCE hDll;
    NextTokenFunc myNextToken;
    hDll = LoadLibrary("nextToken.dll");

    if (hDll == NULL) {
        printf("Error: Could not load nextToken.dll.\n");
        return 1;
    }

    myNextToken = (NextTokenFunc)GetProcAddress(hDll, "nextToken");

    if (myNextToken == NULL) {
        printf("Error: Could not find function 'nextToken' in the DLL.\n");
        FreeLibrary(hDll);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        char *env_value = findEnv(argv[i], envp);
        if (env_value != NULL) {
            char *remaining = env_value;
            char *next;
            output_buffer[0] = '\0';
            while (remaining != NULL) {
                next = myNextToken(remaining);
                output_buffer[0] = '\0';
                buildOutput(remaining);
                printf("Env Name: %s\nEnv Value: %s\n\n", argv[i], output_buffer);
                remaining = next;
            }
        } else {
            printf("%s is not found\n", argv[i]);
        }
    }

    FreeLibrary(hDll);
    return 0;
}
