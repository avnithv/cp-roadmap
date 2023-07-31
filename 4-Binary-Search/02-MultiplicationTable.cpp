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

ll num_less(ll n, ll m) { // num (a, b) such that a*b<=n and a, b <= m
    ll ans = 0;
    for (ll i = 1; i <= m; i++) {
        ans += min(m, n / i);
    }
    cerr<<n<<" "<<m<<" "<<ans<<endl;
    ll ans2 = 0;
    FORN(i,1,m+1) {
        FORN(j,1,m+1) {
            if (i*j<=n) ans2++;
        }
    }
    cerr<<ans2<<endl;
    return ans;
}


signed main() {
	FASTIO
    ll n; cin >> n;

    ll l = 1, r = n * n;
    while (r-l>1) {
        ll m = (l + r)/2;
        if (num_less(m, n) > n * n / 2) r=m;
        else l=m;
    }
    cout << r << endl;
}
