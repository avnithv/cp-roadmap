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
	int n, m; cin >> n >> m;
	vt<vt<ll>> party(m);
	vt<vt<bool>> did(n, vt<bool>(n, false));
	FORN(i,0,m) {
		int k; cin >> k;
		FORN(j,0,k) {
			int x; cin >> x; x--;
			party[i].pb(x);
		}
		FORN(a,0,k) {
			FORN(b,a,k) {
				did[party[i][a]][party[i][b]] = true;
				did[party[i][b]][party[i][a]] = true;
			}
		}
	}
	bool ans = true;
	FORN(i,0,n) {
		FORN(j,0,n) {
			ans &= did[i][j];
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
}
