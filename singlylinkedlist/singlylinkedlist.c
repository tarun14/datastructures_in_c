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
typedef struct node{
	int val;
	struct node *next;
}node;

/* 'Start' pointer for SLL */
node *Start = NULL;


/* Show nodes of SLL */
void showlist(void)
{
	node *pos;
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
void addnodeatbeg(node *temp)
{
	node *pos;
	/* Store current value of Start */
	pos = Start;
	/* The node is being added to empty list */
	if(pos == NULL){
		/* The first node is also the last node of LL */
		temp->next = NULL;
		/* Now 'Start' must point to newly added node */
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

/* MAIN function */
int main()
{
	/* Pointer to hold the address of new node */
	node *temp,*temp1,*temp2,*temp3,*temp4;
    int val=0;

	/* Create a new node */
    printf("Enter new node:");
    scanf("%d",&val);
	temp = (node*)malloc(sizeof(node));
	temp->val=val;
	/* Add node to SLL at beginning */
	addnodeatbeg(temp);


    /* Create a new node */
    printf("Enter node:");
    scanf("%d", &val);
    temp1 = (node*)malloc(sizeof(node));
    temp1->val=val;
    /* Add node to SLL at beginning */
    addnodeatbeg(temp1);	

    /* Create a new node */
    temp2 = (node*)malloc(sizeof(node));
    temp2->val=6;
    /* Add node to SLL at beginning */
    addnodeatbeg(temp2);

    /* Create a new node */
    temp3 = (node*)malloc(sizeof(node));
    temp3->val=7;
    /* Add node to SLL at beginning */
    addnodeatbeg(temp3);

    /* Create a new node */
    temp4 = (node*)malloc(sizeof(node));
    temp4->val=8;
    /* Add node to SLL at beginning */
    addnodeatbeg(temp4);
    showlist();

    /* Delete all allocated memory pointers */
    free(temp);
    free(temp1);
    free(temp2);
    free(temp3);
    free(temp4);
    
    return 0;
}
