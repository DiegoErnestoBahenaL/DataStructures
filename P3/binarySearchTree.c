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

/* Funciones con �rboles: */
/* Insertar en �rbol ordenado: */
void Insertar(Tree *a, int dat);
/* Borrar un elemento: */
void Borrar(Tree *a, int dat);
/* Funci�n de b�squeda: */
int Buscar(Tree a, int dat);
/* Comprobar si el �rbol est� vac�o: */
int Vacio(Tree r);
/* Comprobar si es un nodo hoja: */
int EsHoja(pNode r);
/* Contar n�mero de nodos: */
int NumeroNodos(Tree a, int* c);
/* Calcular la altura de un �rbol: */
int AlturaTree(Tree a, int* altura);
/* Calcular altura de un value: */
int Altura(Tree a, int dat);
/* Aplicar una funci�n a cada elemento del �rbol: */
void InOrden(Tree, void (*func)(int*));
void PreOrden(Tree, void (*func)(int*));
void PostOrden(Tree, void (*func)(int*));

/* Funciones auxiliares: */
void Podar(Tree *a);
void auxContador(Tree a, int*);
void auxAltura(Tree a, int, int*);

void Mostrar(int *d);

/* Programa de ejemplo */
int main()
{
   Tree TreeInt=NULL;
   int altura;
   int nnodos;

   /* Inserci�n de nodos en �rbol: */
   Insertar(&TreeInt, 10);
   Insertar(&TreeInt, 5);
   Insertar(&TreeInt, 12);
   Insertar(&TreeInt, 4);
   Insertar(&TreeInt, 7);
   Insertar(&TreeInt, 3);
   Insertar(&TreeInt, 6);
   Insertar(&TreeInt, 9);
   Insertar(&TreeInt, 8);
   Insertar(&TreeInt, 11);
   Insertar(&TreeInt, 14);
   Insertar(&TreeInt, 13);
   Insertar(&TreeInt, 2);
   Insertar(&TreeInt, 1);
   Insertar(&TreeInt, 15);
   Insertar(&TreeInt, 10);
   Insertar(&TreeInt, 17);
   Insertar(&TreeInt, 18);
   Insertar(&TreeInt, 16);

   printf("Altura de Tree %d\n", AlturaTree(TreeInt, &altura));

   /* Mostrar el �rbol en tres ordenes distintos: */
   printf("InOrden: ");
   InOrden(TreeInt, Mostrar);
   printf("\n");
   printf("PreOrden: ");
   PreOrden(TreeInt, Mostrar);
   printf("\n");
   printf("PostOrden: ");
   PostOrden(TreeInt, Mostrar);
   printf("\n");

   /* Borraremos algunos elementos: */
   printf("N nodos: %d\n", NumeroNodos(TreeInt, &nnodos));
   Borrar(&TreeInt, 5);
   printf("Borrar 5: ");
   InOrden(TreeInt, Mostrar);
   printf("\n");
   Borrar(&TreeInt, 8);
   printf("Borrar 8: ");
   InOrden(TreeInt, Mostrar);
   printf("\n");
   Borrar(&TreeInt, 15);
   printf("Borrar 15: ");
   InOrden(TreeInt, Mostrar);
   printf("\n");
   Borrar(&TreeInt, 245);
   printf("Borrar 245: ");
   InOrden(TreeInt, Mostrar);
   printf("\n");
   Borrar(&TreeInt, 4);
   printf("Borrar 4: ");
   InOrden(TreeInt, Mostrar);
   printf("\n");
   Borrar(&TreeInt, 17);
   printf("Borrar 17: ");
   InOrden(TreeInt, Mostrar);
   printf("\n");

   /* Veamos algunos par�metros */
   printf("N nodos: %d\n", NumeroNodos(TreeInt, &nnodos));
   printf("Altura de 1 %d\n", Altura(TreeInt, 1));
   printf("Altura de 10 %d\n", Altura(TreeInt, 10));
   printf("Altura de Tree %d\n", AlturaTree(TreeInt, &altura));

   /* Liberar memoria asociada al �rbol: */
   Podar(&TreeInt);
   system("PAUSE");
   return 0;
}

