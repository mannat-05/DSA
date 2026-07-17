#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> graph = {{0,1,1}, {0,2,4}, {1,3,2}, {1,4,6}, {2,5,3}, {2,6,1}, {3,5,3}}; //weighted graph
    int n=7;    //No. of nodes mostly given
    vector<vector<pair<int, int>>> adj(n); //adjacency list
    for (const auto& edge : graph) 
    {
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]}); // Push the edge weights as well
    }
    
    //Dijkstra implementation. Note:- Doesn't work for negative edge weights
    // priority_queue<int> pq; //Max  heap

    // Syntax for a Min-Heap 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, INT_MAX);

    int source=0;   //Can be any node 
    dist[source]=0;
    pq.push({0, source}); // starting node

    while (!pq.empty())
    {
        int d=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        if (d > dist[node]) continue;
        for (auto &edge : adj[node])
        {
            int neighbor=edge.first;
            int weight=edge.second;
            if (dist[node]+weight < dist[neighbor])
            {
                dist[neighbor]=dist[node]+weight;
                pq.push({dist[neighbor], neighbor});
            }
        }
    }
    cout << "Shortest distance from source :"<<endl;
    for (int i=0; i<n; i++)
    {
        cout << "Node "<< i << " : " << dist[i] <<" ";
    }
    cout << endl;
    return 0;
}