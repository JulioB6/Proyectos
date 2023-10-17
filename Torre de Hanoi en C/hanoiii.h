#include <stdio.h>
#include <stdlib.h>

// Definición de la estructura Nodo para la pila
struct Nodo {
    int disco;
    int torre_origen;
    int torre_destino;
    struct Nodo* siguiente;
};

// Función para crear un nuevo nodo
struct Nodo* crear_nodo(int disco, int origen, int destino) {
    struct Nodo* nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
    nodo->disco = disco;
    nodo->torre_origen = origen;
    nodo->torre_destino = destino;
    nodo->siguiente = NULL;
    return nodo;
}

// Función para insertar un nuevo nodo en la pila
void insertar_nodo(struct Nodo** pila, struct Nodo* nodo) {
    nodo->siguiente = *pila;
    *pila = nodo;
}

// Función para eliminar un nodo de la pila
struct Nodo* eliminar_nodo(struct Nodo** pila) {
    if (*pila == NULL) {
        return NULL;
    }
    struct Nodo* temp = *pila;
    *pila = (*pila)->siguiente;
    return temp;
}

// Función para imprimir un movimiento
void imprimir_movimiento(int disco, int origen, int destino) {
    printf("Mover disco %d de torre %d a torre %d\n", disco, origen, destino);
}

// Función recursiva para resolver el juego de las Torres de Hanoi
void hanoi(int n, int origen, int auxiliar, int destino, struct Nodo** pila) {
    if (n == 1) {
        insertar_nodo(pila, crear_nodo(1, origen, destino));
        imprimir_movimiento(1, origen, destino);
    } else {
        hanoi(n - 1, origen, destino, auxiliar, pila);
        insertar_nodo(pila, crear_nodo(n, origen, destino));
        imprimir_movimiento(n, origen, destino);
        hanoi(n - 1, auxiliar, origen, destino, pila);
    }
}

// Función para resolver el juego de las Torres de Hanoi
void resolver_hanoi(int n) {
    struct Nodo* pila = NULL;
    hanoi(n, 1, 2, 3, &pila);
    while (pila != NULL) {
        struct Nodo* nodo = eliminar_nodo(&pila);
        imprimir_movimiento(nodo->disco, nodo->torre_origen, nodo->torre_destino);
        free(nodo);
    }
}
