// RANGE QUERY IS [INCLUSIVE, EXCLUSIVE) FOR SOME REASON IDK WHY

template <class T> class MinSegmentTree {
	public: 
		const T DEFAULT = 1e18;  // Will overflow if T is an int
		vector<T> segtree;
		int len;
		MinSegmentTree(int _len) : len(_len), segtree(_len * 2, DEFAULT) {}
 		void set(int ind, T val) {
			//cerr<<"set: " << ind << " " << val << endl;
			ind += len;
			segtree[ind] = val;
			for (; ind > 1; ind /= 2) {
				segtree[ind / 2] = std::min(segtree[ind], segtree[ind ^ 1]);
			}
		}
 		T range_min(int start, int end) {
			T sum = DEFAULT;
			//cerr<<"query: "<<start << " " << end;
			for (start += len, end += len; start < end; start /= 2, end /= 2) {
				if (start % 2 == 1) { sum = std::min(sum, segtree[start++]); }
				if (end % 2 == 1) { sum = std::min(sum, segtree[--end]); }
			}
			//cerr << " " <<sum << endl;
			return sum;
		}
};
using mnst = MinSegmentTree<ll>;
 
template <class T> class MaxSegmentTree {
	public: 
		const T DEFAULT = -1e18;  // Will overflow if T is an int
		vector<T> segtree;
		int len;
		MaxSegmentTree(int _len) : len(_len), segtree(_len * 2, DEFAULT) {}
 		void set(int ind, T val) {
			//cerr<<"set: " << ind << " " << val << endl;
			ind += len;
			segtree[ind] = val;
			for (; ind > 1; ind /= 2) {
				segtree[ind / 2] = std::max(segtree[ind], segtree[ind ^ 1]);
			}
		}
 		T range_max(int start, int end) {
			T sum = DEFAULT;
			//cerr<<"query: "<<start << " " << end;
			for (start += len, end += len; start < end; start /= 2, end /= 2) {
				if (start % 2 == 1) { sum = std::max(sum, segtree[start++]); }
				if (end % 2 == 1) { sum = std::max(sum, segtree[--end]); }
			}
			//cerr << " " <<sum << endl;
			return sum;
		}
};
using mxst = MaxSegmentTree<ll>;
