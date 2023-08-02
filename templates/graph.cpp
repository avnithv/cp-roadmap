#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define f first
#define s second
#define endl "\n"
#define mp make_pair
#define FORN(i, a, b) for(int i = a; i < b; i++)
#define EACH(x, a) for(auto &x : a)
#define sz(x) (int)(x).size()
#define tcT template<class T
#define tcTU tcT, class U

using ll = long long;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
tcT> using vt = vector<T>;

tcT> using pq = priority_queue<T, vt<T>, greater<T>>;

const ll INF = 1e18;

struct Graph {
	int cs = 0; vt<bool> vis; vt<int> par, comp; vt<ll> dist;
	vt<vt<pl>> adj; // graph[i] = {w, j} --> edge from i to j with weight w
	Graph(ll n) : vis(n, false),  par(n, -1), comp(n, -1), dist(n, INF), adj(n) {};
	friend void read(Graph &g, ll m, bool direct = false, bool weight = false) {
		FORN(i,0,m) {
			ll a, b, w = 1; cin >> a >> b; a--; b--;
			if (weight) cin >> w;
			g.addEdge(a, b, direct, w);
		}
	}
	ll addVertex() { vis.pb(false); par.pb(-1); dist.pb(INF); adj.resize(sz(adj)+1); return sz(adj)-1; }
	void addEdge(ll from, ll to, bool direct = false, ll weight = 1) { 
		adj[from].pb({weight, to}); 
		if (!direct) adj[to].pb({weight, from}); 
	}
	int size() { return sz(adj); }
	void __print() {
		FORN(i,0,sz(adj)) {
			cerr<<i<<endl;
			EACH(z, adj[i]) cerr<<z.f<<" "<<z.s<<endl;
			cerr<<endl;
		}
		cerr<<endl;
	}
};

void dfs(Graph &g, int edge = 0, int from = -1) {
	int to = (from == -1 ? edge : (int)g.adj[from][edge].s);

	// process

	if (g.vis[to]) return;
	g.vis[to] = true; g.par[to] = from; g.comp[to] = g.cs;
	g.dist[to] = (from == -1 ? 0 : g.dist[from] + g.adj[from][edge].f);
	FORN(i,0,sz(g.adj[to])) { if (!g.vis[g.adj[to][i].s]) dfs(g, i, to); }
}


void bfs(Graph &g, int start = 0) {
	pq<tuple<ll, int, int>> fr; fr.push({0, -1, start}); // distance, parent node, edge
	while (!fr.empty()) {
		ll d; int from, edge; tie(d, from, edge) = fr.top(); fr.pop();
		int to = (from == -1 ? edge : (int)g.adj[from][edge].s);
			
		// process
		//cerr<<from<<" "<<edge<<" "<<to<<" "<<d<<endl;

		if (g.vis[to]) continue;
		g.vis[to] = true; g.par[to] = from; g.comp[to] = g.cs; g.dist[to] = d;

		FORN(i,0,sz(g.adj[to])) { 
			if (!g.vis[g.adj[to][i].s]) {
				fr.push({d + g.adj[to][i].f, to, i}); 
			}
		}
	}
}
