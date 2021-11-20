#include<bits/stdc++.h>
using namespace std;

void add_edge_undirected(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void print_adj_list(vector<int> adj[], int V) {

    for (int i = 0; i < V; i++) {
        cout << i << " -> ";
        for (int j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << endl;
}

void dfs_util(vector<int> adj[], int current, vector<bool> &visited) {

    if (visited[current]) {
        return;
    }
    cout << current << " ";
    visited[current] = true;

    for (int j : adj[current]) {
        dfs_util(adj, j, visited);
    }
}

void dfs(vector<int> adj[], int V) {
    vector<bool> visited(V, false);

    cout << "DFS: ";
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs_util(adj, i, visited);
        }
    }
    cout << endl;
}

int main() {
    int V = 7;
    vector<int> adj[V];

    add_edge_undirected(adj, 0, 1);
    add_edge_undirected(adj, 1, 2);
    add_edge_undirected(adj, 0, 4);
    add_edge_undirected(adj, 1, 4);
    add_edge_undirected(adj, 1, 3);
    add_edge_undirected(adj, 4, 3);
    add_edge_undirected(adj, 3, 2);
    add_edge_undirected(adj, 5, 6);

    print_adj_list(adj, V);

    dfs(adj, V);
}