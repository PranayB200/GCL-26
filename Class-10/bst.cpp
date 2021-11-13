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


// ---------------- Searching a Node in a BST ----------------
bool search(Node *root, int val) {

    if (root == NULL) {
        return false;
    }

    if (root->data == val) {
        return true;
    }

    if (root->data > val) {
        return search(root->left, val);
    }

    return search(root->right, val);
}
// ----------------------------------------------------------------

// ---------------- Insert a Node in a BST ----------------
Node* insert(Node *root, int val) {

    if (root == NULL) {
        return new Node(val);
    }

    if (root->data < val) { // Insert in the right subtree.
        root->right = insert(root->right, val);
    }
    else if (root->data > val) { // Insert in the left subtree.
        root->left = insert(root->left, val);
    }

    return root;
}
// ----------------------------------------------------------------


// ---------------- Delete a Node from a BST ----------------

int minimum_value(Node *root) {

    while (root->left != NULL) {
        root = root->left;
    }

    return root->data;
}

Node* delete_node(Node *root, int val) {

    if (root == NULL) {
        return NULL;
    }

    if (root->data > val) {
        root->left = delete_node(root->left, val);
    }
    else if (root->data < val) {
        root->right = delete_node(root->right, val);
    }
    else { // root->data == val

        if (root->left == NULL and root->right == NULL) {
            return NULL;
        }
        if (root->left == NULL) { // and root->right != NULL
            return root->right;
        }
        if (root->right == NULL) { // and root->left != NULL
            return root->left;
        }

        // If root->left != NULL and root->right != NULL. 2 child nodes case
        int succ_value = minimum_value(root->right);
        root->data = succ_value;
        root->right = delete_node(root->right, succ_value);
    }

    return root;
}

// ----------------------------------------------------------------

// ---------------- Check if BST ----------------

bool is_BST_helper(Node *root, int min, int max) {

    if (root == NULL) {
        return true;
    }

    if (root->data < min or root->data > max) {
        return false;
    }

    return is_BST_helper(root->left, min, root->data - 1) && 
           is_BST_helper(root->right, root->data + 1, max);
}

bool is_BST(Node *root) {

    return is_BST_helper(root, -1000000, 1000000);
}

// ----------------------------------------------------------------

// ---------------- Sorted array to BST ----------------

Node* sorted_array_to_BST_helper(vector<int> &arr, int low, int high) {

    if (low > high) {
        return NULL;
    }

    int mid = (low + high) / 2;
    Node *root = new Node(arr[mid]);

    root->left = sorted_array_to_BST_helper(arr, low, mid - 1);
    root->right = sorted_array_to_BST_helper(arr, mid + 1, high);

    return root;
}

Node* sorted_array_to_BST(vector<int> arr) {

    return sorted_array_to_BST_helper(arr, 0, arr.size() - 1);
}

// ----------------------------------------------------------------

int main() {

    Node *rt = new Node(4);
    rt->left = new Node(2);
    rt->left->left = new Node(1);
    rt->left->right = new Node(3);
    rt->right = new Node(6);
    rt->right->left = new Node(5);
    rt->right->right = new Node(8);

    cout << "Search 3: " << search(rt, 3) << endl;
    cout << "Search 5: " << search(rt, 5) << endl;
    cout << "Search 7: " << search(rt, 7) << endl;

    rt = insert(rt, 7);
    cout << "7 Inserted!" << endl;

    cout << "Search 7: " << search(rt, 7) << endl;

    rt = delete_node(rt, 7); // Case-1: 0 child nodes.
    cout << "7 deleted!" << endl;

    cout << "Search 7: " << search(rt, 7) << endl;

    rt = delete_node(rt, 5); // Case-1: 0 child nodes.
    cout << "5 deleted!" << endl;

    cout << "Search 5: " << search(rt, 5) << endl;

    rt = delete_node(rt, 6); // Case-2: 1 child node.
    cout << "6 deleted!" << endl;

    cout << "Search 6: " << search(rt, 6) << endl;

    rt = delete_node(rt, 2); // Case-3: 2 child nodes.
    cout << "2 deleted!" << endl;

    cout << "Search 2: " << search(rt, 2) << endl;

    cout << "Preorder: ";
    preorder(rt);
    cout << endl;
    cout << "Inorder: ";
    inorder(rt);
    cout << endl;

    cout << "Check if BST: " << is_BST(rt) << endl;

    Node *rt2 = new Node(4);
    rt2->left = new Node(2);
    rt2->left->left = new Node(1);
    rt2->left->right = new Node(5);
    rt2->right = new Node(6);
    cout << "Check if BST: " << is_BST(rt2) << endl;

    Node *root = sorted_array_to_BST({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
}