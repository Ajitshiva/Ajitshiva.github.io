import java.util.*;

public class BellmanFordHelper {

    static class Edge {
        int source, destination, weight;

        public Edge(int source, int destination, int weight) {
            this.source = source;
            this.destination = destination;
            this.weight = weight;
        }
    }

    public static int[] bellmanFord(List<Edge> edges, int numVertices, int source) {
        int[] distance = new int[numVertices];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[source] = 0;

        // Relax all edges |V| - 1 times
        for (int i = 0; i < numVertices - 1; i++) {
            for (Edge edge : edges) {
                int u = edge.source;
                int v = edge.destination;
                int weight = edge.weight;

                if (distance[u] != Integer.MAX_VALUE && distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                }
            }
        }

        // Check for negative-weight cycles
        for (Edge edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int weight = edge.weight;

            if (distance[u] != Integer.MAX_VALUE && distance[u] + weight < distance[v]) {
                System.out.println("Graph contains negative weight cycle!");
                return new int[0]; // Return empty array to indicate negative cycle
            }
        }

        return distance;
    }

    public static void main(String[] args) {
        List<Edge> edges = Arrays.asList(new Edge(0, 1, 4), new Edge(0, 2, 3),
                                         new Edge(1, 2, -1), new Edge(1, 3, 2),
                                         new Edge(1, 4, 3), new Edge(3, 2, 5),
                                         new Edge(3, 1, 1), new Edge(4, 3, -3));

        int numVertices = 5;
        int source = 0;
        int[] shortestDistances = bellmanFord(edges, numVertices, source);

        if (shortestDistances.length > 0) {
            System.out.println("Shortest distances from vertex " + source + ":");
            for (int i = 0; i < numVertices; ++i) {
                System.out.println("Vertex " + i + ": " + shortestDistances[i]);
            }
        }
    }
}
