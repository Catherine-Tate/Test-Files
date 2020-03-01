#include <fcntl.h>           /* Definition of AT_* constants */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>


int main() {
	
	if(access("fake.txt", F_OK) != -1) {
		printf("ACCESSED!");
	}
	
	return(0);
}
