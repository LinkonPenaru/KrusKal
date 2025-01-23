#include<bits/stdc++.h>
using namespace std;

struct graph
{
    int u, v, w;
};

bool comp(graph a, graph b)
{
    return a.w < b.w; // ascending order
}

int edge, point, points[1000], rankk[1000], parent[1000];


void makeSet()
{
    for(int i = 0; i<point; i++)
    {
        parent[i] = i;
        rankk[i] = 0;
    }
}

int findSet(int x)
{
    if(x == parent[x]) return x;
    return parent[x] = findSet(parent[x]);
}

int unionSet(int a, int b)
{
    int u, v;
    u = findSet(a);
    v = findSet(b);

    if(u == v)
        return 0; // means already in the same set
    if(rankk[u] > rankk[v])
        parent[v] = u;
    else if(rankk[u] < rankk[v])
        parent[u] = v;
    else if(rankk[u] == rankk[v])
    {
        parent[u] = v;
        rankk[v]++;
    }

    return 1;
}

int main()
{
    graph g[100];

    cout << "Enter the number of edges: ";
    cin >> edge;

    cout << "Enter the number of vertices: ";
    cin >> point;

    cout << "Enter the (u, v, w): ";

    for(int i = 0; i < edge; i++)
        cin >> g[i].u >> g[i].v >> g[i].w;

    // sorting according to edges
    sort(g, g+edge, comp);

    cout << "\n\nSorted graph according to the weights\n";

    for(int i = 0; i < edge; i++)
        cout << g[i].u << " "<< g[i].v << " " << g[i].w << endl;



    /// Minimum Spanning Tree

    makeSet();
    cout << "\n\nMinimum Spanning Tree \n\n";

    int weight = 0;
    for(int i = 0; i<edge; i++)
    {
        int u = g[i].u;
        int v = g[i].v;

        if(findSet(u) != findSet(v))
        {
            unionSet(u, v);
            weight += g[i].w;
            cout << u << " "<< v << " " << g[i].w << endl;
        }
    }

    cout << "Total weight of MST: " << weight << endl;

    return 0;

}
