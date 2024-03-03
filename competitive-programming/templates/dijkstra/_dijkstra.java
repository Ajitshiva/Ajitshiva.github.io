import java.util.*;

public class DijkstraAlgorithm {

    static class Pair<U, V> {
        public final U first;
        public final V second;

        public Pair(U first, V second) {
            this.first = first;
            this.second = second;
        }
    }

    public static void dijkstra(ArrayList<ArrayList<Pair<Integer, Integer>>> graph, int start, int numVertices, int[] distances) {
        PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<>(Comparator.comparingInt(pair -> pair.second));
        distances[start] = 0;
        pq.offer(new Pair<>(start, 0));

        while (!pq.isEmpty()) {
            int u = pq.poll().first;

            for (Pair<Integer, Integer> neighbor : graph.get(u)) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (distances[v] > distances[u] + weight) {
                    distances[v] = distances[u] + weight;
                    pq.offer(new Pair<>(v, distances[v]));
                }
            }
        }
    }

    public static void main(String[] args) {
        int numVertices = 6;
        ArrayList<ArrayList<Pair<Integer, Integer>>> graph = new ArrayList<>(numVertices);
        for (int i = 0; i < numVertices; i++) {
            graph.add(new ArrayList<>());
        }

        // Example graph represented as an adjacency list
        graph.get(0).add(new Pair<>(1, 5));
        graph.get(0).add(new Pair<>(2, 3));
        graph.get(1).add(new Pair<>(0, 5));
        graph.get(1).add(new Pair<>(2, 2));
        graph.get(1).add(new Pair<>(3, 1));
        graph.get(2).add(new Pair<>(0, 3));
        graph.get(2).add(new Pair<>(1, 2));
        graph.get(2).add(new Pair<>(3, 4));
        graph.get(2).add(new Pair<>(4, 2));
        graph.get(3).add(new Pair<>(1, 1));
        graph.get(3).add(new Pair<>(2, 4));
        graph.get(3).add(new Pair<>(4, 1));
        graph.get(3).add(new Pair<>(5, 4));
        graph.get(4).add(new Pair<>(2, 2));
        graph.get(4).add(new Pair<>(3, 1));
        graph.get(4).add(new Pair<>(5, 3));
        graph.get(5).add(new Pair<>(3, 4));
        graph.get(5).add(new Pair<>(4, 3));

        int[] distances = new int[numVertices];
        Arrays.fill(distances, Integer.MAX_VALUE);

        int startVertex = 0;
        System.out.println("Shortest distances from vertex " + startVertex);
        dijkstra(graph, startVertex, numVertices, distances);

        for (int i = 0; i < numVertices; i++) {
            System.out.println("Vertex " + i + ": " + distances[i]);
        }
    }
}
