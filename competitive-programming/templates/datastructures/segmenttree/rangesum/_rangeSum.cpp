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

    void propagate(int node, int start, int end) {
        if (tree[node].lazy != 0) {
            tree[node].sum += (end - start + 1) * tree[node].lazy;
            if (start != end) {
                tree[2 * node + 1].lazy += tree[node].lazy;
                tree[2 * node + 2].lazy += tree[node].lazy;
            }
            tree[node].lazy = 0;
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
                tree[2 * node + 1].lazy += diff;
                tree[2 * node + 2].lazy += diff;
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

    void updatePoint(int node, int start, int end, int idx, int diff) {
        propagate(node, start, end);
        if (start == end) {
            tree[node].sum += diff;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid)
            updatePoint(2 * node + 1, start, mid, idx, diff);
        else
            updatePoint(2 * node + 2, mid + 1, end, idx, diff);
        tree[node].sum = tree[2 * node + 1].sum + tree[2 * node + 2].sum;
    }

public:
    SegmentTree(vector<int>& nums) {
        int n = nums.size();
        tree.resize(4 * n);
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
        updateRange(0, 0, tree.size() / 4 - 1, left, right, val);
    }

    void update(int idx, int val) {
        int diff = val - query(idx, idx);
        updatePoint(0, 0, tree.size() / 4 - 1, idx, diff);
    }

    int query(int left, int right) {
        return queryRange(0, 0, tree.size() / 4 - 1, left, right);
    }
};

int main() {
    vector<int> nums = {1, 3, 2, 7, 9, 11};
    SegmentTree st(nums);
    st.update(1, 3, 2); // Update elements in range [1, 3] by adding 2
    cout << st.query(1, 3) << endl; // Output: 17 (sum of elements in range [1, 3] after update)
    cout << st.query(0, 5) << endl; // Output: 35 (sum of elements in range [0, 5] after update)
    st.update(2, 5); // Update element at index 2 to 5
    cout << st.query(0, 5) << endl; // Output: 40 (sum of elements in range [0, 5] after update)
    return 0;
}
