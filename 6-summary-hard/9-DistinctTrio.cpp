/* https://atcoder.jp/contests/abc252/tasks/abc252_d */

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

const int MXN = 2e5;

signed main() {
    ll n; cin >> n;
    ll freq[MXN+1]{0};
    FORN(i, 0, n) {
        int x; cin >> x;
        freq[x]++;
    } 

    ll curr_sum = 0, num_pairs = 0, num_trios = 0;
    EACH(x, freq) {
        num_trios += num_pairs * x;
        num_pairs += curr_sum * x;
        curr_sum += x;
    }
    cout << num_trios << endl;
}
