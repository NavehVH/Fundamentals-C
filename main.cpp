#include <iostream>
#include "MyListNode.h"
#include "MyStack.h"
using namespace std;

int main() {
    // ==== Linked List Demo ====
    MyListNode* head = nullptr;

    head = MyListNode::insertToEndOfList(head, 1);
    head = MyListNode::insertToEndOfList(head, 2);
    head = MyListNode::insertToEndOfList(head, 3);
    head = MyListNode::insertToEndOfList(head, 4);

    cout << "Initial list: ";
    MyListNode::printList(head);

    cout << "Length: " << MyListNode::length(head) << endl;
    cout << "Is empty? " << (MyListNode::isEmpty(head) ? "yes" : "no") << endl;

    head = MyListNode::insertToList(head, 0);
    cout << "After inserting 0 at head: ";
    MyListNode::printList(head);

    head = MyListNode::reverse(head);
    cout << "After iterative reverse: ";
    MyListNode::printList(head);

    head = MyListNode::reverseRecursive(head);
    cout << "After recursive reverse: ";
    MyListNode::printList(head);

    vector<int> arr = MyListNode::listToArray(head);
    cout << "List to array: ";
    for (int v : arr) cout << v << " ";
    cout << endl;

    cout << "2nd value from end: " << MyListNode::kValFromEnd(head, 2) << endl;

    // ==== Stack Demo ====
    MyStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "\nTop of stack: " << stack.peek() << endl;
    cout << "Popped: " << stack.pop() << endl;
    cout << "Now top: " << stack.peek() << endl;
    cout << "Stack empty? " << (stack.isEmpty() ? "yes" : "no") << endl;

    try {
        // intentionally pop too much
        stack.pop();
        stack.pop();
        stack.pop(); // will throw
    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
    }

    return 0;
}
