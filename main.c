#include <stdio.h>
#include "my_stack.h"


int main() {
    MyStack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", peek(&stack));
    printf("Popped element: %d\n", pop(&stack));
    printf("Now top element: %d\n", peek(&stack));

    return 0;
}
