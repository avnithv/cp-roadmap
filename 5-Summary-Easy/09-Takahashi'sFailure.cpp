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
	int n, k; cin >> n >> k;
	vt<int> a(n), b(k);
	FORN(i,0,n) cin >> a[i];
	FORN(i,0,k) cin >> b[i];
	int ma = -1, mb = -1;
	EACH(z, a) chmax(ma, z);
	EACH(z, b) chmax(mb, a[z-1]);
	//cerr<<ma<<" "<<mb<<endl;
	cout << (ma == mb ? "YES" : "NO") << endl;
}
