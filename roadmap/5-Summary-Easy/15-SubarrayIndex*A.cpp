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

const ll MXN = 1e5+5, MOD = 1e9+7;

signed main() {
	FASTIO
	
	ll n, m; cin >> n >> m;
	vt<ll> arr(n), pref(n+1, 0);
	FORN(i,0,n) cin >> arr[i];
	FORN(i,1,n+1) pref[i] = pref[i-1] + arr[i-1];

	ll cur = 0;
	FORN(i,0,m) cur += (i+1) * arr[i];
	ll ans = cur;
	FORN(i,m,n) {
		cur -= pref[i] - pref[i-m];
		cur += m * arr[i];
		chmax(ans, cur);
	}
	cout << ans << endl;

}
