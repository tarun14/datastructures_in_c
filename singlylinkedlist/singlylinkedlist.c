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
#include <stdlib.h>
#include <stdbool.h>

/* Singly linkedlist(SLL) node */
typedef struct node{
	int val;
	struct node *next;
}node;

/* 'Start' pointer for SLL */
node *Start = NULL;

void freelist(void)
{
    node *pos, *next_node;

    pos = Start;
    /* Start should point to 'Null' */
    Start = NULL;
    printf("Freeing the list!!!\n");
    if(pos == NULL){
        printf("The list was already empty, exiting now...\n");
    }
    else{
        /* Delete all nodes till end */
        while(pos->next != NULL){
        /* Store next node's address */
        next_node = pos->next;
        /* Free current node */
        free(pos);
        /* Move to next node */
        pos=next_node;
        }
        /* Free last node */
        free(pos);
        printf("The list is freed, exiting now...\n");
    }
    return;
}
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
void insertnodeatbeg(void)
{
	node *pos;
    node *temp;

    int val;
	/* Store current value of Start */
	pos = Start;

    printf("Enter an integer value of node:");
    scanf("%d",&val);

    /* A new node is created from heap */
    temp = (node *)malloc(sizeof(node));
    /* Store received value into node */
    temp->val = val;

	/* Insert new node at beg of list */
	if(pos == NULL){
		/* If it was an empty list */
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
    int val=0,input=0;
    bool exit=false;


    printf("***** Singly Linked List *******\n");
    
    while(1){
        printf("\nWhich operation do you want to perform??\n");
        printf("1.Insert Node at beginning\n");
        printf("2.Insert Node at end\n");
        printf("3.Delete Node at beginning\n");
        printf("4.Delete Node at end\n");
        printf("5.Display the linked list\n");
        printf("6.Reverse the linked list\n");
        printf("7.Quit\n\n:");

        scanf("%d",&input);
        
        switch(input){
        case 1:
            insertnodeatbeg();
            printf("List after insertion at beginning\n:");
            showlist();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            freelist();
            exit = true;
            break;
        default:
            printf("!!!!!!!!!Enter a valid input!!!!!!!!\n");
            break;
        }

        /* Break out of while loop */
        if(exit)
            break;
    }

    printf("Good Bye!!!\n");
    /* Free all created nodes */
    /* freeallnodes();*/
	/* Create a new node */
//    printf("Enter new node:");
//    scanf("%d",&val);
//	temp = (node*)malloc(sizeof(node));
//	temp->val=val;
//	/* Add node to SLL at beginning */
//	addnodeatbeg(temp);
//
//
//    /* Create a new node */
//    printf("Enter node:");
//    scanf("%d", &val);
//    temp1 = (node*)malloc(sizeof(node));
//    temp1->val=val;
//    /* Add node to SLL at beginning */
//    addnodeatbeg(temp1);	
//
//    /* Create a new node */
//    temp2 = (node*)malloc(sizeof(node));
//    temp2->val=6;
//    /* Add node to SLL at beginning */
//    addnodeatbeg(temp2);
//
//    /* Create a new node */
//    temp3 = (node*)malloc(sizeof(node));
//    temp3->val=7;
//    /* Add node to SLL at beginning */
//    addnodeatbeg(temp3);
//
//    /* Create a new node */
//    temp4 = (node*)malloc(sizeof(node));
//    temp4->val=8;
//    /* Add node to SLL at beginning */
//    addnodeatbeg(temp4);
//    showlist();
//
//    /* Delete all allocated memory pointers */
//    free(temp);
//    free(temp1);
//    free(temp2);
//    free(temp3);
//    free(temp4);
    
    return 0;
}
