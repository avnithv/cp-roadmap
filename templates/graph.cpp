struct Graph {
	int n; vt<bool> vis; vt<int> par; vt<ll> dist; vt<ll> dp; vt<ppl> edg;
	vt<vt<pl>> adj; // graph[i] = {w, j} --> edge from i to j with weight w
	Graph(ll _n) : n(_n), vis(_n, false), par(_n, -1), dist(_n, INF), dp(_n, 0), adj(_n) {};
	friend void read(Graph &g, ll m, bool direct = false, bool weight = false) {
		FORN(i,0,m) {
			ll a, b, w = 1; cin >> a >> b; a--; b--;
			if (weight) cin >> w;
			g.addEdge(a, b, direct, w);
		}
	}
	ll addVertex() { vis.pb(false); par.pb(-1); dist.pb(INF); adj.resize(++n); return n; }
	void addEdge(ll from, ll to, bool direct = false, ll weight = 1) { 
		adj[from].pb({weight, to}); edg.pb({weight, {from, to}});
		if (!direct) { adj[to].pb({weight, from}); edg.pb({weight, {to, from}}); }
	}
	void reset() { FORN(i,0,n) vis[i] = false; }
	int size() { return sz(adj); }
	void __print() {
		FORN(i,0,sz(adj)) {
			cerr<<i<<endl;
			EACH(z, adj[i]) cerr<<z.f<<" "<<z.s<<endl; cerr<<endl;
		} cerr<<endl;
	}
};

void dfs(Graph &g, int edge = 0, int from = -1) {
	int to = (from == -1 ? edge : (int)g.adj[from][edge].s);
	ll edge_w = (from == -1 ? 0 : g.adj[from][edge].f);

	//cerr<<from<<" "<<edge<<" "<<to<<" "<<d<<endl;

	if (g.vis[to]) return; // remove for trees
	g.vis[to] = true; g.par[to] = from;
	g.dist[to] = (from == -1 ? 0 : g.dist[from]) + w;

	FORN(i,0,sz(g.adj[to])) { 
		int nxt = g.adj[to][i].s;
		if (!g.vis[nxt]) {
			dfs(g, i, to); 
		}
	}
}

void bfs(Graph &g, pq<ppl> &fr) {
	while (!fr.empty()) {
		ppl x = fr.top(); fr.pop(); // distance, parent node, edge 
		ll d = x.f.f; int from = (int)x.f.s, edge = (int)x.s.f;
		int to = (from == -1 ? edge : (int)g.adj[from][edge].s);

		//cerr<<from<<" "<<edge<<" "<<to<<" "<<d<<endl;

		if (g.vis[to]) continue;
		g.vis[to] = true; g.par[to] = from; g.dist[to] = d;

		FORN(i,0,sz(g.adj[to])) { 
			pl nxt = g.adj[to][i];
			if (!g.vis[nxt.s]) {
				fr.push({{d + nxt.f, to}, {i, INF}}); 
			}
		}
	}
}
