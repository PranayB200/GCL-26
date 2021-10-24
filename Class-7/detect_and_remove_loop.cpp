#include<bits/stdc++.h>
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


bool detect_loop(Node *head) {

    if (head == NULL) {
        return false;
    }

    Node *slow = head, *fast = head;
    while (fast->next != NULL and fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }
    return false;
}

void remove_loop(Node *head) {

    if (head == NULL) {
        return;
    }

    Node *slow = head, *fast = head;
    while (fast->next != NULL and fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }  

    // If the loop is not present.
    if (fast->next == NULL or fast->next->next == NULL) {
        return;
    }

    // If the linked list is completely circular.
    if (slow == head) {
        Node *ptr1 = head, *ptr2 = head;
        while (ptr2->next != ptr1) {
            ptr2 = ptr2->next;
        }

        ptr2->next = NULL;
        return;
    }

    Node *ptr1 = head;
    Node *ptr2 = slow;

    while (ptr1->next != ptr2->next) {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    ptr2->next = NULL;
}


int main() {

    Node *head = new Node(1);
    head = insert_end(head, 2);
    head = insert_end(head, 3);
    head = insert_end(head, 4);
    head = insert_end(head, 5);

    cout << detect_loop(head) << endl; // Loop not present.

    head->next->next->next->next->next = head->next->next;
    cout << detect_loop(head) << endl; // Loop present.

    remove_loop(head);
    cout << detect_loop(head) << endl;
}