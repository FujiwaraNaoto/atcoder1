/*
https://blog.hamayanhamayan.com/entry/2019/01/08/233906
*/
template<int MOD> struct ModInt {
    static const int Mod = MOD; unsigned x; ModInt() : x(0) { }
    ModInt(signed sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    ModInt(signed long long sig) { x = sig < 0 ? sig % MOD + MOD : sig % MOD; }
    int get() const { return (int)x; }
    ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
    ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
    ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }
    ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
    ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
    ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
    ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }
    ModInt inverse() const {
        long long a = x, b = MOD, u = 1, v = 0;
        while (b) { long long t = a / b; a -= t * b; std::swap(a, b); u -= t * v; std::swap(u, v); }
        return ModInt(u);
    }
    bool operator==(ModInt that) const { return x == that.x; }
    bool operator!=(ModInt that) const { return x != that.x; }
    ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
template<int MOD> ModInt<MOD> operator^(ModInt<MOD> a, unsigned long long k) {
    ModInt<MOD> r = 1; while (k) { if (k & 1) r *= a; a *= a; k >>= 1; } return r;
}
int getrand(int L, int R) { // [L,R]
    random_device rd; mt19937 mt(rd()); uniform_int_distribution<> rand(L, R); return rand(mt);
}
typedef ModInt<1000000007> mint1;
typedef ModInt<1000000009> mint2;
int primes[10] = { 10007, 10009, 10037, 10039, 10061, 10067, 10069, 10079, 10091, 10093 };
bool isShuffle = false;
struct RollingHash {
    mint1 p1; mint2 p2;
    int n;
    vector<mint1> m1; vector<mint2> m2;
    vector<mint1> v1; vector<mint2> v2;

    RollingHash() {
        if (!isShuffle) {
            rep(i, 0, 101) { int a = getrand(0, 9); int b = getrand(0, 9); swap(primes[a], primes[b]); }
            isShuffle = true;
        }
        p1 = primes[0], p2 = primes[1];
    }

    void init(string s, char o = 'a') {
        vector<int> v;
        fore(c, s) v.push_back(c - o);
        init(v);
    }

    void init(vector<int> s) {
        n = s.size();
        m1.resize(n); m2.resize(n); v1.resize(n); v2.resize(n);

        m1[0] = 1; m2[0] = 1;
        v1[0] = s[0]; v2[0] = s[0];

        rep(i, 1, n) {
            m1[i] = m1[i - 1] * p1;
            m2[i] = m2[i - 1] * p2;
            v1[i] = v1[i - 1] + m1[i] * s[i];
            v2[i] = v2[i - 1] + m2[i] * s[i];
        }
    }
    inline pair<mint1, mint2> hash(int l, int r) { // s[l..r]
        assert(l <= r); assert(r < n);
        mint1 a = v1[r];
        if (l) a -= v1[l - 1];
        a *= m1[n - 1 - r];

        mint2 b = v2[r];
        if (l) b -= v2[l - 1];
        b *= m2[n - 1 - r];

        return { a, b };
    }
};