#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge {
    int source, destination, weight;
};

vector<int> bellmanFord(vector<Edge>& edges, int numVertices, int source) {
    vector<int> distance(numVertices, INT_MAX);
    distance[source] = 0;

    // Relax all edges |V| - 1 times
    for (int i = 0; i < numVertices - 1; i++) {
        for (const auto& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;

            if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto& edge : edges) {
        int u = edge.source;
        int v = edge.destination;
        int weight = edge.weight;

        if (distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
            cout << "Graph contains negative weight cycle!" << endl;
            return vector<int>(); // Return empty vector to indicate negative cycle
        }
    }

    return distance;
}

int main() {
    vector<Edge> edges = {{0, 1, 4}, {0, 2, 3}, {1, 2, -1}, {1, 3, 2}, {1, 4, 3},
                          {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};

    int numVertices = 5;
    int source = 0;
    vector<int> shortestDistances = bellmanFord(edges, numVertices, source);

    if (!shortestDistances.empty()) {
        cout << "Shortest distances from vertex " << source << ":" << endl;
        for (int i = 0; i < numVertices; ++i) {
            cout << "Vertex " << i << ": " << shortestDistances[i] << endl;
        }
    }

    return 0;
}
