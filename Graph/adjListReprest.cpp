#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <string>
using namespace std;

class Node
{
public:
    string city;
    list<string> nbrs;
    Node(string city)
    {
        this->city = city;
    }
};

class Graph
{
    unordered_map<string, Node *> iMap;

public:
    Graph(vector<string> cities)
    {
        for (auto city : cities)
            iMap[city] = new Node(city);
    }

    void addEdge(string x, string y, bool undir = false)
    {
        iMap[x]->nbrs.push_back(y);
        if (undir)
            iMap[y]->nbrs.push_back(x);
    }

    void printAdjList()
    {
        for (auto cityPair : iMap)
        {
            auto city = cityPair.first;
            Node *node = cityPair.second;
            cout << city << " --> ";
            for (auto nbr : node->nbrs)
                cout << nbr << " ";

            cout << endl;
        }
    }
};

int main()
{
    vector<string> cities = {"Delhi", "London", "Paris", "NewYork"};
    Graph g(cities);

    g.addEdge("Delhi", "London");
    g.addEdge("NewYork", "London");
    g.addEdge("Delhi", "Paris");
    g.addEdge("Paris", "NewYork");

    g.printAdjList();

    return 0;
}