#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct {
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
} Tarea;

typedef struct {
    Tarea T;
    struct Nodo *Siguiente;
} Nodo;

Nodo * crearListaVacia();
Nodo * crearNodo(char descripcion[], int duracion, int id);
void insertarNodo(Nodo **start, Nodo *nodo);
void mostrarNodos(Nodo ** start);

int main(){
    int aux=1, id=1000;
    Nodo * start = crearListaVacia();
    
    do
    {
        int duracionTarea;
        char buffer[MAX];

        printf("Ingrese una descripcion de la tarea: ");
        fgets(buffer, MAX, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        
        printf("Ingrese la duracion de la tarea (entte 10 y 100): ");
        scanf("%d", &duracionTarea);
        getchar();
        if (duracionTarea >= 10 && duracionTarea <= 100){
            Nodo * tareaPendiente = crearNodo(buffer, duracionTarea, id);
            insertarNodo(&start, tareaPendiente);
            printf("¿Desea ingresar una nueva tarrea? \n0. No\n1. Si\n");
            scanf("%d", &aux);
            getchar();
        } else {
            printf("Ingrese un numero entre 10 y 100.\n");
            return 0;
        }
        
        id++;
    } while (aux != 0);

    mostrarNodos(&start);
    
    
    return 0;
}

Nodo * crearListaVacia(){
    return NULL;
}

Nodo * crearNodo(char descripcion[], int duracion, int id){
    Nodo * tareaPendiente = (Nodo *) malloc(sizeof(Nodo));
    tareaPendiente->T.TareaID = id;

    tareaPendiente->T.Descripcion = (char *) malloc(strlen(descripcion)+1);
    strcpy(tareaPendiente->T.Descripcion, descripcion);

    tareaPendiente->T.Duracion = duracion;

    tareaPendiente->Siguiente = NULL;

    return tareaPendiente;
}

void insertarNodo(Nodo **start, Nodo * nodo){
    nodo->Siguiente = *start;
    *start = nodo;
}

void mostrarNodos(Nodo ** start){
    Nodo * AuxNodo = *start;
    printf("\nNodos\n");
    while (AuxNodo)
    {
        printf("Id: %d \n", AuxNodo->T.TareaID);
        printf("Descripcion: %s\n", AuxNodo->T.Descripcion);
        printf("Duracion: %d\n", AuxNodo->T.Duracion);
        printf("\n");
        AuxNodo = AuxNodo->Siguiente;
    }
}