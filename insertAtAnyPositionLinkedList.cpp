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

// INSERT AT ANY POSITION (1-based index)
void insertAtPosition(Node*& head, Node* newNode, int position) {

    // Insert at beginning if position == 1
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    int count = 1;

    // Move until the node BEFORE insertion position
    while (temp != nullptr && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Position out of range.\n";
        return;
    }

    // Insert node
    newNode->next = temp->next;
    temp->next = newNode;
}

int main() {

    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout << "Before insertion:\n";
    display(head);

    Node* n0 = new Node(15);
    insertAtPosition(head, n0, 2);   // insert at position 2

    cout << "After inserting at position 2:\n";
    display(head);

    return 0;
}
