/* https://codeforces.com/problemset/problem/1517/D */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define f first
#define s second
#define endl "\n"
#define mp make_pair
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define TC int tc; cin >> tc; while (tc--) solve();
#define FORN(i, a, b) for(int i = a; i < b; i++)
#define REV(i, b, a) for(int i = b - 1; i >= a; i--)
#define EACH(x, a) for(auto &x : a)
#define DBG(z) FORN(i,0,sz(z))cerr<<z[i]<<" \n"[i==sz(z)-1];
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define log(x) (63-__builtin_clzll(x))
#define tcT template<class T
#define tcTU tcT, class U

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
#define RAND(a, b) uniform_int_distribution<ll>(a, b)(rng)

// only in emergencies
#define int ll

using ll = long long;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
tcT> using vt = vector<T>;
tcTU> using gp = gp_hash_table<T, U>;
tcT> using pq = priority_queue<T>;
tcT> using qu = queue<T>;

tcT> inline void chmin(T &a, T b) {a = min(a, b);}
tcT> inline void chmax(T &a, T b) {a = max(a, b);}

const ll MOD = 1e9+7, MXN = 1e5;

signed main() {
	FASTIO
	
	ll n, m, k; cin >> n >> m >> k;
	
	if (k & 1) {
		FORN(i,0,n) {
			FORN(j,0,m) {
				cout << "-1" << " \n"[j==m-1];
			}
		}
		return 0;
	}

	k /= 2;
	ll l = n * m;

	vt<vt<pl>> graph(l);
	FORN(i,0,n) {
		FORN(j,0,m-1) {
			ll z = i * m + j, x; cin >> x;
			graph[z].pb(mp(x, z+1));
			graph[z+1].pb(mp(x, z));
		}
	}
	FORN(i,0,n-1) {
		FORN(j,0,m) {
			ll z = i * m + j, x; cin >> x;
			graph[z].pb(mp(x, z+m));
			graph[z+m].pb(mp(x, z));
		}
	}

	vt<vt<ll>> dp(l, vt<ll>(k+1, 1e18)); // dp[i][j] = min bored for path of length j out of node i
	FORN(i,0,l) dp[i][0] = 0;
	FORN(i,1,k+1) {
		FORN(j,0,l) {
			EACH(edg, graph[j]) {
				chmin(dp[j][i], dp[edg.s][i-1] + edg.f);
			}
		}
	} 

	// now make dp[i][j] = min bored for path of length 2 * j returning to i
	FORN(i,0,l) {
		FORN(j,1,k+1) {
			dp[i][j] *= 2;
			for (int a = 1; j * a <= k; a++) {
				chmin(dp[i][j*a], dp[i][j] * a);
			}
		}

	}

	FORN(i,0,n) {
		FORN(j,0,m) {
			cout << dp[i*m+j][k] << " \n"[j==m-1];
		}
	}
}
