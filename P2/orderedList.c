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
void search (List *list, int data);
void delete (List *list, int data);
int isEmpty (List list);
void deleteList (List *list);
void showList(List list);


int main (){

    List list = NULL;

    int option = 0, input;

    while (option != 6){

        printf("\n1.Add\n2.Search\n3.Show List\n4.Delete\n5.Delete List\n6.Exit\n");

        scanf("%d",&option);

        switch (option)
        {
            case 1:

                printf("Enter the new element:\n");

                scanf("%d", &input);

                add(&list, input);
            break;

            case 2: 
                printf("Enter the element to search:\n");

                scanf("%d", &input);

                search(&list, input); 
            break;

            case 3:
                showList(list);
            break;

            case 4:
                printf("Enter the element to delete:\n");

                scanf("%d", &input);

                delete(&list, input); 
            break;
            
            case 5:
                deleteList(&list);
            break;

            case 6:
                
            break;

            default:
                printf("Enter a valid option.\n");       
            break;
        }
    }

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

    if(!node || node->data != data){

        printf("Element to delete not found\n");

        return;
    }   

    else {

        if (!previous)
            *list = node->next;

        else 
            previous->next = node->next;

        free(node);

    }
}

void search (List *list, int data){
    pNode node;

    int index = 0;

    node = *list;

    while (node && node->data < data){
        node = node->next;
        index++;
    }

    if (!node || node->data != data)
    {
        printf("Element not found.\n");
    }
    else {
        printf ("Element found at index %d\n", index);
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