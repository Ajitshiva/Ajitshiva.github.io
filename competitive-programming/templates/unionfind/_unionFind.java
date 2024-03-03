public class UnionFind {
    private int[] parent;
    private int[] rank;

    public UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Each element is its own parent initially.
            rank[i] = 1; // Initial rank of 1 for all elements.
        }
    }

    public int find(int x) {
        if (parent[x] != x) {
            // Path compression by halving.
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    public void union(int x, int y) {
        int parentX = find(x);
        int parentY = find(y);
        if (parentX != parentY) {
            if (rank[parentX] > rank[parentY]) {
                parent[parentY] = parentX;
            } else if (rank[parentX] < rank[parentY]) {
                parent[parentX] = parentY;
            } else {
                parent[parentY] = parentX;
                rank[parentX]++;
            }
        }
    }

    public boolean isConnected(int x, int y) {
        return find(x) == find(y);
    }

    public void reset(int x) {
        parent[x] = x;
        rank[x] = 1;
    }
}

public class Main {
    public static void main(String[] args) {
        // Create an instance of UnionFind for 10 elements
        UnionFind uf = new UnionFind(10);

        // Perform some union operations
        uf.union(1, 2);
        uf.union(3, 4);
        uf.union(1, 4); // This will connect 1, 2, 3, and 4 in the same set

        // Check if two elements are connected
        System.out.println(uf.isConnected(1, 3)); // Output: true, as 1 and 3 are now connected through 2 and 4
        System.out.println(uf.isConnected(1, 5)); // Output: false, as 5 is not connected to 1, 2, 3, or 4

        // Reset an element
        uf.reset(2);
        System.out.println(uf.isConnected(1, 2)); // Output: false, as 2 has been reset and is no longer connected to 1

        // Additional demonstration
        System.out.println(uf.isConnected(3, 4)); // Output: true, because 3 and 4 are still connected
    }
}
