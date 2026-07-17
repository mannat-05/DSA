#include <bits/stdc++.h>
using namespace std;

//undirected
// int main()
// {
//     vector<vector<int>> graph = {{0,1}, {0,2}, {1,3}, {1,4}, {2,5}, {2,6}, {3,5}}; //edge list
//     int n=7;    
//     vector<vector<int>> adj(n); //adjacency list
//     for (const auto& edge : graph) 
//     {
//         adj[edge[0]].push_back(edge[1]);
//         adj[edge[1]].push_back(edge[0]); // for undirected graph skip for directed graph
//     }

//     // DFS implementation for cycle detection
//     vector<bool> visited(n, false);
//     stack<pair<int, int>> s;
//     s.push({0, -1}); // starting node no parent
//     bool flag = false;

//     while (!s.empty())
//     {
//         int node=s.top().first;
//         int parent=s.top().second;
//         s.pop();
//         if (!visited[node])
//         {
//             visited[node]=true;
//             for (auto &neighbor : adj[node])
//             {
//                 if (!visited[neighbor])
//                     s.push({neighbor, node});
//                 else if (neighbor != parent)
//                 {
//                     flag=true;
//                     break;
//                 }
//             }
//         }
//         if (flag)   break;
//     }
//     if (flag)
//         cout <<"Cycle is detected";
//     else
//         cout <<"No cycle detected";
//     return 0;
// }

//directed
//Recursive DFS
bool dfs(int node, vector<vector<int>> &adj, vector<bool>& visited, vector<bool> &recStack)
{
    visited[node]=true;
    recStack[node]=true;
    for (auto neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            if (dfs(neighbor, adj, visited, recStack))
                return true;
        }
        else if (recStack[neighbor])
        {
            return true;
        }
    }
    recStack[node] = false; //backtrack
    return false;
}

int main()
{
    vector<vector<int>> graph = {{0,1}, {0,2}, {1,3}, {1,4}, {2,5}, {2,6}, {3,5}, {5,1}}; //edge list
    int n=7;    
    vector<vector<int>> adj(n); //adjacency list
    for (const auto& edge : graph) 
    {
        adj[edge[0]].push_back(edge[1]);    //directed graph
    }
    vector<bool> visited(n, false);
    vector<bool> recStack(n, false);

    bool flag=false;
    for (int i=0; i<n; i++)
    {
        if (!visited[i])
        {
            if (dfs(i, adj, visited, recStack))
            {
                flag=true;
                break;
            }
        }
    }
    if (flag)   cout<<"Cycle detected";
    else    cout << "No cycle detected";
    return 0;
}