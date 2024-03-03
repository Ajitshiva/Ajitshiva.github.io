def bellman_ford(edges, num_vertices, source):
    distance = [float('inf')] * num_vertices
    distance[source] = 0

    # Relax all edges |V| - 1 times
    for _ in range(num_vertices - 1):
        for u, v, weight in edges:
            if distance[u] != float('inf') and distance[u] + weight < distance[v]:
                distance[v] = distance[u] + weight

    # Check for negative-weight cycles
    for u, v, weight in edges:
        if distance[u] != float('inf') and distance[u] + weight < distance[v]:
            print("Graph contains negative weight cycle!")
            return []

    return distance

edges = [(0, 1, 4), (0, 2, 3), (1, 2, -1), (1, 3, 2), (1, 4, 3),
         (3, 2, 5), (3, 1, 1), (4, 3, -3)]

num_vertices = 5
source = 0
shortest_distances = bellman_ford(edges, num_vertices, source)
if shortest_distances:
    print("Shortest distances from vertex", source)
    for i in range(num_vertices):
        print("Vertex", i, ":", shortest_distances[i])
