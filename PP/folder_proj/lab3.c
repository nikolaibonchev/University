#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
	int i, j;

	for (i = 1; i < argc; i++) {
         for (j = 0; j < argc; j++) {
	  if(argv[i] == envp[j]){
	   printf("\n%s\n", envp[j]);
	  } else {
	   printf("No enviroments found");
	  }
	 }
	}
    

    return 0;
}
