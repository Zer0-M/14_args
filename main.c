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

char ** parse_args(char* line) {
	char ** ans[5] = calloc(5, sizeof(char*));
	char *s = line;
	int i = 0;
	while (line) {
		ans[i] = strsep(&s, " ");	
	}
	return ans;
}

int main() {

	char ** hm[]parse_args(	

	return 0;
}
