#include "MyListNode.h"
using namespace std;

MyListNode::MyListNode(int v, MyListNode* n) : val(v), next(n) {}

bool MyListNode::isEmpty(MyListNode* head) {
    return head == nullptr;
}

// length
int MyListNode::length(MyListNode* head) {
    int len = 0;
    for (MyListNode* t = head; t != nullptr; t = t->next) {
        len++;
    }
    return len;
}

// printList
void MyListNode::printList(MyListNode* head) {
    for (MyListNode* c = head; c != nullptr; c = c->next) {
        cout << c->val << " -> ";
    }
    cout << "null" << endl;
}

// insert at head
MyListNode* MyListNode::insertToList(MyListNode* head, int x) {
    return new MyListNode(x, head);
}

// insert at end
MyListNode* MyListNode::insertToEndOfList(MyListNode* head, int x) {
    if (head == nullptr) return new MyListNode(x, nullptr);
    MyListNode* t = head;
    while (t->next != nullptr) {
        t = t->next;
    }
    t->next = new MyListNode(x, nullptr);
    return head;
}

// listToArray
vector<int> MyListNode::listToArray(MyListNode* head) {
    vector<int> arr;
    for (MyListNode* t = head; t != nullptr; t = t->next) {
        arr.push_back(t->val);
    }
    return arr;
}

// reverse (iterative)
MyListNode* MyListNode::reverse(MyListNode* head) {
    MyListNode* prev = nullptr;
    MyListNode* cur = head;
    while (cur != nullptr) {
        MyListNode* after = cur->next;
        cur->next = prev;
        prev = cur;
        cur = after;
    }
    return prev;
}

// reverseRecursive
MyListNode* MyListNode::reverseRecursive(MyListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    MyListNode* newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}

// middleNode (cut the list)
MyListNode* MyListNode::middleNode(MyListNode* head) {
    MyListNode* slow = head;
    MyListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (slow != nullptr) {
        slow->next = nullptr; // cut
    }
    return slow;
}

// kValFromEnd
int MyListNode::kValFromEnd(MyListNode* head, int k) {
    if (head == nullptr || k <= 0) return -1;

    MyListNode* slow = head;
    MyListNode* fast = head;

    for (int i = 0; i < k; i++) {
        if (fast == nullptr) return -1; // k > length
        fast = fast->next;
    }

    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow->val;
}
