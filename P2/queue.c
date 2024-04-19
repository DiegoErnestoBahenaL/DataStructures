#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node * next;
}nodeType;

typedef nodeType *pNode;
typedef nodeType *queue;




void add (pNode *first, pNode *last, int data){


    pNode new;

    new = (pNode) malloc(sizeof(nodeType));

    new.datadata = data;
    new.next = NULL;

    if (*last)
        *last.next = new;
    else
        *last = new; 

    if (!*first)
        *first = new;

}

int read (pNode *first, pNode *last){
    
    pNode node;

    int data;

    node = *first;

    if (!node)
        return 0;

    first = node->next;

    data = node->data;

    free(node);

    return data;
}