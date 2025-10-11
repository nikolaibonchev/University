#include <stdio.h>
#include <string.h>


int main(int argc, char *argv[], char *envp[]) {
	int i,found;

	char buffer[512], argCopy[512];
	char *name, *value, *context, *token;
	
	if(argv[1] == NULL){
	 printf("Please do mind that for this program to work you'll need command-line arguments\n");
	};

	strcpy(argCopy, argv[1]);
	token = strtok(argv[1], ",");	

	while(token != NULL){
	 found = 0;
	
	 for (i = 0; envp[i] != NULL; i++) {
	  strcpy(buffer, envp[i]);
	  name = strtok_s(buffer, "=", &context);
	  value = strtok_s(NULL, "", &context);

	  if(strcmp(token, name) == 0){
	   printf("ENV Name: %s\nENV Value: %s\n\n", name, value);
	   found = 1;
	   break;
	  };
    	 };

	if(!found){
	 printf("Environment variable '%s' not found.\n\n", token);
	}
	 
	 token = strtok(NULL, ",");
	};

    return 0;
};