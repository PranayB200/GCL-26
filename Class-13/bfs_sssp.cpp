#include<bits/stdc++.h>
using namespace std;

void add_edge_undirected(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}


vector<int> bfs_sssp(vector<vector<int>> &adj, int source) {

    int V = adj.size();

    vector<bool> visited(V, false);
    vector<int> dist(V, INT_MAX);

    queue<int> q;
    q.push(source);
    dist[source] = 0;
    visited[source] = true;

    while (!q.empty()) {

        int current = q.front();
        q.pop();

        for (int j : adj[current]) {
            if (!visited[j]) {
                visited[j] = true;
                dist[j] = dist[current] + 1;
                q.push(j);
            }
        }
    }

    return dist;
}

int main() {

    vector<vector<int>> adj(7);
    add_edge_undirected(adj, 0, 1);
    add_edge_undirected(adj, 0, 2);
    add_edge_undirected(adj, 0, 3);
    add_edge_undirected(adj, 1, 4);
    add_edge_undirected(adj, 2, 5);
    add_edge_undirected(adj, 4, 5);
    add_edge_undirected(adj, 2, 6);
    add_edge_undirected(adj, 4, 6);

    vector<int> result = bfs_sssp(adj, 0);
    for (int i = 0; i < adj.size(); i++) {
        cout << i << ": " << result[i] << endl;
    }
}