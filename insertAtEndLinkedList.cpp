#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// INSERT AT END
void insertAtEnd(Node* head, Node* newNode) {
    while (head->next != nullptr) {
        head = head->next;
    }
    head->next = newNode;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);

    cout << "Before insert:\n";
    display(head);

    Node* n0 = new Node(30);
    insertAtEnd(head, n0);

    cout << "After insert at end:\n";
    display(head);

    return 0;
}
