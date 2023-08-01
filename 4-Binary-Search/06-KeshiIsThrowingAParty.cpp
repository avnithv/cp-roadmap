#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define f first
#define s second
#define endl "\n"
#define mp make_pair
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define TC int tc; cin >> tc; while (tc--) solve();
#define FORN(i,a,b) for(int i=a; i<b; i++)
#define REV(i,b,a) for(int i=b-1; i>=a; i--)
#define EACH(x, a) for (auto &x: a)
#define DBG(z) FORN(i,0,sz(z))cerr<<z[i]<<" \n"[i==sz(z)-1];

#define sz(a) (int)a.size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define lb lower_bound
#define ub upper_bound

using ll = long long;
using ull = unsigned long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
template<class T> using vt = vector<T>;

template<class T> void chmin(T &a, T b) {a = min(a, b);}
template<class T> void chmax(T &a, T b) {a = max(a, b);}

const ll MXN = 4e6+1, MOD = 1e9+7;

bool pos(vt<pl> &arr, ll pep) {
    ll cur = 0;
    EACH(z, arr) {
        if (cur <= z.f && z.s >= pep - cur - 1) {
            cur++;
        }
    }
    return cur >= pep;
}

void solve() {
    ll n; cin >> n;
    vt<pl> arr(n);
    FORN(i,0,n) cin >> arr[i].s >> arr[i].f;
    ll l = 0, r = n + 1;
    while (r-l>1) {
        ll m = (l+r)/2;
        if (pos(arr, m)) l=m;
        else r=m;
    }
    cout << l << endl;
}

signed main() {
	FASTIO
    TC
}
