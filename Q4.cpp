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
    Graph(int vertices) : v(vertices), adjList(vertices + 1) {}

    void addEdge(int src, int dest, int weight)
    {
        adjList[src].push_back(make_pair(dest, weight));
        adjList[dest].push_back(make_pair(src, weight));
    }

    void dijkstras(int start)
    {
        // set all distances to a very high number
        vector<int> dist(v + 1, INT32_MAX);
        vector<int> parent(v + 1, -1);
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

        vector<int> targetVertices = {6, 8, 9, 15, 16, 22};

        cout << "Vertex\tDistance from Source\tPath\n";
        for (int i : targetVertices)
        {
            cout << i << "\t";
            if (dist[i] == INT32_MAX)
            {
                cout << "No path\t";
            }
            else
            {
                cout << dist[i] << "\t\t";
                vector<int> path;
                int curr = i;
                while (curr != -1)
                {
                    path.push_back(curr);
                    curr = parent[curr];
                }

                for (int j = path.size() - 1; j >= 0; --j)
                {
                    cout << path[j];
                    if (j != 0)
                        cout << " -> ";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(22);

    g.addEdge(1, 2, 1);
    g.addEdge(1, 11, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(2, 21, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(3, 8, 2);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 2);
    g.addEdge(5, 7, 1);
    g.addEdge(5, 22, 1);
    g.addEdge(6, 7, 2);
    g.addEdge(7, 8, 1);
    g.addEdge(8, 9, 1);
    g.addEdge(9, 10, 1);
    g.addEdge(9, 19, 2);
    g.addEdge(10, 11, 1);
    g.addEdge(10, 18, 2);
    g.addEdge(11, 12, 2);
    g.addEdge(11, 17, 1);
    g.addEdge(12, 13, 2);
    g.addEdge(13, 14, 2);
    g.addEdge(13, 21, 1);
    g.addEdge(14, 15, 1);
    g.addEdge(14, 16, 1);
    g.addEdge(14, 20, 1);
    g.addEdge(16, 17, 2);
    g.addEdge(17, 18, 2);
    g.addEdge(18, 19, 1);
    g.addEdge(20, 21, 2);
    g.addEdge(20, 22, 1);
    g.addEdge(21, 22, 2);

    g.dijkstras(1);

    return 0;
}