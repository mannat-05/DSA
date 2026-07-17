#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> graph = {{0,1}, {0,2}, {1,3}, {1,4}, {2,5}, {2,6}}; //edge list
    int n=7;    
    vector<vector<int>> adj(n); //adjacency list
    for (const auto& edge : graph) 
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]); // for undirected graph skip for directed graph
    }
    // DFS implementation
    cout << "DFS traversal :" <<endl;
    vector<bool> visited(n, false);
    stack<int> s;
    s.push(0); // starting node

    while (!s.empty())
    {
        int node=s.top();
        s.pop();
        if (!visited[node])
        {
            cout << node << " ";
            visited[node]=true;

            for (auto &neighbor : adj[node])
            {
                if (!visited[neighbor])
                    s.push(neighbor);
            }
        }
    }
    cout << endl;
    return 0;
}