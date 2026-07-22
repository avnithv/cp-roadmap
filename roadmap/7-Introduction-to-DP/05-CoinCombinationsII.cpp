/* https://cses.fi/problemset/task/1636/ */

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
#define DBG2(z, n) EACH(zzz, z) {DBG(zzz, n)}
#define SET(arr, val) memset((arr), (val), (sizeof(arr)));

// only in emergencies
#define int ll

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef priority_queue<ll> pql;

const int mod = 1e9+7;

signed main() {
    int n, x; cin >> n >> x;
    vt<int> arr(n);
    EACH(z, arr) cin >> z;

    int dp[x+1];
    SET(dp, 0)
    dp[0] = 1;
    EACH(z, arr) {
        FORN(i,z,x+1) {
            dp[i] += dp[i - z];
            dp[i] %= mod;
        }
    }
    cout << dp[x] << endl;
}
