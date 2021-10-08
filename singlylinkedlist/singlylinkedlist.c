/*
* File: singlylinkedlist.c
*
* Description: This file contains the c code for singly linked list data
* structure.
*
* Change History: Oct 2021
*
* Creator: tarun14
*
*/

#include <stdio.h>
#include<stdlib.h>

/* Linked List node */
struct node{
	int val;
	struct node *next;
};

/* Initialize the 'start' pointer with NULL */
struct node *Start = NULL;

/* Show the list */

void showlist(void)
{
	struct node *pos;
	/* Store value of Start in temp variable */
	pos = Start;

	if(pos == NULL){

		printf("The list is empty\n");
	}
	else{
		for(;pos!=NULL;pos = pos->next){
			/* Print value of node */
			printf("%d ",pos->val);
		}
		
		printf("\n");
		

	}
	return;
}

/* Add node at beginning */
void addnodeatbeg(struct node *temp)
{
	struct node *pos;

	/* Store current value of Start */
	pos = Start;

	/* The node is being added to empty list */
	if(pos == NULL){
		/* The first node is also the last node of LL */
		temp->next = NULL;
		/* Now Start must point to newly added node */
		Start = temp;

	}
	/* The node is being added to non empty LL */
	else{
		/* New node must point to previosly first node */
		temp->next = pos;
		/* Start must be updated */
		Start = temp;

	}

	return;
}

int main()
{
	/* Pointer to hold the address of new node */
	struct node* temp;

	/* Create a new node and store it's address in temp */
	temp = (struct node*)malloc(sizeof(struct node));
	temp->val=4;
	/* Add node at beginning */
	addnodeatbeg(temp);
	showlist();
	
	/* Create a new node and store it's address in temp */
 69     temp = (struct node*)malloc(sizeof(struct node));
 70     temp->val=1;
 71     /* Add node at beginning */
 72     addnodeatbeg(temp);
 73     showlist();

        /* Create a new node and store it's address in temp */
 69     temp = (struct node*)malloc(sizeof(struct node));
 70     temp->val=2;
 71     /* Add node at beginning */
 72     addnodeatbeg(temp);
 73     showlist();

        /* Create a new node and store it's address in temp */
 69     temp = (struct node*)malloc(sizeof(struct node));
 70     temp->val=3;
 71     /* Add node at beginning */
 72     addnodeatbeg(temp);
 73     showlist();

	/* Create a new node and store it's address in temp */
 69     temp = (struct node*)malloc(sizeof(node));
 70     temp->val=7;
 71     /* Add node at beginning */
 72     addnodeatbeg(temp);
 73     showlist();

return 0;
}
