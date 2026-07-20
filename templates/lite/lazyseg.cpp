template<class T, class U> struct LazySegmentTree {
    int len;
    V<T> tree, lazy;

    const T TD = -INF;
    const U LD = 0;
    T tm(T a, T b) {
        return max(a, b);
    }
    T lm(U a, U b) {
        return a + b;
    }
    T ltm(U a, T b) {
        return a + b;
    }

    LazySegmentTree(int n) {
        len = 1; while (len < n) len *= 2;
        tree.resize(2 * len, TD);
        lazy.resize(2 * len, LD);
    }

    LazySegmentTree(V<T> &arr) {
        len = 1; while (len < arr.size()) len *= 2;
        tree.resize(2 * len, TD);
        lazy.resize(2 * len, LD);
        for (int i = 0; i < arr.size(); i++) tree[i+len] = arr[i];
        for (int i = len-1; i > 0; i--) tree[i] = tm(tree[2*i], tree[2*i+1]);
    }

    void push(int x) {
        // cerr<<"push: "<<x<<endl;
        if (x >= len) return;
        lazy[2*x] = lm(lazy[x], lazy[2*x]); 
        tree[2*x] = ltm(lazy[x], tree[2*x]); 
        lazy[2*x+1] = lm(lazy[x], lazy[2*x+1]); 
        tree[2*x+1] = ltm(lazy[x], tree[2*x+1]); 
        lazy[x] = LD;
    }

    void add(int l, int r, U v, int x, int lx, int rx) {
        // cerr<<"-> add: "<<l<<" "<<r<<" "<<v<<" "<<x<<" "<<lx<<" "<<rx<<endl;
        push(x);
        if (lx >= r || rx <= l) return;
        if (lx >= l && rx <= r) {
            lazy[x] = lm(v, lazy[x]);
            tree[x] = ltm(v, tree[x]);
            return;
        }
        int m = (lx + rx) / 2;
        add(l, r, v, 2*x, lx, m);
        add(l, r, v, 2*x+1, m, rx);
        tree[x] = tm(tree[2*x], tree[2*x+1]);
    }

    T query(int l, int r, int x, int lx, int rx) {
        // cerr<<"-> query: "<<l<<" "<<r<<" "<<x<<" "<<lx<<" "<<rx<<endl;
        push(x);
        if (lx >= r || rx <= l) return TD;
        if (lx >= l && rx <= r) return tree[x];
        int m = (lx + rx) / 2;
        T left = query(l, r, 2*x, lx, m);
        T right = query(l, r, 2*x+1, m, rx);
        return tm(left, right);
    }

    void push_down(int i) {
        if (i > 1) push_down(i/2);
        push(i);
    }

    void set(int i, T v) {
        // cerr<<"set: "<<i<<" "<<v<<endl;
        i += len;
        push_down(i);
        tree[i] = v;
        i /= 2;
        while (i > 0) {
            tree[i] = tm(tree[2*i], tree[2*i+1]);
            i /= 2;
        }
    }

    T get(int i) {
        // cerr<<"get: "<<i<<endl;
        i += len;
        push_down(i);
        return tree[i];
    }

    // [l, r)
    void add(int l, int r, T v) { 
        // cerr<<"add: "<<l<<" "<<r<<" "<<v<<endl;
        add(l, r, v, 1, 0, len); 
    }
    T query(int l, int r) { 
        // cerr<<"query: "<<l<<" "<<r<<endl;
        T ans = query(l, r, 1, 0, len); 
        // cerr<<"ans: "<<ans<<endl;
        return ans;
    }

    void print() {
        cerr<<len<<endl;
        for (auto x : tree) cerr<<x<<" ";
        cerr<<endl;
        for (auto x : lazy) cerr<<x<<" ";
        cerr<<endl;
    }
};
using SegTree = LazySegmentTree<ll, ll>;
