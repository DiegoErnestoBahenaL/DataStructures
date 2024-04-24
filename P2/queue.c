#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node * next;
}nodeType;

typedef nodeType *pNode;
typedef nodeType *queue;


void push (pNode *first, pNode *last, int data);
int pop (pNode *first, pNode *last);
void removeElements (pNode *first, pNode *last, int numberOfElements);

int main (){

    pNode first = NULL, last = NULL;

    int option = 0, input;

    while (option != 4){

        printf("\n1.Push\n2.Pop(Show)\n3.Remove Elements\n4.Exit\n");

        scanf("%d",&option);

        switch (option)
        {
            case 1:

                printf("Enter the new element:\n");

                scanf("%d", &input);

                push (&first, &last, input);
            break;

            case 2:                
                printf("Popped element: %d\n", pop(&first, &last)); 
            break;

            case 3:
                printf("Enter the number of elements to remove:\n");

                scanf("%d", &input);

                printf("Removed Elements:\n");

                removeElements(&first, &last, input);
            break;

            case 4:

            break;
            
            default:

                printf("Enter a valid option.\n");       
            break;
        }
    }

    return 0;
}


void push (pNode *first, pNode *last, int data){


    pNode new;

    new = (pNode) malloc(sizeof(nodeType));

    new->data = data;
    new->next = NULL;

    if (*last)
        (*last)->next = new;
    
    *last = new; 

    if (!*first)
        *first = new;

}

int pop (pNode *first, pNode *last){
    
    pNode node;

    int data;

    node = *first;

    if (!node)
        return 0;

    *first = node->next;

    data = node->data;

    free(node);

    if(! *first)
        *last = NULL;

    return data;
}

void removeElements (pNode *first, pNode *last, int numberOfElements){
    
    pNode node;

    for (int i = 0; i < numberOfElements; i++){
        
        if (! *first){
            printf("Queue is empty\n");

            return;
        }
 
        node = *first;
        
        *first = node->next;

        printf("%d\n", node->data);

        free(node);
    }    

    if(! *first)
        *last = NULL;
}