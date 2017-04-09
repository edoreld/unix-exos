/*
	Program that opens a directory specified by parameter, then creates a second directory inside that one, then goes one by one through 
	the entries of the directory, printing the name out to standard output. If it's the second entry, then it will go back to the first 
	and start going through the entries again (this is to showcase the use of seekdir/telldir). Finally, the program closes the directory that
	we opened at the beginning. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define SYS_ERR -1
#define MYDIR "./exo3dir"

int t_mkdir(path, mode) {
	if (mkdir(path,mode) == SYS_ERR) {
		perror("mkdir");
		exit(SYS_ERR);
	}
}

DIR * t_opendir(dirname) char * dirname;
{ 
	DIR * dir;
	
	if((dir = opendir(dirname)) == NULL)
	{
		perror("opendir"); 
		exit(SYS_ERR);
	}
	return dir; 
}

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2)+1);
    if (result == NULL) {
    	perror("malloc");
    	exit(SYS_ERR);
    }

    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

int main (int c, char *v[]) {
        struct dirent *pDirent;
        DIR *pDir;

        if (c < 2) {
            printf ("Usage: %s <dirname>\n",v[0]);
            return 1;
        }

        pDir = t_opendir (v[1]);

        char *dirToCreate = "test";
        
        char *auxPath = concat(v[1],"/");
        char *fullPath = concat(auxPath, dirToCreate);

        t_mkdir(fullPath, 0752);
        int seekFlag = 0;
        
        long int pos, posAux;
        while ((pDirent = readdir(pDir)) != NULL) {
            printf ("%s\n", pDirent->d_name);
            pos = telldir(pDir);
            seekFlag += 1;
            if (seekFlag == 0) {
            	posAux = pos;	
            }
            if (seekFlag == 2) {
            	printf("Calling seekdir\n");
            	seekdir(pDir, posAux);

            }
            printf("Telldir return value: %ld\n ", pos);
        }
        closedir (pDir);
        return 0;
    }

// mkdir   -> creates the directory specified by parameter
// opendir -> opens a directory for reading through readdir, returns a DIR pointer.
// readdir -> reads the next entry of a directory, returns a struct dirent pointer that allows to access properties of the current entry like d_name (name).
// telldir -> Returns the current location associated with the directory stream (resets if directory is closed).
// seekdir -> Sets the position of the next readdir operation
// closedir -> closes a directory