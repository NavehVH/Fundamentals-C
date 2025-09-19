#ifndef MYLISTNODE_H
#define MYLISTNODE_H

#include <vector>
#include <iostream>

class MyListNode {
private:
    int val;
    MyListNode* next;

    MyListNode(int v, MyListNode* n);

public:
    static bool isEmpty(MyListNode* head);
    static int length(MyListNode* head);
    static void printList(MyListNode* head);

    static MyListNode* insertToList(MyListNode* head, int x);
    static MyListNode* insertToEndOfList(MyListNode* head, int x);

    static std::vector<int> listToArray(MyListNode* head);

    static MyListNode* reverse(MyListNode* head);
    static MyListNode* reverseRecursive(MyListNode* head);
    static MyListNode* middleNode(MyListNode* head);
    static int kValFromEnd(MyListNode* head, int k);
};

#endif // MYLISTNODE_H