/* Poda: borrar todos los nodos a partir de uno, incluido */
void Podar(Tree *a)
{
   /* Algoritmo recursivo, recorrido en postorden */
   if(*a) {
      Podar(&(*a)->left); /* Podar left */
      Podar(&(*a)->right);   /* Podar right */
      free(*a);                /* Eliminar nodo */
      *a = NULL;
   }
}

/* Insertar un value en el �rbol ABB */
void Insertar(Tree *a, int dat)
{
   pNode padre = NULL;
   pNode actual = *a;

   /* Buscar el value en el �rbol, manteniendo un puntero al nodo padre */
   while(!Vacio(actual) && dat != actual->value) {
      padre = actual;
      if(dat < actual->value) actual = actual->left;
      else if(dat > actual->value) actual = actual->right;
   }

   /* Si se ha encontrado el elemento, regresar sin insertar */
   if(!Vacio(actual)) return;
   /* Si padre es NULL, entonces el �rbol estaba vac�o, el nuevo nodo ser�
      el nodo raiz */
   if(Vacio(padre)) {
      *a = (Tree)malloc(sizeof(nodeType));
      (*a)->value = dat;
      (*a)->left = (*a)->right = NULL;
   }
   /* Si el value es menor que el que contiene el nodo padre, lo insertamos
      en la rama izquierda */
   else if(dat < padre->value) {
      actual = (Tree)malloc(sizeof(nodeType));
      padre->left = actual;
      actual->value = dat;
      actual->left = actual->right = NULL;
   }
   /* Si el value es mayor que el que contiene el nodo padre, lo insertamos
      en la rama derecha */
   else if(dat > padre->value) {
      actual = (Tree)malloc(sizeof(nodeType));
      padre->right = actual;
      actual->value = dat;
      actual->left = actual->right = NULL;
  }
}

/* Eliminar un elemento de un �rbol ABB */
void Borrar(Tree *a, int dat)
{
   pNode padre = NULL;
   pNode actual;
   pNode nodo;
   int aux;

   actual = *a;
   /* Mientras sea posible que el valor est� en el �rbol */
   while(!Vacio(actual)) {
      if(dat == actual->value) { /* Si el valor est� en el nodo actual */
         if(EsHoja(actual)) { /* Y si adem�s es un nodo hoja: lo borramos */
            if(padre) /* Si tiene padre (no es el nodo raiz) */
               /* Anulamos el puntero que le hace referencia */
               if(padre->right == actual) padre->right = NULL;
               else if(padre->left == actual) padre->left = NULL;
            free(actual); /* Borrar el nodo */
            actual = NULL;
            return;
         }
         else { /* Si el valor est� en el nodo actual, pero no es hoja */
            padre = actual;
            /* Buscar nodo m�s left de rama derecha */
            if(actual->right) {
               nodo = actual->right;
               while(nodo->left) {
                  padre = nodo;
                  nodo = nodo->left;
               }
            }
            /* O buscar nodo m�s right de rama izquierda */
            else {
               nodo = actual->left;
               while(nodo->right) {
                  padre = nodo;
                  nodo = nodo->right;
               }
            }
            /* Intercambiar valores de no a borrar u nodo encontrado
               y continuar, cerrando el bucle. El nodo encontrado no tiene
               por qu� ser un nodo hoja, cerrando el bucle nos aseguramos
               de que s�lo se eliminan nodos hoja. */
            aux = actual->value;
            actual->value = nodo->value;
            nodo->value = aux;
            actual = nodo;
         }
      }
      else { /* Todav�a no hemos encontrado el valor, seguir busc�ndolo */
         padre = actual;
         if(dat > actual->value) actual = actual->right;
         else if(dat < actual->value) actual = actual->left;
      }
   }
}

