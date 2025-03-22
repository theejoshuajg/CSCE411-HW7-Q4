#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
private:
    // number of vertices
    int v;
    vector<vector<pair<int, int>>> adjList;

public:
    // graph contructor
    Graph(int vertices) : v(vertices), adjList(vertices) {}

    void addEdge(int src, int dest, int weight)
    {
        adjList[src].push_back(make_pair(dest, weight));
        adjList[dest].push_back(make_pair(src, weight));
    }

    void dijkstras(int start)
    {
        // set all distances to a very high number
        vector<int> dist(v, INT32_MAX);
        vector<int> parent(v, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // starting element gets a distance of 0
        dist[start] = 0;
        // add start with a distance of 0 to pq
        pq.push(make_pair(start, 0));

        while (!pq.empty())
        {
            pair<int, int> curr = pq.top();
            pq.pop();

            int node_value = curr.first;
            int currDist = curr.second;

            for (auto edge : adjList[node_value])
            {
                int dest = edge.first;
                int weight = edge.second;

                if (dist[node_value] + weight < dist[dest])
                {
                    dist[dest] = dist[node_value] + weight;
                    parent[dest] = node_value;
                    pq.push(make_pair(dest, dist[dest]));
                }
            }
        }

        cout << "Vertex \t Distance from Source \n";
        for (int i = 0; i < v; ++i)
        {
            if (dist[i] == INT32_MAX)
            {
                cout << i << "\tNo path\n";
            }
            else
            {
                cout << i << "\t" << dist[i] << endl;
            }
        }
    }
};

int main()
{
}