struct Trie {
	int k;
	vt<vt<int>> node;
	vt<int> ind;

	Trie(int kk) : k(kk), node(1, vt<int>(2, -1)), ind(1, -1) {}

	void addNode(int x, int index) {
		int cur = 0;
		REV(i,k,0) {
			// cerr<<i<<" "<<cur<<endl;
			int v = !!(x & (1 << i));
			if (node[cur][v] == -1) {
				node.pb({-1, -1});
				ind.pb(index);
				node[cur][v] = sz(node)-1;
			}
			cur = node[cur][v];
		}
	}

	// CF #888 F: Lisa & Martians
	vt<int> maxOp(int x) {
		int ans = 0, res = 0, cur = 0;
		REV(i,k,0) {
			// cerr<<i<<" "<<cur<<endl;
			int v = !!(x & (1 << i));
			if (node[cur][v] != -1) {
				ans |= (1 << i);
				if (!v) res |= (1 << i);
			} else if (node[cur][!v] != -1) {
				v = !v;
			} else return {-1, -1, -1};
			cur = node[cur][v];
		}
		return {ans, res, ind[cur]};
	}
};
