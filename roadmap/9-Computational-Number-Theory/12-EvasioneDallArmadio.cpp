#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define FORN(i,a,b) for(int i = a; i < b; i++)
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()

using ll = long long;
template<class T> using vt = vector<T>;
const ll MXN = 4e6+1;

vt<ll> sieve(MXN+1, 0), primes;
void precompute_sieve() {
	for (ll i = 2; i <= MXN; i++) {
		if (!sieve[i]) {
			primes.pb(i);
			for (ll j = i * i; j <= MXN; j += i) sieve[j] = i;
		}
	}
}

vt<ll> prime_factors(ll n) {
	vt<ll> fact;
	while (sieve[n]) {
		fact.pb(sieve[n]);
		n /= sieve[n];
	}
	if (n != 1) fact.pb(n);
	sort(all(fact));
	return fact;
}

ll totient(ll n) {
	if (n <= 1) return 0;
	ll ans = n;
	vt<ll> fact = prime_factors(n);
	fact.erase(unique(all(fact)), fact.end());
	for (auto &z : fact) {
		ans *= z - 1;
		ans /= z;
	}
	return ans;
}

ll all_factors(ll n) {
	vt<ll> fact = prime_factors(n);
	vt<ll> allfact(1, 1);
	//DBG(fact)
	int i = 0;
	while (i < sz(fact)) {
		int cur = sz(allfact);
		int j=i;
		while (j < sz(fact)) {
			if (fact[i] != fact[j]) break;
			j++;
		}
		ll c = fact[i];
		FORN(a,1,j-i+1) {
			FORN(b,0,cur) {
				allfact.pb(allfact[b] * c);
			}
			c *= fact[i];
		}
		i=j;
	}
	//DBG(allfact)

	ll ans = 0;
	for (auto &x : allfact) {
		assert(n % x == 0);
		ans += totient((n-x)/x);
	}
    return ans;
}


void evadi(int Q, vector<int>& N) {
    // aggiungi codice qui / insert code here
    precompute_sieve();
    FORN(i,0,Q) {
        N[i] = (int)all_factors(N[i]);
    }
}
