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
#
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
	ll n; cin >> n;
	vt<ll> a(n);
	FORN(i,0,n) cin >> a[i];
	sort(all(a));
	int ind = unique(all(a))-a.begin();
	while (ind < n) {a[ind]=1e9+1; ind++;}


	int vol = 1, r = n;
	FORN(i,0,r) {
		if (a[i] != vol) {
			if (r-i<2) break;
			r -= 2; i--;			
		}
		vol++;
	}
	cout << vol-1 <<endl;
}
