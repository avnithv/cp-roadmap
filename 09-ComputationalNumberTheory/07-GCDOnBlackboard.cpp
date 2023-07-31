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

const ll MXN = 1e6, MOD = 1e9+7;

vt<ll> sieve(MXN+1, 0), primes;
void precompute_sieve() {
	for (ll i = 2; i <= MXN; i++) {
		if (!sieve[i]) {
			primes.pb(i);
			for (ll j = i * i; j <= MXN; j += i) sieve[j] = i;
		}
	}
}

bool pos(ll n, ll p, ll c) {
	ll ans = 0, np = p;
	while (np <= n) {
		ans += n / np;
		np *= p;
	}
	return ans >= c;
}

ll minn(ll p, ll c) {
	ll l = 1, r = 1e12;
	while (r-l>1) {
		ll m = (l + r) / 2;
		if (pos(m,p,c)) r=m;
		else l=m;
	}
	return r;
}

signed main() {
	//precompute_sieve();
	FASTIO

	int n; cin >> n;
	int log = 32-__builtin_clz(n);
	
	vt<vt<ll>> gcd_table(log+1, vt<ll>((1<<log), 0));
	FORN(i,0,n) cin >> gcd_table[0][i];

	FORN(i,0,log) {
		FORN(j,0,(1<<log)-(1<<i)) {
			gcd_table[i+1][j] = __gcd(gcd_table[i][j], gcd_table[i][j+(1<<i)]);
		}
	}
	auto query = [&] (int i, int j) -> ll {
		if (i > j) return 0;
		int lg = 31-__builtin_clz(j-i+1);
		return __gcd(gcd_table[lg][i], gcd_table[lg][j-(1<<lg)+1]);
	};

	ll ans = 1;
	FORN(i,0,n) {
		chmax(ans, __gcd(query(0, i-1), query(i+1, n-1)));
	}
	cout<<ans<<endl;
}
