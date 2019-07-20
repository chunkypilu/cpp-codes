#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int read_and_execute(int );
int main() {
	int c=0,x;
	while (1) {
		c++;
		int x=read_and_execute(c);
	}
	return 0;
}

int read_and_execute(int c)
   {
   
   if (c>1)
   goto label;
   
    char cmds[100];
	char paths[10][100]; int num_paths = 0;
	strcpy(paths[num_paths++], "/home/priyank");
	char pathspp[10][100]; int num_pathspp=0;
   
   label:
   
    printf("sh> ");
		fgets(cmds, sizeof(cmds), stdin);
		cmds[strlen(cmds) - 1] = '\0';
		
		char tokens[10][100]; int num_tokens = 0;
		for (int i = 0; i < 10; i++) { tokens[i][0] = '\0'; }
		for (int i = 0, j = 0; i <= strlen(cmds); i++) {
			tokens[num_tokens][j] = cmds[i];
			if (cmds[i] == ' ' || cmds[i] == '\0') {
				tokens[num_tokens][j] = '\0';
				num_tokens++;
				j = 0;
			}
			else {
				j++;
			}
		}
		
		
		
		if (!strcmp(tokens[0], "exit")) {
			exit(1);
			 
		}
		
		
		
		
		
		
		else if (!strcmp(tokens[0], "cd")) {
			struct stat temp;
			if (!lstat(tokens[1], &temp)) {
				chdir(tokens[1]);
			}
			else {
				printf("Directory doesn't exist...\n");
			}
		}
		
		else if (!strcmp(tokens[0], "path")) {
			if (!strcmp(tokens[1], "+")) {
				struct stat temp;
				if (!lstat(tokens[2], &temp)) {
					strcpy(paths[num_paths++], tokens[2]);
				}
				else {
					printf("Directory doesn't exist...\n");
				}
			}
			else if (!strcmp(tokens[1], "-")) {
				for (int i = 0; i < num_paths; i++) {
					if (!strcmp(paths[i], tokens[2])) {
						for (int j = i; j < num_paths - 1; j++) {
							strcpy(paths[j], paths[j+1]);
						}
						paths[--num_paths][0] = '\0';
					}
				}
			}
			else {
				for (int i = 0; i < num_paths; i++) {
					printf("%s:", paths[i]);
				}
				printf("\n");
			}
		}
		
		
		else if(!strcmp(tokens[0],"pushd")){
		        char current_dir[1024];
		        struct stat temp;
		    if (getcwd(current_dir, sizeof(current_dir)) != NULL){
                 //fprintf(stdout, "Current dir: %s\n", current_dir);
		         }
		        
			if (!lstat(tokens[1], &temp)) {
				chdir(tokens[1]);
				strcpy(pathspp[num_pathspp++],current_dir);					
			}
			else {
				printf("Directory doesn't exist...\n");
			}
			
			
		}
		
		
		else if(!strcmp(tokens[0],"popd")){
		        char c[100];
		        strcpy(c,pathspp[--num_pathspp]);
		        chdir(c);
		        pathspp[num_pathspp][0]='\0';
		}
		
		
		
		else if(!strcmp(tokens[0],"dirs")){
		        for(int i=0;i<num_pathspp;i++){
		        printf("%s:",pathspp[i]);
		     
		     }
		     printf("\n");
		}
		
		
		
		else {
			pid_t pid = fork();
			if (pid == 0) {
				int isexec = 0;
				for (int i = 0; i < num_paths; i++) {
					struct stat temp;
					char total_string[150];
					strcpy(total_string, paths[i]);
					strcat(total_string, "/");
					strcat(total_string, tokens[0]);
					if (!lstat(total_string, &temp)) {
						if (!strcmp(tokens[1], "\0")) { execl(total_string, tokens[0], (char*)NULL); }
						else { execl(total_string, tokens[0], tokens[1], (char*)NULL); }
						isexec = 1;
						break;
					}
				}
				if (!isexec) {
					printf("%s: command not found\n", tokens[0]);
				}
			}
			
			else {
				wait(NULL);
			}
		}

   return 1;
   
   }



