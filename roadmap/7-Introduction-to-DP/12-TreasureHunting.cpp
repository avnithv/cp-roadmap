/* https://atcoder.jp/contests/abc227/tasks/abc227_f */

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

signed main() {
	FASTIO
	
	ll h, w, k; cin >> h >> w >> k;
	vt<vt<ll>> grid(h, vt<ll>(w));
	FORN(i,0,h) {
		FORN(j,0,w) {
			cin >> grid[i][j];
		}
	}

	ll ans = 1e18;
	FORN(a,0,h) {
		FORN(b,0,w) {
			ll kth = grid[a][b];
			vt<vt<vt<ll>>> dp(h, vt<vt<ll>>(w, vt<ll>(k+1, 1e18)));
			if (grid[0][0] >= kth) dp[0][0][1] = grid[0][0]; 
			else dp[0][0][0] = 0;
			FORN(i,0,h){
				FORN(j,0,w) {
					FORN(l,0,k+1) {
						if (i != 0) {
							if (grid[i][j] <= kth) chmin(dp[i][j][l], dp[i-1][j][l]);
							if (grid[i][j] >= kth && l != 0) chmin(dp[i][j][l], dp[i-1][j][l-1] + grid[i][j]);
						}
						if (j != 0) {
							if (grid[i][j] <= kth) chmin(dp[i][j][l], dp[i][j-1][l]);
							if (grid[i][j] >= kth && l != 0) chmin(dp[i][j][l], dp[i][j-1][l-1] + grid[i][j]);
						}
					}
				}
			}
			chmin(ans, dp[h-1][w-1][k]);
		}
	}
	cout << ans << endl;
}