/* Recorrido de �rbol en inorden, aplicamos la funci�n func, que tiene
   el prototipo:
   void func(int*);
*/
void InOrden(Tree a, void (*func)(int*))
{
   if(a->left) InOrden(a->left, func);
   func(&(a->value));
   if(a->right) InOrden(a->right, func);
}

/* Recorrido de �rbol en preorden, aplicamos la funci�n func, que tiene
   el prototipo:
   void func(int*);
*/
void PreOrden(Tree a, void (*func)(int*))
{
   func(&a->value);
   if(a->left) PreOrden(a->left, func);
   if(a->right) PreOrden(a->right, func);
}

/* Recorrido de �rbol en postorden, aplicamos la funci�n func, que tiene
   el prototipo:
   void func(int*);
*/
void PostOrden(Tree a, void (*func)(int*))
{
   if(a->left) PostOrden(a->left, func);
   if(a->right) PostOrden(a->right, func);
   func(&a->value);
}

/* Buscar un valor en el �rbol */
int Buscar(Tree a, int dat)
{
   pNode actual = a;

   /* Todav�a puede aparecer, ya que quedan nodos por mirar */
   while(!Vacio(actual)) {
      if(dat == actual->value) return TRUE; /* value encontrado */
      else if(dat < actual->value) actual = actual->left; /* Seguir */
      else if(dat > actual->value) actual = actual->right;
   }
   return FALSE; /* No est� en �rbol */
}

/* Calcular la altura del nodo que contiene el value dat */
int Altura(Tree a, int dat)
{
   int altura = 0;
   pNode actual = a;

   /* Todav�a puede aparecer, ya que quedan nodos por mirar */
   while(!Vacio(actual)) {
      if(dat == actual->value) return altura; /* encontrado: devolver altura */
      else {
         altura++; /* Incrementamos la altura, seguimos buscando */
         if(dat < actual->value) actual = actual->left;
         else if(dat > actual->value) actual = actual->right;
      }
   }
   return -1; /* No est� en �rbol, devolver -1 */
}

/* Contar el n�mero de nodos */
int NumeroNodos(Tree a, int *contador)
{
   *contador = 0;

   auxContador(a, contador); /* Funci�n auxiliar */
   return *contador;
}

/* Funci�n auxiliar para contar nodos. Funci�n recursiva de recorrido en
   preorden, el proceso es aumentar el contador */
void auxContador(Tree nodo, int *c)
{
   (*c)++; /* Otro nodo */
   /* Continuar recorrido */
   if(nodo->left) auxContador(nodo->left, c);
   if(nodo->right)   auxContador(nodo->right, c);
}

/* Calcular la altura del �rbol, que es la altura del nodo de mayor altura. */
int AlturaTree(Tree a, int *altura)
{
   *altura = 0;

   auxAltura(a, 0, altura); /* Funci�n auxiliar */
   return *altura;
}

/* Funci�n auxiliar para calcular altura. Funci�n recursiva de recorrido en
   postorden, el proceso es actualizar la altura s�lo en nodos hojas de mayor
   altura de la m�xima actual */
void auxAltura(pNode nodo, int a, int *altura)
{
   /* Recorrido postorden */
   if(nodo->left) auxAltura(nodo->left, a+1, altura);
   if(nodo->right)   auxAltura(nodo->right, a+1, altura);
   /* Proceso, si es un nodo hoja, y su altura es mayor que la actual del
      �rbol, actualizamos la altura actual del �rbol */
   if(EsHoja(nodo) && a > *altura) *altura = a;
}

/* Comprobar si un �rbol es vac�o */
int Vacio(Tree r)
{
   return r==NULL;
}

/* Comprobar si un nodo es hoja */
int EsHoja(pNode r)
{
   return !r->right && !r->left;
}

/* Funci�n de prueba para recorridos del �rbol */
void Mostrar(int *d)
{
   printf("%d, ", *d);
}

