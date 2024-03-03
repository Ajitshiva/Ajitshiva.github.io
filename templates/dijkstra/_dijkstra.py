import heapq

def dijkstra(graph, start):
    num_vertices = len(graph)
    distances = [float('inf')] * num_vertices
    distances[start] = 0
    pq = [(0, start)]

    while pq:
        dist_u, u = heapq.heappop(pq)

        if dist_u > distances[u]:
            continue

        for v, weight in graph[u]:
            if distances[v] > dist_u + weight:
                distances[v] = dist_u + weight
                heapq.heappush(pq, (distances[v], v))

    return distances

if __name__ == "__main__":
    num_vertices = 6
    graph = [[] for _ in range(num_vertices)]

    # Example graph represented as an adjacency list
    graph[0].extend([(1, 5), (2, 3)])
    graph[1].extend([(0, 5), (2, 2), (3, 1)])
    graph[2].extend([(0, 3), (1, 2), (3, 4), (4, 2)])
    graph[3].extend([(1, 1), (2, 4), (4, 1), (5, 4)])
    graph[4].extend([(2, 2), (3, 1), (5, 3)])
    graph[5].extend([(3, 4), (4, 3)])

    start_vertex = 0
    print("Shortest distances from vertex", start_vertex)
    print(dijkstra(graph, start_vertex))
