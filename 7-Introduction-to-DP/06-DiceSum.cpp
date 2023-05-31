/* https://atcoder.jp/contests/abc248/tasks/abc248_c */

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

const ll mod = (119<<23)+1;

signed main() {
    ll n, m, k; cin >> n >> m >> k;

    ll dp[n+1][k+1];
    SET(dp, 0)
    dp[0][0] = 1;
    FORN(i,1,n+1) {
        FORN(j,1,m+1) {
            FORN(kk,1,k+1) {
                if ((kk - j) >= 0) {
                    dp[i][kk] += dp[i-1][kk-j];
                    dp[i][kk] %= mod;
                }
            }
        }
    }
    ll ans = 0;
    FORN(i,0,k+1) {
        ans += dp[n][i];
        ans %= mod;
    }
    cout << ans << endl;
}
