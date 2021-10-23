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

Node *delete_begin(Node *head) {
    if (head == NULL) {
        return head;
    }
    head = head->next;

    return head;
}

Node *delete_end(Node *head) {

    if (head == NULL or head->next == NULL) {
        return NULL;
    }

    Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    temp->next = NULL;

    return head;
}

Node *delete_at_pos(Node *head, int pos) {
    if (pos == 0) {
        return delete_begin(head);
    }

    Node *temp = head;
    int count = 0;

    while (temp->next != NULL and count < pos - 1) {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL) {
        return head;
    }

    temp->next = temp->next->next;
    return head;
}

Node *reverse_iterative(Node *head) {
    
    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL) {
        Node *next_node = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next_node;
    }

    return prev;
}

Node *reverse_recursive(Node *head) {

    if (head == NULL or head->next == NULL) {
        return head;
    }

    Node *new_head = reverse_recursive(head->next); // Getting the result of a similar subproblem.

    // Using the result of the subproblem to generate the result of the original problem.
    Node *temp = new_head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    head->next = NULL;
    temp->next = head;

    return new_head;
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

    head = NULL;
    head = insert_end(head, 1);
    head = insert_end(head, 2);
    head = insert_end(head, 3);
    head = insert_end(head, 4);

    cout << "Before Reversing: ";
    print(head);

    head = reverse_iterative(head);
    cout << "After Reversing: ";
    print(head);


    cout << "Before Reverseing: ";
    print(head);

    head = reverse_recursive(head);
    cout << "After Reversing: ";
    print(head);
}