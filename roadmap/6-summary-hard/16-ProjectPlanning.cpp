/* https://atcoder.jp/contests/abc227/tasks/abc227_d */

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
#define REV(i, a, b) for (int i = a-1; i >= b; i--)
#define EACH(x, a) for(auto &x : a)
#define DBG(z, n) FORN(lopital,0,n)cerr<<z[lopital]<<" \n"[lopital==n-1];

// only in emergencies
//#define int ll

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef priority_queue<ll> pql;

signed main() {
    ll n, k; cin >> n >> k;
    vt<ll> arr(n);
    EACH(i, arr) cin >> i;

    ll l = 0, r = 1e18 / k;
    while (l < r - 1) {
        ll m = (l + r) / 2, s = 0;
        EACH(z, arr) s += min(z, m);
        if (s >= m * k) l = m;
        else r = m;
    }
    cout << l << endl;
}
