/**
 * C program to list contents of a directory recursively.
 */

#include <stdio.h>
#include <string.h>
#include <sys/dir.h>

void listFilesRecursively(char *path);
int count;

int main()
{
    /* Directory path to list files */
    char path[100];

    /* Input path from user */
    printf("Enter path to list files: ");
    scanf("%s", path);
    listFilesRecursively(path);
	printf("%d\n",count);
    return 0;
}


/**
 * Lists all files and sub-directories recursively 
 * considering path as base path.
 */
void listFilesRecursively(char *basePath)
{
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(basePath);

    /* Unable to open directory stream */
    if (!dir)
	{
		printf("bad\n");
		return;
	}
    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
		count++;
            /* Construct new path from our base path */
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);

            listFilesRecursively(path);
        }
    }
    closedir(dir);
}
