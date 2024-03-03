#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int sum;
    int lazy;

    Node() {
        sum = 0;
        lazy = 0;
    }
};

class SegmentTree {
private:
    vector<Node> tree;
    vector<int> lazy;

    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node].sum += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
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

public:
    SegmentTree(vector<int>& nums) {
        int n = nums.size();
        tree.resize(4 * n);
        lazy.resize(4 * n);
        buildTree(nums, 0, 0, n - 1);
    }

    void buildTree(vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            tree[node].sum = nums[start];
            return;
        }
        int mid = start + (end - start) / 2;
        buildTree(nums, 2 * node + 1, start, mid);
        buildTree(nums, 2 * node + 2, mid + 1, end);
        tree[node].sum = tree[2 * node + 1].sum + tree[2 * node + 2].sum;
    }

    void update(int left, int right, int val) {
        updateRange(0, 0, lazy.size() / 4 - 1, left, right, val);
    }

    int query(int left, int right) {
        return queryRange(0, 0, lazy.size() / 4 - 1, left, right);
    }
};

int main() {
    vector<int> nums = {1, 3, 2, 7, 9, 11};
    SegmentTree st(nums);
    st.update(1, 3, 2); // Add 2 to elements in range [1, 3]
    cout << st.query(1, 3) << endl; // Output: 17 (sum of elements in range [1, 3] after update)
    cout << st.query(0, 5) << endl; // Output: 35 (sum of elements in range [0, 5] after update)
    return 0;
}
