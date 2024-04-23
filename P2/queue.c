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

    int input;

    push(&first, &last, 10);
    push(&first, &last, 20);
    push(&first, &last, 30);
    push(&first, &last, 40);    
    push(&first, &last, 50);
    push(&first, &last, 60);

    pop(&first, &last);

    scanf("%d", &input);

    removeElements(&first, &last, input);

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