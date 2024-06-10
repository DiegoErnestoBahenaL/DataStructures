#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct node {
   int value;
   struct node *right;
   struct node *left;
} nodeType;

typedef nodeType *pNode;
typedef nodeType *Tree;


void Insert(Tree *tree, int data);
void Delete(Tree *tree, int data);
int Search(Tree tree, int data);
void Prune(Tree *tree);

void InOrder(Tree, void (*func)(int*));
void PreOrder(Tree, void (*func)(int*));
void PostOrder(Tree, void (*func)(int*));

int NumberOfNodes(Tree tree, int* count);
int TreeHeight(Tree tree, int* height);
int Height(Tree tree, int data);

int IsEmpty(Tree tree);
int IsLeaf(pNode node);
void auxCounter(Tree a, int*);
void auxHeight(Tree a, int, int*);
void Show(int *data);

int main()
{
   Tree tree = NULL;
   int height;
   int numberOfNodes;
   int nodeHeight;

   int option = 0, input;


    while (option != 8){

        printf("\n1.Insert Nodes\n2.Show\n3.Delete\n4.Prune\n5.Number of nodes\n6.Tree Height\n7.Node Height\n8.Exit\n");

        scanf("%d",&option);

        switch (option)
        {
            case 1:

               int nodesToCreate;

               printf("Enter the number of nodes:\n");

               scanf("%d", &nodesToCreate);

               printf("Enter the values of the nodes:\n");

               for (int i = 0; i < nodesToCreate; i++){
                  printf("Node %d :\n", i + 1);

                  scanf("%d", &input);

                  Insert(&tree, input);
               }

            break;

            case 2: 

               if(IsEmpty(tree)){
                  printf("The tree is empty");
               }
               else {

                  int showOption;
                  printf("\n1.In Order\n2.Pre Order\n3.Post Order\n");

                  scanf("%d", &showOption);

                  switch (showOption)
                  {
                     case 1:
                     
                        InOrder(tree, Show);

                     break;

                     case 2:
                     
                        PreOrder(tree, Show);

                     break;

                     case 3:
                     
                        PostOrder(tree, Show);

                     break;
                  
                     default:
                        printf("Enter a valid option\n");
                     break;
                  }
               } 

               

            break;

            case 3:
               if(IsEmpty(tree)){
                  printf("The tree is empty");
               }
               else {
                  printf("Enter the element to delete:\n");

                  scanf("%d", &input);

                  Delete(&tree, input);
               }

              
            break;

            case 4:

               if(IsEmpty(tree)){
                  printf("The tree is empty");
               }
               else {
                  Prune(&tree);
               }  
            break;
            
            case 5:
               if(IsEmpty(tree)){
                  printf("The tree is empty");
               }
               else {
                  printf("The number of nodes is: %d\n",NumberOfNodes(tree, &numberOfNodes));
               }
                      
            break;

            case 6:

               if(IsEmpty(tree)){
                  printf("The tree is empty");
               }
               else {
                  printf("The tree height is: %d\n",TreeHeight(tree, &height));
               }

            break;

            case 7:
               
               if(IsEmpty(tree)){
                  printf("The tree is empty");
               }
               else {
                  printf("Enter the element to determine height:\n");

                  scanf("%d", &input);

                  printf("The element height is: %d\n", Height(tree, input));
               }
            break;

            case 8:

            break;

            default:
                printf("Enter a valid option.\n");       
            break;
        }
    }

  
   return 0;
}

void Prune(Tree *tree)
{ 
   if(*tree) {

      Prune(&(*tree)->left); 
      Prune(&(*tree)->right);   
     
      free(*tree);                
      *tree = NULL;
   }
}

void Insert(Tree *tree, int data)
{
   pNode parent = NULL;
   pNode current = *tree;

   //Search for the value to insert in the tree, keeping a pointer to the parent node
   while(!IsEmpty(current) && data != current->value) {
      parent = current;

      if(data < current->value) 
         current = current->left;

      else if(data > current->value) 
         current = current->right;
   }

   //If element found, return
   if(!IsEmpty(current)) 
      return;


   //If parent is null, then the tree was empty, the new node will be the root
   if(IsEmpty(parent)) {

      *tree = (Tree)malloc(sizeof(nodeType));  
      (*tree)->value = data;
      (*tree)->left = (*tree)->right = NULL;
   }

   //If the value to insert is lesser than the parent node, it 
   //is inserted in the left branch 
   else if(data < parent->value) {
      current = (Tree)malloc(sizeof(nodeType));
      parent->left = current;
      current->value = data;
      current->left = current->right = NULL;
   }

   //If the value to insert is greater than the parent node, it
   //is inserted in the right branch
   else if(data > parent->value) {
      current = (Tree)malloc(sizeof(nodeType));
      parent->right = current;
      current->value = data;
      current->left = current->right = NULL;
  }
}

