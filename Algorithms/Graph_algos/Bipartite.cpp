#include<bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>>& graph) 
{
    //2 colorable
    int n=graph.size(); 
    vector<int> color(n, -1);
    for (int i=0; i<n; i++)
    {
        if (color[i] != -1) continue;

        queue<int> q;
        q.push(i);
        color[i]=0;

        while (!q.empty())
        {
            int node=q.front();
            q.pop();
            for (int neighbor: graph[node])
            {
                if (color[neighbor] == -1)
                {
                    color[neighbor]=1-color[node];  //Complementary color
                    q.push(neighbor);
                }
                else if (color[node] == color[neighbor])    return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> graph={
        {1, 3}, // Node 0
        {0, 2}, // Node 1
        {1, 3}, // Node 2
        {0, 2}  // Node 3
    };
    if (isBipartite(graph))
    {
        cout << "The graph is Bipartite";
    }
    else
    {
        cout << "The graph is not Bipartite";
    }
}