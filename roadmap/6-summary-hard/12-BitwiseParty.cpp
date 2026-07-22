/* https://training.olinfo.it/#/task/ois_andxor/statement */

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
#define REV(i, a, b) for (int i = a-1; i >= b; i--)
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
    FASTIO
    int n, q; cin >> n >> q;
    vt<int> arr(n);
    vt<usi> bits(20);
    vt<int> xors(20, 0);

    FORN(i,0,n) {
        int x; cin >> x;
        arr[i] = x;
        FORN(b,0,20) {
            if (x & (1 << b)) {
                bits[b].insert(i);
                xors[b] ^= x;
            }   
        }
    }

    int ans = 0;
    FORN(j,0,20) {
        ans = max(ans, ((int)bits[j].size() - (xors[j] == 0 ? 1 : 0)));
    }
    cout << ans << endl;

    FORN(i,0,q) {
        int p, v; cin >> p >> v; p--;
        int x = arr[p];
        FORN(b,0,20) {
            if (x & (1 << b)) {
                bits[b].erase(p);
                xors[b] ^= x;
            }
        }

        FORN(b,0,20) {
            if (v & (1 << b)) {
                bits[b].insert(p);
                xors[b] ^= v;
            }   
        }

        arr[p] = v;
        
        ans = 0;
        FORN(j,0,20) {
            ans = max(ans,((int)bits[j].size()) - ((xors[j] == 0)? 1 : 0));
        }
        cout << ans << endl;
    }
}
