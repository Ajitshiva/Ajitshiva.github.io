class FenwickTree:
    def __init__(self, n):
        self.tree = [0] * (n + 1)

    def query(self, idx):
        sum_val = 0
        while idx > 0:
            sum_val += self.tree[idx]
            idx -= idx & -idx
        return sum_val

    def update(self, idx, delta):
        while idx < len(self.tree):
            self.tree[idx] += delta
            idx += idx & -idx

    def lower_bound(self, val):
        pos = 0
        bit_mask = 1 << (len(self.tree) - 1)
        sum_val = 0

        while bit_mask:
            if pos + bit_mask < len(self.tree) and sum_val + self.tree[pos + bit_mask] < val:
                sum_val += self.tree[pos + bit_mask]
                pos += bit_mask
            bit_mask >>= 1
        return pos + 1

# Example Usage
nums = [1, 3, 5, 7, 9, 11]
ft = FenwickTree(len(nums))
for i in range(len(nums)):
    ft.update(i + 1, nums[i])

# Query the sum of elements from index 1 to index 4
sum_val = ft.query(4) - ft.query(1 - 1)

# Find the lower bound of value 6
lower_bound_index = ft.lower_bound(6)
