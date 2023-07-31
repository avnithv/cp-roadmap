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

int taglia(int n, vector<int> b) {
	precompute_sieve();
	ll sm = 0;
	FORN(i,0,n) sm += (ll)b[i];
	if (sm == 0) {
		ll target = 0, cur = 0, cnt = 0;
		EACH(z, b) {
			cur += (ll)z;
			if (cur == target) {cnt++; cur=0;}
		}
		if (cnt > 1 && cur == 0) return 2;
		else return -1;
	}

	vt<ll> pos;
	EACH(p, primes) { // atmost log(n) primes divide sum
		if (sm % p == 0) {
			ll target = sm / p, cur = 0, cnt = 0;
			EACH(z, b) {
				cur += (ll)z;
				if (cur == target) {cnt++; cur=0;}
			}
			if (cnt == p && cur == 0)	return (int)p;
		}
	}
	return -1;
}

signed main() {
	//precompute_sieve();
	//cout << sz(primes) << endl;
	int n; cin >> n;
	vt<int> b(n);
	FORN(i,0,n) cin >> b[i];
	cout << taglia(n, b) << endl;
}
