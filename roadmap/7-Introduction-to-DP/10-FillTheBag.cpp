/* https://codeforces.com/contest/1303/problem/D */

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
#define DBG(z) FORN(lopital,0,sz(z))cerr<<z[lopital]<<" \n"[lopital==sz(z)-1];
#define DBG2(z) EACH(zzz, z) {DBG(zzz)}
#define SET(arr, val) memset((arr), (val), (sizeof(arr)));
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

// only in emergencies
#define int ll

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef priority_queue<ll> pql;

void solve() {
	int bts = 62;
	ll n, m; cin >> n >> m;
	vt<ll> arr(m);
	EACH(z, arr) cin >> z;

	vt<ll> freq(bts, 0);
	EACH(z, arr) {
		freq[__builtin_ctz(z)]++;
	}

	vt<ll> needs(bts, 0);
	FORN(i,0,bts) {
		if (n & (1LL << i)) {
			needs[i] = 1;
		}
	}

	ll ans = 0, f = -1;
	FORN(i,0,bts) {
		if (freq[i] == 0) {
			if (needs[i] && f == -1) {
				f = i;
			}
		} else {
			if (needs[i]) {
				needs[i]--;
				freq[i]--;
			}
			if (freq[i] && f != -1) {
				ans += i - f;
				f = -1;
				freq[i]--;
			}
			if (i != bts-1) freq[i+1] += freq[i]/2;
		}
	}
	cout << (f == -1 ? ans : -1) << endl;
}

signed main() {
	FASTIO
	TC
}
