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

const int mod = 1e9+7;

signed main() {
    int n, x; cin >> n >> x;
    vt<int> arr(n);
    EACH(z, arr) cin >> z;

    vt<int> dp(x+1, 0);
    dp[0] = 1;
    FORN(i,1,x+1) {
        EACH(c, arr) {
            if (i - c >= 0) {
                dp[i] += dp[i - c];
                dp[i] %= mod;
            }
        }
    }
    cout << dp[x] << endl;
}
