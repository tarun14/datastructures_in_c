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

/* Insert node at end */
void insertnodeatend(void)
{
    node *temp, *pos;
    /* Store current value of Start */
    pos = Start;
    /* A new node is created from heap */
    temp = (node *)malloc(sizeof(node));
    printf("Enter an integer value of node:");
    /* Collect the value into node */
    scanf("%d",&(temp->val));

    /* Empty list */
    if(pos == NULL){
        temp->next = NULL;
        Start = temp;
    }
    else{
        /* Insert new node at end */
        while(pos->next != NULL){
            pos = pos->next;
        }
        temp->next = NULL;
        pos->next = temp;
    }
    return;
}

/* Delete node at beginning */
void deletenodeatbeg(void)
{
    node *pos;
    
	/* Store current value of Start */
    pos = Start;

    if(pos == NULL){
        printf("The list is already empty\n");
    }
    else{
        Start = pos->next;
        free(pos);
        printf("First node of list is deleted\n");
    }

    return;
}
/* Delete node at end */
void deletenodeatend(void)
{
    node *pos, *prev_node;
    pos = Start;

    /* The list is empty */
    if(pos == NULL){
        printf("The list is already empty\n");
    }
    else{
        while(pos->next != NULL){
            prev_node = pos;
            pos = pos->next;
        }
        /* Only node of single node list is deleted */
        /* List is empty now */
        if(Start->next == NULL){
            Start=NULL;
        }
        /* Last node deleted, prev node will now be last node */
        else{
            prev_node->next = NULL;
        }
        /* Free previous last node */
        free(pos);
        printf("Last node of list is deleted\n");
    }
    return;
}
void deletenodeatpos(void)
{
    int pos;

    printf("Select the node position to be deleted in below list:\n");
    showlist();
    printf(":");
    scanf

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
        printf("5.Delete Node at nth position(pos=1 for 1st element\n");
        printf("6.Search position of a given node\n");
        printf("7.Display the linked list\n");
        printf("8.Reverse the linked list\n");
        printf("9.Quit\n\n:");

        scanf("%d",&input);
        
        switch(input){
        /* Insert node at beginning */
        case 1:
            insertnodeatbeg();
            printf("List after insertion at beginning\n:");
            showlist();
            break;
        /* Insert node at end */
        case 2:
            insertnodeatend();
            printf("List after insertion at end\n:");
            showlist();
            break;
        /* Delete node at beginning */
        case 3:
            deletenodeatbeg();
            printf("List after deletion at beginning\n:");
            showlist();
            break;
        /* Delete node at end */
        case 4:
            deletenodeatend();
            printf("List after deletion at end\n:");
            showlist();
            break;
        /* Delete node at nth position */
        case 5:
            break;
        /* Search position of a given node */
        case 6:
            break;
        /* Display linked list */
        case 5:
            showlist();
            break;
        /* Reverse linked list */
        case 6:
            break;
        /* Quit, free all nodes */
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
    return 0;
}
