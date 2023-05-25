#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

/* ========================================================================== */
/* ========================================================================== */

const int RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();

struct chash {
	const uint64_t C = ll(4e18 * acos(0)) | 71;
	ll operator()(ll x) const { return __builtin_bswap64((x^RANDOM)*C); }
};

struct phash {
    int operator()(pi x) const { return (x.s* 31 + x.s) ^ RANDOM; }
};
