#include <bits/stdc++.h> 
using namespace std;

class Node {

public:
    int data;
    Node *next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

Node* insert_begin(Node *head, int d) {

    Node *new_node = new Node(d);
    new_node->next = head;
    head = new_node;

    return head;
}

void print(Node *head) {
    
    Node *temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* insert_end(Node *head, int d) {

    if (head == NULL) {
        return insert_begin(head, d);
    }

    Node *temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    Node *new_node = new Node(d);
    temp->next = new_node;

    return head;
}

// If pos > size of the LL, insert at the end.
Node *insert_at_pos(Node *head, int d, int pos) {
    
    if (pos == 0) {
        return insert_begin(head, d);
    }

    Node *temp = head;
    int count = 0;

    while (temp->next != NULL and count < pos - 1) {
        temp = temp->next;
        count++;
    }

    Node *new_node = new Node(d);
    Node *orig_next = temp->next;
    temp->next = new_node;
    new_node->next = orig_next;

    return head;
}


int main() {

    Node *head = NULL; // Initially empty linked list.

    head = insert_begin(head, 3);
    head = insert_begin(head, 2);
    head = insert_begin(head, 1);

    print(head); // 1 2 3

    head = insert_end(head, 4);

    print(head); // 1 2 3 4

    head = NULL;
    head = insert_end(head, 1);
    head = insert_end(head, 2);
    head = insert_end(head, 4);
    head = insert_end(head, 5);
    head = insert_at_pos(head, 3, 5);

    print(head); // 1 2 4 5 3
}