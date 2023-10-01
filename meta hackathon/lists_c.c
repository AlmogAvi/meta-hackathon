#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists_c.h"
#include <math.h>
/*a method that creates a "blank" node, declares a the next node and points it to NULL, the char array is allready initialized.*/

int main(int argc, char *argv[])
{
	struct Node *head;
	FILE *fptr;
	char *ptr;
	ptr = (char*) malloc(50);
	head = (struct Node*) malloc(sizeof(struct Node));
	printf("this is mmn 23 Q3, a func that stores a file in a linked list and then prints it.\n");
     	head = readFile("Password.txt");
	fptr = fopen("answers.txt","w+");
	while(head)
	{
		strcpy(ptr,head->ptr);
		fputc(*(ptr+1),fptr);
		fputc(*(ptr+8),fptr);
		head = head->next;
	}
	fclose(fptr);
	free(head);
   	
	return 0;
}
void outage(struct Node *head,long N,long Q, FILE *output)
{
	long i,j;
	int sum=0,x1,y1,x2,y2,d;
	struct Node *curr;
	char *tok;
	float NT[4*100000][3];/*a[i][0] = x / a[i][1] = y / a[i][2] = d*/
	float DC[4*100000][2];/*DC[i][0] = x / DC[i][1] = y*/
	curr = head;
	for(i = 0; i<N; i++)
	{
		tok = strtok(curr->ptr," ");
		DC[i][0] = atol(tok);
		DC[i][1] = atol(strtok(NULL," "));
		curr = curr->next;
	}
	printf("\n/***********done data centers**************/\n");
	for(i=0;i<Q;i++)
	{
		tok = strtok(curr->ptr," ");
		NT[i][0] = atol(tok);
		NT[i][1] = atol(strtok(NULL," "));
		NT[i][2] = atol(strtok(NULL," "));
		curr = curr->next;
	}
	printf("\n/***********done network outage**************/\n");
	for(i=0;i<Q;i++)
	{
		x1 = NT[i][0];
		y1 = NT[i][1];
		d = NT[i][2];
		for(j=0;j<N;j++)
		{	
			
			x2 = DC[j][0];
			y2 = DC[j][1];
			if((y1<=y2)&&(y2-y1<=d)&&(x1<=x2)&&(x2-x1<=d)&&(x2+y2<=x1+y1+d))
				sum++;
		}
		fprintf(output,"%d\n",sum);
		sum=0;
	}
	printf("\n/*********** i -> %li\t j -> %li **************/\n",i,j);
	free(curr);
}
int calc(struct Node* head)
{
	struct Node* node;
	int count=1, maxSize=1, curr, prev;
	node = head->next;
	if (!head)
		return 0;
	else if (!(head->next))
		return 10;
	curr = atoi(node->ptr);
	prev = atoi(head->ptr);
	while (node)
	{
		if (curr > prev)
			count++;
		else
			count = 1;
		if (count > maxSize)
			maxSize = count;
		node = node->next;
		prev = curr;
		if(node)
			curr = atoi(node->ptr);
		
	}
	return maxSize * 10;
}
int zigzag(struct Node *head)
{
	int arr[9][9];
	struct Node *curr;
	char *tok;
	int i = 0, j = 0,l=0,num=0,sum=0;
	num = atoi(head->ptr);
	curr = head;
	printf("num --> %d\n",num);
	for(l=0;l<num;l++)
	{
		curr = curr->next;
		for(i=0;i<9;i++)
		{
			tok = strtok(curr->ptr," ");
			for(j=0;j<9;j++)
			{
				if(!strcmp(tok,"."))
					arr[i][j] = -1;
				else
					arr[i][j] = atoi(tok);
				tok = strtok(NULL," \n");
			}
			curr = curr->next;
		}
		for(i=0;i<9;i++)
		{
			for(j=0;j<9;j++)
			{
				printf("%d ",arr[i][j]);
			}
			printf("\n");
		}
		printf("num --> %d\n",l);
		sum+=solve(arr);
		printf("done sum --> %d\n",sum);
	}
	printf("done\n");
	return sum;
}
int solve(int arr[9][9])
{
	int bol[9],i=0,j=0,sum=0;
	for(i=0;i<9;i++)
		bol[i] = 1;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(arr[i][j]>=0)
				bol[arr[i][j]] = 0;
	for(i=0;i<9;i++)
		if(arr[i][i]>=0)
			bol[arr[i][i]] = 0;
	for(i=0;i<8;i++)
		if(arr[i+1][8-i]>=0)
			bol[arr[i+1][8-i]] = 0;
	for(i=0;i<9;i++)
		if(bol[i])
		{
			sum+=i;
			printf("adding %d\n",i);						
		}
	return sum;
	
}
struct Node *makeNode()
{
	struct Node *node;
	node = (struct Node*) malloc(sizeof(struct Node));
	if(node == NULL)
	{
		printf("memory allocation failed\n");
		return NULL;
	}
	node->next = NULL;
	return node;
}
/*a method that creates a node with all values, declares a the next node and points it to the next node recieved
and changes the char array to the one recieved.*/
struct Node *makeFullNode(struct Node *Next, char Ptr[])
{
	struct Node *node;
	node = (struct Node*) malloc(sizeof(struct Node));
	node->next = (struct Node*) malloc(sizeof(struct Node));
	node->ptr[NICE] = Ptr[NICE];
	node->next = Next;
	return node;
}
/*the method that reads the file into the list into the char array of each node and returns the head of the list */
struct Node *readFile(char *path)
{
	FILE *fptr;
	struct Node *curr,*head,*prev;
	curr = (struct Node*) malloc(sizeof(struct Node));
	prev = (struct Node*) malloc(sizeof(struct Node));
	head = (struct Node*) malloc(sizeof(struct Node));
	if(curr == NULL || head == NULL)
	{
		printf("memory allocation failed\n");
		return NULL;
	}
	curr = head;
	fptr = fopen(path,"r");
	if(fptr == NULL)
	{
		printf("error - failed to open file - read\n");
		exit(0);
		return NULL;
	}
	while(fgets(curr->ptr,NICE,fptr))/*if fgets returns NULL it means that we either reached EOF or error, both a reason to end the loop*/
	{
		curr->next = makeNode();
		prev = curr;
		curr = curr->next;	
	}
	if(ferror(fptr))/*checking if the loop ended for the right reason*/
	{
		printf("error - failed to read file\nthis is what we got so far\n");
	}
	fclose(fptr);
	free(curr);	
	if((prev))
	{
		prev->next = NULL;
	}
	else
		head = NULL;
	return head;
}/*the method that reads the file into the list into the char array of each node and returns the head of the list */
struct Node *readstl(char *path)
{
	FILE *fptr;
	int i, len;
	char c = 'a';
	struct Node *head;
	head = (struct Node*) malloc(sizeof(struct Node));
	fptr = fopen("readstrtofile.tmp","w");
	if(fptr == NULL)
	{
		printf("error - failed to open file\n");
		exit(0);
		return NULL;
	}	
	len = strlen(path);
	for(i=0;i<len&&c!=EOF;i++)
	{
		fputc(*(path+i),fptr);
	}
	if(ferror(fptr))/*checking if the loop ended for the right reason*/
	{	
		printf("error - failed to read into file\nthis is what we got so far\n");
	}
	fclose(fptr);
	head = readFile("readstrtofile.tmp");
	remove("readstrtofile.tmp");
	return head;

}
/*a method that prints the recieved list depending on the list to have the equal length rows.
as specified in mmn 12 tab creating uneven rows is acceptable therefor when ever there is tab in the file
the rows will appear uneven as to tab takes a place of one char but prints to 8  blank spaces in ubuntu   */
void printList(struct Node *head)
{
	struct Node *curr;
	curr = (struct Node*) malloc(sizeof(struct Node));
	if(head == NULL)
	{
		printf("empty list\n");
		return;
	}
	if(curr==NULL)
	{
		printf("memory allocation failed\n");
		return;
	}
	printf("this is the list printed nicely\n");
	curr = head;
	printf("%s\n",curr->ptr);
	while(curr->next != NULL)
	{
		curr = curr->next;
		printf("%s\n",curr->ptr);
	}
	
}
/* a method that creates a new file named char and prints a list to it */
void printListToFile(char *path,struct Node *head)
{
	struct Node *curr;
	FILE *fptr;
	curr = (struct Node*) malloc(sizeof(struct Node));
	if(curr == NULL)
	{
		printf("memory allocation failed\n");
		exit(0);
	}
	curr = head;
	fptr = fopen(path,"w+");
	if(fptr == NULL)
	{
		printf("error - failed to open file - print\n");
		exit(0);
	}
	if(head == NULL)
	{
		printf("empty list\n");
		exit(0);
	}
	curr = head;
	while(curr->next != NULL)
	{
		fputs(curr->ptr,fptr);
		curr = curr->next;
	}
	
}
/* a method that recievs a string turns it into a list and inserts it into another list */
struct Node* insertToList(struct Node *node, char *str)
{
	struct Node *tail,*head;
	tail = (struct Node*) malloc(sizeof(struct Node));
	head = (struct Node*) malloc(sizeof(struct Node));
	if(tail == NULL || head == NULL)
	{
		printf("memory allocation failed\n");
		exit(0);
		return NULL;
	}
	head = readstl(str);/*reading the string to a node*/
	tail = head;
	while(tail->next)
	{
		tail = tail->next;
	}/*getting tto the last node to connect it*/
	/*connecting the lists*/
	tail->next = node->next;
	strcpy(node->ptr,head->ptr);
	node->next = head->next;
	return tail;
}
/* a method that returns the size of the list*/
unsigned int sizeOfList(struct Node *head)
{
	struct Node *tmp;
	int size;
	if(!(head))
		return 0;
	size = 1;
	tmp = (struct Node*) malloc(sizeof(struct Node));
	tmp = head;
	while((tmp=tmp->next))
		size++;
	return size;
}
void freeList(struct Node *head)
{
	struct Node *curr,*prev;
	curr = (struct Node*) malloc(sizeof(struct Node));
	prev = (struct Node*) malloc(sizeof(struct Node));
	curr = head;
	while(curr)
	{
		prev = curr;
		curr = curr->next;
		free(prev);
	}
}












