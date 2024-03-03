import java.util.Arrays;

public class FloydWarshallHelper {

    public static int[][] floydWarshallHelper(int[][] graph) {
        int numVertices = graph.length;

        // Initialize distances matrix with given graph
        int[][] distances = new int[numVertices][numVertices];
        for (int i = 0; i < numVertices; ++i) {
            System.arraycopy(graph[i], 0, distances[i], 0, numVertices);
        }

        // Apply Floyd-Warshall algorithm
        for (int k = 0; k < numVertices; ++k) {
            for (int i = 0; i < numVertices; ++i) {
                for (int j = 0; j < numVertices; ++j) {
                    if (distances[i][k] != Integer.MAX_VALUE && distances[k][j] != Integer.MAX_VALUE &&
                            distances[i][k] + distances[k][j] < distances[i][j]) {
                        distances[i][j] = distances[i][k] + distances[k][j];
                    }
                }
            }
        }

        return distances;
    }

    public static void main(String[] args) {
        int numVertices = 4;
        // Example graph represented as an adjacency matrix
        int[][] graph = {{0, 5, Integer.MAX_VALUE, 10},
                         {Integer.MAX_VALUE, 0, 3, Integer.MAX_VALUE},
                         {Integer.MAX_VALUE, Integer.MAX_VALUE, 0, 1},
                         {Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MAX_VALUE, 0}};

        int[][] shortestDistances = floydWarshallHelper(graph);

        // Use shortestDistances in other methods...
    }
}
