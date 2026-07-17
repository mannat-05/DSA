#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent, rank;
    int components;

public:
    DSU (int n) //Constructor
    {
        parent.resize(n);
        rank.resize(n, 0);
        components=n;
        for (int i=0; i<n; i++) parent[i]=i;
    }

    int findParent(int node)
    {
        if (parent[node] == node)
            return node;
        parent[node]=findParent(parent[node]);  //Path compression
    }

    void merge(int u, int v)
    {
        int pu=findParent(u);
        int pv=findParent(v);
        if (pu == pv)   return;

        if (rank[pu] < rank[pv])
        {
            parent[pu]=pv;
        }
        else if (rank[pu] > rank[pv])
        {
            parent[pv]=pu;
        }
        else
        {
            parent[pv]=pu;
            rank[pu]++;
        }
        components--;
    }
    int count()
    {
        return components;
    }
};

int main()
{
    vector<vector<int>> graph={
        {0, 1}, {1, 2}, 
        {3, 4}, {4, 5}, 
        {6, 7}, {7, 8}};
    int n=9;    //No. of nodes mostly given
    vector<vector<int>> adj(n); //adjacency list
    DSU dsu(n);
    for (const auto& edge : graph)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
        dsu.merge(edge[0], edge[1]); 
    }
    cout << "No. of components: " << dsu.count();
    return 0;
}