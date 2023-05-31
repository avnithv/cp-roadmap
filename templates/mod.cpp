#include <bits/stdc++.h>

using namespace std;

#define MOD(x) mod = (x);

ll mod = 1e9+7;

ll pow(ll &a, ll &b) {
    if (!b) return 1;
    ll x = pow(a, b/2);
    return ((x * x) % mod* (b & 1 ? a : 1)) % mod;
}

ll inv(ll x) {
    return pow(x, mod - 2);
}
