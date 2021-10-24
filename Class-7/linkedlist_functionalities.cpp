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

/*

Even Lengthed Linked List:
1 -> 2 -> 3 -> 4 -> NULL

If we want 3 as the output: while (fast != NULL and fast->next != NULL)
If we want 2 as the output: while (fast->next != NULL and fast->next->next != NULL)

*/

Node *get_middle(Node *head) {

    if (head == NULL) {
        return head;
    }

    Node *slow = head, *fast = head;

    while (fast->next != NULL and fast->next->next != NULL) {

        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;    
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

bool check_palindrome(Node *head) {

    if (head == NULL or head->next == NULL) {
        return true;
    }

    Node *mid = get_middle(head);
    Node *head2 = mid->next;
    mid->next = NULL;

    head2 = reverse_iterative(head2);

    while (head2 != NULL) {
        if (head->data != head2->data) {
            return false;
        }

        head = head->next;
        head2 = head2->next;
    }

    return true;
}

int main() {

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // LL: 1 -> 2 -> 3 -> 4 -> NULL
    cout << get_middle(head)->data << endl; 

    head->next->next->next->next = new Node(5);

    // LL: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    cout << get_middle(head)->data << endl;


    // Check Palindrome.
    head = new Node(1); 
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    cout << check_palindrome(head) << endl;

    head = new Node(1); 
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    cout << check_palindrome(head) << endl;
}