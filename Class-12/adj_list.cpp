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

int main() {
    int V = 5;
    vector<int> adj[V];

    add_edge_undirected(adj, 0, 1);
    add_edge_undirected(adj, 1, 2);
    add_edge_undirected(adj, 0, 4);
    add_edge_undirected(adj, 1, 4);
    add_edge_undirected(adj, 1, 3);
    add_edge_undirected(adj, 4, 3);
    add_edge_undirected(adj, 3, 2);

    print_adj_list(adj, V);
}