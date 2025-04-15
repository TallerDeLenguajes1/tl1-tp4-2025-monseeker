#include <stdio.h>
#include <stdlib.h>
#define N 1000

struct {
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
} typedef Tarea;

struct {
    Tarea T;
    Nodo *Siguiente;
} typedef Nodo;

Nodo * crearListaVacia();
Nodo * crearNodo(int num, char * descripcion, int duracion);

int main(){
    int nuevoDato, duracion, id = 1000;
    char * descripcion;
    Nodo * ToDo = crearListaVacia();
    do
    {
        printf("Ingrese una descripcion de la tarea: ");
        scanf("%s", descripcion);
        printf("Ingrese la duracion de la tarea: ");
        scanf("%d", &duracion);
        crearNodo(id, descripcion, duracion);
        printf("¿Desea ingresar una nueva tarea? \n1. Si\2. No");
        scanf("%d", &nuevoDato);
        id++;
    } while (nuevoDato != 0);
    


    return 0;
}

Nodo * crearListaVacia(){
    return NULL;
}

Nodo * crearNodo(int id, char * descripcion, int duracion){
    Nodo * nodo = (Nodo *) malloc(sizeof(Nodo));
    nodo->T.TareaID = id;
    nodo->T.Descripcion = descripcion;
    nodo->T.Duracion = duracion;
    nodo->Siguiente = NULL;
    return nodo;
}