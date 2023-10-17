
#include "hanoiii.h"

// Función principal
int main() {
    int n;
    printf("Ingrese el numero de discos (5, 7 o 10): ");
    scanf("%d", &n);
    resolver_hanoi(n);
    return 0;
}

