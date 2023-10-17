#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_SIZE 100

/* Definición de la pila */
struct Stack {
    int top;
    char items[MAX_SIZE];
};

/* Funciones para la pila */
void push(struct Stack* stack, char item) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Error: la pila esta llena.\n");
        exit(1);
    }
    stack->top++;
    stack->items[stack->top] = item;
}

char pop(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Error: la pila esta vacia.\n");
        exit(1);
    }
    char item = stack->items[stack->top];
    stack->top--;
    return item;
}

char peek(struct Stack* stack) {
    if (stack->top == -1) {
        printf("Error: la pila esta vacia.\n");
        exit(1);
    }
    return stack->items[stack->top];
}

int is_empty(struct Stack* stack) {
    return stack->top == -1;
}

/* Función para determinar la precedencia de los operadores */
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return -1;
    }
}

/* Función para convertir de notación fija a posfija */
void infix_to_postfix(char* infix, char* postfix) {
    struct Stack stack;
    stack.top = -1;
    int i, j;
    char ch;
    for (i = 0, j = 0; infix[i] != '\0'; i++) {
        ch = infix[i];
        if (isalnum(ch)) {
            postfix[j] = ch;
            j++;
        }
        else if (ch == '(') {
            push(&stack, ch);
        }
        else if (ch == ')') {
            while (!is_empty(&stack) && peek(&stack) != '(') {
                postfix[j] = pop(&stack);
                j++;
            }
            if (!is_empty(&stack) && peek(&stack) != '(') {
                printf("Error: expresion incorrecta.\n");
                exit(1);
            }
            else {
                pop(&stack);
            }
        }
        else {
            while (!is_empty(&stack) && precedence(ch) <= precedence(peek(&stack))) {
                postfix[j] = pop(&stack);
                j++;
            }
            push(&stack, ch);
        }
    }
    while (!is_empty(&stack)) {
        postfix[j] = pop(&stack);
        j++;
    }
    postfix[j] = '\0';
}

