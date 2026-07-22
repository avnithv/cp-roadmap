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

ll num_t(ll lines) {
    // a, b, c = number of lines in each of three directions
    // f(a, b, c) = 2ab + 2bc + 2ac = (a + b + c)^2 - a^2 - b^2 - c^2
    // lines = a + b + c, maximize f(a, b, c)
    ll a = lines / 3;
    ll b = a + (lines % 3 == 2 ? 1 : 0);
    ll c = b + (lines % 3 == 1 ? 1 : 0);
    return lines * lines - a * a - b * b - c * c;
}

void solve() {
    ll n; cin >> n;
    ll l = 1, r = n + 1;
    while (r-l>1) {
        ll m = (l+r)/2;
        if (num_t(m) >= n) r=m;
        else l=m;
    }
    cout << r << endl;
}

signed main() {
	FASTIO
    TC
}
