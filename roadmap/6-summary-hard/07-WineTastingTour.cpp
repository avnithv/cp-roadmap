/* https://training.olinfo.it/#/task/ois_wine/statement */

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

#define int ll

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;

// First index in arr[0...r] with value strictly > k
int find(vt<int> &arr, int r, int k) {
    int l = -1;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (arr[m] <= k) l=m;
        else r=m;
    }
    return r;
}

// # of tours with cost strictly < k 
int numless(vt<int> &arr, int k) {
    int s = 0;
    FORN(i, 0, arr.size()) {
        s += i - find(arr, i, arr[i] - k);
    }
    return s;
}

// cost of Kth tour
int find_cost(vt<int> &arr, int k) {
    int l = 0, r = arr[arr.size() - 1] + 1;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (numless(arr, m) < k) l = m;
        else r=m;
    }
    return l;
}

pi solve(vt<int> &arr, int k) {
    int r = find_cost(arr, k);
    k -= numless(arr, r);
    FORN(i, 0, arr.size()) {
        int p = find(arr, i, arr[i] - r);
        if (p > 0 && arr[p-1] == arr[i] - r) k--;
        if (k == 0) return mp(p, i);
    }
    assert(false);
}

signed main() {
    FASTIO
    int n, k; cin >> n >> k;
    vt<int> arr(n+1, 0);

    FORN(i, 1, n+1) {
        int x; cin >> x;
        arr[i] = arr[i - 1] + x;
    }

    pi ans = solve(arr, k);
    cout << ans.f - 1 << " " << ans.s - 1 << endl;
}
