class UnionFind:

    def __init__(self, n: int):
        self.parent = list(range(n))
        self.rank = [1 for _ in range(n)]
        self.rank[0] = 10 ** 5 + 1

    def find(self, x: int) -> int:
        if self.parent[x] != x: self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x: int, y: int) -> None:
        parentX, parentY = self.parent[x], self.parent[y]
        if parentX == parentY: return

        if self.rank[parentX] > self.rank[parentY]: self.parent[parentY] = parentX
        elif self.rank[parentX] < self.rank[parentY]: self.parent[parentX] = parentY
        else:
            self.parent[parentY] = parentX
            self.rank[parentX] += 1
    
    def is_connected(self, x: int, y: int) -> bool:
        return self.find(x) == self.find(y)

    def reset(self, x: int) -> None:
        self.parent[x] = x
        self.rank[x] = 1

# Create an instance of UnionFind for 10 elements
uf = UnionFind(10)

# Perform some union operations
uf.union(1, 2)
uf.union(3, 4)
uf.union(1, 4)  # This will connect 1, 2, 3, and 4 in the same set

# Check if two elements are connected
print(uf.is_connected(1, 3))  # Output: True, as 1 and 3 are now connected through 2 and 4
print(uf.is_connected(1, 5))  # Output: False, as 5 is not connected to 1, 2, 3, or 4

# Reset an element
uf.reset(2)
print(uf.is_connected(1, 2))  # Output: False, as 2 has been reset and is no longer connected to 1

# Additional demonstration
print(uf.is_connected(3, 4))  # Output: True, because 3 and 4 are still connected