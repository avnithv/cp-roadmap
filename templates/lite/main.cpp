#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T, class U> using ordered_map = tree<T, U, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T, class U> using ordered_multimap = tree<T, U, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
using ll = long long;
#define FORN(i,a,b) for (int i = a; i < b; i++) 
#define REV(i,b,a) for (int i = b-1; i >= a; i--)
#define EACH(x,a) for (auto x : a)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
template<class T> using V = vector<T>;
template<class T> using pq = priority_queue<T, V<T>, greater<T>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
#define F first
#define S second
#define endl "\n"
// #define int ll
template<class T> void chmin(T &a, T b) { a = min(a, b); }
template<class T> void chmax(T &a, T b) { a = max(a, b); }
const int inf = 1e9, mxn = 1e6+5;
const ll INF = 1e18, MOD = 998244353;

void solve() {
	
}

signed main() {
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

	int tc = 1;
	cin >> tc;
	while (tc--) {
		solve();
	}
}
