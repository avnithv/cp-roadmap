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
