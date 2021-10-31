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

int height(Node *root) {

    if (root == NULL) {
        return 0;
    }

    int left_subtree_height = height(root->left);
    int right_subtree_height = height(root->right);

    return 1 + max(left_subtree_height, right_subtree_height);
}

// -------------------------------------

unordered_map<Node*, int> heights;
int height_precompute(Node *root) {
    if (root == NULL) {
        return 0;
    }

    if (heights.find(root) != heights.end()) {
        return heights[root];
    }

    int left_subtree_height = height_precompute(root->left);
    int right_subtree_height = height_precompute(root->right);

    return heights[root] = 1 + max(left_subtree_height, right_subtree_height);
}

int diameter(Node *root) {

    if (root == NULL) {
        return 0;
    }

    int ld = diameter(root->left);
    int rd = diameter(root->right);

    int lh = height_precompute(root->left);
    int rh = height_precompute(root->right);

    return max({ld, rd, lh + rh + 1});
}

// -------------------------------------

int return_height_get_diam(Node *root, int &res) {

    if (root == NULL) {
        return 0;
    }

    int left_subtree_height = return_height_get_diam(root->left, res);
    int right_subtree_height = return_height_get_diam(root->right, res);

    res = max(res, left_subtree_height + right_subtree_height + 1);

    return 1 + max(left_subtree_height, right_subtree_height);
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

    cout << "Height: " << height(root) << endl;

    cout << "Diameter: " << diameter(root) << endl;

    int diam = 0;
    return_height_get_diam(root, diam);
    cout << "Diameter: " << diam << endl;
}
