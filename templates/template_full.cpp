#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define f first
#define s second
#define endl "\n"
#define mp make_pair
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define TC int tc; cin >> tc; while (tc--) solve();
#define FORN(i, a, b) for(int i = a; i < b; i++)
#define EACH(x, a) for(auto &x : a)
#define DBG(z) FORN(i,0,sz(z))cerr<<z[i]<<" \n"[i==sz(z)-1];
#define DBG2(z) EACH(zzz, z) {DBG(zzz)}
#define SET(arr, val) memset((arr), (val), (sizeof(arr)));
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define log(x) (63-__builtin_clzll(x))
#define tcT template<class T
#define tcTU tcT, class U

// only in emergencies
// #define int ll

tcT> using vt<T> = vector<T>;
tcTU> using gp<T, U> = gp_hash_table<T, U>;
tcT> using pq<T> = priority_queue<T>;
tcT> using qu<T> = queue<T>;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

const ll mod = 1e9+7;

tctT> void ckmin(T &a, T b) {a = min(a, b);}
tctT> void ckmax(T &a, T b) {a = max(a, b);}

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();

struct chash {
	const uint64_t C = ll(4e18 * acos(0)) | 71;
	ll operator()(ll x) const { return __builtin_bswap64((x^RANDOM)*C); }
};

struct phash {
    int operator()(pi x) const { return (x.s* 31 + x.s) ^ RANDOM; }
};

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
