#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define vt vector
#define pb push_back
#define f first
#define s second
#define endl "\n"
#define mp make_pair
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define TC int tc; cin >> tc; while (tc--) solve();
#define FORN(i, a, b) for(int i = a; i < b; i++)
#define EACH(x, a) for(auto &x : a)
#define DBG(z, n) FORN(i,0,n)cerr<<z[i]<<" \n"[i==n-1];
#define DBG2(z, n) EACH(zzz, z) {DBG(zzz, n)}
#define SET(arr, val) memset((arr), (val), (sizeof(arr)));
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define log(x) (63-__builtin_clzll(x))

// only in emergencies
#define int ll

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef unordered_set<int> usi;

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();

struct chash {
	const uint64_t C = ll(4e18 * acos(0)) | 71;
	ll operator()(ll x) const { return __builtin_bswap64((x^RANDOM)*C); }
};

struct phash {
    int operator()(pi x) const { return (x.s* 31 + x.s) ^ RANDOM; }
};

const ll mod = 1e9+7;

ll pow(ll &a, ll &b) {
    if (!b) return 1;
    ll x = pow(a, b/2);
    return ((x * x) % mod* (b & 1 ? a : 1)) % mod;
}

ll inv(ll x) {
    return pow(x, mod - 2);
}

void solve() {
}

signed main() {
	FASTIO
}
