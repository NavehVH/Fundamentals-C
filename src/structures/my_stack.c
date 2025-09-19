#include <stdio.h>
#include <stdlib.h>
#include "my_stack.h"

void initStack(MyStack *stack) {
    stack->top = -1;
}

bool isEmpty(MyStack *stack) {
    return stack->top == -1;
}

void push(MyStack *stack, int val) {
    if (stack->top >= CAPACITY - 1) {
        printf("Error: Stack is at max capacity.\n");
        exit(EXIT_FAILURE);
    }
    stack->arr[++(stack->top)] = val;
}

int peek(MyStack *stack) {
    if (isEmpty(stack)) {
        printf("Error: Empty Stack.\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top];
}

int pop(MyStack *stack) {
    if (isEmpty(stack)) {
        printf("Error: Already Empty Stack.\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[(stack->top)--];
}