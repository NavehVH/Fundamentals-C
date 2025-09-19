#ifndef MYSTACK_H
#define MYSTACK_H

#include <stdbool.h>

#define CAPACITY 1000

typedef struct {
    int arr[CAPACITY];
    int top;
} MyStack;

// constructor
void initStack(MyStack *stack);

// methods
bool isEmpty(MyStack *stack);
void push(MyStack *stack, int val);
int peek(MyStack *stack);
int pop(MyStack *stack);

#endif
