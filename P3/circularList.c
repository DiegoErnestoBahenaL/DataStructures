#include <stdio.h>
#include <stdlib.h>

typedef struct node {
   int value;
   struct node *next;
} nodeType;

typedef nodeType *pNode;
typedef nodeType *List;

void Insert (List *list, int data);
void Delete (List *list, int data);
void DeleteList (List *list);
void Show (List list);

int IsEmpty (List list);

int main() {
    List list = NULL;

    int option = 0, input;


    while (option != 5){

        printf("\n1.Insert\n2.Show\n3.Delete\n4.Delete List\n5.Exit\n");

        scanf("%d",&option);

        switch (option)
        {
            case 1:

                printf("Enter the new element:\n");

                scanf("%d", &input);

                Insert(&list, input);
            break;

            case 2: 
                Show(list);
            break;

            case 3:
                printf("Enter the element to delete:\n");

                scanf("%d", &input);

                Delete(&list, input); 
            break;

            case 4:
                DeleteList(&list);
            break;
            
            case 5:
                
            break;

            default:
                printf("Enter a valid option.\n");       
            break;
        }
    }


 
   return 0;
}

void Insert(List *list, int data) {
    pNode node;

    node = (pNode) malloc(sizeof(nodeType));
    node->value = data;

    if(*list == NULL)
        *list = node;
   else 
        node->next = (*list)->next;
   
   
   (*list)->next = node;
}

void Delete(List *list, int data) {

    if (IsEmpty(*list)){
        printf("The list is empty\n");

        return;
    }

    pNode node;

    node = *list;
    //Place the list in the previous node
    //to the one to delete
    do {

        if((*list)->next->value != data) 
            *list = (*list)->next;

    } while((*list)->next->value != data && *list != node);

    if((*list)->next->value == data) {

        //only one element in the list
        if(*list == (*list)->next) {

            free(*list);

            *list = NULL;
        }
        //Multiple elemets in the list
        else {

            node = (*list)->next;
            (*list)->next = node->next;

            free(node);
        }
    }
    else 
        printf("Element to delete not found\n");
}

void DeleteList(List *list) {

    if (IsEmpty(*list)){
        printf("The list is empty\n");

        return;
    }

    pNode node;

    while((*list)->next != *list) {

        node = (*list)->next;
        (*list)->next = node->next;
        free(node);
    }
    free(*list);

   *list = NULL;
}

void Show(List list) {
   
    if (IsEmpty(list)){
        printf("The list is empty\n");

        return;
    }
   
   pNode node = list;

   do {
      printf("%d -> ", node->value);
      node = node->next;
   } while(node != list);

   printf("\n");
}

int IsEmpty(List list){
    return list == NULL;
}

