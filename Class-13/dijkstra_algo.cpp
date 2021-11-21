#include<bits/stdc++.h>
using namespace std;

void add_edge_undirected(vector<vector<int>> &adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

vector<int> dijkstra(vector<pair<int,int>> adj[], int V, int source) {

    // Create a min heap of pair<int,int>
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(V, INT_MAX);

    dist[source] = 0;
    pq.push({dist[source], source}); // {dist[i], i}

    while (!pq.empty()) {

        pair<int,int> temp = pq.top();
        pq.pop();

        int u = temp.second;
        int dist_u = temp.first;

        for (pair<int,int> neighbour : adj[u]) {
            int v = neighbour.first;
            int edge_wt = neighbour.second;

            if (dist[v] > dist[u] + edge_wt) {
                dist[v] = dist[u] + edge_wt;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {


}