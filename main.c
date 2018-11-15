#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include "parse.h"

char ** parse_arg(char* line) {
	char ** ans = calloc(5, sizeof(char*));
	char *s = strsep(&line, " ");
	int i = 0;
	while (s) {
		ans[i] = s;	
		/*printf("%d : %s", i, ans[i]);*/
		s = strsep(&line, " ");
		i++;
	}
	return ans;
}

int main() {
	printf("testing parsing on \"fortune | cowsay | lolcat\"\n");
	char arg0[50] = "fortune | cowsay | lolcat";
	char ** hm0 = parse_arg(arg0); 
	int i = 5;
	while (i) {
		printf("%d: %s \n", 5-i, hm0[5-i]);
		i--;
	}
	free(hm0);

	printf("testing prsing and executing with \"ls -l\"\n");
	char arg1[50] = "ls -a -l";
	char ** hm1 = parse_arg(arg1); 
	i = 3;
	while (i) {
		printf("%d: %s \n", 3-i, hm1[3-i]);
		i--;
	}
	execvp(hm1[0],hm1);
	free(hm1);
	printf("\n");


	return 0;
}