void Delete(Tree *tree, int data)
{
   pNode parent = NULL;
   pNode current;
   pNode node;
   int aux;

   current = *tree;
   
   //While is possible that the value is in the tree
   while(!IsEmpty(current)) {

      //The value to delete must be in 
      //the current node
      if(data == current->value) { 
         
         if(IsLeaf(current)) { 

            //If current is a leaf and has parent,
            //set the pointers of the parent to null
            //given the proper case
            if(parent) {

               if(parent->right == current) 
                  parent->right = NULL;

               else if(parent->left == current) 
                  parent->left = NULL;
            }
            
            free(current); 
            current = NULL;
            return;
         }
         //If current is not leaf...
         else {
            parent = current;

            //search the most left node from the right branch
            if(current->right) {
               node = current->right;
               while(node->left) {
                  parent = node;
                  node = node->left;
               }
            }
         
            //search the most right node from the left branch
            else {
               node = current->left;
               while(node->right) {
                  parent = node;
                  node = node->right;
               }
            }

            //swap with the rightest or leftest node to only delete leafs
            aux = current->value;
            current->value = node->value;
            node->value = aux;
            current = node;
         }
      }
      //Otherwise, value has not been found
      //and it has to be found
      else { 
         parent = current;

         if (data > current->value) 
            current = current->right;

         else if (data < current->value) 
            current = current->left;
      }
   }
}

int Search(Tree tree, int data)
{
   pNode current = tree;

   while(!IsEmpty(current)) {

      if(data == current->value) 
         return TRUE; 

      else if(data < current->value)
         current = current->left; 

      else if(data > current->value) 
         current = current->right;
   }
   return FALSE;
}


void InOrder(Tree tree, void (*func)(int*))
{
   if(tree->left) 
      InOrder(tree->left, func);
   
   func(&(tree->value));

   if(tree->right) 
      InOrder(tree->right, func);
}

void PreOrder(Tree tree, void (*func)(int*))
{
   func(&tree->value);

   if(tree->left) 
      PreOrder(tree->left, func);
  
   if(tree->right) 
      PreOrder(tree->right, func);
}

void PostOrder(Tree tree, void (*func)(int*))
{
   if(tree->left) 
      PostOrder(tree->left, func);
   
   if(tree->right) 
      PostOrder(tree->right, func);
   
   func(&tree->value);
}


int Height(Tree tree, int data)
{
   int height = 0;
   pNode current = tree;

   while(!IsEmpty(current)) { 

      if(data == current->value) 
         return height; 

      else {
         height++; 

         if(data < current->value)
            current = current->left;

         else if(data > current->value) 
            current = current->right;
      }
   }

   //The node doesn't exists in the tree
   return -1; 
}

int NumberOfNodes(Tree tree, int *counter)
{
   *counter = 0;

   auxCounter(tree, counter); 

   return *counter;
}

int TreeHeight(Tree tree, int *height)
{
   *height = 0;

   auxHeight(tree, 0, height); /* Funci�n auxiliar */
   return *height;
}


void auxCounter(Tree nodo, int *c)
{
   //Pre order
   (*c)++; 
   
   if(nodo->left) 
      auxCounter(nodo->left, c);

   if(nodo->right)   
      auxCounter(nodo->right, c);
}

void auxHeight(pNode node, int a, int *height)
{
   //Post order
   if(node->left) 
      auxHeight(node->left, a+1, height);

   if(node->right)   
      auxHeight(node->right, a+1, height);

   if(IsLeaf(node) && a > *height) *height = a;
}

int IsEmpty(Tree tree)
{
   return tree == NULL;
}

int IsLeaf(pNode node)
{
   return !node->right && !node->left;
}

void Show(int *data)
{
   printf("%d, ", *data);
}

