#include <bits/stdc++.h>
using namespace std;

class Node {

public:
    int data;
    Node *left;
    Node *right;

    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node *root) {

    if (root == NULL) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root) {

    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void inorder(Node *root) {

    if (root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void level_order(Node *root) {

    if (root == NULL) {
        return;
    }

    queue<Node*> q;

    q.push(root);
    while (!q.empty()) {

        Node *current_node = q.front();
        q.pop();

        cout << current_node->data << " "; 
        if (current_node->left != NULL) {
            q.push(current_node->left);
        }
        if (current_node->right != NULL) {
            q.push(current_node->right);
        }
    }
}

int main() {

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;
    
    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Lever order: ";
    level_order(root);
    cout << endl;
}