/**
 * C program to check whether a file exists or not.
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>

int isFileExists(const char *path);


int main()
{
    char path[100];

    printf("Enter source file path: ");
    scanf("%s", path);


    /* Check if file exists or not */
    if (isFileExists(path))
    {
        printf("File exists at path '%s'\n", path);
    }
    else
    {
        printf("File does not exists at path '%s'\n", path);
    }

    return 0;
}



/**
 * Function to check whether a file exists or not.
 * It returns 1 if file exists at given path otherwise
 * returns 0.
 */
int isFileExists(const char *path)
{
    /* Try to open file */
    FILE *fptr = fopen(path, "r");

    /* If file does not exists  */
    if (fptr == NULL)
        return 0;

    /* File exists hence close file and return true. */
    fclose(fptr);

    return 1;
}

