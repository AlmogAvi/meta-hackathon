#include <stdio.h>
#include <stdlib.h>

int main()
{
	char fname[20], encrypted_fname[20], ch;
	FILE *fpts, *fptt;
	
	printf("\n\n Encrypt a text file :\n");
	printf("--------------------------\n"); 	
	
	printf(" Input the name of file to encrypt : ");
	scanf("%s",fname);	

	fpts=fopen(fname, "r");
	if(fpts==NULL)
	{
		printf(" File does not exists or error in opening..!!");
		exit(1);
	}
	fptt=fopen("temp.txt", "w");
	if(fptt==NULL)
	{
		printf(" Error in creation of file temp.txt ..!!");
		fclose(fpts);
		exit(2);
	}
	while(1)
	{
		ch=fgetc(fpts);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			ch=ch+100;
			fputc(ch, fptt);
		}
	}
	fclose(fpts);
	fclose(fptt);
	sprintf(encrypted_fname, "%s.%s", fname, "enc");
	fpts=fopen(encrypted_fname, "w");
	if(fpts==NULL)
	{
		printf(" File does not exists or error in opening..!!");
		exit(3);
	}
	fptt=fopen("temp.txt", "r");
	if(fptt==NULL)
	{
		printf(" File does not exists or error in opening..!!");
		fclose(fpts);
		exit(4);
	}
	while(1)
	{
		ch=fgetc(fptt);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			fputc(ch, fpts);
		}
	}
	printf(" File %s successfully encrypted into %s..!!\n\n", fname, encrypted_fname);
	fclose(fpts);
	fclose(fptt);
	
	return 0;
}