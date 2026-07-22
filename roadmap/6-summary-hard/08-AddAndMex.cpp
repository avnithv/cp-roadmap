/* https://atcoder.jp/contests/abc272/tasks/abc272_e */

#include <bits/stdc++.h>
using namespace std;

#define vt vector
#define pb push_back
#define f first
#define s second
#define endl "\n"
#define mp make_pair
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define TC int tc; cin >> tc; while (tc--) solve();
#define FORN(i, a, b) for(int i = a; i < b; i++)
#define EACH(x, a) for(auto &x : a)
#define DBG(z, n) FORN(i,0,n)cerr<<z[i]<<" \n"[i==n-1];

// only in emergencies
// #define int ll

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef unordered_set<int> usi;

signed main() {
    FASTIO
    int n, m; cin >> n >> m;
    int arr[n];
    EACH(x, arr) cin >> x;

    vt<usi> tm(m);
    FORN(i, 0, n) {
        if (arr[i] >= n) continue;
        int d = i + 1;
        int f = (0 <= arr[i] ? arr[i] + d : ((arr[i] % d) + d) % d);
        int t = (f - arr[i]) / d - 1;
        while (f < n && t < m) {
            tm[t].insert(f);
            t++;
            f += d;
        }
    }

    FORN(i, 0, m) {
        int ans = n;
        FORN(j, 0, n) {
            if (tm[i].count(j) == 0) {
                ans = j;
                break;
            }
        }
        cout << ans << endl;
    }
}
