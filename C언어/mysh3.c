/*32131696 Kim jaeHyun*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
struct COMMAND { 
	char* title;
	char* story;
	bool(*func)(int argc, char* argv[]); 
};
bool cmd_cd(int argc, char* argv[]);         
bool cmd_exit(int argc, char* argv[]);        
bool cmd_help(int argc, char* argv[]);       

struct COMMAND help[] =
{
	{ "cd",    "change directory",                    cmd_cd },
	{ "exit",   "exit this shell",                        cmd_exit },
	{ "quit",   "quit this shell",                        cmd_exit },
	{ "help",  "show this help",                      cmd_help },
	{ "?",      "show this help",                      cmd_help }
};
bool cmd_cd(int argc, char* argv[]) { 
	if (argc == 1)
		chdir(getenv("HOME"));
	else if (argc == 2) {
		if (chdir(argv[1]))
			printf("No directory\n");
	}
	else
		printf("USAGE: cd [dir]\n");
}
bool cmd_exit(int argc, char* argv[]) {
	return false;
}
bool cmd_help(int argc, char* argv[]) { 
	int i;
	for (i = 0; i < sizeof(help) / sizeof(struct COMMAND); i++)
	{
		if (argc == 1 || strcmp(help[i].title, argv[1]) == 0)
			printf("%-10s: %s\n", help[i].title, help[i].story);
	}
}

int tokenize(char*buf, char*delims, char*tokens[],int maxTokens){
    int token_count=0; char *token;
	token=strtok(buf,delims);
	while(token!=NULL&&token_count<maxTokens){
		tokens[token_count] = token;
		token = strtok(NULL, delims);
		token_count++;
    }
	tokens[token_count] = (char*)0;
	return token_count;
}

bool run(char*line){
      
	  int token_count=0; 
	  char*tokens[100];
      char delims[10]=" ";  
	  int fd[2]; int fdr; 
	  char *a[50];
	  char *b[50];
	  char *c = NULL;
	  char *d = NULL;
	  int i = 0;  
	  line[strlen(line) - 1] = '\0';
	 
	  if (strchr(line, '|') != NULL) {
		  c = strtok(line, "|");
		  d = strtok(NULL, "|");

		  strcat(c, "\0");
		  strcat(d, "\0");
		  
		  tokenize(c, delims, a, sizeof(a) / sizeof(char*));
		  tokenize(d, delims, b, sizeof(b) / sizeof(char*));

		  if (pipe(fd) == -1) {
			  printf("fail to call pipe()\n");
			  exit(1);
		  }
		  switch (fork())
		  {
		  case -1: perror("fork error"); break;
		  case 0:
			  if (close(1) == -1) perror("close1");
			  if (dup(fd[1]) != 0);
			  if (close(fd[0]) == -1 || close(fd[1]) == -1) {
				  perror("close2");
			  }
			  execvp(a[0], a);
			  printf("command not found \n");
			  exit(0);
		  }
		  switch (fork())
		  {
		  case -1: perror("fork"); break;
		  case 0:
			  if (close(0) == -1) perror("close3");
			  if (dup(fd[0]) != 0);
			  if (close(fd[0]) == -1 || close(fd[1]) == -1) perror("close4");
			  execvp(b[0], b);
			  printf("command not found \n");
			  exit(0);
		  }

		  if (close(fd[0]) == -1 || close(fd[1]) == -1) perror("close5");
		  while (wait(NULL) != -1);
	  }
	  else if (strchr(line, '>') != NULL) {
		  c = strtok(line , ">");
		  d = strtok(NULL, ">");
		  i = 0;
		  tokenize(c, delims, a, sizeof(a) / sizeof(char*));
		  tokenize(d, delims, b, sizeof(b) / sizeof(char*));
		  switch (fork())
		  {
		  case -1: perror("fork"); break;
		  case 0:
			  fdr = open(b[0], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			  if (fdr == -1) {
				  perror("颇老 货肺积己 坷幅"); exit(1);
			  }
			  if (dup2(fdr, 1) == -1) {
				  perror("fdr dup error");
			  }
			  close(fdr);
			  execvp(a[0], a);
			  printf("command not found \n");
			  exit(0);
			  break;
		  default: wait(NULL);
		  }
	  }
	  else if (strchr(line, '<') != NULL) {
		  c = strtok(line, "<");
		  d = strtok(NULL, "<");
		 
		  tokenize(c, delims, a, sizeof(a) / sizeof(char*));
		  tokenize(d, delims, b, sizeof(b) / sizeof(char*));
		  
		  switch (fork())
		  {
		  case -1: perror("fork"); break;
		  case 0:
			  fdr = open(a[0], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			  if (fdr == -1) {
				  perror("颇老 货肺积己 坷幅"); exit(1);
			  }
			  if (dup2(fdr, 1) == -1) {
				  perror("fdr dup error");
			  }
			  close(fdr);
			  execvp(b[0], b);
			  printf("command not found \n");
			  exit(0);
			  break;
		  default: wait(NULL);
		  }
	  }
	  else {
		  token_count = tokenize(line, delims, tokens, sizeof(tokens) / sizeof(char*));
		  if (token_count == 0) return true;
		  for (i = 0; i < sizeof(help) / sizeof(struct COMMAND); i++) {
			  if (strcmp(help[i].title, tokens[0]) == 0)
				  return help[i].func(token_count, tokens);
		  }
		  if (tokens[0] != NULL) {
			  if (fork() == 0) {
				  execvp(tokens[0], tokens);
				  printf("command not found\n");
				  exit(0);
			  }
			  wait(NULL);
		  }
	  }
	  return 1;
}

int main(){
   char line[1024];

   while(1){
           printf("%s $",get_current_dir_name());
           fgets(line,sizeof(line)-1,stdin);
           if(run(line)==0)break;
           }
}
