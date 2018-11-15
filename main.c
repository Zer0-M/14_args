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

	printf("testing on \"ls -l\"\n");
	char arg[50] = "ls -l";
	char ** hm = parse_arg(arg); 
	int i = 2;
	while (i) {
		printf("%d: %s \n", 2-i, hm[2-i]);
		i--;
	}
	free(hm);

	printf("\n");

	printf("testing on \"fortune | cowsay | lolcat\"\n");
	char arg2[50] = "fortune | cowsay | lolcat";
	char ** hm2 = parse_arg(arg2); 
	i = 5;
	while (i) {
		printf("%d: %s \n", 5-i, hm2[5-i]);
		i--;
	}
	free(hm2);
	return 0;
}
