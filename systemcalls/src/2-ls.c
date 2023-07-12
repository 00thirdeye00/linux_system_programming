#include <stdio.h> // standard input and output
#include <dirent.h> // directory operations
#include <string.h> // string operations here for strerror function
#include <errno.h> // error number
#include <stdlib.h> // for exit

int main(int argc, char *argv[]){
	/* opaque data type representing directory stream  */
	DIR *dp;

	/* dirent is a structure which contains information about a file such 
	 * as file name, inode, offset etc  */
	struct dirent *dirp;

	if(argc != 2){
		printf("please provide the directory to list out\n");
		exit(1);
	}

	if((dp = opendir(argv[1])) == NULL){
		printf("cannot open directory=%s\n", strerror(errno));
	}

	while((dirp = readdir(dp)) != NULL)
		printf("%s\n", dirp->d_name);

	closedir(dp);
	exit(0);
}
