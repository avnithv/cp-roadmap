/* https://atcoder.jp/contests/abc162/tasks/abc162_f */

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
#define DBG(z) FORN(lopital,0,sz(z))cerr<<z[lopital]<<" \n"[lopital==sz(z)-1];
#define DBG2(z) EACH(zzz, z) {DBG(zzz)}
#define SET(arr, val) memset((arr), (val), (sizeof(arr)));
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

// only in emergencies
#define int ll

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef priority_queue<ll> pql;

const ll mod = (119<<23)+1;

signed main() {
    ll n; cin >> n;
    vt<ll> arr(n);
    EACH(z, arr) cin >> z;

    ll dp[n+1][3];
    SET(dp, 0x80)
    dp[0][1] = 0;
    dp[1][1] = 0;
    dp[1][2] = arr[0];
    FORN(i,2,n+1) {
        ll pzero = !(i & 1);
        FORN(j, 0, 3) {
            if (j + pzero <= 2) dp[i][j] = max(dp[i][j], dp[i-1][j+pzero]);
            dp[i][j] = max(dp[i][j], dp[i-2][j] + arr[i-1]);
        }
    }
    cout << dp[n][1] << endl;
}
