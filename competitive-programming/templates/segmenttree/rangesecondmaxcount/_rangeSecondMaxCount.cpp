#include <bits/stdc++.h>
using namespace std;

struct Node {
    long long max1, cnt1, max2, cnt2;
    Node(long long max1 = -1, long long cnt1 = 0, long long max2 = -1, long long cnt2 = 0)
        : max1(max1), cnt1(cnt1), max2(max2), cnt2(cnt2) {}
};

class SegmentTree {
private:
    vector<Node> t;
    vector<long long> arr;
    int n;

    Node merge(const Node& left, const Node& right) {
        vector<pair<long long, long long>> vals = {
            {left.max1, left.cnt1}, {right.max1, right.cnt1},
            {left.max2, left.cnt2}, {right.max2, right.cnt2}
        };
        sort(vals.rbegin(), vals.rend());
        Node parent = Node(vals[0].first, vals[0].second);
        for (size_t i = 1; i < vals.size(); ++i) {
            auto val = vals[i].first, cnt = vals[i].second;
            if (val == parent.max1) {
                parent.cnt1 += cnt;
            } else if (parent.max2 < val && val < parent.max1) {
                parent.max2 = val;
                parent.cnt2 = cnt;
            } else if (val == parent.max2) {
                parent.cnt2 += cnt;
            }
        }
        return parent;
    }

    void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = Node(arr[tl], 1);
        } else {
            int tm = (tl + tr) / 2;
            build(v*2, tl, tm);
            build(v*2+1, tm+1, tr);
            t[v] = merge(t[v*2], t[v*2+1]);
        }
    }

    void update(int v, int tl, int tr, int pos, long long new_val) {
        if (tl == tr) {
            t[v] = Node(new_val, 1);
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            t[v] = merge(t[v*2], t[v*2+1]);
        }
    }

    Node query(int v, int tl, int tr, int l, int r) {
        if (l > r) return Node();
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return merge(query(v*2, tl, tm, l, min(r, tm)), query(v*2+1, tm+1, tr, max(l, tm+1), r));
    }

public:
    SegmentTree(vector<long long>& _arr) : arr(_arr) {
        n = arr.size();
        t.resize(4 * n);
        build(1, 0, n-1);
    }

    void update(int pos, long long new_val) {
        update(1, 0, n-1, pos, new_val);
    }

    Node query(int l, int r) {
        return query(1, 0, n-1, l-1, r-1);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    SegmentTree segTree(arr);

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int p;
            long long x;
            cin >> p >> x;
            segTree.update(p-1, x);
        } else {
            int l, r;
            cin >> l >> r;
            Node res = segTree.query(l, r);
            cout << res.cnt2 << "\n";
        }
    }

    return 0;
}
