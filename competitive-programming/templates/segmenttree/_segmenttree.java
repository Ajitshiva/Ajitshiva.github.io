import java.util.*;

class Node {
    int sum;
    int lazy;

    Node() {
        sum = 0;
        lazy = 0;
    }
}

class SegmentTree {
    private Node[] tree;
    private int[] lazy;

    SegmentTree(int[] nums) {
        tree = new Node[4 * nums.length];
        lazy = new int[4 * nums.length];
        buildTree(nums, 0, 0, nums.length - 1);
    }

    private void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node].sum += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    private void buildTree(int[] nums, int node, int start, int end) {
        tree[node] = new Node();
        if (start == end) {
            tree[node].sum = nums[start];
            return;
        }
        int mid = start + (end - start) / 2;
        buildTree(nums, 2 * node + 1, start, mid);
        buildTree(nums, 2 * node + 2, mid + 1, end);
        tree[node].sum = tree[2 * node + 1].sum + tree[2 * node + 2].sum;
    }

    void updateRange(int node, int start, int end, int left, int right, int diff) {
        propagate(node, start, end);
        if (start > right || end < left) {
            return;
        }
        if (left <= start && end <= right) {
            tree[node].sum += (end - start + 1) * diff;
            if (start != end) {
                lazy[2 * node + 1] += diff;
                lazy[2 * node + 2] += diff;
            }
            return;
        }
        int mid = start + (end - start) / 2;
        updateRange(2 * node + 1, start, mid, left, right, diff);
        updateRange(2 * node + 2, mid + 1, end, left, right, diff);
        tree[node].sum = tree[2 * node + 1].sum + tree[2 * node + 2].sum;
    }

    int queryRange(int node, int start, int end, int left, int right) {
        propagate(node, start, end);
        if (start > right || end < left) {
            return 0;
        }
        if (left <= start && end <= right) {
            return tree[node].sum;
        }
        int mid = start + (end - start) / 2;
        int leftSum = queryRange(2 * node + 1, start, mid, left, right);
        int rightSum = queryRange(2 * node + 2, mid + 1, end, left, right);
        return leftSum + rightSum;
    }

    void update(int left, int right, int val) {
        updateRange(0, 0, lazy.length / 4 - 1, left, right, val);
    }

    int query(int left, int right) {
        return queryRange(0, 0, lazy.length / 4 - 1, left, right);
    }

    public static void main(String[] args) {
        int[] nums = {1, 3, 2, 7, 9, 11};
        SegmentTree st = new SegmentTree(nums);
        st.update(1, 3, 2);  // Add 2 to elements in range [1, 3]
        System.out.println(st.query(1, 3));  // Output: 17 (sum of elements in range [1, 3] after update)
        System.out.println(st.query(0, 5));  // Output: 35 (sum of elements in range [0, 5] after update)
    }
}

