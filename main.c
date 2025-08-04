#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1   
  // la funcion main termina con éxito

  typedef struct node {
      char info;
      struct node * link;
  } NODE;


  /*
   *  crea un nodo de list2a
   */

  NODE * new(char v) {

      NODE * node = (NODE *) malloc(sizeof(NODE));        // obtiene el siguiente nodo en el HEAP

      if(node == NULL) {
          printf("ERROR: No hay memoria disponible\n");
          exit(1);                                        // abandonamos el programa!

      } else {
          node  ->  info = v;                                 // inicializa y liga el nuevo nodo
          return node;
      }
  }


  /*
   *  crea el primer nodo de una lista
   */

  NODE * create_list() {

      NODE * node = new('0');                          // elemento HEAD
      node  ->  link = node;                           // la cabeza se apunta a si misma

      return node;
  }

  /*
   *  inserta un nuevo nodo con el valor v al inicio de la lista
   */

  void insertBeginning(NODE * l, char v) {

      NODE * node = new(v);                          // nuevo nodo

      node -> link = l -> link;                      // lo inserta como primer elemento
      l -> link = node;
  }

  /*
   *  inserta un nuevo nodo con el valor v al final de la lista
   */

  void insertEnd(NODE * l, char v) {
    
      NODE * node = new(v);
      NODE * temp = l;
    
      // encuentra el último nodo
      while (temp -> link != l) {
          temp = temp->link;
      }
    
      temp -> link = node;
      node -> link = l; // hace que el nuevo nodo apunte a la cabeza
  }

  NODE * find(NODE * l, char v) {

      // inicializa la búsqueda del nodo con el valor v
      NODE * node = l -> link;                              // saltar el nodo cabeza

      while(node != l) {
          // verificar si es el nodo
          if(node -> info == v) {
              return node;
          }
          // pasar al siguiente nodo
          node = node -> link;
      }

      // el nodo con valor v no estÃ¡ en la list2a
      return NULL;
  }


  NODE * get(NODE * l, int p) {

      // inicializa la búsqueda del nodo en la posición p
      NODE * node = l -> link;                              // saltar el nodo cabeza

      for(int i = 0; i <= p - 1; i++){
          // verifica si hay mÃ¡s nodos
          if(node == l) {
              return NULL;
          }

          // pasa al siguiente nodo
          node = node -> link;
      }

      // regresa el nodo en la posición P
      return node;
  }


  void delete(NODE * l, NODE * e) {

      // Â¿Lista vacía?
      if(l == l -> link) {
          printf("Lista vacía\n");
          return;
      }

      // Inicializa la búsqueda del nodo X
      NODE * node = l -> link, * pred = l;

      // Mientras no sea el nodo buscado
      while(node != l && node != e) {
          // Pasa al siguiente nodo
          pred = node;
          node = node -> link;
      }

      // Verifica si el elemento fue encontrado
      if(node == l) {
          printf("Nodo no encontrado\n");

      } else {

          // Elimina el nodo X
          pred -> link = e -> link;             // equivalente a poner node -> link

          // Regresa el nodo a memoria libre del SO
          free(e);                              // tambiÃ©n podemos pasar la variable node!
      }
  }


  void display(NODE * l, char * message) {
      NODE * node = l -> link;                                 // saltar el nodo cabeza
      printf("\n%s\n", message);

      while(node != l) {
          printf("El valor del elemento es: %c\n", node -> info);
          node = node -> link;
      }
  }


  NODE * cloneList(NODE * l){
    NODE * cloneListNode = create_list(), * temp = l;

    while (temp -> link != l){
      temp = temp -> link;
      insertEnd(cloneListNode, temp -> info);
    };
    
    return cloneListNode;
  }


  int main() {

    printf("\n\n\t Lista para insertar los nodos al inicio \n\n");
    
    NODE * list = create_list();                       // lista vacia

    insertBeginning(list, 'G');
    insertBeginning(list, 'F');
    insertBeginning(list, 'E');
    insertBeginning(list, 'D');
    insertBeginning(list, 'C');
    insertBeginning(list, 'B');
    insertBeginning(list, 'A');

    NODE * e = get(list, 0);
    printf("Dirección del elemento; %p\n", e);

    if(e != NULL) {
        printf("El valor del elemento es: %c\n", e -> info);
    }

    e = get(list, 3);
    printf("Dirección del elemento; %p\n", e);

    if(e != NULL) {
        printf("El valor del elemento es: %c\n", e -> info);
    }

    display(list, "Imprimir todos los valores iniciales");

    delete(list,find(list, 'A'));
    display(list, "Imprimir todos los valores después de borrar A");

    delete(list,find(list, 'F'));
    display(list, "Imprimir todos los valores después de borrar F");

    delete(list,find(list, 'L'));
    display(list, "Imprimir todos los valores después de borrar L");

    printf("\n");

    printf("Tamaño de un nodo: %li\n", sizeof(NODE));                    // 16 bytes
    printf("Tamaño de un nodo: %li\n", sizeof(NODE *));                  //  8 bytes
    printf("Tamaño de un nodo: %li\n", sizeof(struct node *));           //  8 bytes


    printf("\n\n\n");
    printf("\t Lista para insertar los nodos al final \n\n");
    
    NODE * list2 = create_list();

    insertEnd(list2, 'A');
    insertEnd(list2, 'B');
    insertEnd(list2, 'C');
    insertEnd(list2, 'D');
    insertEnd(list2, 'E');
    insertEnd(list2, 'F');
    insertEnd(list2, 'G');
    
      e = get(list2, 0);
      printf("Dirección del elemento; %p\n", e);

      if(e != NULL) {
          printf("El valor del elemento es: %c\n", e -> info);
      }

      e = get(list2, 3);
      printf("Dirección del elemento; %p\n", e);

      if(e != NULL) {
          printf("El valor del elemento es: %c\n", e -> info);
      }

      display(list2, "Imprimir todos los valores iniciales");

      delete(list2,find(list2, 'A'));
      display(list2, "Imprimir todos los valores después de borrar A");

      delete(list2,find(list2, 'F'));
      display(list2, "Imprimir todos los valores después de borrar F");

      delete(list2,find(list2, 'L'));
      display(list2, "Imprimir todos los valores después de borrar L");

      printf("\n");

      printf("Tamaño de un nodo: %li\n", sizeof(NODE));                    // 16 bytes
      printf("Tamaño de un nodo: %li\n", sizeof(NODE *));                  //  8 bytes
      printf("Tamaño de un nodo: %li\n", sizeof(struct node *));           //  8 bytes


    // se crea una lista clon y se copia la lista
    NODE * listCopy = cloneList(list);
    display(listCopy, "\n Imprimir la lista clonada \n");

    return SUCCESS;             // regresa el control al sistema operativo!
}