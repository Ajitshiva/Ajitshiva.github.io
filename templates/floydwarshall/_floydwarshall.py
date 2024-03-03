def floyd_warshall_helper(graph):
    num_vertices = len(graph)

    # Initialize distances matrix with given graph
    distances = [row[:] for row in graph]

    # Apply Floyd-Warshall algorithm
    for k in range(num_vertices):
        for i in range(num_vertices):
            for j in range(num_vertices):
                if distances[i][k] != float('inf') and distances[k][j] != float('inf'):
                    distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j])

    return distances

# Example graph represented as an adjacency matrix
graph = [[0, 5, float('inf'), 10],
         [float('inf'), 0, 3, float('inf')],
         [float('inf'), float('inf'), 0, 1],
         [float('inf'), float('inf'), float('inf'), 0]]

shortest_distances = floyd_warshall_helper(graph)

# Use shortest_distances in other methods...
