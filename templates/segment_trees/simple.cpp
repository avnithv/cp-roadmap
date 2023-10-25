tcT> class SimpleSegmentTree {
	int len;
    vector<T> segtree;
	static constexpr T DEFAULT = 1e18;
	SimpleSegmentTree(int _len) : len(_len), segtree(_len * 2, DEFAULT) {}
 	void set(int ind, T val) {
		//cerr<<"set: " << ind << " " << val << endl;
		ind += len; segtree[ind] = val;
		for (; ind > 1; ind /= 2) segtree[ind / 2] = merge(segtree[ind], segtree[ind ^ 1]);
	}
 	T query(int start, int end) {
		//cerr<<"query: "<< start << " " << end;
		T res = DEFAULT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if (start % 2 == 1) { res = merge(res, segtree[start++]); }
			if (end % 2 == 1) { res = merge(res, segtree[--end]); }
		}
		//cerr << " " << res << endl;
    	return res;
	}
    T merge(T a, T b) { return min(a, b); }
};
using SegTree = SimpleSegmentTree<ll>;
