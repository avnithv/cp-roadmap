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
	ll n, q; cin >> n >> q;
	vt<ll> a(n), b(n);
	FORN(i,0,n) a[i] = i;
	FORN(i,0,n) b[i] = i;

	while (q--) {
		int x; cin >> x; x--;
		if (b[x] == n-1) {
			int l = a[b[x]-1];
			swap(a[b[x]-1], a[b[x]]);
			b[l]++; b[x]--;
		} else {
			int r = a[b[x]+1];
			swap(a[b[x]+1], a[b[x]]);
			b[r]--; b[x]++;
		}
	}

	FORN(i,0,n) cout << a[i]+1 << " \n"[i==n-1];
}
