template<const int num_hashes> struct HashTuple {
	static constexpr array<ll, 3> M{
			1'000'000'007, 
			1'000'000'009, 
			998'244'353
	};
	array<ll, num_hashes> a;

	HashTuple(ll x = 0) { for (int i = 0; i < num_hashes; i++) a[i] = x; }
	HashTuple(array<ll, num_hashes> _a) : a(_a) {}
	static HashTuple rnd() {
		HashTuple ret;
		for (int i = 0; i < num_hashes; i++) ret[i] = uniform_int_distribution<ll>(0, M[i] - 1)(rng);
		return ret;
	}

	ll& operator[](int ind) { return a[ind]; }
	bool operator==(HashTuple b) { return a == b.a; }
	HashTuple& operator=(HashTuple b) {
		for (int i = 0; i < num_hashes; i++) a[i] = b.a[i];
		return *this;
	}

	HashTuple& operator+=(HashTuple b) { 
		for (int i = 0; i < num_hashes; i++) {
			a[i] += b.a[i];
			if (a[i] > M[i]) a[i] -= M[i];
		}
		return *this;
	}
	HashTuple& operator-=(HashTuple b) { 
		for (int i = 0; i < num_hashes; i++) {
			a[i] -= b.a[i];
			if (a[i] < 0) a[i] += M[i];
		}
		return *this;
	}
	HashTuple& operator*=(HashTuple b) { 
		for (int i = 0; i < num_hashes; i++) a[i] = (a[i] * b.a[i]) % M[i];
		return *this;
	}
	HashTuple operator+(HashTuple b) {
		HashTuple ret(a); ret += b;
		return ret;
	}
	HashTuple operator-(HashTuple b) {
		HashTuple ret(a); ret -= b;
		return ret;
	}
	HashTuple operator*(HashTuple b) {
		HashTuple ret(a); ret *= b;
		return ret;
	}

	ll collapse() {
		ll ret = 0;
		for (int i = 0; i < num_hashes; i++) {
			if (i & 1) ret ^= (a[i] << 32);
			else ret ^= a[i];
		}
		return ret;
	}
};

template<const int num_hashes> struct RollingHash {
	using Hash = HashTuple<num_hashes>;
	
	const Hash B = Hash::rnd();
	vector<Hash> pw, hsh, iv;
	
	RollingHash(int n) {
		pw.resize(n+1); pw[0] = Hash(1);
		for (int i = 0; i < n; i++) pw[i+1] = pw[i] * B;
	}
	void hash_string(string &s) {
		int n = (int)s.size();
		hsh.resize(n+1); hsh[0] = Hash(0);
		for (int i = 0; i < n; i++) hsh[i+1] = hsh[i] * B + Hash(s[i]);
	}
	Hash val(int a, int b) { return hsh[b+1] - (hsh[a] * pw[b-a+1]); } 
};

using Hash = HashTuple<3>;
