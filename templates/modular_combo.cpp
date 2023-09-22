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
