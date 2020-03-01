#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	
	struct stat buffer;
	int rc = lstat("/bin/ls", &buffer);
	printf("rc: %d\n", rc);
	
	return(EXIT_SUCCESS);
}

