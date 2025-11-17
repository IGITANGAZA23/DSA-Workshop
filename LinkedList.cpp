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

int main() {

    // Create nodes
    Node* n1 = new Node(10);
    Node* n2 = new Node(20);
    Node* n3 = new Node(30);
    Node* n0 = new Node(40);

    // Build the linked list: n0 → n1 → n2 → n3
    n0->next = n1;
    n1->next = n2;
    n2->next = n3;

    // Display
    display(n0);

    return 0;
}
