/* https://atcoder.jp/contests/abc270/tasks/abc270_e */

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


bool sameline(pi &a, pi &b, pi &c) {
    return (b.f - a.f) * (c.s - b.s) == (b.s - a.s) * (c.f - b.f);
}

ll laps(vt<ll> &arr, ll nlaps) {
    ll ans = 0;
    EACH(x, arr) {
        ans += min(x, nlaps);
    }
    return ans;
}

signed main() {
    ll n, k; cin >> n >> k;
    vt<ll> arr(n);
    EACH(i, arr) cin >> i;

    ll l=-1, r=1e12;
    while (l<r-1) {
        ll m = (l+r) / 2;
        if (laps(arr, m) < k) l=m;
        else r=m;
    }

    k -= laps(arr, l);
    FORN(i,0,n) {
        arr[i] = max(0LL, arr[i] - l);
        if (arr[i] > 0 && k > 0) {
            arr[i]--;
            k--;
        }
    }

    FORN(i,0,n) {
        cout << arr[i] << " \n"[i==n-1];
    }
}
