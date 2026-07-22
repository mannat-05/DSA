#include <bits/stdc++.h>
using namespace std;
//Applicable only on DAG(Kahn's algo)
vector<int> topo_sort(int n, vector<vector<int>> adj)
{
    vector<int> indegree(n, 0);
    for (int u=0; u<n; u++)
    {
        for (int v : adj[u])
        {
            indegree[v]++;
        }
    }

    queue<int> q;
    for (int i=0; i<n; i++)
    {
        if (indegree[i] == 0)   q.push(i);
    }
    vector<int> res;
    while (!q.empty())
    {
        int node=q.front();
        q.pop();
        res.push_back(node);

        for (int neighbor : adj[node])
        {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0)    q.push(neighbor);
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> graph={{5, 0}, {5, 1}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};
    int n=6;
    vector<vector<int>> adj(n);
    for (int i=0; i<graph.size(); i++)
    {
        int u=graph[i][0];
        int v=graph[i][1];
        adj[u].push_back(v);
    }

    vector<int> result = topo_sort(n, adj);
    if (!result.empty()) 
    {
        cout << "Topological Order (BFS): ";
        for (int node : result) 
        {
            cout << node << " ";
        }
        return 0;
    }
}