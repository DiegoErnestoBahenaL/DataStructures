#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;    
}nodeType;

typedef nodeType *pNode;
typedef nodeType *Stack;


void push (Stack *stack, int data){

    pNode new;

    new = (pNode)malloc(sizeof(nodeType));

    new->data = data;
    new->next = *stack;

    *stack = new;
}

int pop (Stack *stack){
    
    pNode node;

    int data;

    node = *stack;

    if (!node)
        return 0;
    
    *stack = node->next;

    data = node->data;

    free(node);

    return data;
}

int main (){


    Stack stack;

    stack = (Stack)malloc(sizeof(Stack));

    int option = 0, input;


    while (option != 3){

        printf("\n1.Push\n2.Pop(Show)\n3.Exit\n");

        scanf("%d",&option);

        switch (option)
        {
            case 1:

                printf("Enter the new element:\n");

                scanf("%d", &input);

                push (stack, input);
            break;

            case 2:                
                printf("Popped element: %d\n", pop(stack)); 
            break;

            case 3:

            break;
            
            default:

                printf("Enter a valid option.\n");       
            break;
        }
    }

    return 0;
}