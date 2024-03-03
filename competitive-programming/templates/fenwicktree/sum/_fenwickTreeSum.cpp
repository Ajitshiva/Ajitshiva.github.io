#include <vector>
#include <algorithm>
using namespace std;

class FenwickTree {
private:
    vector<int> tree;

public:
    FenwickTree(int n) {
        tree.assign(n + 1, 0);
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }

    void update(int idx, int delta) {
        while (idx < tree.size()) {
            tree[idx] += delta;
            idx += (idx & -idx);
        }
    }

    int lowerBound(int val) {
        int pos = 0;
        int bitMask = 1;
        int sum = 0;
        int len = tree.size();

        while (bitMask < len)
            bitMask <<= 1;

        for (int i = bitMask; i > 0; i >>= 1) {
            if (pos + i < len && sum + tree[pos + i] < val) {
                sum += tree[pos + i];
                pos += i;
            }
        }
        return pos + 1;
    }
};

// Example Usage
int main() {
    vector<int> nums = {1, 3, 5, 7, 9, 11};
    FenwickTree ft(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
        ft.update(i + 1, nums[i]);
    }

    // Query the sum of elements from index 1 to index 4
    int sum = ft.query(4) - ft.query(1 - 1);

    // Find the lower bound of value 6
    int lower_bound_index = ft.lowerBound(6);
    return 0;
}
