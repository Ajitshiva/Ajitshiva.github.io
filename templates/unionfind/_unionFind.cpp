class UnionFind {
private:
    vector<int> parent; 
    vector<int> rank;

public:
    UnionFind(int n) : parent(n), rank(n, 1) {
        // Initialize parent so each element is its own parent.
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            // Path compression
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int parentX = find(x);
        int parentY = find(y);
        if (parentX != parentY) {
            if (rank[parentX] > rank[parentY]) {
                parent[parentY] = parentX;
            } else if (rank[parentX] < rank[parentY]) {
                parent[parentX] = parentY;
            } else {
                parent[parentY] = parentX;
                rank[parentX] += 1;
            }
        }
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }

    void reset(int x) {
        parent[x] = x;
        rank[x] = 1;
    }
};

int main() {
    // Create an instance of UnionFind for 10 elements
    UnionFind uf(10);

    // Perform some union operations
    uf.unite(1, 2);
    uf.unite(3, 4);
    uf.unite(1, 4); // This will connect 1, 2, 3, and 4 in the same set

    // Check if two elements are connected
    cout << uf.isConnected(1, 3) << endl; // Output: 1 (True), as 1 and 3 are now connected through 2 and 4
    cout << uf.isConnected(1, 5) << endl; // Output: 0 (False), as 5 is not connected to 1, 2, 3, or 4

    // Reset an element
    uf.reset(2);
    cout << uf.isConnected(1, 2) << endl; // Output: 0 (False), as 2 has been reset and is no longer connected to 1

    // Additional demonstration
    cout << uf.isConnected(3, 4) << endl; // Output: 1 (True), because 3 and 4 are still connected

    return 0;
}

