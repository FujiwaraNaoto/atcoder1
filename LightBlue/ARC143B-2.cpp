#include <iostream>
#include <functional>
#include <cassert>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
const bool debug = true;
#define DBG(x) if (debug) { cerr << #x << ":" << x << endl; }

template<typename T>
istream& operator>>(istream& is, vector<T>& xs) {
    for (auto&& x : xs) is >> x;
    return is;
}
template<typename T>
ostream& operator<<(ostream& os, const vector<T>& xs) {
    if (xs.empty()) { return os << ""; }
    bool fst = true;
    for (auto&& x : xs) {
        if (fst) {
            fst = false;
        } else {
            os << " ";
        }
        os << x;
    }
    return os;
}

namespace modint {
    ll extgcd(ll a, ll b, ll &x, ll &y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        ll d = extgcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }
    ll modinv(ll a, ll m) {
        ll x, y;
        extgcd(a, m, x, y);
        return (x % m + m) % m;
    }
    template<ll mod>
        struct ModInt {
            ll x;
            ModInt(ll x) : x(x % mod) { } /* TODO:コンストラクタでmodを取るのは速度上問題かもしれない */
            ModInt(const ModInt& a) : x(a.x) {}
            ModInt inv() const {
                return modinv(x, mod);
            }
        };
    template<ll mod>
        ModInt<mod> operator+(const ModInt<mod>& a, const ModInt<mod>& b) {
            return ModInt<mod>(a.x + b.x);
        }
    template<ll mod>
        ModInt<mod> operator-(const ModInt<mod>& a, const ModInt<mod>& b) {
            return ModInt<mod>(a.x - b.x + mod);
        }
    template<ll mod>
        ModInt<mod> operator*(const ModInt<mod>& a, const ModInt<mod>& k) {
            return ModInt<mod>(a.x * k.x);
        }
    template<ll mod>
        ostream& operator<<(ostream& os, const ModInt<mod>& a) {
            return os << "ModInt(" << a.x << ")";
        }
    template<ll mod>
        ModInt<mod> operator/(const ModInt<mod>& a, const ModInt<mod>& d) {
            return a * d.inv();
        }
}


namespace {
    using mint = modint::ModInt<998244353>;

    mint fact(ll n) {
        mint ret(1);
        for (ll i = 2; i <= n; i++) {
            ret = ret * mint(i);
        }
        return ret;
    }
    mint comb(ll n, ll k) {
        return fact(n) / fact(k) / fact(n-k);
    }
    mint pow2(mint x) {
        return x*x;
    }

    void solve() {
        ll N0; cin >> N0;
        mint N(N0);
        mint ans = fact(N0*N0) - ( N*N*comb(N0*N0, 2*N0 - 1) * pow2(fact(N0-1)) * fact( (N0-1) * (N0-1) ) );
        cout << ans.x << endl;
    }
}

int main() {
    solve();
    return 0;
}
