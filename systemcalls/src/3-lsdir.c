#include <stdio.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

void listdir(const char *path){
	DIR *dp;
	struct dirent *dirp;
	char PATH[259] = {0};

	/* open the directory */
	if((dp = opendir(path)) == NULL)
		return;

	while((dirp = readdir(dp)) != NULL){
		/* if the file type is DT_DIR */
		if(dirp->d_type == DT_DIR){
			/* continue if the name is either '.'(current) or '..'(parent) directories */
			if((strcmp(dirp->d_name, ".") == 0) || (strcmp(dirp->d_name, "..") == 0))
				continue;

			/* print file name */
			printf("%s\n", dirp->d_name);
			/* append file name to the current path */
			snprintf(PATH, sizeof(PATH)-1, "%s/%s", path, dirp->d_name);
			/* call this function on the new path for recursive list display */
			listdir(PATH);
		} else {
			/* print file name if its not directory type */
			printf("%s\n", dirp->d_name);
		}
	}
	closedir(dp);
}


int main(int argc, char *argv[]){
	// DIR *dp;
	// struct dirent *dirp;

	/* atleast two arguments needed */
	if(argc != 2){
		printf("please provide the directory to list\n");
		exit(1);
	}

	listdir(argv[1]);

	exit(0);
}
