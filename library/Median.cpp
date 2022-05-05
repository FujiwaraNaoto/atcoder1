//ABC218
/*
中央値
include set
*/
struct Median {
  multiset<int> l;
  multiset<int> r;
  Median() {}
  //常に l.size()==r.size() or l.size()+1==r.size()になるようになっている
  // lの各要素の方が rの各要素よりも小さい
  void rebalance() {
    while (l.size() >= r.size()+2) {
        //sizeの引き算は危険　l.size()-r.size()>=2はだめ
        // intでやらないと

      r.insert(*(l.rbegin()));
      l.erase(--(l.end()));
    }
    while (l.size() < r.size()) {
      l.insert(*(r.begin()));
      r.erase(r.begin());
    }
    if (r.size() > 0) {
        //lの最後尾とrの最前の値の代償関係があるなら交換
      //たかだか一回の計算
      while (*(l.rbegin()) > *(r.begin())) {
        //lの最後尾の要素lx rの最前の要素rx 
        int lx = *(l.rbegin()), rx = *(r.begin());
        l.erase(--(l.end()));
        r.erase(r.begin());
        l.insert(rx); r.insert(lx);
      }
    }
  }
  void add(int x) {
    l.insert(x);
    rebalance();
  }
  void del(int x) {
    auto it = l.find(x);
    if (it != l.end()) l.erase(it);
    else r.erase(r.find(x));
    rebalance();
  }
  int get() {
    int x = *(l.rbegin());//
    if (l.size() != r.size()) return x;
    return (x+*(r.begin()))/2;
  }
};