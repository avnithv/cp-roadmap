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
#define REV(i, b, a) for(int i = b - 1; i >= a; i--)
#define EACH(x, a) for(auto &x : a)
#define DBG(z) FORN(i,0,sz(z))cerr<<z[i]<<" \n"[i==sz(z)-1];
#define DBG2(z) EACH(zzz, z) {DBG(zzz)}
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define log(x) (63-__builtin_clzll(x))
#define tcT template<class T
#define tcTU tcT, class U

// only in emergencies
// #define int ll


using ll = long long;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
tcT> using vt = vector<T>;
tcTU> using gp = gp_hash_table<T, U>;
tcT> using pq = priority_queue<T>;
tcT> using qu = queue<T>;

const ll MOD = 1e9+7;

tcT> inline void ckmin(T &a, T b) {a = min(a, b);}
tcT> inline void ckmax(T &a, T b) {a = max(a, b);}

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();

ll mpw(ll &a, ll &b) {
    if (!b) return 1;
    ll x = mpw(a, b/2);
    return ((x * x) % MOD) * (b & 1 ? a : 1) % MOD;
}

inline ll inv(ll x) {
    return mpw(x, MOD - 2);
}

inline ll norm(ll x) {
    return (x % MOD + MOD) % MOD;
}

void solve() {
}

signed main() {
	FASTIO
}
