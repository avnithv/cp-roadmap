tcT> struct DisjointSetUnion {
	vt<T> e;
	DisjointSetUnion(T n) : e(n, -1) { }
	T get(T x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool same_set(T a, T b) { return get(a) == get(b); }
	T operator[](int ind) { return e[ind]; }
	int size() { return sz(e); }
	T setsz(T x) { return -e[get(x)]; }
	bool unite(T x, T y) {  
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x; return true;
	}
};
using DSU = DisjointSetUnion<ll>;
