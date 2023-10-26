tcT> struct LazySegmentTree {
    int len;
    vt<T> tree, lazy;

    LazySegmentTree(int n) {
        len = 1; while (len < n) len *= 2;
        tree.resize(2 * len, TREE_DEFAULT);
        lazy.resize(2 * len, LAZY_DEFAULT);
    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1) return;
        lazy_merged(lazy[2 * x + 1], lazy[x]);
        lazy_merged(lazy[2 * x + 2], lazy[x]);
        lazy_merged(tree[2 * x + 1], lazy[x]);
        lazy_merged(tree[2 * x + 2], lazy[x]);
        lazy[x] = LAZY_DEFAULT;
    }

    void add(int l, int r, T v, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            lazy_merged(lazy[x], v);
            lazy_merged(tree[x], v);
            return;
        }
        int m = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, m);
        add(l, r, v, 2 * x + 2, m, rx);
        tree[x] = tree_merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    T query(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);
        if (lx >= r || rx <= l) return TREE_DEFAULT;
        if (lx >= l && rx <= r) return tree[x];
        int m = (lx + rx) / 2;
        T left = query(l, r, 2 * x + 1, lx, m);
        T right = query(l, r, 2 * x + 2, m, rx);
        return tree_merge(left, right);
    }

    void add(int l, int r, T v) { add(l, r, v, 0, 0, len); }
    T query(int l, int r) { return query(l, r, 0, 0, len); }
    void tree_merged(T &a, T b) { a = tree_merge(a, b); }
    void lazy_merged(T &a, T b) { a = lazy_merge(a, b); }

    // CHANGE THESE
    static constexpr T TREE_DEFAULT = 0;
    static constexpr T LAZY_DEFAULT = 0;
    static constexpr T QUERY_DEFAULT = -INF;

    // max, min
    T tree_merge(T a, T b) {
        return max(a, b);
    }

    // add, min, max
    T lazy_merge(T a, T b) {
        return a + b;
    }
};
using SegTree = LazySegmentTree<ll>;
