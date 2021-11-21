#include<bits/stdc++.h>
using namespace std;

void add_edge_directed(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
}

bool is_cyclic_util(vector<vector<int>> &adj, int current, vector<bool> &visited, vector<bool> &rec_stack) {

    if (visited[current]) {
        return false;
    }

    visited[current] = true;
    rec_stack[current] = true;

    for (int j : adj[current]) {
        
        // If an adjacent node is already present in the recursive stack, then it means
        // that the cycle exists.
        if (rec_stack[j]) {
            return true;
        }

        // Checking for all of the adjacent nodes.
        if (is_cyclic_util(adj, j, visited, rec_stack)) {
            return true;
        }
    }

    rec_stack[current] = false; // Removing the current node from rec_stack just before backtracking.
    return false;
}

bool is_cyclic(vector<vector<int>> &adj) {

    int V = adj.size();
    vector<bool> visited(V, false);
    vector<bool> rec_stack(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (is_cyclic_util(adj, i, visited, rec_stack)) {
                return true;
            }
        }
    }
    return false;
}

int main() {

    vector<vector<int>> adj1(3);
    add_edge_directed(adj1, 0, 1);
    add_edge_directed(adj1, 0, 2);
    add_edge_directed(adj1, 1, 2);

    cout << is_cyclic(adj1) << endl;

    vector<vector<int>> adj2(3);
    add_edge_directed(adj2, 0, 1);
    add_edge_directed(adj2, 2, 0);
    add_edge_directed(adj2, 1, 2);

    cout << is_cyclic(adj2) << endl;

    
}