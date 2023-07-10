/* https://training.olinfo.it/#/task/preoii_yutaka/statement */
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
// #define int ll

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

const ll MOD = 1e9+7, MXN = 1e6;

inline void norm(ll &x) {
    while (x >= MOD) x -= MOD;
    while (x < 0) x += MOD;
}

signed main() {
	FASTIO

	ll n; cin >> n;
	vt<ll> arr(n);
	EACH(z, arr) cin >> z;
	
	vt<ll> prev(n, -1), nxt(n, n);
    gp<int, int> table, table2;
    FORN(i,0,n) {
        if (table[arr[i]]) prev[i] = table[arr[i]] - 1;
        table[arr[i]] = i + 1;
    }
    REV(i,n,0) {
        if (table2[arr[i]]) nxt[i] = table2[arr[i]] - 1;
        table2[arr[i]] = i + 1;
    }

	vt<bool> flag(n, false);
	set<ll> st;
	FORN(i,0,n) {
		ll l = prev[i], r = nxt[i];
		if (l != -1) st.erase(i);
		vt<ll> fs;
		for (auto it2 = upper_bound(all(st), r); it2 != st.end(); it2++) fs.pb(*it2);
		EACH(f, fs) flag[f] = true;
		EACH(f, fs) st.erase(f);
		if (r != n) st.insert(r);
	}
	
	vt<vt<ll>> dp(n, vt<ll>(2, 0));
	vt<ll> pref(n+1, 0);
	pref[1] = 1;
	dp[0][1] = 1;
	FORN(i,1,n) {
		dp[i][1] += dp[i-1][0] + dp[i-1][1]; dp[i][1] %= MOD;
		pref[i+1] += pref[i] + dp[i][1]; pref[i+1] %= MOD;

		ll k = prev[i];
		if (k != -1 && !flag[i]) dp[i][0] += pref[i] - pref[k+1];
		else dp[i][0] = dp[i][1];
		dp[i][0] %= MOD;
	}
	cout << (int)((dp[n-1][0] + dp[n-1][1] + MOD + MOD) % MOD) << endl;
}
