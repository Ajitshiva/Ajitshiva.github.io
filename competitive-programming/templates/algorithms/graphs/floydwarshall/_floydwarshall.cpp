#include <iostream>
#include <vector>
#include <limits>

using namespace std;

vector<vector<int>> floydWarshallHelper(vector<vector<int>>& graph) {
    int numVertices = graph.size();

    // Initialize distances matrix with given graph
    vector<vector<int>> distances = graph;

    // Apply Floyd-Warshall algorithm
    for (int k = 0; k < numVertices; ++k) {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                if (distances[i][k] != INT_MAX && distances[k][j] != INT_MAX &&
                    distances[i][k] + distances[k][j] < distances[i][j]) {
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
            }
        }
    }

    return distances;
}

int main() {
    int numVertices = 4;
    // Example graph represented as an adjacency matrix
    vector<vector<int>> graph = {{0, 5, INT_MAX, 10},
                                 {INT_MAX, 0, 3, INT_MAX},
                                 {INT_MAX, INT_MAX, 0, 1},
                                 {INT_MAX, INT_MAX, INT_MAX, 0}};

    vector<vector<int>> shortestDistances = floydWarshallHelper(graph);

    // Use shortestDistances in other methods...
    return 0;
}
