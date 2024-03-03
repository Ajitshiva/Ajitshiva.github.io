class Node:
    def __init__(self):
        self.sum = 0
        self.lazy = 0

class SegmentTree:
    def __init__(self, nums):
        self.tree = [Node() for _ in range(4 * len(nums))]
        self.build_tree(nums, 0, 0, len(nums) - 1)

    def propagate(self, node, start, end):
        if self.tree[node].lazy != 0:
            self.tree[node].sum += (end - start + 1) * self.tree[node].lazy
            if start != end:
                self.tree[2 * node + 1].lazy += self.tree[node].lazy
                self.tree[2 * node + 2].lazy += self.tree[node].lazy
            self.tree[node].lazy = 0

    def build_tree(self, nums, node, start, end):
        if start == end:
            self.tree[node].sum = nums[start]
            return
        mid = start + (end - start) // 2
        self.build_tree(nums, 2 * node + 1, start, mid)
        self.build_tree(nums, 2 * node + 2, mid + 1, end)
        self.tree[node].sum = self.tree[2 * node + 1].sum + self.tree[2 * node + 2].sum

    def update_point(self, node, start, end, idx, diff):
        self.propagate(node, start, end)
        if start == end:
            self.tree[node].sum += diff
            return
        mid = start + (end - start) // 2
        if idx <= mid:
            self.update_point(2 * node + 1, start, mid, idx, diff)
        else:
            self.update_point(2 * node + 2, mid + 1, end, idx, diff)
        self.tree[node].sum = self.tree[2 * node + 1].sum + self.tree[2 * node + 2].sum

    def update_range(self, node, start, end, left, right, diff):
        self.propagate(node, start, end)
        if start > right or end < left:
            return
        if left <= start and end <= right:
            self.tree[node].sum += (end - start + 1) * diff
            if start != end:
                self.tree[2 * node + 1].lazy += diff
                self.tree[2 * node + 2].lazy += diff
            return
        mid = start + (end - start) // 2
        self.update_range(2 * node + 1, start, mid, left, right, diff)
        self.update_range(2 * node + 2, mid + 1, end, left, right, diff)
        self.tree[node].sum = self.tree[2 * node + 1].sum + self.tree[2 * node + 2].sum

    def query_range(self, node, start, end, left, right):
        self.propagate(node, start, end)
        if start > right or end < left:
            return 0
        if left <= start and end <= right:
            return self.tree[node].sum
        mid = start + (end - start) // 2
        left_sum = self.query_range(2 * node + 1, start, mid, left, right)
        right_sum = self.query_range(2 * node + 2, mid + 1, end, left, right)
        return left_sum + right_sum

    def update(self, idx, val):
        diff = val - self.query(idx, idx)
        self.update_point(0, 0, len(self.tree) // 4 - 1, idx, diff)

    def update(self, left, right, val):
        self.update_range(0, 0, len(self.tree) // 4 - 1, left, right, val)

    def query(self, left, right):
        return self.query_range(0, 0, len(self.tree) // 4 - 1, left, right)

# Example usage:
nums = [1, 3, 2, 7, 9, 11]
st = SegmentTree(nums)
st.update(1, 3, 2)  # Add 2 to elements in range [1, 3]
print(st.query(1, 3))  # Output: 17 (sum of elements in range [1, 3] after update)
print(st.query(0, 5))  # Output: 35 (sum of elements in range [0, 5] after update)
st.update(1, 5)  # Update element at index 1 to 5
