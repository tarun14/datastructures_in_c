/*H**********************************************************************
* FILENAME :        singlylinkedlist.c             DESIGN REF: FMCM00
*
* DESCRIPTION :
*       Singly linkedlist(SLL) with various operations.
*
* PUBLIC FUNCTIONS :
*       
*
*
* NOTES :
*       
*      
*
*       Copyright info:
*
* AUTHOR :    Tarun14        START DATE :    08 Oct 21
*
* CHANGES :
*
* REF NO  VERSION DATE    WHO     DETAIL
* 
*
*H*/


#include <stdio.h>
#include<stdlib.h>

/* Singly linkedlist(SLL) node */
struct node{
	int val;
	struct node *next;
};

/* 'Start' pointer for SLL */
struct node *Start = NULL;


/* Show nodes of SLL */
void showlist(void)
{
	struct node *pos;
	/* Store value of 'Start' in 'temp' variable */
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

/* Add node to SLL at beginning */
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

	/* Create a new node */
	temp = (struct node*)malloc(sizeof(struct node));
	temp->val=4;
	/* Add node to SLL at beginning */
	addnodeatbeg(temp);
	showlist();
	
	/* As above */
 	temp = (struct node*)malloc(sizeof(struct node));
 	temp->val=1;
 	addnodeatbeg(temp);
 	showlist();

 	temp = (struct node*)malloc(sizeof(struct node));
 	temp->val=2;
 	addnodeatbeg(temp);
 	showlist();

 	temp = (struct node*)malloc(sizeof(struct node));
 	temp->val=3;
 	addnodeatbeg(temp);
 	showlist();

 	temp = (struct node*)malloc(sizeof(struct node));
 	temp->val=7;
 	addnodeatbeg(temp);
 	showlist();

return 0;
}
