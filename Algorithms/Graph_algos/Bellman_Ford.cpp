#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> graph = {{0,1,1}, {0,2,4}, {1,3,2}, {1,4,-6}, {2,5,3}, {2,6,1}, {3,5,8}, {5,1,2}}; //weighted graph
    int n=7;    //No. of nodes mostly given
    vector<int> dist(n, INT_MAX);
    int source=0;
    dist[source]=0;

    //Relax n-1 times
    for (int i=0; i<n-1; i++)
    {
        for (const auto& edges:graph)
        {
            int u=edges[0];
            int v=edges[1];
            int weight=edges[2];
            if (dist[u]!=INT_MAX && dist[u]+weight < dist[v])
            {
                dist[v]=dist[u]+weight;
            }
        }
    }

    bool flag=false;
    //Try to relax one more time
    for (const auto& edges:graph)
    {
        int u=edges[0];
        int v=edges[1];
        int weight=edges[2];
        if (dist[u]!=INT_MAX && dist[u]+weight < dist[v])
        {
            flag=true;  //If it relaxes negative cycle is there
            break;
        }
    }
    if (flag)   cout<<"Negative edge cycle exists";
    else
    {
        cout << "No negative cycle detected. Shortest distances from source " << source << ":" << endl;
        for (int i = 0; i < n; i++)
        {
            if (dist[i] == INT_MAX) cout << "Node " << i << " : INF" << endl;
            else cout << "Node " << i << " : " << dist[i] << endl;
        }
    }
    return 0;
}