/* https://codeforces.com/problemset/problem/1359/D */

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
#define EACH(x, a) for(auto &x : a)
#define DBG(z) FORN(i,0,sz(z))cerr<<z[i]<<" \n"[i==sz(z)-1];
#define DBG2(z) EACH(zzz, z) {DBG(zzz)}
#define SET(arr, val) memset((arr), (val), (sizeof(arr)));
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define log(x) (63-__builtin_clzll(x))
#define tcT template<class T
#define tcTU tcT, class U

// only in emergencies
#define int ll

tcT> using vt = vector<T>;
tcTU> using gp = gp_hash_table<T, U>;
tcT> using pq = priority_queue<T>;
tcT> using qu = queue<T>;

typedef long long ll;
typedef pair<int, int> pi;

const ll mod = 1e9+7;

tcT> void ckmin(T &a, T b) {a = min(a, b);}
tcT> void ckmax(T &a, T b) {a = max(a, b);}

signed main() {
	// dp[i][j] maximum segment ending at i so that the maximum element is at most j
	ll n; cin >> n;
	vt<ll> arr(n);
	EACH(z, arr) cin >> z;

	ll ans = 0;
	vt<vt<ll>> dp(n, vt<ll>(61, -1e18));
	FORN(i,arr[0]+30,61) dp[0][i] = arr[0];
	FORN(i,1,n) {
		FORN(j,0,arr[i]+31) ckmax(dp[i][arr[i]+30], max(0LL, dp[i-1][j]) + arr[i]);
		FORN(j,arr[i]+31,61) ckmax(dp[i][j], max(0LL, dp[i-1][j]) + arr[i]);
		FORN(j,0,61) ckmax(ans, dp[i][j] - (j - 30));
	}
	cout << ans << endl;
}
