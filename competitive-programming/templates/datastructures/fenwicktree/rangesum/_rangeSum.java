class FenwickTree {
    private int[] tree;

    public FenwickTree(int n) {
        tree = new int[n + 1];
    }

    public int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }

    public void update(int idx, int delta) {
        while (idx < tree.length) {
            tree[idx] += delta;
            idx += (idx & -idx);
        }
    }

    public int lowerBound(int val) {
        int pos = 0;
        int bitMask = Integer.highestOneBit(tree.length - 1) << 1;
        int sum = 0;

        for (int i = bitMask; i > 0; i >>= 1) {
            if (pos + i < tree.length && sum + tree[pos + i] < val) {
                sum += tree[pos + i];
                pos += i;
            }
        }
        return pos + 1;
    }
}

// Example Usage
public class Main {
    public static void main(String[] args) {
        int[] nums = {1, 3, 5, 7, 9, 11};
        FenwickTree ft = new FenwickTree(nums.length);
        for (int i = 0; i < nums.length; ++i) {
            ft.update(i + 1, nums[i]);
        }

        // Query the sum of elements from index 1 to index 4
        int sum = ft.query(4) - ft.query(1 - 1);

        // Find the lower bound of value 6
        int lowerBoundIndex = ft.lowerBound(6);
    }
}
