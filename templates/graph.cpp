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
	vt<vt<pl>> adj; // graph[i] = {w, j} --> edge from i to j with weight w
	Graph(ll n) : adj(n) {};
	friend void read(Graph &g, ll m, bool direct = false, bool weight = false) {
		FORN(i,0,m) {
			ll a, b, w = 1; cin >> a >> b; a--; b--;
			if (weight) cin >> w;
			g.addEdge(a, b, direct, w);
		}
	}
	ll addVertex() { adj.resize(sz(adj)+1); return sz(adj)-1; }
	void addEdge(ll from, ll to, bool direct = false, ll weight = 1) { 
		adj[from].pb({weight, to}); 
		if (!direct) adj[to].pb({weight, from}); 
	}
	int size() { return sz(adj); }
	void print() {
		FORN(i,0,sz(adj)) {
			cerr<<i<<endl;
			EACH(z, adj[i]) cerr<<z.f<<" "<<z.s<<endl;
			cerr<<endl;
		}
		cerr<<endl;
	}
};

struct BaseDFS {
	Graph* graph;
	int cs = -1; // # of components
	vt<bool> vis; // visited
	vt<int> par, comp; // parent node, component #
	vt<ll> dist; // distance
	BaseDFS(Graph &g) : vis(sz(g), false), par(sz(g), -1), comp(sz(g), -1), dist(sz(g), INF) { graph = &g; }
	virtual void dfsProcess(int from, int edge, int to) = 0;
	void dfs(int start) {
		vt<pi> fr; fr.pb({-1, start}); // parent node, edge
		while (!fr.empty()) {
			pi x = fr.back(); fr.pop_back(); int from = x.f, edge = x.s;
			int to = (from == -1 ? edge : (int)graph->adj[from][edge].s);
			
			dfsProcess(from, edge, to);

			if (vis[to]) continue;
			vis[to] = true; par[to] = from; comp[to] = cs;
			dist[to] = (from == -1 ? 0 : dist[from] + graph->adj[from][edge].f);
			FORN(i,0,sz(graph->adj[to])) { if (!vis[graph->adj[to][i].s]) fr.pb({to, i}); }
		}
	}
	void dfsAll() {
		for (int i = 0; i < graph->size(); i++) {
			if (vis[i]) continue;
			cs++; dfs(i);
		}
	}
};

struct BaseBFS {
	Graph* graph;
	int cs = -1; // # of components
	vt<bool> vis; // visited
	vt<int> par, comp; // parent node, component #
	vt<ll> dist; // distance
	BaseBFS(Graph &g) : vis(sz(g), false), par(sz(g), -1), comp(sz(g), -1), dist(sz(g), INF) { graph = &g; }
	virtual void bfsProcess(ll d, int from, int edge, int to) = 0;
	void bfs(int start) {
		pq<tuple<ll, int, int>> fr; fr.push({0, -1, start}); // distance, parent node, edge
		while (!fr.empty()) {
			ll d; int from, edge; tie(d, from, edge) = fr.top(); fr.pop();
			int to = (from == -1 ? edge : (int)graph->adj[from][edge].s);
			
			bfsProcess(d, from, edge, to);

			if (vis[to]) continue;
			vis[to] = true; par[to] = from; 
			comp[to] = cs; dist[to] = d;

			FORN(i,0,sz(graph->adj[to])) { 
				if (!vis[graph->adj[to][i].s]) {
					fr.push({d + graph->adj[to][i].f, to, i}); 
				}
			}
		}
	}
	void bfsAll() {
		for (int i = 0; i < graph->size(); i++) {
			if (vis[i]) continue;
			cs++; bfs(i);
		}
	}
};

struct ShortestPath : BaseBFS {
	ShortestPath(Graph &g) : BaseBFS(g) {}
	void bfsProcess(ll d, int from, int edge, int to) {}
	vt<int> spath(int a, int b) {
		vt<int> rev(1, b), ans;
		cs = max(0, comp[a]); bfs(a);
		if (comp[a] != comp[b]) return ans;
		while (b != a) rev.pb(b = par[b]);
		REV(i,sz(rev),0) ans.pb(rev[i]);
		return ans;
	}
};

struct TwoCol : BaseBFS {
	bool possible = true;
	vt<int> col;
	TwoCol(Graph &g) : BaseBFS(g), col(sz(g), -1) {}
	void bfsProcess(ll d, int from, int edge, int to) {
		if (vis[to]) possible &= (col[from] != col[to]);
		else if (from == -1) col[to] = 0;
		else col[to] = !col[from];
	}
};


struct Cycle : BaseDFS {
	pi ans = mp(-1, -1);
	Cycle(Graph &g) : BaseDFS(g) {}
	void dfsProcess(int from, int edge, int to) {
		EACH(edg, graph->adj[to]) {
			if (edg.s != from && !vis[to] && vis[edg.s] && ans.f == -1) {
				ans = mp(to, edg.s);
			}
		}
	}
};
