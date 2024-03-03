#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

void dijkstra(vector<pair<int, int>> adj[], int num_vertices, int start, vector<int>& distances) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap to store (distance, vertex) pairs
    
    distances[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int dist_u = pq.top().first;
        pq.pop();
        
        // Check all neighbors of vertex u
        for (const auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            
            // Relaxation step
            if (distances[v] > dist_u + weight) {
                distances[v] = dist_u + weight;
                pq.push({distances[v], v});
            }
        }
    }
}

int main() {
    int num_vertices = 6;
    vector<pair<int, int>> adj[num_vertices];

    // Example graph represented as an adjacency list
    adj[0].push_back({1, 5});
    adj[0].push_back({2, 3});
    adj[1].push_back({0, 5});
    adj[1].push_back({2, 2});
    adj[1].push_back({3, 1});
    adj[2].push_back({0, 3});
    adj[2].push_back({1, 2});
    adj[2].push_back({3, 4});
    adj[2].push_back({4, 2});
    adj[3].push_back({1, 1});
    adj[3].push_back({2, 4});
    adj[3].push_back({4, 1});
    adj[3].push_back({5, 4});
    adj[4].push_back({2, 2});
    adj[4].push_back({3, 1});
    adj[4].push_back({5, 3});
    adj[5].push_back({3, 4});
    adj[5].push_back({4, 3});

    vector<int> distances(num_vertices, numeric_limits<int>::max());
    int start_vertex = 0;
    cout << "Shortest distances from vertex " << start_vertex << endl;
    dijkstra(adj, num_vertices, start_vertex, distances);

    for (int i = 0; i < num_vertices; ++i) {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}
