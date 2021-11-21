#include<bits/stdc++.h>
using namespace std;

void add_edge_undirected(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}


bool is_cyclic_util(vector<vector<int>> &adj, int current, int parent, vector<bool> &visited) {

    visited[current] = true;

    for (int j : adj[current]) {

        // If there is a visited adjacent node which is not the parent of the current node,
        // then the cycle exists and we will return true.
        if (visited[j] and j != parent) {
            return true;
        }

        // Making a recursive to all of the unvisited adjacent nodes.
        // If any of those recursive calls return true, then the cycle exists.
        if (!visited[j]) {
            if (is_cyclic_util(adj, j, current, visited)) {
                return true;
            }
        }
    }

    return false;
}

bool is_cyclic(vector<vector<int>> &adj) {

    int V = adj.size();
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (is_cyclic_util(adj, i, -1, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<int>> adj1(5);
    add_edge_undirected(adj1, 0, 1);
    add_edge_undirected(adj1, 0, 3);
    add_edge_undirected(adj1, 2, 3);
    add_edge_undirected(adj1, 1, 2);
    add_edge_undirected(adj1, 1, 4);
    
    cout << is_cyclic(adj1) << endl;

    vector<vector<int>> adj2(5);
    add_edge_undirected(adj2, 0, 1);
    add_edge_undirected(adj2, 2, 3);
    add_edge_undirected(adj2, 1, 2);
    add_edge_undirected(adj2, 1, 4);
    
    cout << is_cyclic(adj2) << endl;

    
}