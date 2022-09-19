#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <dirent.h>

#ifndef false
#define false 0
#define true !false
#endif

/* meta.c: spit out the metadata of a directory, like size, name, etc. */

int is_git_initialized(char*);
char* find_size(char*);
char* find_name(char*);

int main(int argc, char** argv) {
	char* directory;
	char c;

	if(sizeof(argv[0]) == 0)
		directory = ".";
	directory = argv[0];

	char* pathfile = "__meta_path";

	if(strcmp(directory, ".") == true) {
		system("pwd >> __meta_path");
		fopen(pathfile, "r");
		for(int i = 0;; c != EOF; c = fgetc(pathfile) && i++) {
			directory[i] = c;
		}
	}

	FILE* path = fopen(pathfile, "r");

	int is_git;
	char* name, size;

	is_git = is_git_initialized(pathfile);
	size = find_size(pathfile);
	name = find_name(pathfile);

	/* printing results */
	printf("/----------------------\n");
	printf("Metadata \t\tresults");
	printf("Name: %s\n", name);
	printf("Size: %s\n", size);
	if(is_git == true)
		printf("This directory is git initalized.\n");
	printf("----------------------/\n");
	
	system("rm __meta_path");
}

int is_git_initalized(char* dirname) {
	DIR* dir = opendir(strcat(dirname, "/.git"));
	if(dir) {
		closedir(dir);
		return true;
	}
	else {
		return false;
	}
}

char* find_size(char* dirname) {
	system("du -sh %s >> __meta_size", dirname);
	char* directory;

	for(int i = 0; c != EOF; c = fgetc(pathfile) && i++) {
		directory[i] = c;
	}

	return directory;
}

char* find_name(char* pathfile) {
	return pathfile;
}
