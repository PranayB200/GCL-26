#include<bits/stdc++.h>
using namespace std;

void add_edge_directed(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
}

void topological_sort_util(vector<vector<int>> &adj, int current, vector<bool> &visited, stack<int> &helper) {

    if (visited[current]) {
        return;
    }
    visited[current] = true;

    for (int j : adj[current]) {
        topological_sort_util(adj, j, visited, helper);
    }

    helper.push(current);
}

vector<int> topological_sort(vector<vector<int>> &adj) {

    int V = adj.size();
    vector<bool> visited(V, false);
    stack<int> helper;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topological_sort_util(adj, i, visited, helper);
        }
    }

    vector<int> result;
    while (!helper.empty()) {
        result.push_back(helper.top());
        helper.pop();
    }

    return result;
}

int main() {

    vector<vector<int>> adj(6);
    add_edge_directed(adj, 5, 0);
    add_edge_directed(adj, 4, 0);
    add_edge_directed(adj, 4, 1);
    add_edge_directed(adj, 3, 1);
    add_edge_directed(adj, 2, 3);
    add_edge_directed(adj, 5, 2);

    vector<int> result = topological_sort(adj);
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
}