/* https://atcoder.jp/contests/abc257/tasks/abc257_e */

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
#define int ll

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

const int MXN = 9;

signed main() {
    int n; cin >> n;
    int mnx = 1e9;
    vt<int> arr(MXN);
    FORN(i,0,MXN) {
        int x; cin >> x; 
        mnx = min(mnx, x);
        arr[i] = x;
    }

    int numd = n / mnx + 1;
    string ans = "";
    while (--numd) {
        REV(i,MXN,0) {
            if (arr[i] <= n && (n - arr[i]) / mnx == numd-1) {
                ans += to_string(i+1);
                n -= arr[i];
                break;
            }
        }
    }
    cout << ans << endl;
}
