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
#define RE(arr, n) vt<ll> arr(n); EACH(zzz, arr) cin >> zzz;

// only in emergencies
#define int ll
 
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef priority_queue<ll> pql;
 
signed main() {
    int n, x; cin >> n >> x;
    RE(arr, n);
 
    vt<int> dp(x+1, 1e9); dp[0] = 0;
    FORN(i,0,x+1) {
        EACH(x, arr) {
            if (i - x >= 0) {
                dp[i] = min(dp[i], dp[i-x] + 1);
            }
        }
    }
    cout << (dp[x] != 1e9 ? dp[x] : -1) << endl;
}
