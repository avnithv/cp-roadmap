/* https://atcoder.jp/contests/abc267/tasks/abc267_d */

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
    ll n, m; cin >> n >> m;
    vt<ll> arr(n);
    EACH(z, arr) cin >> z;

    ll dp[n+1][m+1];
    SET(dp, 0x80)
    dp[0][0] = 0;
    FORN(i,1,n+1) {
        dp[i][1] = arr[i-1];
    }
    FORN(i,1,n+1) {
        FORN(j,1,m+1) {
            dp[i][j] = max(dp[i][j], max(dp[i-1][j], dp[i-1][j-1] + arr[i-1] * j));
            //cerr<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    cout << dp[n][m] << endl;
}
