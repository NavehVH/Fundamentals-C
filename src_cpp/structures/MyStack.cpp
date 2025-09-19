#include "include/MyStack.h"
#include <stdexcept>

// constructor
MyStack::MyStack() : top(-1) {}

// isEmpty
bool MyStack::isEmpty() const {
    return top == -1;
}

// push
void MyStack::push(int val) {
    if (top >= CAPACITY - 1) {
        throw std::overflow_error("Stack is at max capacity.");
    }
    arr[++top] = val;
}

// peek
int MyStack::peek() const {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty.");
    }
    return arr[top];
}

// pop
int MyStack::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty.");
    }
    return arr[top--];
}
