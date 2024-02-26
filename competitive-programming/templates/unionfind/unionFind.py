class UnionFind:

    def __init__(self, n: int):
        self.root = list(range(n))
        self.rank = [1 for _ in range(n)]
        self.rank[0] = 10 ** 5 + 1

    def find(self, x: int) -> int:
        if self.root[x] != x: self.root[x] = self.find(self.root[x])
        return self.root[x]

    def union(self, x: int, y: int) -> None:
        rootx, rooty = self.root[x], self.root[y]
        if rootx == rooty: return

        if self.rank[rootx] > self.rank[rooty]: self.root[rooty] = rootx
        elif self.rank[rootx] < self.rank[rooty]: self.root[rootx] = rooty
        else:
            self.root[rooty] = rootx
            self.rank[rootx] += 1
    
    def is_connected(self, x: int, y: int) -> bool:
        return self.find(x) == self.find(y)

    def reset(self, x: int) -> None:
        self.root[x] = x
        self.rank[x] = 1