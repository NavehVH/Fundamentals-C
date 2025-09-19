#ifndef MYSTACK_H
#define MYSTACK_H

#include <stdexcept>

class MyStack {
private:
    static const int CAPACITY = 1000;
    int arr[CAPACITY];
    int top;

public:
    // constructor
    MyStack();

    // methods
    bool isEmpty() const;
    void push(int val);
    int peek() const;
    int pop();
};

#endif // MYSTACK_H
