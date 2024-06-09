#include <stdio.h>
#include <stdlib.h>

#define ASC 1
#define DESC 0

typedef struct node {
   int value;
   struct node *next;
   struct node *previous;
} nodeType;

typedef nodeType *pNode;
typedef nodeType *List;

void Insert(List *list, int data);
void Delete(List *list, int data);
void DeleteList(List *list);
void Show(List list, int order);

int IsEmpty (List list);

int main() {
   List list = NULL;

    int option = 0, input;


    while (option != 6){

        printf("\n1.Insert\n2.Show Ascending\n3.Show Descending\n4.Delete\n5.Delete List\n6.Exit\n");

        scanf("%d",&option);

        switch (option)
        {
            case 1:

                printf("Enter the new element:\n");

                scanf("%d", &input);

                Insert(&list, input);
            break;

            case 2: 
                Show(list, ASC);
            break;

            case 3:
               Show(list, DESC);
            break;

            case 4:
                printf("Enter the element to delete:\n");

                scanf("%d", &input);

                Delete(&list, input); 
            break;

            case 5:
                DeleteList(&list);
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

void Insert(List *list, int data) {
   pNode new, current;

   new = (pNode)malloc(sizeof(nodeType));
   new->value = data;

   current = *list;

   if(current){
      
      while(current->previous) 
         current = current->previous;

   }

   if(!current || current->value > data) {

      new->next = current;
      new->previous = NULL;

      if(current) 
         current->previous = new;

      if(!*list) 
         *list = new;

   }

   else {
   
      while(current->next && current->next->value <= data)
         current = current->next;

      new->next = current->next;
      current->next = new;
      new->previous = current;
    
      if(new->next)
         new->next->previous = new;
   }
}

void Delete(List *list, int data) {
 
   if (IsEmpty(*list)){
      printf("The list is empty");
      
      return;
   }  
   
   pNode node;

   node = *list;

   while(node && node->value < data) 
      node = node->next;

   while(node && node->value > data) 
      node = node->previous;

   /* El value v no está en la list */
   if(!node || node->value != data) {
      
      printf("Element to delete not found.\n");

      return;
   }
      

   if(node == *list)
      if(node->previous) 
         *list = node->previous;
   
   else 
      *list = node->next;

   if(node->previous)
      node->previous->next = node->next;

   if(node->next)
      node->next->previous = node->previous;

   free(node);
}

void DeleteList(List *list) {

   if (IsEmpty(*list)){
      printf("The list is empty");

      return;
   }

   pNode node, current;

   current = *list;

   while(current->previous) 
      current = current->previous;

   while(current) {
      node = current;
      current = current->next;
      free(node);
   }
   *list = NULL;
}

void Show(List list, int order) {
   pNode node = list;

   if(IsEmpty(list)){
      printf("List is empty");
      return;
   } 

   node = list;

   if(order == ASC) {
      while(node->previous) 
         node = node->previous;

      printf("Order ASC: ");

      while(node) {
         printf("%d -> ", node->value);
         node = node->next;
      }
   }
   else {
      while(node->next) 
         node = node->next;

      printf("Order DESC: ");

      while(node) {
         printf("%d -> ", node->value);
         node = node->previous;
      }
   }

   printf("\n");
}

int IsEmpty(List list){
   return list == NULL;
}