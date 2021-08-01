#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph
{
private:
    int V;
    list<int> *l;

public:
    Graph(int v)
    {
        this->V = v;
        l = new list<int>[V];
    }

    void addEdge(int u, int v, bool undir = false)
    {
        l[u].push_back(v);
        if (undir)
            l[v].push_back(v);
    }

    int getMinDist(int source, int dest)
    {
        queue<int> q;

        vector<int> distance(V, 0);
        vector<bool> visited(V, false);

        distance[source] = 0;
        visited[source] = true;
        q.push(source);

        while (!q.empty())
        {
            int temp = q.front();
            q.pop();

            for (auto nbr : l[temp])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    distance[nbr] = distance[temp] + 1;
                    visited[nbr] = true;
                }
            }
        }

        return distance[dest];
    }
};

int min_dice_throws(int n, vector<pair<int, int>> snakes, vector<pair<int, int>> ladders)
{
    vector<int> board(n + 1, 0);

    for (auto la : ladders)
    {
        int sp = la.first;
        int ep = la.second;
        board[sp] = ep - sp;
    }

    for (auto sn : snakes)
    {
        int sp = sn.first;
        int ep = sn.second;
        board[sp] = ep - sp;
    }

    Graph g(n + 1);
    for (int u = 1; u < n; u++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            int v = u + dice;
            v += board[v];

            if (v <= n)
                g.addEdge(u, v);
        }
    }

    return g.getMinDist(1, n);
}
