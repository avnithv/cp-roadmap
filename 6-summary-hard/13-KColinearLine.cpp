/* https://atcoder.jp/contests/abc248/tasks/abc248_e */

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
#define DBG(z, n) FORN(lopital,0,n)cerr<<z[lopital]<<" \n"[lopital==n-1];

// only in emergencies
#define int ll

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;


bool sameline(pi &a, pi &b, pi &c) {
    return (b.f - a.f) * (c.s - b.s) == (b.s - a.s) * (c.f - b.f);
}

signed main() {
    int n, k; cin >> n >> k;
    if (k == 1) {
        cout << "Infinity" << endl;
        return 0;
    }

    vt<pi> points;
    FORN(i,0,n) {
        int x, y;
        cin >> x >> y;
        points.pb(mp(x, y));
    }

    int ans = 0;
    bool vis[n][n];
    memset(vis, 0, sizeof(vis));
    FORN(i,0,n) {
        FORN(j,i+1,n) {
            if (vis[i][j]) continue;

            vt<int> line{i, j};
            FORN(m,j+1,n) {
                if (sameline(points[i], points[j], points[m])) {
                    line.pb(m);
                }
            }

            if (line.size() >= k) ans += 1;

            FORN(a,0,line.size()) {
                FORN(b,a+1,line.size()) {
                    vis[line[a]][line[b]] = true;
                }
            }
        }
    }
    cout << ans << endl;
}
