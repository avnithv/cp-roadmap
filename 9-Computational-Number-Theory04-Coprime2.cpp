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

const ll MXN = 1e5, MOD = 1e9+7;

vt<ll> sieve(MXN+1, 0), primes;
void precompute_sieve() {
	for (ll i = 2; i <= MXN; i++) {
		if (!sieve[i]) {
			primes.pb(i);
			for (ll j = i * i; j <= MXN; j += i) sieve[j] = i;
		}
	}
}

signed main() {
	precompute_sieve();
	FASTIO

	ll n, m; cin >> n >> m;
	vt<ll> a(n);
	FORN(i,0,n) cin >> a[i];

	vt<bool> vis(MXN+1, true);
	EACH(z, a) {
		while (sieve[z]) {
			vis[sieve[z]] = false;
			z /= sieve[z];
		}
		if (z != 1) vis[z] = false;
	}

	REV(i,MXN+1,1) {
		if (!vis[i]) {
			for (int j = i; j <= MXN; j += i) {
				vis[j] = false;
			}
		}
	} 

	vt<int> ans;
	FORN(i,1,m+1) {
		if (vis[i]) {
			ans.pb(i);
		}
	}
	cout << sz(ans) << endl;
	EACH(z, ans) cout << z << endl;
}