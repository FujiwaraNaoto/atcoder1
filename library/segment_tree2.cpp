
/*
https://opt-cp.com/lazysegtree-aclpc-k/

https://atcoder.github.io/ac-library/document_ja/lazysegtree.html
*/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;


const int mod = 998244353;
struct mint {
  ll x; // typedef long long ll;
  mint(ll x=0):x((x%mod+mod)%mod){}
  mint operator-() const { return mint(-x);}
  mint& operator+=(const mint a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator-=(const mint a) {
    if ((x += mod-a.x) >= mod) x -= mod;
    return *this;
  }
  mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
  mint operator+(const mint a) const { return mint(*this) += a;}//後ろのconstはメンバxを変更しないことを示す
  mint operator-(const mint a) const { return mint(*this) -= a;}
  mint operator*(const mint a) const { return mint(*this) *= a;}
  mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t>>1);
    a *= a;
    if (t&1) a *= *this;
    return a;
  }

  // for prime mod
  mint inv() const { return pow(mod-2);}
  mint& operator/=(const mint a) { return *this *= a.inv();}
  mint operator/(const mint a) const { return mint(*this) /= a;}
};

istream& operator>>(istream& is, mint& a) { return is >> a.x;}
ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}



template <class S,
          S (*op)(S, S),//関数ポインタ
          S (*e)(),//関数ポインタ
          class F,
          S (*mapping)(F, S),//関数ポインタ
          F (*composition)(F, F),//関数ポインタ
          F (*id)()>//関数ポインタ
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {//a[p]=xの操作を行う aのp番目にxを代入する
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {//aのp番目の要素を返す a[p]
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    // op( a[l],a[l+1],a[l+2],...,a[r-1] )を返す l==rの時はe()を返す
    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();//範囲が0の時

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();//関数eには長さ0に対応する情報を書く
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);//
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }//op(a[0],...,a[n-1])を計算する

    void apply(int p, F f) {//a[p] = f(a[p])
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        //i=l,l+1,l+2,...,r-1についてa[i] = f(a[i])
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    // 2^x がnを超えるときのxを返す
    int ceil_pow2(int n) {
        int x = 0;
        while ((1U << x) < (unsigned int)(n)) x++;
        return x;
    }

    //opに従ってアップデートする opにはs[l,m)とs[m,r)からs[l,r)を計算する手法を書く
    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);//更新クエリにより, s[l,r)がどのように変化するかを表すのがmapping
        if (k < size) lz[k] = composition(f, lz[k]);//クエリを処理する順番 先にlz[k]を行った後で次にfを行う
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();//何もしない更新クエリ id
    }
};





struct S {
    //a[l,r)から抽出した情報 s[l,r)の型を表す s[l,r) = ( s^{sum}[l,r),  s^{len}[l,r) )
  mint sum, len;
};

struct F {
    //a[l,r)に適用される更新クエリの情報を表す型,更新クエリとして(l,r以外に)2つの整数b,cが与えられるので以下のように
  mint b, c;
};

S op(S s_l, S s_r) {
    //s[l,r)のsum についてのものと s[l,r)のlenについてのもの
  return {s_l.sum + s_r.sum, s_l.len + s_r.len};
}

S e() {//長さ区間が0に対する情報
  return {0, 0};
}

S mapping(F f, S s) {
    //更新クエリによってs[l,r]がどのように変化するか
    // sumは変わるけど lenは変わらない
  return {f.b * s.sum + f.c * s.len, s.len};
}

F composition(F f, F g) {
    //クエリを適用する順番はg,f 引数はf,gの順で書く(仕様)
  return {f.b * g.b, f.b * g.c + f.c};
}

F id() {
    //何もしない　更新クエリ(b,c)=(1,0)の時が何もしないを表す
  return {1, 0};
}


int main() {
  int n, q; cin >> n >> q;
  vector<S> v(n);
  for(int i=0;i<n;i++) {
    int a; cin >> a;
    v[i] = {a, 1};
  }
  lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);

  
  for(int i=0;i<q;i++){
    int t, l, r; cin >> t >> l >> r;
    if (t == 0) {
      int b, c;
      cin >> b >> c;
      seg.apply(l, r, {b, c});//[l,r) b*sum + c
    }
    else cout << seg.prod(l, r).sum << '\n';
  }
}