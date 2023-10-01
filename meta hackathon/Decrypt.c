#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CODE 256

int main(int argc, char *argv[])
{
	char ch;
	int dec_index = 0, code_length = strlen(argv[1]);
	
	while(1)
	{
		ch=getchar();
		if(ch==EOF)
		{
			break;
		}
		else
		{
			ch=ch-argv[1][dec_index++ % code_length] % MAX_CODE;
			if (ch < 0)
				ch += MAX_CODE;
			putchar(ch);
		}
	}
	return 0;
}
