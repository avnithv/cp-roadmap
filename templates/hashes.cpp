#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using str = string;
template<class T> using vt = vector<T>;

#define FORN(i,a,b) for(int i = a; i < b; i++)
#define sz(a) (int)a.size()

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
#define RAND(a, b) uniform_int_distribution<ll>(a, b)(rng)

/* ========================================================================== */
/* ========================================================================== */

template<class T> struct RollingHash {
	int n;
	const ll M = (1ULL<<61) - 1, B = RAND(0, M - 1);
	vt<ll> pow, hsh;
	ll mod_mul(ll a, ll b) {
		ll res = 0; a %= M;
		while (b) {
			if (b & 1) res = (res + a) % M;
			a = (2 * a) % M;
			b >>= 1;
		}
		return res;
	}
	//ll mod_mul(ll a, ll b) { return ((__int128)a*b) % M; }
	Hash(T &s) {
		n = sz(s); pow.resize(n+1); pow[0] = 1;
		FORN(i,0,n) pow[i+1] = mod_mul(pow[i], B);
		hsh.resize(n+1); hsh[0] = 0;
		FORN(i,0,n) hsh[i+1] = (mod_mul(hsh[i], B) + s[i]) % M;
	}
	ll hash(int a, int b) { return (hsh[b+1] - mod_mul(hsh[a], pow[b-a+1]) + M) % M; }
};
using HSTR = RollingHash<str>;
