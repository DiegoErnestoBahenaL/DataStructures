//Ordered List

#include <stdio.h>
#include <stdlib.h>


typedef struct node{

    int data;
    struct node * next;

} nodeType;


typedef nodeType *pNode;
typedef nodeType *List;

void add (List *list, int data);
void delete (List *list, int data);
int isEmpty (List list);
void deleteList (List *list);
void showList(List list);


int main (){

    List list = NULL;

    pNode l;

    add (&list, 20);
    add (&list, 10);
    add (&list, 40);
    add (&list, 30);

    showList(list);

    delete(&list, 20);
    delete(&list, 15);
    
    showList(list);

    deleteList(&list);

    showList(list);

    return 0;
}

int isEmpty (List list){
    return (list == NULL);
}

void deleteList(List *list){

    pNode node;

    while (*list){
        node = *list;

        *list = node->next;

        free(node);
    }

}


 add (List *list, int data){

    pNode new, previous;

    new = (pNode)malloc(sizeof(nodeType));

    new ->data = data;

    if (isEmpty(*list) || (*list)->data > data){
        new ->next = *list;
        *list = new;
    }
    else {
        previous = *list;

        while (previous->next && previous->next->data <= data){
            
            previous = previous->next;   
        }

        new ->next = previous->next;
        previous->next = new;
    }
}

void delete (List *list, int data){

    pNode previous, node;

    node = *list;

    previous = NULL;

    while (node && node->data < data){
        previous = node;
        node = node->next;
    }

    if(!node || node->data != data)  

        return;

    else {

        if (!previous)
            *list = node->next;

        else 
            previous->next = node->next;

        free(node);

    }
}

void showList(List list){

    pNode node = list;

    if(isEmpty(node))

        printf("List is empty\n");

    else {

        while (node){

            printf("%d -> ", node->data);

            node = node->next;
        }

        printf("\n"); 

    }
}