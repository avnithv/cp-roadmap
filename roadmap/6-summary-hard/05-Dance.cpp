/* https://atcoder.jp/contests/abc236/tasks/abc236_d */

#include <bits/stdc++.h>
using namespace std;

#define vt vector
#define pb push_back
#define f first
#define s second

typedef pair<int, int> pi;
typedef long long ll;

int N;
ll arr[16][16];


ll recur(vt<pi> &cur, ll curv) {
    if (cur.size() == N) return curv;
    bool vis[2*N]{0};
    for (pi x : cur) {
        vis[x.f] = true;
        vis[x.s] = true;
    }
    vt<int> usable;
    for (int i = 0; i < 2 * N; i++) {
        if (!vis[i]) {
            usable.pb(i);
        }
    }
    ll ans = -1e18;
    int z = usable[0];
    for (int i = 1; i < usable.size(); i++) {
        vt<pi> nxt;
        for (pi x : cur) {
            nxt.pb({x.f, x.s});
        }
        nxt.pb({z, usable[i]});
        ll pos = recur(nxt, curv ^ arr[z][usable[i]]);
        ans = max(ans, pos);
    }
    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < 2 * N; i++) {
        for (int j = i + 1; j < 2 * N; j++) {
            cin >> arr[i][j];
        }
    }

    vt<pi> cur;
    cout << recur(cur, 0) << endl;
}
