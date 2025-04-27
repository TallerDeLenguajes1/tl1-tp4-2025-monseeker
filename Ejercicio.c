#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50

typedef struct {
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
} Tarea;

typedef struct Nodo {
    Tarea T;
    struct Nodo *Siguiente;
} Nodo;

Nodo * crearListaVacia();
Nodo * crearNodo(char descripcion[], int duracion, int id);
void insertarNodo(Nodo **start, Nodo *nodo);
int cargarTareas(int id, Nodo ** start);
void mostrarNodos(Nodo ** start);
Nodo * buscarNodo(Nodo ** start, int id);
Nodo * quitarNodo(Nodo ** start, int id);
void moverNodo(Nodo **startRealizados, Nodo **startPendientes, int id);

int main(){
    int id=1000, aux, idTarea;
    Nodo * startPendientes = crearListaVacia();
    Nodo * startRealizadas = crearListaVacia();
    
    do
    {
        aux=cargarTareas(id, &startPendientes);
        id++;
    } while (aux != 0);

    printf("\n");
    printf("Tareas Pendientes: \n");
    mostrarNodos(&startPendientes);

    printf("Ingrese el ID de la tarea realizada: ");
    scanf("%d", &idTarea);
    getchar();
    moverNodo(&startRealizadas, &startPendientes, idTarea);
   
    
    printf("\n");
    printf("Tareas Pendientes: \n");
    mostrarNodos(&startPendientes);
    
    printf("\n");
    printf("Tareas Realizadas: \n");
    mostrarNodos(&startRealizadas);
    
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

void insertarNodo(Nodo ** start, Nodo *nodo){
    nodo->Siguiente = *start;
    *start = nodo;
}

int cargarTareas(int id, Nodo ** start){
    int duracionTarea;
        int bool;
        char buffer[MAX];

        printf("Ingrese una descripcion de la tarea: ");
        fgets(buffer, MAX, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        
        printf("Ingrese la duracion de la tarea (entre 10 y 100): ");
        scanf("%d", &duracionTarea);
        getchar();
        if (duracionTarea >= 10 && duracionTarea <= 100){
            Nodo * tareaPendiente = crearNodo(buffer, duracionTarea, id);
            insertarNodo(start, tareaPendiente);
            printf("Desea ingresar una nueva tarea? \n0. No\n1. Si\n");
            scanf("%d", &bool);
            getchar();
            return bool;
        } else {
            printf("Ingrese un numero entre 10 y 100.\n");
            return 0;
        }
        
}

void mostrarNodos(Nodo ** start){
    Nodo * AuxNodo = *start;
    while (AuxNodo)
    {
        printf("Id: %d \n", AuxNodo->T.TareaID);
        printf("Descripcion: %s\n", AuxNodo->T.Descripcion);
        printf("Duracion: %d\n", AuxNodo->T.Duracion);
        printf("\n");
        AuxNodo = AuxNodo->Siguiente;
    }
}

Nodo * buscarNodo(Nodo ** start, int id){
    Nodo * auxNodo = *start;
    while (auxNodo && auxNodo->T.TareaID != id)
    {
        auxNodo = auxNodo->Siguiente;
    }
    return auxNodo;    
}

Nodo * quitarNodo(Nodo ** start, int id){
    Nodo ** auxNodo = start;

    while (*auxNodo && (*auxNodo)->T.TareaID != id)
    {
        auxNodo = &(*auxNodo)->Siguiente;
    }



    if(*auxNodo){
        Nodo *temp = *auxNodo;
        *auxNodo = (*auxNodo)->Siguiente;
        temp->Siguiente = NULL;
        return temp;
    }
    return NULL;
    
}

void moverNodo(Nodo **startRealizados, Nodo **startPendientes, int id){
    int bool;
    Nodo * auxNodo = *startRealizados;
    Nodo * temp = buscarNodo(startPendientes, id);

    if (temp == NULL) {
        printf("Error: No se encontró el nodo con ID %d.\n", id);
        return;
    }

    if (auxNodo == NULL) {
        *startRealizados = temp;
        temp->Siguiente = NULL;
        return;
    }

    while ((auxNodo)->Siguiente != NULL)
    {
        auxNodo = auxNodo->Siguiente;
    }
    printf("\n");
    printf("Nodo a mover: \n");
    printf("    ID: %d \n", temp->T.TareaID);
    printf("    Descripcion: %s \n", temp->T.Descripcion);
    printf("    Duracion: %d \n", temp->T.Duracion);
    printf("\n");
    printf("Confirma la operacion?  0.No  1.Si \n");
    scanf("%d", &bool);
    getchar();

    if(bool){
        auxNodo->Siguiente = temp;
        temp->Siguiente = NULL;
        Nodo * eliminar = quitarNodo(startPendientes, id);
        free(eliminar);
    } 

}