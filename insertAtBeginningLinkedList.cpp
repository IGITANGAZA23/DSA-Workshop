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

// INSERT AT BEGINNING
void insertAtBeginning(Node*& head, Node* newNode) {
    newNode->next = head;
    head = newNode;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);

    cout << "Before insert:\n";
    display(head);

    Node* n0 = new Node(5);  // Insert this node
    insertAtBeginning(head, n0);

    cout << "After insert at beginning:\n";
    display(head);

    return 0;
}
