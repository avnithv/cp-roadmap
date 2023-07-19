#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define log(x) (63-__builtin_clzll(x))
#define tcT template<class T
#define tcTU tcT, class U
#define lb lower_bound
#define ub upper_bound

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
#define rand(a, b) uniform_int_distribution<ll>(a, b)(rng)

// only in emergencies
// #define int ll

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

void solve() {
	
}

signed main() {
	FASTIO
	TC
}
