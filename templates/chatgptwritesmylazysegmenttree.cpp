
template <typename T>
struct SegmentTree {
    // CHANGE HERE
    static constexpr T = INF;
    //static constexpr pl DEFAULT = mp(INF, INF);
    struct Node {
        T val, lazy;
        Node() : val(DEFAULT), lazy(DEFAULT) {}
    };

    int n;
    vector<Node> tree;

    SegmentTree(int size) {
        n = size;
        tree.resize(4 * n);
    }

    // Update the tree with lazy propagation
    void update(int v, int tl, int tr, int l, int r, T x) {
        if (l > r) return;
        if (l == tl && r == tr) {
            tree[v].val = min(tree[v].val, x);
            tree[v].lazy = min(tree[v].lazy, x);
            return;
        }
        int tm = (tl + tr) / 2;
        int leftChild = v * 2;
        int rightChild = v * 2 + 1;

        // Propagate the lazy update
        tree[leftChild].val = min(tree[leftChild].val, tree[v].lazy);
        tree[rightChild].val = min(tree[rightChild].val, tree[v].lazy);
        tree[leftChild].lazy = min(tree[leftChild].lazy, tree[v].lazy);
        tree[rightChild].lazy = min(tree[rightChild].lazy, tree[v].lazy);
        tree[v].lazy = DEFAULT;

        if (r <= tm) {
            update(leftChild, tl, tm, l, r, x);
        } else if (l > tm) {
            update(rightChild, tm + 1, tr, l, r, x);
        } else {
            update(leftChild, tl, tm, l, tm, x);
            update(rightChild, tm + 1, tr, tm + 1, r, x);
        }
        tree[v].val = min(tree[leftChild].val, tree[rightChild].val);
    }

    // Query the minimum in the given range
    T query(int v, int tl, int tr, int l, int r) {
        if (l > r) return DEFAULT;
        if (l == tl && r == tr) {
            return tree[v].val;
        }
        int tm = (tl + tr) / 2;
        int leftChild = v * 2;
        int rightChild = v * 2 + 1;

        // Propagate the lazy update
        tree[leftChild].val = min(tree[leftChild].val, tree[v].lazy);
        tree[rightChild].val = min(tree[rightChild].val, tree[v].lazy);
        tree[leftChild].lazy = min(tree[leftChild].lazy, tree[v].lazy);
        tree[rightChild].lazy = min(tree[rightChild].lazy, tree[v].lazy);
        tree[v].lazy = DEFAULT;

        if (r <= tm) {
            return query(leftChild, tl, tm, l, r);
        } else if (l > tm) {
            return query(rightChild, tm + 1, tr, l, r);
        } else {
            T leftResult = query(leftChild, tl, tm, l, tm);
            T rightResult = query(rightChild, tm + 1, tr, tm + 1, r);
            return min(leftResult, rightResult);
        }
    }

    // Range update operation
    void updateRange(int l, int r, T x) {
        update(1, 0, n - 1, l, r, x);
    }

    // Minimum query operation
    T queryMin(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }
};
