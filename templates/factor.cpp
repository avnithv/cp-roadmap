
vt<Mint> fc(MXN+1), iv(MXN+1);
void precompute_factorials() {
	fc[0] = 1;
	FORN(i,1,MXN+1) fc[i] = fc[i-1] * i;
	FORN(i,0,MXN+1) iv[i] = inv(fc[i]);
}
Mint choose(ll n, ll k) { return fc[n] * iv[k] * iv[n-k]; }

vt<ll> sieve(MXN+1, 0), primes;
void precompute_sieve() {
	for (ll i = 2; i <= MXN; i++) {
		if (sieve[i]) continue;
		primes.pb(i);
		for (ll j = i * i; j <= MXN; j += i) sieve[j] = i;
	}
}
vt<ll> factor_with_sieve(ll n) { // O(log N), N <= MXN
	vt<ll> fs;
	while (sieve[n]) {
		fs.pb(sieve[n]);
		n /= sieve[n];
	}
	if (n != 1) fs.pb(n);
	sort(all(fs));
	return fs;
}
vt<ll> factor_with_primes(ll n) { // O(|primes|), N <= MXN^2
	vt<ll> facts;
	EACH(p, primes) {
		while (n % p == 0) {
			facts.pb(p);
			n /= p;
		}
	}
	if (n != 1) facts.pb(n);
	return facts;
}
