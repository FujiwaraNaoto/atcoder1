/*
Convex Hull Trick法
これはありほんだと p304 K-Anonymous Sequenceに相当
https://sune2.hatenadiary.org/entry/20140310/1394440369
https://blog.hamayanhamayan.com/entry/2019/01/12/161237

https://atcoder.jp/contests/dp Zに相当
*/

typedef pair<ll,ll> P;

struct CHT {
  vector<P> deq;              // first * x + second
  int s,t;
  CHT(int n) {                  // n : クエリ数
    deq.resize(n);
    s=0, t=0;
  }
  void add(ll a, ll b) {      // a : 単調減少
    const P p(a,b);
    while(s+1<t && check(deq[t-2],deq[t-1],p)) t--;
    deq[t++] = p;
  }
  ll incl_query(ll x) {            // x : 単調増加
    while(s+1<t && f(deq[s], x) >= f(deq[s+1], x)) s++;
    return f(deq[s], x);
  }
  ll query(ll x) {           // 条件なし
    int low = s-1, high = t-1;
    while(low+1<high) {
      int mid = (low+high)>>1;
      if (isright(deq[mid], deq[mid+1], x)) low = mid;
      else high = mid;
    }
    return f(deq[high], x);
  }
private:
  bool isright(const P &p1, const P &p2, int x) {
    return (p1.second-p2.second) >= x * (p2.first-p1.first);
  }
  bool check(const P &p1, const P &p2, const P &p3) {
    return (p2.first-p1.first)*(p3.second-p2.second) >=
      (p2.second-p1.second)*(p3.first-p2.first);
  }
  ll f(const P &p, ll x) {
    return p.first * x + p.second;
  }
};
