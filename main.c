#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

// Prototipos de funciones
int menu();
void cargarPILA(Pila *pila);
void pasarPILA(Pila *origen);
void pasarPilaOrdenada(Pila *origen);
int encontrarMenor (Pila *pila);
void ordenamientoSeleccion (Pila *origen);
int encontrarMenorElemento (Pila *pila);


int main(int argc, char *argv[]) {
    int selected;
    Pila pila0,pila1;

    inicpila(&pila0);

    do {
        selected = menu();
        switch (selected) {
            case 1:
                inicpila(&pila0);
                cargarPILA(&pila0);
                system("PAUSE");
                break;
            case 2:
                inicpila(&pila0);
                cargarPILA(&pila0);
                pasarPILA(&pila0);
                system("PAUSE");
                break;
            case 3:
                inicpila(&pila0);
                cargarPILA(&pila0);
                pasarPilaOrdenada(&pila0);
                system("PAUSE");
                break;
            case 4:
                inicpila(&pila0);
                cargarPILA(&pila0);
                int menorElemento = encontrarMenor(&pila0);
                printf("El menor elemento es: %d \n", menorElemento);
                printf("La pila sin el menor elemento es: \n");
                mostrar(&pila0);
                system("PAUSE");
                break;
            case 5:
                inicpila(&pila0);
                cargarPILA(&pila0);
                ordenamientoSeleccion(&pila0);
                printf("Pila origen:");
                mostrar(&pila0);
                system("PAUSE");
                break;
            case 6:
                inicpila(&pila0);
                cargarPILA(&pila0);
                int dato;
                ordenamientoSeleccion(&pila0);
                printf("Ingrese un dato a insertar en la pila: /n");
                scanf(&dato);
                ordenamientoInsercion(&pila0, &dato);

                system("PAUSE");
                break;
            case 0:
                printf("\n\nTERMINATE THE PROGRAM\n");
                break;
            default:
                printf("\nOpción no válida. Intente nuevamente.\n");
                system("PAUSE");
                break;
        }
    } while (selected != 0);

    return 0;
}


int menu() {
    system("color 1F");
    int input;
    system("cls");
    printf("\nLABORATORIO 1");
    printf("\n----------");
    printf("\nLIST MENU");
    printf("\n-----------");
    printf("\n1- Ingresar varios elementos en una pila (cantidad indefinida por usuario).");
    printf("\n2- Hacer una función que pase todos los elementos de una pila a otra.");
    printf("\n3- Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden.");
    printf("\n4- Hacer una función que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila.");
    printf("\n5- Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección).");
    printf("\n6- Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden de ésta.");
    printf("\n0- SALIR");
    printf("\n\nIngrese su elección: ");
    scanf("%d", &input);
    return input;
}

void cargarPILA(Pila *pila){
    char respuesta;
    int dato;
    do {
        printf("\n Ingrese un numero  para la pila: \n");
        fflush(stdin);
        scanf("%d", &dato);
        apilar(pila,dato);
        printf("\n Desea ingresar otro numero? (s/n): ");
        fflush(stdin);
        scanf(" %c",&respuesta);
    } while (respuesta == 's' || respuesta == 'S');

    printf("\n Elementos en la pila después de la carga:\n");
    mostrar(pila);  // Mostrar la pila después de la carga
}


void pasarPILA(Pila *origen){
    Pila destino;
    inicpila(&destino);

    printf("Pila origen antes:\n");
    mostrar(origen);

    while (!pilavacia(origen)) {
        apilar(&destino, desapilar(origen));
    }
    printf("Pila destino:\n");
    mostrar(&destino);

    printf("Pila origen despues:\n");
    mostrar(origen);
}

void pasarPilaOrdenada(Pila *origen){
    Pila destino, aux;

    inicpila(&destino);
    inicpila(&aux);

    printf("Pila origen antes:\n");
    mostrar(origen);

    while (!pilavacia(origen)){
        apilar(&aux, desapilar(origen));
    }
    while(!pilavacia(&aux)){
        apilar(&destino, desapilar(&aux));
    }
    printf("Pila destino:\n");
    mostrar(&destino);

    printf("Pila origen despues:\n");
    mostrar(origen);
}

int encontrarMenor (Pila *pila){
    Pila aux;
    inicpila(&aux);
    int menor=tope(pila);

    //encontrar el menor
    while(!pilavacia(pila)) {
        if (tope(pila)<menor){
            menor=tope(pila);
        }
        apilar(&aux, desapilar(pila));
    }


   // Reconstruir la pila SIN el menor
    while (!pilavacia(&aux)) {
        if (tope(&aux) != menor) {  // Solo apilar si NO es el menor
            apilar(pila, desapilar(&aux));
        } else {
            desapilar(&aux);  // Eliminar el menor
        }
    }


    return menor; // Devuelve el menor eliminado
}

void ordenamientoSeleccion (Pila *origen){
    Pila destino;
    inicpila (&destino);

    while(!pilavacia(origen)){
        int elemento=encontrarMenor(origen);
        apilar(&destino, elemento);
    }
    printf("Pila destino ordenada:");
    mostrar(&destino);

    //paso elementos a la pila original
    printf("PASO DE DESTINO A ORIGEN: ");
    while (!pilavacia(&destino)) {
        apilar(origen, desapilar(&destino));
    }
    printf("Pila destino:\n");
    mostrar(&destino);
}


void insertarElemento (Pila *pila, int *dato){
    Pila aux;
    
    while(!pilavacia(pila)){
        
    }
    
    

   // Reconstruir la pila SIN el menor
    while (!pilavacia(&aux)) {
        if (tope(&aux) != menor) {  // Solo apilar si NO es el menor
            apilar(pila, desapilar(&aux));
        } else {
            desapilar(&aux);  // Eliminar el menor
        }
    }


    return menor; // Devuelve el menor eliminado
}

void ordenamientoSeleccion (Pila *origen){
    Pila destino;
    inicpila (&destino);

    while(!pilavacia(origen)){
        int elemento=encontrarMenor(origen);
        apilar(&destino, elemento);
    }
    printf("Pila destino ordenada:");
    mostrar(&destino);
}


