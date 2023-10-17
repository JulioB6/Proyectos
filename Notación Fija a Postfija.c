#include "Operaciones.h"


/* Función principal */
int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Introduzca una expresion en notacion fija: ");
    fgets(infix, MAX_SIZE, stdin);
    infix[strlen(infix) - 1] = '\0';  /* Eliminar el caracter de nueva línea */
    infix_to_postfix(infix, postfix);
    printf("La expresion en notacion posfija es: %s\n", postfix);
    return 0;
}

