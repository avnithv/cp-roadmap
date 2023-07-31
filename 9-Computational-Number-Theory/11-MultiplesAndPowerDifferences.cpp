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

const ll MXN = 1e7, MOD = 1e9+7;

vt<ll> sieve(MXN+1, 0), primes;
void precompute_sieve() {
	primes.reserve(1e6);
	for (ll i = 2; i <= MXN; i++) {
		if (!sieve[i]) {
			primes.pb(i);
			for (ll j = i * i; j <= MXN; j += i) sieve[j] = i;
		}
	}
}

signed main() {
	int n, m; cin >> n >> m;
	vt<vt<int>> a(n, vt<int>(m));
	FORN(i,0,n) {
		FORN(j,0,m) {
			cin >> a[i][j];
		}
	}

	vt<int> k4(17);
	FORN(i,0,17) k4[i] = i*i*i*i;

	int orznumber = 720720;

	vt<vt<int>> b(n, vt<int>(m, 0));	
	FORN(i,0,n) {
		FORN(j,0,m) {
			if ((i+j)&1) cout << orznumber << " ";
			else cout << orznumber - k4[a[i][j]] << " ";
		}
		cout << endl;
	} 

}
