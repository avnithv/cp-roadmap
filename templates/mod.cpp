#include <bits/stdc++.h>

using namespace std;

#define MOD(x) mod = (x);

ll mod = 1e9+7;
struct M {
    ll x;
    M (ll xx) : x((xx + mod) % mod) {}
    M pow(M b) {
        if (b == M(0)) return 1;
        M z = pow(b / 2); z = z * z;
        return (b.x & 1 ? (*this) * z : z);
    }
    M inv() {return pow(mod - 2);}
    M operator+(M o) {return M((x + o.x) % mod); }
    M operator-(M o) {return M((x - o.x + mod) % mod);}
    M operator*(M o) {return M((x * o.x) % mod);}
    M operator/(M o) {return (*this) * o.inv();}
    bool operator==(M o) {return x == o.x;}
    bool operator<(M o) {return x < o.x;}
    bool operator<=(M o) {return x <= o.x;}
    bool operator>(M o) {return x > o.x;}
    bool operator>=(M o) {return x >= o.x;}
};
