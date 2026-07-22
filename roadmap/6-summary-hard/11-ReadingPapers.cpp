/* https://training.olinfo.it/#/task/ois_reading/statement */

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
    int n, l; cin >> n >> l;
    vt<vt<int>> days(l);

    vt<int> ops(101, 0);
    FORN(i,0,n) {
        int p, d; cin >> p >> d;
        d = (d+l) % l;
        days[d].pb(p);
    }

    int s = 0;
    REV(i,l,0) {
        EACH(x, days[i]) {
            ops[x]++;
        }
        REV(j,101,1) {
            if (ops[j] > 0) {
                s += j;
                ops[j]--;
                break;
            }
        }
    }
    cout << s << endl;
}
