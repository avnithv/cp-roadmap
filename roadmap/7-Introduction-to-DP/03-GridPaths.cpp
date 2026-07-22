/* https://cses.fi/problemset/task/1638/ */

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
//#define int ll

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef priority_queue<ll> pql;

const int mod = 1e9+7;

signed main() {
    int n; cin >> n;
    int dp[n][n];
    SET(dp, 0);
    dp[0][0] = 1;
    FORN(i,0,n) {
        string s; cin >> s;
        FORN(j,0,n) {
            if (s[j] == '*') {
                dp[i][j] = -1;
            }
        }
    }

    FORN(i,0,n) {
        FORN(j,0,n) {
            if (dp[i][j] == -1) continue;
            if (i != 0) dp[i][j] += max(0, dp[i-1][j]);
            if (j != 0) dp[i][j] += max(0, dp[i][j-1]);
            dp[i][j] %= mod;
        }
    }
    cout << max(0, dp[n-1][n-1]) << endl;
}
