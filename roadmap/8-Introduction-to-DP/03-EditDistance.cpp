/* https://cses.fi/problemset/task/1639 */

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

const ll MOD = 1e9+7;

signed main() {
	FASTIO
	
	string a, b;
	cin >> a >> b;

	vt<vt<ll>> dp(sz(a)+1, vt<ll>(sz(b)+1, 1e18));
	dp[0][0] = 0;
	FORN(i,1,sz(a)+1) dp[i][0] = i;
	FORN(i,1,sz(b)+1) dp[0][i] = i;
	FORN(i,1,sz(a)+1) {
		FORN(j,1,sz(b)+1) {
			chmin(dp[i][j], dp[i-1][j] + 1);
			chmin(dp[i][j], dp[i][j-1] + 1);
			chmin(dp[i][j], dp[i-1][j-1] + (a[i-1] == b[j-1] ? 0 : 1));
		}
	}
	cout << dp[sz(a)][sz(b)] << endl;
}
