#include <iostream>
#include <list>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
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

    void addEdge(int i, int j, bool undir = true)
    {
        l[i].push_back(j);
        if (undir)
            l[j].push_back(i);
    }

    //single source shortest path
    void bfsShortestPath(int source, int destination = -1)
    {
        queue<int> q;
        bool *visited = new bool[V]{false};
        int *distance = new int[V]{0};
        int *parent = new int[V];

        for (int i = 0; i < V; i++)
            parent[i] = -1;

        q.push(source);
        visited[source] = true;
        distance[source] = 0;
        parent[source] = source;

        while (!q.empty())
        {
            //Do some work for every node
            int f = q.front();
            //cout << f << endl;
            q.pop();

            //push the nbrs of current node if they are not visited
            for (auto nbr : l[f])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    parent[nbr] = f;
                    distance[nbr] = distance[f] + 1;
                    visited[nbr] = true;
                }
            }
        }

        //print all the nodes with shortest distance from source
        for (int i = 0; i < V; i++)
        {
            cout << "Shortest distance from source: " << source << " to node " << i << " is: " << distance[i] << endl;
        }

        if (destination != -1)
        {
            vector<int> revPath;
            int temp = destination;
            while (temp != source)
            {
                revPath.push_back(temp);
                temp = parent[temp];
            };
            revPath.push_back(source);
            std::reverse(revPath.begin(), revPath.end());
            for (int i = 0; i < revPath.size(); i++)
            {
                cout << revPath[i];
                string s = (i == revPath.size() - 1) ? " " : "-->";
                cout << s;
            }
        }
    }
};

int main()
{
    Graph g(7);

    g.addEdge(1, 2);
    g.addEdge(1, 0);
    g.addEdge(2, 3);
    g.addEdge(0, 4);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    g.bfsShortestPath(1, 6);

    return 0;
}