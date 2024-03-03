import java.util.*;

class Node {
    long max1, cnt1, max2, cnt2;

    Node(long max1, long cnt1, long max2, long cnt2) {
        this.max1 = max1;
        this.cnt1 = cnt1;
        this.max2 = max2;
        this.cnt2 = cnt2;
    }

    Node() {
        this(-1, 0, -1, 0);
    }
}

class SegmentTree {
    private Node[] t;
    private long[] arr;
    private int n;

    SegmentTree(long[] arr) {
        this.arr = arr;
        n = arr.length;
        t = new Node[4 * n];
        build(1, 0, n - 1);
    }

    private Node merge(Node left, Node right) {
        List<long[]> vals = new ArrayList<>();
        vals.add(new long[]{left.max1, left.cnt1});
        vals.add(new long[]{right.max1, right.cnt1});
        vals.add(new long[]{left.max2, left.cnt2});
        vals.add(new long[]{right.max2, right.cnt2});
        vals.sort((a, b) -> Long.compare(b[0], a[0]));

        Node parent = new Node(vals.get(0)[0], vals.get(0)[1]);
        for (int i = 1; i < vals.size(); ++i) {
            long val = vals.get(i)[0];
            long cnt = vals.get(i)[1];
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

    private void build(int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = new Node(arr[tl], 1, -1, 0);
        } else {
            int tm = (tl + tr) / 2;
            build(v * 2, tl, tm);
            build(v * 2 + 1, tm + 1, tr);
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }

    private void update(int v, int tl, int tr, int pos, long new_val) {
        if (tl == tr) {
            t[v] = new Node(new_val, 1, -1, 0);
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }

    private Node query(int v, int tl, int tr, int l, int r) {
        if (l > r) return new Node();
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return merge(query(v * 2, tl, tm, l, Math.min(r, tm)), query(v * 2 + 1, tm + 1, tr, Math.max(l, tm + 1), r));
    }

    public void update(int pos, long new_val) {
        update(1, 0, n - 1, pos, new_val);
    }

    public Node query(int l, int r) {
        return query(1, 0, n - 1, l - 1, r - 1);
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int q = scanner.nextInt();
        long[] arr = new long[n];
        for (int i = 0; i < n; ++i) arr[i] = scanner.nextLong();

        SegmentTree segTree = new SegmentTree(arr);

        for (int i = 0; i < q; ++i) {
            int type = scanner.nextInt();
            if (type == 1) {
                int p = scanner.nextInt();
                long x = scanner.nextLong();
                segTree.update(p - 1, x);
            } else {
                int l = scanner.nextInt();
                int r = scanner.nextInt();
                Node res = segTree.query(l, r);
                System.out.println(res.cnt2);
            }
        }
    }
}
