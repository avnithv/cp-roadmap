// https://atcoder.jp/contests/abc456/tasks/abc456_f
template<class T> class SegmentTree {
    int len;
    V<T> tree;

    const T TD = {0, inf, inf, 0};
    T tm(T a, T b) {
        T c{
            min(a[0]+b[0], a[1]+b[2]),
            min(a[0]+b[1], a[1]+b[3]),
            min(a[2]+b[0], a[3]+b[2]),
            min(a[2]+b[1], a[3]+b[3])
        };
        FORN(i,0,4) {
            if (c[i] > inf) {
                c[i] = inf;
            }
        }
        return c;
    }

    public: SegmentTree(int n) {
        len = 1; while (len < n) len *= 2;
        tree.resize(2 * len, TD);
    }

    public: SegmentTree(V<T> &arr) {
        len = 1; while (len < arr.size()) len *= 2;
        tree.resize(2 * len, TD);
        for (int i = 0; i < arr.size(); i++) tree[i+len] = arr[i];
        for (int i = len-1; i > 0; i--) tree[i] = tm(tree[2*i], tree[2*i+1]);
    }

    void set(int i, T v) {
        // cerr<<"set: "<<i<<" "<<v<<endl;
        i += len;
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
        return tree[i];
    }

    // [L, R)
 	T query(int start, int end) {
		//cerr<<"query: "<< start << " " << end;
		T resl = TD, resr = TD;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { resl = tm(resl, tree[start++]); }
			if (end % 2 == 1) { resr = tm(tree[--end], resr); }
		}
		//cerr << " " << res << endl;
    	return tm(resl,resr);
	}
};
using SegTree = SegmentTree<array<int, 4>>;
