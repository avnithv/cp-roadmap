#include <bits/stdc++.h>

using namespace std;

#define FORN(i,a,b) for(int i = a; i < b; i++)
#define sz(a) (int)a.size()

using ll = long long;
const ll MOD = 1e9+7;
const ll MXN = 1e5+5;

/*==============MODULAR==============*/

ll mpw(ll &a, ll &b) {
    if (!b) return 1;
    ll x = mpw(a, b/2);
    return ((x * x) % MOD) * (b & 1 ? a : 1) % MOD;
}

inline ll inv(ll x) {
    return pow(x, mod - 2);
}

inline ll norm(ll x) {
    return (x % MOD + MOD) % MOD;
}

template<int MOD> struct Modular {
	static const int mod = MOD;
	int v; explicit operator int() const { return v; } // explicit -> don't silently convert to int
	Modular():v(0) {}
	Modular(ll _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD); if (v < 0) v += MOD; }
	bool operator==(const Modular& o) const { return v == o.v; }
	friend bool operator!=(const Modular& a, const Modular& b) { return !(a == b); }
	friend bool operator<(const Modular& a, const Modular& b) { return a.v < b.v; }
	Modular& operator+=(const Modular& o) { if ((v += o.v) >= MOD) v -= MOD; return *this; }
	Modular& operator-=(const Modular& o) { if ((v -= o.v) < 0) v += MOD; return *this; }
	Modular& operator*=(const Modular& o) { v = int((ll)v*o.v%MOD); return *this; }
	Modular& operator/=(const Modular& o) { return (*this) *= inv(o); }
	friend Modular mpw(Modular a, ll p) {
		Modular ans = 1; 
		for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans; }
	friend Modular inv(const Modular& a) { return mpw(a,MOD-2); }
	Modular operator-() const { return Modular(-v); }
	Modular& operator++() { return *this += 1; }
	Modular& operator--() { return *this -= 1; }
	friend Modular operator+(Modular a, const Modular& b) { return a += b; }
	friend Modular operator-(Modular a, const Modular& b) { return a -= b; }
	friend Modular operator*(Modular a, const Modular& b) { return a *= b; }
	friend Modular operator/(Modular a, const Modular& b) { return a /= b; }
	friend istream& operator>>(istream& inp, Modular& a) { ll x; cin >> x; a = Modular(x); return inp;}
	friend ostream& operator<<(ostream& out, const Modular& a) { out << a.v; return out; }
};
using Mint = Modular<MOD>;
using pM = pair<Mint, Mint>;

/*=============COMBO=============*/

vt<ll> fc(MXN+1), iv(MXN+1);
void precompute_factorials() {
	fc[0] = 1;
	FORN(i,1,MXN+1) fc[i] = (fc[i-1] * i) % MOD;
	FORN(i,0,MXN+1) iv[i] = inv(fc[i]);
}
ll choose(ll n, ll k) { return (fc[n] * iv[k] % MOD) * iv[n-k] % MOD; }


/*=============SIEVE=============*/

vt<ll> sieve(MXN+1, 0), primes;
void precompute_sieve() {
	for (int i = 2; i * i <= MXN; i++) {
		if (sieve[i]) continue;
		primes.pb(i);
		for (int j = i * i; j <= MXN; j += i) sieve[j] = i;
	}
}
vt<pl> factor(ll n) {
	vt<pl> fs;
	while (sieve[n]) {
		ll c = sieve[n], f = 0;
		while (sieve[n] == c) {
			n /= c;
			f++;
		}
		fs.pb(mp(c, f));
	}
	return fs;
}

/*==============NTT==============*/
/*=========SOURCE:KACTL==========*/

void ntt(vt<ll> &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vt<ll> rt(2, 1);
	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		ll z[] = {1, mpw(root, MOD >> s)};
		FORN(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % MOD;
	}
	vt<int> rev(n);
	FORN(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	FORN(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) FORN(j,0,k) {
			ll z = rt[j + k] * a[i + j + k] % MOD, &ai = a[i + j];
			a[i + j + k] = ai - z + (z > ai ? MOD : 0);
			ai += z; ai %= MOD;
		}
}
 
vt<ll> conv(const vt<ll> &a, const vt<ll> &b) {
	if (a.empty() || b.empty()) return {};
	int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
	int inverse = inv(n);
	vt<ll> L(a), R(b), out(n);
	L.resize(n), R.resize(n);
	ntt(L), ntt(R);
	FORN(i,0,n) out[-i & (n - 1)] = (ll)L[i] * R[i] % MOD * inverse % MOD;
	ntt(out);
	return {out.begin(), out.begin() + s};
}

