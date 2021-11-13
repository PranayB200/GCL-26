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

// -------- Build tree using inorder and preorder --------------
Node* build_tree_helper(vector<int> &in, int in_start, int in_end, vector<int> &pre, int &pre_index) {

    if (in_start > in_end) {
        return NULL;
    }

    Node *root = new Node(pre[pre_index]);
    pre_index++;

    int i = in_start;
    for (int j = in_start + 1; j <= in_end; j++) {
        if (in[j] == root->data) {
            i = j;
            break;
        }
    }

    root->left = build_tree_helper(in, in_start, i - 1, pre, pre_index);
    root->right = build_tree_helper(in, i + 1, in_end, pre, pre_index);

    return root;
}

Node* build_tree(vector<int> in, vector<int> pre) {

    int pre_index = 0;
    return build_tree_helper(in, 0, in.size() - 1, pre, pre_index);
}
// ------------------------------------------------------------------


// ---------------------- Iterative Inorder ----------------------

void push_left(Node *root, stack<Node*> &s) {

    while (root != NULL) {
        s.push(root);
        root = root->left;
    }
}

vector<int> iterative_inorder(Node *root) {

    vector<int> result;

    stack<Node*> s;
    push_left(root, s);

    while (!s.empty()) {

        Node *current = s.top();
        s.pop();

        result.push_back(current->data);
        push_left(current->right, s);
    }

    return result;
}

// ------------------------------------------------------------------

int main() {

    vector<int> in = {3, 1, 4, 0, 5, 2};
    vector<int> pre = {0, 1, 3, 4, 2, 5};

    Node *root = build_tree(in, pre);
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    vector<int> inorder_arr = iterative_inorder(root);
    cout << "Iterative Inorder: ";
    for (int i : inorder_arr) {
        cout << i << " ";
    }
    cout << endl;
}