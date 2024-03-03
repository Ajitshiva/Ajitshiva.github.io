class Node:
    def __init__(self, max1=-1, cnt1=0, max2=-1, cnt2=0):
        self.max1 = max1
        self.cnt1 = cnt1
        self.max2 = max2
        self.cnt2 = cnt2

class SegmentTree:
    def __init__(self, arr):
        self.arr = arr
        self.n = len(arr)
        self.t = [Node() for _ in range(4 * self.n)]
        self.build(1, 0, self.n - 1)

    def merge(self, left, right):
        vals = [
            (left.max1, left.cnt1), (right.max1, right.cnt1),
            (left.max2, left.cnt2), (right.max2, right.cnt2)
        ]
        vals.sort(reverse=True)
        parent = Node(vals[0][0], vals[0][1])
        for val, cnt in vals[1:]:
            if val == parent.max1:
                parent.cnt1 += cnt
            elif parent.max2 < val < parent.max1:
                parent.max2 = val
                parent.cnt2 = cnt
            elif val == parent.max2:
                parent.cnt2 += cnt
        return parent

    def build(self, v, tl, tr):
        if tl == tr:
            self.t[v] = Node(self.arr[tl], 1)
        else:
            tm = (tl + tr) // 2
            self.build(v * 2, tl, tm)
            self.build(v * 2 + 1, tm + 1, tr)
            self.t[v] = self.merge(self.t[v * 2], self.t[v * 2 + 1])

    def update(self, v, tl, tr, pos, new_val):
        if tl == tr:
            self.t[v] = Node(new_val, 1)
        else:
            tm = (tl + tr) // 2
            if pos <= tm:
                self.update(v * 2, tl, tm, pos, new_val)
            else:
                self.update(v * 2 + 1, tm + 1, tr, pos, new_val)
            self.t[v] = self.merge(self.t[v * 2], self.t[v * 2 + 1])

    def query(self, v, tl, tr, l, r):
        if l > r:
            return Node()
        if l == tl and r == tr:
            return self.t[v]
        tm = (tl + tr) // 2
        return self.merge(self.query(v * 2, tl, tm, l, min(r, tm)), self.query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r))


if __name__ == "__main__":
    n, q = map(int, input().split())
    arr = list(map(int, input().split()))

    segTree = SegmentTree(arr)

    for _ in range(q):
        query = list(map(int, input().split()))
        if query[0] == 1:
            p, x = query[1:]
            segTree.update(1, 0, n - 1, p - 1, x)
        else:
            l, r = query[1:]
            res = segTree.query(1, 0, n - 1, l - 1, r - 1)
            print(res.cnt2)
