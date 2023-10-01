#ifndef _LISTS_C_H
#define _LISTS_C_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NICE 80
/*the node structure of a the list which containes a string the size we choose is nice 
to print by and a pointer to the next node in the list. */
struct Node {
	char ptr[NICE];
	struct Node *next;
	};
void outage(struct Node *head,long N,long Q, FILE *output);
int calc(struct Node*);
int zigzag(struct Node*);
int solve(int arr[9][9]);
/*makeNode - a method that returns a newely created node and sets all values to NULL values.*/
struct Node *makeNode();
/*makeFullNode - a method that return a newely created node with values set to params as listed below.
@param Next - tho ptr to the next node desired.
@param Ptr - the string that will go into the node ptr.*/
struct Node *makeFullNode(struct Node *Next, char *Ptr);
/*readFile - a method that reads a file into a linked list returning the head to that list.
it reads the file using fgets and a const to decide what size the node strings should be.
@param path - the name of the file to open.
@return the head of the list.*/
struct Node *readFile(char *path);
/*readstl - a method that reads a string into a linked list returning the head to that list.
it prints the list to a tmp file then reads the file using readFile.
@param path - the string to read.
@return the head of the list.*/
struct Node *readstl(char*);
/*printList - a method that prints the list to stdout.
it goes in loop on the nodes each time printing the node->ptr.
@param head - the head of the linked list.*/
void printList(struct Node *head);
/*insertToList - a method that inserts a string into list.
it creates a new list using readstl the connects the nodes using the basic method.
@param node - the node to override.
@param str - the string to insert.*/
struct Node* insertToList(struct Node *node, char *str);
/*a method that prints the list to stdout.
it goes in loop on the nodes each time printing the node->ptr.
@param head - the head of the linked list.*/
void printListToFile(char *path,struct Node *head);
/*sizeOfList - a method that returns how many node are in the list.
it goes in a while loop incresing counter by 1 each iteration.
@param head - the head of the list to measure.
@return the size of the list.*/
unsigned int sizeOfList(struct Node *head);
/*freeList - a method to free a list ffrom memory*/
void freeList(struct Node *head);
#endif

