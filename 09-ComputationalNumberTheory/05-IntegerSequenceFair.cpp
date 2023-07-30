#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define f first
#define s second
#define endl "\n"
#define mp make_pair
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define TC int tc; cin >> tc; while (tc--) solve();
#define FORN(i,a,b) for(int i=a; i<b; i++)
#define REV(i,b,a) for(int i=b-1; i>=a; i--)
#define EACH(x, a) for (auto &x: a)
#define DBG(z) FORN(i,0,sz(z))cerr<<z[i]<<" \n"[i==sz(z)-1];

#define sz(a) (int)a.size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define lb lower_bound
#define ub upper_bound

using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
template<class T> using vt = vector<T>;

template<class T> void chmin(T &a, T b) {a = min(a, b);}
template<class T> void chmax(T &a, T b) {a = max(a, b);}

const ll MXN = 1e5, MOD = 998244353;

ll mpow(ll a, ll b, ll m)  {
	if (b == 0) return 1;
	ll x = mpow(a, b/2, m);
	return (x * x % m) * (b & 1 ? a : 1) % m;
}

signed main() {
	FASTIO

	// m ^ {k ^ n}
	ll n, k, m; cin >> n >> k >> m;
	k %= MOD - 1; m %= MOD;
	if (m == 0) {cout << 0 << endl; return 0;}
	if (k == 0) {cout << m << endl; return 0;}
	cout << mpow(m, mpow(k, n, MOD-1), MOD) << endl;
}
