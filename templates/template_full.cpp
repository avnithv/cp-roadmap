#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

/*===============================DEFINES=================================*/

#define pb push_back
#define f first
#define s second
#define endl "\n"
#define mp make_pair
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define TC int tc; cin >> tc; while (tc--) solve();
#define FORN(i, a, b) for(int i = a; i < b; i++)
#define REV(i, b, a) for(int i = b - 1; i >= a; i--)
#define EACH(x, a) for(auto &x : a)
#define DBG(z) FORN(i,0,sz(z))cerr<<z[i]<<" \n"[i==sz(z)-1];
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define log(x) (63-__builtin_clzll(x))
#define tcT template<class T
#define tcTU tcT, class U
#define lb lower_bound
#define ub upper_bound

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
#define RAND(a, b) uniform_int_distribution<ll>(a, b)(rng)

// only in emergencies
#define int ll


using ll = long long;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
tcT> using vt = vector<T>;

const ll RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
tcT> struct chash { 
	const uint64_t C = ll(4e18*acos(0))+71; 
	ll operator()(T x) const { return __builtin_bswap64((((ll)x)^RANDOM)*C); }
};

tcTU> using gp = gp_hash_table<T, U, chash<T>>;
tcT> using pq = priority_queue<T>;
tcT> using qu = queue<T>;
tcT> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
tcT> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
tcTU> using ordered_map = tree<T, U, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

tcT> inline void chmin(T &a, T b) {a = min(a, b);}
tcT> inline void chmax(T &a, T b) {a = max(a, b);}

const ll MOD = 1e9+7;
const ll MXN = 1e5+5;

/*=======================================================================*/
/*============================NUMBER_THEORY==============================*/

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

vt<Mint> fc(MXN+1), iv(MXN+1);
void precompute_factorials() {
	fc[0] = 1;
	FORN(i,1,MXN+1) fc[i] = fc[i-1] * i;
	FORN(i,0,MXN+1) iv[i] = inv(fc[i]);
}
Mint choose(ll n, ll k) { return fc[n] * iv[k] * iv[n-k]; }

vt<ll> sieve(MXN+1, 0), primes;
void precompute_sieve() {
	for (ll i = 2; i * i <= MXN; i++) {
		if (sieve[i]) continue;
		primes.pb(i);
		for (ll j = i * i; j <= MXN; j += i) sieve[j] = i;
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

/*=======================================================================*/
/*================================MISC===================================*/

tcT> struct RollingHash {
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
	RollingHash(T &s) {
		n = sz(s); pow.resize(n+1); pow[0] = 1;
		FORN(i,0,n) pow[i+1] = mod_mul(pow[i], B);
		hsh.resize(n+1); hsh[0] = 0;
		FORN(i,0,n) hsh[i+1] = (mod_mul(hsh[i], B) + s[i]) % M;
	}
	ll hash(int a, int b) { return (hsh[b+1] - mod_mul(hsh[a], pow[b-a+1]) + M) % M; }
};
using HS = RollingHash<str>;

tcT> struct PrefixSum {
	vt<T> arr;
	PrefixSum() : arr(1, 0) {}
	PrefixSum(int n) : arr(n+1, 0) {}
	PrefixSum(vt<T> &ar) : arr(sz(ar)+1, 0) {FORN(i,1,sz(ar)+1) arr[i] = arr[i-1] + ar[i-1];}
	inline T& operator()(int ind) { return arr[ind]; }
	inline T operator[](int ind) {return arr[ind+1] - arr[ind];}
	inline void summarize() { FORN(i,1,sz(arr)+1) arr[i] += arr[i-1]; }
	inline void difference() { REV(i,sz(arr)+1,1) arr[i] -= arr[i-1]; }
	inline T sum(int l, int r) {return arr[r+1] - arr[l];}
	inline void update(int l, int r, T v) {arr[l+1] += v; if (r + 2 < sz(arr)) arr[r+2] -= v;}
	inline int size() {return sz(arr)-1;}
	inline void push_back(T x) { arr.pb(arr.back() + x); }
	inline T back() { return arr.back() - arr[size()-1]; }
	inline void pop_back() { arr.pop_back(); }
};
using PS = PrefixSum<ll>;
using PSM = PrefixSum<Mint>;

tcT> struct DisjointSetUnion {
	vt<T> e;
	DisjointSetUnion(T n) : e(n, -1) { }
	T get(T x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
	bool same_set(T a, T b) { return get(a) == get(b); }
	T operator[](int ind) { return e[ind]; }
	int size() { return sz(e); }
	T setsz(T x) { return -e[get(x)]; }
	bool unite(T x, T y) {  
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x; return true;
	}
};
using DSU = DisjointSetUnion<ll>;

/*=======================================================================*/


void solve() {
	
}

signed main() {
	FASTIO
	TC
}
