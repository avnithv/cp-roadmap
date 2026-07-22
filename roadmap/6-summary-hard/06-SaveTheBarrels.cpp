/* https://training.olinfo.it/#/task/ois_butoaie/statement */

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
#define EACH(x, a) for(auto x : a)
#define DBG(z, n) FORN(i,0,n)cerr<<z[i]<<" \n"[i==n-1];

// op move
#define int ll

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

bool pos(vt<int> &arr, int p, int k, int q, int d) {
    vt<int> narr;
    EACH(x, arr) {
        narr.pb(x - q * d);
    }

    if (p == 0) {
        EACH(x, narr) {
            if (x > 0) {
                return false;
            }
        }
        return true;
    }

    int mx = 0, s = 0;
    EACH(x, narr) {
        if (x <= 0) continue;
        int numd = (x + p - 1) / p;
        mx = max(mx, numd);
        s += numd;
    }
    return (mx <= d) && (s <= d * k);
}

signed main() {
    int n, k; cin >> n >> k;
    int p, q; cin >> p >> q;
    vt<int> arr(n);
    FORN(i, 0, n) {cin >> arr[i];}

    int nq = min(p, q); 
    int np = max(p, q) - nq;
    int nk = (p > q ? k : n - k);

    int l = -1, r = 1e9;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (pos(arr, np, nk, nq, m)) r=m;
        else l=m;
    }
    cout << r << endl;
}
