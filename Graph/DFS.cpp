#include <iostream>
#include <stack>
#include <list>

using namespace std;

class Graph
{
    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        this->V = v;
        l = new list<int>[V];
    }

    void addEdge(int u, int v, bool undir = true)
    {
        l[u].push_back(v);
        if (undir)
            l[v].push_back(u);
    }

    void dfsHelper(int node, bool *visited)
    {
        cout << node << ", ";
        visited[node] = true;

        //make a dfs call to all its neighbour
        for (int nbr : l[node])
        {
            if (!visited[nbr])
            {
                dfsHelper(nbr, visited);
            }
        }
        return;
    }

    void dfs(int source)
    {
        bool *visited = new bool[V];
        dfsHelper(source, visited);
    }
};

int main()
{
    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 5);
    g.addEdge(0, 4);
    g.addEdge(3, 4);

    g.dfs(1);

    return 0;
}