const ll FIXED_RANDOM = RAND(0, 9e18);
struct chash {          
    static ll splitmix64(ll x) { // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15; x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		    x = (x ^ (x >> 27)) * 0x94d049bb133111eb; return x ^ (x >> 31);
    }
    ll operator()(ll x) const { return splitmix64(x + FIXED_RANDOM); }
};
